# Function Specification: `workers.fishing.hooking`

This is a reconstruction dossier from static Nuitka constants and Ghidra decompilation. It is not original Python source text.

## Source Path Hints
- `workers\fishing\hooking.py`

## Docstrings / Long Text
- `89` '\n        Нажать пробел когда найдены red или bubles шаблоны - МГНОВЕННЫЙ ответ\n        ОДНО нажатие на детекцию, затем пауза 30 сек\n        Возвращает: (red_confidence, bubles_confidence, red_detected, bubles_detected, pressed, trigger_reason, fps, paused)\n        '
- `116` '\nНажмите Enter для выхода...'
- `128` '\n'
- `169` '\nGTA5 Template Matching Monitor - Монитор поиска шаблонов\nРегион 1: Отслеживает появление red.png/red_2k.png и мгновенно нажимает Space\nРегион 2: Отслеживает появление bubles.png/bubles_2k.png и мгновенно нажимает Space\n'

## Function Inventory
| Inferred qualname | Impl | Source line | Arg count | Decompiled C |
|---|---:|---:|---:|---|
| `red.png` | `FUN_23e7a9c40` | 45 | 2 | yes |
| `red_2k.png` | `FUN_23e7aa110` | 49 | uVar9 | yes |
| `bubles.png` | `FUN_23e7abf50` | 75 | uVar9 | yes |
| `bubles_2k.png` | `FUN_23e7acc60` | 83 | uVar9 | yes |
| `WindowCapture.__init__` | `FUN_23e7af970` | 124 | 4 | yes |
| `WindowCapture.find_window_by_process` | `FUN_23e7b0240` | 142 | uVar23 | yes |
| `WindowCapture.get_window_size` | `FUN_23e7b22d0` | 167 | 4 | yes |
| `WindowCapture.capture` | `FUN_23e7b4360` | 194 | uVar9 | yes |
| `TemplateMonitor.__init__` | `FUN_23e7b6580` | 232 | uVar9 | yes |
| `TemplateMonitor.load_templates` | `FUN_23e7b73b0` | 246 | uVar23&0xffffffff00000000 | yes |

## Local Variable Lists
- `215` `__class__`
- `216` `self, roi1, roi2, resolution_type`
- `217` `self, process_name`
- `218` `hwnd, hwnds, _, pid, process, self`
- `219` `self`
- `220` `self, left, top, right, bottom, width, height, hwndDC, mfcDC, saveDC, saveBitMap, bmpinfo, bmpstr, img, e`
- `221` `self, frame, current_time, elapsed, remaining, red_confidence, red_detected, bubles_confidence, bubles_detected, pressed, trigger_reason`
- `223` `self, callback, hwnds, hwnd, title`
- `224` `self, left, top, right, bottom`
- `225` `self, e`
- `227` `self, frame, template, roi, x, y, w, h, roi_frame, result, min_val, max_val, min_loc, max_loc, pattern_detected`

## Structured Constants
- `16` [0, 0]
- `31` [True]
- `77` [0.0, False]
- `144` [1]
- `155` {'__dict_items__': [['end', ''], ['flush', True]]}
- `178` [1370, 982, 134, 15]
- `179` [1828, 1312, 171, 16]
- `180` [1361, 861, 56, 55]
- `181` [1817, 1148, 71, 71]
- `193` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
- `195` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
- `197` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
- `203` {'__dict_items__': [['roi1', {'__builtin__': 'tuple'}], ['roi2', {'__builtin__': 'tuple'}], ['resolution_type', {'__builtin__': 'str'}]]}
- `211` {'__dict_items__': [['width', {'__builtin__': 'int'}], ['height', {'__builtin__': 'int'}], ['return', {'__builtin__': 'tuple'}]]}

## Per-Function Context
### `red.png`

- implementation: `FUN_23e7a9c40`
- source line hint: `45`
- Nuitka codevar: `DAT_23eedab70`
- factory: `FUN_23e93e480`
- nearby constants:
     `178` [1370, 982, 134, 15]
     `179` [1828, 1312, 171, 16]
     `180` [1361, 861, 56, 55]
     `181` [1817, 1148, 71, 71]
     `182` 0.85
     `183` ['triger']
     `184` 'RESOURCES_DIR'
     `185` 'join'
  => `186` 'red.png'
     `187` 'red_2k.png'
     `188` 'bubles.png'
     `189` 'bubles_2k.png'
     `190` 'workers.fishing.hooking'
     `191` 'Захват скриншотов окна по имени процесса'
     `192` '__qualname__'
     `193` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
     `194` 'WindowCapture.__init__'
     `195` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `196` 'WindowCapture.find_window_by_process'
     `197` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `198` 'WindowCapture.get_window_size'
     `199` 'return'
     `200` 'ndarray'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__hooking\23e7a9c40_red.png.c`

### `red_2k.png`

- implementation: `FUN_23e7aa110`
- source line hint: `49`
- Nuitka codevar: `DAT_23eedab60`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `179` [1828, 1312, 171, 16]
     `180` [1361, 861, 56, 55]
     `181` [1817, 1148, 71, 71]
     `182` 0.85
     `183` ['triger']
     `184` 'RESOURCES_DIR'
     `185` 'join'
     `186` 'red.png'
  => `187` 'red_2k.png'
     `188` 'bubles.png'
     `189` 'bubles_2k.png'
     `190` 'workers.fishing.hooking'
     `191` 'Захват скриншотов окна по имени процесса'
     `192` '__qualname__'
     `193` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
     `194` 'WindowCapture.__init__'
     `195` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `196` 'WindowCapture.find_window_by_process'
     `197` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `198` 'WindowCapture.get_window_size'
     `199` 'return'
     `200` 'ndarray'
     `201` 'WindowCapture.capture'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__hooking\23e7aa110_red_2k.png.c`

### `bubles.png`

- implementation: `FUN_23e7abf50`
- source line hint: `75`
- Nuitka codevar: `_DAT_23eedab30`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `180` [1361, 861, 56, 55]
     `181` [1817, 1148, 71, 71]
     `182` 0.85
     `183` ['triger']
     `184` 'RESOURCES_DIR'
     `185` 'join'
     `186` 'red.png'
     `187` 'red_2k.png'
  => `188` 'bubles.png'
     `189` 'bubles_2k.png'
     `190` 'workers.fishing.hooking'
     `191` 'Захват скриншотов окна по имени процесса'
     `192` '__qualname__'
     `193` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
     `194` 'WindowCapture.__init__'
     `195` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `196` 'WindowCapture.find_window_by_process'
     `197` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `198` 'WindowCapture.get_window_size'
     `199` 'return'
     `200` 'ndarray'
     `201` 'WindowCapture.capture'
     `202` 'Отслеживает два региона: поиск red.png/red_2k.png и bubles.png/bubles_2k.png'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__hooking\23e7abf50_bubles.png.c`

### `bubles_2k.png`

- implementation: `FUN_23e7acc60`
- source line hint: `83`
- Nuitka codevar: `_DAT_23eedab20`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `181` [1817, 1148, 71, 71]
     `182` 0.85
     `183` ['triger']
     `184` 'RESOURCES_DIR'
     `185` 'join'
     `186` 'red.png'
     `187` 'red_2k.png'
     `188` 'bubles.png'
  => `189` 'bubles_2k.png'
     `190` 'workers.fishing.hooking'
     `191` 'Захват скриншотов окна по имени процесса'
     `192` '__qualname__'
     `193` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
     `194` 'WindowCapture.__init__'
     `195` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `196` 'WindowCapture.find_window_by_process'
     `197` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `198` 'WindowCapture.get_window_size'
     `199` 'return'
     `200` 'ndarray'
     `201` 'WindowCapture.capture'
     `202` 'Отслеживает два региона: поиск red.png/red_2k.png и bubles.png/bubles_2k.png'
     `203` {'__dict_items__': [['roi1', {'__builtin__': 'tuple'}], ['roi2', {'__builtin__': 'tuple'}], ['resolution_type', {'__builtin__': 'str'}]]}
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__hooking\23e7acc60_bubles_2k.png.c`

### `WindowCapture.__init__`

- implementation: `FUN_23e7af970`
- source line hint: `124`
- Nuitka codevar: `_DAT_23eedab08`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `186` 'red.png'
     `187` 'red_2k.png'
     `188` 'bubles.png'
     `189` 'bubles_2k.png'
     `190` 'workers.fishing.hooking'
     `191` 'Захват скриншотов окна по имени процесса'
     `192` '__qualname__'
     `193` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
  => `194` 'WindowCapture.__init__'
     `195` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `196` 'WindowCapture.find_window_by_process'
     `197` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `198` 'WindowCapture.get_window_size'
     `199` 'return'
     `200` 'ndarray'
     `201` 'WindowCapture.capture'
     `202` 'Отслеживает два региона: поиск red.png/red_2k.png и bubles.png/bubles_2k.png'
     `203` {'__dict_items__': [['roi1', {'__builtin__': 'tuple'}], ['roi2', {'__builtin__': 'tuple'}], ['resolution_type', {'__builtin__': 'str'}]]}
     `204` 'TemplateMonitor.__init__'
     `205` 'TemplateMonitor.load_templates'
     `206` 'frame'
     `207` 'template'
     `208` 'roi'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__hooking\23e7af970_WindowCapture.__init.c`

### `WindowCapture.find_window_by_process`

- implementation: `FUN_23e7b0240`
- source line hint: `142`
- Nuitka codevar: `_DAT_23eedaaf8`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `188` 'bubles.png'
     `189` 'bubles_2k.png'
     `190` 'workers.fishing.hooking'
     `191` 'Захват скриншотов окна по имени процесса'
     `192` '__qualname__'
     `193` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
     `194` 'WindowCapture.__init__'
     `195` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
  => `196` 'WindowCapture.find_window_by_process'
     `197` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `198` 'WindowCapture.get_window_size'
     `199` 'return'
     `200` 'ndarray'
     `201` 'WindowCapture.capture'
     `202` 'Отслеживает два региона: поиск red.png/red_2k.png и bubles.png/bubles_2k.png'
     `203` {'__dict_items__': [['roi1', {'__builtin__': 'tuple'}], ['roi2', {'__builtin__': 'tuple'}], ['resolution_type', {'__builtin__': 'str'}]]}
     `204` 'TemplateMonitor.__init__'
     `205` 'TemplateMonitor.load_templates'
     `206` 'frame'
     `207` 'template'
     `208` 'roi'
     `209` 'TemplateMonitor.match_template'
     `210` 'TemplateMonitor.check_and_act'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__hooking\23e7b0240_WindowCapture.find_window_by_process.c`

### `WindowCapture.get_window_size`

- implementation: `FUN_23e7b22d0`
- source line hint: `167`
- Nuitka codevar: `_DAT_23eedaac8`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `190` 'workers.fishing.hooking'
     `191` 'Захват скриншотов окна по имени процесса'
     `192` '__qualname__'
     `193` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
     `194` 'WindowCapture.__init__'
     `195` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `196` 'WindowCapture.find_window_by_process'
     `197` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
  => `198` 'WindowCapture.get_window_size'
     `199` 'return'
     `200` 'ndarray'
     `201` 'WindowCapture.capture'
     `202` 'Отслеживает два региона: поиск red.png/red_2k.png и bubles.png/bubles_2k.png'
     `203` {'__dict_items__': [['roi1', {'__builtin__': 'tuple'}], ['roi2', {'__builtin__': 'tuple'}], ['resolution_type', {'__builtin__': 'str'}]]}
     `204` 'TemplateMonitor.__init__'
     `205` 'TemplateMonitor.load_templates'
     `206` 'frame'
     `207` 'template'
     `208` 'roi'
     `209` 'TemplateMonitor.match_template'
     `210` 'TemplateMonitor.check_and_act'
     `211` {'__dict_items__': [['width', {'__builtin__': 'int'}], ['height', {'__builtin__': 'int'}], ['return', {'__builtin__': 'tuple'}]]}
     `212` 'main'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__hooking\23e7b22d0_WindowCapture.get_window_size.c`

### `WindowCapture.capture`

- implementation: `FUN_23e7b4360`
- source line hint: `194`
- Nuitka codevar: `_DAT_23eedaab8`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `193` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
     `194` 'WindowCapture.__init__'
     `195` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `196` 'WindowCapture.find_window_by_process'
     `197` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `198` 'WindowCapture.get_window_size'
     `199` 'return'
     `200` 'ndarray'
  => `201` 'WindowCapture.capture'
     `202` 'Отслеживает два региона: поиск red.png/red_2k.png и bubles.png/bubles_2k.png'
     `203` {'__dict_items__': [['roi1', {'__builtin__': 'tuple'}], ['roi2', {'__builtin__': 'tuple'}], ['resolution_type', {'__builtin__': 'str'}]]}
     `204` 'TemplateMonitor.__init__'
     `205` 'TemplateMonitor.load_templates'
     `206` 'frame'
     `207` 'template'
     `208` 'roi'
     `209` 'TemplateMonitor.match_template'
     `210` 'TemplateMonitor.check_and_act'
     `211` {'__dict_items__': [['width', {'__builtin__': 'int'}], ['height', {'__builtin__': 'int'}], ['return', {'__builtin__': 'tuple'}]]}
     `212` 'main'
     `213` 'workers\\fishing\\hooking.py'
     `214` '<module workers.fishing.hooking>'
     `215` ['__class__']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__hooking\23e7b4360_WindowCapture.capture.c`

### `TemplateMonitor.__init__`

- implementation: `FUN_23e7b6580`
- source line hint: `232`
- Nuitka codevar: `_DAT_23eedaaa8`
- factory: `FUN_23e93df40`
- nearby constants:
     `196` 'WindowCapture.find_window_by_process'
     `197` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `198` 'WindowCapture.get_window_size'
     `199` 'return'
     `200` 'ndarray'
     `201` 'WindowCapture.capture'
     `202` 'Отслеживает два региона: поиск red.png/red_2k.png и bubles.png/bubles_2k.png'
     `203` {'__dict_items__': [['roi1', {'__builtin__': 'tuple'}], ['roi2', {'__builtin__': 'tuple'}], ['resolution_type', {'__builtin__': 'str'}]]}
  => `204` 'TemplateMonitor.__init__'
     `205` 'TemplateMonitor.load_templates'
     `206` 'frame'
     `207` 'template'
     `208` 'roi'
     `209` 'TemplateMonitor.match_template'
     `210` 'TemplateMonitor.check_and_act'
     `211` {'__dict_items__': [['width', {'__builtin__': 'int'}], ['height', {'__builtin__': 'int'}], ['return', {'__builtin__': 'tuple'}]]}
     `212` 'main'
     `213` 'workers\\fishing\\hooking.py'
     `214` '<module workers.fishing.hooking>'
     `215` ['__class__']
     `216` ['self', 'roi1', 'roi2', 'resolution_type']
     `217` ['self', 'process_name']
     `218` ['hwnd', 'hwnds', '_', 'pid', 'process', 'self']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__hooking\23e7b6580_TemplateMonitor.__init.c`

### `TemplateMonitor.load_templates`

- implementation: `FUN_23e7b73b0`
- source line hint: `246`
- Nuitka codevar: `_DAT_23eedaa98`
- factory: `FUN_23e93df40`
- nearby constants:
     `197` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `198` 'WindowCapture.get_window_size'
     `199` 'return'
     `200` 'ndarray'
     `201` 'WindowCapture.capture'
     `202` 'Отслеживает два региона: поиск red.png/red_2k.png и bubles.png/bubles_2k.png'
     `203` {'__dict_items__': [['roi1', {'__builtin__': 'tuple'}], ['roi2', {'__builtin__': 'tuple'}], ['resolution_type', {'__builtin__': 'str'}]]}
     `204` 'TemplateMonitor.__init__'
  => `205` 'TemplateMonitor.load_templates'
     `206` 'frame'
     `207` 'template'
     `208` 'roi'
     `209` 'TemplateMonitor.match_template'
     `210` 'TemplateMonitor.check_and_act'
     `211` {'__dict_items__': [['width', {'__builtin__': 'int'}], ['height', {'__builtin__': 'int'}], ['return', {'__builtin__': 'tuple'}]]}
     `212` 'main'
     `213` 'workers\\fishing\\hooking.py'
     `214` '<module workers.fishing.hooking>'
     `215` ['__class__']
     `216` ['self', 'roi1', 'roi2', 'resolution_type']
     `217` ['self', 'process_name']
     `218` ['hwnd', 'hwnds', '_', 'pid', 'process', 'self']
     `219` ['self']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__hooking\23e7b73b0_TemplateMonitor.load_templates.c`
