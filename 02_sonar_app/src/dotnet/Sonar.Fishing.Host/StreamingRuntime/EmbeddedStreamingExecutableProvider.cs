using System.IO;
using System.Reflection;
using System.Security.Cryptography;

namespace Sonar.Fishing.Host.StreamingRuntime;

internal sealed record EmbeddedStreamingExecutableDescriptor(
    string ResourceName,
    string FileName,
    string Sha256);

/// <summary>
/// Materializes hash-pinned embedded tools for one streaming generation.
/// The resulting lease is transient runtime state, never a release dependency.
/// </summary>
internal sealed class EmbeddedStreamingExecutableProvider : IStreamingExecutableProvider
{
    private readonly Assembly assembly;
    private readonly string rootDirectory;
    private readonly EmbeddedStreamingExecutableDescriptor encoder;
    private readonly EmbeddedStreamingExecutableDescriptor tunnel;

    internal EmbeddedStreamingExecutableProvider(
        Assembly assembly,
        string rootDirectory,
        EmbeddedStreamingExecutableDescriptor encoder,
        EmbeddedStreamingExecutableDescriptor tunnel)
    {
        this.assembly = assembly ?? throw new ArgumentNullException(nameof(assembly));
        this.rootDirectory = Path.GetFullPath(
            string.IsNullOrWhiteSpace(rootDirectory)
                ? throw new ArgumentException("streaming_tool_root_required", nameof(rootDirectory))
                : rootDirectory);
        this.encoder = ValidateDescriptor(encoder, nameof(encoder));
        this.tunnel = ValidateDescriptor(tunnel, nameof(tunnel));
        if (string.Equals(
                this.encoder.FileName,
                this.tunnel.FileName,
                StringComparison.OrdinalIgnoreCase))
        {
            throw new ArgumentException("streaming_tool_names_must_be_distinct");
        }
    }

    public async ValueTask<IStreamingExecutableLease> AcquireAsync(
        CancellationToken cancellationToken)
    {
        cancellationToken.ThrowIfCancellationRequested();
        Directory.CreateDirectory(rootDirectory);
        var sessionDirectory = Path.Combine(
            rootDirectory,
            $"session-{Guid.NewGuid():N}");
        Directory.CreateDirectory(sessionDirectory);

        try
        {
            var encoderPath = await ExtractAsync(
                    encoder,
                    sessionDirectory,
                    cancellationToken)
                .ConfigureAwait(false);
            var tunnelPath = await ExtractAsync(
                    tunnel,
                    sessionDirectory,
                    cancellationToken)
                .ConfigureAwait(false);
            return new EmbeddedStreamingExecutableLease(
                rootDirectory,
                sessionDirectory,
                new StreamingExecutableSet(
                    encoderPath,
                    tunnelPath,
                    StreamingExecutableOrigin.EmbeddedResource));
        }
        catch
        {
            DeleteSessionDirectory(rootDirectory, sessionDirectory);
            throw;
        }
    }

    private async ValueTask<string> ExtractAsync(
        EmbeddedStreamingExecutableDescriptor descriptor,
        string sessionDirectory,
        CancellationToken cancellationToken)
    {
        await using var source = assembly.GetManifestResourceStream(descriptor.ResourceName)
            ?? throw new StreamingRuntimeException("streaming_embedded_tool_missing");
        var destinationPath = Path.Combine(sessionDirectory, descriptor.FileName);
        await using (var destination = new FileStream(
                         destinationPath,
                         FileMode.CreateNew,
                         FileAccess.Write,
                         FileShare.None,
                         bufferSize: 81920,
                         FileOptions.Asynchronous | FileOptions.WriteThrough))
        {
            await source.CopyToAsync(destination, cancellationToken).ConfigureAwait(false);
            await destination.FlushAsync(cancellationToken).ConfigureAwait(false);
        }

        await using var verification = new FileStream(
            destinationPath,
            FileMode.Open,
            FileAccess.Read,
            FileShare.Read,
            bufferSize: 81920,
            FileOptions.Asynchronous | FileOptions.SequentialScan);
        var actualHash = Convert.ToHexString(
            await SHA256.HashDataAsync(verification, cancellationToken).ConfigureAwait(false));
        if (!string.Equals(actualHash, descriptor.Sha256, StringComparison.OrdinalIgnoreCase))
        {
            throw new StreamingRuntimeException("streaming_embedded_tool_hash_mismatch");
        }
        return destinationPath;
    }

    private static EmbeddedStreamingExecutableDescriptor ValidateDescriptor(
        EmbeddedStreamingExecutableDescriptor descriptor,
        string parameterName)
    {
        ArgumentNullException.ThrowIfNull(descriptor, parameterName);
        if (string.IsNullOrWhiteSpace(descriptor.ResourceName) ||
            string.IsNullOrWhiteSpace(descriptor.FileName) ||
            !string.Equals(
                descriptor.FileName,
                Path.GetFileName(descriptor.FileName),
                StringComparison.Ordinal) ||
            !descriptor.FileName.EndsWith(".exe", StringComparison.OrdinalIgnoreCase) ||
            descriptor.Sha256.Length != 64 ||
            descriptor.Sha256.Any(static character => !Uri.IsHexDigit(character)))
        {
            throw new ArgumentException("streaming_embedded_tool_descriptor_invalid", parameterName);
        }
        return descriptor;
    }

    private static void DeleteSessionDirectory(string rootDirectory, string sessionDirectory)
    {
        var relative = Path.GetRelativePath(rootDirectory, sessionDirectory);
        if (relative.StartsWith("..", StringComparison.Ordinal) ||
            Path.IsPathFullyQualified(relative))
        {
            throw new StreamingRuntimeException("streaming_tool_cleanup_scope_invalid");
        }
        if (Directory.Exists(sessionDirectory))
        {
            Directory.Delete(sessionDirectory, recursive: true);
        }
    }

    private sealed class EmbeddedStreamingExecutableLease : IStreamingExecutableLease
    {
        private readonly string rootDirectory;
        private readonly string sessionDirectory;
        private bool disposed;

        internal EmbeddedStreamingExecutableLease(
            string rootDirectory,
            string sessionDirectory,
            StreamingExecutableSet executables)
        {
            this.rootDirectory = rootDirectory;
            this.sessionDirectory = sessionDirectory;
            Executables = executables;
        }

        public StreamingExecutableSet Executables { get; }

        public ValueTask DisposeAsync()
        {
            if (!disposed)
            {
                DeleteSessionDirectory(rootDirectory, sessionDirectory);
                disposed = true;
            }
            return ValueTask.CompletedTask;
        }
    }
}
