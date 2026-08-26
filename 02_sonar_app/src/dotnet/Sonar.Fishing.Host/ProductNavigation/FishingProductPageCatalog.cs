using System.Collections.ObjectModel;

namespace Sonar.Fishing.Host.ProductNavigation;

public enum FishingProductPageId
{
    Overview,
    License,
    Fishing,
    Inventory,
    Settings,
    Statistics,
    Streaming,
    Telegram,
    About,
}

public sealed record FishingProductPageDescriptor(
    FishingProductPageId Id,
    string Title,
    string IconResourceKey,
    string? RequiredFeature);

public static class FishingProductPageCatalog
{
    private static readonly ReadOnlyCollection<FishingProductPageDescriptor> Pages =
        Array.AsReadOnly<FishingProductPageDescriptor>(
        [
            new(FishingProductPageId.Overview, "Обзор", "menu", "overview"),
            new(FishingProductPageId.License, "Лицензия", "id_card", null),
            new(FishingProductPageId.Fishing, "Рыбалка", "fishing_rod", "fishing"),
            new(FishingProductPageId.Inventory, "Инвентарь", "inventory", "fishing"),
            new(FishingProductPageId.Settings, "Настройки", "settings", "settings"),
            new(FishingProductPageId.Statistics, "Статистика", "chart", "statistics"),
            new(FishingProductPageId.Streaming, "Стрим", "stream", "stream"),
            new(FishingProductPageId.Telegram, "Telegram", "telegram_outline", "telegram"),
            new(FishingProductPageId.About, "О программе", "info", null),
        ]);

    public static IReadOnlyList<FishingProductPageDescriptor> All => Pages;

    public static FishingProductPageId InitialPage => FishingProductPageId.License;

    public static FishingProductPageId ResolveAllowed(
        FishingProductPageId preferred,
        IReadOnlySet<string> allowedFeatures)
    {
        ArgumentNullException.ThrowIfNull(allowedFeatures);
        var descriptor = Pages.Single(page => page.Id == preferred);
        return descriptor.RequiredFeature is null ||
            allowedFeatures.Contains(descriptor.RequiredFeature)
            ? preferred
            : FishingProductPageId.License;
    }
}
