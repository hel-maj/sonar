using CommunityToolkit.Mvvm.ComponentModel;
using Sonar.Fishing.Host.ProductCatalog;

namespace Sonar.Fishing.Host.SettingsPage;

public sealed class FishingFishSelectionViewModel : ObservableObject
{
    private readonly Action<string, bool> changeHandler;
    private bool keep;

    public FishingFishSelectionViewModel(
        FishingFishDefinition definition,
        bool keep,
        Action<string, bool> changeHandler)
    {
        ArgumentNullException.ThrowIfNull(definition);
        ArgumentNullException.ThrowIfNull(changeHandler);
        Definition = definition;
        this.keep = keep;
        this.changeHandler = changeHandler;
    }

    public FishingFishDefinition Definition { get; }

    public string Id => Definition.Id;

    public string DisplayName => Definition.DisplayName;

    public string ImageResourceUri => Definition.ImageResourceUri;

    public string KeepAutomationName => $"Оставлять: {DisplayName}";

    public bool Keep
    {
        get => keep;
        set
        {
            if (!SetProperty(ref keep, value))
            {
                return;
            }
            changeHandler(Id, value);
        }
    }

    internal void ApplyKeep(bool value) => SetProperty(ref keep, value, nameof(Keep));
}
