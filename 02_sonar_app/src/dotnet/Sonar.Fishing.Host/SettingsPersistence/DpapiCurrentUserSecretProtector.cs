using System.ComponentModel;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Security.Cryptography;
using System.Text;

namespace Sonar.Fishing.Host.SettingsPersistence;

[SupportedOSPlatform("windows")]
public sealed class DpapiCurrentUserSecretProtector : ISecretProtector
{
    private const int CryptprotectUiForbidden = 0x1;
    private static readonly byte[] Entropy = SHA256.HashData(
        Encoding.UTF8.GetBytes("Sonar.Fishing.state.dat.v1"));

    public byte[] Protect(ReadOnlySpan<byte> plaintext) => Transform(
        plaintext,
        protect: true);

    public byte[] Unprotect(ReadOnlySpan<byte> protectedData) => Transform(
        protectedData,
        protect: false);

    private static byte[] Transform(ReadOnlySpan<byte> value, bool protect)
    {
        var input = DataBlob.Create(value);
        var entropy = DataBlob.Create(Entropy);
        try
        {
            DataBlob output;
            var success = protect
                ? CryptProtectData(
                    ref input,
                    null,
                    ref entropy,
                    IntPtr.Zero,
                    IntPtr.Zero,
                    CryptprotectUiForbidden,
                    out output)
                : CryptUnprotectData(
                    ref input,
                    IntPtr.Zero,
                    ref entropy,
                    IntPtr.Zero,
                    IntPtr.Zero,
                    CryptprotectUiForbidden,
                    out output);
            if (!success)
            {
                throw new Win32Exception(Marshal.GetLastWin32Error());
            }
            try
            {
                var result = new byte[output.Length];
                if (result.Length != 0)
                {
                    Marshal.Copy(output.Data, result, 0, result.Length);
                }
                return result;
            }
            finally
            {
                if (output.Data != IntPtr.Zero)
                {
                    LocalFree(output.Data);
                }
            }
        }
        finally
        {
            input.Dispose();
            entropy.Dispose();
        }
    }

    [StructLayout(LayoutKind.Sequential)]
    private struct DataBlob
    {
        public int Length;
        public IntPtr Data;

        public static DataBlob Create(ReadOnlySpan<byte> source)
        {
            var result = new DataBlob
            {
                Length = source.Length,
                Data = source.Length == 0 ? IntPtr.Zero : Marshal.AllocHGlobal(source.Length),
            };
            if (source.Length != 0)
            {
                Marshal.Copy(source.ToArray(), 0, result.Data, source.Length);
            }
            return result;
        }

        public void Dispose()
        {
            if (Data != IntPtr.Zero)
            {
                Marshal.FreeHGlobal(Data);
                Data = IntPtr.Zero;
            }
            Length = 0;
        }
    }

    [DllImport("Crypt32.dll", SetLastError = true, CharSet = CharSet.Unicode)]
    [return: MarshalAs(UnmanagedType.Bool)]
    private static extern bool CryptProtectData(
        ref DataBlob dataIn,
        string? description,
        ref DataBlob optionalEntropy,
        IntPtr reserved,
        IntPtr promptStruct,
        int flags,
        out DataBlob dataOut);

    [DllImport("Crypt32.dll", SetLastError = true, CharSet = CharSet.Unicode)]
    [return: MarshalAs(UnmanagedType.Bool)]
    private static extern bool CryptUnprotectData(
        ref DataBlob dataIn,
        IntPtr description,
        ref DataBlob optionalEntropy,
        IntPtr reserved,
        IntPtr promptStruct,
        int flags,
        out DataBlob dataOut);

    [DllImport("Kernel32.dll")]
    private static extern IntPtr LocalFree(IntPtr memory);
}
