# Function Specification: `workers.fishing.memory_reeling`

This is a reconstruction dossier from static Nuitka constants and Ghidra decompilation. It is not original Python source text.

## Source Path Hints
- `workers\fishing\memory_reeling.py`

## Docstrings / Long Text
- `223` '\nВываживание рыбы через чтение памяти GTA5.\nОдин универсальный модуль вместо fatigue/ocean_fishing.\n'

## Function Inventory
| Inferred qualname | Impl | Source line | Arg count | Decompiled C |
|---|---:|---:|---:|---|
| `MemoryReelingTracker.__init__` | `FUN_23e7fea70` | ? | ? | yes |
| `MemoryReelingTracker._log` | `FUN_23e7ffd30` | ? | ? | yes |
| `MemoryReelingTracker.start` | `FUN_23e800240` | ? | ? | yes |
| `MemoryReelingTracker.stop` | `FUN_23e801b80` | ? | ? | yes |
| `MemoryReelingTracker.step` | `FUN_23e8026b0` | ? | ? | yes |
| `MemoryReelingTracker._hold_key` | `FUN_23e80a550` | ? | ? | yes |
| `MemoryReelingTracker._release_key` | `FUN_23e80ab40` | ? | ? | yes |
| `MemoryReelingTracker._get_pid` | `FUN_23e80b5c0` | ? | ? | yes |
| `MemoryReelingTracker._read` | `FUN_23e80bb70` | ? | ? | yes |
| `MemoryReelingTracker._u64` | `FUN_23e80c310` | ? | ? | yes |
| `MemoryReelingTracker._f32` | `FUN_23e80c8c0` | ? | ? | yes |
| `MemoryReelingTracker._i32` | `FUN_23e80db10` | ? | ? | yes |
| `MemoryReelingTracker._read_pos` | `FUN_23e80dff0` | ? | ? | yes |
| `MemoryReelingTracker._is_ptr` | `FUN_23e810950` | ? | ? | yes |
| `MemoryReelingTracker._get_modules` | `FUN_23e8116a0` | ? | ? | yes |
| `MemoryReelingTracker._pattern_scan` | `FUN_23e812d00` | ? | ? | yes |
| `MemoryReelingTracker._find_cped` | `FUN_23e813650` | ? | ? | yes |
| `MemoryReelingTracker._find_replay_interface_global` | `FUN_23e8186f0` | ? | ? | yes |
| `MemoryReelingTracker._read_entity_hash` | `FUN_23e818f10` | ? | ? | yes |
| `MemoryReelingTracker._find_fish_addr_replay` | `FUN_23e81ccf0` | ? | ? | yes |
| `MemoryReelingTracker._read_player_right_vec` | `FUN_23e81da40` | ? | ? | yes |

## Local Variable Lists
- `311` `.0, lo, hi, rs`
- `312` `.0, lo, hi, vt`
- `313` `.0, j, pb, comb, i`
- `315` `__class__`
- `316` `self, capture, log_callback`
- `317` `self, hint_min, hint_max, key, cached, regions, addr, mbi, ret, rsz, rs, in_mod, re, cur, end, nxt, na, out`
- `318` `self, cped_addr, half, lo, hi`
- `319` `self, addr, d, v`
- `320` `self, gta, base, size, vtable_ranges, nm, info, b, s, pattern, rp, il, offsets, m, raw, wp, cw, wo, cp, vt`
- `321` `self, player_pos, by_hash, px, py, pz, hint_min, hint_max, regions, marker_delta, xmin, xmax, ymin, ymax, zmin, zmax, best, rs, re, data, n32, a32f, finite, m, hits4, idxs, i_np, i, xi, x, y, z, dist, addr`
- `322` `self, player_pos, p_iface, p_ped_iface, max_peds, p_ped_list, px, py, pz, best, max_dist, max_dist2, i, ent_addr, h, pos, dx, dy, dz, d2`
- `323` `self, gta, base, size, hit, rel, disp, ptr_addr, p_iface`
- `324` `self, pid, snap, me, out, ok, name, base`
- `326` `self, key`
- `327` `self, addr, d`
- `328` `self, msg`
- `329` `self, source, now`
- `330` `self, base, size, pattern, chunk, plen, prev, off, data, comb, i`
- `331` `self, addr, size, buf, n`
- `332` `self, ent_addr, archetype, d`
- `333` `self, cped_addr, mat_off, raw, row, rv, rx, ry, ln`
- `334` `self, addr, x, y, z`
- `335` `self`
- `336` `self, pp, fp, x, y, z, px, py, pz, dist, t_now, dt, dx, dy, vx, vy, vx_sm, vy_sm, right, lateral, move_val`

## Structured Constants
- `69` [0]
- `98` [-1]
- `157` [80, 64, 96, 48]
- `160` [0, 1, 2]
- `169` [1099511627776, 4398046511104]
- `207` [None, None, None]
- `209` {'__slice__': [None, -3, None]}
- `210` {'__slice__': [1, -2, None]}
- `211` {'__slice__': [2, -1, None]}
- `212` {'__slice__': [3, None, None]}
- `245` [1.0]
- `249` [72, 141, 13, None, None, None, None, 72, 139, 215, 232, None, None, None, None, 72, 141, 13, None, None, None, None, 138, 216, 232, None, None, None, None, 132, 219, 117, 19, 72, 141, 13]
- `279` [[[72, 139, 5, None, None, None, None, 72, 139, 72, 8, 72, 133, 201], 3, 7, [8]], [[72, 139, 5, None, None, None, None, 243, 15, 16, 80], 3, 7, [8, 16]], [[72, 139, 5, None, None, None, None, 72, 133, 192], 3, 7, [8, 16, 24]], [[72, 139, 13, None, None, None, None, 72, 133, 201], 3, 7, [8]], [[72, 139, 5, None, None, None, None, 51, 255], 3, 7, [8]]]
- `281` [None]
- `299` [1048576]

## Per-Function Context
### `MemoryReelingTracker.__init__`

- implementation: `FUN_23e7fea70`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `274` 'hModule'
     `275` 'HMODULE'
     `276` 'c_wchar'
     `277` 'szExePath'
     `278` 260
     `279` [[[72, 139, 5, None, None, None, None, 72, 139, 72, 8, 72, 133, 201], 3, 7, [8]], [[72, 139, 5, None, None, None, None, 243, 15, 16, 80], 3, 7, [8, 16]], [[72, 139, 5, None, None, None, None, 72, 133, 192], 3, 7, [8, 16, 24]], [[72, 139, 13, None, None, None, None, 72, 133, 20...
     `280` 'MemoryReelingTracker'
     `281` [None]
  => `282` 'MemoryReelingTracker.__init__'
     `283` 'MemoryReelingTracker._log'
     `284` 'start'
     `285` 'MemoryReelingTracker.start'
     `286` 'MemoryReelingTracker.stop'
     `287` 'step'
     `288` 'MemoryReelingTracker.step'
     `289` 'MemoryReelingTracker._hold_key'
     `290` 'MemoryReelingTracker._release_key'
     `291` 'MemoryReelingTracker._get_pid'
     `292` 'MemoryReelingTracker._read'
     `293` 'MemoryReelingTracker._u64'
     `294` 'MemoryReelingTracker._f32'
     `295` 'MemoryReelingTracker._i32'
     `296` 'MemoryReelingTracker._read_pos'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__memory_reeling\23e7fea70_MemoryReelingTracker.__init.c`

### `MemoryReelingTracker._log`

- implementation: `FUN_23e7ffd30`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `275` 'HMODULE'
     `276` 'c_wchar'
     `277` 'szExePath'
     `278` 260
     `279` [[[72, 139, 5, None, None, None, None, 72, 139, 72, 8, 72, 133, 201], 3, 7, [8]], [[72, 139, 5, None, None, None, None, 243, 15, 16, 80], 3, 7, [8, 16]], [[72, 139, 5, None, None, None, None, 72, 133, 192], 3, 7, [8, 16, 24]], [[72, 139, 13, None, None, None, None, 72, 133, 20...
     `280` 'MemoryReelingTracker'
     `281` [None]
     `282` 'MemoryReelingTracker.__init__'
  => `283` 'MemoryReelingTracker._log'
     `284` 'start'
     `285` 'MemoryReelingTracker.start'
     `286` 'MemoryReelingTracker.stop'
     `287` 'step'
     `288` 'MemoryReelingTracker.step'
     `289` 'MemoryReelingTracker._hold_key'
     `290` 'MemoryReelingTracker._release_key'
     `291` 'MemoryReelingTracker._get_pid'
     `292` 'MemoryReelingTracker._read'
     `293` 'MemoryReelingTracker._u64'
     `294` 'MemoryReelingTracker._f32'
     `295` 'MemoryReelingTracker._i32'
     `296` 'MemoryReelingTracker._read_pos'
     `297` 'MemoryReelingTracker._is_ptr'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__memory_reeling\23e7ffd30_MemoryReelingTracker._log.c`

### `MemoryReelingTracker.start`

- implementation: `FUN_23e800240`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `277` 'szExePath'
     `278` 260
     `279` [[[72, 139, 5, None, None, None, None, 72, 139, 72, 8, 72, 133, 201], 3, 7, [8]], [[72, 139, 5, None, None, None, None, 243, 15, 16, 80], 3, 7, [8, 16]], [[72, 139, 5, None, None, None, None, 72, 133, 192], 3, 7, [8, 16, 24]], [[72, 139, 13, None, None, None, None, 72, 133, 20...
     `280` 'MemoryReelingTracker'
     `281` [None]
     `282` 'MemoryReelingTracker.__init__'
     `283` 'MemoryReelingTracker._log'
     `284` 'start'
  => `285` 'MemoryReelingTracker.start'
     `286` 'MemoryReelingTracker.stop'
     `287` 'step'
     `288` 'MemoryReelingTracker.step'
     `289` 'MemoryReelingTracker._hold_key'
     `290` 'MemoryReelingTracker._release_key'
     `291` 'MemoryReelingTracker._get_pid'
     `292` 'MemoryReelingTracker._read'
     `293` 'MemoryReelingTracker._u64'
     `294` 'MemoryReelingTracker._f32'
     `295` 'MemoryReelingTracker._i32'
     `296` 'MemoryReelingTracker._read_pos'
     `297` 'MemoryReelingTracker._is_ptr'
     `298` 'MemoryReelingTracker._get_modules'
     `299` [1048576]
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__memory_reeling\23e800240_MemoryReelingTracker.start.c`

### `MemoryReelingTracker.stop`

- implementation: `FUN_23e801b80`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `278` 260
     `279` [[[72, 139, 5, None, None, None, None, 72, 139, 72, 8, 72, 133, 201], 3, 7, [8]], [[72, 139, 5, None, None, None, None, 243, 15, 16, 80], 3, 7, [8, 16]], [[72, 139, 5, None, None, None, None, 72, 133, 192], 3, 7, [8, 16, 24]], [[72, 139, 13, None, None, None, None, 72, 133, 20...
     `280` 'MemoryReelingTracker'
     `281` [None]
     `282` 'MemoryReelingTracker.__init__'
     `283` 'MemoryReelingTracker._log'
     `284` 'start'
     `285` 'MemoryReelingTracker.start'
  => `286` 'MemoryReelingTracker.stop'
     `287` 'step'
     `288` 'MemoryReelingTracker.step'
     `289` 'MemoryReelingTracker._hold_key'
     `290` 'MemoryReelingTracker._release_key'
     `291` 'MemoryReelingTracker._get_pid'
     `292` 'MemoryReelingTracker._read'
     `293` 'MemoryReelingTracker._u64'
     `294` 'MemoryReelingTracker._f32'
     `295` 'MemoryReelingTracker._i32'
     `296` 'MemoryReelingTracker._read_pos'
     `297` 'MemoryReelingTracker._is_ptr'
     `298` 'MemoryReelingTracker._get_modules'
     `299` [1048576]
     `300` 'MemoryReelingTracker._pattern_scan'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__memory_reeling\23e801b80_MemoryReelingTracker.stop.c`

### `MemoryReelingTracker.step`

- implementation: `FUN_23e8026b0`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `280` 'MemoryReelingTracker'
     `281` [None]
     `282` 'MemoryReelingTracker.__init__'
     `283` 'MemoryReelingTracker._log'
     `284` 'start'
     `285` 'MemoryReelingTracker.start'
     `286` 'MemoryReelingTracker.stop'
     `287` 'step'
  => `288` 'MemoryReelingTracker.step'
     `289` 'MemoryReelingTracker._hold_key'
     `290` 'MemoryReelingTracker._release_key'
     `291` 'MemoryReelingTracker._get_pid'
     `292` 'MemoryReelingTracker._read'
     `293` 'MemoryReelingTracker._u64'
     `294` 'MemoryReelingTracker._f32'
     `295` 'MemoryReelingTracker._i32'
     `296` 'MemoryReelingTracker._read_pos'
     `297` 'MemoryReelingTracker._is_ptr'
     `298` 'MemoryReelingTracker._get_modules'
     `299` [1048576]
     `300` 'MemoryReelingTracker._pattern_scan'
     `301` 'MemoryReelingTracker._find_cped'
     `302` 'MemoryReelingTracker._find_replay_interface_global'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__memory_reeling\23e8026b0_MemoryReelingTracker.step.c`

### `MemoryReelingTracker._hold_key`

- implementation: `FUN_23e80a550`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `281` [None]
     `282` 'MemoryReelingTracker.__init__'
     `283` 'MemoryReelingTracker._log'
     `284` 'start'
     `285` 'MemoryReelingTracker.start'
     `286` 'MemoryReelingTracker.stop'
     `287` 'step'
     `288` 'MemoryReelingTracker.step'
  => `289` 'MemoryReelingTracker._hold_key'
     `290` 'MemoryReelingTracker._release_key'
     `291` 'MemoryReelingTracker._get_pid'
     `292` 'MemoryReelingTracker._read'
     `293` 'MemoryReelingTracker._u64'
     `294` 'MemoryReelingTracker._f32'
     `295` 'MemoryReelingTracker._i32'
     `296` 'MemoryReelingTracker._read_pos'
     `297` 'MemoryReelingTracker._is_ptr'
     `298` 'MemoryReelingTracker._get_modules'
     `299` [1048576]
     `300` 'MemoryReelingTracker._pattern_scan'
     `301` 'MemoryReelingTracker._find_cped'
     `302` 'MemoryReelingTracker._find_replay_interface_global'
     `303` 'MemoryReelingTracker._read_entity_hash'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__memory_reeling\23e80a550_MemoryReelingTracker._hold_key.c`

### `MemoryReelingTracker._release_key`

- implementation: `FUN_23e80ab40`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `282` 'MemoryReelingTracker.__init__'
     `283` 'MemoryReelingTracker._log'
     `284` 'start'
     `285` 'MemoryReelingTracker.start'
     `286` 'MemoryReelingTracker.stop'
     `287` 'step'
     `288` 'MemoryReelingTracker.step'
     `289` 'MemoryReelingTracker._hold_key'
  => `290` 'MemoryReelingTracker._release_key'
     `291` 'MemoryReelingTracker._get_pid'
     `292` 'MemoryReelingTracker._read'
     `293` 'MemoryReelingTracker._u64'
     `294` 'MemoryReelingTracker._f32'
     `295` 'MemoryReelingTracker._i32'
     `296` 'MemoryReelingTracker._read_pos'
     `297` 'MemoryReelingTracker._is_ptr'
     `298` 'MemoryReelingTracker._get_modules'
     `299` [1048576]
     `300` 'MemoryReelingTracker._pattern_scan'
     `301` 'MemoryReelingTracker._find_cped'
     `302` 'MemoryReelingTracker._find_replay_interface_global'
     `303` 'MemoryReelingTracker._read_entity_hash'
     `304` 'MemoryReelingTracker._find_fish_addr_replay'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__memory_reeling\23e80ab40_MemoryReelingTracker._release_key.c`

### `MemoryReelingTracker._get_pid`

- implementation: `FUN_23e80b5c0`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `283` 'MemoryReelingTracker._log'
     `284` 'start'
     `285` 'MemoryReelingTracker.start'
     `286` 'MemoryReelingTracker.stop'
     `287` 'step'
     `288` 'MemoryReelingTracker.step'
     `289` 'MemoryReelingTracker._hold_key'
     `290` 'MemoryReelingTracker._release_key'
  => `291` 'MemoryReelingTracker._get_pid'
     `292` 'MemoryReelingTracker._read'
     `293` 'MemoryReelingTracker._u64'
     `294` 'MemoryReelingTracker._f32'
     `295` 'MemoryReelingTracker._i32'
     `296` 'MemoryReelingTracker._read_pos'
     `297` 'MemoryReelingTracker._is_ptr'
     `298` 'MemoryReelingTracker._get_modules'
     `299` [1048576]
     `300` 'MemoryReelingTracker._pattern_scan'
     `301` 'MemoryReelingTracker._find_cped'
     `302` 'MemoryReelingTracker._find_replay_interface_global'
     `303` 'MemoryReelingTracker._read_entity_hash'
     `304` 'MemoryReelingTracker._find_fish_addr_replay'
     `305` 'MemoryReelingTracker._read_player_right_vec'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__memory_reeling\23e80b5c0_MemoryReelingTracker._get_pid.c`

### `MemoryReelingTracker._read`

- implementation: `FUN_23e80bb70`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `284` 'start'
     `285` 'MemoryReelingTracker.start'
     `286` 'MemoryReelingTracker.stop'
     `287` 'step'
     `288` 'MemoryReelingTracker.step'
     `289` 'MemoryReelingTracker._hold_key'
     `290` 'MemoryReelingTracker._release_key'
     `291` 'MemoryReelingTracker._get_pid'
  => `292` 'MemoryReelingTracker._read'
     `293` 'MemoryReelingTracker._u64'
     `294` 'MemoryReelingTracker._f32'
     `295` 'MemoryReelingTracker._i32'
     `296` 'MemoryReelingTracker._read_pos'
     `297` 'MemoryReelingTracker._is_ptr'
     `298` 'MemoryReelingTracker._get_modules'
     `299` [1048576]
     `300` 'MemoryReelingTracker._pattern_scan'
     `301` 'MemoryReelingTracker._find_cped'
     `302` 'MemoryReelingTracker._find_replay_interface_global'
     `303` 'MemoryReelingTracker._read_entity_hash'
     `304` 'MemoryReelingTracker._find_fish_addr_replay'
     `305` 'MemoryReelingTracker._read_player_right_vec'
     `306` 'MemoryReelingTracker._cped_hint_range'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__memory_reeling\23e80bb70_MemoryReelingTracker._read.c`

### `MemoryReelingTracker._u64`

- implementation: `FUN_23e80c310`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `285` 'MemoryReelingTracker.start'
     `286` 'MemoryReelingTracker.stop'
     `287` 'step'
     `288` 'MemoryReelingTracker.step'
     `289` 'MemoryReelingTracker._hold_key'
     `290` 'MemoryReelingTracker._release_key'
     `291` 'MemoryReelingTracker._get_pid'
     `292` 'MemoryReelingTracker._read'
  => `293` 'MemoryReelingTracker._u64'
     `294` 'MemoryReelingTracker._f32'
     `295` 'MemoryReelingTracker._i32'
     `296` 'MemoryReelingTracker._read_pos'
     `297` 'MemoryReelingTracker._is_ptr'
     `298` 'MemoryReelingTracker._get_modules'
     `299` [1048576]
     `300` 'MemoryReelingTracker._pattern_scan'
     `301` 'MemoryReelingTracker._find_cped'
     `302` 'MemoryReelingTracker._find_replay_interface_global'
     `303` 'MemoryReelingTracker._read_entity_hash'
     `304` 'MemoryReelingTracker._find_fish_addr_replay'
     `305` 'MemoryReelingTracker._read_player_right_vec'
     `306` 'MemoryReelingTracker._cped_hint_range'
     `307` 'MemoryReelingTracker._collect_regions'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__memory_reeling\23e80c310_MemoryReelingTracker._u64.c`

### `MemoryReelingTracker._f32`

- implementation: `FUN_23e80c8c0`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `286` 'MemoryReelingTracker.stop'
     `287` 'step'
     `288` 'MemoryReelingTracker.step'
     `289` 'MemoryReelingTracker._hold_key'
     `290` 'MemoryReelingTracker._release_key'
     `291` 'MemoryReelingTracker._get_pid'
     `292` 'MemoryReelingTracker._read'
     `293` 'MemoryReelingTracker._u64'
  => `294` 'MemoryReelingTracker._f32'
     `295` 'MemoryReelingTracker._i32'
     `296` 'MemoryReelingTracker._read_pos'
     `297` 'MemoryReelingTracker._is_ptr'
     `298` 'MemoryReelingTracker._get_modules'
     `299` [1048576]
     `300` 'MemoryReelingTracker._pattern_scan'
     `301` 'MemoryReelingTracker._find_cped'
     `302` 'MemoryReelingTracker._find_replay_interface_global'
     `303` 'MemoryReelingTracker._read_entity_hash'
     `304` 'MemoryReelingTracker._find_fish_addr_replay'
     `305` 'MemoryReelingTracker._read_player_right_vec'
     `306` 'MemoryReelingTracker._cped_hint_range'
     `307` 'MemoryReelingTracker._collect_regions'
     `308` 'MemoryReelingTracker._find_fish_addr'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__memory_reeling\23e80c8c0_MemoryReelingTracker._f32.c`

### `MemoryReelingTracker._i32`

- implementation: `FUN_23e80db10`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `287` 'step'
     `288` 'MemoryReelingTracker.step'
     `289` 'MemoryReelingTracker._hold_key'
     `290` 'MemoryReelingTracker._release_key'
     `291` 'MemoryReelingTracker._get_pid'
     `292` 'MemoryReelingTracker._read'
     `293` 'MemoryReelingTracker._u64'
     `294` 'MemoryReelingTracker._f32'
  => `295` 'MemoryReelingTracker._i32'
     `296` 'MemoryReelingTracker._read_pos'
     `297` 'MemoryReelingTracker._is_ptr'
     `298` 'MemoryReelingTracker._get_modules'
     `299` [1048576]
     `300` 'MemoryReelingTracker._pattern_scan'
     `301` 'MemoryReelingTracker._find_cped'
     `302` 'MemoryReelingTracker._find_replay_interface_global'
     `303` 'MemoryReelingTracker._read_entity_hash'
     `304` 'MemoryReelingTracker._find_fish_addr_replay'
     `305` 'MemoryReelingTracker._read_player_right_vec'
     `306` 'MemoryReelingTracker._cped_hint_range'
     `307` 'MemoryReelingTracker._collect_regions'
     `308` 'MemoryReelingTracker._find_fish_addr'
     `309` 'MemoryReelingTracker._maybe_log_find_stats'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__memory_reeling\23e80db10_MemoryReelingTracker._i32.c`

### `MemoryReelingTracker._read_pos`

- implementation: `FUN_23e80dff0`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `288` 'MemoryReelingTracker.step'
     `289` 'MemoryReelingTracker._hold_key'
     `290` 'MemoryReelingTracker._release_key'
     `291` 'MemoryReelingTracker._get_pid'
     `292` 'MemoryReelingTracker._read'
     `293` 'MemoryReelingTracker._u64'
     `294` 'MemoryReelingTracker._f32'
     `295` 'MemoryReelingTracker._i32'
  => `296` 'MemoryReelingTracker._read_pos'
     `297` 'MemoryReelingTracker._is_ptr'
     `298` 'MemoryReelingTracker._get_modules'
     `299` [1048576]
     `300` 'MemoryReelingTracker._pattern_scan'
     `301` 'MemoryReelingTracker._find_cped'
     `302` 'MemoryReelingTracker._find_replay_interface_global'
     `303` 'MemoryReelingTracker._read_entity_hash'
     `304` 'MemoryReelingTracker._find_fish_addr_replay'
     `305` 'MemoryReelingTracker._read_player_right_vec'
     `306` 'MemoryReelingTracker._cped_hint_range'
     `307` 'MemoryReelingTracker._collect_regions'
     `308` 'MemoryReelingTracker._find_fish_addr'
     `309` 'MemoryReelingTracker._maybe_log_find_stats'
     `310` 'workers\\fishing\\memory_reeling.py'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__memory_reeling\23e80dff0_MemoryReelingTracker._read_pos.c`

### `MemoryReelingTracker._is_ptr`

- implementation: `FUN_23e810950`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `289` 'MemoryReelingTracker._hold_key'
     `290` 'MemoryReelingTracker._release_key'
     `291` 'MemoryReelingTracker._get_pid'
     `292` 'MemoryReelingTracker._read'
     `293` 'MemoryReelingTracker._u64'
     `294` 'MemoryReelingTracker._f32'
     `295` 'MemoryReelingTracker._i32'
     `296` 'MemoryReelingTracker._read_pos'
  => `297` 'MemoryReelingTracker._is_ptr'
     `298` 'MemoryReelingTracker._get_modules'
     `299` [1048576]
     `300` 'MemoryReelingTracker._pattern_scan'
     `301` 'MemoryReelingTracker._find_cped'
     `302` 'MemoryReelingTracker._find_replay_interface_global'
     `303` 'MemoryReelingTracker._read_entity_hash'
     `304` 'MemoryReelingTracker._find_fish_addr_replay'
     `305` 'MemoryReelingTracker._read_player_right_vec'
     `306` 'MemoryReelingTracker._cped_hint_range'
     `307` 'MemoryReelingTracker._collect_regions'
     `308` 'MemoryReelingTracker._find_fish_addr'
     `309` 'MemoryReelingTracker._maybe_log_find_stats'
     `310` 'workers\\fishing\\memory_reeling.py'
     `311` ['.0', 'lo', 'hi', 'rs']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__memory_reeling\23e810950_MemoryReelingTracker._is_ptr.c`

### `MemoryReelingTracker._get_modules`

- implementation: `FUN_23e8116a0`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `290` 'MemoryReelingTracker._release_key'
     `291` 'MemoryReelingTracker._get_pid'
     `292` 'MemoryReelingTracker._read'
     `293` 'MemoryReelingTracker._u64'
     `294` 'MemoryReelingTracker._f32'
     `295` 'MemoryReelingTracker._i32'
     `296` 'MemoryReelingTracker._read_pos'
     `297` 'MemoryReelingTracker._is_ptr'
  => `298` 'MemoryReelingTracker._get_modules'
     `299` [1048576]
     `300` 'MemoryReelingTracker._pattern_scan'
     `301` 'MemoryReelingTracker._find_cped'
     `302` 'MemoryReelingTracker._find_replay_interface_global'
     `303` 'MemoryReelingTracker._read_entity_hash'
     `304` 'MemoryReelingTracker._find_fish_addr_replay'
     `305` 'MemoryReelingTracker._read_player_right_vec'
     `306` 'MemoryReelingTracker._cped_hint_range'
     `307` 'MemoryReelingTracker._collect_regions'
     `308` 'MemoryReelingTracker._find_fish_addr'
     `309` 'MemoryReelingTracker._maybe_log_find_stats'
     `310` 'workers\\fishing\\memory_reeling.py'
     `311` ['.0', 'lo', 'hi', 'rs']
     `312` ['.0', 'lo', 'hi', 'vt']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__memory_reeling\23e8116a0_MemoryReelingTracker._get_modules.c`

### `MemoryReelingTracker._pattern_scan`

- implementation: `FUN_23e812d00`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `292` 'MemoryReelingTracker._read'
     `293` 'MemoryReelingTracker._u64'
     `294` 'MemoryReelingTracker._f32'
     `295` 'MemoryReelingTracker._i32'
     `296` 'MemoryReelingTracker._read_pos'
     `297` 'MemoryReelingTracker._is_ptr'
     `298` 'MemoryReelingTracker._get_modules'
     `299` [1048576]
  => `300` 'MemoryReelingTracker._pattern_scan'
     `301` 'MemoryReelingTracker._find_cped'
     `302` 'MemoryReelingTracker._find_replay_interface_global'
     `303` 'MemoryReelingTracker._read_entity_hash'
     `304` 'MemoryReelingTracker._find_fish_addr_replay'
     `305` 'MemoryReelingTracker._read_player_right_vec'
     `306` 'MemoryReelingTracker._cped_hint_range'
     `307` 'MemoryReelingTracker._collect_regions'
     `308` 'MemoryReelingTracker._find_fish_addr'
     `309` 'MemoryReelingTracker._maybe_log_find_stats'
     `310` 'workers\\fishing\\memory_reeling.py'
     `311` ['.0', 'lo', 'hi', 'rs']
     `312` ['.0', 'lo', 'hi', 'vt']
     `313` ['.0', 'j', 'pb', 'comb', 'i']
     `314` '<module workers.fishing.memory_reeling>'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__memory_reeling\23e812d00_MemoryReelingTracker._pattern_scan.c`

### `MemoryReelingTracker._find_cped`

- implementation: `FUN_23e813650`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `293` 'MemoryReelingTracker._u64'
     `294` 'MemoryReelingTracker._f32'
     `295` 'MemoryReelingTracker._i32'
     `296` 'MemoryReelingTracker._read_pos'
     `297` 'MemoryReelingTracker._is_ptr'
     `298` 'MemoryReelingTracker._get_modules'
     `299` [1048576]
     `300` 'MemoryReelingTracker._pattern_scan'
  => `301` 'MemoryReelingTracker._find_cped'
     `302` 'MemoryReelingTracker._find_replay_interface_global'
     `303` 'MemoryReelingTracker._read_entity_hash'
     `304` 'MemoryReelingTracker._find_fish_addr_replay'
     `305` 'MemoryReelingTracker._read_player_right_vec'
     `306` 'MemoryReelingTracker._cped_hint_range'
     `307` 'MemoryReelingTracker._collect_regions'
     `308` 'MemoryReelingTracker._find_fish_addr'
     `309` 'MemoryReelingTracker._maybe_log_find_stats'
     `310` 'workers\\fishing\\memory_reeling.py'
     `311` ['.0', 'lo', 'hi', 'rs']
     `312` ['.0', 'lo', 'hi', 'vt']
     `313` ['.0', 'j', 'pb', 'comb', 'i']
     `314` '<module workers.fishing.memory_reeling>'
     `315` ['__class__']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__memory_reeling\23e813650_MemoryReelingTracker._find_cped.c`

### `MemoryReelingTracker._find_replay_interface_global`

- implementation: `FUN_23e8186f0`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `294` 'MemoryReelingTracker._f32'
     `295` 'MemoryReelingTracker._i32'
     `296` 'MemoryReelingTracker._read_pos'
     `297` 'MemoryReelingTracker._is_ptr'
     `298` 'MemoryReelingTracker._get_modules'
     `299` [1048576]
     `300` 'MemoryReelingTracker._pattern_scan'
     `301` 'MemoryReelingTracker._find_cped'
  => `302` 'MemoryReelingTracker._find_replay_interface_global'
     `303` 'MemoryReelingTracker._read_entity_hash'
     `304` 'MemoryReelingTracker._find_fish_addr_replay'
     `305` 'MemoryReelingTracker._read_player_right_vec'
     `306` 'MemoryReelingTracker._cped_hint_range'
     `307` 'MemoryReelingTracker._collect_regions'
     `308` 'MemoryReelingTracker._find_fish_addr'
     `309` 'MemoryReelingTracker._maybe_log_find_stats'
     `310` 'workers\\fishing\\memory_reeling.py'
     `311` ['.0', 'lo', 'hi', 'rs']
     `312` ['.0', 'lo', 'hi', 'vt']
     `313` ['.0', 'j', 'pb', 'comb', 'i']
     `314` '<module workers.fishing.memory_reeling>'
     `315` ['__class__']
     `316` ['self', 'capture', 'log_callback']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__memory_reeling\23e8186f0_MemoryReelingTracker._find_replay_interface_global.c`

### `MemoryReelingTracker._read_entity_hash`

- implementation: `FUN_23e818f10`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `295` 'MemoryReelingTracker._i32'
     `296` 'MemoryReelingTracker._read_pos'
     `297` 'MemoryReelingTracker._is_ptr'
     `298` 'MemoryReelingTracker._get_modules'
     `299` [1048576]
     `300` 'MemoryReelingTracker._pattern_scan'
     `301` 'MemoryReelingTracker._find_cped'
     `302` 'MemoryReelingTracker._find_replay_interface_global'
  => `303` 'MemoryReelingTracker._read_entity_hash'
     `304` 'MemoryReelingTracker._find_fish_addr_replay'
     `305` 'MemoryReelingTracker._read_player_right_vec'
     `306` 'MemoryReelingTracker._cped_hint_range'
     `307` 'MemoryReelingTracker._collect_regions'
     `308` 'MemoryReelingTracker._find_fish_addr'
     `309` 'MemoryReelingTracker._maybe_log_find_stats'
     `310` 'workers\\fishing\\memory_reeling.py'
     `311` ['.0', 'lo', 'hi', 'rs']
     `312` ['.0', 'lo', 'hi', 'vt']
     `313` ['.0', 'j', 'pb', 'comb', 'i']
     `314` '<module workers.fishing.memory_reeling>'
     `315` ['__class__']
     `316` ['self', 'capture', 'log_callback']
     `317` ['self', 'hint_min', 'hint_max', 'key', 'cached', 'regions', 'addr', 'mbi', 'ret', 'rsz', 'rs', 'in_mod', 're', 'cur', 'end', 'nxt', 'na', 'out']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__memory_reeling\23e818f10_MemoryReelingTracker._read_entity_hash.c`

### `MemoryReelingTracker._find_fish_addr_replay`

- implementation: `FUN_23e81ccf0`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `296` 'MemoryReelingTracker._read_pos'
     `297` 'MemoryReelingTracker._is_ptr'
     `298` 'MemoryReelingTracker._get_modules'
     `299` [1048576]
     `300` 'MemoryReelingTracker._pattern_scan'
     `301` 'MemoryReelingTracker._find_cped'
     `302` 'MemoryReelingTracker._find_replay_interface_global'
     `303` 'MemoryReelingTracker._read_entity_hash'
  => `304` 'MemoryReelingTracker._find_fish_addr_replay'
     `305` 'MemoryReelingTracker._read_player_right_vec'
     `306` 'MemoryReelingTracker._cped_hint_range'
     `307` 'MemoryReelingTracker._collect_regions'
     `308` 'MemoryReelingTracker._find_fish_addr'
     `309` 'MemoryReelingTracker._maybe_log_find_stats'
     `310` 'workers\\fishing\\memory_reeling.py'
     `311` ['.0', 'lo', 'hi', 'rs']
     `312` ['.0', 'lo', 'hi', 'vt']
     `313` ['.0', 'j', 'pb', 'comb', 'i']
     `314` '<module workers.fishing.memory_reeling>'
     `315` ['__class__']
     `316` ['self', 'capture', 'log_callback']
     `317` ['self', 'hint_min', 'hint_max', 'key', 'cached', 'regions', 'addr', 'mbi', 'ret', 'rsz', 'rs', 'in_mod', 're', 'cur', 'end', 'nxt', 'na', 'out']
     `318` ['self', 'cped_addr', 'half', 'lo', 'hi']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__memory_reeling\23e81ccf0_MemoryReelingTracker._find_fish_addr_replay.c`

### `MemoryReelingTracker._read_player_right_vec`

- implementation: `FUN_23e81da40`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `297` 'MemoryReelingTracker._is_ptr'
     `298` 'MemoryReelingTracker._get_modules'
     `299` [1048576]
     `300` 'MemoryReelingTracker._pattern_scan'
     `301` 'MemoryReelingTracker._find_cped'
     `302` 'MemoryReelingTracker._find_replay_interface_global'
     `303` 'MemoryReelingTracker._read_entity_hash'
     `304` 'MemoryReelingTracker._find_fish_addr_replay'
  => `305` 'MemoryReelingTracker._read_player_right_vec'
     `306` 'MemoryReelingTracker._cped_hint_range'
     `307` 'MemoryReelingTracker._collect_regions'
     `308` 'MemoryReelingTracker._find_fish_addr'
     `309` 'MemoryReelingTracker._maybe_log_find_stats'
     `310` 'workers\\fishing\\memory_reeling.py'
     `311` ['.0', 'lo', 'hi', 'rs']
     `312` ['.0', 'lo', 'hi', 'vt']
     `313` ['.0', 'j', 'pb', 'comb', 'i']
     `314` '<module workers.fishing.memory_reeling>'
     `315` ['__class__']
     `316` ['self', 'capture', 'log_callback']
     `317` ['self', 'hint_min', 'hint_max', 'key', 'cached', 'regions', 'addr', 'mbi', 'ret', 'rsz', 'rs', 'in_mod', 're', 'cur', 'end', 'nxt', 'na', 'out']
     `318` ['self', 'cped_addr', 'half', 'lo', 'hi']
     `319` ['self', 'addr', 'd', 'v']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__memory_reeling\23e81da40_MemoryReelingTracker._read_player_right_vec.c`
