using Sonar.Fishing.Host.EngineIntegration;
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
        new("current_statistics_duration_only_session_is_resettable", DurationOnlySessionIsResettable),
        new("current_statistics_reset_rejection_preserves_snapshot", ResetRejectionPreservesSnapshot),
        new("current_statistics_reset_cancel_without_retirement_preserves_snapshot", ResetCancellationWithoutRetirementPreservesSnapshot),
        new("current_statistics_reset_double_click_is_single_flight", ResetDoubleClickIsSingleFlight),
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
        var runtime = new FakeStatisticsRuntime(_ =>
        {
            resets++;
            return Task.FromResult(FishingSessionStateSnapshot.Empty);
        });
        var model = new StatisticsPageViewModel(
            CreateSnapshot(),
            persistPrice: null,
            runtime);

        TestAssert.True(model.ResetSessionCommand.CanExecute(null), "Populated session could not be reset");
        model.ResetSessionCommand.ExecuteAsync(null).GetAwaiter().GetResult();
        TestAssert.Equal(1, resets, "Session reset command was not coarse and singular");
        TestAssert.True(!model.Current.HasCatches, "Accepted reset did not replace the aggregate snapshot");
        TestAssert.True(!model.ResetSessionCommand.CanExecute(null), "Empty session remained resettable");
        TestAssert.Equal(string.Empty, model.CommandStatus,
            "Successful reset exposed a status toast/message");
    }

    private static void DurationOnlySessionIsResettable()
    {
        var durationOnly = new FishingSessionStateSnapshot(
            3,
            true,
            false,
            "active",
            new FishingSessionTotalsSnapshot(4, 0, 0, 0, 0, 0, 0),
            []);
        var model = new StatisticsPageViewModel(
            durationOnly,
            persistPrice: null,
            new FakeStatisticsRuntime(_ =>
                Task.FromResult(FishingSessionStateSnapshot.Empty)));

        TestAssert.True(model.ResetSessionCommand.CanExecute(null),
            "Duration-only current session was not resettable");
    }

    private static void ResetRejectionPreservesSnapshot()
    {
        var snapshot = CreateSnapshot();
        var model = new StatisticsPageViewModel(
            snapshot,
            persistPrice: null,
            new FakeStatisticsRuntime(_ =>
                Task.FromException<FishingSessionStateSnapshot>(
                    new EngineCommandRejectedException(
                        "reset-fishing-session-statistics",
                        "session_statistics_reset_rejected"))));

        model.ResetSessionCommand.ExecuteAsync(null).GetAwaiter().GetResult();

        TestAssert.True(model.Current.HasCatches,
            "Rejected reset replaced the current aggregate");
        TestAssert.Equal("Не удалось начать новую сессию", model.CommandStatus,
            "Rejected reset lost its safe presentation state");
    }

    private static void ResetCancellationWithoutRetirementPreservesSnapshot()
    {
        var entered = new TaskCompletionSource(
            TaskCreationOptions.RunContinuationsAsynchronously);
        var model = new StatisticsPageViewModel(
            CreateSnapshot(),
            persistPrice: null,
            new FakeStatisticsRuntime(async cancellationToken =>
            {
                entered.TrySetResult();
                await Task.Delay(Timeout.InfiniteTimeSpan, cancellationToken)
                    .ConfigureAwait(false);
                throw new InvalidOperationException("unreachable");
            }));

        var reset = model.ResetSessionCommand.ExecuteAsync(null);
        TestAssert.True(entered.Task.Wait(TimeSpan.FromSeconds(1)),
            "Reset command did not enter the runtime");
        model.ResetSessionCommand.Cancel();
        reset.GetAwaiter().GetResult();

        TestAssert.True(model.Current.HasCatches,
            "Cancelled reset replaced the current aggregate");
        TestAssert.True(model.ResetSessionCommand.CanExecute(null),
            "Cancelled reset did not restore command availability");
    }

    private static void ResetDoubleClickIsSingleFlight()
    {
        var calls = 0;
        var entered = new TaskCompletionSource(
            TaskCreationOptions.RunContinuationsAsynchronously);
        var release = new TaskCompletionSource<FishingSessionStateSnapshot>(
            TaskCreationOptions.RunContinuationsAsynchronously);
        var model = new StatisticsPageViewModel(
            CreateSnapshot(),
            persistPrice: null,
            new FakeStatisticsRuntime(_ =>
            {
                calls++;
                entered.TrySetResult();
                return release.Task;
            }));

        var first = model.ResetSessionCommand.ExecuteAsync(null);
        TestAssert.True(entered.Task.Wait(TimeSpan.FromSeconds(1)),
            "First reset command did not enter the runtime");
        var second = model.ResetSessionCommand.ExecuteAsync(null);
        TestAssert.Equal(1, calls, "Concurrent reset command crossed the single-flight gate");
        release.TrySetResult(FishingSessionStateSnapshot.Empty);
        Task.WhenAll(first, second).GetAwaiter().GetResult();
        TestAssert.Equal(1, calls, "Reset command executed more than once");
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

    private sealed class FakeStatisticsRuntime(
        Func<CancellationToken, Task<FishingSessionStateSnapshot>> reset) :
        IFishingSessionStatisticsRuntime
    {
        public Task<FishingSessionStateSnapshot> ResetCurrentSessionAsync(
            CancellationToken cancellationToken) => reset(cancellationToken);
    }
}
