using System.IO;

namespace Sonar.Fishing.Host.UpdateRuntime;

internal static class ReleaseInstallLayout
{
    internal static readonly string[] ReleaseFiles =
        ["Sonar.Engine.exe", "Sonar.exe", "bundle-manifest.json"];

    internal static string ValidateSteadyState(
        string installRoot,
        params string[] allowedTransactionDirectories)
    {
        var root = ValidateRoot(installRoot);
        var allowedTransactionRoots = allowedTransactionDirectories
            .Select(Path.GetFullPath)
            .Select(path => path.TrimEnd(Path.DirectorySeparatorChar))
            .ToArray();
        foreach (var file in ReleaseFiles)
        {
            var payload = Path.Combine(root, file);
            if (!File.Exists(payload))
            {
                throw new InvalidOperationException("release_install_payload_missing");
            }
            ValidateNoReparseFile(payload);
        }

        foreach (var directory in Directory.EnumerateDirectories(
                     root,
                     "*",
                     SearchOption.TopDirectoryOnly))
        {
            var fullPath = Path.GetFullPath(directory).TrimEnd(Path.DirectorySeparatorChar);
            if (allowedTransactionRoots.Contains(fullPath, StringComparer.OrdinalIgnoreCase))
            {
                ValidateNoReparseDirectories(fullPath);
                continue;
            }
            var name = Path.GetFileName(fullPath);
            if (name is not ("config" or "logs"))
            {
                throw new InvalidOperationException("release_install_allowlist_invalid");
            }
            ValidateNoReparseDirectories(fullPath);
        }

        ValidateRuntimeDirectory(root, "config", path =>
            string.Equals(path, "state.dat", StringComparison.Ordinal));
        ValidateRuntimeDirectory(root, "logs", path =>
            string.Equals(Path.GetExtension(path), ".log", StringComparison.Ordinal));

        foreach (var path in Directory.EnumerateFiles(root, "*", SearchOption.AllDirectories))
        {
            var fullPath = Path.GetFullPath(path);
            ValidateNoReparseFile(fullPath);
            if (allowedTransactionRoots.Any(transactionRoot =>
                    fullPath.StartsWith(
                        transactionRoot + Path.DirectorySeparatorChar,
                        StringComparison.OrdinalIgnoreCase)))
            {
                continue;
            }
            var relative = NormalizeRelative(root, path);
            if (ReleaseFiles.Contains(relative, StringComparer.Ordinal) ||
                string.Equals(relative, "config/state.dat", StringComparison.Ordinal) ||
                relative.StartsWith("logs/", StringComparison.Ordinal))
            {
                continue;
            }
            throw new InvalidOperationException("release_install_allowlist_invalid");
        }
        return root;
    }

    internal static string ValidateTransactionDirectory(
        string installRoot,
        string transactionDirectory,
        string prefix)
    {
        var root = ValidateRoot(installRoot);
        var transaction = Path.GetFullPath(transactionDirectory);
        var relative = Path.GetRelativePath(root, transaction);
        if (Path.IsPathFullyQualified(relative) ||
            relative.StartsWith("..", StringComparison.Ordinal) ||
            relative.Contains(Path.DirectorySeparatorChar) ||
            relative.Contains(Path.AltDirectorySeparatorChar) ||
            !relative.StartsWith(prefix, StringComparison.Ordinal) ||
            relative.Length != prefix.Length + 32 ||
            relative[prefix.Length..].Any(character => !Uri.IsHexDigit(character)))
        {
            throw new InvalidOperationException("release_transaction_scope_invalid");
        }
        if (Directory.Exists(transaction) &&
            (new DirectoryInfo(transaction).Attributes & FileAttributes.ReparsePoint) != 0)
        {
            throw new InvalidOperationException("release_transaction_reparse_point");
        }
        return transaction;
    }

    internal static void ValidatePayloadDirectory(string directory)
    {
        if (Directory.EnumerateDirectories(directory, "*", SearchOption.TopDirectoryOnly).Any())
        {
            throw new InvalidOperationException("release_staging_allowlist_invalid");
        }
        var files = Directory.EnumerateFiles(directory, "*", SearchOption.AllDirectories)
            .Select(path =>
            {
                ValidateNoReparseFile(path);
                return NormalizeRelative(directory, path);
            })
            .OrderBy(path => path, StringComparer.Ordinal)
            .ToArray();
        var expected = ReleaseFiles.OrderBy(path => path, StringComparer.Ordinal).ToArray();
        if (!files.SequenceEqual(expected, StringComparer.Ordinal))
        {
            throw new InvalidOperationException("release_staging_allowlist_invalid");
        }
    }

    internal static void DeleteTransactionDirectory(
        string installRoot,
        string transactionDirectory,
        string prefix)
    {
        var transaction = ValidateTransactionDirectory(installRoot, transactionDirectory, prefix);
        if (Directory.Exists(transaction))
        {
            Directory.Delete(transaction, recursive: true);
        }
    }

    internal static string NormalizeRelative(string root, string path) =>
        Path.GetRelativePath(root, path).Replace(Path.DirectorySeparatorChar, '/');

    private static void ValidateNoReparseDirectories(string directory)
    {
        var pending = new Stack<string>();
        pending.Push(directory);
        while (pending.Count > 0)
        {
            var current = pending.Pop();
            if ((new DirectoryInfo(current).Attributes & FileAttributes.ReparsePoint) != 0)
            {
                throw new InvalidOperationException("release_install_reparse_point");
            }
            foreach (var child in Directory.EnumerateDirectories(
                         current,
                         "*",
                         SearchOption.TopDirectoryOnly))
            {
                pending.Push(child);
            }
        }
    }

    private static void ValidateRuntimeDirectory(
        string root,
        string name,
        Func<string, bool> acceptsFileName)
    {
        var directory = Path.Combine(root, name);
        if (!Directory.Exists(directory))
        {
            return;
        }
        if (Directory.EnumerateDirectories(directory, "*", SearchOption.TopDirectoryOnly).Any())
        {
            throw new InvalidOperationException("release_install_allowlist_invalid");
        }
        foreach (var path in Directory.EnumerateFiles(directory, "*", SearchOption.TopDirectoryOnly))
        {
            ValidateNoReparseFile(path);
            if (!acceptsFileName(Path.GetFileName(path)))
            {
                throw new InvalidOperationException("release_install_allowlist_invalid");
            }
        }
    }

    private static void ValidateNoReparseFile(string path)
    {
        if ((File.GetAttributes(path) & FileAttributes.ReparsePoint) != 0)
        {
            throw new InvalidOperationException("release_install_reparse_point");
        }
    }

    internal static string ValidateRoot(string installRoot)
    {
        if (string.IsNullOrWhiteSpace(installRoot) || !Path.IsPathFullyQualified(installRoot))
        {
            throw new InvalidOperationException("release_install_root_invalid");
        }
        var root = Path.GetFullPath(installRoot).TrimEnd(
            Path.DirectorySeparatorChar,
            Path.AltDirectorySeparatorChar);
        if (string.IsNullOrEmpty(root) ||
            string.Equals(root, Path.GetPathRoot(root)?.TrimEnd(Path.DirectorySeparatorChar),
                StringComparison.OrdinalIgnoreCase) ||
            !Directory.Exists(root) ||
            (new DirectoryInfo(root).Attributes & FileAttributes.ReparsePoint) != 0 ||
            Directory.Exists(Path.Combine(root, ".git")) ||
            (Directory.Exists(Path.Combine(root, "src")) &&
             Directory.Exists(Path.Combine(root, "tests"))))
        {
            throw new InvalidOperationException("release_install_root_unsafe");
        }
        return root;
    }
}
