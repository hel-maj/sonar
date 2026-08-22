using System.IO;
using System.Text.Encodings.Web;
using System.Text.Json;

namespace Sonar.Fishing.Host.UpdateRuntime;

internal sealed class SignedReleaseManifestVerifier
{
    internal const int MaximumEnvelopeBytes = 64 * 1024;
    internal const long MaximumPayloadBytes = 512L * 1024 * 1024;
    private static readonly string[] RequiredPaths =
        ["Sonar.Engine.exe", "Sonar.exe", "bundle-manifest.json"];
    private static readonly HashSet<string> RootProperties =
    [
        "format_version",
        "product",
        "version",
        "generation",
        "files",
        "signature",
    ];
    private static readonly HashSet<string> FileProperties =
    [
        "path",
        "bytes",
        "sha256",
        "download_url",
    ];
    private readonly IReleaseSignatureVerifier signatureVerifier;

    internal SignedReleaseManifestVerifier(IReleaseSignatureVerifier signatureVerifier)
    {
        this.signatureVerifier = signatureVerifier ??
            throw new ArgumentNullException(nameof(signatureVerifier));
    }

    internal ReleaseManifestVerificationResult Verify(ReadOnlySpan<byte> utf8Json)
    {
        if (utf8Json.Length is 0 or > MaximumEnvelopeBytes)
        {
            return ReleaseManifestVerificationResult.Failure("release_manifest_size_invalid");
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
                !HasExactProperties(root, RootProperties) ||
                !root.TryGetProperty("format_version", out var formatElement) ||
                !formatElement.TryGetInt32(out var formatVersion) ||
                formatVersion != 1 ||
                !root.TryGetProperty("product", out var productElement) ||
                productElement.ValueKind != JsonValueKind.String ||
                !string.Equals(productElement.GetString(), "Sonar Fishing", StringComparison.Ordinal) ||
                !root.TryGetProperty("version", out var versionElement) ||
                versionElement.ValueKind != JsonValueKind.String ||
                !root.TryGetProperty("generation", out var generationElement) ||
                !generationElement.TryGetInt64(out var generation) ||
                generation <= 0 ||
                !root.TryGetProperty("files", out var filesElement) ||
                filesElement.ValueKind != JsonValueKind.Array ||
                !root.TryGetProperty("signature", out var signatureElement) ||
                signatureElement.ValueKind != JsonValueKind.String)
            {
                return ReleaseManifestVerificationResult.Failure("release_manifest_contract_invalid");
            }

            var version = versionElement.GetString() ?? string.Empty;
            if (!IsCanonicalVersion(version))
            {
                return ReleaseManifestVerificationResult.Failure("release_version_invalid");
            }

            var files = ParseFiles(filesElement);
            if (files is null)
            {
                return ReleaseManifestVerificationResult.Failure("release_files_invalid");
            }

            var signature = DecodeBase64Url(signatureElement.GetString() ?? string.Empty);
            var canonical = CanonicalPayload(version, generation, files);
            if (!signatureVerifier.Verify(canonical, signature))
            {
                return ReleaseManifestVerificationResult.Failure("release_signature_invalid");
            }

            return new ReleaseManifestVerificationResult(
                true,
                new ProductReleaseManifest(version, generation, files, utf8Json.ToArray()),
                string.Empty);
        }
        catch (JsonException)
        {
            return ReleaseManifestVerificationResult.Failure("release_manifest_json_invalid");
        }
        catch (FormatException)
        {
            return ReleaseManifestVerificationResult.Failure("release_signature_encoding_invalid");
        }
        catch (OverflowException)
        {
            return ReleaseManifestVerificationResult.Failure("release_manifest_contract_invalid");
        }
    }

    internal static byte[] CanonicalPayload(
        string version,
        long generation,
        IReadOnlyList<ReleaseFileDescriptor> files)
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
            writer.WriteNumber("format_version", 1);
            writer.WriteString("product", "Sonar Fishing");
            writer.WriteString("version", version);
            writer.WriteNumber("generation", generation);
            writer.WritePropertyName("files");
            writer.WriteStartArray();
            foreach (var file in files)
            {
                writer.WriteStartObject();
                writer.WriteString("path", file.Path);
                writer.WriteNumber("bytes", file.Bytes);
                writer.WriteString("sha256", file.Sha256);
                writer.WriteString("download_url", file.DownloadUri.AbsoluteUri);
                writer.WriteEndObject();
            }
            writer.WriteEndArray();
            writer.WriteEndObject();
        }
        return buffer.ToArray();
    }

    private static IReadOnlyList<ReleaseFileDescriptor>? ParseFiles(JsonElement filesElement)
    {
        if (filesElement.GetArrayLength() != RequiredPaths.Length)
        {
            return null;
        }
        var files = new List<ReleaseFileDescriptor>(RequiredPaths.Length);
        var index = 0;
        foreach (var element in filesElement.EnumerateArray())
        {
            if (element.ValueKind != JsonValueKind.Object ||
                !HasExactProperties(element, FileProperties) ||
                !element.TryGetProperty("path", out var pathElement) ||
                pathElement.ValueKind != JsonValueKind.String ||
                !element.TryGetProperty("bytes", out var bytesElement) ||
                !bytesElement.TryGetInt64(out var bytes) ||
                !element.TryGetProperty("sha256", out var hashElement) ||
                hashElement.ValueKind != JsonValueKind.String ||
                !element.TryGetProperty("download_url", out var urlElement) ||
                urlElement.ValueKind != JsonValueKind.String)
            {
                return null;
            }

            var path = pathElement.GetString() ?? string.Empty;
            var hash = hashElement.GetString() ?? string.Empty;
            var url = urlElement.GetString() ?? string.Empty;
            if (!string.Equals(path, RequiredPaths[index], StringComparison.Ordinal) ||
                bytes is <= 0 or > MaximumPayloadBytes ||
                !IsCanonicalSha256(hash) ||
                !IsSafeDownloadUri(url, out var downloadUri))
            {
                return null;
            }
            files.Add(new ReleaseFileDescriptor(path, bytes, hash, downloadUri));
            index++;
        }
        return files.AsReadOnly();
    }

    private static bool HasExactProperties(JsonElement element, HashSet<string> expected)
    {
        var actual = new HashSet<string>(StringComparer.Ordinal);
        foreach (var property in element.EnumerateObject())
        {
            if (!actual.Add(property.Name))
            {
                return false;
            }
        }
        return actual.SetEquals(expected);
    }

    private static bool IsCanonicalVersion(string value) =>
        value.Length is > 0 and <= 32 &&
        Version.TryParse(value, out var parsed) &&
        parsed.Major >= 0 &&
        string.Equals(parsed.ToString(), value, StringComparison.Ordinal);

    private static bool IsCanonicalSha256(string value) =>
        value.Length == 64 &&
        value.All(character => char.IsDigit(character) || character is >= 'A' and <= 'F');

    private static bool IsSafeDownloadUri(string value, out Uri uri)
    {
        if (value.Length is 0 or > 2048 ||
            !Uri.TryCreate(value, UriKind.Absolute, out var parsed) ||
            !string.Equals(parsed.Scheme, Uri.UriSchemeHttps, StringComparison.OrdinalIgnoreCase) ||
            !string.IsNullOrEmpty(parsed.UserInfo) ||
            !string.IsNullOrEmpty(parsed.Fragment))
        {
            uri = null!;
            return false;
        }
        uri = parsed;
        return true;
    }

    private static byte[] DecodeBase64Url(string value)
    {
        var normalized = value.Trim();
        if (normalized.Length == 0 ||
            normalized.Any(character =>
                !(char.IsLetterOrDigit(character) || character is '-' or '_' or '=')))
        {
            throw new FormatException("release_base64url_invalid");
        }
        var firstPadding = normalized.IndexOf('=');
        if (firstPadding >= 0 && normalized[firstPadding..].Any(character => character != '='))
        {
            throw new FormatException("release_base64url_invalid");
        }
        normalized = normalized.TrimEnd('=').Replace('-', '+').Replace('_', '/');
        normalized = normalized.PadRight((normalized.Length + 3) / 4 * 4, '=');
        return Convert.FromBase64String(normalized);
    }
}
