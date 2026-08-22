using System.Net;
using System.Net.Http;
using System.Text;
using System.Text.Json;
using Sonar.Fishing.Host.TelegramPage;

namespace Sonar.Fishing.Host.Tests;

internal static class TelegramBotApiClientTests
{
    private const string Token = "12345:abc_TEST-1234567890";

    public static IReadOnlyList<TestCase> Create() =>
    [
        new("telegram_http_client_sends_bounded_html_and_menu_contract", SendMessageMatches),
        new("telegram_http_client_edits_message_and_supports_https_url_button", EditMessageMatches),
        new("telegram_http_client_parses_offset_long_poll_without_network", GetUpdatesMatches),
        new("telegram_http_client_sends_photo_as_bounded_multipart", SendPhotoMatches),
        new("telegram_http_client_classifies_unchanged_edit_without_response_leak", UnchangedEditMatches),
        new("telegram_http_client_redacts_token_from_stable_failures", FailureRedactsToken),
    ];

    private static void SendMessageMatches()
    {
        CapturedRequest? captured = null;
        using var httpClient = Client(request =>
        {
            captured = request;
            return JsonResponse(HttpStatusCode.OK, "{\"ok\":true,\"result\":{\"message_id\":77}}");
        });
        var api = new TelegramBotApiClient(httpClient, Token);
        var menu = new TelegramMenuPlan(
            "menu",
            [[new TelegramMenuButton("Статистика", "action:stats")]]);

        var messageId = api.SendMessageAsync(
            42,
            "<b>Готово</b>",
            silent: true,
            menu,
            CancellationToken.None).GetAwaiter().GetResult();

        TestAssert.Equal<long>(77, messageId!.Value, "Telegram message id was not parsed");
        TestAssert.Equal(HttpMethod.Post, captured!.Method, "Telegram message did not use POST");
        TestAssert.Equal(
            $"/bot{Token}/sendMessage",
            captured.Uri.AbsolutePath,
            "Telegram message endpoint changed");
        using var body = JsonDocument.Parse(captured.Body);
        var root = body.RootElement;
        TestAssert.Equal(42L, root.GetProperty("chat_id").GetInt64(), "Telegram chat id changed");
        TestAssert.Equal("HTML", root.GetProperty("parse_mode").GetString()!, "HTML mode changed");
        TestAssert.True(root.GetProperty("disable_notification").GetBoolean(), "Silent policy changed");
        TestAssert.True(
            root.GetProperty("link_preview_options").GetProperty("is_disabled").GetBoolean(),
            "Link preview was not disabled");
        var callback = root.GetProperty("reply_markup")
            .GetProperty("inline_keyboard")[0][0]
            .GetProperty("callback_data")
            .GetString();
        TestAssert.Equal("action:stats", callback!, "Inline menu callback changed");
    }

    private static void EditMessageMatches()
    {
        CapturedRequest? captured = null;
        using var httpClient = Client(request =>
        {
            captured = request;
            return JsonResponse(HttpStatusCode.OK, "{\"ok\":true,\"result\":{\"message_id\":77}}");
        });
        var api = new TelegramBotApiClient(httpClient, Token);
        var menu = new TelegramMenuPlan(
            "stream",
            [[new TelegramMenuButton("Открыть", Url: "https://stream.example/live/")]]);

        api.EditMessageAsync(
            42,
            77,
            "<b>Стрим</b>",
            menu,
            CancellationToken.None).GetAwaiter().GetResult();

        TestAssert.Equal(
            $"/bot{Token}/editMessageText",
            captured!.Uri.AbsolutePath,
            "Telegram edit endpoint changed");
        using var body = JsonDocument.Parse(captured.Body);
        TestAssert.Equal(77L, body.RootElement.GetProperty("message_id").GetInt64(), "Edit message id changed");
        var url = body.RootElement.GetProperty("reply_markup")
            .GetProperty("inline_keyboard")[0][0]
            .GetProperty("url")
            .GetString();
        TestAssert.Equal("https://stream.example/live/", url!, "HTTPS menu URL changed");
    }

    private static void GetUpdatesMatches()
    {
        CapturedRequest? captured = null;
        using var httpClient = Client(request =>
        {
            captured = request;
            return JsonResponse(
                HttpStatusCode.OK,
                "{\"ok\":true,\"result\":[{\"update_id\":9,\"message\":{\"chat\":{\"id\":42},\"text\":\"/menu\"}}]}");
        });
        var api = new TelegramBotApiClient(httpClient, Token);

        var updates = api.GetUpdatesAsync(
            offset: 9,
            longPollingTimeoutSeconds: 20,
            CancellationToken.None).GetAwaiter().GetResult();

        TestAssert.Equal(1, updates.Count, "Telegram update count changed");
        TestAssert.Equal(9L, updates[0].UpdateId, "Telegram update id changed");
        using var update = JsonDocument.Parse(updates[0].Utf8Json);
        TestAssert.Equal("/menu", update.RootElement.GetProperty("message").GetProperty("text").GetString()!, "Update payload changed");
        using var body = JsonDocument.Parse(captured!.Body);
        TestAssert.Equal(9L, body.RootElement.GetProperty("offset").GetInt64(), "Polling offset changed");
        TestAssert.Equal(20, body.RootElement.GetProperty("timeout").GetInt32(), "Long-poll timeout changed");
        TestAssert.True(
            body.RootElement.GetProperty("allowed_updates")
                .EnumerateArray()
                .Select(value => value.GetString())
                .SequenceEqual(["message", "callback_query"], StringComparer.Ordinal),
            "Allowed Telegram updates changed");
    }

    private static void SendPhotoMatches()
    {
        CapturedRequest? captured = null;
        using var httpClient = Client(request =>
        {
            captured = request;
            return JsonResponse(HttpStatusCode.OK, "{\"ok\":true,\"result\":{\"message_id\":91}}");
        });
        var api = new TelegramBotApiClient(httpClient, Token);
        var png = new byte[] { 0x89, 0x50, 0x4e, 0x47, 1, 2, 3 };

        var messageId = api.SendPhotoAsync(
            42,
            png,
            "<b>Улов</b>",
            silent: false,
            menu: null,
            CancellationToken.None).GetAwaiter().GetResult();

        TestAssert.Equal<long>(91, messageId!.Value, "Telegram photo message id changed");
        TestAssert.Equal(
            $"/bot{Token}/sendPhoto",
            captured!.Uri.AbsolutePath,
            "Telegram photo endpoint changed");
        TestAssert.True(
            captured.ContentType.StartsWith("multipart/form-data;", StringComparison.OrdinalIgnoreCase),
            "Telegram photo did not use multipart form data");
        var body = Encoding.UTF8.GetString(captured.Body);
        TestAssert.True(body.Contains("name=photo", StringComparison.Ordinal), "Photo field is missing");
        TestAssert.True(body.Contains("filename=screen.png", StringComparison.Ordinal), "Photo filename changed");
        TestAssert.True(body.Contains("<b>Улов</b>", StringComparison.Ordinal), "Photo caption changed");
    }

    private static void FailureRedactsToken()
    {
        using var httpClient = new HttpClient(new ThrowingHandler())
        {
            BaseAddress = new Uri("https://api.telegram.test/"),
        };
        var api = new TelegramBotApiClient(httpClient, Token);

        var exception = TestAssert.Throws<TelegramBotApiException>(
            () => api.SendMessageAsync(
                42,
                "test",
                silent: false,
                menu: null,
                CancellationToken.None).GetAwaiter().GetResult(),
            "Telegram HTTP failure escaped as an unstable exception");

        TestAssert.Equal("telegram_http_unavailable", exception.Reason, "Telegram failure reason changed");
        TestAssert.True(
            !exception.ToString().Contains(Token, StringComparison.Ordinal),
            "Telegram token leaked into failure text");
    }

    private static void UnchangedEditMatches()
    {
        using var httpClient = Client(_ => JsonResponse(
            HttpStatusCode.BadRequest,
            "{\"ok\":false,\"error_code\":400,\"description\":\"Bad Request: message is not modified\"}"));
        var api = new TelegramBotApiClient(httpClient, Token);

        var exception = TestAssert.Throws<TelegramBotApiException>(
            () => api.EditMessageAsync(
                42,
                77,
                "same",
                menu: null,
                CancellationToken.None).GetAwaiter().GetResult(),
            "Unchanged Telegram edit was not classified");

        TestAssert.Equal(
            "telegram_message_not_modified",
            exception.Reason,
            "Unchanged edit reason changed");
        TestAssert.True(
            !exception.ToString().Contains("Bad Request", StringComparison.Ordinal),
            "Telegram API description leaked into an exception");
    }

    private static HttpClient Client(Func<CapturedRequest, HttpResponseMessage> responder) => new(
        new CapturingHandler(responder))
    {
        BaseAddress = new Uri("https://api.telegram.test/"),
        Timeout = Timeout.InfiniteTimeSpan,
    };

    private static HttpResponseMessage JsonResponse(HttpStatusCode status, string json) => new(status)
    {
        Content = new StringContent(json, Encoding.UTF8, "application/json"),
    };

    private sealed record CapturedRequest(
        HttpMethod Method,
        Uri Uri,
        string ContentType,
        byte[] Body);

    private sealed class CapturingHandler(Func<CapturedRequest, HttpResponseMessage> responder)
        : HttpMessageHandler
    {
        protected override async Task<HttpResponseMessage> SendAsync(
            HttpRequestMessage request,
            CancellationToken cancellationToken)
        {
            var body = request.Content is null
                ? Array.Empty<byte>()
                : await request.Content.ReadAsByteArrayAsync(cancellationToken);
            var captured = new CapturedRequest(
                request.Method,
                request.RequestUri!,
                request.Content?.Headers.ContentType?.ToString() ?? string.Empty,
                body);
            return responder(captured);
        }
    }

    private sealed class ThrowingHandler : HttpMessageHandler
    {
        protected override Task<HttpResponseMessage> SendAsync(
            HttpRequestMessage request,
            CancellationToken cancellationToken) =>
            throw new HttpRequestException($"unsafe transport detail: {request.RequestUri}");
    }
}
