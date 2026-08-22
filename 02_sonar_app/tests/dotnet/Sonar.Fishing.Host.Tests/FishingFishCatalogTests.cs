using System.IO;
using System.Windows;
using Sonar.Fishing.Host.ProductCatalog;
using Sonar.Fishing.Host.SettingsPage;
using Sonar.Fishing.Host.SettingsPersistence;

namespace Sonar.Fishing.Host.Tests;

internal static class FishingFishCatalogTests
{
    public static IReadOnlyList<TestCase> Create() =>
    [
        new("fish_catalog_is_one_embedded_31_entry_product_contract", CatalogIsEmbedded),
        new("fish_catalog_default_and_bulk_selection_match_legacy_semantics", SelectionMatches),
    ];

    private static void CatalogIsEmbedded()
    {
        var catalog = FishingFishCatalog.All;
        TestAssert.Equal(31, catalog.Count, "Fish catalog count changed");
        TestAssert.Equal(31, FishingFishCatalog.AllIds.Count, "Fish catalog id count changed");
        TestAssert.Equal("Альбула", catalog[0].DisplayName, "Fish catalog sorting changed");
        var marlin = catalog.Single(fish => fish.Id == "marlin");
        TestAssert.Equal("Марлин", marlin.DisplayName, "Fish display name changed");
        TestAssert.Equal(670.0, marlin.Price!.Per1000Min, "Fish base price changed");
        foreach (var fish in catalog)
        {
            var uri = new Uri(
                $"pack://application:,,,/Sonar.Fishing.Host;component/Assets/Fish/{fish.Id}.png",
                UriKind.Absolute);
            using var stream = Application.GetResourceStream(uri)?.Stream;
            TestAssert.True(
                stream is { Length: > 0 },
                $"Embedded fish image is missing: {fish.Id}");
        }
        TestAssert.True(
            !Directory.Exists(Path.Combine(AppContext.BaseDirectory, "Assets", "Fish")),
            "Fish images leaked into output as loose runtime assets");
        TestAssert.True(
            !File.Exists(Path.Combine(AppContext.BaseDirectory, "fish-catalog.json")),
            "Fish catalog leaked into output as a loose runtime asset");
    }

    private static void SelectionMatches()
    {
        var defaults = FishingRuntimeSettings.CreateDefault();
        TestAssert.Equal(31, defaults.Selection.FishKeep.Count, "Default fish selection is incomplete");
        TestAssert.True(
            defaults.Selection.FishKeep.Values.All(keep => keep),
            "Default fish selection no longer keeps every fish");
        var viewModel = new FishingSettingsPageViewModel(defaults);
        TestAssert.Equal(16, viewModel.FishColumnOne.Count, "First fish column count changed");
        TestAssert.Equal(15, viewModel.FishColumnTwo.Count, "Second fish column count changed");

        viewModel.ClearAllFishCommand.Execute(null);
        TestAssert.True(viewModel.IsDirty, "Clear-all fish selection did not mark settings dirty");
        TestAssert.True(
            viewModel.FishColumnOne.Concat(viewModel.FishColumnTwo).All(fish => !fish.Keep),
            "Clear-all fish selection left selected rows");
        viewModel.DiscardCommand.Execute(null);
        TestAssert.True(
            viewModel.FishColumnOne.Concat(viewModel.FishColumnTwo).All(fish => fish.Keep),
            "Discard did not restore fish selection");
    }
}
