from __future__ import annotations

import base64
import ctypes
import json
import math
import os
import struct
import threading
import time
from ctypes import wintypes
from datetime import datetime, timezone
from dataclasses import dataclass
from typing import Callable, TextIO

import psutil
import numpy as np

from sonar.automation.input_controller import InputController
from sonar.core.logging import debug_log
from sonar.fishing.constants import PROCESS_NAME
from sonar.paths import LOG_DIR
from sonar.security.runtime import decrypt_json_literal


PROCESS_ALL_READ = 0x0410
MEM_COMMIT = 0x1000
PAGE_GUARD = 0x100
PAGE_NOACCESS = 0x01
TH32CS_SNAPMODULE = 0x00000008
TH32CS_SNAPMODULE32 = 0x00000010
INVALID_HANDLE_VALUE = -1
PTR_MIN = 0x10000000000
PTR_MAX = 0x40000000000
MAX_SCAN_REGION = 1024 * 1024
FISH_MODEL_HASH = 802685111
TRACK_MAX_DIST = 35.0
CONFIRMED_FISH_MAX_DIST = 120.0
FISH_WORLD_POS_OFFSET = 0x90
MOVE_EPS = 0.5
KEY_SWITCH_MIN_SECONDS = 0.0
REEL_CONTROL_INTERVAL_SECONDS = 0.005
REEL_DEBUG_INTERVAL_SECONDS = 0.10
STALE_FISH_POSITION_SECONDS = 0.25
STALE_REELING_INPUT_HOLD_SECONDS = 0.55
LATERAL_VELOCITY_EPS = 0.65
PROJECTED_VELOCITY_MIN_EPS = 0.20
PROJECTED_VELOCITY_MAX_EPS = 0.75
PROJECTED_VELOCITY_EPS_WEIGHT = 0.02
FISH_BEHIND_PLAYER_FORWARD_EPS = 1.0
FISH_POSITION_CHANGE_EPS = 0.00001
FISH_VELOCITY_NEW_SAMPLE_WEIGHT = 0.8
DIRECTION_SWITCH_CONFIRM_SECONDS = 0.015
DIRECTION_SWITCH_CONFIRM_SAMPLES = 2
DIRECTION_MOVE = 1.0
DIRECTION_EPS = 0.5
FISH_FAST_RETRY_SECONDS = 0.12
FISH_DEEP_RETRY_SECONDS = 0.8
REPLAY_BROAD_SCAN_LIMIT = 512
STATIONARY_TARGET_EPS = 0.02
STATIONARY_TARGET_SECONDS = 0.45
STATIONARY_TARGET_MIN_DISTANCE = 5.0
UNREADABLE_REJECT_SECONDS = 0.08
UNREADABLE_REJECT_COUNT = 3
_MEMORY_CONFIG = decrypt_json_literal("memory_reeling")
# The encrypted config retains names from the initial port. Entity world
# positions are direct +0x90 reads; these offsets are matrix candidates.
PLAYER_MATRIX_OFFSETS = tuple(int(item) for item in _MEMORY_CONFIG["pos_offsets"])
POS_OFFSETS = (0x90,)
FISH_POS_OFFSETS = tuple(
    dict.fromkeys((FISH_WORLD_POS_OFFSET, *(int(item) for item in _MEMORY_CONFIG["fish_pos_offsets"])))
)
FISH_LOCAL_X_RANGE = (1.5, 45.0)
FISH_LOCAL_Y_RANGE = (1.0, 12.0)
FISH_LOCAL_Z_RANGE = (-0.75, 0.75)
FISH_DIRECTION_MAX_ABS = 4.0
FISH_PRIMARY_DIRECTION_OFFSETS = frozenset(int(item) for item in _MEMORY_CONFIG["fish_primary_direction_offsets"])
FISH_DIRECTION_SOURCE_RANK = {int(offset): int(rank) for offset, rank in _MEMORY_CONFIG["fish_direction_source_rank"]}
ALLOW_UNKNOWN_FISH_CANDIDATES = False
DIRECTION_STALE_EPS = 0.01
DIRECTION_STALE_SECONDS = 1.6
FISH_DIRECTION_CONSENSUS_EPS = 1.5
FISH_DIRECTION_CONSENSUS_MAX_CONTRIBUTION = 3.0
FISH_DIRECTION_ALIGNMENT_THRESHOLD = 12
FISH_DIRECTION_ANCHOR_OFFSET = int(_MEMORY_CONFIG["fish_direction_anchor_offset"])
FISH_DIRECTION_ANCHOR_SCALE = 0.0017
FISH_DIRECTION_ANCHOR_WEIGHT = 1.5
FISH_REELING_ACTIVE_OFFSET = 0x189
FISH_REELING_ACTIVE_VALUE = 1
FISH_DIRECTION_FIELDS = tuple(
    (int(offset), float(eps), float(polarity))
    for offset, eps, polarity in _MEMORY_CONFIG["fish_direction_fields"]
)
FISH_DIRECTION_ADAPTIVE_FIELDS = tuple(
    (int(offset), float(scale), float(weight))
    for offset, scale, weight in _MEMORY_CONFIG["fish_direction_adaptive_fields"]
)
FISH_DIRECTION_FIELD_CONFIG = {offset: (eps, polarity) for offset, eps, polarity in FISH_DIRECTION_FIELDS}
MANUAL_REELING_ENV = "SONAR_REELING_MANUAL_MODE"
MANUAL_REELING_DUMP_INTERVAL_SECONDS = 0.02
MANUAL_REELING_MEMORY_DUMP_INTERVAL_SECONDS = 0.25
MANUAL_REELING_MEMORY_DUMP_BYTES = 0x400
VK_A = 0x41
VK_D = 0x44
POS_X_OFF = 144
POS_Y_OFF = 148
POS_Z_OFF = 152
BOBBER_MARKER_OFFSETS = (264,)
BOBBER_MARKER_F32 = 0.03
BOBBER_MARKER_EPS = 0.002
BOBBER_Z_BELOW = 6.0
BOBBER_Z_ABOVE = 2.5
SCAN_RADIUS = 120.0
FAST_HASH_RADIUS = 90.0
MAX_REGION_BYTES = 536_870_912
MARKER_REGION_CHUNK = 32 * 1024 * 1024
SCAN_HALF_RANGE = 0x20000000

WORLD_PATTERNS: tuple[tuple[tuple[int | None, ...], int, int, tuple[int, ...]], ...] = tuple(
    (
        tuple(None if value is None else int(value) for value in pattern),
        int(rel_off),
        int(insn_len),
        tuple(int(offset) for offset in offsets),
    )
    for pattern, rel_off, insn_len, offsets in _MEMORY_CONFIG["replay_patterns"]
)

REPLAY_IFACE_PATTERN: tuple[int | None, ...] = tuple(
    None if value is None else int(value) for value in _MEMORY_CONFIG["cped_pattern"]
)


@dataclass(slots=True)
class ReelingState:
    active: bool = False
    distance: float | None = None
    action: str = "idle"
    fish_addr: int | None = None
    player_addr: int | None = None
    lateral: float | None = None
    move_val: float | None = None
    player_pos_offset: int | None = None
    fish_pos_offset: int | None = None


@dataclass(slots=True)
class ModuleInfo:
    name: str
    base: int
    size: int


class MODULEENTRY32(ctypes.Structure):
    _fields_ = [
        ("dwSize", wintypes.DWORD),
        ("th32ModuleID", wintypes.DWORD),
        ("th32ProcessID", wintypes.DWORD),
        ("GlblcntUsage", wintypes.DWORD),
        ("ProccntUsage", wintypes.DWORD),
        ("modBaseAddr", ctypes.POINTER(ctypes.c_byte)),
        ("modBaseSize", wintypes.DWORD),
        ("hModule", wintypes.HMODULE),
        ("szModule", ctypes.c_char * 256),
        ("szExePath", ctypes.c_char * 260),
    ]


class MEMORY_BASIC_INFORMATION(ctypes.Structure):
    _fields_ = [
        ("BaseAddress", ctypes.c_void_p),
        ("AllocationBase", ctypes.c_void_p),
        ("AllocationProtect", wintypes.DWORD),
        ("RegionSize", ctypes.c_size_t),
        ("State", wintypes.DWORD),
        ("Protect", wintypes.DWORD),
        ("Type", wintypes.DWORD),
    ]


class MemoryReelingTracker:
    def __init__(
        self,
        process_name: str = PROCESS_NAME,
        input_controller: InputController | None = None,
        log_callback: Callable[[str], None] | None = None,
        manual_input_mode: bool | None = None,
    ) -> None:
        self.process_name = process_name
        self.input_controller = input_controller or InputController()
        self.log_callback = log_callback
        self.manual_input_mode = self._manual_mode_enabled(manual_input_mode)
        self.running = False
        self.pid: int | None = None
        self.handle: int | None = None
        self.player_addr: int | None = None
        self.fish_addr: int | None = None
        self.replay_interface: int | None = None
        self.last_time: float | None = None
        self.last_fish_xy: tuple[float, float] | None = None
        self.last_fish_pos: tuple[float, float, float] | None = None
        self.last_fish_pos_offset: int | None = None
        self.last_good_fish_at = 0.0
        self.last_player_right_vec: tuple[float, float] | None = None
        self.velocity_xy = (0.0, 0.0)
        self.held_key: str | None = None
        self._last_key_switch_at = 0.0
        self._resolver_thread: threading.Thread | None = None
        self._last_fish_search_at = 0.0
        self._last_deep_fish_search_at = 0.0
        self._last_target_search_at = 0.0
        self._last_search_log_at = 0.0
        self._last_step_debug_at = 0.0
        self._motion_last_pos: tuple[float, float, float] | None = None
        self._motion_stationary_since = 0.0
        self._rejected_fish_addrs: set[int] = set()
        self._unreadable_addr: int | None = None
        self._unreadable_since = 0.0
        self._unreadable_count = 0
        self._replay_broad_paths: list[tuple[int, int, int, int]] = []
        self._fish_direction_offsets: frozenset[int] | None = FISH_PRIMARY_DIRECTION_OFFSETS
        self._fish_confirmed_hash = False
        self._direction_watch_addr: int | None = None
        self._direction_watch: dict[int, tuple[float, float]] = {}
        self._direction_alignment: dict[int, int] = {}
        self._blocked_direction_offsets: set[int] = set()
        self._projected_velocity_fish_addr: int | None = None
        self._projected_velocity = 0.0
        self._projected_velocity_abs_ema = LATERAL_VELOCITY_EPS
        self._projected_velocity_eps = LATERAL_VELOCITY_EPS
        self._stable_move_sign: int | None = None
        self._last_stable_move_at = 0.0
        self._pending_move_sign: int | None = None
        self._pending_move_since = 0.0
        self._pending_move_count = 0
        self._latest_state = ReelingState(active=False)
        self._state_lock = threading.Lock()
        self._control_thread: threading.Thread | None = None
        self._control_stop = threading.Event()
        self._last_input_allowed_check_at = 0.0
        self._input_allowed_cached = True
        self._manual_dump_file: TextIO | None = None
        self._manual_dump_path = None
        self._last_manual_dump_at = 0.0
        self._last_manual_memory_dump_at = 0.0

    def configure_manual_mode(self, enabled: bool | None) -> None:
        self.manual_input_mode = self._manual_mode_enabled(enabled)
        if self.running and self.manual_input_mode:
            self._open_manual_dump()
        elif self.running:
            self._close_manual_dump()

    @staticmethod
    def _manual_mode_enabled(enabled: bool | None) -> bool:
        env_value = os.environ.get(MANUAL_REELING_ENV, "").strip().lower()
        env_enabled = env_value in {"1", "true", "yes", "on"}
        return env_enabled if enabled is None else bool(enabled) or env_enabled

    def _manual_input_enabled(self) -> bool:
        return bool(getattr(self, "manual_input_mode", False))

    def _log(self, msg: str) -> None:
        if self.log_callback:
            self.log_callback(msg)

    def start(self) -> None:
        self.running = True
        self._close_manual_dump()
        self.player_addr = None
        self.fish_addr = None
        self.replay_interface = None
        self.last_fish_xy = None
        self.last_fish_pos = None
        self.last_fish_pos_offset = None
        self.last_good_fish_at = 0.0
        self.last_player_right_vec = None
        self.velocity_xy = (0.0, 0.0)
        self._last_key_switch_at = 0.0
        self._last_fish_search_at = 0.0
        self._last_deep_fish_search_at = 0.0
        self._last_target_search_at = 0.0
        self._last_search_log_at = 0.0
        self._last_step_debug_at = 0.0
        self._motion_last_pos = None
        self._motion_stationary_since = 0.0
        self._rejected_fish_addrs.clear()
        self._fish_direction_offsets = FISH_PRIMARY_DIRECTION_OFFSETS
        self._fish_confirmed_hash = False
        self._reset_direction_tracking()
        self._unreadable_addr = None
        self._unreadable_since = 0.0
        self._unreadable_count = 0
        self._reset_projected_velocity_tracking()
        self._reset_move_stabilizer()
        self._last_input_allowed_check_at = 0.0
        self._input_allowed_cached = True
        self._last_manual_dump_at = 0.0
        self._last_manual_memory_dump_at = 0.0
        if self._manual_input_enabled():
            self._open_manual_dump()
        self._set_latest_state(ReelingState(active=True, action="starting"))
        self.pid = self._get_pid()
        if self.pid is None:
            self._log("Memory reeling: process not found")
            return
        self.handle = ctypes.windll.kernel32.OpenProcess(PROCESS_ALL_READ, False, self.pid)
        if not self.handle:
            self.handle = None
            self._log("Memory reeling: OpenProcess failed")
            return
        self.last_time = time.time()
        self._resolver_thread = threading.Thread(target=self._resolve_targets, name="sonar-memory-resolver", daemon=True)
        self._resolver_thread.start()

    def stop(self) -> None:
        self.running = False
        self.stop_control_loop()
        self._release_key("a")
        self._release_key("d")
        self._close_manual_dump()
        if self.handle:
            ctypes.windll.kernel32.CloseHandle(self.handle)
        self.handle = None
        self.held_key = None
        self._last_key_switch_at = 0.0
        if self._resolver_thread and self._resolver_thread.is_alive():
            self._resolver_thread.join(timeout=0.2)
        self._set_latest_state(ReelingState(active=False))

    def start_control_loop(self, interval: float = REEL_CONTROL_INTERVAL_SECONDS) -> None:
        if not self.running:
            return
        if not self.handle:
            self._set_latest_state(ReelingState(active=True, action="memory_unavailable"))
            return
        if self._control_thread and self._control_thread.is_alive():
            return
        self._control_stop.clear()
        self._control_thread = threading.Thread(
            target=self._control_loop,
            args=(interval,),
            name="sonar-reeling-control",
            daemon=True,
        )
        self._control_thread.start()

    def stop_control_loop(self) -> None:
        self._control_stop.set()
        if (
            self._control_thread
            and self._control_thread.is_alive()
            and threading.current_thread() is not self._control_thread
        ):
            self._control_thread.join(timeout=1.0)
        self._control_thread = None

    def latest_state(self) -> ReelingState:
        with self._state_lock:
            return self._latest_state

    def _set_latest_state(self, state: ReelingState) -> None:
        with self._state_lock:
            self._latest_state = state

    def _control_loop(self, interval: float) -> None:
        memory_unavailable_released = False
        while self.running and not self._control_stop.is_set():
            started_at = time.perf_counter()
            try:
                state = self.step()
                if state.action == "memory_unavailable" and not memory_unavailable_released:
                    if self._manual_input_enabled():
                        debug_log("REEL_MANUAL_MEMORY_UNAVAILABLE release_skipped")
                    else:
                        self.input_controller.key_up("a")
                        self.input_controller.key_up("d")
                    memory_unavailable_released = True
                elif state.action != "memory_unavailable":
                    memory_unavailable_released = False
            except Exception as exc:
                state = ReelingState(active=True, action="control_error")
                debug_log(f"REEL_CONTROL_ERROR {exc}")
            self._write_manual_dump(state)
            self._set_latest_state(state)
            elapsed = time.perf_counter() - started_at
            self._control_stop.wait(max(0.0, interval - elapsed))

    def step(self) -> ReelingState:
        if not self.running:
            return ReelingState(active=False)
        if not self.handle:
            return ReelingState(active=True, action="memory_unavailable")
        if not self._input_allowed():
            if self.held_key:
                self._release_key(self.held_key)
            return ReelingState(active=True, action="input_blocked", fish_addr=self.fish_addr, player_addr=self.player_addr)
        if self.player_addr is None:
            self._retry_find_targets()
            return ReelingState(active=True, action="target_search", fish_addr=self.fish_addr)
        if self.fish_addr is None:
            self._retry_find_fish()
            return ReelingState(active=True, action="target_search", player_addr=self.player_addr)
        if self.player_addr is None or self.fish_addr is None:
            return ReelingState(active=True, action="target_search", fish_addr=self.fish_addr, player_addr=self.player_addr)

        if self._fish_confirmed_hash and self._is_finished_fish(self.fish_addr):
            if self.held_key:
                self._release_key(self.held_key)
            return ReelingState(
                active=True,
                action="fish_caught",
                fish_addr=self.fish_addr,
                player_addr=self.player_addr,
            )

        self._ensure_direction_tracking_target()
        now = time.time()
        direction_item = None
        if not self._fish_confirmed_hash:
            direction_item = self._read_control_direction(
                self.fish_addr,
                self._fish_direction_offsets,
                self._blocked_direction_offsets,
            )
        if direction_item is not None:
            move_val, direction_offset, raw_value = direction_item
            if not self._fish_confirmed_hash and self._is_stale_direction_signal(now, direction_offset, raw_value):
                self._blocked_direction_offsets.add(direction_offset)
                debug_log(
                    "REEL_DIRECTION_STALE "
                    f"player={self._fmt_addr(self.player_addr)} fish={self._fmt_addr(self.fish_addr)} "
                    f"direction_offset=0x{direction_offset:X} raw={raw_value:.5f} "
                    f"candidates={self._format_direction_candidates(self.fish_addr)}"
                )
                if self.held_key:
                    self._release_key(self.held_key)
                next_direction = self._read_control_direction(
                    self.fish_addr,
                    self._fish_direction_offsets,
                    self._blocked_direction_offsets,
                )
                if next_direction is None and self._fish_direction_offsets is not None:
                    self._reject_current_fish(f"stale direction field 0x{direction_offset:X}")
                    return ReelingState(active=True, action="target_search", player_addr=self.player_addr)
                return ReelingState(
                    active=True,
                    action="direction_recalibrate",
                    fish_addr=self.fish_addr,
                    player_addr=self.player_addr,
                    fish_pos_offset=direction_offset,
                )
            move_val, stable_source = self._stabilize_move(move_val, DIRECTION_EPS, now)
            action = self._apply_move(move_val, DIRECTION_EPS)
            if now - self._last_step_debug_at >= REEL_DEBUG_INTERVAL_SECONDS:
                self._last_step_debug_at = now
                debug_log(
                    "REEL_STEP "
                    f"player={self._fmt_addr(self.player_addr)} fish={self._fmt_addr(self.fish_addr)} "
                    f"direction_offset=0x{direction_offset:X} direction_value={raw_value:.5f} move={move_val:.3f} "
                    f"source=fish_direction_field/{stable_source}"
                )
            return ReelingState(
                True,
                action=action,
                fish_addr=self.fish_addr,
                player_addr=self.player_addr,
                move_val=move_val,
                fish_pos_offset=direction_offset,
            )

        player_item = self._read_pos_at_offsets(self.player_addr, POS_OFFSETS)
        if player_item is None:
            stale_state = self._hold_last_stable_move(now, "position_unreadable")
            if stale_state is not None:
                return stale_state
            if self.held_key:
                self._release_key(self.held_key)
            return ReelingState(active=True, action="position_unreadable", player_addr=self.player_addr, fish_addr=self.fish_addr)
        fish_item = (
            self._read_confirmed_fish_world_pos(self.fish_addr, player_item[0])
            if self._fish_confirmed_hash
            else self._read_fish_pos_relative(self.fish_addr, player_item[0])
        )
        using_stale_fish_pos = False
        if fish_item is None:
            if (
                self.last_fish_pos is not None
                and self.last_fish_pos_offset is not None
                and now - self.last_good_fish_at <= STALE_FISH_POSITION_SECONDS
            ):
                stale_state = self._hold_last_stable_move(now, "wait_fresh_position")
                if stale_state is not None:
                    return stale_state
                if self.held_key:
                    self._release_key(self.held_key)
                return ReelingState(active=True, action="wait_fresh_position", player_addr=self.player_addr, fish_addr=self.fish_addr)
            if self._fish_confirmed_hash:
                stale_state = self._hold_last_stable_move(now, "position_unreadable")
                if stale_state is not None:
                    return stale_state
                if self.held_key:
                    self._release_key(self.held_key)
                return ReelingState(active=True, action="position_unreadable", player_addr=self.player_addr, fish_addr=self.fish_addr)
            if self._should_reject_unreadable(now):
                self._reject_current_fish("position unreadable")
                return ReelingState(active=True, action="target_search", player_addr=self.player_addr)
            if self.held_key:
                self._release_key(self.held_key)
            return ReelingState(active=True, action="position_unreadable", player_addr=self.player_addr, fish_addr=self.fish_addr)

        player_pos, player_pos_offset = player_item
        fish_pos, fish_pos_offset = fish_item
        using_local_fish_frame = self._is_fishing_local_pos(fish_pos) and not self._is_fishing_local_pos(player_pos)
        if using_local_fish_frame and not self._fish_confirmed_hash:
            self._reject_current_fish("local fish position without live direction", fish_pos)
            return ReelingState(active=True, action="target_search", player_addr=self.player_addr)
        if not using_stale_fish_pos:
            self._reset_unreadable_tracking()
            self.last_fish_pos = fish_pos
            self.last_fish_pos_offset = fish_pos_offset
            self.last_good_fish_at = now
        control_player_pos = (0.0, 0.0, 0.0) if using_local_fish_frame else player_pos
        px, py, pz = control_player_pos
        x, y, z = fish_pos
        distance = math.sqrt((x - px) ** 2 + (y - py) ** 2 + (z - pz) ** 2)
        if not self._fish_confirmed_hash and self._is_stationary_wrong_target(
            now,
            fish_pos,
            distance,
            using_stale_fish_pos or using_local_fish_frame,
        ):
            self._reject_current_fish("stationary target", fish_pos, distance)
            return ReelingState(active=True, action="target_search", player_addr=self.player_addr)
        motion_updated = self._update_fish_velocity(now, fish_pos, using_stale_fish_pos)

        if using_local_fish_frame:
            right = (1.0, 0.0)
            right_source = "fish_local_frame"
        else:
            right = self._read_player_right_vec(self.player_addr)
            right_source = "player_matrix"
            if right is None:
                right = self.last_player_right_vec
                right_source = "cached_player_matrix"
            else:
                self.last_player_right_vec = right
            if right is None:
                stale_state = self._hold_last_stable_move(now, "right_vector_unreadable")
                if stale_state is not None:
                    return stale_state
                if self.held_key:
                    self._release_key(self.held_key)
                return ReelingState(
                    active=True,
                    action="right_vector_unreadable",
                    player_addr=self.player_addr,
                    fish_addr=self.fish_addr,
                )

        lateral = (x - px) * right[0] + (y - py) * right[1]
        raw_velocity_along = self.velocity_xy[0] * right[0] + self.velocity_xy[1] * right[1]
        velocity_along, fish_forward, fish_behind_player = self._orient_projected_velocity_to_fish_side(
            raw_velocity_along,
            right,
            control_player_pos,
            fish_pos,
        )
        move_val, move_source, action_eps = self._movement_from_projected_velocity(
            velocity_along=velocity_along,
            fish_addr=self.fish_addr,
            using_stale_fish_pos=using_stale_fish_pos,
            motion_updated=motion_updated,
        )
        move_val, stable_source = self._stabilize_move(move_val, action_eps, now)
        fish_heading_x: float | None = None
        if now - self._last_step_debug_at >= REEL_DEBUG_INTERVAL_SECONDS:
            self._last_step_debug_at = now
            debug_log(
                "REEL_STEP "
                f"player={self._fmt_addr(self.player_addr)} fish={self._fmt_addr(self.fish_addr)} "
                f"pp=({px:.3f},{py:.3f},{pz:.3f}) fp=({x:.3f},{y:.3f},{z:.3f}) "
                f"offsets=0x{player_pos_offset:X}/0x{fish_pos_offset:X} "
                f"frame={'fish_local' if using_local_fish_frame else 'world'} "
                f"right=({right[0]:.4f},{right[1]:.4f},{right_source}) "
                f"vel=({self.velocity_xy[0]:.4f},{self.velocity_xy[1]:.4f}) dist={distance:.3f} "
                f"heading={fish_heading_x} "
                f"lateral={lateral:.4f} move={move_val:.4f} eps={action_eps:.4f} "
                f"source={move_source}/{stable_source} projected_raw={raw_velocity_along:.4f} "
                f"projected_vel={self._projected_velocity:.4f} "
                f"fish_forward={fish_forward:.4f} fish_behind_player={fish_behind_player} "
                f"projected_eps={self._projected_velocity_eps:.4f} stale={using_stale_fish_pos} "
                f"player_candidates={self._format_pos_candidates(self.player_addr)} "
                f"fish_candidates={self._format_pos_candidates(self.fish_addr)}"
            )
        action = self._apply_move(move_val, action_eps)
        return ReelingState(True, distance, action, self.fish_addr, self.player_addr, lateral, move_val, player_pos_offset, fish_pos_offset)

    def _is_stationary_wrong_target(
        self,
        now: float,
        fish_pos: tuple[float, float, float],
        distance: float,
        using_stale_fish_pos: bool,
    ) -> bool:
        if using_stale_fish_pos or distance < STATIONARY_TARGET_MIN_DISTANCE:
            self._motion_last_pos = fish_pos
            self._motion_stationary_since = now
            return False
        if self._motion_last_pos is None:
            self._motion_last_pos = fish_pos
            self._motion_stationary_since = now
            return False
        dx = fish_pos[0] - self._motion_last_pos[0]
        dy = fish_pos[1] - self._motion_last_pos[1]
        dz = fish_pos[2] - self._motion_last_pos[2]
        moved = math.sqrt(dx * dx + dy * dy + dz * dz)
        if moved > STATIONARY_TARGET_EPS:
            self._motion_last_pos = fish_pos
            self._motion_stationary_since = now
            return False
        if self._motion_stationary_since == 0.0:
            self._motion_stationary_since = now
        return now - self._motion_stationary_since >= STATIONARY_TARGET_SECONDS

    def _read_fish_direction(
        self,
        fish_addr: int,
        allowed_offsets: frozenset[int] | None = None,
        blocked_offsets: set[int] | None = None,
    ) -> tuple[float, int, float] | None:
        for offset, eps, polarity in FISH_DIRECTION_FIELDS:
            if allowed_offsets is not None and offset not in allowed_offsets:
                continue
            if blocked_offsets is not None and offset in blocked_offsets:
                continue
            value = self._f32(fish_addr + offset)
            if value is None or not math.isfinite(value):
                continue
            if abs(value) > FISH_DIRECTION_MAX_ABS:
                continue
            move_val = value * polarity
            if abs(move_val) >= eps:
                return (DIRECTION_MOVE if move_val > 0 else -DIRECTION_MOVE), offset, value
        return None

    def _read_control_direction(
        self,
        fish_addr: int,
        allowed_offsets: frozenset[int] | None = None,
        blocked_offsets: set[int] | None = None,
        update_alignment: bool = True,
    ) -> tuple[float, int, float] | None:
        if not self._fish_confirmed_hash:
            return self._read_fish_direction(fish_addr, allowed_offsets, blocked_offsets)

        values: dict[int, float] = {}
        anchor_sign = 0
        for offset in (FISH_DIRECTION_ANCHOR_OFFSET, *(item[0] for item in FISH_DIRECTION_ADAPTIVE_FIELDS)):
            if blocked_offsets is not None and offset in blocked_offsets:
                continue
            normalized = self._read_normalized_direction_value(fish_addr, offset)
            if normalized is None:
                continue
            values[offset] = normalized
            if offset == FISH_DIRECTION_ANCHOR_OFFSET:
                anchor_sign = self._direction_value_sign(normalized, FISH_DIRECTION_FIELD_CONFIG[offset][0])

        score = 0.0
        dominant: tuple[float, int] | None = None
        used = False
        anchor_value = values.get(FISH_DIRECTION_ANCHOR_OFFSET)
        if anchor_value is not None:
            contribution = self._clamp_direction_contribution(
                anchor_value * FISH_DIRECTION_ANCHOR_WEIGHT / FISH_DIRECTION_ANCHOR_SCALE
            )
            score += contribution
            used = True
            dominant = (abs(contribution), FISH_DIRECTION_ANCHOR_OFFSET)

        for offset, scale, weight in FISH_DIRECTION_ADAPTIVE_FIELDS:
            normalized = values.get(offset)
            if normalized is None:
                continue
            alignment = self._direction_alignment.get(offset, 0)
            if alignment >= FISH_DIRECTION_ALIGNMENT_THRESHOLD:
                relative_polarity = 1
            elif alignment <= -FISH_DIRECTION_ALIGNMENT_THRESHOLD:
                relative_polarity = -1
            else:
                field_sign = self._direction_value_sign(normalized, FISH_DIRECTION_FIELD_CONFIG[offset][0])
                relative_polarity = 1 if anchor_sign and field_sign == anchor_sign else 0
            if relative_polarity == 0:
                continue
            contribution = self._clamp_direction_contribution(normalized * relative_polarity * weight / scale)
            score += contribution
            used = True
            if dominant is None or abs(contribution) > dominant[0]:
                dominant = (abs(contribution), offset)

        if update_alignment and anchor_sign:
            for offset, _scale, _weight in FISH_DIRECTION_ADAPTIVE_FIELDS:
                field_sign = self._direction_value_sign(values.get(offset), FISH_DIRECTION_FIELD_CONFIG[offset][0])
                if field_sign:
                    self._direction_alignment[offset] = self._direction_alignment.get(offset, 0) + anchor_sign * field_sign

        if not used or dominant is None:
            return self._read_fish_direction(fish_addr, allowed_offsets, blocked_offsets)
        if score > FISH_DIRECTION_CONSENSUS_EPS:
            return DIRECTION_MOVE, dominant[1], score
        if score < -FISH_DIRECTION_CONSENSUS_EPS:
            return -DIRECTION_MOVE, dominant[1], score
        return 0.0, dominant[1], score

    def _read_normalized_direction_value(self, fish_addr: int, offset: int) -> float | None:
        config = FISH_DIRECTION_FIELD_CONFIG.get(offset)
        if config is None:
            return None
        _eps, field_polarity = config
        raw = self._f32(fish_addr + offset)
        if raw is None or not math.isfinite(raw):
            return None
        if abs(raw) > FISH_DIRECTION_MAX_ABS:
            return None
        return raw * field_polarity

    @staticmethod
    def _direction_value_sign(value: float | None, eps: float) -> int:
        if value is None:
            return 0
        if value > eps:
            return 1
        if value < -eps:
            return -1
        return 0

    @staticmethod
    def _clamp_direction_contribution(value: float) -> float:
        return max(
            -FISH_DIRECTION_CONSENSUS_MAX_CONTRIBUTION,
            min(FISH_DIRECTION_CONSENSUS_MAX_CONTRIBUTION, value),
        )

    def _ensure_direction_tracking_target(self) -> None:
        if self._direction_watch_addr != self.fish_addr:
            self._reset_direction_tracking(self.fish_addr)

    def _reset_direction_tracking(self, fish_addr: int | None = None) -> None:
        self._direction_watch_addr = fish_addr
        self._direction_watch = {}
        self._direction_alignment = {offset: 0 for offset, _scale, _weight in FISH_DIRECTION_ADAPTIVE_FIELDS}
        self._blocked_direction_offsets = set()

    def _is_stale_direction_signal(self, now: float, offset: int, raw_value: float) -> bool:
        previous = self._direction_watch.get(offset)
        if previous is None:
            self._direction_watch[offset] = (raw_value, now)
            return False
        last_value, changed_at = previous
        if abs(raw_value - last_value) > DIRECTION_STALE_EPS:
            self._direction_watch[offset] = (raw_value, now)
            return False
        return now - changed_at >= DIRECTION_STALE_SECONDS

    def _format_direction_candidates(self, fish_addr: int | None) -> str:
        if fish_addr is None:
            return ""
        parts: list[str] = []
        for offset, _eps, polarity in FISH_DIRECTION_FIELDS:
            value = self._f32(fish_addr + offset)
            if value is None or not math.isfinite(value):
                continue
            if abs(value) > FISH_DIRECTION_MAX_ABS:
                continue
            blocked = "*" if offset in self._blocked_direction_offsets else ""
            parts.append(f"0x{offset:X}{blocked}={value:.5f}/{value * polarity:.5f}")
        return ",".join(parts)

    def _hold_last_stable_move(self, now: float, reason: str) -> ReelingState | None:
        if self._stable_move_sign is None:
            return None
        if self._last_stable_move_at <= 0.0:
            return None
        if now - self._last_stable_move_at > STALE_REELING_INPUT_HOLD_SECONDS:
            return None
        move_val = self._stable_move_sign * DIRECTION_MOVE
        action = self._apply_move(move_val, DIRECTION_EPS)
        return ReelingState(
            active=True,
            action=f"{action}_{reason}",
            fish_addr=self.fish_addr,
            player_addr=self.player_addr,
            move_val=move_val,
            fish_pos_offset=self.last_fish_pos_offset,
        )

    def _apply_move(self, move_val: float, action_eps: float) -> str:
        if move_val > action_eps:
            if self._hold_key("d"):
                self._release_key("a")
            return "hold_d" if self.held_key == "d" else "hold_d_throttled"
        if move_val < -action_eps:
            if self._hold_key("a"):
                self._release_key("d")
            return "hold_a" if self.held_key == "a" else "hold_a_throttled"
        if self.held_key == "d":
            return "hold_d_wait"
        if self.held_key == "a":
            return "hold_a_wait"
        return "center"

    def _should_reject_unreadable(self, now: float) -> bool:
        if self.fish_addr is None:
            return False
        if self._unreadable_addr != self.fish_addr:
            self._unreadable_addr = self.fish_addr
            self._unreadable_since = now
            self._unreadable_count = 1
            return False
        self._unreadable_count += 1
        return (
            self._unreadable_count >= UNREADABLE_REJECT_COUNT
            and now - self._unreadable_since >= UNREADABLE_REJECT_SECONDS
        )

    def _reset_unreadable_tracking(self) -> None:
        self._unreadable_addr = None
        self._unreadable_since = 0.0
        self._unreadable_count = 0

    def _reset_projected_velocity_tracking(self) -> None:
        self._projected_velocity_fish_addr = None
        self._projected_velocity = 0.0
        self._projected_velocity_abs_ema = LATERAL_VELOCITY_EPS
        self._projected_velocity_eps = LATERAL_VELOCITY_EPS

    def _update_fish_velocity(
        self,
        now: float,
        fish_pos: tuple[float, float, float],
        using_stale_fish_pos: bool,
    ) -> bool:
        if using_stale_fish_pos:
            return False
        x, y, _z = fish_pos
        if self.last_fish_xy is None or self.last_time is None:
            self.last_time = now
            self.last_fish_xy = (x, y)
            return False
        dx = x - self.last_fish_xy[0]
        dy = y - self.last_fish_xy[1]
        if math.hypot(dx, dy) <= FISH_POSITION_CHANGE_EPS:
            return False
        dt = max(now - self.last_time, 0.001)
        old_weight = 1.0 - FISH_VELOCITY_NEW_SAMPLE_WEIGHT
        self.velocity_xy = (
            self.velocity_xy[0] * old_weight + dx / dt * FISH_VELOCITY_NEW_SAMPLE_WEIGHT,
            self.velocity_xy[1] * old_weight + dy / dt * FISH_VELOCITY_NEW_SAMPLE_WEIGHT,
        )
        self.last_time = now
        self.last_fish_xy = (x, y)
        return True

    def _reset_move_stabilizer(self) -> None:
        self._stable_move_sign = None
        self._last_stable_move_at = 0.0
        self._pending_move_sign = None
        self._pending_move_since = 0.0
        self._pending_move_count = 0

    def _stabilize_move(self, move_val: float, action_eps: float, now: float) -> tuple[float, str]:
        sign = self._move_sign(move_val, action_eps)
        if sign == 0:
            self._pending_move_sign = None
            self._pending_move_count = 0
            if self._stable_move_sign is None:
                return 0.0, "stable_center"
            return self._stable_move_sign * DIRECTION_MOVE, "hold_stable_center"
        if self._stable_move_sign is None:
            self._stable_move_sign = sign
            self._last_stable_move_at = now
            self._pending_move_sign = None
            self._pending_move_count = 0
            return sign * DIRECTION_MOVE, "stable_initial"
        if sign == self._stable_move_sign:
            self._last_stable_move_at = now
            self._pending_move_sign = None
            self._pending_move_count = 0
            return sign * DIRECTION_MOVE, "stable_same"
        if sign != self._pending_move_sign:
            self._pending_move_sign = sign
            self._pending_move_since = now
            self._pending_move_count = 1
            return self._stable_move_sign * DIRECTION_MOVE, "switch_pending"
        self._pending_move_count += 1
        pending_age = now - self._pending_move_since
        if (
            self._pending_move_count >= DIRECTION_SWITCH_CONFIRM_SAMPLES
            and pending_age >= DIRECTION_SWITCH_CONFIRM_SECONDS
        ):
            self._stable_move_sign = sign
            self._last_stable_move_at = now
            self._pending_move_sign = None
            self._pending_move_count = 0
            return sign * DIRECTION_MOVE, "switch_confirmed"
        return self._stable_move_sign * DIRECTION_MOVE, "switch_pending"

    @staticmethod
    def _move_sign(move_val: float, action_eps: float) -> int:
        if move_val > action_eps:
            return 1
        if move_val < -action_eps:
            return -1
        return 0

    def _movement_from_projected_velocity(
        self,
        velocity_along: float,
        fish_addr: int | None,
        using_stale_fish_pos: bool,
        motion_updated: bool,
    ) -> tuple[float, str, float]:
        if using_stale_fish_pos:
            return 0.0, "wait_fresh_position", DIRECTION_EPS

        if fish_addr is None or self._projected_velocity_fish_addr != fish_addr:
            self._projected_velocity_fish_addr = fish_addr
            self._projected_velocity = 0.0
            self._projected_velocity_abs_ema = LATERAL_VELOCITY_EPS
            self._projected_velocity_eps = LATERAL_VELOCITY_EPS
            return 0.0, "motion_warmup", DIRECTION_EPS
        if not motion_updated:
            return 0.0, "wait_fish_motion", DIRECTION_EPS

        self._projected_velocity = velocity_along
        self._projected_velocity_abs_ema = (
            self._projected_velocity_abs_ema * (1.0 - PROJECTED_VELOCITY_EPS_WEIGHT)
            + abs(velocity_along) * PROJECTED_VELOCITY_EPS_WEIGHT
        )
        self._projected_velocity_eps = max(
            PROJECTED_VELOCITY_MIN_EPS,
            min(PROJECTED_VELOCITY_MAX_EPS, self._projected_velocity_abs_ema),
        )
        if velocity_along > self._projected_velocity_eps:
            return -DIRECTION_MOVE, "reel_against_right_motion", DIRECTION_EPS
        if velocity_along < -self._projected_velocity_eps:
            return DIRECTION_MOVE, "reel_against_left_motion", DIRECTION_EPS
        return 0.0, "wait_fish_motion", DIRECTION_EPS

    @staticmethod
    def _fish_forward_distance(
        right: tuple[float, float],
        player_pos: tuple[float, float, float],
        fish_pos: tuple[float, float, float],
    ) -> float:
        forward = (-right[1], right[0])
        return (fish_pos[0] - player_pos[0]) * forward[0] + (fish_pos[1] - player_pos[1]) * forward[1]

    @staticmethod
    def _orient_projected_velocity_to_fish_side(
        velocity_along: float,
        right: tuple[float, float],
        player_pos: tuple[float, float, float],
        fish_pos: tuple[float, float, float],
    ) -> tuple[float, float, bool]:
        fish_forward = MemoryReelingTracker._fish_forward_distance(right, player_pos, fish_pos)
        fish_behind_player = fish_forward < -FISH_BEHIND_PLAYER_FORWARD_EPS
        if fish_behind_player:
            return -velocity_along, fish_forward, True
        return velocity_along, fish_forward, False

    def _reject_current_fish(
        self,
        reason: str,
        fish_pos: tuple[float, float, float] | None = None,
        distance: float | None = None,
    ) -> None:
        if self.fish_addr is not None:
            self._rejected_fish_addrs.add(self.fish_addr)
            position = "unreadable" if fish_pos is None else f"({fish_pos[0]:.2f},{fish_pos[1]:.2f},{fish_pos[2]:.2f})"
            distance_text = "unknown" if distance is None else f"{distance:.2f}"
            self._log(
                "Memory reeling rejected fish target: "
                f"{reason} addr={self._fmt_addr(self.fish_addr)} "
                f"pos={position} distance={distance_text}"
            )
        if self.held_key:
            self._release_key(self.held_key)
        self.fish_addr = None
        self._fish_direction_offsets = FISH_PRIMARY_DIRECTION_OFFSETS
        self._fish_confirmed_hash = False
        self._reset_direction_tracking()
        self.last_fish_xy = None
        self.last_fish_pos = None
        self.last_fish_pos_offset = None
        self.last_good_fish_at = 0.0
        self.last_player_right_vec = None
        self.velocity_xy = (0.0, 0.0)
        self._motion_last_pos = None
        self._motion_stationary_since = 0.0
        self._reset_unreadable_tracking()
        self._reset_projected_velocity_tracking()
        self._reset_move_stabilizer()
        self._last_fish_search_at = 0.0
        self._last_deep_fish_search_at = 0.0

    def _is_rejected_fish(self, ent_addr: int) -> bool:
        return ent_addr in self._rejected_fish_addrs

    def _hold_key(self, key: str) -> bool:
        if self.held_key == key:
            return True
        manual = self._manual_input_enabled()
        now = time.time()
        if self.held_key and self.held_key != key and now - self._last_key_switch_at < KEY_SWITCH_MIN_SECONDS:
            debug_log(
                f"REEL_KEY_SWITCH_THROTTLED requested={key} held={self.held_key} "
                f"age={now - self._last_key_switch_at:.3f}"
            )
            return False
        previous_key = self.held_key
        if self.held_key and self.held_key != key:
            if manual:
                debug_log(f"REEL_MANUAL_KEY_UP key={self.held_key} next={key}")
            else:
                self.input_controller.key_up(self.held_key)
            self.held_key = None
        if manual:
            debug_log(f"REEL_MANUAL_KEY_DOWN key={key} previous={previous_key}")
        else:
            if self.input_controller.key_down(key) is False:
                self._last_key_switch_at = time.time()
                return False
            debug_log(f"REEL_KEY_DOWN key={key} previous={previous_key}")
        self.held_key = key
        self._last_key_switch_at = time.time()
        return True

    def _release_key(self, key: str) -> None:
        manual = self._manual_input_enabled()
        if self.held_key == key:
            if manual:
                debug_log(f"REEL_MANUAL_KEY_UP key={key}")
            else:
                self.input_controller.key_up(key)
                debug_log(f"REEL_KEY_UP key={key}")
            self.held_key = None
            self._last_key_switch_at = time.time()
        elif self.held_key is None and not manual:
            self.input_controller.key_up(key)

    def _input_allowed(self) -> bool:
        is_allowed = getattr(self.input_controller, "is_input_allowed", None)
        if is_allowed is None:
            return True
        now = time.time()
        if now - self._last_input_allowed_check_at >= 0.02:
            self._input_allowed_cached = bool(is_allowed())
            self._last_input_allowed_check_at = now
        return self._input_allowed_cached

    def _open_manual_dump(self) -> None:
        if self._manual_dump_file is not None:
            return
        dump_dir = LOG_DIR / "reeling_manual"
        dump_dir.mkdir(parents=True, exist_ok=True)
        stamp = datetime.now().strftime("%Y%m%d_%H%M%S")
        self._manual_dump_path = dump_dir / f"reeling_manual_{stamp}.jsonl"
        self._manual_dump_file = self._manual_dump_path.open("w", encoding="utf-8")
        self._log(f"Manual reeling mode: bot A/D input disabled, dump={self._manual_dump_path}")
        self._write_manual_record(
            {
                "type": "session_start",
                "created_at_utc": datetime.now(timezone.utc).isoformat(),
                "process": self.process_name,
                "manual_input_mode": True,
                "label_meaning": {"-1": "A", "0": "none", "1": "D", "2": "A+D"},
            }
        )

    def _close_manual_dump(self) -> None:
        dump_file = getattr(self, "_manual_dump_file", None)
        if dump_file is None:
            return
        try:
            self._write_manual_record(
                {
                    "type": "session_stop",
                    "created_at_utc": datetime.now(timezone.utc).isoformat(),
                    "bot_key": self.held_key,
                }
            )
        finally:
            dump_file.close()
            self._manual_dump_file = None

    def _write_manual_dump(self, state: ReelingState) -> None:
        if not self._manual_input_enabled():
            return
        now = time.time()
        if now - getattr(self, "_last_manual_dump_at", 0.0) < MANUAL_REELING_DUMP_INTERVAL_SECONDS:
            return
        self._last_manual_dump_at = now
        try:
            if getattr(self, "_manual_dump_file", None) is None:
                self._open_manual_dump()
            actual_label, actual_a, actual_d = self._keyboard_snapshot()
            selected_direction = self._manual_selected_direction()
            record: dict[str, object] = {
                "type": "sample",
                "t": now,
                "action": state.action,
                "move_val": state.move_val,
                "distance": state.distance,
                "lateral": state.lateral,
                "bot_key": self.held_key,
                "bot_label": self._key_label(self.held_key),
                "actual_label": actual_label,
                "actual_a": actual_a,
                "actual_d": actual_d,
                "player_addr": self._fmt_addr(self.player_addr),
                "fish_addr": self._fmt_addr(self.fish_addr),
                "player_pos_offset": state.player_pos_offset,
                "fish_pos_offset": state.fish_pos_offset,
                "fish_confirmed_hash": self._fish_confirmed_hash,
                "blocked_direction_offsets": [f"0x{offset:X}" for offset in sorted(self._blocked_direction_offsets)],
                "stable_move_sign": self._stable_move_sign,
                "pending_move_sign": self._pending_move_sign,
                "pending_move_count": self._pending_move_count,
                "selected_direction": selected_direction,
                "direction_values": self._manual_direction_values(),
                "player_pos": self._manual_player_pos(),
                "fish_pos": self._manual_fish_pos(),
            }
            if now - getattr(self, "_last_manual_memory_dump_at", 0.0) >= MANUAL_REELING_MEMORY_DUMP_INTERVAL_SECONDS:
                self._last_manual_memory_dump_at = now
                record["memory"] = {
                    "bytes": MANUAL_REELING_MEMORY_DUMP_BYTES,
                    "player_b64": self._read_memory_b64(self.player_addr, MANUAL_REELING_MEMORY_DUMP_BYTES),
                    "fish_b64": self._read_memory_b64(self.fish_addr, MANUAL_REELING_MEMORY_DUMP_BYTES),
                }
            self._write_manual_record(record)
        except Exception as exc:
            debug_log(f"REEL_MANUAL_DUMP_FAILED {exc}")

    def _write_manual_record(self, record: dict[str, object]) -> None:
        dump_file = getattr(self, "_manual_dump_file", None)
        if dump_file is None:
            return
        json.dump(record, dump_file, ensure_ascii=False, separators=(",", ":"))
        dump_file.write("\n")
        dump_file.flush()

    def _manual_selected_direction(self) -> dict[str, object] | None:
        if self.fish_addr is None:
            return None
        selected = self._read_control_direction(
            self.fish_addr,
            self._fish_direction_offsets,
            self._blocked_direction_offsets,
            update_alignment=False,
        )
        if selected is None:
            return None
        move_val, offset, value = selected
        return {"offset": f"0x{offset:X}", "score": value, "move": move_val}

    def _manual_direction_values(self) -> dict[str, float | None]:
        if self.fish_addr is None:
            return {}
        values: dict[str, float | None] = {}
        for offset, _eps, polarity in FISH_DIRECTION_FIELDS:
            raw = self._f32(self.fish_addr + offset)
            values[f"0x{offset:X}"] = raw * polarity if raw is not None and math.isfinite(raw) else None
        return values

    def _manual_player_pos(self) -> list[float] | None:
        if self.player_addr is None:
            return None
        item = self._read_pos_at_offsets(self.player_addr, POS_OFFSETS)
        return None if item is None else [float(value) for value in item[0]]

    def _manual_fish_pos(self) -> list[float] | None:
        if self.fish_addr is None:
            return None
        player_pos = self._manual_player_pos()
        player_pos_tuple = None if player_pos is None else (player_pos[0], player_pos[1], player_pos[2])
        item = (
            self._read_confirmed_fish_world_pos(self.fish_addr, player_pos_tuple)
            if self._fish_confirmed_hash and player_pos_tuple is not None
            else self._read_fish_pos_relative(self.fish_addr, player_pos_tuple)
        )
        return None if item is None else [float(value) for value in item[0]]

    def _read_memory_b64(self, addr: int | None, size: int) -> str | None:
        if addr is None:
            return None
        data = self._read(addr, size)
        if data is None:
            return None
        return base64.b64encode(data).decode("ascii")

    @staticmethod
    def _key_label(key: str | None) -> int:
        if key == "a":
            return -1
        if key == "d":
            return 1
        return 0

    @staticmethod
    def _keyboard_snapshot() -> tuple[int, bool, bool]:
        if not hasattr(ctypes, "windll"):
            return 0, False, False
        try:
            user32 = ctypes.windll.user32
            a_down = bool(user32.GetAsyncKeyState(VK_A) & 0x8000)
            d_down = bool(user32.GetAsyncKeyState(VK_D) & 0x8000)
        except Exception:
            return 0, False, False
        if a_down and d_down:
            return 2, True, True
        if a_down:
            return -1, True, False
        if d_down:
            return 1, False, True
        return 0, False, False

    def _get_pid(self) -> int | None:
        wanted = self.process_name.lower()
        for proc in psutil.process_iter(["name"]):
            if (proc.info.get("name") or "").lower() == wanted:
                return proc.pid
        return None

    def _resolve_targets(self) -> None:
        try:
            self.replay_interface = self._find_replay_interface_global()
            self.player_addr = self._find_cped()
            self.fish_addr = self._find_fish_addr_replay() or self._find_fish_addr()
            self._log(
                "Memory reeling targets: "
                f"replay={self._fmt_addr(self.replay_interface)} "
                f"player={self._fmt_addr(self.player_addr)} "
                f"fish={self._fmt_addr(self.fish_addr)}"
            )
        except Exception as exc:
            self._log(f"Memory reeling resolver failed: {exc}")

    def _retry_find_fish(self, *, allow_deep_search: bool = True) -> None:
        if self.fish_addr is not None:
            return
        now = time.time()
        if now - self._last_fish_search_at < FISH_FAST_RETRY_SECONDS:
            return
        self._last_fish_search_at = now
        try:
            self.fish_addr = self._find_fish_addr_replay()
            if (
                allow_deep_search
                and self.fish_addr is None
                and now - self._last_deep_fish_search_at >= FISH_DEEP_RETRY_SECONDS
            ):
                self._last_deep_fish_search_at = now
                self.fish_addr = self._find_fish_addr()
            if self.fish_addr:
                self._log(f"Memory reeling fish found: {self._fmt_addr(self.fish_addr)}")
            elif now - self._last_search_log_at > 3.0:
                self._last_search_log_at = now
                self._log("Memory reeling fish search: not found yet")
        except Exception as exc:
            if now - self._last_search_log_at > 3.0:
                self._last_search_log_at = now
                self._log(f"Memory reeling fish search failed: {exc}")

    def _retry_find_targets(self) -> None:
        now = time.time()
        if now - self._last_target_search_at < 1.0:
            return
        self._last_target_search_at = now
        try:
            if self.replay_interface is None:
                self.replay_interface = self._find_replay_interface_global()
            self.player_addr = self._find_cped()
            if self.player_addr:
                if self.fish_addr is None:
                    self.fish_addr = self._find_fish_addr_replay() or self._find_fish_addr()
                self._log(
                    "Memory reeling targets retry: "
                    f"replay={self._fmt_addr(self.replay_interface)} "
                    f"player={self._fmt_addr(self.player_addr)} "
                    f"fish={self._fmt_addr(self.fish_addr)}"
                )
            elif now - self._last_search_log_at > 3.0:
                self._last_search_log_at = now
                self._log("Memory reeling target search: player not found yet")
        except Exception as exc:
            if now - self._last_search_log_at > 3.0:
                self._last_search_log_at = now
                self._log(f"Memory reeling target search failed: {exc}")

    @staticmethod
    def _fmt_addr(addr: int | None) -> str:
        return "None" if addr is None else f"0x{addr:X}"

    def _read(self, addr: int, size: int) -> bytes | None:
        if not self.handle or addr <= 0:
            return None
        buffer = ctypes.create_string_buffer(size)
        nread = ctypes.c_size_t()
        ok = ctypes.windll.kernel32.ReadProcessMemory(self.handle, ctypes.c_void_p(addr), buffer, size, ctypes.byref(nread))
        if not ok or nread.value != size:
            return None
        return buffer.raw

    def _u64(self, addr: int) -> int | None:
        data = self._read(addr, 8)
        return None if data is None else struct.unpack("<Q", data)[0]

    def _f32(self, addr: int) -> float | None:
        data = self._read(addr, 4)
        return None if data is None else struct.unpack("<f", data)[0]

    def _i32(self, addr: int) -> int | None:
        data = self._read(addr, 4)
        return None if data is None else struct.unpack("<i", data)[0]

    def _u32(self, addr: int) -> int | None:
        data = self._read(addr, 4)
        return None if data is None else struct.unpack("<I", data)[0]

    def _u8(self, addr: int) -> int | None:
        data = self._read(addr, 1)
        return None if data is None else data[0]

    def _is_finished_fish(self, fish_addr: int) -> bool:
        active = self._u8(fish_addr + FISH_REELING_ACTIVE_OFFSET)
        return active is not None and active != FISH_REELING_ACTIVE_VALUE

    def _read_pos_at_offsets(self, addr: int, offsets: tuple[int, ...]) -> tuple[tuple[float, float, float], int] | None:
        for offset in offsets:
            x = self._f32(addr + offset)
            y = self._f32(addr + offset + 4)
            z = self._f32(addr + offset + 8)
            if x is None or y is None or z is None:
                continue
            if all(math.isfinite(v) and abs(v) < 100000.0 for v in (x, y, z)):
                return (x, y, z), offset
        return None

    def _read_pos(self, addr: int) -> tuple[float, float, float] | None:
        item = self._read_pos_at_offsets(addr, POS_OFFSETS)
        return None if item is None else item[0]

    def _format_pos_candidates(self, addr: int | None) -> str:
        if addr is None:
            return "None"
        items: list[str] = []
        for offset in (0x30, 0x40, 0x50, 0x60, 0x90, 0x110, 0x120, 0x130, 0x160):
            x = self._f32(addr + offset)
            y = self._f32(addr + offset + 4)
            z = self._f32(addr + offset + 8)
            if x is None or y is None or z is None:
                items.append(f"0x{offset:X}=unreadable")
                continue
            finite = all(math.isfinite(v) and abs(v) < 100000.0 for v in (x, y, z))
            items.append(f"0x{offset:X}=({x:.2f},{y:.2f},{z:.2f},{'ok' if finite else 'bad'})")
        return "[" + "; ".join(items) + "]"

    def _read_player_pos(self, addr: int) -> tuple[float, float, float] | None:
        item = self._read_pos_at_offsets(addr, POS_OFFSETS)
        return None if item is None else item[0]

    def _read_fish_pos(self, addr: int) -> tuple[float, float, float] | None:
        item = self._read_pos_at_offsets(addr, FISH_POS_OFFSETS)
        return None if item is None else item[0]

    def _read_fish_pos_relative(
        self,
        addr: int,
        player_pos: tuple[float, float, float] | None,
        max_dist: float = TRACK_MAX_DIST,
    ) -> tuple[tuple[float, float, float], int] | None:
        px, py, pz = player_pos if player_pos is not None else (0.0, 0.0, 0.0)
        offsets = FISH_POS_OFFSETS
        if self.last_fish_pos_offset in FISH_POS_OFFSETS:
            offsets = (self.last_fish_pos_offset,) + tuple(offset for offset in FISH_POS_OFFSETS if offset != self.last_fish_pos_offset)
        for offset in offsets:
            item = self._read_pos_at_offsets(addr, (offset,))
            if item is None:
                continue
            pos, _ = item
            x, y, z = pos
            if abs(x) + abs(y) + abs(z) < 0.01:
                continue
            if abs(x) + abs(y) < 0.5:
                continue
            if self._is_invalid_fish_pos(pos):
                continue
            if self._is_fishing_local_pos(pos):
                return pos, offset
            if player_pos is None:
                continue
            dist = math.sqrt((x - px) ** 2 + (y - py) ** 2 + (z - pz) ** 2)
            if 1.0 < dist < max_dist:
                return pos, offset
        return None

    def _read_confirmed_fish_world_pos(
        self,
        addr: int,
        player_pos: tuple[float, float, float],
    ) -> tuple[tuple[float, float, float], int] | None:
        item = self._read_pos_at_offsets(addr, (FISH_WORLD_POS_OFFSET,))
        if item is None:
            return None
        pos, offset = item
        x, y, z = pos
        if abs(x) + abs(y) + abs(z) < 0.01:
            return None
        if abs(x) + abs(y) < 0.5:
            return None
        if self._is_invalid_fish_pos(pos):
            return None
        px, py, pz = player_pos
        dist = math.sqrt((x - px) ** 2 + (y - py) ** 2 + (z - pz) ** 2)
        if 1.0 < dist < CONFIRMED_FISH_MAX_DIST:
            return pos, offset
        return None

    @staticmethod
    def _is_fishing_local_pos(pos: tuple[float, float, float]) -> bool:
        x, y, z = pos
        return (
            FISH_LOCAL_X_RANGE[0] <= x <= FISH_LOCAL_X_RANGE[1]
            and FISH_LOCAL_Y_RANGE[0] <= y <= FISH_LOCAL_Y_RANGE[1]
            and FISH_LOCAL_Z_RANGE[0] <= z <= FISH_LOCAL_Z_RANGE[1]
            and abs(x) + abs(y) >= 0.5
        )

    @staticmethod
    def _is_invalid_fish_pos(pos: tuple[float, float, float]) -> bool:
        return all(-1.05 <= value <= -0.95 for value in pos)

    def _is_ptr(self, addr: int | None) -> bool:
        return bool(addr and PTR_MIN <= addr <= PTR_MAX)

    def _get_modules(self) -> list[ModuleInfo]:
        if self.pid is None:
            return []
        kernel32 = ctypes.windll.kernel32
        snapshot = kernel32.CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, self.pid)
        if snapshot == INVALID_HANDLE_VALUE:
            return []
        entry = MODULEENTRY32()
        entry.dwSize = ctypes.sizeof(MODULEENTRY32)
        modules: list[ModuleInfo] = []
        try:
            ok = kernel32.Module32First(snapshot, ctypes.byref(entry))
            while ok:
                name = entry.szModule.decode("mbcs", errors="ignore").lower()
                modules.append(ModuleInfo(name, ctypes.addressof(entry.modBaseAddr.contents), int(entry.modBaseSize)))
                ok = kernel32.Module32Next(snapshot, ctypes.byref(entry))
        finally:
            kernel32.CloseHandle(snapshot)
        return modules

    def _pattern_scan(self, base: int, size: int, pattern: tuple[int | None, ...]) -> int | None:
        if not self.handle:
            return None
        plen = len(pattern)
        prev = b""
        end = base + size
        cur = base
        while cur < end:
            chunk = min(MAX_SCAN_REGION, end - cur)
            data = self._read(cur, chunk)
            if data:
                combined = prev + data
                for i in range(0, len(combined) - plen + 1):
                    if all(pb is None or combined[i + j] == pb for j, pb in enumerate(pattern)):
                        return cur - len(prev) + i
                prev = combined[-plen:]
            cur += chunk
        return None

    def _find_cped(self) -> int | None:
        gta = self._gta_module()
        if gta is None:
            return None
        for pattern, rel_off, insn_len, offsets in WORLD_PATTERNS:
            hit = self._pattern_scan(gta.base, gta.size, pattern)
            if hit is None:
                continue
            rel = self._i32(hit + rel_off)
            if rel is None:
                continue
            value = self._u64(hit + insn_len + rel)
            for offset in offsets:
                value = self._u64(value + offset) if self._is_ptr(value) else None
            if self._is_valid_cped(value, gta):
                return value
        return None

    def _find_replay_interface_global(self) -> int | None:
        gta = self._gta_module()
        if gta is None:
            return None
        hit = self._pattern_scan(gta.base, gta.size, REPLAY_IFACE_PATTERN)
        if hit is None:
            return None
        rel = self._i32(hit + 3)
        if rel is None:
            return None
        value = self._u64(hit + 7 + rel)
        return value if self._is_ptr(value) else None

    def _is_valid_cped(self, cped_addr: int | None, gta: ModuleInfo) -> bool:
        if not self._is_ptr(cped_addr):
            return False
        vtable = self._u64(cped_addr)
        return bool(
            vtable
            and gta.base <= vtable < gta.base + gta.size
            and self._read_pos(cped_addr) is not None
            and self._read_player_right_vec(cped_addr) is not None
        )

    def _read_entity_hash(self, ent_addr: int) -> int | None:
        # GTA entities usually store the model hash on the archetype/model-info
        # object, not directly on the entity. The original bot's decompiled
        # locals also show an intermediate "archetype" value here.
        first_generic: int | None = None
        for archetype_off in (0x20, 0x18, 0x28, 0x10):
            archetype = self._u64(ent_addr + archetype_off)
            if not self._is_ptr(archetype):
                continue
            for hash_off in (0x18, 0x20, 0x24, 0x10, 0x8):
                value = self._u32(archetype + hash_off)
                if value == FISH_MODEL_HASH:
                    return value
            for hash_off in (0x18, 0x20, 0x24, 0x10, 0x8):
                value = self._u32(archetype + hash_off)
                if value is not None and 0 < value < 0x80000000 and first_generic is None:
                    first_generic = value
        if first_generic is not None:
            return first_generic
        for offset in (0x20, 0x18, 0x10):
            value = self._u32(ent_addr + offset)
            if value is not None and 0 < value < 0x80000000:
                return value
        return None

    def _find_fish_addr_replay(self) -> int | None:
        player_pos = self._read_pos(self.player_addr) if self.player_addr else None
        p_iface = self.replay_interface or self._find_replay_interface_global()
        if p_iface is None:
            debug_log(f"REPLAY_SEARCH skipped p_iface={self._fmt_addr(p_iface)} player_pos={player_pos}")
            return None
        if player_pos is None:
            return self._find_fish_addr_replay_hash_only(p_iface) or self._find_fish_addr_replay_broad(p_iface, None)
        ped_candidates: list[tuple[int, int, int, int, int | None, int | None]] = []
        for ri_off in (0x8, 0x20, 0x18, 0x10, 0x28):
            p_ped_iface = self._u64(p_iface + ri_off)
            if not self._is_ptr(p_ped_iface):
                ped_candidates.append((ri_off, 0, 0, p_ped_iface or 0, None, None))
                continue
            for list_off, max_off in ((0x0, 0x18), (0x8, 0x18), (0x100, 0x108), (0x108, 0x110), (0x110, 0x118)):
                p_ped_list = self._u64(p_ped_iface + list_off)
                max_peds = self._i32(p_ped_iface + max_off)
                ped_candidates.append((ri_off, list_off, max_off, p_ped_iface, p_ped_list, max_peds))
                if self._is_ptr(p_ped_list) and p_ped_list % 8 == 0 and max_peds is not None and 0 < max_peds <= 2048:
                    break
            if (
                ped_candidates
                and self._is_ptr(ped_candidates[-1][4])
                and ped_candidates[-1][4] % 8 == 0
                and ped_candidates[-1][5] is not None
                and 0 < ped_candidates[-1][5] <= 2048
            ):
                break
        chosen_ped = next(
            (
                candidate
                for candidate in ped_candidates
                if self._is_ptr(candidate[4]) and candidate[4] % 8 == 0 and candidate[5] is not None and 0 < candidate[5] <= 2048
            ),
            None,
        )
        if chosen_ped is None:
            chosen_ped = next(
                (
                    candidate
                    for candidate in ped_candidates
                    if self._is_ptr(candidate[4]) and candidate[4] % 8 == 0
                ),
                None,
            )
        if chosen_ped is None:
            p_ped_iface = None
            p_ped_list = None
            max_peds = None
            ri_off = list_off = max_off = 0
        else:
            ri_off, list_off, max_off, p_ped_iface, p_ped_list, max_peds = chosen_ped
            if max_peds is None or not (0 < max_peds <= 2048):
                max_peds = 512
        if not self._is_ptr(p_ped_list):
            debug_log(
                "REPLAY_SEARCH no_ped_list "
                f"p_iface={self._fmt_addr(p_iface)} ped_iface={self._fmt_addr(p_ped_iface)} "
                f"ped_list={self._fmt_addr(p_ped_list)} max_peds={max_peds} "
                f"candidates="
                + " | ".join(
                    f"ri=0x{r:X} list=0x{lo:X} max=0x{mo:X} iface={self._fmt_addr(iface)} "
                    f"list_ptr={self._fmt_addr(lst)} max_peds={mx}"
                    for r, lo, mo, iface, lst, mx in ped_candidates
                )
            )
            return None
        px, py, pz = player_pos
        best_signal: tuple[float, int, int | None, tuple[float, float, float], str] | None = None
        debug_candidates: list[tuple[float, int, int | None, tuple[float, float, float], int, str]] = []
        limit = min(max_peds or 256, 2048)
        for i in range(limit):
            ent_addr = self._u64(p_ped_list + i * 0x10)
            if not self._is_ptr(ent_addr) or ent_addr == self.player_addr or self._is_rejected_fish(ent_addr):
                continue
            signal = self._read_fish_candidate_signal(ent_addr, player_pos)
            if signal is not None:
                signal_d2, signal_hash, signal_pos, signal_source = signal
                debug_candidates.append((signal_d2, ent_addr, signal_hash, signal_pos, i, signal_source))
                if best_signal is None or self._fish_signal_key(signal) < self._fish_signal_key(
                    (best_signal[0], best_signal[2], best_signal[3], best_signal[4])
                ):
                    best_signal = (signal_d2, ent_addr, signal_hash, signal_pos, signal_source)
                continue
            pos = self._read_pos(ent_addr)
            if pos is None:
                continue
            dx, dy, dz = pos[0] - px, pos[1] - py, pos[2] - pz
            d2 = dx * dx + dy * dy + dz * dz
            if not (1.0 < d2 < TRACK_MAX_DIST * TRACK_MAX_DIST):
                continue
            entity_hash = self._read_entity_hash(ent_addr)
            debug_candidates.append((d2, ent_addr, entity_hash, pos, i, "nearby"))
        chosen = best_signal
        closest = sorted(debug_candidates, key=lambda item: item[0])[:12]
        debug_log(
            "REPLAY_SEARCH "
            f"p_iface={self._fmt_addr(p_iface)} ped_iface={self._fmt_addr(p_ped_iface)} "
            f"ri_off=0x{ri_off:X} list_off=0x{list_off:X} max_off=0x{max_off:X} "
            f"ped_list={self._fmt_addr(p_ped_list)} max_peds={max_peds} limit={limit} "
            f"chosen={self._fmt_addr(None if chosen is None else chosen[1])} "
            f"candidates="
            + " | ".join(
                f"i={i} addr={self._fmt_addr(addr)} hash={h} d={math.sqrt(d2):.2f} "
                f"source={source} pos=({pos[0]:.2f},{pos[1]:.2f},{pos[2]:.2f})"
                for d2, addr, h, pos, i, source in closest
            )
        )
        if chosen is not None:
            self._set_fish_signal_profile(chosen[2])
            return chosen[1]
        return self._find_fish_addr_replay_hash_only(p_iface) or self._find_fish_addr_replay_broad(p_iface, player_pos)

    def _find_fish_addr_replay_hash_only(self, p_iface: int) -> int | None:
        for iface_off, list_off, stride, index in list(self._replay_broad_paths):
            iface = self._u64(p_iface + iface_off)
            if not self._is_ptr(iface):
                continue
            p_list = self._u64(iface + list_off)
            if not self._is_ptr(p_list):
                continue
            for delta in (0, -1, 1, -2, 2, -4, 4, -8, 8):
                idx = index + delta
                if idx < 0 or idx >= 2048:
                    continue
                ent_addr = self._u64(p_list + idx * stride)
                if not self._is_ptr(ent_addr) or ent_addr == self.player_addr or self._is_rejected_fish(ent_addr):
                    continue
                if self._read_entity_hash(ent_addr) == FISH_MODEL_HASH and not self._is_finished_fish(ent_addr):
                    self._set_fish_signal_profile(FISH_MODEL_HASH)
                    self._remember_replay_broad_path(iface_off, list_off, stride, idx)
                    debug_log(
                        "REPLAY_HASH_CACHED "
                        f"chosen={self._fmt_addr(ent_addr)} iface_off=0x{iface_off:X} "
                        f"list_off=0x{list_off:X} stride=0x{stride:X} i={idx}"
                    )
                    return ent_addr

        hits: list[tuple[int, int, int, int]] = []
        for iface_off in (0x8, 0x20, 0x18, 0x10, 0x28):
            iface = self._u64(p_iface + iface_off)
            if not self._is_ptr(iface):
                continue
            for list_off, max_off in ((0x0, 0x18), (0x8, 0x18), (0x30, 0x38), (0x100, 0x108), (0x108, 0x110), (0x110, 0x118)):
                p_list = self._u64(iface + list_off)
                max_peds = self._i32(iface + max_off)
                if not self._is_ptr(p_list) or p_list % 8 != 0:
                    continue
                limit = min(max_peds if max_peds is not None and 0 < max_peds <= 2048 else 512, 2048)
                for index in range(limit):
                    ent_addr = self._u64(p_list + index * 0x10)
                    if not self._is_ptr(ent_addr) or ent_addr == self.player_addr or self._is_rejected_fish(ent_addr):
                        continue
                    if self._read_entity_hash(ent_addr) != FISH_MODEL_HASH:
                        continue
                    if self._is_finished_fish(ent_addr):
                        continue
                    self._set_fish_signal_profile(FISH_MODEL_HASH)
                    hits.append((ent_addr, iface_off, list_off, index))
                    self._remember_replay_broad_path(iface_off, list_off, 0x10, index)
                    debug_log(
                        "REPLAY_HASH_ONLY "
                        f"chosen={self._fmt_addr(ent_addr)} iface_off=0x{iface_off:X} "
                        f"list_off=0x{list_off:X} i={index} hits={len(hits)}"
                    )
                    return ent_addr
        debug_log("REPLAY_HASH_ONLY no fish hash found")
        return None

    def _find_fish_addr_replay_broad(self, p_iface: int, player_pos: tuple[float, float, float] | None) -> int | None:
        cached = self._find_fish_addr_replay_broad_cached(p_iface, player_pos)
        if cached is not None:
            return cached
        best: tuple[float, int, int | None, int, int, int, int, tuple[float, float, float], str] | None = None
        checked_lists = 0
        fish_hits: list[tuple[float, int, int | None, int, int, int, int, tuple[float, float, float], str]] = []
        for iface_off in range(0, 0x50, 0x8):
            iface = self._u64(p_iface + iface_off)
            if not self._is_ptr(iface):
                continue
            for list_off in range(0, 0x140, 0x8):
                p_list = self._u64(iface + list_off)
                if not self._is_ptr(p_list):
                    continue
                checked_lists += 1
                for stride in (0x8, 0x10):
                    for i in range(REPLAY_BROAD_SCAN_LIMIT):
                        ent_addr = self._u64(p_list + i * stride)
                        if not self._is_ptr(ent_addr) or ent_addr == self.player_addr or self._is_rejected_fish(ent_addr):
                            continue
                        signal = self._read_fish_candidate_signal(ent_addr, player_pos)
                        if signal is None:
                            continue
                        d2, entity_hash, pos, source = signal
                        hit = (d2, ent_addr, entity_hash, iface_off, list_off, stride, i, pos, source)
                        fish_hits.append(hit)
                        if best is None or self._fish_signal_key(signal) < self._fish_signal_key((best[0], best[2], best[7], best[8])):
                            best = hit
                            self._remember_replay_broad_path(iface_off, list_off, stride, i)
        debug_log(
            "REPLAY_BROAD "
            f"checked_lists={checked_lists} chosen={self._fmt_addr(None if best is None else best[1])} "
            f"hits="
            + " | ".join(
                f"addr={self._fmt_addr(addr)} hash={entity_hash} d={math.sqrt(d2):.2f} source={source} "
                f"iface_off=0x{iface_off:X} "
                f"list_off=0x{list_off:X} stride=0x{stride:X} i={idx} "
                f"pos=({pos[0]:.2f},{pos[1]:.2f},{pos[2]:.2f})"
                for d2, addr, entity_hash, iface_off, list_off, stride, idx, pos, source in sorted(
                    fish_hits, key=lambda item: self._fish_signal_key((item[0], item[2], item[7], item[8]))
                )[:8]
            )
        )
        if best is None:
            return None
        self._set_fish_signal_profile(best[2])
        return best[1]

    def _find_fish_addr_replay_broad_cached(self, p_iface: int, player_pos: tuple[float, float, float] | None) -> int | None:
        if not self._replay_broad_paths:
            return None
        for iface_off, list_off, stride, index in list(self._replay_broad_paths):
            iface = self._u64(p_iface + iface_off)
            if not self._is_ptr(iface):
                continue
            p_list = self._u64(iface + list_off)
            if not self._is_ptr(p_list):
                continue
            for delta in (0, -1, 1, -2, 2, -4, 4, -8, 8):
                idx = index + delta
                if idx < 0 or idx >= REPLAY_BROAD_SCAN_LIMIT:
                    continue
                ent_addr = self._u64(p_list + idx * stride)
                if not self._is_ptr(ent_addr) or ent_addr == self.player_addr or self._is_rejected_fish(ent_addr):
                    continue
                signal = self._read_fish_candidate_signal(ent_addr, player_pos)
                if signal is None:
                    continue
                d2, entity_hash, pos, source = signal
                debug_log(
                    "REPLAY_BROAD_CACHED "
                    f"chosen={self._fmt_addr(ent_addr)} hash={entity_hash} d={math.sqrt(d2):.2f} source={source} "
                    f"iface_off=0x{iface_off:X} list_off=0x{list_off:X} stride=0x{stride:X} i={idx} "
                    f"pos=({pos[0]:.2f},{pos[1]:.2f},{pos[2]:.2f})"
                )
                self._set_fish_signal_profile(entity_hash)
                self._remember_replay_broad_path(iface_off, list_off, stride, idx)
                return ent_addr
        return None

    def _remember_replay_broad_path(self, iface_off: int, list_off: int, stride: int, index: int) -> None:
        item = (iface_off, list_off, stride, index)
        if item in self._replay_broad_paths:
            self._replay_broad_paths.remove(item)
        self._replay_broad_paths.insert(0, item)
        del self._replay_broad_paths[16:]

    def _read_fish_candidate_signal(
        self,
        ent_addr: int,
        player_pos: tuple[float, float, float] | None,
    ) -> tuple[float, int | None, tuple[float, float, float], str] | None:
        entity_hash = self._read_entity_hash(ent_addr)
        if entity_hash == FISH_MODEL_HASH and self._is_finished_fish(ent_addr):
            return None
        fish_item = (
            self._read_confirmed_fish_world_pos(ent_addr, player_pos)
            if entity_hash == FISH_MODEL_HASH and player_pos is not None
            else None
        )
        if fish_item is None:
            fish_item = self._read_fish_pos_relative(ent_addr, player_pos)
        if fish_item is None:
            return None
        pos, _ = fish_item
        if player_pos is None or self._is_fishing_local_pos(pos):
            d2 = pos[0] * pos[0] + pos[1] * pos[1] + pos[2] * pos[2]
        else:
            px, py, pz = player_pos
            d2 = (pos[0] - px) ** 2 + (pos[1] - py) ** 2 + (pos[2] - pz) ** 2
        if entity_hash == FISH_MODEL_HASH:
            return d2, entity_hash, pos, "hash"
        if not ALLOW_UNKNOWN_FISH_CANDIDATES:
            return None
        if not self._is_fishing_local_pos(pos):
            return None
        direction = self._read_fish_direction(ent_addr, FISH_PRIMARY_DIRECTION_OFFSETS)
        if direction is not None:
            _, direction_offset, _ = direction
            return d2, entity_hash, pos, f"direction_0x{direction_offset:X}"
        return None

    @staticmethod
    def _fish_signal_key(signal: tuple[float, int | None, tuple[float, float, float], str]) -> tuple[int, float]:
        d2, entity_hash, _pos, source = signal
        if entity_hash == FISH_MODEL_HASH:
            return 0, d2
        rank = 99
        if source.startswith("direction_0x"):
            try:
                offset = int(source.removeprefix("direction_0x"), 16)
            except ValueError:
                offset = -1
            rank = 1 + FISH_DIRECTION_SOURCE_RANK.get(offset, 90)
        return rank, d2

    def _set_fish_signal_profile(self, entity_hash: int | None) -> None:
        self._fish_confirmed_hash = entity_hash == FISH_MODEL_HASH
        self._fish_direction_offsets = self._direction_offsets_for_signal(entity_hash)

    @staticmethod
    def _direction_offsets_for_signal(entity_hash: int | None) -> frozenset[int]:
        return FISH_PRIMARY_DIRECTION_OFFSETS

    def _cped_hint_range(self, cped_addr: int, half: int = SCAN_HALF_RANGE) -> tuple[int, int]:
        return max(PTR_MIN, cped_addr - half), min(PTR_MAX, cped_addr + half)

    def _collect_regions(self, hint_min: int, hint_max: int) -> list[tuple[int, int]]:
        if not self.handle:
            return []
        kernel32 = ctypes.windll.kernel32
        regions: list[tuple[int, int]] = []
        addr = hint_min
        mbi = MEMORY_BASIC_INFORMATION()
        mbi_size = ctypes.sizeof(MEMORY_BASIC_INFORMATION)
        while addr < hint_max:
            ret = kernel32.VirtualQueryEx(self.handle, ctypes.c_void_p(addr), ctypes.byref(mbi), mbi_size)
            if not ret:
                addr += 0x10000
                continue
            base = int(mbi.BaseAddress or 0)
            size = int(mbi.RegionSize or 0)
            end = base + size
            if (
                size > 0
                and end > hint_min
                and base < hint_max
                and mbi.State == MEM_COMMIT
                and not (mbi.Protect & PAGE_NOACCESS)
                and not (mbi.Protect & PAGE_GUARD)
                and size <= MAX_REGION_BYTES
            ):
                regions.append((max(base, hint_min), min(end, hint_max)))
            addr = max(addr + 0x1000, end)
        return regions

    def _find_fish_addr(self) -> int | None:
        player_pos = self._read_pos(self.player_addr) if self.player_addr else None
        if player_pos is None or self.player_addr is None:
            return None
        px, py, pz = player_pos
        hint_min, hint_max = self._cped_hint_range(self.player_addr)
        regions = self._collect_regions(hint_min, hint_max)
        strict = self._scan_fish_regions(regions, px, py, pz, pz - BOBBER_Z_BELOW, pz + BOBBER_Z_ABOVE)
        if strict:
            return strict
        broad = self._scan_fish_regions(regions, px, py, pz, pz - 20.0, pz + 5.0)
        return broad

    def _scan_fish_regions(
        self,
        regions: list[tuple[int, int]],
        px: float,
        py: float,
        pz: float,
        zmin: float,
        zmax: float,
    ) -> int | None:
        best_hash: tuple[float, int] | None = None
        debug_candidates: list[tuple[float, int, int | None, tuple[float, float, float]]] = []
        candidate_count = 0
        min_d2 = 4.0
        max_d2 = TRACK_MAX_DIST * TRACK_MAX_DIST
        overlap = max(BOBBER_MARKER_OFFSETS) + 64
        for rs, re in regions:
            cur = rs
            while cur < re:
                read_start = max(rs, cur - overlap)
                read_end = min(re, cur + MARKER_REGION_CHUNK)
                data = self._read(read_start, read_end - read_start)
                if not data:
                    cur += MARKER_REGION_CHUNK
                    continue
                data = data[: len(data) - (len(data) % 4)]
                if not data:
                    cur += MARKER_REGION_CHUNK
                    continue
                arr = np.frombuffer(data, dtype=np.float32)
                marker_deltas = tuple((off - POS_X_OFF) // 4 for off in BOBBER_MARKER_OFFSETS)
                max_marker_delta = max(marker_deltas)
                max_i = len(arr) - max(2, max_marker_delta)
                if max_i <= 0:
                    cur += MARKER_REGION_CHUNK
                    continue
                xs = arr[:max_i]
                ys = arr[1 : max_i + 1]
                zs = arr[2 : max_i + 2]
                with np.errstate(invalid="ignore"):
                    finite = np.isfinite(xs) & np.isfinite(ys) & np.isfinite(zs)
                    in_box = (
                        finite
                        & (xs >= px - SCAN_RADIUS)
                        & (xs <= px + SCAN_RADIUS)
                        & (ys >= py - SCAN_RADIUS)
                        & (ys <= py + SCAN_RADIUS)
                        & (zs >= zmin)
                        & (zs <= zmax)
                    )
                    marker_mask = np.zeros(max_i, dtype=bool)
                    for marker_delta in marker_deltas:
                        markers = arr[marker_delta : marker_delta + max_i]
                        marker_mask |= np.abs(markers - BOBBER_MARKER_F32) <= BOBBER_MARKER_EPS
                    idxs = np.where(in_box & marker_mask)[0]
                for idx in idxs[:512]:
                    x = float(xs[idx])
                    y = float(ys[idx])
                    z = float(zs[idx])
                    dx, dy, dz = x - px, y - py, z - pz
                    d2 = dx * dx + dy * dy + dz * dz
                    if not (min_d2 < d2 < max_d2):
                        continue
                    addr = read_start + int(idx) * 4 - POS_X_OFF
                    if not self._is_ptr(addr) or addr == self.player_addr or self._is_rejected_fish(addr):
                        continue
                    entity_hash = self._read_entity_hash(addr)
                    candidate_count += 1
                    if len(debug_candidates) < 24:
                        debug_candidates.append((d2, addr, entity_hash, (x, y, z)))
                    else:
                        worst_i, worst = max(enumerate(debug_candidates), key=lambda item: item[1][0])
                        if d2 < worst[0]:
                            debug_candidates[worst_i] = (d2, addr, entity_hash, (x, y, z))
                    if (
                        entity_hash == FISH_MODEL_HASH
                        and not self._is_finished_fish(addr)
                        and (best_hash is None or d2 < best_hash[0])
                    ):
                        best_hash = (d2, addr)
                cur += MARKER_REGION_CHUNK
        chosen = best_hash
        closest = sorted(debug_candidates, key=lambda item: item[0])
        debug_log(
            "FISH_SCAN_SUMMARY "
            f"count={candidate_count} chosen={self._fmt_addr(None if chosen is None else chosen[1])} "
            f"hash_chosen={best_hash is not None} "
            f"top="
            + " | ".join(
                f"addr={self._fmt_addr(addr)} hash={h} d={math.sqrt(d2):.2f} pos=({pos[0]:.2f},{pos[1]:.2f},{pos[2]:.2f})"
                for d2, addr, h, pos in closest[:12]
            )
        )
        if chosen:
            self._set_fish_signal_profile(FISH_MODEL_HASH)
            self._log(f"Memory reeling scan fish candidate: {self._fmt_addr(chosen[1])}")
        return None if chosen is None else chosen[1]

    def _read_player_right_vec(self, cped_addr: int) -> tuple[float, float] | None:
        for mat_off in PLAYER_MATRIX_OFFSETS:
            raw = self._read(cped_addr + mat_off, 64)
            if raw is None:
                continue
            for row in (0, 1, 2):
                rx, ry, rz, _rw = struct.unpack_from("<4f", raw, row * 16)
                if not all(math.isfinite(v) for v in (rx, ry, rz)):
                    continue
                ln = math.hypot(rx, ry)
                if 0.45 < ln < 1.55 and abs(rx) <= 1.2 and abs(ry) <= 1.2:
                    return rx / ln, ry / ln
        return None

    def _read_entity_heading_x(self, ent_addr: int | None) -> float | None:
        if ent_addr is None:
            return None
        for offset in (0x60, 0x30):
            x = self._f32(ent_addr + offset)
            y = self._f32(ent_addr + offset + 4)
            if x is None or y is None:
                continue
            if not math.isfinite(x) or not math.isfinite(y):
                continue
            ln = math.hypot(x, y)
            if 0.45 < ln < 1.55:
                return x / ln
        return None

    def _gta_module(self) -> ModuleInfo | None:
        modules = self._get_modules()
        for module in modules:
            if module.name == self.process_name.lower():
                return module
        return modules[0] if modules else None
