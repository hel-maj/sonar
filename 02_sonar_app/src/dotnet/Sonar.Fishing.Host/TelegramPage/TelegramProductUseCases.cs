using Sonar.Fishing.Host.FishingSessionState;
using Sonar.Fishing.Host.EngineIntegration;
using Sonar.Fishing.Host.SettingsPersistence;

namespace Sonar.Fishing.Host.TelegramPage;

public enum TelegramProductAction
{
    ToggleFishing = 1,
    ScanPlayerStatus = 2,
    SendScreenshot = 3,
    FocusGame = 4,
    ShutdownPc = 5,
    ShutdownGame = 6,
}

public sealed record TelegramProductState(
    TelegramMenuCapabilities Capabilities,
    FishingSessionStateSnapshot Session,
    TelegramPlayerStatusSnapshot? PlayerStatus,
    ReadOnlyMemory<byte> TacklePng)
{
    public static TelegramProductState Unavailable { get; } = new(
        new TelegramMenuCapabilities(false, false, false, false),
        FishingSessionStateSnapshot.Empty,
        null,
        ReadOnlyMemory<byte>.Empty);
}

public sealed record TelegramProductActionResult(
    bool Accepted,
    string Html,
    ReadOnlyMemory<byte> Png)
{
    public static TelegramProductActionResult Rejected(string html) => new(
        false,
        html,
        ReadOnlyMemory<byte>.Empty);

    public static TelegramProductActionResult Message(string html) => new(
        true,
        html,
        ReadOnlyMemory<byte>.Empty);

    public static TelegramProductActionResult Photo(
        string captionHtml,
        ReadOnlyMemory<byte> png) => new(
        true,
        captionHtml,
        png);
}

public interface ITelegramProductUseCases
{
    TelegramProductState Current { get; }

    Task<TelegramProductActionResult> ExecuteAsync(
        TelegramProductAction action,
        CancellationToken cancellationToken);
}

public sealed class UnavailableTelegramProductUseCases : ITelegramProductUseCases
{
    public TelegramProductState Current => TelegramProductState.Unavailable;

    public Task<TelegramProductActionResult> ExecuteAsync(
        TelegramProductAction action,
        CancellationToken cancellationToken)
    {
        cancellationToken.ThrowIfCancellationRequested();
        if (!Enum.IsDefined(action))
        {
            throw new ArgumentOutOfRangeException(nameof(action));
        }
        return Task.FromResult(TelegramProductActionResult.Rejected(
            "⚠️ Команда недоступна в текущем режиме."));
    }
}

internal sealed class FishingTelegramProductUseCases : ITelegramProductUseCases
{
    private readonly IFishingAutomationRuntime automationRuntime;
    private readonly Func<FishingHostState> currentState;
    private FishingSessionStateSnapshot session = FishingSessionStateSnapshot.Empty;

    internal FishingTelegramProductUseCases(
        IFishingAutomationRuntime automationRuntime,
        Func<FishingHostState> currentState)
    {
        this.automationRuntime = automationRuntime ??
            throw new ArgumentNullException(nameof(automationRuntime));
        this.currentState = currentState ?? throw new ArgumentNullException(nameof(currentState));
        if (automationRuntime is IFishingAutomationStateSource stateSource)
        {
            stateSource.SessionStateChanged += snapshot => Volatile.Write(ref session, snapshot);
        }
    }

    public TelegramProductState Current
    {
        get
        {
            var state = currentState();
            var snapshot = Volatile.Read(ref session);
            var features = state.License.Features;
            return new TelegramProductState(
                new TelegramMenuCapabilities(
                    Fishing: snapshot.Running || features.Contains("fishing_bot", StringComparer.Ordinal),
                    Statistics: features.Contains("statistics", StringComparer.Ordinal),
                    Tackle: features.Contains("fishing_tackle", StringComparer.Ordinal),
                    Streaming: false),
                snapshot,
                PlayerStatus: null,
                TacklePng: ReadOnlyMemory<byte>.Empty);
        }
    }

    public async Task<TelegramProductActionResult> ExecuteAsync(
        TelegramProductAction action,
        CancellationToken cancellationToken)
    {
        cancellationToken.ThrowIfCancellationRequested();
        if (!Enum.IsDefined(action))
        {
            throw new ArgumentOutOfRangeException(nameof(action));
        }
        if (action != TelegramProductAction.ToggleFishing)
        {
            return TelegramProductActionResult.Rejected(
                "⚠️ Команда недоступна в текущей версии.");
        }

        var before = Current;
        if (!before.Capabilities.Fishing)
        {
            return TelegramProductActionResult.Rejected(
                "🚤 Управление рыбалкой недоступно для этой подписки.");
        }

        try
        {
            var updated = before.Session.Running
                ? await automationRuntime.StopAsync(cancellationToken).ConfigureAwait(false)
                : await automationRuntime.StartAsync(cancellationToken).ConfigureAwait(false);
            Volatile.Write(ref session, updated);
            return TelegramProductActionResult.Message(
                updated.Running
                    ? "🚤 Рыбалка запущена."
                    : "🛑 Рыбалка остановлена.");
        }
        catch (EngineCommandRejectedException)
        {
            return TelegramProductActionResult.Rejected(
                "⚠️ Команда отклонена: проверьте лицензию и готовность игры.");
        }
    }
}
