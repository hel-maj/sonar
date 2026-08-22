using System.Collections.ObjectModel;

namespace Sonar.Fishing.Host.TelegramPage;

public sealed record TelegramBotApiUpdate(long UpdateId, ReadOnlyMemory<byte> Utf8Json);

public interface ITelegramBotApi
{
    Task<IReadOnlyList<TelegramBotApiUpdate>> GetUpdatesAsync(
        long? offset,
        int longPollingTimeoutSeconds,
        CancellationToken cancellationToken);

    Task<long?> SendMessageAsync(
        long chatId,
        string html,
        bool silent,
        TelegramMenuPlan? menu,
        CancellationToken cancellationToken);

    Task EditMessageAsync(
        long chatId,
        long messageId,
        string html,
        TelegramMenuPlan? menu,
        CancellationToken cancellationToken);

    Task<long?> SendPhotoAsync(
        long chatId,
        ReadOnlyMemory<byte> png,
        string captionHtml,
        bool silent,
        TelegramMenuPlan? menu,
        CancellationToken cancellationToken);

    Task AnswerCallbackQueryAsync(
        string callbackId,
        CancellationToken cancellationToken);
}

public sealed class TelegramBotApiException : Exception
{
    public TelegramBotApiException(
        string reason,
        int? statusCode = null,
        int? apiErrorCode = null)
        : base(reason)
    {
        ArgumentException.ThrowIfNullOrWhiteSpace(reason);
        Reason = reason;
        StatusCode = statusCode;
        ApiErrorCode = apiErrorCode;
    }

    public string Reason { get; }

    public int? StatusCode { get; }

    public int? ApiErrorCode { get; }
}

internal static class TelegramBotApiCollections
{
    internal static IReadOnlyList<TelegramBotApiUpdate> Freeze(
        IEnumerable<TelegramBotApiUpdate> updates) =>
        new ReadOnlyCollection<TelegramBotApiUpdate>(updates.ToArray());
}
