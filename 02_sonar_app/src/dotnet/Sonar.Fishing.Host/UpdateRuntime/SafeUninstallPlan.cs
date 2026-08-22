using System.IO;

namespace Sonar.Fishing.Host.UpdateRuntime;

internal sealed record SafeUninstallPlan(string InstallRoot, IReadOnlyList<string> RelativePaths)
{
    internal const string ConfirmationPhrase = "УДАЛИТЬ SONAR FISHING";

    internal static SafeUninstallPlan Create(string installRoot, string confirmation)
    {
        if (!string.Equals(confirmation, ConfirmationPhrase, StringComparison.Ordinal))
        {
            throw new InvalidOperationException("uninstall_confirmation_required");
        }
        var root = ReleaseInstallLayout.ValidateSteadyState(installRoot);
        var paths = Directory.EnumerateFiles(root, "*", SearchOption.AllDirectories)
            .Select(path => ReleaseInstallLayout.NormalizeRelative(root, path))
            .OrderBy(path => path, StringComparer.Ordinal)
            .ToArray();
        return new SafeUninstallPlan(root, Array.AsReadOnly(paths));
    }
}
