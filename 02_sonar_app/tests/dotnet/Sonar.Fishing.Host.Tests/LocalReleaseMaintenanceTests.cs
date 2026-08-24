using System.IO;
using System.Security.Cryptography;
using System.Text;
using Sonar.Fishing.Host.SettingsPersistence;
using Sonar.Fishing.Host.UpdateRuntime;

namespace Sonar.Fishing.Host.Tests;

internal static class LocalReleaseMaintenanceTests
{
    public static IReadOnlyList<TestCase> Create() =>
    [
        new("local_release_bundle_verification_rejects_tampering", BundleVerificationIsExact),
        new("local_release_rejects_developer_authority_bundle_contamination", DeveloperBundleIsNotInstallable),
        new("local_release_install_update_and_rollback_preserve_user_state", LifecyclePreservesState),
        new("local_release_interrupted_swap_recovers_previous_pair", InterruptedSwapRecovers),
        new("local_release_after_exit_command_is_explicit_and_bounded", CommandContractIsBounded),
        new("legacy_license_import_moves_only_key_without_trusting_metadata", LegacyLicenseImportIsKeyOnly),
    ];

    private static void BundleVerificationIsExact()
    {
        using var scope = TempScope.Create();
        var bundle = scope.CreateBundle("source", "1.0.0", "host-a", "engine-a");
        var verified = DevelopmentBundleVerifier.Verify(bundle);
        TestAssert.Equal("1.0.0", verified.Version, "Development bundle version changed");

        File.AppendAllText(Path.Combine(bundle, "Sonar.exe"), "tampered");
        TestAssert.Throws<InvalidOperationException>(
            () => DevelopmentBundleVerifier.Verify(bundle),
            "Local maintenance accepted a tampered Host");
    }

    private static void LifecyclePreservesState()
    {
        using var scope = TempScope.Create();
        var first = scope.CreateBundle("first", "1.0.0", "host-a", "engine-a");
        var second = scope.CreateBundle("second", "1.1.0", "host-b", "engine-b");
        var install = Path.Combine(scope.Root, "installed");

        var preview = LocalReleaseMaintenance.Execute(new LocalReleaseMaintenanceRequest(
            LocalReleaseMaintenanceAction.Install,
            first,
            install,
            null,
            DryRun: true));
        TestAssert.True(!preview.Changed && !Directory.Exists(install),
            "Install dry-run changed filesystem state");

        var installed = LocalReleaseMaintenance.Execute(new LocalReleaseMaintenanceRequest(
            LocalReleaseMaintenanceAction.Install,
            first,
            install,
            null,
            DryRun: false));
        TestAssert.Equal("installed", installed.Status, "Install status changed");
        TestAssert.True(
            File.Exists(Path.Combine(install, "config", "state.dat")) &&
            Directory.Exists(Path.Combine(install, "logs")),
            "Install did not create the exact CurrentUser runtime layout");
        _ = new FishingStateStore(
            Path.Combine(install, "config"),
            new DpapiCurrentUserSecretProtector()).Load();
        File.WriteAllText(Path.Combine(install, "config", "state.dat"), "user-state");
        File.WriteAllText(Path.Combine(install, "logs", "current.log"), "session-log");

        var firstBackup = Path.Combine(scope.Root, "backup-first");
        var updated = LocalReleaseMaintenance.Execute(new LocalReleaseMaintenanceRequest(
            LocalReleaseMaintenanceAction.Update,
            second,
            install,
            firstBackup,
            DryRun: false));
        TestAssert.Equal("updated", updated.Status, "Update status changed");
        TestAssert.Equal("1.1.0", DevelopmentBundleVerifier.Verify(install).Version,
            "Update did not activate the new pair");
        TestAssert.Equal("1.0.0", DevelopmentBundleVerifier.Verify(firstBackup).Version,
            "Update backup did not retain the previous pair");
        AssertUserState(install);

        var secondBackup = Path.Combine(scope.Root, "backup-second");
        var rolledBack = LocalReleaseMaintenance.Execute(new LocalReleaseMaintenanceRequest(
            LocalReleaseMaintenanceAction.Rollback,
            firstBackup,
            install,
            secondBackup,
            DryRun: false));
        TestAssert.Equal("rolled_back", rolledBack.Status, "Rollback status changed");
        TestAssert.Equal("1.0.0", DevelopmentBundleVerifier.Verify(install).Version,
            "Rollback did not restore the previous pair");
        TestAssert.Equal("1.1.0", DevelopmentBundleVerifier.Verify(secondBackup).Version,
            "Rollback did not preserve the displaced current pair");
        AssertUserState(install);
        TestAssert.True(
            !Directory.EnumerateDirectories(install, ".update-*").Any() &&
            !Directory.EnumerateDirectories(install, ".rollback-*").Any(),
            "Local lifecycle left transaction residue");
    }

    private static void DeveloperBundleIsNotInstallable()
    {
        using var scope = TempScope.Create();
        var bundle = scope.CreateBundle("developer", "1.0.0", "host-dev", "engine-dev");
        var manifestPath = Path.Combine(bundle, "bundle-manifest.json");
        var manifest = File.ReadAllText(manifestPath, Encoding.UTF8)
            .Replace(
                "\"schemaVersion\":1,\"product\":\"fishing\",\"releaseMode\":\"development-unsigned\"",
                "\"schemaVersion\":2,\"product\":\"fishing\",\"releaseMode\":\"developer-full-access-unsigned\",\"developerFullAccess\":true",
                StringComparison.Ordinal);
        File.WriteAllText(manifestPath, manifest, new UTF8Encoding(false));

        TestAssert.Throws<InvalidOperationException>(
            () => DevelopmentBundleVerifier.Verify(bundle),
            "Local maintenance accepted a developer authority bundle");
    }

    private static void InterruptedSwapRecovers()
    {
        using var scope = TempScope.Create();
        var first = scope.CreateBundle("first", "1.0.0", "host-a", "engine-a");
        var second = scope.CreateBundle("second", "1.1.0", "host-b", "engine-b");
        var install = Path.Combine(scope.Root, "installed");
        _ = LocalReleaseMaintenance.Execute(new LocalReleaseMaintenanceRequest(
            LocalReleaseMaintenanceAction.Install,
            first,
            install,
            null,
            DryRun: false));

        var transactionId = Guid.NewGuid().ToString("N");
        var staging = Path.Combine(install, $".update-{transactionId}");
        var rollback = Path.Combine(install, $".rollback-{transactionId}");
        Directory.CreateDirectory(staging);
        Directory.CreateDirectory(rollback);
        foreach (var file in ReleaseInstallLayout.ReleaseFiles)
        {
            File.Copy(Path.Combine(second, file), Path.Combine(staging, file));
        }
        foreach (var file in ReleaseInstallLayout.ReleaseFiles.Take(2))
        {
            File.Move(Path.Combine(install, file), Path.Combine(rollback, file));
        }
        File.Move(
            Path.Combine(staging, "Sonar.Engine.exe"),
            Path.Combine(install, "Sonar.Engine.exe"));

        var recovered = LocalReleaseMaintenance.Execute(new LocalReleaseMaintenanceRequest(
            LocalReleaseMaintenanceAction.Recover,
            second,
            install,
            null,
            DryRun: false));
        TestAssert.Equal("recovered", recovered.Status, "Recovery status changed");
        TestAssert.Equal("1.0.0", DevelopmentBundleVerifier.Verify(install).Version,
            "Recovery did not restore the previous coherent pair");
        TestAssert.True(
            !Directory.EnumerateDirectories(install, ".update-*").Any() &&
            !Directory.EnumerateDirectories(install, ".rollback-*").Any(),
            "Interrupted recovery left transaction residue");
    }

    private static void CommandContractIsBounded()
    {
        using var scope = TempScope.Create();
        var source = scope.CreateBundle("source", "1.1.0", "host-b", "engine-b");
        var target = scope.CreateBundle("target", "1.0.0", "host-a", "engine-a");
        var backup = Path.Combine(scope.Root, "backup");
        var receipt = Path.Combine(scope.Root, "receipt.json");
        var parsed = ReleaseMaintenanceCommand.Parse(
        [
            "--release-maintenance",
            "--action", "update",
            "--source", source,
            "--target", target,
            "--backup", backup,
            "--receipt", receipt,
            "--wait-timeout-seconds", "30",
            "--development-unsigned",
            "--dry-run",
        ]);
        TestAssert.Equal(LocalReleaseMaintenanceAction.Update, parsed.Request.Action,
            "After-exit action changed");
        TestAssert.Equal(TimeSpan.FromSeconds(30), parsed.WaitTimeout,
            "After-exit timeout changed");
        TestAssert.True(parsed.Request.DryRun, "Dry-run gate was lost");

        TestAssert.Throws<InvalidOperationException>(
            () => ReleaseMaintenanceCommand.Parse(
            [
                "--release-maintenance", "--action", "update",
                "--source", source, "--target", target,
                "--backup", backup, "--receipt", receipt,
            ]),
            "Command accepted maintenance without explicit unsigned authority");
        TestAssert.Throws<InvalidOperationException>(
            () => ReleaseMaintenanceCommand.Parse(
            [
                "--release-maintenance", "--action", "update",
                "--source", source, "--target", target,
                "--receipt", receipt, "--development-unsigned",
            ]),
            "Command accepted update without a fresh backup target");
    }

    private static void LegacyLicenseImportIsKeyOnly()
    {
        using var scope = TempScope.Create();
        var install = scope.CreateBundle("installed", "1.0.0", "host-a", "engine-a");
        var legacyDirectory = Path.Combine(scope.Root, "legacy-config");
        Directory.CreateDirectory(legacyDirectory);
        var legacy = Path.Combine(legacyDirectory, "license_settings.json");
        File.WriteAllText(
            legacy,
            """
            {
              "license_key": "legacy-key",
              "license_id": "untrusted-id",
              "last_validated_at": "2099-01-01T00:00:00Z",
              "expires_at": "2099-01-01T00:00:00Z",
              "role": "admin",
              "group": "untrusted",
              "features": ["fishing", "stream"],
              "denied_features": []
            }
            """,
            new UTF8Encoding(false));
        var protector = new TestSecretProtector();

        var preview = LegacyLicenseKeyImporter.Import(legacy, install, protector, dryRun: true);
        TestAssert.True(!preview.Changed &&
            !File.Exists(Path.Combine(install, "config", "state.dat")),
            "Legacy license dry-run wrote product state");
        var imported = LegacyLicenseKeyImporter.Import(legacy, install, protector);
        TestAssert.True(imported.Changed, "Legacy key import reported no change");
        var state = new FishingStateStore(Path.Combine(install, "config"), protector).Load();
        TestAssert.Equal("legacy-key", state.Secrets.LicenseKey,
            "Legacy license key changed during import");
        TestAssert.Equal(string.Empty, state.Secrets.SignedLicenseCache,
            "Legacy import synthesized a signed cache");
        TestAssert.Equal(string.Empty, state.License.LicenseId,
            "Legacy license id became trusted state");
        TestAssert.True(state.License.Features.Count == 0,
            "Legacy feature list became trusted state");
        TestAssert.True(File.Exists(legacy), "One-time import deleted the legacy source");

        var repeated = LegacyLicenseKeyImporter.Import(legacy, install, protector);
        TestAssert.True(!repeated.Changed, "Idempotent legacy import rewrote state");
    }

    private static void AssertUserState(string install)
    {
        TestAssert.Equal(
            "user-state",
            File.ReadAllText(Path.Combine(install, "config", "state.dat")),
            "Local release operation changed state.dat");
        TestAssert.Equal(
            "session-log",
            File.ReadAllText(Path.Combine(install, "logs", "current.log")),
            "Local release operation changed logs");
    }

    private sealed class TempScope : IDisposable
    {
        private TempScope(string root)
        {
            Root = root;
        }

        internal string Root { get; }

        internal static TempScope Create()
        {
            var root = Path.Combine(
                Path.GetTempPath(),
                $"sonar-fishing-local-release-tests-{Guid.NewGuid():N}");
            Directory.CreateDirectory(root);
            return new TempScope(root);
        }

        internal string CreateBundle(
            string name,
            string version,
            string hostText,
            string engineText)
        {
            var directory = Path.Combine(Root, name);
            Directory.CreateDirectory(directory);
            var host = Encoding.UTF8.GetBytes(hostText);
            var engine = Encoding.UTF8.GetBytes(engineText);
            File.WriteAllBytes(Path.Combine(directory, "Sonar.exe"), host);
            File.WriteAllBytes(Path.Combine(directory, "Sonar.Engine.exe"), engine);
            var hostHash = Convert.ToHexString(SHA256.HashData(host));
            var engineHash = Convert.ToHexString(SHA256.HashData(engine));
            var manifest =
                $"{{\"schemaVersion\":1,\"product\":\"fishing\"," +
                $"\"releaseMode\":\"development-unsigned\",\"version\":\"{version}\"," +
                "\"source\":{\"commitSha\":\"0000000000000000000000000000000000000000\",\"dirty\":true}," +
                "\"ipc\":{\"schema\":\"ipc/v1/sonar_fishing.proto\"," +
                $"\"schemaSha256\":\"{new string('0', 64)}\"}}," +
                $"\"host\":{{\"path\":\"Sonar.exe\",\"sha256\":\"{hostHash}\"," +
                $"\"unsignedSha256\":\"{hostHash}\",\"buildId\":\"fishing-host-{hostHash[..16].ToLowerInvariant()}\"}}," +
                $"\"engine\":{{\"path\":\"Sonar.Engine.exe\",\"sha256\":\"{engineHash}\"," +
                $"\"unsignedSha256\":\"{engineHash}\",\"buildId\":\"fishing-engine-{engineHash[..16].ToLowerInvariant()}\"}}," +
                "\"requiredRuntime\":{\"family\":\"Microsoft.WindowsDesktop.App\",\"majorVersion\":10," +
                "\"architecture\":\"x64\",\"deployment\":\"framework-dependent-single-file\"}," +
                $"\"determinism\":{{\"verified\":true,\"secondHostSha256\":\"{hostHash}\"," +
                $"\"secondEngineSha256\":\"{engineHash}\"}}," +
                "\"authenticode\":{\"required\":false,\"hostStatus\":\"NotRequired\"," +
                "\"engineStatus\":\"NotRequired\"}}\n";
            File.WriteAllText(
                Path.Combine(directory, "bundle-manifest.json"),
                manifest,
                new UTF8Encoding(false));
            return directory;
        }

        public void Dispose()
        {
            if (Directory.Exists(Root))
            {
                Directory.Delete(Root, recursive: true);
            }
        }
    }

    private sealed class TestSecretProtector : ISecretProtector
    {
        public byte[] Protect(ReadOnlySpan<byte> plaintext) => Transform(plaintext);

        public byte[] Unprotect(ReadOnlySpan<byte> protectedData) => Transform(protectedData);

        private static byte[] Transform(ReadOnlySpan<byte> value)
        {
            var result = value.ToArray();
            for (var index = 0; index < result.Length; index++)
            {
                result[index] ^= 0x5a;
            }
            return result;
        }
    }
}
