using Sonar.Fishing.Host.ProductCatalog;

namespace Sonar.Fishing.Host.SettingsPersistence;

public sealed class HostStateCoordinator
{
    private readonly object gate = new();
    private readonly FishingStateStore store;
    private FishingHostState current;

    public HostStateCoordinator(FishingStateStore store, FishingHostState current)
    {
        this.store = store ?? throw new ArgumentNullException(nameof(store));
        this.current = current ?? throw new ArgumentNullException(nameof(current));
        this.current.Validate();
    }

    public event Action<FishingHostState>? StateChanged;

    public FishingHostState Current
    {
        get
        {
            lock (gate)
            {
                return current;
            }
        }
    }

    public void SaveFishing(FishingRuntimeSettings settings)
    {
        ArgumentNullException.ThrowIfNull(settings);
        settings.Validate();
        Commit(existing =>
        {
            if (existing.Fishing.Revision == ulong.MaxValue)
            {
                throw new InvalidOperationException("settings_revision_exhausted");
            }
            if (settings.Revision != existing.Fishing.Revision + 1)
            {
                throw new InvalidOperationException("settings_revision_stale");
            }
            return existing with { Fishing = settings };
        });
    }

    public void SaveTelegram(TelegramHostSettings settings, string botToken)
    {
        ArgumentNullException.ThrowIfNull(settings);
        ArgumentNullException.ThrowIfNull(botToken);
        Commit(existing => existing with
        {
            Telegram = settings,
            Secrets = existing.Secrets with { TelegramBotToken = botToken },
        });
    }

    public void SaveLicense(
        LicenseHostSettings settings,
        string licenseKey,
        string signedLicenseCache)
    {
        ArgumentNullException.ThrowIfNull(settings);
        ArgumentNullException.ThrowIfNull(licenseKey);
        ArgumentNullException.ThrowIfNull(signedLicenseCache);
        if (licenseKey.Length > 256)
        {
            throw new ArgumentException("license_key_invalid", nameof(licenseKey));
        }
        Commit(existing => existing with
        {
            License = settings,
            Secrets = existing.Secrets with
            {
                LicenseKey = licenseKey,
                SignedLicenseCache = signedLicenseCache,
            },
        });
    }

    public void RevokeLicenseAuthority(bool clearSignedCache)
    {
        Commit(existing => existing with
        {
            License = LicenseHostSettings.Default,
            Secrets = existing.Secrets with
            {
                SignedLicenseCache = clearSignedCache
                    ? string.Empty
                    : existing.Secrets.SignedLicenseCache,
            },
        });
    }

    public FishingRuntimeSettings UpdateCustomFishPrice(
        string fishId,
        double? price)
    {
        ArgumentException.ThrowIfNullOrWhiteSpace(fishId);
        if (!FishingFishCatalog.AllIds.Contains(fishId, StringComparer.Ordinal))
        {
            throw new ArgumentException("settings_unknown_fish_id", nameof(fishId));
        }
        if (price is { } value && (!double.IsFinite(value) || value < 0))
        {
            throw new ArgumentOutOfRangeException(nameof(price));
        }

        FishingRuntimeSettings? accepted = null;
        Commit(existing =>
        {
            if (existing.Fishing.Revision == ulong.MaxValue)
            {
                throw new InvalidOperationException("settings_revision_exhausted");
            }
            var prices = new SortedDictionary<string, double>(StringComparer.Ordinal);
            foreach (var entry in existing.Fishing.Selection.CustomFishPrices)
            {
                prices.Add(entry.Key, entry.Value);
            }
            if (price is null or <= 0)
            {
                prices.Remove(fishId);
            }
            else
            {
                prices[fishId] = price.Value;
            }
            var selection = new FishingSelectionPolicy(
                existing.Fishing.Selection.FishKeep,
                existing.Fishing.Selection.GarbageDisposal,
                prices);
            accepted = existing.Fishing with
            {
                Revision = existing.Fishing.Revision + 1,
                Selection = selection,
            };
            return existing with { Fishing = accepted };
        });
        return accepted ?? throw new InvalidOperationException("settings_price_update_missing");
    }

    public FishingRuntimeSettings UpdateStreamSnapshotMode(bool enabled)
    {
        FishingRuntimeSettings? accepted = null;
        Commit(existing =>
        {
            if (existing.Fishing.Revision == ulong.MaxValue)
            {
                throw new InvalidOperationException("settings_revision_exhausted");
            }
            accepted = existing.Fishing with
            {
                Revision = existing.Fishing.Revision + 1,
                Behavior = existing.Fishing.Behavior with
                {
                    StreamSnapshotMode = enabled,
                },
            };
            return existing with { Fishing = accepted };
        });
        return accepted ?? throw new InvalidOperationException("settings_stream_mode_update_missing");
    }

    private void Commit(Func<FishingHostState, FishingHostState> createNext)
    {
        ArgumentNullException.ThrowIfNull(createNext);
        FishingHostState next;
        lock (gate)
        {
            next = createNext(current);
            next.Validate();
            store.Save(next);
            current = next;
        }
        StateChanged?.Invoke(next);
    }
}
