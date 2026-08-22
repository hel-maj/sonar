namespace Sonar.Fishing.Host.StartupGate;

public enum StartupAdmissionKind
{
    Allowed = 1,
    Blocked = 2,
    Unavailable = 3,
}

public sealed record StartupAdmissionDecision(
    StartupAdmissionKind Kind,
    string DownloadUrl,
    string Reason)
{
    public bool CanCreateMainWindow => Kind == StartupAdmissionKind.Allowed;
}

public static class StartupAdmissionPolicy
{
    public static StartupAdmissionDecision InitialLaunch(StartupBlockStatus status)
    {
        ArgumentNullException.ThrowIfNull(status);
        if (!status.Checked || status.Error.Length != 0)
        {
            return new StartupAdmissionDecision(
                StartupAdmissionKind.Unavailable,
                string.Empty,
                status.Error.Length == 0 ? "startup_block_check_missing" : status.Error);
        }
        return status.Blocked
            ? new StartupAdmissionDecision(
                StartupAdmissionKind.Blocked,
                status.DownloadUrl,
                "startup_blocked")
            : new StartupAdmissionDecision(
                StartupAdmissionKind.Allowed,
                string.Empty,
                string.Empty);
    }

    public static bool MustStopRunningApplication(StartupBlockStatus status)
    {
        ArgumentNullException.ThrowIfNull(status);
        return status.Checked && status.Blocked && status.Error.Length == 0;
    }
}
