using Sonar.Fishing.Host.EngineIntegration;
using Sonar.Fishing.Host.FishingPage;
using Sonar.Fishing.Host.FishingSessionState;

namespace Sonar.Fishing.Host.Tests;

internal static class FishingAutomationViewModelTests
{
    public static IReadOnlyList<TestCase> Create() =>
    [
        new("fishing_page_sends_start_stop_exactly_once_and_projects_snapshots", CommandsProjectSnapshots),
        new("fishing_page_disables_start_without_engine_entitlement", StartRequiresEntitlement),
        new("fishing_page_surfaces_guard_rejection_without_losing_retry", GuardRejectionIsVisible),
    ];

    private static void CommandsProjectSnapshots()
    {
        var runtime = new FakeRuntime { HasActiveEntitlement = true };
        var viewModel = FishingPageViewModel.CreateProduction(runtime);
        var published = new List<FishingSessionStateSnapshot>();
        viewModel.SessionStateChanged += published.Add;

        TestAssert.True(
            viewModel.StartFishingCommand.CanExecute(null),
            "Authorized ready session did not expose start");
        viewModel.StartFishingCommand.Execute(null);
        TestAssert.Equal(1, runtime.StartCount, "Start command crossed the boundary more than once");
        TestAssert.True(!viewModel.StartFishingCommand.CanExecute(null), "Running session still allowed start");
        TestAssert.True(viewModel.StopFishingCommand.CanExecute(null), "Running session did not allow stop");
        TestAssert.Equal("Работает", viewModel.EngineStatus.Title, "Start snapshot was not projected");

        viewModel.StopFishingCommand.Execute(null);
        TestAssert.Equal(1, runtime.StopCount, "Stop command crossed the boundary more than once");
        TestAssert.Equal(2, published.Count, "Command snapshots were not published exactly once");
        TestAssert.Equal("Можно начинать", viewModel.EngineStatus.Title, "Stop snapshot was not projected");
    }

    private static void StartRequiresEntitlement()
    {
        var runtime = new FakeRuntime { HasActiveEntitlement = false };
        var viewModel = FishingPageViewModel.CreateProduction(runtime);

        TestAssert.True(
            !viewModel.StartFishingCommand.CanExecute(null),
            "Start was enabled before Engine accepted an entitlement");
        viewModel.StartFishingCommand.Execute(null);
        TestAssert.Equal(0, runtime.StartCount, "Disabled start reached the Engine boundary");
    }

    private static void GuardRejectionIsVisible()
    {
        var runtime = new FakeRuntime
        {
            HasActiveEntitlement = true,
            StartRejection = "settings_revision_mismatch",
        };
        var viewModel = FishingPageViewModel.CreateProduction(runtime);

        viewModel.StartFishingCommand.Execute(null);

        TestAssert.Equal(1, runtime.StartCount, "Rejected start was duplicated");
        TestAssert.Equal("Команда не выполнена", viewModel.EngineStatus.Title, "Guard rejection was hidden");
        TestAssert.True(
            viewModel.EngineStatus.Description.Contains("Настройки изменились", StringComparison.Ordinal),
            "Settings revision rejection lost its actionable presentation");
        TestAssert.True(
            viewModel.StartFishingCommand.CanExecute(null),
            "Guard rejection removed a safe retry");
    }

    private sealed class FakeRuntime : IFishingAutomationRuntime
    {
        public bool HasActiveEntitlement { get; set; }

        public string? StartRejection { get; set; }

        public int StartCount { get; private set; }

        public int StopCount { get; private set; }

        public Task<FishingSessionStateSnapshot> StartAsync(
            CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            StartCount++;
            if (StartRejection is not null)
            {
                throw new EngineCommandRejectedException(
                    "start-fishing-session",
                    StartRejection);
            }
            return Task.FromResult(CreateSnapshot(running: true));
        }

        public Task<FishingSessionStateSnapshot> StopAsync(
            CancellationToken cancellationToken)
        {
            cancellationToken.ThrowIfCancellationRequested();
            StopCount++;
            return Task.FromResult(CreateSnapshot(running: false));
        }

        private static FishingSessionStateSnapshot CreateSnapshot(bool running) => new(
            revision: 5,
            running: running,
            stopping: false,
            detectedStage: running ? "Ожидаем поклевку" : "idle",
            totals: new FishingSessionTotalsSnapshot(0, 0, 0, 0, 0, 0, 0),
            tackleItems: Array.Empty<FishingTackleItemSnapshot>());
    }
}
