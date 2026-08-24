using Sonar.Fishing.Host.SettingsPersistence;

namespace Sonar.Fishing.Host.Licensing;

internal static class DeveloperFullAccessPolicy
{
    internal static IReadOnlyList<string> Features { get; } =
    [
        "fishing",
        "fishing_bot",
        "fishing_tackle",
        "statistics",
        "telegram",
    ];

    internal static LicenseHostSettings VisibleLicense { get; } = new(
        "local-owner",
        DateTimeOffset.UnixEpoch.ToString("O"),
        string.Empty,
        "owner",
        "Локальный доступ",
        Features,
        Array.Empty<string>());
}

internal sealed class DeveloperLicenseRuntimeLifecycle : ILicenseRuntimeLifecycle
{
    internal static DeveloperLicenseRuntimeLifecycle Instance { get; } = new();

    private DeveloperLicenseRuntimeLifecycle()
    {
    }

    public Task StartAsync() => Task.CompletedTask;

    public Task StopAsync() => Task.CompletedTask;
}
