using System.IO;
using Sonar.Fishing.Host.ProductCatalog;
using Sonar.Fishing.Host.SettingsPersistence;
using Sonar.Fishing.Ipc.Contracts.V1;
using Sonar.Platform.Ipc.Contracts.V1;

using HostRuntimeSettings = Sonar.Fishing.Host.SettingsPersistence.FishingRuntimeSettings;
using WireRuntimeSettings = Sonar.Fishing.Ipc.Contracts.V1.FishingRuntimeSettings;

namespace Sonar.Fishing.Host.EngineIntegration.RuntimeSettings;

internal static class OfflineRuntimeSettingsOperation
{
    internal static async Task<ulong> ApplyAsync(
        Stream control,
        EngineSessionIdentity identity,
        string sessionId,
        ulong sequence,
        HostRuntimeSettings settings,
        CancellationToken cancellationToken)
    {
        ArgumentNullException.ThrowIfNull(settings);
        settings.Validate();

        var requestId = $"apply-settings-{Guid.NewGuid():N}";
        var request = OfflineEngineSessionProtocol.CreateEnvelope(
            identity,
            PeerRole.Host,
            MessageKind.Command,
            sessionId,
            sequence,
            requestId: requestId,
            commandId: "apply-runtime-settings",
            status: "pending");
        request.ApplyRuntimeSettingsRequest = new ApplyRuntimeSettingsRequest
        {
            Settings = CreateWireSnapshot(settings),
        };
        await OfflineEngineSessionProtocol.WriteEnvelopeAsync(
            control,
            request,
            cancellationToken).ConfigureAwait(false);

        var reply = await OfflineEngineSessionProtocol.ReadEnvelopeAsync(
            control,
            cancellationToken).ConfigureAwait(false);
        OfflineEngineSessionProtocol.ValidateEngineEnvelope(
            identity,
            reply,
            MessageKind.Reply,
            sessionId,
            expectedCorrelationId: requestId);
        if (reply.PayloadCase != Envelope.PayloadOneofCase.ApplyRuntimeSettingsResult ||
            !reply.ApplyRuntimeSettingsResult.Accepted ||
            reply.ApplyRuntimeSettingsResult.AcceptedRevision != settings.Revision)
        {
            throw new InvalidOperationException(
                $"runtime_settings_rejected:{reply.ApplyRuntimeSettingsResult?.Reason}");
        }
        return reply.ApplyRuntimeSettingsResult.AcceptedRevision;
    }

    private static WireRuntimeSettings CreateWireSnapshot(HostRuntimeSettings source)
    {
        var snapshot = new WireRuntimeSettings
        {
            Revision = source.Revision,
            AutoMeal = source.Behavior.AutoMeal,
            RestoreFoodFrom = checked((uint)source.Thresholds.Food),
            RestoreWaterFrom = checked((uint)source.Thresholds.Water),
            RestoreHealthFrom = checked((uint)source.Thresholds.Health),
            AutoChangeBait = source.Behavior.AutoChangeBait,
            StoreInTrunk = source.Behavior.StoreInTrunk,
            StartStopSoundEnabled = source.Behavior.StartStopSoundEnabled,
            OverweightAction = Map(source.Behavior.OverweightAction),
            FishWithoutLeader = source.Behavior.FishWithoutLeader,
            LeaderDepletedAction = Map(source.Behavior.LeaderDepletedAction),
            FishWithoutNet = source.Behavior.FishWithoutNet,
            NetDepletedAction = Map(source.Behavior.NetDepletedAction),
            EquipmentDepletedAction = Map(source.Behavior.EquipmentDepletedAction),
            FoodDepletedAction = Map(source.Behavior.FoodDepletedAction),
            StartStopHotkey = source.Hotkeys.StartStop,
            InventoryHotkey = source.Hotkeys.Inventory,
            UseItemHotkey = source.Hotkeys.UseItem,
            BackpackMoveHotkey = source.Hotkeys.BackpackMove,
            DiscardHotkey = source.Hotkeys.Discard,
            ChatHotkey = source.Hotkeys.Chat,
            StreamSnapshotMode = source.Behavior.StreamSnapshotMode,
        };
        snapshot.FishKeepPolicy.Add(FishingFishCatalog.AllIds.Select(fishId =>
            new BooleanPolicyEntry
            {
                Id = fishId,
                Enabled = !source.Selection.FishKeep.TryGetValue(fishId, out var keep) || keep,
            }));
        snapshot.GarbageDisposalPolicy.Add(source.Selection.GarbageDisposal.Select(entry =>
            new BooleanPolicyEntry
            {
                Id = entry.Key,
                Enabled = entry.Value,
            }));
        snapshot.CustomFishPrices.Add(source.Selection.CustomFishPrices.Select(entry =>
            new CustomFishPriceEntry
            {
                FishId = entry.Key,
                Price = entry.Value,
            }));
        return snapshot;
    }

    private static OverweightAction Map(OverweightPolicyAction action) => action switch
    {
        OverweightPolicyAction.Release => OverweightAction.Release,
        OverweightPolicyAction.Stop => OverweightAction.Stop,
        OverweightPolicyAction.ExitGame => OverweightAction.ExitGame,
        _ => throw new ArgumentOutOfRangeException(nameof(action)),
    };

    private static DepletedAction Map(DepletedPolicyAction action) => action switch
    {
        DepletedPolicyAction.Stop => DepletedAction.Stop,
        DepletedPolicyAction.ExitGame => DepletedAction.ExitGame,
        _ => throw new ArgumentOutOfRangeException(nameof(action)),
    };

    private static EquipmentDepletedAction Map(EquipmentDepletedPolicyAction action) => action switch
    {
        EquipmentDepletedPolicyAction.Stop => EquipmentDepletedAction.Stop,
        EquipmentDepletedPolicyAction.ExitGame => EquipmentDepletedAction.ExitGame,
        EquipmentDepletedPolicyAction.ShutdownPc => EquipmentDepletedAction.ShutdownPc,
        _ => throw new ArgumentOutOfRangeException(nameof(action)),
    };

    private static FoodDepletedAction Map(FoodDepletedPolicyAction action) => action switch
    {
        FoodDepletedPolicyAction.Continue => FoodDepletedAction.Continue,
        FoodDepletedPolicyAction.Stop => FoodDepletedAction.Stop,
        FoodDepletedPolicyAction.ExitGame => FoodDepletedAction.ExitGame,
        FoodDepletedPolicyAction.ShutdownPc => FoodDepletedAction.ShutdownPc,
        _ => throw new ArgumentOutOfRangeException(nameof(action)),
    };
}
