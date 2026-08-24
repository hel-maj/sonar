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
        ApplyVerifiedPayloadDirectory(
            staged.InstallRoot,
            staged.StagingDirectory,
            afterMove);
        staged.MarkActivated();
    }

    // Both the signed network stager and the explicit local maintenance mode
    // arrive here only after independently verifying their payload boundary.
    // Keeping the swap in one owner prevents the local after-exit workflow from
    // reimplementing rollback and crash-recovery semantics in a script.
    internal static void ApplyVerifiedPayloadDirectory(
        string installRoot,
        string stagingDirectory,
        Action<int>? afterMove = null)
    {
        var staging = ReleaseInstallLayout.ValidateTransactionDirectory(
            installRoot,
            stagingDirectory,
            ".update-");
        var root = ReleaseInstallLayout.ValidateSteadyState(installRoot, staging);
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
