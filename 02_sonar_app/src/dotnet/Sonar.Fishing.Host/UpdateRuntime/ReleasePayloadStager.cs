using System.Buffers;
using System.IO;
using System.Security.Cryptography;

namespace Sonar.Fishing.Host.UpdateRuntime;

internal interface IReleasePayloadSource
{
    ValueTask<Stream> OpenReadAsync(
        ReleaseFileDescriptor descriptor,
        CancellationToken cancellationToken);
}

internal sealed class ReleasePayloadStager
{
    internal static readonly TimeSpan MaximumStagingDuration = TimeSpan.FromMinutes(15);
    private readonly IReleasePayloadSource source;

    internal ReleasePayloadStager(IReleasePayloadSource source)
    {
        this.source = source ?? throw new ArgumentNullException(nameof(source));
    }

    internal async ValueTask<StagedProductRelease> StageAsync(
        ProductReleaseManifest manifest,
        string currentVersion,
        long currentGeneration,
        string installRoot,
        CancellationToken cancellationToken)
    {
        ArgumentNullException.ThrowIfNull(manifest);
        if (!manifest.IsNewerThan(currentVersion) ||
            currentGeneration < 0 ||
            manifest.Generation <= currentGeneration)
        {
            throw new InvalidOperationException("release_version_not_newer");
        }

        var root = ReleaseInstallLayout.ValidateSteadyState(installRoot);
        var stagingDirectory = Path.Combine(root, $".update-{Guid.NewGuid():N}");
        ReleaseInstallLayout.ValidateTransactionDirectory(root, stagingDirectory, ".update-");
        Directory.CreateDirectory(stagingDirectory);
        using var deadline = CancellationTokenSource.CreateLinkedTokenSource(cancellationToken);
        deadline.CancelAfter(MaximumStagingDuration);

        try
        {
            foreach (var descriptor in manifest.Files)
            {
                deadline.Token.ThrowIfCancellationRequested();
                await StageFileAsync(stagingDirectory, descriptor, deadline.Token)
                    .ConfigureAwait(false);
            }
            ReleaseInstallLayout.ValidatePayloadDirectory(stagingDirectory);
            return new StagedProductRelease(root, stagingDirectory, manifest);
        }
        catch
        {
            ReleaseInstallLayout.DeleteTransactionDirectory(root, stagingDirectory, ".update-");
            throw;
        }
    }

    private async ValueTask StageFileAsync(
        string stagingDirectory,
        ReleaseFileDescriptor descriptor,
        CancellationToken cancellationToken)
    {
        var destinationPath = Path.Combine(stagingDirectory, descriptor.Path);
        await using var input = await source.OpenReadAsync(descriptor, cancellationToken)
            .ConfigureAwait(false);
        await using var output = new FileStream(
            destinationPath,
            FileMode.CreateNew,
            FileAccess.Write,
            FileShare.None,
            bufferSize: 64 * 1024,
            FileOptions.Asynchronous | FileOptions.WriteThrough);
        using var hash = IncrementalHash.CreateHash(HashAlgorithmName.SHA256);
        var buffer = ArrayPool<byte>.Shared.Rent(64 * 1024);
        long written = 0;
        try
        {
            while (true)
            {
                var read = await input.ReadAsync(buffer.AsMemory(0, buffer.Length), cancellationToken)
                    .ConfigureAwait(false);
                if (read == 0)
                {
                    break;
                }
                written = checked(written + read);
                if (written > descriptor.Bytes)
                {
                    throw new InvalidOperationException("release_payload_size_mismatch");
                }
                hash.AppendData(buffer, 0, read);
                await output.WriteAsync(buffer.AsMemory(0, read), cancellationToken)
                    .ConfigureAwait(false);
            }
            await output.FlushAsync(cancellationToken).ConfigureAwait(false);
        }
        finally
        {
            ArrayPool<byte>.Shared.Return(buffer, clearArray: true);
        }

        var actualHash = Convert.ToHexString(hash.GetHashAndReset());
        if (written != descriptor.Bytes ||
            !string.Equals(actualHash, descriptor.Sha256, StringComparison.Ordinal))
        {
            throw new InvalidOperationException("release_payload_integrity_invalid");
        }
    }
}

internal sealed class StagedProductRelease : IAsyncDisposable
{
    private bool disposed;

    internal StagedProductRelease(
        string installRoot,
        string stagingDirectory,
        ProductReleaseManifest manifest)
    {
        InstallRoot = installRoot;
        StagingDirectory = stagingDirectory;
        Manifest = manifest;
    }

    internal string InstallRoot { get; }
    internal string StagingDirectory { get; }
    internal ProductReleaseManifest Manifest { get; }

    internal void MarkActivated()
    {
        disposed = true;
    }

    public ValueTask DisposeAsync()
    {
        if (!disposed)
        {
            ReleaseInstallLayout.DeleteTransactionDirectory(
                InstallRoot,
                StagingDirectory,
                ".update-");
            disposed = true;
        }
        return ValueTask.CompletedTask;
    }
}
