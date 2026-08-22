using System.Collections.ObjectModel;
using System.IO;
using System.Text.Json;

namespace Sonar.Fishing.Host.ProductCatalog;

public sealed record FishingFishPrice(
    double PerItemMin,
    double PerItemMax,
    double Per1000Min,
    double Per1000Max);

public sealed record FishingFishDefinition(
    string Id,
    string DisplayName,
    string ImageResourceUri,
    FishingFishPrice? Price);

public static class FishingFishCatalog
{
    private const string ResourceName =
        "Sonar.Fishing.Host.ProductCatalog.fish-catalog.json";
    private static readonly Lazy<IReadOnlyList<FishingFishDefinition>> Catalog = new(Load);

    public static IReadOnlyList<FishingFishDefinition> All => Catalog.Value;

    public static IReadOnlyList<string> AllIds { get; } = new ReadOnlyCollection<string>(
        All.Select(fish => fish.Id).Order(StringComparer.Ordinal).ToArray());

    private static IReadOnlyList<FishingFishDefinition> Load()
    {
        using var stream = typeof(FishingFishCatalog).Assembly.GetManifestResourceStream(ResourceName)
            ?? throw new InvalidDataException("fish_catalog_resource_missing");
        var document = JsonSerializer.Deserialize<CatalogDocument>(stream, new JsonSerializerOptions
        {
            PropertyNamingPolicy = JsonNamingPolicy.CamelCase,
            PropertyNameCaseInsensitive = false,
            UnmappedMemberHandling = System.Text.Json.Serialization.JsonUnmappedMemberHandling.Disallow,
        }) ?? throw new InvalidDataException("fish_catalog_invalid");
        if (document.SchemaVersion != 1 ||
            document.CatalogId != "sonar-fishing-fish" ||
            document.Fishes is not { Count: 31 })
        {
            throw new InvalidDataException("fish_catalog_header_invalid");
        }

        var definitions = new List<FishingFishDefinition>(document.Fishes.Count);
        var ids = new HashSet<string>(StringComparer.Ordinal);
        var displayNames = new HashSet<string>(StringComparer.Ordinal);
        foreach (var source in document.Fishes)
        {
            if (string.IsNullOrWhiteSpace(source.Id) ||
                source.Id.Length > 64 ||
                source.Id.Any(character =>
                    character is not (>= 'a' and <= 'z') &&
                    character is not (>= '0' and <= '9') &&
                    character != '_') ||
                !ids.Add(source.Id) ||
                string.IsNullOrWhiteSpace(source.DisplayName) ||
                source.DisplayName.Length > 128 ||
                !displayNames.Add(source.DisplayName))
            {
                throw new InvalidDataException("fish_catalog_entry_invalid");
            }
            var price = source.Price is null
                ? null
                : ValidatePrice(source.Price);
            definitions.Add(new FishingFishDefinition(
                source.Id,
                source.DisplayName,
                $"/Sonar.Fishing.Host;component/Assets/Fish/{source.Id}.png",
                price));
        }
        return new ReadOnlyCollection<FishingFishDefinition>(
            definitions.OrderBy(fish => fish.DisplayName, StringComparer.Ordinal).ToArray());
    }

    private static FishingFishPrice ValidatePrice(CatalogPrice source)
    {
        if (!double.IsFinite(source.PerItemMin) ||
            !double.IsFinite(source.PerItemMax) ||
            !double.IsFinite(source.Per1000Min) ||
            !double.IsFinite(source.Per1000Max) ||
            source.PerItemMin <= 0 ||
            source.PerItemMin > source.PerItemMax ||
            source.Per1000Min <= 0 ||
            source.Per1000Min > source.Per1000Max)
        {
            throw new InvalidDataException("fish_catalog_price_invalid");
        }
        return new FishingFishPrice(
            source.PerItemMin,
            source.PerItemMax,
            source.Per1000Min,
            source.Per1000Max);
    }

    private sealed record CatalogDocument(
        int SchemaVersion,
        string CatalogId,
        IReadOnlyList<CatalogFish> Fishes);

    private sealed record CatalogFish(
        string Id,
        string DisplayName,
        CatalogPrice? Price);

    private sealed record CatalogPrice(
        double PerItemMin,
        double PerItemMax,
        double Per1000Min,
        double Per1000Max);
}
