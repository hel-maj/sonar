using System.IO;

namespace Sonar.Fishing.Host.UpdateRuntime;

internal static class ReleaseSwapRecovery
{
    internal static void Recover(string installRoot)
    {
        var root = ReleaseInstallLayout.ValidateRoot(installRoot);
        var stagingDirectories = ExactTransactionDirectories(root, ".update-");
        var rollbackDirectories = ExactTransactionDirectories(root, ".rollback-");
        if (stagingDirectories.Length > 1 || rollbackDirectories.Length > 1)
        {
            throw new InvalidOperationException("release_recovery_ambiguous");
        }

        if (rollbackDirectories.Length == 0)
        {
            if (stagingDirectories.Length == 1)
            {
                ReleaseInstallLayout.DeleteTransactionDirectory(
                    root,
                    stagingDirectories[0],
                    ".update-");
            }
            ReleaseInstallLayout.ValidateSteadyState(root);
            return;
        }

        var rollback = rollbackDirectories[0];
        var transactionId = Path.GetFileName(rollback)[".rollback-".Length..];
        var staging = Path.Combine(root, $".update-{transactionId}");
        if (stagingDirectories.Length == 1 &&
            !string.Equals(stagingDirectories[0], staging, StringComparison.OrdinalIgnoreCase))
        {
            throw new InvalidOperationException("release_recovery_generation_mismatch");
        }
        if (!Directory.Exists(staging))
        {
            Directory.CreateDirectory(staging);
        }

        foreach (var file in ReleaseInstallLayout.ReleaseFiles.Reverse())
        {
            var backup = Path.Combine(rollback, file);
            if (!File.Exists(backup))
            {
                continue;
            }
            var installed = Path.Combine(root, file);
            var staged = Path.Combine(staging, file);
            if (File.Exists(installed))
            {
                if (File.Exists(staged))
                {
                    throw new InvalidOperationException("release_recovery_payload_ambiguous");
                }
                File.Move(installed, staged);
            }
            File.Move(backup, installed);
        }

        ReleaseInstallLayout.ValidateSteadyState(root, staging, rollback);
        ReleaseInstallLayout.DeleteTransactionDirectory(root, rollback, ".rollback-");
        ReleaseInstallLayout.DeleteTransactionDirectory(root, staging, ".update-");
        ReleaseInstallLayout.ValidateSteadyState(root);
    }

    private static string[] ExactTransactionDirectories(string root, string prefix) =>
        Directory.EnumerateDirectories(root, $"{prefix}*", SearchOption.TopDirectoryOnly)
            .Where(path =>
            {
                var name = Path.GetFileName(path);
                return name.Length == prefix.Length + 32 &&
                    name.StartsWith(prefix, StringComparison.Ordinal) &&
                    name[prefix.Length..].All(Uri.IsHexDigit);
            })
            .Select(Path.GetFullPath)
            .OrderBy(path => path, StringComparer.OrdinalIgnoreCase)
            .ToArray();
}
