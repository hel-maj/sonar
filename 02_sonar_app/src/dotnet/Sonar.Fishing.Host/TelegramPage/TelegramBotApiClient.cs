using System.Globalization;
using System.IO;
using System.Net;
using System.Net.Http;
using System.Net.Http.Headers;
using System.Net.Http.Json;
using System.Text;
using System.Text.Json;

namespace Sonar.Fishing.Host.TelegramPage;

public sealed class TelegramBotApiClient : ITelegramBotApi
{
    private const int MaximumResponseBytes = 2 * 1024 * 1024;
    private const int MaximumUpdateBytes = 64 * 1024;
    private static readonly JsonSerializerOptions JsonOptions = new(JsonSerializerDefaults.Web);
    private readonly HttpClient httpClient;
    private readonly string methodPrefix;

    public TelegramBotApiClient(HttpClient httpClient, string botToken)
    {
        ArgumentNullException.ThrowIfNull(httpClient);
        ValidateToken(botToken);
        if (httpClient.BaseAddress is null ||
            !string.Equals(httpClient.BaseAddress.Scheme, Uri.UriSchemeHttps, StringComparison.OrdinalIgnoreCase))
        {
            throw new ArgumentException("telegram_https_base_required", nameof(httpClient));
        }
        this.httpClient = httpClient;
        methodPrefix = $"bot{botToken}/";
    }

    public async Task<IReadOnlyList<TelegramBotApiUpdate>> GetUpdatesAsync(
        long? offset,
        int longPollingTimeoutSeconds,
        CancellationToken cancellationToken)
    {
        if (offset is <= 0 || longPollingTimeoutSeconds is < 1 or > 50)
        {
            throw new ArgumentOutOfRangeException(
                offset is <= 0 ? nameof(offset) : nameof(longPollingTimeoutSeconds));
        }
        using var request = JsonRequest(
            "getUpdates",
            new
            {
                offset,
                limit = 100,
                timeout = longPollingTimeoutSeconds,
                allowed_updates = new[] { "message", "callback_query" },
            });
        using var document = await SendAsync(request, cancellationToken).ConfigureAwait(false);
        var result = RequireResult(document.RootElement);
        if (result.ValueKind != JsonValueKind.Array || result.GetArrayLength() > 100)
        {
            throw new TelegramBotApiException("telegram_updates_invalid");
        }

        var updates = new List<TelegramBotApiUpdate>(result.GetArrayLength());
        foreach (var update in result.EnumerateArray())
        {
            if (update.ValueKind != JsonValueKind.Object ||
                !update.TryGetProperty("update_id", out var updateIdElement) ||
                !updateIdElement.TryGetInt64(out var updateId) ||
                updateId <= 0)
            {
                throw new TelegramBotApiException("telegram_update_invalid");
            }
            var utf8Json = Encoding.UTF8.GetBytes(update.GetRawText());
            if (utf8Json.Length > MaximumUpdateBytes)
            {
                throw new TelegramBotApiException("telegram_update_too_large");
            }
            updates.Add(new TelegramBotApiUpdate(updateId, utf8Json));
        }
        return TelegramBotApiCollections.Freeze(updates);
    }

    public async Task<long?> SendMessageAsync(
        long chatId,
        string html,
        bool silent,
        TelegramMenuPlan? menu,
        CancellationToken cancellationToken)
    {
        ValidateMessage(chatId, html);
        using var request = JsonRequest(
            "sendMessage",
            new
            {
                chat_id = chatId,
                text = html,
                parse_mode = "HTML",
                link_preview_options = new { is_disabled = true },
                disable_notification = silent,
                reply_markup = menu is null ? null : BuildReplyMarkup(menu),
            });
        using var document = await SendAsync(request, cancellationToken).ConfigureAwait(false);
        return ReadMessageId(RequireResult(document.RootElement));
    }

    public async Task EditMessageAsync(
        long chatId,
        long messageId,
        string html,
        TelegramMenuPlan? menu,
        CancellationToken cancellationToken)
    {
        ValidateMessage(chatId, html);
        if (messageId <= 0)
        {
            throw new ArgumentOutOfRangeException(nameof(messageId));
        }
        using var request = JsonRequest(
            "editMessageText",
            new
            {
                chat_id = chatId,
                message_id = messageId,
                text = html,
                parse_mode = "HTML",
                link_preview_options = new { is_disabled = true },
                reply_markup = menu is null ? null : BuildReplyMarkup(menu),
            });
        using var document = await SendAsync(request, cancellationToken).ConfigureAwait(false);
        var result = RequireResult(document.RootElement);
        if (result.ValueKind is not JsonValueKind.Object and not JsonValueKind.True)
        {
            throw new TelegramBotApiException("telegram_message_edit_invalid");
        }
    }

    public async Task<long?> SendPhotoAsync(
        long chatId,
        ReadOnlyMemory<byte> png,
        string captionHtml,
        bool silent,
        TelegramMenuPlan? menu,
        CancellationToken cancellationToken)
    {
        ValidateMessage(chatId, captionHtml);
        if (png.IsEmpty || png.Length > 10 * 1024 * 1024)
        {
            throw new ArgumentOutOfRangeException(nameof(png));
        }
        using var request = new HttpRequestMessage(HttpMethod.Post, MethodUri("sendPhoto"));
        using var content = new MultipartFormDataContent();
        content.Add(new StringContent(chatId.ToString(CultureInfo.InvariantCulture)), "chat_id");
        content.Add(new StringContent(captionHtml, Encoding.UTF8), "caption");
        content.Add(new StringContent("HTML", Encoding.ASCII), "parse_mode");
        content.Add(new StringContent(silent ? "true" : "false", Encoding.ASCII), "disable_notification");
        if (menu is not null)
        {
            content.Add(
                new StringContent(
                    JsonSerializer.Serialize(BuildReplyMarkup(menu), JsonOptions),
                    Encoding.UTF8,
                    "application/json"),
                "reply_markup");
        }
        var photoContent = new ByteArrayContent(png.ToArray());
        photoContent.Headers.ContentType = new MediaTypeHeaderValue("image/png");
        content.Add(photoContent, "photo", "screen.png");
        request.Content = content;
        using var document = await SendAsync(request, cancellationToken).ConfigureAwait(false);
        return ReadMessageId(RequireResult(document.RootElement));
    }

    public async Task AnswerCallbackQueryAsync(
        string callbackId,
        CancellationToken cancellationToken)
    {
        if (string.IsNullOrWhiteSpace(callbackId) || callbackId.Length > 256)
        {
            throw new ArgumentException("telegram_callback_id_invalid", nameof(callbackId));
        }
        using var request = JsonRequest(
            "answerCallbackQuery",
            new { callback_query_id = callbackId });
        using var document = await SendAsync(request, cancellationToken).ConfigureAwait(false);
        var result = RequireResult(document.RootElement);
        if (result.ValueKind is not JsonValueKind.True)
        {
            throw new TelegramBotApiException("telegram_callback_answer_invalid");
        }
    }

    private async Task<JsonDocument> SendAsync(
        HttpRequestMessage request,
        CancellationToken cancellationToken)
    {
        HttpResponseMessage response;
        try
        {
            response = await httpClient.SendAsync(
                request,
                HttpCompletionOption.ResponseHeadersRead,
                cancellationToken).ConfigureAwait(false);
        }
        catch (OperationCanceledException) when (cancellationToken.IsCancellationRequested)
        {
            throw;
        }
        catch (OperationCanceledException)
        {
            throw new TelegramBotApiException("telegram_http_timeout");
        }
        catch (HttpRequestException)
        {
            throw new TelegramBotApiException("telegram_http_unavailable");
        }

        using (response)
        {
            var statusCode = (int)response.StatusCode;
            var bytes = await ReadBoundedAsync(response.Content, cancellationToken).ConfigureAwait(false);
            JsonDocument? document = null;
            try
            {
                document = JsonDocument.Parse(bytes, new JsonDocumentOptions
                {
                    AllowTrailingCommas = false,
                    CommentHandling = JsonCommentHandling.Disallow,
                    MaxDepth = 32,
                });
                var root = document.RootElement;
                if (!response.IsSuccessStatusCode ||
                    !root.TryGetProperty("ok", out var ok) ||
                    ok.ValueKind is not JsonValueKind.True)
                {
                    int? apiErrorCode = root.TryGetProperty("error_code", out var errorCode) &&
                        errorCode.TryGetInt32(out var parsed)
                            ? parsed
                            : null;
                    var reason = IsMessageNotModified(root)
                        ? "telegram_message_not_modified"
                        : "telegram_api_rejected";
                    throw new TelegramBotApiException(
                        reason,
                        statusCode,
                        apiErrorCode);
                }
                return document;
            }
            catch (JsonException)
            {
                document?.Dispose();
                throw new TelegramBotApiException("telegram_response_invalid", statusCode);
            }
            catch
            {
                document?.Dispose();
                throw;
            }
        }
    }

    private static async Task<byte[]> ReadBoundedAsync(
        HttpContent content,
        CancellationToken cancellationToken)
    {
        if (content.Headers.ContentLength is > MaximumResponseBytes)
        {
            throw new TelegramBotApiException("telegram_response_too_large");
        }
        await using var stream = await content.ReadAsStreamAsync(cancellationToken).ConfigureAwait(false);
        using var buffer = new MemoryStream();
        var scratch = new byte[16 * 1024];
        while (true)
        {
            var read = await stream.ReadAsync(scratch, cancellationToken).ConfigureAwait(false);
            if (read == 0)
            {
                return buffer.ToArray();
            }
            if (buffer.Length + read > MaximumResponseBytes)
            {
                throw new TelegramBotApiException("telegram_response_too_large");
            }
            buffer.Write(scratch, 0, read);
        }
    }

    private HttpRequestMessage JsonRequest(string method, object body) => new(
        HttpMethod.Post,
        MethodUri(method))
    {
        Content = JsonContent.Create(body, options: JsonOptions),
    };

    private string MethodUri(string method) => "/" + methodPrefix + method;

    private static JsonElement RequireResult(JsonElement root)
    {
        if (!root.TryGetProperty("result", out var result))
        {
            throw new TelegramBotApiException("telegram_result_missing");
        }
        return result;
    }

    private static long? ReadMessageId(JsonElement result)
    {
        if (result.ValueKind != JsonValueKind.Object)
        {
            throw new TelegramBotApiException("telegram_message_result_invalid");
        }
        return result.TryGetProperty("message_id", out var messageId) &&
            messageId.TryGetInt64(out var parsed)
                ? parsed
                : null;
    }

    private static object BuildReplyMarkup(TelegramMenuPlan menu) => new
    {
        inline_keyboard = menu.Rows.Select(row =>
            row.Select(BuildButtonMarkup).ToArray()).ToArray(),
    };

    private static IReadOnlyDictionary<string, string> BuildButtonMarkup(
        TelegramMenuButton button)
    {
        ArgumentNullException.ThrowIfNull(button);
        if (string.IsNullOrWhiteSpace(button.Text) || button.Text.Length > 128)
        {
            throw new ArgumentException("telegram_menu_button_text_invalid", nameof(button));
        }
        var hasCallback = !string.IsNullOrEmpty(button.CallbackData);
        var hasUrl = !string.IsNullOrEmpty(button.Url);
        if (hasCallback == hasUrl || button.CallbackData.Length > 64)
        {
            throw new ArgumentException("telegram_menu_button_target_invalid", nameof(button));
        }
        if (hasUrl &&
            (!Uri.TryCreate(button.Url, UriKind.Absolute, out var uri) ||
             !string.Equals(uri.Scheme, Uri.UriSchemeHttps, StringComparison.OrdinalIgnoreCase)))
        {
            throw new ArgumentException("telegram_menu_button_url_invalid", nameof(button));
        }
        return hasUrl
            ? new Dictionary<string, string>(StringComparer.Ordinal)
            {
                ["text"] = button.Text,
                ["url"] = button.Url,
            }
            : new Dictionary<string, string>(StringComparer.Ordinal)
            {
                ["text"] = button.Text,
                ["callback_data"] = button.CallbackData,
            };
    }

    private static bool IsMessageNotModified(JsonElement root) =>
        root.TryGetProperty("error_code", out var errorCode) &&
        errorCode.TryGetInt32(out var parsed) &&
        parsed == 400 &&
        root.TryGetProperty("description", out var description) &&
        description.ValueKind == JsonValueKind.String &&
        (description.GetString() ?? string.Empty).Contains(
            "message is not modified",
            StringComparison.OrdinalIgnoreCase);

    private static void ValidateMessage(long chatId, string html)
    {
        if (chatId == 0)
        {
            throw new ArgumentOutOfRangeException(nameof(chatId));
        }
        if (string.IsNullOrWhiteSpace(html) || html.Length > 4096)
        {
            throw new ArgumentException("telegram_message_invalid", nameof(html));
        }
    }

    private static void ValidateToken(string botToken)
    {
        if (string.IsNullOrWhiteSpace(botToken) ||
            botToken.Length > 256 ||
            botToken.Any(character =>
                character > 0x7f ||
                !(char.IsLetterOrDigit(character) || character is ':' or '_' or '-')))
        {
            throw new ArgumentException("telegram_bot_token_invalid", nameof(botToken));
        }
    }
}
