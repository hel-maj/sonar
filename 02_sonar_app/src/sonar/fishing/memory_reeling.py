from __future__ import annotations

import ctypes
import math
import random
import struct
import threading
import time
from ctypes import wintypes
from dataclasses import dataclass
from typing import Callable

import psutil
import numpy as np

from sonar.automation.input_controller import InputController
from sonar.core.logging import debug_log


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
MOVE_EPS = 0.5
VELOCITY_MOVE_EPS = 0.15
HEADING_MOVE_EPS = 0.08
VELOCITY_MAX_ABS = 8.0
KEY_SWITCH_MIN_SECONDS = 0.02
REEL_CONTROL_INTERVAL_SECONDS = 0.005
REEL_DEBUG_INTERVAL_SECONDS = 0.10
KEY_INITIAL_PRESS_DELAY_RANGE = (0.10, 0.20)
KEY_SWITCH_DELAY_RANGE = (0.10, 0.20)
LATERAL_DELTA_EPS = 0.35
LATERAL_VELOCITY_EPS = 1.2
LINE_TURN_EPS = 0.025
DIRECTION_MOVE = 1.0
DIRECTION_EPS = 0.5
FISH_FAST_RETRY_SECONDS = 0.12
FISH_DEEP_RETRY_SECONDS = 0.8
STATIONARY_TARGET_EPS = 0.02
STATIONARY_TARGET_SECONDS = 0.45
STATIONARY_TARGET_MIN_DISTANCE = 5.0
UNREADABLE_REJECT_SECONDS = 0.08
UNREADABLE_REJECT_COUNT = 3
POS_OFFSETS = (0x50, 0x40, 0x60, 0x30)
FISH_POS_OFFSETS = (0x130, 0x120, 0x90, 0x110, 0x160)
FISH_DIRECTION_FIELDS = (
    (0x300, 0.08, 1.0),
    (0x68, 0.0012, 1.0),
    (0x70, 0.08, 1.0),
    (0x80, 0.08, -1.0),
    (0x64, 0.08, -1.0),
    (0x314, 0.08, -1.0),
)
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

REPLAY_PATTERNS: tuple[tuple[tuple[int | None, ...], int, int, tuple[int, ...]], ...] = (
    ((72, 139, 5, None, None, None, None, 72, 139, 72, 8, 72, 133, 201), 3, 7, (8,)),
    ((72, 139, 5, None, None, None, None, 243, 15, 16, 80), 3, 7, (8, 16)),
    ((72, 139, 5, None, None, None, None, 72, 133, 192), 3, 7, (8, 16, 24)),
    ((72, 139, 13, None, None, None, None, 72, 133, 201), 3, 7, (8,)),
    ((72, 139, 5, None, None, None, None, 51, 255), 3, 7, (8,)),
)

CPED_PATTERN: tuple[int | None, ...] = (
    72,
    141,
    13,
    None,
    None,
    None,
    None,
    72,
    139,
    215,
    232,
    None,
    None,
    None,
    None,
    72,
    141,
    13,
    None,
    None,
    None,
    None,
    138,
    216,
    232,
    None,
    None,
    None,
    None,
    132,
    219,
    117,
    19,
    72,
    141,
    13,
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
        process_name: str = "gta5.exe",
        input_controller: InputController | None = None,
        log_callback: Callable[[str], None] | None = None,
    ) -> None:
        self.process_name = process_name
        self.input_controller = input_controller or InputController()
        self.log_callback = log_callback
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
        self._last_lateral: float | None = None
        self._last_lateral_at: float | None = None
        self._last_lateral_fish_addr: int | None = None
        self._lateral_velocity = 0.0
        self._last_line_vector: tuple[float, float] | None = None
        self._latest_state = ReelingState(active=False)
        self._state_lock = threading.Lock()
        self._control_thread: threading.Thread | None = None
        self._control_stop = threading.Event()
        self._last_input_allowed_check_at = 0.0
        self._input_allowed_cached = True

    def _log(self, msg: str) -> None:
        if self.log_callback:
            self.log_callback(msg)

    def start(self) -> None:
        self.running = True
        self.player_addr = None
        self.fish_addr = None
        self.replay_interface = None
        self.last_fish_xy = None
        self.last_fish_pos = None
        self.last_fish_pos_offset = None
        self.last_good_fish_at = 0.0
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
        self._unreadable_addr = None
        self._unreadable_since = 0.0
        self._unreadable_count = 0
        self._reset_lateral_tracking()
        self._last_input_allowed_check_at = 0.0
        self._input_allowed_cached = True
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
                    self.input_controller.key_up("a")
                    self.input_controller.key_up("d")
                    memory_unavailable_released = True
                elif state.action != "memory_unavailable":
                    memory_unavailable_released = False
            except Exception as exc:
                state = ReelingState(active=True, action="control_error")
                debug_log(f"REEL_CONTROL_ERROR {exc}")
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
            return ReelingState(active=True, action="target_search")
        if self.fish_addr is None:
            self._retry_find_fish()
            return ReelingState(active=True, action="target_search", player_addr=self.player_addr)
        if self.player_addr is None or self.fish_addr is None:
            return ReelingState(active=True, action="target_search")

        direction_item = self._read_fish_direction(self.fish_addr)
        now = time.time()
        if direction_item is not None:
            move_val, direction_offset, raw_value = direction_item
            action = self._apply_move(move_val, DIRECTION_EPS)
            if now - self._last_step_debug_at >= REEL_DEBUG_INTERVAL_SECONDS:
                self._last_step_debug_at = now
                debug_log(
                    "REEL_STEP "
                    f"player={self._fmt_addr(self.player_addr)} fish={self._fmt_addr(self.fish_addr)} "
                    f"direction_offset=0x{direction_offset:X} raw={raw_value:.5f} move={move_val:.3f} "
                    f"source=fish_direction_field"
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
            self.fish_addr = None
            return ReelingState(active=True, action="position_unreadable", player_addr=self.player_addr, fish_addr=self.fish_addr)
        fish_item = self._read_fish_pos_relative(self.fish_addr, player_item[0])
        using_stale_fish_pos = False
        if fish_item is None:
            if (
                self.last_fish_pos is not None
                and self.last_fish_pos_offset is not None
                and now - self.last_good_fish_at <= 3.0
            ):
                fish_item = self.last_fish_pos, self.last_fish_pos_offset
                using_stale_fish_pos = True
            else:
                if self._should_reject_unreadable(now):
                    self._reject_current_fish("position unreadable")
                    return ReelingState(active=True, action="target_search", player_addr=self.player_addr)
                return ReelingState(active=True, action="position_unreadable", player_addr=self.player_addr, fish_addr=self.fish_addr)

        player_pos, player_pos_offset = player_item
        fish_pos, fish_pos_offset = fish_item
        if not using_stale_fish_pos:
            self._reset_unreadable_tracking()
            self.last_fish_pos = fish_pos
            self.last_fish_pos_offset = fish_pos_offset
            self.last_good_fish_at = now
        px, py, pz = player_pos
        x, y, z = fish_pos
        distance = math.sqrt((x - px) ** 2 + (y - py) ** 2 + (z - pz) ** 2)
        if self._is_stationary_wrong_target(now, fish_pos, distance, using_stale_fish_pos):
            self._reject_current_fish("stationary target", fish_pos, distance)
            return ReelingState(active=True, action="target_search", player_addr=self.player_addr)
        if self.last_fish_xy and self.last_time and not using_stale_fish_pos:
            dt = max(now - self.last_time, 0.001)
            vx = (x - self.last_fish_xy[0]) / dt
            vy = (y - self.last_fish_xy[1]) / dt
            self.velocity_xy = (self.velocity_xy[0] * 0.7 + vx * 0.3, self.velocity_xy[1] * 0.7 + vy * 0.3)
        if not using_stale_fish_pos:
            self.last_time = now
            self.last_fish_xy = (x, y)

        right = self._read_player_right_vec(self.player_addr)
        right_source = "player_matrix"
        if right is None:
            right = (1.0, 0.0)
            right_source = "velocity_x_fallback"

        lateral = (x - px) * right[0] + (y - py) * right[1]
        velocity_along = self.velocity_xy[0] * right[0] + self.velocity_xy[1] * right[1]
        move_val, move_source, action_eps = self._movement_from_lateral(
            lateral=lateral,
            velocity_along=velocity_along,
            now=now,
            fish_addr=self.fish_addr,
            using_stale_fish_pos=using_stale_fish_pos,
            player_pos=player_pos,
            fish_pos=fish_pos,
        )
        fish_heading_x: float | None = None
        if now - self._last_step_debug_at >= REEL_DEBUG_INTERVAL_SECONDS:
            self._last_step_debug_at = now
            debug_log(
                "REEL_STEP "
                f"player={self._fmt_addr(self.player_addr)} fish={self._fmt_addr(self.fish_addr)} "
                f"pp=({px:.3f},{py:.3f},{pz:.3f}) fp=({x:.3f},{y:.3f},{z:.3f}) "
                f"offsets=0x{player_pos_offset:X}/0x{fish_pos_offset:X} "
                f"right=({right[0]:.4f},{right[1]:.4f},{right_source}) "
                f"vel=({self.velocity_xy[0]:.4f},{self.velocity_xy[1]:.4f}) dist={distance:.3f} "
                f"heading={fish_heading_x} "
                f"lateral={lateral:.4f} move={move_val:.4f} eps={action_eps:.4f} "
                f"source={move_source} lateral_vel={self._lateral_velocity:.4f} stale={using_stale_fish_pos} "
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

    def _read_fish_direction(self, fish_addr: int) -> tuple[float, int, float] | None:
        for offset, eps, polarity in FISH_DIRECTION_FIELDS:
            value = self._f32(fish_addr + offset)
            if value is None or not math.isfinite(value):
                continue
            move_val = value * polarity
            if abs(move_val) >= eps:
                return (DIRECTION_MOVE if move_val > 0 else -DIRECTION_MOVE), offset, value
        return None

    def _apply_move(self, move_val: float, action_eps: float) -> str:
        if move_val > action_eps:
            if self._hold_key("d"):
                self._release_key("a")
            return "hold_d" if self.held_key == "d" else "hold_d_throttled"
        if move_val < -action_eps:
            if self._hold_key("a"):
                self._release_key("d")
            return "hold_a" if self.held_key == "a" else "hold_a_throttled"
        if self.held_key == "a":
            return "hold_a_wait"
        if self.held_key == "d":
            return "hold_d_wait"
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

    def _reset_lateral_tracking(self) -> None:
        self._last_lateral = None
        self._last_lateral_at = None
        self._last_lateral_fish_addr = None
        self._lateral_velocity = 0.0
        self._last_line_vector = None

    def _movement_from_lateral(
        self,
        lateral: float,
        velocity_along: float,
        now: float,
        fish_addr: int | None,
        using_stale_fish_pos: bool,
        player_pos: tuple[float, float, float],
        fish_pos: tuple[float, float, float],
    ) -> tuple[float, str, float]:
        if using_stale_fish_pos:
            if self.held_key == "a":
                return -DIRECTION_MOVE, "hold_previous_stale", DIRECTION_EPS
            if self.held_key == "d":
                return DIRECTION_MOVE, "hold_previous_stale", DIRECTION_EPS
            return 0.0, "wait_fresh_position", DIRECTION_EPS

        current_vector = (fish_pos[0] - player_pos[0], fish_pos[1] - player_pos[1])

        if fish_addr is None or self._last_lateral_fish_addr != fish_addr:
            self._last_lateral = lateral
            self._last_lateral_at = now
            self._last_lateral_fish_addr = fish_addr
            self._lateral_velocity = 0.0
            self._last_line_vector = current_vector
            return 0.0, "line_warmup", DIRECTION_EPS

        if self._last_lateral is None or self._last_lateral_at is None or self._last_line_vector is None:
            self._last_lateral = lateral
            self._last_lateral_at = now
            self._lateral_velocity = 0.0
            self._last_line_vector = current_vector
            return 0.0, "line_warmup", DIRECTION_EPS

        dt = max(now - self._last_lateral_at, 0.001)
        delta = lateral - self._last_lateral
        instant_velocity = delta / dt
        self._lateral_velocity = self._lateral_velocity * 0.45 + instant_velocity * 0.55
        previous_vector = self._last_line_vector
        self._last_lateral = lateral
        self._last_lateral_at = now
        self._last_line_vector = current_vector

        prev_len = math.hypot(previous_vector[0], previous_vector[1])
        curr_len = math.hypot(current_vector[0], current_vector[1])
        if prev_len > 0.5 and curr_len > 0.5:
            cross = previous_vector[0] * current_vector[1] - previous_vector[1] * current_vector[0]
            turn = cross / (prev_len * curr_len)
            if turn > LINE_TURN_EPS:
                return DIRECTION_MOVE, "line_left", DIRECTION_EPS
            if turn < -LINE_TURN_EPS:
                return -DIRECTION_MOVE, "line_right", DIRECTION_EPS

        if abs(delta) >= LATERAL_DELTA_EPS:
            return (DIRECTION_MOVE if delta > 0 else -DIRECTION_MOVE), "lateral_delta", DIRECTION_EPS
        if self.held_key == "a":
            return -DIRECTION_MOVE, "hold_previous_wait", DIRECTION_EPS
        if self.held_key == "d":
            return DIRECTION_MOVE, "hold_previous_wait", DIRECTION_EPS
        return 0.0, "wait_line_delta", DIRECTION_EPS

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
        self.fish_addr = None
        self.last_fish_xy = None
        self.last_fish_pos = None
        self.last_fish_pos_offset = None
        self.last_good_fish_at = 0.0
        self.velocity_xy = (0.0, 0.0)
        self._motion_last_pos = None
        self._motion_stationary_since = 0.0
        self._reset_unreadable_tracking()
        self._reset_lateral_tracking()
        self._last_fish_search_at = 0.0
        self._last_deep_fish_search_at = 0.0

    def _is_rejected_fish(self, ent_addr: int) -> bool:
        return ent_addr in self._rejected_fish_addrs

    def _hold_key(self, key: str) -> bool:
        if self.held_key == key:
            return True
        now = time.time()
        if self.held_key and self.held_key != key and now - self._last_key_switch_at < KEY_SWITCH_MIN_SECONDS:
            debug_log(
                f"REEL_KEY_SWITCH_THROTTLED requested={key} held={self.held_key} "
                f"age={now - self._last_key_switch_at:.3f}"
            )
            return False
        previous_key = self.held_key
        if self.held_key and self.held_key != key:
            self.input_controller.key_up(self.held_key)
            self.held_key = None
            time.sleep(random.uniform(*KEY_SWITCH_DELAY_RANGE))
        elif self.held_key is None:
            time.sleep(random.uniform(*KEY_INITIAL_PRESS_DELAY_RANGE))
        if self.input_controller.key_down(key) is False:
            self._last_key_switch_at = time.time()
            return False
        debug_log(f"REEL_KEY_DOWN key={key} previous={previous_key}")
        self.held_key = key
        self._last_key_switch_at = time.time()
        return True

    def _release_key(self, key: str) -> None:
        if self.held_key == key:
            self.input_controller.key_up(key)
            debug_log(f"REEL_KEY_UP key={key}")
            self.held_key = None
            self._last_key_switch_at = time.time()
        elif self.held_key is None:
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

    def _retry_find_fish(self) -> None:
        now = time.time()
        if now - self._last_fish_search_at < FISH_FAST_RETRY_SECONDS:
            return
        self._last_fish_search_at = now
        try:
            self.fish_addr = self._find_fish_addr_replay()
            if self.fish_addr is None and now - self._last_deep_fish_search_at >= FISH_DEEP_RETRY_SECONDS:
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
        player_pos: tuple[float, float, float],
        max_dist: float = TRACK_MAX_DIST,
    ) -> tuple[tuple[float, float, float], int] | None:
        px, py, pz = player_pos
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
            dist = math.sqrt((x - px) ** 2 + (y - py) ** 2 + (z - pz) ** 2)
            if 1.0 < dist < max_dist:
                return pos, offset
        return None

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
        hit = self._pattern_scan(gta.base, gta.size, CPED_PATTERN)
        if hit is None:
            return None
        rel = self._i32(hit + 3)
        if rel is None:
            return None
        candidate = hit + 7 + rel
        maybe = self._u64(candidate)
        return maybe if self._is_ptr(maybe) else None

    def _find_replay_interface_global(self) -> int | None:
        gta = self._gta_module()
        if gta is None:
            return None
        for pattern, rel_off, insn_len, offsets in REPLAY_PATTERNS:
            hit = self._pattern_scan(gta.base, gta.size, pattern)
            if hit is None:
                continue
            rel = self._i32(hit + rel_off)
            if rel is None:
                continue
            ptr = hit + insn_len + rel
            value = self._u64(ptr)
            for offset in offsets:
                value = self._u64(value + offset) if self._is_ptr(value) else None
            if self._is_ptr(value):
                return value
        return None

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
            return self._find_fish_addr_replay_hash_only(p_iface)
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
        best_hash: tuple[float, int] | None = None
        debug_candidates: list[tuple[float, int, int | None, tuple[float, float, float], int]] = []
        limit = min(max_peds or 256, 2048)
        for i in range(limit):
            ent_addr = self._u64(p_ped_list + i * 0x10)
            if not self._is_ptr(ent_addr) or ent_addr == self.player_addr or self._is_rejected_fish(ent_addr):
                continue
            pos = self._read_pos(ent_addr)
            if pos is None:
                continue
            dx, dy, dz = pos[0] - px, pos[1] - py, pos[2] - pz
            d2 = dx * dx + dy * dy + dz * dz
            if not (1.0 < d2 < TRACK_MAX_DIST * TRACK_MAX_DIST):
                continue
            entity_hash = self._read_entity_hash(ent_addr)
            fish_item = self._read_fish_pos_relative(ent_addr, player_pos) if entity_hash == FISH_MODEL_HASH else None
            fish_pos = fish_item[0] if fish_item else pos
            fish_dx, fish_dy, fish_dz = fish_pos[0] - px, fish_pos[1] - py, fish_pos[2] - pz
            fish_d2 = fish_dx * fish_dx + fish_dy * fish_dy + fish_dz * fish_dz
            debug_candidates.append((fish_d2, ent_addr, entity_hash, fish_pos, i))
            if entity_hash == FISH_MODEL_HASH and fish_item is not None and (best_hash is None or fish_d2 < best_hash[0]):
                best_hash = (fish_d2, ent_addr)
        chosen = best_hash
        closest = sorted(debug_candidates, key=lambda item: item[0])[:12]
        debug_log(
            "REPLAY_SEARCH "
            f"p_iface={self._fmt_addr(p_iface)} ped_iface={self._fmt_addr(p_ped_iface)} "
            f"ri_off=0x{ri_off:X} list_off=0x{list_off:X} max_off=0x{max_off:X} "
            f"ped_list={self._fmt_addr(p_ped_list)} max_peds={max_peds} limit={limit} "
            f"chosen={self._fmt_addr(None if chosen is None else chosen[1])} "
            f"candidates="
            + " | ".join(
                f"i={i} addr={self._fmt_addr(addr)} hash={h} d={math.sqrt(d2):.2f} pos=({pos[0]:.2f},{pos[1]:.2f},{pos[2]:.2f})"
                for d2, addr, h, pos, i in closest
            )
        )
        if chosen is not None:
            return chosen[1]
        return self._find_fish_addr_replay_broad(p_iface, player_pos)

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
                if self._read_entity_hash(ent_addr) == FISH_MODEL_HASH:
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

    def _find_fish_addr_replay_broad(self, p_iface: int, player_pos: tuple[float, float, float]) -> int | None:
        cached = self._find_fish_addr_replay_broad_cached(p_iface, player_pos)
        if cached is not None:
            return cached
        best: tuple[float, int, int, int, int, int, tuple[float, float, float]] | None = None
        checked_lists = 0
        fish_hits: list[tuple[float, int, int, int, int, int, tuple[float, float, float]]] = []
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
                    for i in range(256):
                        ent_addr = self._u64(p_list + i * stride)
                        if not self._is_ptr(ent_addr) or ent_addr == self.player_addr or self._is_rejected_fish(ent_addr):
                            continue
                        if self._read_entity_hash(ent_addr) != FISH_MODEL_HASH:
                            continue
                        fish_item = self._read_fish_pos_relative(ent_addr, player_pos)
                        if fish_item is None:
                            continue
                        pos, _ = fish_item
                        px, py, pz = player_pos
                        d2 = (pos[0] - px) ** 2 + (pos[1] - py) ** 2 + (pos[2] - pz) ** 2
                        hit = (d2, ent_addr, iface_off, list_off, stride, i, pos)
                        fish_hits.append(hit)
                        if best is None or d2 < best[0]:
                            best = hit
                            self._remember_replay_broad_path(iface_off, list_off, stride, i)
        debug_log(
            "REPLAY_BROAD "
            f"checked_lists={checked_lists} chosen={self._fmt_addr(None if best is None else best[1])} "
            f"hits="
            + " | ".join(
                f"addr={self._fmt_addr(addr)} d={math.sqrt(d2):.2f} iface_off=0x{iface_off:X} "
                f"list_off=0x{list_off:X} stride=0x{stride:X} i={idx} "
                f"pos=({pos[0]:.2f},{pos[1]:.2f},{pos[2]:.2f})"
                for d2, addr, iface_off, list_off, stride, idx, pos in sorted(fish_hits, key=lambda item: item[0])[:8]
            )
        )
        return None if best is None else best[1]

    def _find_fish_addr_replay_broad_cached(self, p_iface: int, player_pos: tuple[float, float, float]) -> int | None:
        if not self._replay_broad_paths:
            return None
        px, py, pz = player_pos
        for iface_off, list_off, stride, index in list(self._replay_broad_paths):
            iface = self._u64(p_iface + iface_off)
            if not self._is_ptr(iface):
                continue
            p_list = self._u64(iface + list_off)
            if not self._is_ptr(p_list):
                continue
            for delta in (0, -1, 1, -2, 2, -4, 4, -8, 8):
                idx = index + delta
                if idx < 0 or idx >= 256:
                    continue
                ent_addr = self._u64(p_list + idx * stride)
                if not self._is_ptr(ent_addr) or ent_addr == self.player_addr or self._is_rejected_fish(ent_addr):
                    continue
                if self._read_entity_hash(ent_addr) != FISH_MODEL_HASH:
                    continue
                fish_item = self._read_fish_pos_relative(ent_addr, player_pos)
                if fish_item is None:
                    continue
                pos, _ = fish_item
                d2 = (pos[0] - px) ** 2 + (pos[1] - py) ** 2 + (pos[2] - pz) ** 2
                debug_log(
                    "REPLAY_BROAD_CACHED "
                    f"chosen={self._fmt_addr(ent_addr)} d={math.sqrt(d2):.2f} "
                    f"iface_off=0x{iface_off:X} list_off=0x{list_off:X} stride=0x{stride:X} i={idx} "
                    f"pos=({pos[0]:.2f},{pos[1]:.2f},{pos[2]:.2f})"
                )
                self._remember_replay_broad_path(iface_off, list_off, stride, idx)
                return ent_addr
        return None

    def _remember_replay_broad_path(self, iface_off: int, list_off: int, stride: int, index: int) -> None:
        item = (iface_off, list_off, stride, index)
        if item in self._replay_broad_paths:
            self._replay_broad_paths.remove(item)
        self._replay_broad_paths.insert(0, item)
        del self._replay_broad_paths[16:]

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
                    if entity_hash == FISH_MODEL_HASH and (best_hash is None or d2 < best_hash[0]):
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
            self._log(f"Memory reeling scan fish candidate: {self._fmt_addr(chosen[1])}")
        return None if chosen is None else chosen[1]

    def _read_player_right_vec(self, cped_addr: int) -> tuple[float, float] | None:
        for mat_off in (0x20, 0x30, 0x40, 0x50, 0x60, 0x70):
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
