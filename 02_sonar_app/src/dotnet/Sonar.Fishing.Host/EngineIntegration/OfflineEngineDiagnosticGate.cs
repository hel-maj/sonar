using System.Diagnostics;
using Sonar.Fishing.Host.SettingsPersistence;

namespace Sonar.Fishing.Host.EngineIntegration;

/// <summary>
/// Runs one bounded, inert parity scenario through the shared session owner.
/// </summary>
public static class OfflineEngineDiagnosticGate
{
    public static async Task<OfflineEngineDiagnosticReceipt> ExecuteAsync(
        string engineExecutable,
        string? rawCatchQualityText,
        string? fishId,
        IReadOnlyCollection<string> selectedFishIds,
        bool inventoryFull,
        FishingRuntimeSettings runtimeSettings,
        TimeSpan timeout,
        CancellationToken cancellationToken = default)
    {
        ArgumentNullException.ThrowIfNull(selectedFishIds);
        ArgumentNullException.ThrowIfNull(runtimeSettings);
        runtimeSettings.Validate();
        if (timeout <= TimeSpan.Zero || timeout > TimeSpan.FromSeconds(30))
        {
            throw new ArgumentOutOfRangeException(nameof(timeout));
        }

        using var timeoutSource = CancellationTokenSource.CreateLinkedTokenSource(
            cancellationToken);
        timeoutSource.CancelAfter(timeout);
        var token = timeoutSource.Token;
        var totalStartedAt = Stopwatch.GetTimestamp();
        await using var session = await OfflineEngineSession.StartAsync(
            engineExecutable,
            timeout,
            token).ConfigureAwait(false);
        var scenarioStartedAt = Stopwatch.GetTimestamp();

        var acknowledgedHeartbeatId = await session.PingAsync(token).ConfigureAwait(false);
        var acceptedSettingsRevision = await session.ApplyRuntimeSettingsAsync(
            runtimeSettings,
            token).ConfigureAwait(false);
        var sessionState = await session.StartReadOnlySessionAsync(token).ConfigureAwait(false);
        var catchQuality = await session.ClassifyCatchQualityAsync(
            rawCatchQualityText,
            token).ConfigureAwait(false);
        var catchDisposition = await session.EvaluateCatchDispositionAsync(
            fishId,
            selectedFishIds,
            inventoryFull,
            token).ConfigureAwait(false);

        var process = session.Process;
        process.Refresh();
        var processId = session.ProcessId;
        var containmentVerified = session.IsContained;
        var negotiatedProtocolMinor = session.NegotiatedProtocolMinor;
        var engineProcessorTime = process.TotalProcessorTime;
        var enginePeakWorkingSetBytes = process.PeakWorkingSet64;
        await session.ShutdownAsync(token).ConfigureAwait(false);
        var scenarioDuration = Stopwatch.GetElapsedTime(scenarioStartedAt);

        return new OfflineEngineDiagnosticReceipt(
            catchQuality,
            catchDisposition,
            sessionState,
            processId,
            containmentVerified,
            negotiatedProtocolMinor,
            SideEffectsEnabled: false,
            acceptedSettingsRevision,
            acknowledgedHeartbeatId,
            OfflineEngineSessionProtocol.OfflineDiagnosticAuthority,
            new OfflineEnginePerformanceSnapshot(
                session.BootstrapDuration,
                scenarioDuration,
                Stopwatch.GetElapsedTime(totalStartedAt),
                engineProcessorTime,
                enginePeakWorkingSetBytes,
                MeasuredIpcOperations: 6));
    }
}
