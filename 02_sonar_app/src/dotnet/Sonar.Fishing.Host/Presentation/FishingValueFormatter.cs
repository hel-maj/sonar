using System.Globalization;
using Sonar.Fishing.Host.FishingSessionState;

namespace Sonar.Fishing.Host.Presentation;

public static class FishingValueFormatter
{
    public static string Duration(double seconds)
    {
        var totalMinutes = Math.Max(0L, checked((long)Math.Floor(seconds / 60d)));
        var hours = Math.DivRem(totalMinutes, 60L, out var minutes);
        return hours > 0
            ? $"{Invariant(hours)} ч {Invariant(minutes)} мин"
            : $"{Invariant(minutes)} мин";
    }

    public static string Weight(double kilograms) =>
        Math.Abs(kilograms - Math.Round(kilograms)) < 0.05d
            ? $"{kilograms.ToString("0", CultureInfo.InvariantCulture)} кг"
            : $"{kilograms.ToString("0.0", CultureInfo.InvariantCulture)} кг";

    public static string CatchSummary(int count, double kilograms) =>
        $"{Invariant(count)} шт · {Weight(kilograms)}";

    public static string Money(double value) =>
        Math.Round(value)
            .ToString("#,0", CultureInfo.InvariantCulture)
            .Replace(",", " ", StringComparison.Ordinal) + " $";

    public static string MoneyRange(double minValue, double maxValue) =>
        Math.Abs(minValue - maxValue) < 0.5d
            ? Money(maxValue)
            : $"от {Money(minValue)} до {Money(maxValue)}";

    public static string BasePrice(FishingPriceSnapshot? price)
    {
        if (price is null)
        {
            return string.Empty;
        }
        return $"{PriceRange(price.PerItemMin, price.PerItemMax)} $/шт · " +
            $"{PriceRange(price.PerThousandMin, price.PerThousandMax)} $/1000";
    }

    public static string OptionalPrice(double? price) => price?.ToString(
        "G",
        CultureInfo.InvariantCulture) ?? string.Empty;

    private static string PriceRange(double minValue, double maxValue)
    {
        var left = PriceValue(minValue);
        var right = PriceValue(maxValue);
        return left == right ? left : $"{left}-{right}";
    }

    private static string PriceValue(double value) =>
        Math.Abs(value - Math.Round(value)) < 0.005d
            ? Invariant(checked((long)Math.Round(value)))
            : value.ToString("0.##", CultureInfo.InvariantCulture);

    private static string Invariant(long value) => value.ToString(
        CultureInfo.InvariantCulture);
}
