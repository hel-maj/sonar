using System.Text.RegularExpressions;
using System.Windows;
using System.Windows.Automation;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Threading;
using Sonar.Fishing.Host.EngineIntegration;
using Sonar.Fishing.Host.EngineStatus;
using Sonar.Fishing.Host.FishingPage;
using Sonar.Fishing.Host.FishingSessionState;
using Sonar.Fishing.Host.Shell;
using Sonar.Fishing.Host.StartupGate;

namespace Sonar.Fishing.Host.Tests;

internal static class VisibleCopyAudit
{
    private static readonly (string Name, Regex Pattern)[] Forbidden =
    [
        ("language", new Regex(
            @"(?i)(?<![\p{L}\p{N}_])(?:C#|C\+\+)(?![\p{L}\p{N}_])",
            RegexOptions.CultureInvariant)),
        ("boundary", new Regex(
            @"(?i)(?<![\p{L}\p{N}_])(?:Engine|Host|IPC|runtime(?:-gates?)?|heartbeat|PID)(?![\p{L}\p{N}_])",
            RegexOptions.CultureInvariant)),
        ("implementation", new Regex(
            @"(?i)(?:движ(?:ок|ка|ке|ком|ки)|изоляц\w*|процесс(?:а|е|ом|ы|ов)?|" +
            @"внутренн\w*\s+(?:защитн\w*\s+)?(?:услов\w*|проверк\w*)|" +
            @"подписанн\w*\s+ответ\w*|" +
            @"встроенн\w*\s+средств\w*\s+[^.]{0,40}проверк\w*|" +
            @"инертн\w*|fail-closed|DPAPI)",
            RegexOptions.CultureInvariant)),
        ("legacy", new Regex(
            @"(?i)(?:демонстрац\w*|(?<!\p{L})демо(?!\p{L})|не\s+подключ\w*|" +
            @"рабоч\w*\s+верси\w*|сборк\w*\s+больше\s+не\s+допущ\w*)",
            RegexOptions.CultureInvariant)),
        ("narration", new Regex(
            @"(?i)(?:эта\s+[^.]{0,40}страниц\w*\s+(?:показыва|отображ)|" +
            @"на\s+этой\s+страниц\w*|здесь\s+(?:показыва|отображ))",
            RegexOptions.CultureInvariant)),
        ("manual-restart", new Regex(
            @"(?i)перезапустите\s+(?:приложение|программу)",
            RegexOptions.CultureInvariant)),
        ("unlocalized-state", new Regex(
            @"(?i)^\s*(?:Empty|Loading|Error|Unavailable)\s*$",
            RegexOptions.CultureInvariant)),
    ];

    internal static void AssertSurface(DependencyObject root, string context)
    {
        ArgumentNullException.ThrowIfNull(root);
        var visited = new HashSet<DependencyObject>(ReferenceEqualityComparer.Instance);
        AuditNode(root, context, visited);
    }

    internal static void AssertText(string? value, string context)
    {
        if (string.IsNullOrWhiteSpace(value))
        {
            return;
        }
        foreach (var forbidden in Forbidden)
        {
            if (forbidden.Pattern.IsMatch(value))
            {
                throw new InvalidOperationException(
                    $"Visible copy contains forbidden {forbidden.Name} fragment in {context}: {value}");
            }
        }
    }

    private static void AuditNode(
        DependencyObject node,
        string context,
        ISet<DependencyObject> visited)
    {
        if (!visited.Add(node))
        {
            return;
        }

        var owner = $"{context}/{node.GetType().Name}";
        AssertText(AutomationProperties.GetName(node), $"{owner}.AutomationName");
        AssertText(AutomationProperties.GetHelpText(node), $"{owner}.AutomationHelpText");
        if (node is TextBlock textBlock)
        {
            AssertText(textBlock.Text, $"{owner}.Text");
        }
        if (node is ContentControl { Content: string content })
        {
            AssertText(content, $"{owner}.Content");
        }
        if (node is ContentControl { Content: Enum enumContent })
        {
            AssertText(enumContent.ToString(), $"{owner}.Content");
        }
        if (node is HeaderedContentControl { Header: string header })
        {
            AssertText(header, $"{owner}.Header");
        }
        if (node is HeaderedItemsControl { Header: string itemsHeader })
        {
            AssertText(itemsHeader, $"{owner}.Header");
        }
        if (node is FrameworkElement element)
        {
            var toolTip = ToolTipService.GetToolTip(element);
            if (toolTip is string toolTipText)
            {
                AssertText(toolTipText, $"{owner}.ToolTip");
            }
            else if (toolTip is DependencyObject toolTipObject)
            {
                AuditNode(toolTipObject, $"{owner}.ToolTip", visited);
            }
        }

        for (var index = 0; index < VisualTreeHelper.GetChildrenCount(node); index++)
        {
            AuditNode(VisualTreeHelper.GetChild(node, index), owner, visited);
        }
    }
}

internal static class VisibleCopyTests
{
    public static IReadOnlyList<TestCase> Create() =>
    [
        new("all_product_pages_hide_implementation_copy", ProductPagesAreClean),
        new("automation_states_map_internal_reasons_to_actionable_copy", AutomationStatesAreClean),
    ];

    private static void ProductPagesAreClean()
    {
        var shell = new FishingHostShell
        {
            ViewModel = FishingHostShellViewModel.CreatePreview(),
        };
        var pages = new (string Name, Action Navigate)[]
        {
            ("overview", () => shell.ViewModel.ShowOverviewCommand.Execute(null)),
            ("license", () => shell.ViewModel.ShowLicenseCommand.Execute(null)),
            ("fishing", () => shell.ViewModel.ShowFishingCommand.Execute(null)),
            ("settings", () => shell.ViewModel.ShowSettingsCommand.Execute(null)),
            ("statistics", () => shell.ViewModel.ShowStatisticsCommand.Execute(null)),
            ("streaming", () => shell.ViewModel.ShowStreamingCommand.Execute(null)),
            ("telegram", () => shell.ViewModel.ShowTelegramCommand.Execute(null)),
            ("about", () => shell.ViewModel.ShowAboutCommand.Execute(null)),
        };
        foreach (var page in pages)
        {
            page.Navigate();
            Arrange(shell, new Size(1_280, 800));
            VisibleCopyAudit.AssertSurface(shell, page.Name);
        }

        var startupStates = new (string Name, StartupAdmissionDecision? Decision)[]
        {
            ("checking", null),
            ("blocked", new StartupAdmissionDecision(
                StartupAdmissionKind.Blocked,
                "https://m-sonar-addr.ru/download",
                "startup_blocked")),
            ("invalid-download", new StartupAdmissionDecision(
                StartupAdmissionKind.Blocked,
                "http://unsafe.example/download",
                "startup_blocked")),
            ("unavailable", new StartupAdmissionDecision(
                StartupAdmissionKind.Unavailable,
                string.Empty,
                "startup_block_http_unavailable")),
        };
        foreach (var state in startupStates)
        {
            var viewModel = new StartupAdmissionViewModel(_ => { }, () => { });
            if (state.Decision is not null)
            {
                viewModel.Apply(state.Decision);
            }
            var surface = new StartupAdmissionScreen { ViewModel = viewModel };
            Arrange(surface, new Size(960, 760));
            VisibleCopyAudit.AssertSurface(surface, $"startup/{state.Name}");
        }
    }

    private static void AutomationStatesAreClean()
    {
        var snapshots = new[]
        {
            EngineStatusViewModel.MigrationPreview,
            EngineStatusViewModel.FromSnapshot(EngineSessionSnapshot.InertReady),
            EngineStatusViewModel.FromSnapshot(new EngineSessionSnapshot(true, false, "started")),
            EngineStatusViewModel.FromSnapshot(new EngineSessionSnapshot(true, false, "Ожидаем поклёвку")),
            EngineStatusViewModel.FromSnapshot(new EngineSessionSnapshot(true, true, "stopping")),
            EngineStatusViewModel.FromSessionState(CreateState(true, "read_only_session_started")),
            EngineStatusViewModel.FromProductionSessionState(CreateState(true, "reeling")),
            EngineStatusViewModel.FromBoundaryFailure(canRetry: true),
        };
        foreach (var snapshot in snapshots)
        {
            AssertStatus(snapshot);
        }
        foreach (var reason in new[]
                 {
                     "active_entitlement_required",
                     "settings_revision_mismatch",
                     "side_effects_not_negotiated",
                     "unknown_internal_reason",
                 })
        {
            AssertStatus(EngineStatusViewModel
                .FromSnapshot(EngineSessionSnapshot.InertReady)
                .WithCommandRejection(reason));
        }

    }

    private static void AssertStatus(EngineStatusViewModel status)
    {
        VisibleCopyAudit.AssertText(status.Title, "automation/title");
        VisibleCopyAudit.AssertText(status.Description, "automation/description");
        VisibleCopyAudit.AssertText(status.BadgeText, "automation/badge");
    }

    private static FishingSessionStateSnapshot CreateState(bool running, string stage) => new(
        revision: 1,
        running: running,
        stopping: false,
        detectedStage: stage,
        totals: new FishingSessionTotalsSnapshot(0, 0, 0, 0, 0, 0, 0),
        tackleItems: []);

    private static void Arrange(FrameworkElement element, Size size)
    {
        element.Measure(size);
        element.Arrange(new Rect(new Point(0, 0), size));
        element.Dispatcher.Invoke(() => { }, DispatcherPriority.DataBind);
        element.UpdateLayout();
        element.Dispatcher.Invoke(() => { }, DispatcherPriority.Render);
    }

    private sealed class InertAutomationRuntime : IFishingAutomationRuntime
    {
        public bool HasActiveEntitlement => true;

        public Task<FishingSessionStateSnapshot> StartAsync(CancellationToken cancellationToken) =>
            Task.FromResult(FishingSessionStateSnapshot.Empty);

        public Task<FishingSessionStateSnapshot> StopAsync(CancellationToken cancellationToken) =>
            Task.FromResult(FishingSessionStateSnapshot.Empty);
    }
}
