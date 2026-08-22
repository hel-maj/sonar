using System.Security.Cryptography;
using System.Text;

namespace Sonar.Fishing.Host.TelegramPage;

public enum TelegramAvailabilityStatus
{
    Unknown = 0,
    Checking = 1,
    Available = 2,
    Unavailable = 3,
}

public sealed class TelegramConfigurationIdentity : IEquatable<TelegramConfigurationIdentity>
{
    private readonly byte[] digest;

    private TelegramConfigurationIdentity(byte[] digest)
    {
        this.digest = digest;
    }

    public static TelegramConfigurationIdentity Create(
        string botToken,
        IEnumerable<long> adminIds)
    {
        ArgumentNullException.ThrowIfNull(botToken);
        ArgumentNullException.ThrowIfNull(adminIds);
        var normalized = string.Concat(
            botToken.Trim(),
            "\n",
            string.Join(',', adminIds));
        return new TelegramConfigurationIdentity(
            SHA256.HashData(Encoding.UTF8.GetBytes(normalized)));
    }

    public bool Equals(TelegramConfigurationIdentity? other) =>
        other is not null &&
        CryptographicOperations.FixedTimeEquals(digest, other.digest);

    public override bool Equals(object? obj) =>
        obj is TelegramConfigurationIdentity other && Equals(other);

    public override int GetHashCode() => BitConverter.ToInt32(digest, 0);
}

public sealed record TelegramAvailability(
    TelegramAvailabilityStatus Status,
    TelegramConfigurationIdentity? Configuration,
    string Error)
{
    public static TelegramAvailability Unknown { get; } = new(
        TelegramAvailabilityStatus.Unknown,
        null,
        string.Empty);

    public static TelegramAvailability Checking(
        string botToken,
        IEnumerable<long> adminIds) => new(
            TelegramAvailabilityStatus.Checking,
            TelegramConfigurationIdentity.Create(botToken, adminIds),
            string.Empty);

    public static TelegramAvailability Available(
        string botToken,
        IEnumerable<long> adminIds) => new(
            TelegramAvailabilityStatus.Available,
            TelegramConfigurationIdentity.Create(botToken, adminIds),
            string.Empty);

    public static TelegramAvailability Unavailable(
        string botToken,
        IEnumerable<long> adminIds,
        string error) => new(
            TelegramAvailabilityStatus.Unavailable,
            TelegramConfigurationIdentity.Create(botToken, adminIds),
            error?.Trim() ?? string.Empty);

    public bool Matches(
        string botToken,
        IEnumerable<long> adminIds) =>
        Configuration is not null &&
        Configuration.Equals(TelegramConfigurationIdentity.Create(botToken, adminIds));
}
