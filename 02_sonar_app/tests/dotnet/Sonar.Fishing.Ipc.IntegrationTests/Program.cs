using Google.Protobuf;
using System.Globalization;
using Sonar.Fishing.Host.EngineIntegration;
using Sonar.Fishing.Host.Licensing;
using Sonar.Fishing.Host.SettingsPersistence;
using Sonar.Fishing.Ipc.Contracts.V1;
using Sonar.Fishing.Ipc.IntegrationTests;

using HostFishingRuntimeSettings = Sonar.Fishing.Host.SettingsPersistence.FishingRuntimeSettings;

var allTests = new (string Name, Func<Task> Run)[]
{
    ("catch_quality_envelope_managed_golden_parity", CatchQualityManagedGoldenParity),
    ("catch_disposition_envelope_managed_golden_parity", CatchDispositionManagedGoldenParity),
    ("offline_host_native_engine_round_trip", OfflineHostNativeEngineRoundTrip),
    ("offline_host_keeps_one_contained_engine_session_alive", OfflineHostKeepsSessionAlive),
    ("offline_host_restarts_one_crashed_engine_generation", OfflineHostRestartsCrashedEngine),
    ("offline_host_and_engine_independently_verify_raw_entitlement", OfflineHostAndEngineVerifyRawEntitlement),
    ("production_host_engine_uses_verified_pair_identity_and_stays_inert", ProductionHostEngineUsesVerifiedIdentity),
};
var selection = Environment.GetEnvironmentVariable("SONAR_FISHING_IPC_TEST_SELECTION");
var tests = selection switch
{
    null or "" => allTests,
    "packaged-production" => new (string Name, Func<Task> Run)[]
    {
        ("packaged_production_pair_survives_crash_and_stays_inert", PackagedProductionPairLifecycle),
    },
    _ => throw new InvalidOperationException("SONAR_FISHING_IPC_TEST_SELECTION is invalid"),
};

var failures = new List<string>();
foreach (var test in tests)
{
    try
    {
        await test.Run();
        Console.WriteLine($"PASS {test.Name}");
    }
    catch (Exception exception)
    {
        failures.Add(test.Name);
        Console.Error.WriteLine($"FAIL {test.Name}: {exception}");
    }
}

Console.WriteLine($"Executed {tests.Length} Fishing IPC tests; failures: {failures.Count}.");
return failures.Count == 0 ? 0 : 1;

static Task CatchQualityManagedGoldenParity()
{
    var path = Path.Combine(
        AppContext.BaseDirectory,
        "fixtures",
        "ipc",
        "v1",
        "catch_quality_request.hex");
    var golden = Convert.FromHexString(File.ReadAllText(path).Trim());
    var envelope = Envelope.Parser.ParseFrom(golden);
    Require(
        envelope.PayloadCase == Envelope.PayloadOneofCase.ClassifyCatchQualityRequest,
        "golden payload case changed");
    Require(envelope.ClassifyCatchQualityRequest.HasRawText, "golden presence changed");
    Require(
        envelope.ClassifyCatchQualityRequest.RawText == "Трофейная",
        "golden text changed");
    Require(envelope.ToByteArray().SequenceEqual(golden), "managed wire parity changed");
    return Task.CompletedTask;
}

static Task CatchDispositionManagedGoldenParity()
{
    var path = Path.Combine(
        AppContext.BaseDirectory,
        "fixtures",
        "ipc",
        "v1",
        "catch_disposition_request.hex");
    var golden = Convert.FromHexString(File.ReadAllText(path).Trim());
    var envelope = Envelope.Parser.ParseFrom(golden);
    Require(
        envelope.PayloadCase == Envelope.PayloadOneofCase.EvaluateCatchDispositionRequest,
        "golden payload case changed");
    var request = envelope.EvaluateCatchDispositionRequest;
    Require(request.HasFishId, "golden presence changed");
    Require(request.FishId == "marlin", "golden fish changed");
    Require(
        request.SelectedFishIds.SequenceEqual(["ruster", "marlin"]),
        "golden selected-fish policy changed");
    Require(request.InventoryFull, "golden inventory state changed");
    Require(envelope.ToByteArray().SequenceEqual(golden), "managed wire parity changed");
    return Task.CompletedTask;
}

static async Task OfflineHostNativeEngineRoundTrip()
{
    var enginePath = Environment.GetEnvironmentVariable("SONAR_FISHING_OFFLINE_ENGINE");
    if (string.IsNullOrWhiteSpace(enginePath))
    {
        throw new InvalidOperationException("SONAR_FISHING_OFFLINE_ENGINE is required");
    }

    var defaults = HostFishingRuntimeSettings.CreateDefault();
    var runtimeSettings = new HostFishingRuntimeSettings(
        Revision: 7,
        new RecoveryThresholds(12, 34, 5),
        defaults.Behavior with
        {
            AutoMeal = false,
            OverweightAction = OverweightPolicyAction.Release,
        },
        new FishingHotkeys("F10", "Tab", "e", "r", "q", "t"),
        new FishingSelectionPolicy(
            new Dictionary<string, bool> { ["marlin"] = true },
            new Dictionary<string, bool> { ["bag"] = true },
            new Dictionary<string, double> { ["marlin"] = 700.5 }));
    var receipt = await OfflineEngineDiagnosticGate.ExecuteAsync(
        enginePath,
        "  ТРОФЕЙНАЯ  ",
        "marlin",
        ["ruster", "marlin"],
        inventoryFull: false,
        runtimeSettings: runtimeSettings,
        timeout: TimeSpan.FromSeconds(10));
    Require(
        receipt.CatchQuality.NormalizedLabel == "Трофейная",
        "normalized label changed");
    Require(receipt.CatchQuality.StableKey == "trophy", "stable key changed");
    Require(
        receipt.CatchQuality.Recognized,
        "known catch quality was not recognized");
    Require(receipt.CatchDisposition.Keep, "selected fish was not kept");
    Require(
        receipt.CatchDisposition.Reason == "fish_selected",
        "catch disposition reason changed");
    Require(receipt.VerifiedEngineProcessId > 0, "engine PID was not verified");
    Require(receipt.ProcessContainmentVerified, "engine process was not contained");
    Require(receipt.NegotiatedProtocolMinor == 0, "protocol minor was not negotiated");
    Require(!receipt.SideEffectsEnabled, "offline Engine received side-effect authority");
    Require(receipt.AcceptedSettingsRevision == 7, "runtime settings were not accepted");
    Require(receipt.AcknowledgedHeartbeatId == 1, "heartbeat was not acknowledged");
    Require(receipt.SessionState.Revision == 1, "session snapshot revision changed");
    Require(
        receipt.SessionState.AcceptedSettingsRevision == 7,
        "session snapshot lost accepted settings revision");
    Require(!receipt.SessionState.Running, "read-only session claimed automation was running");
    Require(
        receipt.SessionState.DetectedStage == "read_only_session_started",
        "session snapshot stage changed");
    Require(receipt.SessionState.Totals.CaughtCount == 0, "empty native session was seeded");
    Require(receipt.SessionState.TackleItems.Count == 0, "empty native tackle state was seeded");
    Require(receipt.SessionState.FishRows.Count == 0, "empty native fish rows were seeded");
    Require(receipt.SessionState.CatchSizes.Count == 4, "native catch-size catalog changed");
    Require(
        receipt.ProductionAuthority == "native-cpp-diagnostic-engine",
        "production authority assertion changed");
    Require(receipt.Performance.BootstrapDuration > TimeSpan.Zero, "bootstrap timing missing");
    Require(receipt.Performance.IpcScenarioDuration > TimeSpan.Zero, "IPC timing missing");
    Require(receipt.Performance.TotalDuration >= receipt.Performance.BootstrapDuration, "total timing invalid");
    Require(receipt.Performance.EngineProcessorTime >= TimeSpan.Zero, "Engine CPU timing invalid");
    Require(receipt.Performance.EnginePeakWorkingSetBytes > 0, "Engine peak memory missing");
    Require(receipt.Performance.MeasuredIpcOperations == 6, "IPC operation count changed");
    Console.WriteLine(string.Create(
        CultureInfo.InvariantCulture,
        $"METRIC offline_engine bootstrap_ms={receipt.Performance.BootstrapDuration.TotalMilliseconds:F3} " +
        $"ipc_scenario_ms={receipt.Performance.IpcScenarioDuration.TotalMilliseconds:F3} " +
        $"total_ms={receipt.Performance.TotalDuration.TotalMilliseconds:F3} " +
        $"engine_cpu_ms={receipt.Performance.EngineProcessorTime.TotalMilliseconds:F3} " +
        $"engine_peak_working_set_bytes={receipt.Performance.EnginePeakWorkingSetBytes} " +
        $"ipc_operations={receipt.Performance.MeasuredIpcOperations}"));
}

static async Task OfflineHostKeepsSessionAlive()
{
    var enginePath = Environment.GetEnvironmentVariable("SONAR_FISHING_OFFLINE_ENGINE");
    if (string.IsNullOrWhiteSpace(enginePath))
    {
        throw new InvalidOperationException("SONAR_FISHING_OFFLINE_ENGINE is required");
    }

    var useCase = new OfflineEngineHealthUseCase(
        enginePath,
        TimeSpan.FromSeconds(10),
        HostFishingRuntimeSettings.CreateDefault(revision: 11));
    var first = await useCase.RunAsync(CancellationToken.None);
    Require(first.VerifiedEngineProcessId > 0, "long-lived Engine PID missing");
    Require(first.ProcessContainmentVerified, "long-lived Engine was not contained");
    await Task.Delay(TimeSpan.FromMilliseconds(2_250));
    var second = await useCase.RunAsync(CancellationToken.None);
    Require(
        second.VerifiedEngineProcessId == first.VerifiedEngineProcessId,
        "health recheck replaced the live Engine process");
    Require(
        second.SessionState.AcceptedSettingsRevision == 11,
        "long-lived Engine lost its accepted settings revision");

    await useCase.DisposeAsync();
    await useCase.DisposeAsync();
    Require(
        !IsProcessAlive(first.VerifiedEngineProcessId),
        "long-lived Engine survived Host session disposal");
}

static async Task OfflineHostRestartsCrashedEngine()
{
    var enginePath = Environment.GetEnvironmentVariable("SONAR_FISHING_OFFLINE_ENGINE");
    if (string.IsNullOrWhiteSpace(enginePath))
    {
        throw new InvalidOperationException("SONAR_FISHING_OFFLINE_ENGINE is required");
    }

    await using var useCase = new OfflineEngineHealthUseCase(
        enginePath,
        TimeSpan.FromSeconds(10),
        HostFishingRuntimeSettings.CreateDefault(revision: 12));
    var first = await useCase.RunAsync(CancellationToken.None);
    using (var crashed = System.Diagnostics.Process.GetProcessById(
               first.VerifiedEngineProcessId))
    {
        crashed.Kill(entireProcessTree: true);
        await crashed.WaitForExitAsync(CancellationToken.None);
    }

    var recovered = await useCase.RunAsync(CancellationToken.None);
    Require(
        recovered.VerifiedEngineProcessId != first.VerifiedEngineProcessId,
        "crashed Engine generation retained its PID");
    Require(recovered.ProcessContainmentVerified, "replacement Engine was not contained");
    Require(
        recovered.SessionState.AcceptedSettingsRevision == 12,
        "replacement Engine lost the full runtime settings snapshot");
    Require(
        !IsProcessAlive(first.VerifiedEngineProcessId),
        "crashed Engine generation was still alive after recovery");
}

static async Task OfflineHostAndEngineVerifyRawEntitlement()
{
    var enginePath = Environment.GetEnvironmentVariable("SONAR_FISHING_OFFLINE_ENGINE");
    if (string.IsNullOrWhiteSpace(enginePath))
    {
        throw new InvalidOperationException("SONAR_FISHING_OFFLINE_ENGINE is required");
    }
    var fixture = LoadEntitlementFixture();
    await using var session = await OfflineEngineSession.StartAsync(
        enginePath,
        TimeSpan.FromSeconds(10),
        CancellationToken.None);
    var first = await session.ApplySignedEntitlementAsync(
        fixture.Envelope,
        fixture.Trust,
        fixture.ClaimsPolicy(lastAcceptedGeneration: 0),
        CancellationToken.None);
    Require(first.HostVerification.Accepted, "Host rejected signed entitlement fixture");
    Require(first.EngineAccepted, $"Engine rejected signed entitlement fixture: {first.EngineReason}");
    Require(first.IndependentlyAccepted, "Host/Engine entitlement acceptance diverged");
    Require(first.AcceptedGeneration == 7, "Engine entitlement generation changed");
    Require(first.ExpiresUnixSeconds == 1787360883, "Engine entitlement expiry changed");

    var revokedGeneration = await session.RevokeSignedEntitlementAsync(
        CancellationToken.None);
    Require(revokedGeneration == 7, "Engine revoke lost previous generation");

    var restored = await session.ApplySignedEntitlementAsync(
        fixture.Envelope,
        fixture.Trust,
        fixture.ClaimsPolicy(lastAcceptedGeneration: 0),
        CancellationToken.None);
    Require(restored.IndependentlyAccepted, "Engine did not restore a freshly applied lease");

    var replay = await session.ApplySignedEntitlementAsync(
        fixture.Envelope,
        fixture.Trust,
        fixture.ClaimsPolicy(lastAcceptedGeneration: 0),
        CancellationToken.None);
    Require(replay.HostVerification.Accepted, "Host unexpectedly rejected replay fixture");
    Require(!replay.EngineAccepted, "Engine accepted equal-generation entitlement replay");
    Require(replay.EngineReason == "entitlement_lease_replayed", "Engine replay reason changed");
}

static async Task ProductionHostEngineUsesVerifiedIdentity()
{
    var productionEngine = Environment.GetEnvironmentVariable("SONAR_FISHING_PRODUCTION_ENGINE");
    if (string.IsNullOrWhiteSpace(productionEngine))
    {
        throw new InvalidOperationException("SONAR_FISHING_PRODUCTION_ENGINE is required");
    }

    using var bundle = ProductionBundleFixture.Create(productionEngine);
    await using var session = await OfflineEngineSession.StartProductionAsync(
        bundle.EnginePath,
        TimeSpan.FromSeconds(10),
        bundle.Identity,
        CancellationToken.None);
    var settings = HostFishingRuntimeSettings.CreateDefault(revision: 31);
    var acceptedRevision = await session.ApplyRuntimeSettingsAsync(
        settings,
        CancellationToken.None);
    Require(acceptedRevision == 31, "production Engine rejected runtime settings");
    Require(await session.PingAsync(CancellationToken.None) == 1,
        "production Engine heartbeat was not acknowledged");

    try
    {
        _ = await session.StartFishingSessionAsync(31, CancellationToken.None);
        throw new InvalidOperationException("production Engine started without entitlement");
    }
    catch (EngineCommandRejectedException rejection)
    {
        Require(
            rejection.Reason == "signed_entitlement_required_before_session",
            $"production admission reason changed: {rejection.Reason}");
    }
}

static async Task PackagedProductionPairLifecycle()
{
    var bundleRoot = Environment.GetEnvironmentVariable("SONAR_FISHING_PRODUCTION_BUNDLE");
    if (string.IsNullOrWhiteSpace(bundleRoot))
    {
        throw new InvalidOperationException("SONAR_FISHING_PRODUCTION_BUNDLE is required");
    }
    bundleRoot = Path.GetFullPath(bundleRoot);
    var hostPath = Path.Combine(bundleRoot, "Sonar.exe");
    var enginePath = Path.Combine(bundleRoot, "Sonar.Engine.exe");
    var identity = BundleSessionIdentityLoader.Load(enginePath, hostPath);
    var firstProcessId = 0;

    await using (var first = await OfflineEngineSession.StartProductionAsync(
                     enginePath,
                     TimeSpan.FromSeconds(10),
                     identity,
                     CancellationToken.None))
    {
        firstProcessId = first.ProcessId;
        Require(firstProcessId > 0, "packaged Engine PID missing");
        Require(first.IsContained, "packaged Engine was not contained");
        Require(first.IsAlive, "packaged Engine exited during bootstrap");
        var accepted = await first.ApplyRuntimeSettingsAsync(
            HostFishingRuntimeSettings.CreateDefault(revision: 41),
            CancellationToken.None);
        Require(accepted == 41, "packaged Engine rejected runtime settings");
        Require(await first.PingAsync(CancellationToken.None) == 1,
            "packaged Engine heartbeat was not acknowledged");
        try
        {
            _ = await first.StartFishingSessionAsync(41, CancellationToken.None);
            throw new InvalidOperationException(
                "packaged Engine started without signed entitlement");
        }
        catch (EngineCommandRejectedException rejection)
        {
            Require(
                rejection.Reason == "signed_entitlement_required_before_session",
                $"packaged admission reason changed: {rejection.Reason}");
        }

        using var crashed = System.Diagnostics.Process.GetProcessById(firstProcessId);
        crashed.Kill(entireProcessTree: true);
        await crashed.WaitForExitAsync(CancellationToken.None);
        Require(!first.IsAlive, "crashed packaged Engine still reports alive");
    }
    Require(!IsProcessAlive(firstProcessId),
        "crashed packaged Engine survived session disposal");

    var replacementProcessId = 0;
    await using (var replacement = await OfflineEngineSession.StartProductionAsync(
                     enginePath,
                     TimeSpan.FromSeconds(10),
                     identity,
                     CancellationToken.None))
    {
        replacementProcessId = replacement.ProcessId;
        Require(replacementProcessId > 0 && replacementProcessId != firstProcessId,
            "packaged Engine recovery retained the crashed process identity");
        Require(replacement.IsContained, "replacement packaged Engine was not contained");
        Require(await replacement.PingAsync(CancellationToken.None) == 1,
            "replacement packaged Engine heartbeat failed");
    }
    Require(!IsProcessAlive(replacementProcessId),
        "replacement packaged Engine survived bounded disposal");
}

static EntitlementFixture LoadEntitlementFixture()
{
    var root = Path.Combine(AppContext.BaseDirectory, "fixtures", "licensing");
    var values = File.ReadAllLines(Path.Combine(root, "signed-entitlement-v1.properties"))
        .Where(line => line.Length != 0 && !line.StartsWith('#'))
        .Select(line => line.Split('=', 2))
        .ToDictionary(parts => parts[0], parts => parts[1], StringComparer.Ordinal);
    Require(values["schemaVersion"] == "1", "Entitlement fixture schema changed");
    var rawBody = Convert.FromHexString(
        File.ReadAllText(Path.Combine(root, "signed-entitlement-v1-body.hex")).Trim());
    var publicKey = File.ReadAllText(
        Path.Combine(root, "signed-entitlement-v1-public.pem")).Trim();
    var now = DateTimeOffset.FromUnixTimeSeconds(long.Parse(values["nowUnix"]));
    return new EntitlementFixture(
        new FishingSignedEntitlementEnvelope(
            values["method"],
            values["requestTarget"],
            values["host"],
            values["date"],
            values["digest"],
            values["signature"],
            rawBody),
        new FishingEntitlementTrustPolicy(
            values["keyId"],
            values["method"],
            values["requestTarget"],
            values["host"],
            publicKey,
            now,
            TimeSpan.FromMinutes(5),
            TimeSpan.FromMinutes(1)),
        values);
}

static bool IsProcessAlive(int processId)
{
    try
    {
        using var process = System.Diagnostics.Process.GetProcessById(processId);
        return !process.HasExited;
    }
    catch (ArgumentException)
    {
        return false;
    }
}

static void Require(bool condition, string message)
{
    if (!condition)
    {
        throw new InvalidOperationException(message);
    }
}

internal sealed record EntitlementFixture(
    FishingSignedEntitlementEnvelope Envelope,
    FishingEntitlementTrustPolicy Trust,
    IReadOnlyDictionary<string, string> Values)
{
    internal FishingEntitlementClaimPolicy ClaimsPolicy(ulong lastAcceptedGeneration) => new(
        Values["machineFingerprint"],
        Values["bundleManifestHash"],
        Values["policyId"],
        ["fishing", "fishing_bot"],
        lastAcceptedGeneration,
        TimeSpan.FromMinutes(10));
}
