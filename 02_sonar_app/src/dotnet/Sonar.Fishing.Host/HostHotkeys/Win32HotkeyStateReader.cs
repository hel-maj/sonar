using System.Runtime.InteropServices;
using System.Windows.Input;
using Sonar.UI.Wpf.Controls;

namespace Sonar.Fishing.Host.HostHotkeys;

internal interface IHotkeyStateReader
{
    bool IsDown(HotkeyGesture gesture);
}

internal sealed class Win32HotkeyStateReader : IHotkeyStateReader
{
    public bool IsDown(HotkeyGesture gesture)
    {
        var virtualKeys = HotkeyVirtualKeyMapper.Map(gesture);
        return virtualKeys.Count > 0 && virtualKeys.All(IsVirtualKeyDown);
    }

    private static bool IsVirtualKeyDown(int virtualKey) =>
        (GetAsyncKeyState(virtualKey) & 0x8000) != 0;

    [DllImport("user32.dll")]
    private static extern short GetAsyncKeyState(int virtualKey);
}

internal static class HotkeyVirtualKeyMapper
{
    internal static IReadOnlyList<int> Map(HotkeyGesture gesture)
    {
        var result = new List<int>(5);
        AddModifier(result, gesture.Modifiers, ModifierKeys.Control, 0x11);
        AddModifier(result, gesture.Modifiers, ModifierKeys.Shift, 0x10);
        AddModifier(result, gesture.Modifiers, ModifierKeys.Alt, 0x12);
        AddModifier(result, gesture.Modifiers, ModifierKeys.Windows, 0x5B);
        var baseKey = KeyInterop.VirtualKeyFromKey(gesture.Key);
        if (baseKey <= 0)
        {
            return Array.Empty<int>();
        }
        result.Add(baseKey);
        return result.AsReadOnly();
    }

    private static void AddModifier(
        ICollection<int> target,
        ModifierKeys actual,
        ModifierKeys expected,
        int virtualKey)
    {
        if (actual.HasFlag(expected))
        {
            target.Add(virtualKey);
        }
    }
}
