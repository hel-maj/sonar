using System.Windows;
using System.Windows.Media;

namespace Sonar.Fishing.Host.Tests;

internal static class WpfTestVisualTree
{
    internal static T FindDescendant<T>(DependencyObject root, string message)
        where T : DependencyObject
    {
        return TryFindDescendant<T>(root) ?? throw new InvalidOperationException(message);
    }

    internal static IReadOnlyList<T> FindDescendants<T>(DependencyObject root)
        where T : DependencyObject
    {
        var matches = new List<T>();
        AddDescendants(root, matches);
        return matches;
    }

    private static T? TryFindDescendant<T>(DependencyObject root)
        where T : DependencyObject
    {
        if (root is T match)
        {
            return match;
        }

        for (var index = 0; index < VisualTreeHelper.GetChildrenCount(root); index++)
        {
            var child = VisualTreeHelper.GetChild(root, index);
            var descendant = TryFindDescendant<T>(child);
            if (descendant is not null)
            {
                return descendant;
            }
        }

        return null;
    }

    private static void AddDescendants<T>(DependencyObject root, ICollection<T> matches)
        where T : DependencyObject
    {
        if (root is T match)
        {
            matches.Add(match);
        }

        for (var index = 0; index < VisualTreeHelper.GetChildrenCount(root); index++)
        {
            AddDescendants(VisualTreeHelper.GetChild(root, index), matches);
        }
    }
}
