using System.IO;

namespace Sonar.Fishing.Host.UpdateRuntime;

internal static class ReleaseSwapTransaction
{
    internal static void Apply(StagedProductRelease staged)
    {
        Apply(staged, afterMove: null);
    }

    internal static void Apply(StagedProductRelease staged, Action<int>? afterMove)
    {
        ArgumentNullException.ThrowIfNull(staged);
        var staging = ReleaseInstallLayout.ValidateTransactionDirectory(
            staged.InstallRoot,
            staged.StagingDirectory,
            ".update-");
        var root = ReleaseInstallLayout.ValidateSteadyState(staged.InstallRoot, staging);
        ReleaseInstallLayout.ValidatePayloadDirectory(staging);

        var transactionId = Path.GetFileName(staging)[".update-".Length..];
        var rollback = Path.Combine(root, $".rollback-{transactionId}");
        ReleaseInstallLayout.ValidateTransactionDirectory(root, rollback, ".rollback-");
        Directory.CreateDirectory(rollback);
        var moveIndex = 0;
        try
        {
            foreach (var file in ReleaseInstallLayout.ReleaseFiles)
            {
                File.Move(Path.Combine(root, file), Path.Combine(rollback, file));
                afterMove?.Invoke(++moveIndex);
            }
            foreach (var file in ReleaseInstallLayout.ReleaseFiles)
            {
                File.Move(Path.Combine(staging, file), Path.Combine(root, file));
                afterMove?.Invoke(++moveIndex);
            }
            ReleaseInstallLayout.ValidateSteadyState(root, staging, rollback);
            ReleaseInstallLayout.DeleteTransactionDirectory(root, rollback, ".rollback-");
            ReleaseInstallLayout.DeleteTransactionDirectory(root, staging, ".update-");
            ReleaseInstallLayout.ValidateSteadyState(root);
            staged.MarkActivated();
        }
        catch (Exception exception)
        {
            RollBack(root, staging, rollback);
            throw new InvalidOperationException("release_update_apply_failed", exception);
        }
    }

    private static void RollBack(string root, string staging, string rollback)
    {
        foreach (var file in ReleaseInstallLayout.ReleaseFiles.Reverse())
        {
            var installed = Path.Combine(root, file);
            var stagedPath = Path.Combine(staging, file);
            if (File.Exists(installed) && !File.Exists(stagedPath))
            {
                File.Move(installed, stagedPath);
            }
        }
        foreach (var file in ReleaseInstallLayout.ReleaseFiles)
        {
            var backup = Path.Combine(rollback, file);
            var installed = Path.Combine(root, file);
            if (File.Exists(backup) && !File.Exists(installed))
            {
                File.Move(backup, installed);
            }
        }
        ReleaseInstallLayout.DeleteTransactionDirectory(root, rollback, ".rollback-");
        ReleaseInstallLayout.ValidateSteadyState(root, staging);
    }
}
