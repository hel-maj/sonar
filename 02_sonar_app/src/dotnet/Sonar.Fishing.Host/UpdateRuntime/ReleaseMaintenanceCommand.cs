using System.Diagnostics;
using System.IO;
using System.Text.Json;
using System.Text.Json.Serialization;
using System.Text.RegularExpressions;

namespace Sonar.Fishing.Host.UpdateRuntime;

internal sealed record ReleaseMaintenanceCommandOptions(
    LocalReleaseMaintenanceRequest Request,
    IReadOnlyList<int> WaitProcessIds,
    TimeSpan WaitTimeout,
    string ReceiptPath);

internal sealed record ReleaseMaintenanceReceipt(
    [property: JsonPropertyName("schema_version")] int SchemaVersion,
    [property: JsonPropertyName("accepted")] bool Accepted,
    [property: JsonPropertyName("status")] string Status,
    [property: JsonPropertyName("version")] string Version,
    [property: JsonPropertyName("host_sha256")] string HostSha256,
    [property: JsonPropertyName("engine_sha256")] string EngineSha256,
    [property: JsonPropertyName("changed")] bool Changed,
    [property: JsonPropertyName("reason")] string Reason);

internal static partial class ReleaseMaintenanceCommand
{
    private const string Command = "--release-maintenance";
    private static readonly JsonSerializerOptions ReceiptJsonOptions = new()
    {
        WriteIndented = false,
    };

    internal static bool IsRequest(IReadOnlyList<string> arguments) =>
        arguments.Count > 0 &&
        string.Equals(arguments[0], Command, StringComparison.Ordinal);

    internal static ReleaseMaintenanceCommandOptions Parse(IReadOnlyList<string> arguments)
    {
        if (!IsRequest(arguments))
        {
            throw new InvalidOperationException("release_maintenance_command_missing");
        }

        string? action = null;
        string? source = null;
        string? target = null;
        string? backup = null;
        string? legacyLicenseSettings = null;
        string? receipt = null;
        var waitPids = new List<int>();
        var waitTimeoutSeconds = 60;
        var dryRun = false;
        var developmentUnsigned = false;
        var developerFullAccess = false;
        var seen = new HashSet<string>(StringComparer.Ordinal);

        for (var index = 1; index < arguments.Count; index++)
        {
            var token = arguments[index];
            switch (token)
            {
                case "--development-unsigned":
                    RequireUnique(seen, token);
                    developmentUnsigned = true;
                    break;
                case "--developer-full-access":
                    RequireUnique(seen, token);
                    developerFullAccess = true;
                    break;
                case "--dry-run":
                    RequireUnique(seen, token);
                    dryRun = true;
                    break;
                case "--wait-pid":
                    if (++index >= arguments.Count ||
                        !int.TryParse(arguments[index], out var processId) ||
                        processId <= 0 || processId == Environment.ProcessId ||
                        waitPids.Count >= 2)
                    {
                        throw new InvalidOperationException("release_maintenance_wait_pid_invalid");
                    }
                    waitPids.Add(processId);
                    break;
                case "--action":
                    action = ReadUniqueValue(arguments, ref index, seen, token);
                    break;
                case "--source":
                    source = ReadUniqueValue(arguments, ref index, seen, token);
                    break;
                case "--target":
                    target = ReadUniqueValue(arguments, ref index, seen, token);
                    break;
                case "--backup":
                    backup = ReadUniqueValue(arguments, ref index, seen, token);
                    break;
                case "--receipt":
                    receipt = ReadUniqueValue(arguments, ref index, seen, token);
                    break;
                case "--legacy-license-settings":
                    legacyLicenseSettings = ReadUniqueValue(
                        arguments,
                        ref index,
                        seen,
                        token);
                    break;
                case "--wait-timeout-seconds":
                    var timeout = ReadUniqueValue(arguments, ref index, seen, token);
                    if (!int.TryParse(timeout, out waitTimeoutSeconds) ||
                        waitTimeoutSeconds is < 5 or > 120)
                    {
                        throw new InvalidOperationException(
                            "release_maintenance_wait_timeout_invalid");
                    }
                    break;
                default:
                    throw new InvalidOperationException("release_maintenance_argument_invalid");
            }
        }

        if (!developmentUnsigned)
        {
            throw new InvalidOperationException(
                "release_maintenance_development_unsigned_required");
        }
        if (string.IsNullOrWhiteSpace(source) || string.IsNullOrWhiteSpace(target) ||
            string.IsNullOrWhiteSpace(receipt) || !Path.IsPathFullyQualified(source) ||
            !Path.IsPathFullyQualified(target) || !Path.IsPathFullyQualified(receipt))
        {
            throw new InvalidOperationException("release_maintenance_path_invalid");
        }
        var parsedAction = action switch
        {
            "install" => LocalReleaseMaintenanceAction.Install,
            "update" => LocalReleaseMaintenanceAction.Update,
            "rollback" => LocalReleaseMaintenanceAction.Rollback,
            "recover" => LocalReleaseMaintenanceAction.Recover,
            "import-license" => LocalReleaseMaintenanceAction.ImportLicense,
            _ => throw new InvalidOperationException("release_maintenance_action_invalid"),
        };
        if ((parsedAction is LocalReleaseMaintenanceAction.Update or
                LocalReleaseMaintenanceAction.Rollback) &&
            (string.IsNullOrWhiteSpace(backup) || !Path.IsPathFullyQualified(backup)))
        {
            throw new InvalidOperationException("release_maintenance_backup_required");
        }
        if ((parsedAction is LocalReleaseMaintenanceAction.Install or
                LocalReleaseMaintenanceAction.Recover or
                LocalReleaseMaintenanceAction.ImportLicense) && backup is not null)
        {
            throw new InvalidOperationException("release_maintenance_backup_unexpected");
        }
        if (parsedAction == LocalReleaseMaintenanceAction.ImportLicense)
        {
            if (string.IsNullOrWhiteSpace(legacyLicenseSettings) ||
                !Path.IsPathFullyQualified(legacyLicenseSettings))
            {
                throw new InvalidOperationException("legacy_license_source_required");
            }
        }
        else if (legacyLicenseSettings is not null)
        {
            throw new InvalidOperationException("legacy_license_source_unexpected");
        }

        return new ReleaseMaintenanceCommandOptions(
            new LocalReleaseMaintenanceRequest(
                parsedAction,
                Path.GetFullPath(source),
                Path.GetFullPath(target),
                backup is null ? null : Path.GetFullPath(backup),
                dryRun,
                developerFullAccess
                    ? LocalReleaseChannel.DeveloperFullAccessUnsigned
                    : LocalReleaseChannel.DevelopmentUnsigned,
                legacyLicenseSettings is null
                    ? null
                    : Path.GetFullPath(legacyLicenseSettings)),
            waitPids.AsReadOnly(),
            TimeSpan.FromSeconds(waitTimeoutSeconds),
            Path.GetFullPath(receipt));
    }

    internal static async Task<int> ExecuteAsync(
        IReadOnlyList<string> arguments,
        CancellationToken cancellationToken)
    {
        ReleaseMaintenanceCommandOptions? options = null;
        ReleaseMaintenanceReceipt receipt;
        try
        {
            options = Parse(arguments);
            if (!SamePath(options.Request.SourceBundle, AppContext.BaseDirectory))
            {
                throw new InvalidOperationException(
                    "release_maintenance_executor_source_mismatch");
            }
            await WaitForExitAsync(
                options.WaitProcessIds,
                options.WaitTimeout,
                cancellationToken).ConfigureAwait(false);
            var result = LocalReleaseMaintenance.Execute(options.Request);
            receipt = new ReleaseMaintenanceReceipt(
                1,
                true,
                result.Status,
                result.Version,
                result.HostSha256,
                result.EngineSha256,
                result.Changed,
                "accepted");
        }
        catch (Exception exception) when (
            exception is InvalidOperationException or IOException or
                UnauthorizedAccessException or OperationCanceledException)
        {
            receipt = new ReleaseMaintenanceReceipt(
                1,
                false,
                "rejected",
                string.Empty,
                string.Empty,
                string.Empty,
                false,
                SanitizedReason(exception));
        }

        if (options is not null)
        {
            WriteReceipt(options.ReceiptPath, receipt);
        }
        return receipt.Accepted ? 0 : 20;
    }

    private static async Task WaitForExitAsync(
        IReadOnlyList<int> processIds,
        TimeSpan timeout,
        CancellationToken cancellationToken)
    {
        using var deadline = CancellationTokenSource.CreateLinkedTokenSource(cancellationToken);
        deadline.CancelAfter(timeout);
        try
        {
            foreach (var processId in processIds.Distinct())
            {
                try
                {
                    using var process = Process.GetProcessById(processId);
                    await process.WaitForExitAsync(deadline.Token).ConfigureAwait(false);
                }
                catch (ArgumentException)
                {
                    // It exited between command preparation and observation.
                }
            }
        }
        catch (OperationCanceledException exception) when (!cancellationToken.IsCancellationRequested)
        {
            throw new InvalidOperationException("release_maintenance_wait_timeout", exception);
        }
    }

    private static void WriteReceipt(string path, ReleaseMaintenanceReceipt receipt)
    {
        var parent = Path.GetDirectoryName(path);
        if (string.IsNullOrWhiteSpace(parent) || !Directory.Exists(parent) ||
            (new DirectoryInfo(parent).Attributes & FileAttributes.ReparsePoint) != 0 ||
            File.Exists(path))
        {
            throw new InvalidOperationException("release_maintenance_receipt_path_invalid");
        }
        var json = JsonSerializer.Serialize(receipt, ReceiptJsonOptions) + "\n";
        using var output = new FileStream(
            path,
            FileMode.CreateNew,
            FileAccess.Write,
            FileShare.Read,
            bufferSize: 4096,
            FileOptions.WriteThrough);
        using var writer = new StreamWriter(output, new System.Text.UTF8Encoding(false));
        writer.Write(json);
    }

    private static string ReadUniqueValue(
        IReadOnlyList<string> arguments,
        ref int index,
        ISet<string> seen,
        string token)
    {
        RequireUnique(seen, token);
        if (++index >= arguments.Count || string.IsNullOrWhiteSpace(arguments[index]))
        {
            throw new InvalidOperationException("release_maintenance_argument_invalid");
        }
        return arguments[index];
    }

    private static void RequireUnique(ISet<string> seen, string token)
    {
        if (!seen.Add(token))
        {
            throw new InvalidOperationException("release_maintenance_argument_duplicate");
        }
    }

    private static string SanitizedReason(Exception exception) =>
        ReasonPattern().IsMatch(exception.Message)
            ? exception.Message
            : "release_maintenance_failed";

    private static bool SamePath(string left, string right) => string.Equals(
        Path.GetFullPath(left).TrimEnd(Path.DirectorySeparatorChar),
        Path.GetFullPath(right).TrimEnd(Path.DirectorySeparatorChar),
        StringComparison.OrdinalIgnoreCase);

    [GeneratedRegex("^[a-z0-9_]{1,96}$", RegexOptions.CultureInvariant)]
    private static partial Regex ReasonPattern();
}
