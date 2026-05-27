from __future__ import annotations

import math
import time

from sonar.fishing import memory_reeling as reeling_module
from sonar.fishing.memory_reeling import (
    DIRECTION_STALE_SECONDS,
    FISH_MODEL_HASH,
    FISH_PRIMARY_DIRECTION_OFFSETS,
    MemoryReelingTracker,
    PTR_MIN,
)


BASE = PTR_MIN + 0x100000
P_IFACE = BASE + 0x10000
IFACE = BASE + 0x20000
P_LIST = BASE + 0x30000
PLAYER = BASE + 0x40000
FISH = BASE + 0x50000


class DummyInput:
    def __init__(self) -> None:
        self.key_downs: list[str] = []
        self.key_ups: list[str] = []

    def key_down(self, key: str) -> bool:
        self.key_downs.append(key)
        return True

    def key_up(self, key: str) -> None:
        self.key_ups.append(key)

    def is_input_allowed(self) -> bool:
        return True


def make_tracker(
    *,
    entity_hash: int,
    direction: float | None,
    direction_offset: int = 0x300,
    extra_directions: dict[int, float] | None = None,
    fish_pos: tuple[float, float, float] | None = (3.0, 4.0, 0.0),
    player_pos: tuple[float, float, float] = (0.0, 0.0, 0.0),
) -> MemoryReelingTracker:
    tracker = MemoryReelingTracker.__new__(MemoryReelingTracker)
    tracker.running = True
    tracker.handle = 1
    tracker.input_controller = DummyInput()
    tracker.manual_input_mode = False
    tracker.log_messages = []
    tracker.log_callback = tracker.log_messages.append
    tracker.player_addr = PLAYER
    tracker.fish_addr = FISH
    tracker.last_time = None
    tracker.last_fish_xy = None
    tracker.last_fish_pos = None
    tracker.held_key = None
    tracker._last_key_switch_at = 0.0
    tracker.last_good_fish_at = 0.0
    tracker.velocity_xy = (0.0, 0.0)
    tracker._last_step_debug_at = 0.0
    tracker._last_input_allowed_check_at = 0.0
    tracker._input_allowed_cached = True
    tracker._motion_last_pos = None
    tracker._motion_stationary_since = 0.0
    tracker._unreadable_addr = None
    tracker._unreadable_since = 0.0
    tracker._unreadable_count = 0
    tracker._fish_direction_offsets = FISH_PRIMARY_DIRECTION_OFFSETS
    tracker._fish_confirmed_hash = entity_hash == FISH_MODEL_HASH
    tracker._direction_watch_addr = None
    tracker._direction_watch = {}
    tracker._direction_alignment = {}
    tracker._dead_direction_addr = None
    tracker._dead_direction_since = 0.0
    tracker._dead_direction_count = 0
    tracker._blocked_direction_offsets = set()
    tracker._last_lateral = None
    tracker._last_lateral_at = None
    tracker._last_lateral_fish_addr = None
    tracker._lateral_velocity = 0.0
    tracker._last_line_vector = None
    tracker._stable_move_sign = None
    tracker._last_stable_move_at = 0.0
    tracker._pending_move_sign = None
    tracker._pending_move_since = 0.0
    tracker._pending_move_count = 0
    tracker._last_fish_search_at = 0.0
    tracker._last_deep_fish_search_at = 0.0
    tracker.last_fish_pos_offset = None
    tracker._rejected_fish_addrs = set()
    tracker._replay_broad_paths = []

    def u64(addr: int) -> int | None:
        if addr == P_IFACE + 0x8:
            return IFACE
        if addr == IFACE:
            return P_LIST
        if addr == P_LIST + 7 * 0x8:
            return FISH
        return None

    def f32(addr: int) -> float | None:
        fish_values = {
            PLAYER + 0x50: player_pos[0],
            PLAYER + 0x54: player_pos[1],
            PLAYER + 0x58: player_pos[2],
        }
        if fish_pos is not None:
            fish_values.update({
                FISH + 0x130: fish_pos[0],
                FISH + 0x134: fish_pos[1],
                FISH + 0x138: fish_pos[2],
            })
        for offset, value in (extra_directions or {}).items():
            fish_values[FISH + offset] = value
        if direction is not None:
            fish_values[FISH + direction_offset] = direction
        return fish_values.get(addr)

    tracker._u64 = u64
    tracker._f32 = f32
    tracker._read_entity_hash = lambda addr: entity_hash if addr == FISH else None
    return tracker


def test_replay_broad_accepts_known_fish_hash() -> None:
    tracker = make_tracker(entity_hash=FISH_MODEL_HASH, direction=None)

    assert tracker._find_fish_addr_replay_broad(P_IFACE, (0.0, 0.0, 0.0)) == FISH
    assert tracker._fish_direction_offsets == FISH_PRIMARY_DIRECTION_OFFSETS
    assert tracker._fish_confirmed_hash is True


def test_replay_broad_accepts_fishing_local_pos_when_player_pos_is_world_coord() -> None:
    tracker = make_tracker(entity_hash=FISH_MODEL_HASH, direction=None)

    assert tracker._find_fish_addr_replay_broad(P_IFACE, (-19744.0, 0.0, 0.0)) == FISH


def test_replay_broad_accepts_fishing_local_pos_without_player_position() -> None:
    tracker = make_tracker(entity_hash=FISH_MODEL_HASH, direction=None)

    assert tracker._find_fish_addr_replay_broad(P_IFACE, None) == FISH


def test_replay_broad_rejects_unknown_hash_with_direction_signal() -> None:
    tracker = make_tracker(entity_hash=12345, direction=0.75)

    assert tracker._find_fish_addr_replay_broad(P_IFACE, (0.0, 0.0, 0.0)) is None


def test_unknown_direction_candidates_prefer_primary_memory_fields() -> None:
    near_70 = (1.0, 12345, (3.0, 4.0, 0.0), "direction_0x70")
    far_68 = (100.0, 12345, (9.0, 2.0, 0.0), "direction_0x68")

    assert MemoryReelingTracker._fish_signal_key(far_68) < MemoryReelingTracker._fish_signal_key(near_70)


def test_read_fish_direction_skips_blocked_offset() -> None:
    tracker = make_tracker(
        entity_hash=12345,
        direction=0.75,
        direction_offset=0x70,
        extra_directions={0x300: -0.5},
    )

    assert tracker._read_fish_direction(FISH, frozenset({0x300, 0x68, 0x70}), {0x300}) == (1.0, 0x70, 0.75)


def test_stale_direction_signal_is_detected() -> None:
    tracker = make_tracker(entity_hash=12345, direction=-0.325)
    tracker.fish_addr = FISH
    tracker._fish_direction_offsets = frozenset({0x300, 0x68, 0x70})
    tracker._reset_direction_tracking(FISH)

    assert not tracker._is_stale_direction_signal(10.0, 0x70, -0.325)
    assert not tracker._is_stale_direction_signal(10.5, 0x70, -0.326)
    assert tracker._is_stale_direction_signal(10.0 + DIRECTION_STALE_SECONDS + 0.1, 0x70, -0.324)


def test_confirmed_hash_fish_does_not_recalibrate_on_stable_direction() -> None:
    tracker = make_tracker(entity_hash=FISH_MODEL_HASH, direction=0.003, direction_offset=0x68)
    tracker.held_key = "d"
    tracker._reset_direction_tracking(FISH)
    tracker._direction_watch[0x68] = (0.003, time.time() - DIRECTION_STALE_SECONDS - 1.0)

    state = tracker.step()

    assert state.action == "hold_d"
    assert tracker.fish_addr == FISH
    assert tracker._blocked_direction_offsets == set()


def test_live_68_direction_is_preferred_before_stale_heading_fields() -> None:
    tracker = make_tracker(
        entity_hash=FISH_MODEL_HASH,
        direction=-0.75,
        direction_offset=0x300,
        extra_directions={0x68: 0.003},
    )

    assert tracker._read_fish_direction(FISH, FISH_PRIMARY_DIRECTION_OFFSETS) == (1.0, 0x68, 0.003)


def test_live_304_direction_is_preferred_for_current_fish_profile() -> None:
    tracker = make_tracker(
        entity_hash=FISH_MODEL_HASH,
        direction=-0.75,
        direction_offset=0x300,
        extra_directions={0x68: 0.003, 0x304: -0.25},
    )

    assert tracker._read_fish_direction(FISH, FISH_PRIMARY_DIRECTION_OFFSETS) == (-1.0, 0x304, -0.25)


def test_positive_move_presses_reeling_key() -> None:
    tracker = make_tracker(entity_hash=FISH_MODEL_HASH, direction=0.003, direction_offset=0x68)
    input_controller = tracker.input_controller

    state = tracker.step()

    assert state.move_val == 1.0
    assert state.action == "hold_d"
    assert tracker.held_key == "d"
    assert input_controller.key_downs == ["d"]
    assert input_controller.key_ups == []


def test_negative_move_holds_opposite_reeling_key() -> None:
    tracker = make_tracker(entity_hash=FISH_MODEL_HASH, direction=-0.003, direction_offset=0x68)
    tracker.held_key = "a"

    state = tracker.step()

    assert state.move_val == -1.0
    assert state.action == "hold_a"


def test_negative_move_switches_reeling_key() -> None:
    tracker = make_tracker(entity_hash=FISH_MODEL_HASH, direction=-0.003, direction_offset=0x68)
    tracker.held_key = "d"
    input_controller = tracker.input_controller

    state = tracker.step()

    assert state.move_val == -1.0
    assert state.action == "hold_a"
    assert tracker.held_key == "a"
    assert input_controller.key_ups == ["d"]
    assert input_controller.key_downs == ["a"]


def test_manual_reeling_uses_virtual_key_without_physical_input() -> None:
    tracker = make_tracker(entity_hash=FISH_MODEL_HASH, direction=0.003, direction_offset=0x68)
    tracker.manual_input_mode = True
    input_controller = tracker.input_controller

    state = tracker.step()

    assert state.action == "hold_d"
    assert tracker.held_key == "d"
    assert input_controller.key_downs == []
    assert input_controller.key_ups == []


def test_manual_reeling_switch_does_not_release_or_press_physical_keys() -> None:
    tracker = make_tracker(entity_hash=FISH_MODEL_HASH, direction=-0.003, direction_offset=0x68)
    tracker.manual_input_mode = True
    tracker.held_key = "d"
    input_controller = tracker.input_controller

    state = tracker.step()

    assert state.action == "hold_a"
    assert tracker.held_key == "a"
    assert input_controller.key_downs == []
    assert input_controller.key_ups == []


def test_confirmed_fish_uses_direction_consensus_when_primary_field_disagrees() -> None:
    tracker = make_tracker(
        entity_hash=FISH_MODEL_HASH,
        direction=None,
        extra_directions={
            0x304: -0.33,
            0x68: 0.004,
            0x80: 0.45,
        },
    )

    state = tracker.step()

    assert state.action == "hold_d"
    assert state.move_val == 1.0
    assert tracker.held_key == "d"


def test_confirmed_fish_adapts_heading_fields_with_direct_polarity() -> None:
    tracker = make_tracker(
        entity_hash=FISH_MODEL_HASH,
        direction=None,
        extra_directions={
            0x68: 0.0008,
            0x300: 0.6,
            0x70: 0.6,
            0x80: -0.3,
            0x64: -0.6,
        },
    )
    tracker._direction_watch_addr = FISH
    for offset in (0x300, 0x70, 0x80, 0x64):
        tracker._direction_alignment[offset] = reeling_module.FISH_DIRECTION_ALIGNMENT_THRESHOLD

    state = tracker.step()

    assert state.action == "hold_d"
    assert state.move_val == 1.0


def test_confirmed_fish_20260527_direct_heading_overrides_wrong_anchor_sample() -> None:
    tracker = make_tracker(
        entity_hash=FISH_MODEL_HASH,
        direction=None,
        extra_directions={
            0x304: -0.07647757977247238,
            0x68: -0.0035606950987130404,
            0x300: 0.82224041223526,
            0x70: 0.810722291469574,
            0x80: -0.5747964382171631,
            0x64: -0.9938056468963623,
            0x314: -0.5996294617652893,
        },
    )
    tracker._direction_watch_addr = FISH
    for offset in (0x300, 0x70, 0x80, 0x64, 0x314):
        tracker._direction_alignment[offset] = reeling_module.FISH_DIRECTION_ALIGNMENT_THRESHOLD

    state = tracker.step()

    assert state.action == "hold_d"
    assert state.move_val == 1.0


def test_confirmed_fish_preserves_inverse_heading_polarity_after_learning() -> None:
    tracker = make_tracker(
        entity_hash=FISH_MODEL_HASH,
        direction=None,
        extra_directions={
            0x68: 0.0008,
            0x300: -0.6,
            0x70: -0.6,
            0x80: 0.3,
            0x64: 0.6,
        },
    )
    tracker._direction_watch_addr = FISH
    for offset in (0x300, 0x70, 0x80, 0x64):
        tracker._direction_alignment[offset] = -reeling_module.FISH_DIRECTION_ALIGNMENT_THRESHOLD

    state = tracker.step()

    assert state.action == "hold_d"
    assert state.move_val == 1.0


def test_confirmed_fish_rejects_dead_zero_anchor_from_20260527_manual_log() -> None:
    tracker = make_tracker(
        entity_hash=FISH_MODEL_HASH,
        direction=None,
        fish_pos=(3.0001258850097656, 4.007851600646973, 0.0),
        player_pos=(7.403059862554073e-05, 6.221765181602188e-43, 0.0),
        extra_directions={
            0x68: 0.0,
            0x304: -0.2592464089393616,
            0x300: 0.7563496828079224,
            0x70: 0.7549276947975159,
            0x80: -0.5309227108955383,
            0x64: -0.9229272603988647,
            0x314: -0.5696833729743958,
        },
    )
    tracker._direction_watch_addr = FISH
    tracker._dead_direction_addr = FISH
    tracker._dead_direction_since = time.time() - reeling_module.CONFIRMED_DEAD_DIRECTION_SECONDS - 0.1
    tracker._dead_direction_count = reeling_module.CONFIRMED_DEAD_DIRECTION_COUNT - 1

    state = tracker.step()

    assert state.action == "target_search"
    assert tracker.fish_addr is None
    assert FISH in tracker._rejected_fish_addrs
    assert any("confirmed direction unavailable" in message for message in tracker.log_messages)


def test_confirmed_fish_does_not_reject_zero_anchor_after_alignment_is_learned() -> None:
    tracker = make_tracker(
        entity_hash=FISH_MODEL_HASH,
        direction=None,
        extra_directions={
            0x68: 0.0,
            0x300: 0.7563496828079224,
            0x70: 0.7549276947975159,
            0x80: -0.5309227108955383,
            0x64: -0.9229272603988647,
        },
    )
    tracker._direction_watch_addr = FISH
    for offset in (0x300, 0x70, 0x80, 0x64):
        tracker._direction_alignment[offset] = reeling_module.FISH_DIRECTION_ALIGNMENT_THRESHOLD
    tracker._dead_direction_addr = FISH
    tracker._dead_direction_since = time.time() - reeling_module.CONFIRMED_DEAD_DIRECTION_SECONDS - 0.1
    tracker._dead_direction_count = reeling_module.CONFIRMED_DEAD_DIRECTION_COUNT - 1

    state = tracker.step()

    assert state.action == "hold_d"
    assert state.move_val == 1.0
    assert tracker.fish_addr == FISH


def test_confirmed_hash_local_position_without_direction_keeps_target() -> None:
    tracker = make_tracker(
        entity_hash=FISH_MODEL_HASH,
        direction=None,
        fish_pos=(3.51, 2.06, 0.0),
        player_pos=(-19744.0, 1300.0, 35.0),
    )
    tracker.held_key = "d"
    input_controller = tracker.input_controller

    state = tracker.step()

    assert state.action == "hold_d_wait"
    assert tracker.fish_addr == FISH
    assert FISH not in tracker._rejected_fish_addrs
    assert input_controller.key_ups == []
    assert tracker.log_messages == []
    assert state.distance is not None
    assert abs(state.distance - math.hypot(3.51, 2.06)) < 0.001
    assert state.lateral == 3.51


def test_unconfirmed_local_position_without_direction_is_rejected() -> None:
    tracker = make_tracker(
        entity_hash=12345,
        direction=None,
        fish_pos=(3.51, 2.06, 0.0),
        player_pos=(-19744.0, 1300.0, 35.0),
    )

    state = tracker.step()

    assert state.action == "target_search"
    assert tracker.fish_addr is None
    assert FISH in tracker._rejected_fish_addrs
    assert tracker.log_messages == [
        "Memory reeling rejected fish target: local fish position without live direction "
        f"addr=0x{FISH:X} pos=(3.51,2.06,0.00) distance=unknown"
    ]


def test_known_hash_direction_offsets_stay_on_primary_fields() -> None:
    assert (
        MemoryReelingTracker._direction_offsets_for_signal(FISH_MODEL_HASH)
        == FISH_PRIMARY_DIRECTION_OFFSETS
    )


def test_replay_broad_rejects_unknown_hash_with_fish_position_only() -> None:
    tracker = make_tracker(entity_hash=12345, direction=None)

    assert tracker._find_fish_addr_replay_broad(P_IFACE, (0.0, 0.0, 0.0)) is None


def test_replay_broad_rejects_unknown_hash_with_non_primary_direction() -> None:
    tracker = make_tracker(entity_hash=12345, direction=-0.4, direction_offset=0x314)

    assert tracker._find_fish_addr_replay_broad(P_IFACE, (0.0, 0.0, 0.0)) is None


def test_replay_broad_rejects_small_local_false_positive() -> None:
    tracker = make_tracker(entity_hash=12345, direction=0.75, fish_pos=(0.9, 0.1, 0.1))

    assert tracker._find_fish_addr_replay_broad(P_IFACE, (0.0, 0.0, 0.0)) is None


def test_replay_broad_rejects_unknown_hash_with_high_local_z() -> None:
    tracker = make_tracker(entity_hash=12345, direction=-0.25, direction_offset=0x70, fish_pos=(8.0, 2.0, 2.1))

    assert tracker._find_fish_addr_replay_broad(P_IFACE, (0.0, 0.0, 0.0)) is None


def test_replay_broad_rejects_sentinel_local_position_and_huge_direction() -> None:
    tracker = make_tracker(entity_hash=12345, direction=100000.0, fish_pos=(-1.0, -1.0, -1.0))

    assert tracker._find_fish_addr_replay_broad(P_IFACE, (0.0, 0.0, 0.0)) is None


def test_reeling_key_switch_waits_like_manual_input(monkeypatch) -> None:
    tracker = make_tracker(entity_hash=FISH_MODEL_HASH, direction=-0.003, direction_offset=0x68)
    tracker.held_key = "d"
    sleep_calls: list[float] = []
    monkeypatch.setattr(reeling_module.random, "uniform", lambda start, end: 0.123)
    monkeypatch.setattr(reeling_module.time, "sleep", sleep_calls.append)

    state = tracker.step()

    assert state.action == "hold_a"
    assert tracker.held_key == "a"
    assert sleep_calls == [0.123]


def test_reeling_initial_press_has_no_artificial_sleep(monkeypatch) -> None:
    tracker = make_tracker(entity_hash=FISH_MODEL_HASH, direction=0.003, direction_offset=0x68)
    sleep_calls: list[float] = []
    monkeypatch.setattr(reeling_module.time, "sleep", sleep_calls.append)

    state = tracker.step()

    assert state.action == "hold_d"
    assert tracker.held_key == "d"
    assert sleep_calls == []


def test_missing_fresh_fish_position_keeps_last_stable_input_briefly() -> None:
    tracker = make_tracker(entity_hash=FISH_MODEL_HASH, direction=None, fish_pos=None)
    tracker.held_key = "d"
    tracker._stable_move_sign = 1
    tracker._last_stable_move_at = time.time()
    tracker.last_fish_pos = (3.0, 4.0, 0.0)
    tracker.last_fish_pos_offset = 0x130
    tracker.last_good_fish_at = time.time()
    input_controller = tracker.input_controller

    state = tracker.step()

    assert state.action == "hold_d_wait_fresh_position"
    assert state.move_val == 1.0
    assert tracker.held_key == "d"
    assert input_controller.key_ups == []


def test_missing_fresh_fish_position_releases_key_after_stable_input_grace() -> None:
    tracker = make_tracker(entity_hash=FISH_MODEL_HASH, direction=None, fish_pos=None)
    tracker.held_key = "d"
    tracker._stable_move_sign = 1
    tracker._last_stable_move_at = time.time() - reeling_module.STALE_REELING_INPUT_HOLD_SECONDS - 0.1
    tracker.last_fish_pos = (3.0, 4.0, 0.0)
    tracker.last_fish_pos_offset = 0x130
    tracker.last_good_fish_at = time.time()
    input_controller = tracker.input_controller

    state = tracker.step()

    assert state.action == "wait_fresh_position"
    assert tracker.held_key is None
    assert input_controller.key_ups == ["d"]


def test_lateral_velocity_switches_before_large_delta_accumulates() -> None:
    tracker = make_tracker(entity_hash=FISH_MODEL_HASH, direction=None)
    tracker._last_lateral = 1.0
    tracker._last_lateral_at = 10.0
    tracker._last_lateral_fish_addr = FISH
    tracker._last_line_vector = (6.0, 0.0)
    tracker.held_key = "d"

    move_val, source, _ = tracker._movement_from_lateral(
        lateral=1.08,
        velocity_along=0.0,
        now=10.05,
        fish_addr=FISH,
        using_stale_fish_pos=False,
        player_pos=(0.0, 0.0, 0.0),
        fish_pos=(6.0, 0.0, 0.0),
    )

    assert move_val == 1.0
    assert source == "lateral_velocity"


def test_reeling_direction_ignores_single_opposite_jitter() -> None:
    tracker = make_tracker(entity_hash=FISH_MODEL_HASH, direction=-0.003, direction_offset=0x68)
    tracker.held_key = "d"
    tracker._stable_move_sign = 1

    state = tracker.step()

    assert state.move_val == 1.0
    assert state.action == "hold_d"
    assert tracker.held_key == "d"
    assert tracker.input_controller.key_downs == []
    assert tracker.input_controller.key_ups == []
    assert tracker._pending_move_sign == -1
    assert tracker._pending_move_count == 1


def test_reeling_direction_switches_after_confirmed_opposite_samples() -> None:
    tracker = make_tracker(entity_hash=FISH_MODEL_HASH, direction=-0.003, direction_offset=0x68)
    tracker.held_key = "d"
    tracker._stable_move_sign = 1
    tracker._last_stable_move_at = time.time()
    tracker._pending_move_sign = -1
    tracker._pending_move_count = reeling_module.DIRECTION_SWITCH_CONFIRM_SAMPLES - 1
    tracker._pending_move_since = time.time() - reeling_module.DIRECTION_SWITCH_CONFIRM_SECONDS - 0.01
    input_controller = tracker.input_controller

    state = tracker.step()

    assert state.move_val == -1.0
    assert state.action == "hold_a"
    assert tracker.held_key == "a"
    assert input_controller.key_ups == ["d"]
    assert input_controller.key_downs == ["a"]
