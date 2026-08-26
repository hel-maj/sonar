using System.Windows.Media;
using Sonar.UI.Wpf.CatalogImages;

namespace Sonar.Fishing.Host.InventoryPage;

internal interface IInventoryImageProvider
{
    Task<ImageSource?> LoadAsync(
        string imageReference,
        CancellationToken cancellationToken);
}

// The product composes the shared loader but does not implement URL admission,
// redirect handling, media validation, decoding, deduplication or caching.
internal sealed class CommonInventoryImageProvider :
    IInventoryImageProvider,
    IDisposable
{
    private readonly CatalogImageSourceLoader loader = new();

    public async Task<ImageSource?> LoadAsync(
        string imageReference,
        CancellationToken cancellationToken)
    {
        var result = await loader.LoadAsync(
            new CatalogImageRequest(imageReference),
            cancellationToken);
        return result.IsSuccess ? result.Source : null;
    }

    public void Dispose() => loader.Dispose();
}
