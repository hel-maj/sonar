namespace Sonar.Fishing.Host.InventoryPage;

public static class InventoryGridContract
{
    public const uint Rows = 17;
    public const uint Columns = 6;
    public const uint Capacity = Rows * Columns;
}

public enum InventoryConditionKind
{
    None,
    Wear,
    Food,
}

public sealed record InventoryItemState(
    string RuntimeId,
    ulong CatalogItemId,
    string Name,
    string Category,
    uint Column,
    uint Row,
    uint ColumnSpan,
    uint RowSpan,
    uint Count,
    uint? MaximumCount,
    double? UnitWeight,
    double? TotalWeight,
    double? ConditionPercent,
    double? FreshnessPercent,
    InventoryConditionKind ConditionKind,
    string Durability,
    string Description,
    string ImageReference,
    IReadOnlyList<string> DetailLines);

public sealed record InventoryProductState(
    bool Ready,
    string Reason,
    ulong Revision,
    ulong ObservedAtMilliseconds,
    bool OpenKnown,
    bool Open,
    double? CurrentWeight,
    double? MaximumWeight,
    IReadOnlyList<InventoryItemState> Items)
{
    public uint GridRows { get; init; } = InventoryGridContract.Rows;

    public uint GridColumns { get; init; } = InventoryGridContract.Columns;

    public static InventoryProductState Unknown { get; } = new(
        Ready: false,
        Reason: "inventory_snapshot_missing",
        Revision: 0,
        ObservedAtMilliseconds: 0,
        OpenKnown: false,
        Open: false,
        CurrentWeight: null,
        MaximumWeight: null,
        Items: Array.Empty<InventoryItemState>());
}
