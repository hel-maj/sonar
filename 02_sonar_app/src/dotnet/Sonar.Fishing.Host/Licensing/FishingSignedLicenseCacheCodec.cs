using System.IO;
using System.Text.Json;
using System.Text.Json.Serialization;

namespace Sonar.Fishing.Host.Licensing;

internal static class FishingSignedLicenseCacheCodec
{
    private const int MaximumTokenCharacters = 512 * 1024;
    private const int MaximumRawBodyBytes = 256 * 1024;
    private static readonly JsonSerializerOptions JsonOptions = new()
    {
        PropertyNamingPolicy = JsonNamingPolicy.CamelCase,
        PropertyNameCaseInsensitive = false,
        UnmappedMemberHandling = JsonUnmappedMemberHandling.Disallow,
        MaxDepth = 8,
    };

    internal static string Encode(FishingSignedEntitlementEnvelope envelope)
    {
        ArgumentNullException.ThrowIfNull(envelope);
        if (envelope.RawBody.Length is 0 or > MaximumRawBodyBytes)
        {
            throw new InvalidDataException("license_cache_body_size_invalid");
        }
        var document = new CacheDocument
        {
            SchemaVersion = 1,
            Method = envelope.Method,
            RequestTarget = envelope.RequestTarget,
            Host = envelope.Host,
            Date = envelope.DateHeader,
            Digest = envelope.DigestHeader,
            Signature = envelope.SignatureHeader,
            RawBody = envelope.RawBody.ToArray(),
        };
        var token = Convert.ToBase64String(JsonSerializer.SerializeToUtf8Bytes(document, JsonOptions));
        return token.Length <= MaximumTokenCharacters
            ? token
            : throw new InvalidDataException("license_cache_token_size_invalid");
    }

    internal static FishingSignedEntitlementEnvelope Decode(string token)
    {
        if (string.IsNullOrWhiteSpace(token) || token.Length > MaximumTokenCharacters)
        {
            throw new InvalidDataException("license_cache_token_invalid");
        }
        byte[] bytes;
        try
        {
            bytes = Convert.FromBase64String(token);
        }
        catch (FormatException exception)
        {
            throw new InvalidDataException("license_cache_token_invalid", exception);
        }
        var document = JsonSerializer.Deserialize<CacheDocument>(bytes, JsonOptions)
            ?? throw new InvalidDataException("license_cache_document_missing");
        if (document.SchemaVersion != 1 ||
            document.RawBody is null ||
            document.RawBody.Length is 0 or > MaximumRawBodyBytes)
        {
            throw new InvalidDataException("license_cache_document_invalid");
        }
        return new FishingSignedEntitlementEnvelope(
            Require(document.Method, 16),
            Require(document.RequestTarget, 512),
            Require(document.Host, 256),
            Require(document.Date, 64),
            Require(document.Digest, 128),
            Require(document.Signature, 2048),
            document.RawBody);
    }

    private static string Require(string? value, int maximum) =>
        !string.IsNullOrWhiteSpace(value) && value.Length <= maximum &&
        !value.Any(character => character is '\r' or '\n')
            ? value
            : throw new InvalidDataException("license_cache_field_invalid");

    private sealed class CacheDocument
    {
        public int SchemaVersion { get; set; }

        public string? Method { get; set; }

        public string? RequestTarget { get; set; }

        public string? Host { get; set; }

        public string? Date { get; set; }

        public string? Digest { get; set; }

        public string? Signature { get; set; }

        public byte[]? RawBody { get; set; }
    }
}
