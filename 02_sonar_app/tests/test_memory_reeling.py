from __future__ import annotations

import math
import time

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
    fish_pos: tuple[float, float, float] = (3.0, 4.0, 0.0),
    player_pos: tuple[float, float, float] = (0.0, 0.0, 0.0),
) -> MemoryReelingTracker:
    tracker = MemoryReelingTracker.__new__(MemoryReelingTracker)
    tracker.running = True
    tracker.handle = 1
    tracker.input_controller = DummyInput()
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
    tracker._blocked_direction_offsets = set()
    tracker._last_lateral = None
    tracker._last_lateral_at = None
    tracker._last_lateral_fish_addr = None
    tracker._lateral_velocity = 0.0
    tracker._last_line_vector = None
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
            FISH + 0x130: fish_pos[0],
            FISH + 0x134: fish_pos[1],
            FISH + 0x138: fish_pos[2],
        }
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
    tracker = make_tracker(entity_hash=FISH_MODEL_HASH, direction=0.75)
    tracker.held_key = "d"
    tracker._reset_direction_tracking(FISH)
    tracker._direction_watch[0x300] = (0.75, time.time() - DIRECTION_STALE_SECONDS - 1.0)

    state = tracker.step()

    assert state.action == "hold_d"
    assert tracker.fish_addr == FISH
    assert tracker._blocked_direction_offsets == set()


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
