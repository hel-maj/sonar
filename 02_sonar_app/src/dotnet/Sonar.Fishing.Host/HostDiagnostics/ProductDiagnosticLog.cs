using System.IO;
using System.Text;
using System.Text.Json;

namespace Sonar.Fishing.Host.HostDiagnostics;

internal sealed class ProductDiagnosticLog : IDisposable
{
    internal const long DefaultMaximumFileBytes = 1024 * 1024;
    internal const int DefaultRetainedFileCount = 4;
    private const string CurrentFileName = "sonar.log";
    private readonly object sync = new();
    private readonly string logsDirectory;
    private readonly long maximumFileBytes;
    private readonly int retainedFileCount;
    private bool disposed;

    private ProductDiagnosticLog(
        string logsDirectory,
        long maximumFileBytes,
        int retainedFileCount)
    {
        this.logsDirectory = logsDirectory;
        this.maximumFileBytes = maximumFileBytes;
        this.retainedFileCount = retainedFileCount;
    }

    internal static ProductDiagnosticLog Open(
        string applicationDirectory,
        long maximumFileBytes = DefaultMaximumFileBytes,
        int retainedFileCount = DefaultRetainedFileCount)
    {
        if (string.IsNullOrWhiteSpace(applicationDirectory) ||
            !Path.IsPathFullyQualified(applicationDirectory) ||
            maximumFileBytes < 256 ||
            retainedFileCount is < 1 or > 16)
        {
            throw new ArgumentException("product_diagnostic_configuration_invalid");
        }

        var root = Path.GetFullPath(applicationDirectory).TrimEnd(
            Path.DirectorySeparatorChar,
            Path.AltDirectorySeparatorChar);
        if (!Directory.Exists(root) ||
            string.Equals(
                root,
                Path.GetPathRoot(root)?.TrimEnd(Path.DirectorySeparatorChar),
                StringComparison.OrdinalIgnoreCase) ||
            (new DirectoryInfo(root).Attributes & FileAttributes.ReparsePoint) != 0)
        {
            throw new InvalidOperationException("product_diagnostic_root_unsafe");
        }

        var logs = Path.Combine(root, "logs");
        Directory.CreateDirectory(logs);
        if ((new DirectoryInfo(logs).Attributes & FileAttributes.ReparsePoint) != 0)
        {
            throw new InvalidOperationException("product_diagnostic_logs_reparse_point");
        }
        return new ProductDiagnosticLog(logs, maximumFileBytes, retainedFileCount);
    }

    internal void Append(ProductDiagnosticEntry entry)
    {
        ArgumentNullException.ThrowIfNull(entry);
        Validate(entry);
        var line = Serialize(entry);
        lock (sync)
        {
            ObjectDisposedException.ThrowIf(disposed, this);
            var current = Path.Combine(logsDirectory, CurrentFileName);
            var existingBytes = File.Exists(current) ? new FileInfo(current).Length : 0;
            if (existingBytes > 0 && existingBytes + line.Length > maximumFileBytes)
            {
                Rotate();
            }

            using var stream = new FileStream(
                current,
                FileMode.Append,
                FileAccess.Write,
                FileShare.Read,
                bufferSize: 4096,
                FileOptions.WriteThrough);
            stream.Write(line);
            stream.Flush(flushToDisk: true);
        }
    }

    internal void Clear()
    {
        lock (sync)
        {
            ObjectDisposedException.ThrowIf(disposed, this);
            foreach (var path in ExactProductLogPaths())
            {
                File.Delete(path);
            }
        }
    }

    public void Dispose()
    {
        lock (sync)
        {
            disposed = true;
        }
    }

    private static void Validate(ProductDiagnosticEntry entry)
    {
        if (entry.OccurredAt == default ||
            string.IsNullOrWhiteSpace(entry.EventId) ||
            entry.EventId.Length > 96 ||
            entry.EventId.Any(character =>
                !(char.IsAsciiLetterOrDigit(character) || character is '.' or '-' or '_')) ||
            string.IsNullOrWhiteSpace(entry.Message))
        {
            throw new ArgumentException("product_diagnostic_entry_invalid", nameof(entry));
        }
    }

    private static byte[] Serialize(ProductDiagnosticEntry entry)
    {
        var payload = JsonSerializer.SerializeToUtf8Bytes(new
        {
            at = entry.OccurredAt.ToUniversalTime().ToString("O"),
            level = entry.Level.ToString().ToLowerInvariant(),
            event_id = entry.EventId,
            message = ProductDiagnosticRedactor.Redact(entry.Message),
        });
        var line = new byte[payload.Length + 1];
        payload.CopyTo(line, 0);
        line[^1] = (byte)'\n';
        return line;
    }

    private void Rotate()
    {
        var oldest = LogPath(retainedFileCount - 1);
        if (File.Exists(oldest))
        {
            File.Delete(oldest);
        }
        for (var index = retainedFileCount - 2; index >= 0; index--)
        {
            var source = LogPath(index);
            if (File.Exists(source))
            {
                File.Move(source, LogPath(index + 1));
            }
        }
    }

    private string[] ExactProductLogPaths() =>
        Enumerable.Range(0, retainedFileCount)
            .Select(LogPath)
            .Where(File.Exists)
            .ToArray();

    private string LogPath(int index) => Path.Combine(
        logsDirectory,
        index == 0 ? CurrentFileName : $"sonar.{index}.log");
}
