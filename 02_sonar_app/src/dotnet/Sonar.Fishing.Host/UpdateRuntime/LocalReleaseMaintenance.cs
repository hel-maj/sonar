using System.IO;
using Sonar.Fishing.Host.SettingsPersistence;

namespace Sonar.Fishing.Host.UpdateRuntime;

internal enum LocalReleaseMaintenanceAction
{
    Install,
    Update,
    Rollback,
    Recover,
    ImportLicense,
}

internal sealed record LocalReleaseMaintenanceRequest(
    LocalReleaseMaintenanceAction Action,
    string SourceBundle,
    string InstallRoot,
    string? BackupDirectory,
    bool DryRun,
    string? LegacyLicenseSettingsPath = null);

internal sealed record LocalReleaseMaintenanceResult(
    string Status,
    string Version,
    string HostSha256,
    string EngineSha256,
    bool Changed);

internal static class LocalReleaseMaintenance
{
    internal static LocalReleaseMaintenanceResult Execute(
        LocalReleaseMaintenanceRequest request)
    {
        ArgumentNullException.ThrowIfNull(request);
        var source = DevelopmentBundleVerifier.Verify(request.SourceBundle);
        var installRoot = Path.GetFullPath(request.InstallRoot);
        if (SamePath(source.Root, installRoot) ||
            IsDescendant(source.Root, installRoot) ||
            IsDescendant(installRoot, source.Root))
        {
            throw new InvalidOperationException("release_maintenance_source_target_overlap");
        }

        return request.Action switch
        {
            LocalReleaseMaintenanceAction.Install =>
                Install(source, installRoot, request.DryRun),
            LocalReleaseMaintenanceAction.Update =>
                Replace(source, installRoot, request.BackupDirectory, request.DryRun,
                    allowOlder: false),
            LocalReleaseMaintenanceAction.Rollback =>
                Replace(source, installRoot, request.BackupDirectory, request.DryRun,
                    allowOlder: true),
            LocalReleaseMaintenanceAction.Recover =>
                Recover(source, installRoot, request.DryRun),
            LocalReleaseMaintenanceAction.ImportLicense =>
                ImportLegacyLicense(source, installRoot, request),
            _ => throw new ArgumentOutOfRangeException(nameof(request)),
        };
    }

    private static LocalReleaseMaintenanceResult Install(
        VerifiedDevelopmentBundle source,
        string installRoot,
        bool dryRun)
    {
        var parent = ValidateNewDirectoryTarget(installRoot, "release_install_target_invalid");
        if (dryRun)
        {
            return Result("install_ready", source, changed: false);
        }

        var temporary = Path.Combine(
            parent,
            $".{Path.GetFileName(installRoot)}.install-{Guid.NewGuid():N}");
        Directory.CreateDirectory(temporary);
        try
        {
            CopyReleaseFiles(source.Root, temporary);
            InitializeRuntimeState(temporary);
            var verified = DevelopmentBundleVerifier.Verify(temporary);
            Directory.Move(temporary, installRoot);
            _ = DevelopmentBundleVerifier.Verify(installRoot);
            return Result("installed", verified, changed: true);
        }
        catch
        {
            if (Directory.Exists(temporary))
            {
                Directory.Delete(temporary, recursive: true);
            }
            throw;
        }
    }

    private static LocalReleaseMaintenanceResult Replace(
        VerifiedDevelopmentBundle source,
        string installRoot,
        string? backupDirectory,
        bool dryRun,
        bool allowOlder)
    {
        var current = DevelopmentBundleVerifier.Verify(installRoot);
        if (!allowOlder &&
            DevelopmentBundleVerifier.CompareVersions(source.Version, current.Version) < 0)
        {
            throw new InvalidOperationException("release_maintenance_downgrade_rejected");
        }
        if (source.HostSha256 == current.HostSha256 &&
            source.EngineSha256 == current.EngineSha256)
        {
            throw new InvalidOperationException("release_maintenance_pair_unchanged");
        }

        var backup = RequireBackupTarget(
            backupDirectory,
            source.Root,
            current.Root);
        if (dryRun)
        {
            return Result(
                allowOlder ? "rollback_ready" : "update_ready",
                source,
                changed: false);
        }

        Directory.CreateDirectory(backup);
        try
        {
            CopyReleaseFiles(current.Root, backup);
            _ = DevelopmentBundleVerifier.Verify(backup);
        }
        catch
        {
            if (Directory.Exists(backup))
            {
                Directory.Delete(backup, recursive: true);
            }
            throw;
        }

        var staging = Path.Combine(current.Root, $".update-{Guid.NewGuid():N}");
        ReleaseInstallLayout.ValidateTransactionDirectory(
            current.Root,
            staging,
            ".update-");
        Directory.CreateDirectory(staging);
        try
        {
            CopyReleaseFiles(source.Root, staging);
            ReleaseInstallLayout.ValidatePayloadDirectory(staging);
            ReleaseSwapTransaction.ApplyVerifiedPayloadDirectory(current.Root, staging);
            var verified = DevelopmentBundleVerifier.Verify(current.Root);
            return Result(allowOlder ? "rolled_back" : "updated", verified, changed: true);
        }
        catch
        {
            if (Directory.Exists(staging))
            {
                ReleaseInstallLayout.DeleteTransactionDirectory(
                    current.Root,
                    staging,
                    ".update-");
            }
            throw;
        }
    }

    private static LocalReleaseMaintenanceResult Recover(
        VerifiedDevelopmentBundle executorBundle,
        string installRoot,
        bool dryRun)
    {
        if (dryRun)
        {
            _ = ReleaseInstallLayout.ValidateRoot(installRoot);
            return Result("recovery_ready", executorBundle, changed: false);
        }
        ReleaseSwapRecovery.Recover(installRoot);
        var current = DevelopmentBundleVerifier.Verify(installRoot);
        return Result("recovered", current, changed: true);
    }

    private static LocalReleaseMaintenanceResult ImportLegacyLicense(
        VerifiedDevelopmentBundle executorBundle,
        string installRoot,
        LocalReleaseMaintenanceRequest request)
    {
        if (string.IsNullOrWhiteSpace(request.LegacyLicenseSettingsPath))
        {
            throw new InvalidOperationException("legacy_license_source_required");
        }
        var imported = LegacyLicenseKeyImporter.Import(
            request.LegacyLicenseSettingsPath,
            installRoot,
            new DpapiCurrentUserSecretProtector(),
            request.DryRun);
        return new LocalReleaseMaintenanceResult(
            imported.Status,
            executorBundle.Version,
            executorBundle.HostSha256,
            executorBundle.EngineSha256,
            imported.Changed);
    }

    private static string RequireBackupTarget(
        string? backupDirectory,
        string sourceRoot,
        string installRoot)
    {
        if (string.IsNullOrWhiteSpace(backupDirectory))
        {
            throw new InvalidOperationException("release_maintenance_backup_required");
        }
        var backup = Path.GetFullPath(backupDirectory);
        _ = ValidateNewDirectoryTarget(backup, "release_maintenance_backup_invalid");
        if (SamePath(backup, sourceRoot) || SamePath(backup, installRoot) ||
            IsDescendant(backup, sourceRoot) || IsDescendant(backup, installRoot) ||
            IsDescendant(sourceRoot, backup) || IsDescendant(installRoot, backup))
        {
            throw new InvalidOperationException("release_maintenance_backup_overlap");
        }
        return backup;
    }

    private static string ValidateNewDirectoryTarget(string path, string reason)
    {
        if (string.IsNullOrWhiteSpace(path) || !Path.IsPathFullyQualified(path))
        {
            throw new InvalidOperationException(reason);
        }
        var fullPath = Path.GetFullPath(path).TrimEnd(
            Path.DirectorySeparatorChar,
            Path.AltDirectorySeparatorChar);
        var root = Path.GetPathRoot(fullPath)?.TrimEnd(
            Path.DirectorySeparatorChar,
            Path.AltDirectorySeparatorChar);
        var parent = Path.GetDirectoryName(fullPath);
        if (string.IsNullOrEmpty(fullPath) ||
            string.Equals(fullPath, root, StringComparison.OrdinalIgnoreCase) ||
            string.IsNullOrEmpty(parent) ||
            !Directory.Exists(parent) ||
            Directory.Exists(fullPath) || File.Exists(fullPath) ||
            (new DirectoryInfo(parent).Attributes & FileAttributes.ReparsePoint) != 0)
        {
            throw new InvalidOperationException(reason);
        }
        return parent;
    }

    private static void CopyReleaseFiles(string source, string destination)
    {
        foreach (var file in ReleaseInstallLayout.ReleaseFiles)
        {
            File.Copy(
                Path.Combine(source, file),
                Path.Combine(destination, file),
                overwrite: false);
        }
    }

    private static void InitializeRuntimeState(string installRoot)
    {
        var configDirectory = Path.Combine(installRoot, "config");
        Directory.CreateDirectory(Path.Combine(installRoot, "logs"));
        _ = new FishingStateStore(
            configDirectory,
            new DpapiCurrentUserSecretProtector()).LoadOrCreate(FishingHostState.Default);
    }

    private static LocalReleaseMaintenanceResult Result(
        string status,
        VerifiedDevelopmentBundle bundle,
        bool changed) => new(
            status,
            bundle.Version,
            bundle.HostSha256,
            bundle.EngineSha256,
            changed);

    private static bool SamePath(string left, string right) => string.Equals(
        Path.GetFullPath(left).TrimEnd(Path.DirectorySeparatorChar),
        Path.GetFullPath(right).TrimEnd(Path.DirectorySeparatorChar),
        StringComparison.OrdinalIgnoreCase);

    private static bool IsDescendant(string candidate, string parent)
    {
        var parentPrefix = Path.GetFullPath(parent).TrimEnd(
            Path.DirectorySeparatorChar,
            Path.AltDirectorySeparatorChar) + Path.DirectorySeparatorChar;
        return Path.GetFullPath(candidate).StartsWith(
            parentPrefix,
            StringComparison.OrdinalIgnoreCase);
    }
}
