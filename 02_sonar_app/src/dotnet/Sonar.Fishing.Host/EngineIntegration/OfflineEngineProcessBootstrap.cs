using System.Diagnostics;
using System.IO;
using Sonar.Platform.Ipc.NamedPipes;

namespace Sonar.Fishing.Host.EngineIntegration;

internal enum EngineProcessAuthorityMode
{
    OfflineDiagnostics,
    Production,
}

internal static class OfflineEngineProcessBootstrap
{
    internal static string RequireEnginePath(string engineExecutable)
    {
        ArgumentException.ThrowIfNullOrWhiteSpace(engineExecutable);
        var enginePath = Path.GetFullPath(engineExecutable);
        if (!File.Exists(enginePath))
        {
            throw new FileNotFoundException("Offline Fishing Engine was not built.", enginePath);
        }
        return enginePath;
    }

    internal static ProcessStartInfo CreateStartInfo(
        string enginePath,
        PipeBootstrap bootstrap,
        string sessionId,
        EngineSessionIdentity identity,
        EngineProcessAuthorityMode authorityMode = EngineProcessAuthorityMode.OfflineDiagnostics)
    {
        ArgumentNullException.ThrowIfNull(identity);
        if (identity.Production !=
            (authorityMode == EngineProcessAuthorityMode.Production))
        {
            throw new InvalidOperationException("engine_session_identity_mode_mismatch");
        }
        var startInfo = new ProcessStartInfo
        {
            FileName = enginePath,
            UseShellExecute = false,
            CreateNoWindow = true,
            WorkingDirectory = Path.GetDirectoryName(enginePath)!,
        };
        if (authorityMode == EngineProcessAuthorityMode.OfflineDiagnostics)
        {
            startInfo.Environment["SONAR_FISHING_OFFLINE_GATE"] = "1";
        }
        else
        {
            startInfo.Environment["SONAR_FISHING_ENGINE_MODE"] = "production";
            startInfo.Environment["SONAR_FISHING_HOST_BUILD_ID"] = identity.HostBuildId;
            startInfo.Environment["SONAR_FISHING_ENGINE_BUILD_ID"] = identity.EngineBuildId;
            startInfo.Environment["SONAR_FISHING_BUNDLE_MANIFEST_HASH"] =
                identity.BundleManifestHash;
        }
        startInfo.Environment["SONAR_FISHING_CONTROL_PIPE"] = bootstrap.ControlPipeName;
        startInfo.Environment["SONAR_FISHING_EVENT_PIPE"] = bootstrap.EventsPipeName;
        startInfo.Environment["SONAR_FISHING_BOOTSTRAP_NONCE"] =
            Convert.ToHexString(bootstrap.Nonce);
        startInfo.Environment["SONAR_FISHING_EXPECTED_HOST_PID"] =
            Environment.ProcessId.ToString();
        startInfo.Environment["SONAR_FISHING_SESSION_ID"] = sessionId;
        return startInfo;
    }
}
