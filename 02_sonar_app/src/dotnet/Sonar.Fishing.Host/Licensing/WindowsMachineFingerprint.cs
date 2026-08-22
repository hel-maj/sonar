using System.IO;
using System.Runtime.InteropServices;
using System.Security;
using System.Security.Cryptography;
using System.Text;
using Microsoft.Win32;

namespace Sonar.Fishing.Host.Licensing;

internal static class WindowsMachineFingerprint
{
    internal static string Current()
    {
        var architecture = RuntimeInformation.OSArchitecture switch
        {
            Architecture.X64 => "AMD64",
            Architecture.X86 => "x86",
            Architecture.Arm64 => "ARM64",
            Architecture.Arm => "ARM",
            _ => RuntimeInformation.OSArchitecture.ToString(),
        };
        return Compute(
            OperatingSystem.IsWindows() ? "Windows" : string.Empty,
            architecture,
            ReadMachineGuid(),
            ReadSystemVolumeSerial(),
            Environment.MachineName);
    }

    internal static string Compute(
        string platform,
        string architecture,
        string machineGuid,
        string volumeSerial,
        string fallbackHost)
    {
        var raw = string.Join(
            '|',
            new[] { platform, architecture, machineGuid, volumeSerial }
                .Where(value => !string.IsNullOrEmpty(value)));
        if (raw.Length == 0)
        {
            raw = fallbackHost;
        }
        if (string.IsNullOrWhiteSpace(raw) || raw.Length > 1024)
        {
            throw new InvalidOperationException("license_machine_identity_unavailable");
        }
        return Convert.ToHexString(SHA256.HashData(Encoding.UTF8.GetBytes(raw))).ToLowerInvariant();
    }

    private static string ReadMachineGuid()
    {
        if (!OperatingSystem.IsWindows())
        {
            return string.Empty;
        }
        try
        {
            using var key = Registry.LocalMachine.OpenSubKey(
                @"SOFTWARE\Microsoft\Cryptography",
                writable: false);
            return key?.GetValue("MachineGuid") as string ?? string.Empty;
        }
        catch (Exception exception) when (exception is SecurityException or UnauthorizedAccessException)
        {
            return string.Empty;
        }
    }

    private static string ReadSystemVolumeSerial()
    {
        if (!OperatingSystem.IsWindows())
        {
            return string.Empty;
        }
        var root = Path.GetPathRoot(Environment.SystemDirectory);
        if (string.IsNullOrEmpty(root) ||
            !GetVolumeInformation(
                root,
                null,
                0,
                out var serial,
                out _,
                out _,
                null,
                0) ||
            serial == 0)
        {
            return string.Empty;
        }
        return serial.ToString(System.Globalization.CultureInfo.InvariantCulture);
    }

    [DllImport("kernel32.dll", CharSet = CharSet.Unicode, SetLastError = true)]
    [return: MarshalAs(UnmanagedType.Bool)]
    private static extern bool GetVolumeInformation(
        string rootPathName,
        StringBuilder? volumeNameBuffer,
        int volumeNameSize,
        out uint volumeSerialNumber,
        out uint maximumComponentLength,
        out uint fileSystemFlags,
        StringBuilder? fileSystemNameBuffer,
        int fileSystemNameSize);
}
