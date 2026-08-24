using System.IO;
using System.Text.Json;
using Sonar.Fishing.Host.AboutPage;
using Sonar.Fishing.Host.HostDiagnostics;

namespace Sonar.Fishing.Host.Tests;

internal static class ProductDiagnosticLogTests
{
    public static IReadOnlyList<TestCase> Create() =>
    [
        new("product_diagnostics_are_bounded_redacted_and_jsonl", IsBoundedAndRedacted),
        new("product_diagnostics_clear_only_exact_owned_logs", ClearIsScoped),
        new("about_page_exposes_only_available_diagnostic_clear", AboutPageClearIsExplicit),
    ];

    private static void IsBoundedAndRedacted()
    {
        using var root = TempRoot.Create();
        using var log = ProductDiagnosticLog.Open(root.Path, maximumFileBytes: 384, retainedFileCount: 3);
        for (var index = 0; index < 24; index++)
        {
            log.Append(new ProductDiagnosticEntry(
                DateTimeOffset.UnixEpoch.AddSeconds(index + 1),
                ProductDiagnosticLevel.Information,
                "host.test",
                $"iteration={index} bot_token=123456:abcdefghijklmnop " +
                "license_key='license-secret-value' " +
                "https://example.test/path?access_token=query-secret"));
        }

        var files = Directory.EnumerateFiles(Path.Combine(root.Path, "logs"), "sonar*.log")
            .OrderBy(path => path, StringComparer.Ordinal)
            .ToArray();
        TestAssert.True(files.Length is > 1 and <= 3, "Diagnostic rotation bound changed");
        var combined = string.Join("", files.Select(File.ReadAllText));
        TestAssert.True(
            !combined.Contains("abcdefghijklmnop", StringComparison.Ordinal) &&
            !combined.Contains("license-secret-value", StringComparison.Ordinal) &&
            !combined.Contains("query-secret", StringComparison.Ordinal) &&
            combined.Contains("[REDACTED]", StringComparison.Ordinal),
            "Diagnostic output leaked a credential or omitted redaction marker");
        foreach (var line in combined.Split('\n', StringSplitOptions.RemoveEmptyEntries))
        {
            using var document = JsonDocument.Parse(line);
            TestAssert.Equal(
                "host.test",
                document.RootElement.GetProperty("event_id").GetString() ?? string.Empty,
                "Diagnostic event ID changed");
        }
    }

    private static void ClearIsScoped()
    {
        using var root = TempRoot.Create();
        using var log = ProductDiagnosticLog.Open(root.Path, maximumFileBytes: 384, retainedFileCount: 2);
        log.Append(new ProductDiagnosticEntry(
            DateTimeOffset.UnixEpoch,
            ProductDiagnosticLevel.Warning,
            "host.clear",
            "clear test"));
        var unrelated = Path.Combine(root.Path, "logs", "external.log");
        File.WriteAllText(unrelated, "owned by another diagnostic source");
        log.Clear();
        TestAssert.True(
            File.Exists(unrelated) &&
            !Directory.EnumerateFiles(Path.Combine(root.Path, "logs"), "sonar*.log").Any(),
            "Diagnostic clear escaped exact owned log files");
    }

    private static void AboutPageClearIsExplicit()
    {
        var clearCount = 0;
        var enabled = new AboutPageViewModel(() => clearCount++);
        TestAssert.True(
            enabled.ClearDiagnosticsCommand.CanExecute(null),
            "Available diagnostics clear command was disabled");
        enabled.ClearDiagnosticsCommand.Execute(null);
        TestAssert.Equal(1, clearCount, "Diagnostics clear handler was not called exactly once");
        TestAssert.Equal("Журнал очищен", enabled.DiagnosticsStatus, "Clear status did not update");

        var unavailable = new AboutPageViewModel();
        TestAssert.True(
            !unavailable.ClearDiagnosticsCommand.CanExecute(null),
            "Unavailable diagnostics clear command was enabled");
        TestAssert.True(
            !unavailable.Build.Contains('+', StringComparison.Ordinal) &&
            unavailable.Build.Length <= 32,
            "About page exposed full source metadata as the user-facing build");
    }

    private sealed class TempRoot : IDisposable
    {
        private TempRoot(string path) => Path = path;

        internal string Path { get; }

        internal static TempRoot Create()
        {
            var path = System.IO.Path.Combine(
                System.IO.Path.GetTempPath(),
                $"sonar-fishing-diagnostics-{Guid.NewGuid():N}");
            Directory.CreateDirectory(path);
            return new TempRoot(path);
        }

        public void Dispose()
        {
            if (Directory.Exists(Path))
            {
                Directory.Delete(Path, recursive: true);
            }
        }
    }
}
