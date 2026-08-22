namespace Sonar.Fishing.Host.Tests;

internal static class TestAssert
{
    public static void True(bool condition, string message)
    {
        if (!condition)
        {
            throw new InvalidOperationException(message);
        }
    }

    public static void Equal<T>(T expected, T actual, string message)
        where T : notnull
    {
        if (!EqualityComparer<T>.Default.Equals(expected, actual))
        {
            throw new InvalidOperationException(
                $"{message}. Expected: {expected}; actual: {actual}.");
        }
    }

    public static T IsType<T>(object? value, string message)
        where T : class
    {
        if (value is not T typed)
        {
            throw new InvalidOperationException(message);
        }
        return typed;
    }

    public static TException Throws<TException>(Action action, string message)
        where TException : Exception
    {
        try
        {
            action();
        }
        catch (TException exception)
        {
            return exception;
        }

        throw new InvalidOperationException(message);
    }
}
