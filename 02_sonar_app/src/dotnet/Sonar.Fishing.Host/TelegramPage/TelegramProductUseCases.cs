using Sonar.Fishing.Host.FishingSessionState;

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
