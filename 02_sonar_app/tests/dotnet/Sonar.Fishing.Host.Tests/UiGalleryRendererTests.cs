namespace Sonar.Fishing.Host.Tests;

internal static class UiGalleryRendererTests
{
    public static IReadOnlyList<TestCase> Create() =>
    [
        new("ui_gallery_covers_all_pages_layout_modes_and_dpi_targets", CoverageIsComplete),
        new("ui_gallery_reports_the_loaded_common_ui_version", ReportsLoadedCommonUiVersion),
    ];

    private static void ReportsLoadedCommonUiVersion()
    {
        var version = typeof(Sonar.UI.Wpf.ThemeCatalog).Assembly.GetName().Version
            ?? throw new InvalidOperationException("Common UI assembly version is unavailable.");
        TestAssert.Equal(
            $"{version.Major}.{version.Minor}.{version.Build}",
            UiGalleryRenderer.CommonUiVersion,
            "UI gallery manifest version drifted from the assembly used to render it");
    }

    private static void CoverageIsComplete()
    {
        var definitions = UiGalleryRenderer.Definitions;
        TestAssert.Equal(204, definitions.Count, "UI gallery render matrix is incomplete");
        TestAssert.Equal(
            204,
            definitions.Select(definition =>
                $"{definition.PageId}/{definition.VariantId}/{definition.LayoutId}/{definition.DpiPercent}")
                .Distinct(StringComparer.Ordinal)
                .Count(),
            "UI gallery render matrix contains duplicate cases");
        TestAssert.Equal(
            11,
            definitions.Select(definition => definition.PageId)
                .Distinct(StringComparer.Ordinal)
                .Count(),
            "UI gallery does not cover every product page");
        TestAssert.Equal(
            12,
            definitions.Count(definition =>
                definition is { PageId: "fishing", VariantId: "session" }),
            "UI gallery does not cover the responsive session and tackle surface");
        TestAssert.Equal(
            3,
            definitions.Select(definition => definition.LayoutId)
                .Distinct(StringComparer.Ordinal)
                .Count(),
            "UI gallery does not cover compact, medium, and expanded layouts");
        TestAssert.Equal(
            4,
            definitions.Select(definition => definition.DpiPercent)
                .Distinct()
                .Count(),
            "UI gallery does not cover 100, 125, 150, and 200 percent DPI");
        TestAssert.Equal(
            12,
            definitions.Count(definition =>
                definition is { PageId: "settings", VariantId: "fish-selection" }),
            "UI gallery does not cover the complete responsive fish-selection surface");
        TestAssert.Equal(
            12,
            definitions.Count(definition =>
                definition is { PageId: "settings", VariantId: "thresholds" }),
            "UI gallery does not cover the Common threshold-slider surface");
        TestAssert.Equal(
            12,
            definitions.Count(definition =>
                definition is { PageId: "settings", VariantId: "hotkey-conflict" }),
            "UI gallery does not cover the hotkey-conflict warning state");
        foreach (var variant in new[] { "checking", "blocked", "unavailable" })
        {
            TestAssert.Equal(
                12,
                definitions.Count(definition =>
                    definition.PageId == "startup" && definition.VariantId == variant),
                $"UI gallery does not cover startup state {variant}");
        }
    }
}
