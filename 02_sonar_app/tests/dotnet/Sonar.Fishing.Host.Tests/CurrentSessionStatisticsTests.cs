using Sonar.Fishing.Host.FishingSessionState;
using Sonar.Fishing.Host.StatisticsPage;

namespace Sonar.Fishing.Host.Tests;

internal static class CurrentSessionStatisticsTests
{
    public static IReadOnlyList<TestCase> Create() =>
    [
        new("current_statistics_maps_exact_metrics_rows_and_chart_union", MapsExactUnion),
        new("current_statistics_snapshot_defensively_freezes_rows_and_buckets", SnapshotFreezesCollections),
        new("current_statistics_rejects_inconsistent_native_aggregate", RejectsInconsistentAggregate),
        new("current_statistics_custom_price_normalizes_and_persists", CustomPricePersists),
        new("current_statistics_reset_uses_coarse_session_command", ResetUsesCoarseCommand),
    ];

    private static void MapsExactUnion()
    {
        var model = CurrentSessionStatisticsViewModel.FromSnapshot(CreateSnapshot());

        TestAssert.Equal("1 ч 0 мин", model.Duration, "Statistics duration changed");
        TestAssert.Equal("2 шт · 5.1 кг", model.Caught, "Caught summary changed");
        TestAssert.Equal("1 шт · 3.1 кг", model.Kept, "Kept summary changed");
        TestAssert.Equal("3.1 кг", model.KeptWeight, "Kept weight changed");
        TestAssert.Equal("от 2 077 $ до 2 263 $", model.Income, "Income range changed");
        TestAssert.Equal("от 2 077 $ до 2 263 $", model.IncomePerHour, "Hourly income changed");
        TestAssert.True(model.HasCatches, "Populated session was shown as empty");
        TestAssert.Equal(1, model.FishRows.Count, "Fish row was lost");
        var row = model.FishRows[0];
        TestAssert.Equal("fish/marlin", row.IconResourceKey, "Product fish icon key changed");
        TestAssert.Equal("0.67-0.73 $/шт · 670-730 $/1000", row.BasePrice, "Base price changed");
        TestAssert.Equal("", row.CustomPrice, "Missing custom price became a value");
        TestAssert.Equal(2, model.CatchSizes.Count, "Chart buckets changed");
    }

    private static void SnapshotFreezesCollections()
    {
        var rows = new List<FishingSessionFishRowSnapshot>
        {
            CreateRow(),
        };
        var buckets = new List<FishingCatchSizeSnapshot>
        {
            new("good", "Хороший улов", 1, 50),
        };
        var snapshot = new FishingSessionStateSnapshot(
            1,
            false,
            false,
            "idle",
            new FishingSessionTotalsSnapshot(0, 0, 0, 0, 0, 0, 0),
            [],
            fishRows: rows,
            catchSizes: buckets);
        rows.Clear();
        buckets.Clear();

        TestAssert.Equal(1, snapshot.FishRows.Count, "Caller mutation removed fish row");
        TestAssert.Equal(1, snapshot.CatchSizes.Count, "Caller mutation removed chart bucket");
    }

    private static void RejectsInconsistentAggregate()
    {
        TestAssert.Throws<ArgumentException>(
            () => new FishingSessionStateSnapshot(
                1,
                false,
                false,
                "idle",
                new FishingSessionTotalsSnapshot(0, 0, 0, 0, 0, 0, 0),
                [],
                fishRows:
                [
                    CreateRow() with
                    {
                        CaughtCount = 1,
                        ReleasedCount = 1,
                        KeptCount = 1,
                    },
                ]),
            "Inconsistent kept count was accepted");
    }

    private static void CustomPricePersists()
    {
        var changes = new List<(string FishId, double? Price)>();
        var model = CurrentSessionStatisticsViewModel.FromSnapshot(
            CreateSnapshot(),
            (fishId, price) =>
            {
                changes.Add((fishId, price));
                return true;
            });
        var row = model.FishRows.Single();

        row.CustomPrice = "7x01";
        TestAssert.Equal("701", row.CustomPrice, "Custom price was not normalized to legacy digits-only input");
        TestAssert.Equal(("marlin", (double?)701), changes.Single(), "Custom price persistence changed");

        row.CustomPrice = "0";
        TestAssert.Equal("", row.CustomPrice, "Zero custom price was not removed");
        TestAssert.Equal(("marlin", (double?)null), changes[^1], "Custom price removal changed");
    }

    private static void ResetUsesCoarseCommand()
    {
        var resets = 0;
        var model = new StatisticsPageViewModel(
            CreateSnapshot(),
            resetSession: () =>
            {
                resets++;
                return FishingSessionStateSnapshot.Empty;
            });

        TestAssert.True(model.ResetSessionCommand.CanExecute(null), "Populated session could not be reset");
        model.ResetSessionCommand.Execute(null);
        TestAssert.Equal(1, resets, "Session reset command was not coarse and singular");
        TestAssert.True(!model.Current.HasCatches, "Accepted reset did not replace the aggregate snapshot");
        TestAssert.True(!model.ResetSessionCommand.CanExecute(null), "Empty session remained resettable");
    }

    private static FishingSessionStateSnapshot CreateSnapshot() => new(
        2,
        true,
        false,
        "catch",
        new FishingSessionTotalsSnapshot(3600, 2, 5.1, 1, 2.0, 2077, 2263),
        [],
        acceptedSettingsRevision: 4,
        fishRows: [CreateRow()],
        catchSizes:
        [
            new FishingCatchSizeSnapshot("good", "Хороший улов", 1, 50),
            new FishingCatchSizeSnapshot("record", "Рекордный улов", 1, 50),
        ]);

    private static FishingSessionFishRowSnapshot CreateRow() => new(
        "marlin",
        "Марлин",
        2,
        5.1,
        1,
        2.0,
        1,
        3.1,
        new FishingPriceSnapshot(0.67, 0.73, 670, 730),
        null,
        2077,
        2263);
}
