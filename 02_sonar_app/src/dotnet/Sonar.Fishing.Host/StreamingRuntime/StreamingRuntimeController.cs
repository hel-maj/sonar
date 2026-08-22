using Sonar.Fishing.Host.StreamingPage;

namespace Sonar.Fishing.Host.StreamingRuntime;

internal sealed class StreamingRuntimeController : IStreamingController, IAsyncDisposable
{
    private readonly object sync = new();
    private readonly IStreamingSessionBackend backend;
    private readonly IStreamingChatModeBridge chatModeBridge;
    private readonly StreamingRuntimePolicy policy;
    private readonly TimeProvider timeProvider;
    private readonly Action<Action> eventDispatcher;
    private StreamingRuntimeSnapshot current;
    private CancellationTokenSource? generationCancellation;
    private Task activeGeneration = Task.CompletedTask;
    private long generationId;
    private bool disposed;

    internal StreamingRuntimeController(
        IStreamingSessionBackend backend,
        IStreamingChatModeBridge chatModeBridge,
        bool snapshotModeEnabled,
        StreamingRuntimePolicy? policy = null,
        TimeProvider? timeProvider = null,
        Action<Action>? eventDispatcher = null)
    {
        this.backend = backend ?? throw new ArgumentNullException(nameof(backend));
        this.chatModeBridge = chatModeBridge ??
            throw new ArgumentNullException(nameof(chatModeBridge));
        this.policy = policy ?? StreamingRuntimePolicy.Default;
        this.policy.Validate();
        this.timeProvider = timeProvider ?? TimeProvider.System;
        this.eventDispatcher = eventDispatcher ?? CreateEventDispatcher();
        current = StreamingRuntimeSnapshot.Offline(snapshotModeEnabled);
    }

    public StreamingRuntimeSnapshot Current
    {
        get
        {
            lock (sync)
            {
                return current;
            }
        }
    }

    public event Action<StreamingRuntimeSnapshot>? SnapshotChanged;

    public StreamingCommandResult Start()
    {
        StreamingRuntimeSnapshot published;
        lock (sync)
        {
            if (disposed)
            {
                return RejectLocked("streaming_runtime_disposed");
            }
            if (current.Status is not StreamingRuntimeStatus.Offline and
                not StreamingRuntimeStatus.Error)
            {
                return RejectLocked("streaming_already_running");
            }
            published = BeginGenerationLocked(current);
        }
        Publish(published);
        return Accept(published);
    }

    public StreamingCommandResult Stop(string reason)
    {
        ArgumentException.ThrowIfNullOrWhiteSpace(reason);
        StreamingRuntimeSnapshot published;
        lock (sync)
        {
            if (disposed)
            {
                return RejectLocked("streaming_runtime_disposed");
            }
            generationCancellation?.Cancel();
            published = AdvanceLocked(current with
            {
                Status = StreamingRuntimeStatus.Offline,
                Active = false,
                ChatModeEnabled = false,
                ChatActive = false,
                LocalUrl = null,
                PublicUrl = null,
                StreamUrl = null,
                StartedAt = null,
                SecondsUntilAutoStop = null,
                Error = string.Empty,
            });
        }
        Publish(published);
        return Accept(published);
    }

    public StreamingCommandResult SetQuality(string quality)
    {
        var canonical = StreamingQualityCatalog.Require(quality).Name;
        return UpdateSettings(snapshot => snapshot with { Quality = canonical });
    }

    public StreamingCommandResult SetChatZoom(bool enabled) =>
        UpdateSettings(snapshot => snapshot with { ChatZoomEnabled = enabled });

    public StreamingCommandResult SetSnapshotMode(bool enabled) =>
        UpdateSettings(snapshot => snapshot with { SnapshotModeEnabled = enabled });

    public StreamingCommandResult SetChatMode(bool enabled)
    {
        long expectedGeneration;
        lock (sync)
        {
            if (disposed)
            {
                return RejectLocked("streaming_runtime_disposed");
            }
            if (!current.Active || current.Status != StreamingRuntimeStatus.Online)
            {
                return RejectLocked("streaming_not_online");
            }
            if (current.ChatModeEnabled == enabled && current.ChatActive == enabled)
            {
                return Accept(current);
            }
            expectedGeneration = generationId;
        }

        StreamingChatModeResult bridgeResult;
        using (var cancellation = new CancellationTokenSource(policy.ChatCommandTimeout))
        {
            try
            {
                bridgeResult = chatModeBridge.SetEnabledAsync(enabled, cancellation.Token)
                    .AsTask()
                    .WaitAsync(policy.ChatCommandTimeout, CancellationToken.None)
                    .GetAwaiter()
                    .GetResult();
            }
            catch (Exception exception) when (
                exception is OperationCanceledException or TimeoutException)
            {
                lock (sync)
                {
                    return RejectLocked("streaming_chat_command_timeout");
                }
            }
            catch
            {
                lock (sync)
                {
                    return RejectLocked("streaming_chat_command_failed");
                }
            }
        }

        StreamingRuntimeSnapshot published;
        lock (sync)
        {
            if (disposed || expectedGeneration != generationId || !current.Active)
            {
                _ = DisableChatModeAfterStateChangeAsync(enabled);
                return RejectLocked("streaming_state_changed");
            }
            if (bridgeResult.Active != enabled)
            {
                return RejectLocked("streaming_chat_command_failed");
            }
            published = AdvanceLocked(current with
            {
                ChatModeEnabled = enabled,
                ChatActive = bridgeResult.Active,
            });
        }
        Publish(published);
        return Accept(published);
    }

    public async ValueTask DisposeAsync()
    {
        Task generation;
        lock (sync)
        {
            if (disposed)
            {
                return;
            }
            disposed = true;
            generationCancellation?.Cancel();
            generation = activeGeneration;
            current = AdvanceLocked(current with
            {
                Status = StreamingRuntimeStatus.Offline,
                Active = false,
                ChatModeEnabled = false,
                ChatActive = false,
                LocalUrl = null,
                PublicUrl = null,
                StreamUrl = null,
                StartedAt = null,
                SecondsUntilAutoStop = null,
                Error = string.Empty,
            });
        }

        try
        {
            await generation.WaitAsync(policy.CleanupTimeout, CancellationToken.None)
                .ConfigureAwait(false);
        }
        catch (TimeoutException)
        {
            // Backend resources own their own Common Job hard-stop fallback.
        }
    }

    private StreamingCommandResult UpdateSettings(
        Func<StreamingRuntimeSnapshot, StreamingRuntimeSnapshot> update)
    {
        ArgumentNullException.ThrowIfNull(update);
        StreamingRuntimeSnapshot published;
        lock (sync)
        {
            if (disposed)
            {
                return RejectLocked("streaming_runtime_disposed");
            }
            if (current.Status is StreamingRuntimeStatus.Preparing or
                StreamingRuntimeStatus.Starting)
            {
                return RejectLocked("streaming_restart_in_progress");
            }
            var next = update(current);
            if (next == current)
            {
                return Accept(current);
            }
            published = current.Active
                ? BeginGenerationLocked(next with
                {
                    ChatModeEnabled = false,
                    ChatActive = false,
                })
                : AdvanceLocked(next);
        }
        Publish(published);
        return Accept(published);
    }

    private StreamingRuntimeSnapshot BeginGenerationLocked(
        StreamingRuntimeSnapshot settings)
    {
        generationCancellation?.Cancel();
        var previous = activeGeneration;
        var cancellation = new CancellationTokenSource();
        generationCancellation = cancellation;
        var nextGeneration = checked(++generationId);
        var starting = AdvanceLocked(settings with
        {
            Status = StreamingRuntimeStatus.Starting,
            Active = false,
            ChatModeEnabled = false,
            ChatActive = false,
            LocalUrl = null,
            PublicUrl = null,
            StreamUrl = null,
            StartedAt = null,
            SecondsUntilAutoStop = null,
            Error = string.Empty,
        });
        var request = StreamingSessionRequest.From(starting);
        activeGeneration = Task.Run(
            () => RunGenerationAsync(
                nextGeneration,
                request,
                previous,
                cancellation));
        return starting;
    }

    private async Task RunGenerationAsync(
        long expectedGeneration,
        StreamingSessionRequest request,
        Task previousGeneration,
        CancellationTokenSource cancellation)
    {
        try
        {
            await previousGeneration
                .WaitAsync(policy.CleanupTimeout, cancellation.Token)
                .ConfigureAwait(false);
        }
        catch (OperationCanceledException) when (cancellation.IsCancellationRequested)
        {
            CompleteGeneration(expectedGeneration, cancellation);
            return;
        }
        catch (TimeoutException)
        {
            PublishFailure(expectedGeneration, "streaming_previous_cleanup_timeout");
            CompleteGeneration(expectedGeneration, cancellation);
            return;
        }
        catch
        {
            PublishFailure(expectedGeneration, "streaming_previous_cleanup_failed");
            CompleteGeneration(expectedGeneration, cancellation);
            return;
        }

        var attempt = 0;
        try
        {
            while (!cancellation.IsCancellationRequested)
            {
                IStreamingRuntimeSession? session = null;
                string? failure = null;
                var autoStopped = false;
                try
                {
                    PublishStarting(expectedGeneration);
                    using var startup = CancellationTokenSource.CreateLinkedTokenSource(
                        cancellation.Token);
                    startup.CancelAfter(policy.StartupTimeout);
                    session = await backend.StartAsync(request, startup.Token)
                        .AsTask()
                        .WaitAsync(policy.StartupTimeout, CancellationToken.None)
                        .ConfigureAwait(false);
                    PublishOnline(expectedGeneration, session);
                    var monitor = await MonitorAsync(
                            expectedGeneration,
                            session,
                            cancellation.Token)
                        .ConfigureAwait(false);
                    autoStopped = monitor.AutoStopped;
                    failure = monitor.FailureReason;
                }
                catch (OperationCanceledException) when (cancellation.IsCancellationRequested)
                {
                }
                catch (OperationCanceledException)
                {
                    failure = "streaming_start_timeout";
                }
                catch (TimeoutException)
                {
                    failure = "streaming_start_timeout";
                }
                catch (StreamingRuntimeException exception)
                {
                    failure = exception.Reason;
                }
                catch
                {
                    failure = "streaming_runtime_failed";
                }

                var cleanupFailure = await StopSessionAsync(session).ConfigureAwait(false);
                if (cleanupFailure is not null)
                {
                    failure = cleanupFailure;
                }
                await DisableChatModeAsync().ConfigureAwait(false);

                if (cancellation.IsCancellationRequested)
                {
                    if (failure is not null)
                    {
                        PublishFailure(expectedGeneration, failure);
                    }
                    return;
                }
                if (autoStopped)
                {
                    PublishOffline(expectedGeneration);
                    return;
                }
                if (failure is null)
                {
                    failure = "streaming_runtime_ended";
                }
                if (attempt >= policy.MaximumRestartAttempts)
                {
                    PublishFailure(expectedGeneration, failure);
                    return;
                }

                attempt++;
                PublishStarting(expectedGeneration);
                await Task.Delay(policy.RestartDelay, cancellation.Token)
                    .ConfigureAwait(false);
            }
        }
        catch (OperationCanceledException) when (cancellation.IsCancellationRequested)
        {
        }
        finally
        {
            CompleteGeneration(expectedGeneration, cancellation);
        }
    }

    private async ValueTask<(bool AutoStopped, string? FailureReason)> MonitorAsync(
        long expectedGeneration,
        IStreamingRuntimeSession session,
        CancellationToken cancellationToken)
    {
        DateTimeOffset? noViewersSince = timeProvider.GetUtcNow();
        PublishAutoStop(expectedGeneration, policy.NoViewerAutoStop);
        while (true)
        {
            var observation = await session.ObserveAsync(
                    policy.MonitorInterval,
                    cancellationToken)
                .ConfigureAwait(false);
            if (!observation.Healthy)
            {
                return (false, string.IsNullOrWhiteSpace(observation.FailureReason)
                    ? "streaming_component_exited"
                    : observation.FailureReason);
            }

            if (observation.ViewerCount > 0)
            {
                noViewersSince = null;
                PublishAutoStop(expectedGeneration, remaining: null);
                continue;
            }

            noViewersSince ??= timeProvider.GetUtcNow();
            var elapsed = timeProvider.GetUtcNow() - noViewersSince.Value;
            var remaining = policy.NoViewerAutoStop - elapsed;
            if (remaining <= TimeSpan.Zero)
            {
                return (true, null);
            }
            PublishAutoStop(expectedGeneration, remaining);
        }
    }

    private async ValueTask<string?> StopSessionAsync(IStreamingRuntimeSession? session)
    {
        if (session is null)
        {
            return null;
        }
        return await StreamingCleanupScope.RunAsync(
                policy.CleanupTimeout,
                cancellationToken => session.StopAsync(cancellationToken),
                _ => session.DisposeAsync())
            .ConfigureAwait(false);
    }

    private async ValueTask DisableChatModeAsync()
    {
        using var cancellation = new CancellationTokenSource(policy.ChatCommandTimeout);
        try
        {
            _ = await chatModeBridge.SetEnabledAsync(false, cancellation.Token)
                .AsTask()
                .WaitAsync(policy.ChatCommandTimeout, CancellationToken.None)
                .ConfigureAwait(false);
        }
        catch
        {
            // Session cleanup remains authoritative even if the external chat bridge is absent.
        }
    }

    private async Task DisableChatModeAfterStateChangeAsync(bool wasEnabled)
    {
        if (wasEnabled)
        {
            await DisableChatModeAsync().ConfigureAwait(false);
        }
    }

    private void PublishStarting(long expectedGeneration) =>
        TryPublishGeneration(expectedGeneration, snapshot => snapshot with
        {
            Status = StreamingRuntimeStatus.Starting,
            Active = false,
            LocalUrl = null,
            PublicUrl = null,
            StreamUrl = null,
            StartedAt = null,
            SecondsUntilAutoStop = null,
            Error = string.Empty,
        });

    private void PublishOnline(
        long expectedGeneration,
        IStreamingRuntimeSession session) =>
        TryPublishGeneration(expectedGeneration, snapshot => snapshot with
        {
            Status = StreamingRuntimeStatus.Online,
            Active = true,
            LocalUrl = session.LocalUri.AbsoluteUri,
            PublicUrl = session.PublicUri.AbsoluteUri,
            StreamUrl = session.StreamUri.AbsoluteUri,
            StartedAt = timeProvider.GetUtcNow(),
            SecondsUntilAutoStop = checked((int)Math.Ceiling(
                policy.NoViewerAutoStop.TotalSeconds)),
            Error = string.Empty,
        });

    private void PublishAutoStop(long expectedGeneration, TimeSpan? remaining) =>
        TryPublishGeneration(expectedGeneration, snapshot => snapshot with
        {
            SecondsUntilAutoStop = remaining is null
                ? null
                : Math.Max(0, checked((int)Math.Ceiling(remaining.Value.TotalSeconds))),
        }, requireOnline: true);

    private void PublishOffline(long expectedGeneration) =>
        TryPublishGeneration(expectedGeneration, snapshot => snapshot with
        {
            Status = StreamingRuntimeStatus.Offline,
            Active = false,
            ChatModeEnabled = false,
            ChatActive = false,
            LocalUrl = null,
            PublicUrl = null,
            StreamUrl = null,
            StartedAt = null,
            SecondsUntilAutoStop = null,
            Error = string.Empty,
        });

    private void PublishFailure(long expectedGeneration, string reason) =>
        TryPublishGeneration(expectedGeneration, snapshot => snapshot with
        {
            Status = StreamingRuntimeStatus.Error,
            Active = false,
            ChatModeEnabled = false,
            ChatActive = false,
            LocalUrl = null,
            PublicUrl = null,
            StreamUrl = null,
            StartedAt = null,
            SecondsUntilAutoStop = null,
            Error = FailureText(reason),
        });

    private void TryPublishGeneration(
        long expectedGeneration,
        Func<StreamingRuntimeSnapshot, StreamingRuntimeSnapshot> update,
        bool requireOnline = false)
    {
        StreamingRuntimeSnapshot? published = null;
        lock (sync)
        {
            if (!disposed && expectedGeneration == generationId &&
                (!requireOnline || current.Status == StreamingRuntimeStatus.Online))
            {
                published = AdvanceLocked(update(current));
            }
        }
        if (published is not null)
        {
            Publish(published);
        }
    }

    private void CompleteGeneration(
        long expectedGeneration,
        CancellationTokenSource cancellation)
    {
        lock (sync)
        {
            if (expectedGeneration == generationId)
            {
                generationCancellation = null;
                activeGeneration = Task.CompletedTask;
            }
        }
        cancellation.Dispose();
    }

    private StreamingRuntimeSnapshot AdvanceLocked(StreamingRuntimeSnapshot next)
    {
        current = next with { Revision = checked(current.Revision + 1) };
        current.Validate();
        return current;
    }

    private StreamingCommandResult RejectLocked(string reason) =>
        new(false, reason, current);

    private static StreamingCommandResult Accept(StreamingRuntimeSnapshot snapshot) =>
        new(true, "accepted", snapshot);

    private void Publish(StreamingRuntimeSnapshot snapshot) =>
        eventDispatcher(() => SnapshotChanged?.Invoke(snapshot));

    private static Action<Action> CreateEventDispatcher()
    {
        var context = SynchronizationContext.Current;
        return context is null
            ? action => action()
            : action => context.Post(static state => ((Action)state!).Invoke(), action);
    }

    private static string FailureText(string reason) => reason switch
    {
        "streaming_start_timeout" => "Не удалось запустить трансляцию вовремя.",
        "streaming_previous_cleanup_timeout" or "streaming_cleanup_timeout" or
            "streaming_process_cleanup_timeout" =>
            "Не удалось безопасно завершить предыдущую трансляцию.",
        "streaming_loose_tools_forbidden" or "streaming_embedded_tool_missing" or
            "streaming_embedded_tool_hash_mismatch" =>
            "Не удалось подготовить трансляцию. Перезапустите приложение и повторите.",
        "streaming_network_boundary_invalid" =>
            "Не удалось открыть трансляцию. Повторите запуск.",
        _ => "Трансляция завершилась с ошибкой.",
    };
}
