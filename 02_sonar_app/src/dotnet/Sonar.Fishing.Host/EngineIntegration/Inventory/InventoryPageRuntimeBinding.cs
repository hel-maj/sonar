using Sonar.Fishing.Host.InventoryPage;

namespace Sonar.Fishing.Host.EngineIntegration.Inventory;

internal sealed class InventoryPageRuntimeBinding : IDisposable
{
    private readonly IFishingInventorySnapshotSource source;
    private readonly InventoryPageViewModel target;
    private readonly SynchronizationContext? uiContext;
    private int disposed;

    internal InventoryPageRuntimeBinding(
        IFishingInventorySnapshotSource source,
        InventoryPageViewModel target,
        SynchronizationContext? uiContext = null)
    {
        this.source = source ?? throw new ArgumentNullException(nameof(source));
        this.target = target ?? throw new ArgumentNullException(nameof(target));
        this.uiContext = uiContext ?? SynchronizationContext.Current;
        source.InventorySnapshotReceived += OnInventorySnapshotReceived;
    }

    public void Dispose()
    {
        if (Interlocked.Exchange(ref disposed, 1) != 0)
        {
            return;
        }

        source.InventorySnapshotReceived -= OnInventorySnapshotReceived;
        target.Dispose();
    }

    private void OnInventorySnapshotReceived(FishingInventorySnapshotReceipt receipt)
    {
        if (Volatile.Read(ref disposed) != 0)
        {
            return;
        }

        void Apply()
        {
            if (Volatile.Read(ref disposed) == 0)
            {
                target.ApplyEngineSnapshot(receipt.Generation, receipt.Snapshot);
            }
        }

        if (uiContext is null || ReferenceEquals(SynchronizationContext.Current, uiContext))
        {
            Apply();
        }
        else
        {
            uiContext.Post(static state => ((Action)state!).Invoke(), (Action)Apply);
        }
    }
}
