using System.IO;
using System.Text;
using System.Text.Encodings.Web;
using System.Text.Json;
using Sonar.Licensing.Verification;

namespace Sonar.Fishing.Host.StartupGate;

public sealed class StartupBlockResponseVerifier
{
    public const int MaximumResponseBytes = 16 * 1024;
    private readonly byte[] publicKey;

    public StartupBlockResponseVerifier(string encodedPublicKey)
    {
        publicKey = DecodePublicKey(encodedPublicKey);
    }

    public StartupBlockResponseVerifier(ReadOnlySpan<byte> publicKey)
    {
        if (publicKey.Length != Ed25519DetachedSignatureVerifier.PublicKeyLength)
        {
            throw new ArgumentException("startup_block_public_key_invalid", nameof(publicKey));
        }
        this.publicKey = publicKey.ToArray();
    }

    public StartupBlockStatus Verify(ReadOnlySpan<byte> utf8Json)
    {
        if (utf8Json.Length is 0 or > MaximumResponseBytes)
        {
            return StartupBlockStatus.Failure("startup_block_response_size_invalid");
        }
        try
        {
            using var document = JsonDocument.Parse(utf8Json.ToArray(), new JsonDocumentOptions
            {
                AllowTrailingCommas = false,
                CommentHandling = JsonCommentHandling.Disallow,
                MaxDepth = 8,
            });
            var root = document.RootElement;
            if (root.ValueKind != JsonValueKind.Object ||
                !root.TryGetProperty("blocked", out var blockedElement) ||
                blockedElement.ValueKind is not JsonValueKind.True and not JsonValueKind.False ||
                !root.TryGetProperty("download_url", out var downloadElement) ||
                downloadElement.ValueKind != JsonValueKind.String ||
                !root.TryGetProperty("signature", out var signatureElement) ||
                signatureElement.ValueKind != JsonValueKind.String)
            {
                return StartupBlockStatus.Failure("startup_block_response_contract_invalid");
            }

            var blocked = blockedElement.GetBoolean();
            var downloadUrl = (downloadElement.GetString() ?? string.Empty).Trim();
            if (downloadUrl.Length > 2048)
            {
                return StartupBlockStatus.Failure("startup_block_download_url_invalid");
            }
            var signature = DecodeBase64Url(signatureElement.GetString() ?? string.Empty);
            var canonicalPayload = CanonicalPayload(blocked, downloadUrl);
            if (!Ed25519DetachedSignatureVerifier.Verify(
                publicKey,
                canonicalPayload,
                signature))
            {
                return StartupBlockStatus.Failure("startup_block_signature_invalid");
            }
            if (blocked && !IsSafeDownloadUrl(downloadUrl))
            {
                return new StartupBlockStatus(
                    true,
                    false,
                    string.Empty,
                    "startup_block_download_url_invalid");
            }
            return new StartupBlockStatus(
                true,
                blocked,
                downloadUrl,
                string.Empty);
        }
        catch (JsonException)
        {
            return StartupBlockStatus.Failure("startup_block_response_json_invalid");
        }
        catch (FormatException)
        {
            return StartupBlockStatus.Failure("startup_block_signature_encoding_invalid");
        }
    }

    internal static byte[] CanonicalPayload(bool blocked, string downloadUrl)
    {
        using var buffer = new MemoryStream();
        using (var writer = new Utf8JsonWriter(buffer, new JsonWriterOptions
        {
            Encoder = JavaScriptEncoder.UnsafeRelaxedJsonEscaping,
            Indented = false,
            SkipValidation = false,
        }))
        {
            writer.WriteStartObject();
            writer.WriteBoolean("blocked", blocked);
            writer.WriteString("download_url", downloadUrl);
            writer.WriteEndObject();
        }
        return buffer.ToArray();
    }

    private static byte[] DecodePublicKey(string encodedPublicKey)
    {
        ArgumentNullException.ThrowIfNull(encodedPublicKey);
        var value = encodedPublicKey.Trim();
        byte[] decoded;
        if (value.Length == 64 && value.All(Uri.IsHexDigit))
        {
            decoded = Convert.FromHexString(value);
        }
        else
        {
            try
            {
                decoded = DecodeBase64Url(value);
            }
            catch (FormatException exception)
            {
                throw new ArgumentException(
                    "startup_block_public_key_invalid",
                    nameof(encodedPublicKey),
                    exception);
            }
        }
        if (decoded.Length != Ed25519DetachedSignatureVerifier.PublicKeyLength)
        {
            throw new ArgumentException("startup_block_public_key_invalid", nameof(encodedPublicKey));
        }
        return decoded;
    }

    private static byte[] DecodeBase64Url(string value)
    {
        var normalized = value.Trim();
        if (normalized.Length == 0 ||
            normalized.Any(character =>
                !(char.IsLetterOrDigit(character) || character is '-' or '_' or '=')))
        {
            throw new FormatException("startup_block_base64url_invalid");
        }
        var firstPadding = normalized.IndexOf('=');
        if (firstPadding >= 0 && normalized[firstPadding..].Any(character => character != '='))
        {
            throw new FormatException("startup_block_base64url_invalid");
        }
        normalized = normalized.TrimEnd('=').Replace('-', '+').Replace('_', '/');
        normalized = normalized.PadRight((normalized.Length + 3) / 4 * 4, '=');
        return Convert.FromBase64String(normalized);
    }

    private static bool IsSafeDownloadUrl(string value) =>
        Uri.TryCreate(value, UriKind.Absolute, out var uri) &&
        string.Equals(uri.Scheme, Uri.UriSchemeHttps, StringComparison.OrdinalIgnoreCase) &&
        string.IsNullOrEmpty(uri.UserInfo);
}
