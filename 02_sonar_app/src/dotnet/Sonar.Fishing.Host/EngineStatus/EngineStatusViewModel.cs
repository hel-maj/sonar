using Sonar.UI.Wpf.Controls;
using Sonar.Fishing.Host.FishingSessionState;

namespace Sonar.Fishing.Host.EngineStatus;

public sealed record EngineStatusViewModel(
    string Title,
    string Description,
    string BadgeText,
    SemanticTone BadgeTone,
    bool CanStart,
    bool CanStop,
    bool ShowActions)
{
    public static EngineStatusViewModel MigrationPreview { get; } = new(
        Title: "Готово к настройке",
        Description: "Активируйте лицензию и проверьте настройки перед запуском.",
        BadgeText: "Ожидание",
        BadgeTone: SemanticTone.Neutral,
        CanStart: false,
        CanStop: false,
        ShowActions: false);

    public static EngineStatusViewModel FromSnapshot(EngineSessionSnapshot snapshot)
    {
        ArgumentNullException.ThrowIfNull(snapshot);

        if (snapshot.Stopping)
        {
            return new EngineStatusViewModel(
                Title: "Остановка",
                Description: "Завершаем текущие операции",
                BadgeText: "Остановка",
                BadgeTone: SemanticTone.Warning,
                CanStart: false,
                CanStop: false,
                ShowActions: true);
        }

        if (snapshot.Running)
        {
            return new EngineStatusViewModel(
                Title: "Работает",
                Description: FormatDetectedStage(snapshot.DetectedStage),
                BadgeText: "Активен",
                BadgeTone: SemanticTone.Success,
                CanStart: false,
                CanStop: true,
                ShowActions: true);
        }

        return new EngineStatusViewModel(
            Title: "Можно начинать",
            Description: "При необходимости измените настройки перед запуском.",
            BadgeText: "Готово",
            BadgeTone: SemanticTone.Success,
            CanStart: true,
            CanStop: false,
            ShowActions: true);
    }

    public static EngineStatusViewModel FromSessionState(
        FishingSessionStateSnapshot snapshot)
    {
        ArgumentNullException.ThrowIfNull(snapshot);
        var mapped = FromSnapshot(new EngineSessionSnapshot(
            snapshot.Running,
            snapshot.Stopping,
            snapshot.DetectedStage));
        return mapped;
    }

    internal static EngineStatusViewModel FromProductionSessionState(
        FishingSessionStateSnapshot snapshot)
    {
        ArgumentNullException.ThrowIfNull(snapshot);
        var mapped = FromSnapshot(new EngineSessionSnapshot(
            snapshot.Running,
            snapshot.Stopping,
            snapshot.DetectedStage));
        return mapped;
    }

    internal EngineStatusViewModel WithCommandRejection(string reason)
    {
        var description = reason switch
        {
            "active_entitlement_required" or "production_entitlement_required" =>
                "Сначала активируйте лицензию.",
            "settings_revision_mismatch" or "runtime_settings_revision_mismatch" =>
                "Настройки изменились. Сохраните их и повторите команду.",
            "side_effects_not_negotiated" =>
                "Запуск сейчас недоступен. Повторите попытку позже.",
            _ => "Команда отклонена. Проверьте лицензию и настройки.",
        };
        return this with
        {
            Title = "Команда не выполнена",
            Description = description,
            BadgeText = "Заблокировано",
            BadgeTone = SemanticTone.Warning,
        };
    }

    internal static EngineStatusViewModel FromBoundaryFailure(bool canRetry) => new(
        Title: "Автоматизация недоступна",
        Description: "Рыбалка остановлена. Восстановление продолжается автоматически; повторите команду, когда статус снова станет готовым.",
        BadgeText: "Ошибка",
        BadgeTone: SemanticTone.Danger,
        CanStart: canRetry,
        CanStop: false,
        ShowActions: true);

    private static string FormatDetectedStage(string detectedStage)
    {
        var normalized = detectedStage.Trim();
        if (normalized.Length == 0)
        {
            return "Выполняется текущий цикл";
        }
        var knownStage = normalized.ToLowerInvariant() switch
        {
            "started" or "session_started" or "already_running" => "Рыбалка началась",
            "read_only_session_started" => "Локальный режим готов",
            "casting" => "Забрасываем удочку",
            "waiting_for_bite" => "Ожидаем поклёвку",
            "reeling" => "Вытягиваем улов",
            "tackle_selection" => "Выбираем снасти",
            _ => null,
        };
        if (knownStage is not null)
        {
            return knownStage;
        }
        return normalized.Any(character => character is >= 'А' and <= 'я' or 'Ё' or 'ё')
            ? normalized
            : "Выполняется текущий цикл";
    }
}
