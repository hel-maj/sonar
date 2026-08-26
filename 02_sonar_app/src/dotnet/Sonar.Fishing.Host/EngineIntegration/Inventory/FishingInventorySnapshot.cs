using System.Globalization;
using System.IO;
using Sonar.Fishing.Host.InventoryPage;
using Sonar.Inventory.Ipc.Contracts;
using Sonar.Inventory.Ipc.Contracts.V1;

namespace Sonar.Fishing.Host.EngineIntegration.Inventory;

internal sealed record FishingInventorySnapshotFrame(
    string SessionId,
    ulong Sequence,
    long CapturedAtUnixMs,
    InventoryProductState Snapshot);

internal sealed record FishingInventorySnapshotReceipt(
    ulong Generation,
    ulong Sequence,
    long CapturedAtUnixMs,
    InventoryProductState Snapshot);

internal interface IEngineInventorySnapshotFrameSource
{
    event Action<FishingInventorySnapshotFrame>? InventorySnapshotReceived;
}

internal interface IFishingInventorySnapshotSource
{
    event Action<FishingInventorySnapshotReceipt>? InventorySnapshotReceived;
}

internal static class FishingInventoryWireMapper
{
    internal static InventoryProductState Map(InventoryStateSnapshot wire)
    {
        ArgumentNullException.ThrowIfNull(wire);
        if (!InventorySnapshotValidator.TryValidate(wire, out var reason))
        {
            throw new InvalidDataException(reason);
        }

        if (wire.Availability == InventoryAvailability.Unavailable)
        {
            return new InventoryProductState(
                Ready: false,
                Reason: wire.Reason,
                Revision: wire.Revision,
                ObservedAtMilliseconds: wire.ObservedAtMs,
                OpenKnown: wire.HasOpen,
                Open: wire.HasOpen && wire.Open,
                CurrentWeight: null,
                MaximumWeight: null,
                Items: Array.Empty<InventoryItemState>())
            {
                GridRows = InventoryGridContract.Rows,
                GridColumns = InventoryGridContract.Columns,
            };
        }

        return new InventoryProductState(
            Ready: true,
            Reason: string.Empty,
            Revision: wire.Revision,
            ObservedAtMilliseconds: wire.ObservedAtMs,
            OpenKnown: wire.HasOpen,
            Open: wire.HasOpen && wire.Open,
            CurrentWeight: wire.HasCurrentWeight ? wire.CurrentWeight : null,
            MaximumWeight: wire.HasMaximumWeight ? wire.MaximumWeight : null,
            Items: wire.Items.Select(MapItem).ToArray())
        {
            GridRows = wire.GridRows,
            GridColumns = wire.GridColumns,
        };
    }

    private static InventoryItemState MapItem(InventoryItemSnapshot item) => new(
        RuntimeId: item.RuntimeId,
        CatalogItemId: item.CatalogItemId,
        Name: item.Name,
        Category: item.Category,
        Column: item.Column,
        Row: item.Row,
        ColumnSpan: item.ColumnSpan,
        RowSpan: item.RowSpan,
        Count: item.Count,
        MaximumCount: item.HasMaximumCount ? item.MaximumCount : null,
        UnitWeight: item.HasUnitWeight ? item.UnitWeight : null,
        TotalWeight: item.HasTotalWeight ? item.TotalWeight : null,
        ConditionPercent: item.HasConditionPercent ? item.ConditionPercent : null,
        FreshnessPercent: item.HasFreshnessPercent ? item.FreshnessPercent : null,
        ConditionKind: item.ConditionKind switch
        {
            Sonar.Inventory.Ipc.Contracts.V1.InventoryConditionKind.Wear =>
                Sonar.Fishing.Host.InventoryPage.InventoryConditionKind.Wear,
            Sonar.Inventory.Ipc.Contracts.V1.InventoryConditionKind.Food =>
                Sonar.Fishing.Host.InventoryPage.InventoryConditionKind.Food,
            _ => Sonar.Fishing.Host.InventoryPage.InventoryConditionKind.None,
        },
        Durability: item.Durability,
        Description: item.Description,
        ImageReference: item.ImageReference,
        DetailLines: BuildDetailLines(item));

    private static IReadOnlyList<string> BuildDetailLines(InventoryItemSnapshot item)
    {
        var lines = new List<string>(item.Stats.Count + item.Buffs.Count * 2);
        foreach (var stat in item.Stats)
        {
            var value = stat.HasNumericValue
                ? stat.NumericValue.ToString("0.##", CultureInfo.CurrentCulture)
                : stat.TextValue;
            lines.Add($"{stat.Name}: {value}");
        }

        foreach (var buff in item.Buffs)
        {
            lines.Add(string.IsNullOrWhiteSpace(buff.Description)
                ? buff.Name
                : $"{buff.Name}: {buff.Description}");
            lines.AddRange(buff.Modifiers);
            lines.AddRange(buff.Effects.Select(effect =>
                string.IsNullOrWhiteSpace(effect.Description)
                    ? effect.Title
                    : $"{effect.Title}: {effect.Description}"));
        }

        return lines;
    }
}
