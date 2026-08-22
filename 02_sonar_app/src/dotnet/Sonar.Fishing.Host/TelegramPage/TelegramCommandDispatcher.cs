using System.Text;
using Sonar.Fishing.Host.SettingsPersistence;
using Sonar.Fishing.Host.StreamingPage;

namespace Sonar.Fishing.Host.TelegramPage;

public sealed class TelegramCommandDispatcher
{
    private const int MaximumActionHtmlLength = 4000;
    private readonly ITelegramBotApi api;
    private readonly Func<TelegramHostSettings> readSettings;
    private readonly Func<TelegramHostSettings, CancellationToken, Task> saveSettings;
    private readonly ITelegramProductUseCases product;
    private readonly IStreamingController streaming;

    public TelegramCommandDispatcher(
        ITelegramBotApi api,
        Func<TelegramHostSettings> readSettings,
        Func<TelegramHostSettings, CancellationToken, Task> saveSettings,
        ITelegramProductUseCases product,
        IStreamingController streaming)
    {
        this.api = api ?? throw new ArgumentNullException(nameof(api));
        this.readSettings = readSettings ?? throw new ArgumentNullException(nameof(readSettings));
        this.saveSettings = saveSettings ?? throw new ArgumentNullException(nameof(saveSettings));
        this.product = product ?? throw new ArgumentNullException(nameof(product));
        this.streaming = streaming ?? throw new ArgumentNullException(nameof(streaming));
    }

    public async Task DispatchAsync(
        TelegramInboundDecision decision,
        CancellationToken cancellationToken)
    {
        ArgumentNullException.ThrowIfNull(decision);
        cancellationToken.ThrowIfCancellationRequested();
        if (decision.ChatId == 0)
        {
            throw new ArgumentException("telegram_dispatch_chat_missing", nameof(decision));
        }

        switch (decision.Kind)
        {
            case TelegramInboundIntentKind.ShowMainMenu:
                await SendPlanAsync(
                    decision,
                    TelegramMenuPlanner.BuildMainMenu(
                        product.Current.Capabilities,
                        product.Current.Session.Running),
                    cancellationToken).ConfigureAwait(false);
                return;
            case TelegramInboundIntentKind.ShowNotifications:
                await SendPlanAsync(
                    decision,
                    TelegramMenuPlanner.BuildNotifications(readSettings()),
                    cancellationToken).ConfigureAwait(false);
                return;
            case TelegramInboundIntentKind.ToggleNotification:
            case TelegramInboundIntentKind.ToggleNotificationSound:
                await ToggleNotificationAsync(decision, cancellationToken).ConfigureAwait(false);
                return;
            case TelegramInboundIntentKind.ShowStatistics:
                await SendStatisticsAsync(decision.ChatId, cancellationToken).ConfigureAwait(false);
                return;
            case TelegramInboundIntentKind.ShowTackle:
                await SendTackleAsync(decision.ChatId, cancellationToken).ConfigureAwait(false);
                return;
            case TelegramInboundIntentKind.ShowPlayerStatus:
                await api.SendMessageAsync(
                    decision.ChatId,
                    TelegramNotificationPlanner.FormatPlayerStatus(product.Current.PlayerStatus),
                    silent: false,
                    menu: null,
                    cancellationToken).ConfigureAwait(false);
                return;
            case TelegramInboundIntentKind.ShowStream:
            case TelegramInboundIntentKind.OpenStream:
                await SendStreamMenuAsync(decision, cancellationToken).ConfigureAwait(false);
                return;
            case TelegramInboundIntentKind.ShowStreamQuality:
                await SendStreamQualityAsync(decision, cancellationToken).ConfigureAwait(false);
                return;
            case TelegramInboundIntentKind.SetStreamQuality:
            case TelegramInboundIntentKind.ToggleStream:
            case TelegramInboundIntentKind.SwitchStreamArea:
            case TelegramInboundIntentKind.SwitchStreamMode:
                await MutateStreamAsync(decision, cancellationToken).ConfigureAwait(false);
                return;
            case TelegramInboundIntentKind.ToggleFishing:
                await ExecuteProductActionAsync(
                    decision.ChatId,
                    TelegramProductAction.ToggleFishing,
                    requiredCapability: product.Current.Capabilities.Fishing,
                    unavailable: "🚤 Запуск рыбалки недоступен для этой подписки",
                    cancellationToken).ConfigureAwait(false);
                return;
            case TelegramInboundIntentKind.ScanPlayerStatus:
                await ExecuteProductActionAsync(
                    decision.ChatId,
                    TelegramProductAction.ScanPlayerStatus,
                    requiredCapability: true,
                    unavailable: "🔎 Сканирование показателей недоступно",
                    cancellationToken).ConfigureAwait(false);
                return;
            case TelegramInboundIntentKind.SendScreenshot:
                await ExecuteProductActionAsync(
                    decision.ChatId,
                    TelegramProductAction.SendScreenshot,
                    requiredCapability: true,
                    unavailable: "⚠️ Скриншот недоступен",
                    cancellationToken).ConfigureAwait(false);
                return;
            case TelegramInboundIntentKind.FocusGame:
                await ExecuteProductActionAsync(
                    decision.ChatId,
                    TelegramProductAction.FocusGame,
                    requiredCapability: true,
                    unavailable: "⚠️ Не удалось вернуть фокус игре",
                    cancellationToken).ConfigureAwait(false);
                return;
            case TelegramInboundIntentKind.ShutdownPc:
                await ExecuteProductActionAsync(
                    decision.ChatId,
                    TelegramProductAction.ShutdownPc,
                    requiredCapability: true,
                    unavailable: "⚠️ Выключение ПК недоступно",
                    cancellationToken).ConfigureAwait(false);
                return;
            case TelegramInboundIntentKind.ShutdownGame:
                await ExecuteProductActionAsync(
                    decision.ChatId,
                    TelegramProductAction.ShutdownGame,
                    requiredCapability: true,
                    unavailable: "⚠️ Выключение игры недоступно",
                    cancellationToken).ConfigureAwait(false);
                return;
            case TelegramInboundIntentKind.Ignore:
            case TelegramInboundIntentKind.AcknowledgeOnly:
                return;
            default:
                throw new ArgumentOutOfRangeException(nameof(decision));
        }
    }

    private async Task ToggleNotificationAsync(
        TelegramInboundDecision decision,
        CancellationToken cancellationToken)
    {
        var current = readSettings();
        if (TelegramSettingsReducer.TryApply(current, decision, out var updated))
        {
            await saveSettings(updated, cancellationToken).ConfigureAwait(false);
        }
        await SendPlanAsync(
            decision,
            TelegramMenuPlanner.BuildNotifications(updated),
            cancellationToken).ConfigureAwait(false);
    }

    private async Task SendStatisticsAsync(
        long chatId,
        CancellationToken cancellationToken)
    {
        var state = product.Current;
        string html;
        if (!state.Capabilities.Statistics)
        {
            html = "📊 Статистика недоступна для этой подписки";
        }
        else if (state.Session.Totals.CaughtCount == 0)
        {
            html = "📊 В текущей сессии пока нет улова";
        }
        else
        {
            html = TelegramNotificationPlanner.FormatSessionStatistics(
                "📊 Текущая статистика",
                "🎣 Сессия рыбалки",
                state.Session.Totals,
                rows: state.Session.FishRows);
            if (html.Length > MaximumActionHtmlLength)
            {
                html = TelegramNotificationPlanner.FormatSessionStatistics(
                    "📊 Текущая статистика",
                    "🎣 Сессия рыбалки",
                    state.Session.Totals);
            }
        }
        await api.SendMessageAsync(
            chatId,
            html,
            silent: false,
            menu: null,
            cancellationToken).ConfigureAwait(false);
    }

    private async Task SendTackleAsync(
        long chatId,
        CancellationToken cancellationToken)
    {
        var state = product.Current;
        if (!state.Capabilities.Tackle)
        {
            await api.SendMessageAsync(
                chatId,
                "🎒 Снаряжение недоступно для этой подписки",
                silent: false,
                menu: null,
                cancellationToken).ConfigureAwait(false);
            return;
        }
        var html = FormatTackle(state);
        if (!state.TacklePng.IsEmpty)
        {
            await api.SendPhotoAsync(
                chatId,
                state.TacklePng,
                html,
                silent: false,
                menu: null,
                cancellationToken).ConfigureAwait(false);
            return;
        }
        await api.SendMessageAsync(
            chatId,
            html,
            silent: false,
            menu: null,
            cancellationToken).ConfigureAwait(false);
    }

    private async Task SendStreamMenuAsync(
        TelegramInboundDecision decision,
        CancellationToken cancellationToken)
    {
        if (!product.Current.Capabilities.Streaming)
        {
            await SendPlanAsync(
                decision,
                TelegramMenuPlanner.BuildUnavailable("Стрим"),
                cancellationToken).ConfigureAwait(false);
            return;
        }
        await SendPlanAsync(
            decision,
            TelegramMenuPlanner.BuildStreamMenu(streaming.Current),
            cancellationToken).ConfigureAwait(false);
    }

    private async Task SendStreamQualityAsync(
        TelegramInboundDecision decision,
        CancellationToken cancellationToken)
    {
        if (!product.Current.Capabilities.Streaming)
        {
            await SendPlanAsync(
                decision,
                TelegramMenuPlanner.BuildUnavailable("Стрим"),
                cancellationToken).ConfigureAwait(false);
            return;
        }
        await SendPlanAsync(
            decision,
            TelegramMenuPlanner.BuildStreamQuality(streaming.Current.Quality),
            cancellationToken).ConfigureAwait(false);
    }

    private async Task MutateStreamAsync(
        TelegramInboundDecision decision,
        CancellationToken cancellationToken)
    {
        if (!product.Current.Capabilities.Streaming)
        {
            await SendPlanAsync(
                decision,
                TelegramMenuPlanner.BuildUnavailable("Стрим"),
                cancellationToken).ConfigureAwait(false);
            return;
        }

        StreamingCommandResult result;
        try
        {
            result = decision.Kind switch
            {
                TelegramInboundIntentKind.SetStreamQuality => streaming.SetQuality(decision.Value),
                TelegramInboundIntentKind.ToggleStream => streaming.Current.Active ||
                    streaming.Current.Status is StreamingRuntimeStatus.Starting or StreamingRuntimeStatus.Preparing
                        ? streaming.Stop("telegram_command")
                        : streaming.Start(),
                TelegramInboundIntentKind.SwitchStreamArea =>
                    streaming.SetChatZoom(!streaming.Current.ChatZoomEnabled),
                TelegramInboundIntentKind.SwitchStreamMode =>
                    streaming.SetSnapshotMode(!streaming.Current.SnapshotModeEnabled),
                _ => throw new ArgumentOutOfRangeException(nameof(decision)),
            };
        }
        catch (Exception) when (!cancellationToken.IsCancellationRequested)
        {
            await api.SendMessageAsync(
                decision.ChatId,
                "⚠️ Не удалось изменить настройки стрима.",
                silent: false,
                menu: null,
                cancellationToken).ConfigureAwait(false);
            return;
        }
        if (!result.Accepted)
        {
            await api.SendMessageAsync(
                decision.ChatId,
                "⚠️ Не удалось изменить настройки стрима.",
                silent: false,
                menu: null,
                cancellationToken).ConfigureAwait(false);
        }
        await SendPlanAsync(
            decision,
            TelegramMenuPlanner.BuildStreamMenu(result.Snapshot),
            cancellationToken).ConfigureAwait(false);
    }

    private async Task ExecuteProductActionAsync(
        long chatId,
        TelegramProductAction action,
        bool requiredCapability,
        string unavailable,
        CancellationToken cancellationToken)
    {
        TelegramProductActionResult result;
        if (!requiredCapability)
        {
            result = TelegramProductActionResult.Rejected(unavailable);
        }
        else
        {
            try
            {
                result = await product.ExecuteAsync(action, cancellationToken).ConfigureAwait(false);
            }
            catch (OperationCanceledException) when (cancellationToken.IsCancellationRequested)
            {
                throw;
            }
            catch
            {
                result = TelegramProductActionResult.Rejected(unavailable);
            }
        }
        var html = ValidActionHtml(result.Html) ? result.Html : unavailable;
        if (result.Accepted && !result.Png.IsEmpty)
        {
            await api.SendPhotoAsync(
                chatId,
                result.Png,
                html,
                silent: false,
                menu: null,
                cancellationToken).ConfigureAwait(false);
            return;
        }
        await api.SendMessageAsync(
            chatId,
            html,
            silent: false,
            menu: null,
            cancellationToken).ConfigureAwait(false);
    }

    private async Task SendPlanAsync(
        TelegramInboundDecision decision,
        TelegramMenuPlan plan,
        CancellationToken cancellationToken)
    {
        if (decision.MessageId is not { } messageId)
        {
            await api.SendMessageAsync(
                decision.ChatId,
                plan.Text,
                silent: false,
                plan,
                cancellationToken).ConfigureAwait(false);
            return;
        }
        try
        {
            await api.EditMessageAsync(
                decision.ChatId,
                messageId,
                plan.Text,
                plan,
                cancellationToken).ConfigureAwait(false);
        }
        catch (TelegramBotApiException exception)
            when (exception.Reason == "telegram_message_not_modified")
        {
        }
        catch (TelegramBotApiException)
        {
            await api.SendMessageAsync(
                decision.ChatId,
                plan.Text,
                silent: false,
                plan,
                cancellationToken).ConfigureAwait(false);
        }
    }

    private static string FormatTackle(TelegramProductState state)
    {
        if (state.Session.TackleItems.Count == 0)
        {
            return "🎒 Снаряжение\n\nПоследнего сканирования ещё нет.";
        }
        var text = new StringBuilder("🎒 <b>Снаряжение</b>\n\n");
        foreach (var item in state.Session.TackleItems.OrderBy(item => item.Name, StringComparer.Ordinal))
        {
            var line = $"• {Html(item.Name)}: <b>{item.Count}</b>\n";
            if (text.Length + line.Length > MaximumActionHtmlLength)
            {
                break;
            }
            text.Append(line);
        }
        return text.ToString().TrimEnd();
    }

    private static bool ValidActionHtml(string html) =>
        !string.IsNullOrWhiteSpace(html) && html.Length <= MaximumActionHtmlLength;

    private static string Html(string value) => value
        .Replace("&", "&amp;", StringComparison.Ordinal)
        .Replace("<", "&lt;", StringComparison.Ordinal)
        .Replace(">", "&gt;", StringComparison.Ordinal);
}
