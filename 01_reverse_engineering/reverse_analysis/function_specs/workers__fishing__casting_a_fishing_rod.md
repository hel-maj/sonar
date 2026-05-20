# Function Specification: `workers.fishing.casting_a_fishing_rod`

This is a reconstruction dossier from static Nuitka constants and Ghidra decompilation. It is not original Python source text.

## Source Path Hints
- `workers\fishing\casting_a_fishing_rod.py`

## Docstrings / Long Text
- `75` 'Вычислить минимальный bounding box всех зелёных пикселей внутри ROI.\n        Возвращает (x, y, w, h) в frame-координатах или None.'
- `84` '\n⬇ ЗЕЛЁНЫЕ: '
- `90` '\n⚡ ПИК: '
- `96` 'Вызывать каждый кадр. Возвращает (count, count, -1, detected, pressed, fps, paused_remaining).'
- `120` '\nНажмите Enter для выхода...'
- `131` '\n'
- `175` '\nGTA5 Green Pixel Monitor - Мониторинг зеленых пикселей\nОтслеживает регион для зеленых пикселей и нажимает Space когда они уменьшаются\n'
- `194` 'Мониторинг зелёных пикселей для заброса удочки.\n\n    Алгоритм (3 состояния):\n    SEARCHING → сканируем полный ROI каждый кадр;\n                как только нашли ≥ MIN_GREEN_PIXELS зелёных — вычисляем\n                tight bbox (минимальный прямоугольник вокруг всех зелёных\n                пикселей) и переходим в TRACKING.\n    TRACKING  → считаем зелёные только внутри tight bbox каждый кадр;\n                пока растёт — обновляем пик;\n                как только стал МЕНЬШЕ пика — мгн...

## Function Inventory
| Inferred qualname | Impl | Source line | Arg count | Decompiled C |
|---|---:|---:|---:|---|
| `WindowCapture.__init__` | `LAB_23e6f0c70` | 26 | 2 | yes |
| `WindowCapture.find_window_by_process` | `FUN_23e6f1140` | 30 | uVar9 | yes |
| `WindowCapture.get_window_size` | `FUN_23e6f2f80` | 56 | uVar21 | yes |
| `WindowCapture.capture` | `FUN_23e6f3c90` | 64 | uVar9 | yes |
| `GreenPixelMonitor.__init__` | `FUN_23e6f69a0` | 127 | 2 | yes |
| `GreenPixelMonitor._count_green` | `FUN_23e6f76a0` | 148 | 6 | yes |
| `GreenPixelMonitor._find_tight_bbox` | `FUN_23e6f84f0` | 155 | 2 | yes |
| `GreenPixelMonitor.check_and_act` | `FUN_23e6f9e00` | 172 | uVar9 | yes |
| `GreenPixelMonitor.count_green_pixels` | `FUN_23e6fd930` | 232 | uVar9 | yes |
| `?` | `FUN_23e6fe010` | 236 | uVar9 | yes |
| `?` | `FUN_23e6fed40` | 250 | uVar21&0xffffffff00000000 | yes |

## Local Variable Lists
- `216` `__class__`
- `217` `self, roi`
- `218` `self, process_name`
- `219` `self, frame, x, y, w, h, region, hsv, mask`
- `220` `self, frame, region, hsv, mask, coords, rx, ry, rw, rh`
- `221` `hwnd, hwnds, _, pid, process, self`
- `222` `self`
- `223` `self, left, top, right, bottom, width, height, hwndDC, mfcDC, saveDC, saveBitMap, bmpinfo, bmpstr, img, e`
- `224` `self, frame, now, remaining, count, bbox, bx, by, bw, bh, elapsed`
- `225` `self, frame`
- `227` `self, callback, hwnds, hwnd, title`
- `228` `self, left, top, right, bottom`

## Structured Constants
- `16` [0, 0]
- `31` [True]
- `151` [1]
- `162` {'__dict_items__': [['end', ''], ['flush', True]]}
- `180` [690, 891, 539, 11]
- `181` [913, 1186, 735, 20]
- `185` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
- `187` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
- `189` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
- `202` {'__dict_items__': [['roi', {'__builtin__': 'tuple'}]]}
- `212` {'__dict_items__': [['width', {'__builtin__': 'int'}], ['height', {'__builtin__': 'int'}], ['return', {'__builtin__': 'tuple'}]]}

## Per-Function Context
### `WindowCapture.__init__`

- implementation: `LAB_23e6f0c70`
- source line hint: `26`
- Nuitka codevar: `DAT_23eedb260`
- factory: `FUN_23e93e480`
- nearby constants:
     `178` 'numpy'
     `179` 'sys'
     `180` [690, 891, 539, 11]
     `181` [913, 1186, 735, 20]
     `182` 'workers.fishing.casting_a_fishing_rod'
     `183` 'Захват скриншотов окна по имени процесса'
     `184` '__qualname__'
     `185` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
  => `186` 'WindowCapture.__init__'
     `187` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `188` 'WindowCapture.find_window_by_process'
     `189` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `190` 'WindowCapture.get_window_size'
     `191` 'return'
     `192` 'ndarray'
     `193` 'WindowCapture.capture'
     `194` 'Мониторинг зелёных пикселей для заброса удочки.\n\n    Алгоритм (3 состояния):\n    SEARCHING → сканируем полный ROI каждый кадр;\n                как только нашли ≥ MIN_GREEN_PIXELS зелёных — вычисляем\n                tight bbox (минимальный прямоугольник вокруг всех зелёны...
     `195` 'array'
     `196` 40
     `197` 80
     `198` 255
     `199` 15
     `200` 10.0
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__casting_a_fishing_rod\23e6f0c70_WindowCapture.__init.c`

### `WindowCapture.find_window_by_process`

- implementation: `FUN_23e6f1140`
- source line hint: `30`
- Nuitka codevar: `_DAT_23eedb250`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `180` [690, 891, 539, 11]
     `181` [913, 1186, 735, 20]
     `182` 'workers.fishing.casting_a_fishing_rod'
     `183` 'Захват скриншотов окна по имени процесса'
     `184` '__qualname__'
     `185` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
     `186` 'WindowCapture.__init__'
     `187` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
  => `188` 'WindowCapture.find_window_by_process'
     `189` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `190` 'WindowCapture.get_window_size'
     `191` 'return'
     `192` 'ndarray'
     `193` 'WindowCapture.capture'
     `194` 'Мониторинг зелёных пикселей для заброса удочки.\n\n    Алгоритм (3 состояния):\n    SEARCHING → сканируем полный ROI каждый кадр;\n                как только нашли ≥ MIN_GREEN_PIXELS зелёных — вычисляем\n                tight bbox (минимальный прямоугольник вокруг всех зелёны...
     `195` 'array'
     `196` 40
     `197` 80
     `198` 255
     `199` 15
     `200` 10.0
     `201` 3.0
     `202` {'__dict_items__': [['roi', {'__builtin__': 'tuple'}]]}
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__casting_a_fishing_rod\23e6f1140_WindowCapture.find_window_by_process.c`

### `WindowCapture.get_window_size`

- implementation: `FUN_23e6f2f80`
- source line hint: `56`
- Nuitka codevar: `_DAT_23eedb220`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `182` 'workers.fishing.casting_a_fishing_rod'
     `183` 'Захват скриншотов окна по имени процесса'
     `184` '__qualname__'
     `185` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
     `186` 'WindowCapture.__init__'
     `187` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `188` 'WindowCapture.find_window_by_process'
     `189` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
  => `190` 'WindowCapture.get_window_size'
     `191` 'return'
     `192` 'ndarray'
     `193` 'WindowCapture.capture'
     `194` 'Мониторинг зелёных пикселей для заброса удочки.\n\n    Алгоритм (3 состояния):\n    SEARCHING → сканируем полный ROI каждый кадр;\n                как только нашли ≥ MIN_GREEN_PIXELS зелёных — вычисляем\n                tight bbox (минимальный прямоугольник вокруг всех зелёны...
     `195` 'array'
     `196` 40
     `197` 80
     `198` 255
     `199` 15
     `200` 10.0
     `201` 3.0
     `202` {'__dict_items__': [['roi', {'__builtin__': 'tuple'}]]}
     `203` 'GreenPixelMonitor.__init__'
     `204` 'frame'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__casting_a_fishing_rod\23e6f2f80_WindowCapture.get_window_size.c`

### `WindowCapture.capture`

- implementation: `FUN_23e6f3c90`
- source line hint: `64`
- Nuitka codevar: `_DAT_23eedb210`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `185` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
     `186` 'WindowCapture.__init__'
     `187` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `188` 'WindowCapture.find_window_by_process'
     `189` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `190` 'WindowCapture.get_window_size'
     `191` 'return'
     `192` 'ndarray'
  => `193` 'WindowCapture.capture'
     `194` 'Мониторинг зелёных пикселей для заброса удочки.\n\n    Алгоритм (3 состояния):\n    SEARCHING → сканируем полный ROI каждый кадр;\n                как только нашли ≥ MIN_GREEN_PIXELS зелёных — вычисляем\n                tight bbox (минимальный прямоугольник вокруг всех зелёны...
     `195` 'array'
     `196` 40
     `197` 80
     `198` 255
     `199` 15
     `200` 10.0
     `201` 3.0
     `202` {'__dict_items__': [['roi', {'__builtin__': 'tuple'}]]}
     `203` 'GreenPixelMonitor.__init__'
     `204` 'frame'
     `205` 'y'
     `206` 'h'
     `207` 'GreenPixelMonitor._count_green'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__casting_a_fishing_rod\23e6f3c90_WindowCapture.capture.c`

### `GreenPixelMonitor.__init__`

- implementation: `FUN_23e6f69a0`
- source line hint: `127`
- Nuitka codevar: `_DAT_23eedb1f8`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `195` 'array'
     `196` 40
     `197` 80
     `198` 255
     `199` 15
     `200` 10.0
     `201` 3.0
     `202` {'__dict_items__': [['roi', {'__builtin__': 'tuple'}]]}
  => `203` 'GreenPixelMonitor.__init__'
     `204` 'frame'
     `205` 'y'
     `206` 'h'
     `207` 'GreenPixelMonitor._count_green'
     `208` 'GreenPixelMonitor._find_tight_bbox'
     `209` 'GreenPixelMonitor.check_and_act'
     `210` 'count_green_pixels'
     `211` 'GreenPixelMonitor.count_green_pixels'
     `212` {'__dict_items__': [['width', {'__builtin__': 'int'}], ['height', {'__builtin__': 'int'}], ['return', {'__builtin__': 'tuple'}]]}
     `213` 'main'
     `214` 'workers\\fishing\\casting_a_fishing_rod.py'
     `215` '<module workers.fishing.casting_a_fishing_rod>'
     `216` ['__class__']
     `217` ['self', 'roi']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__casting_a_fishing_rod\23e6f69a0_GreenPixelMonitor.__init.c`

### `GreenPixelMonitor._count_green`

- implementation: `FUN_23e6f76a0`
- source line hint: `148`
- Nuitka codevar: `_DAT_23eedb1e8`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `199` 15
     `200` 10.0
     `201` 3.0
     `202` {'__dict_items__': [['roi', {'__builtin__': 'tuple'}]]}
     `203` 'GreenPixelMonitor.__init__'
     `204` 'frame'
     `205` 'y'
     `206` 'h'
  => `207` 'GreenPixelMonitor._count_green'
     `208` 'GreenPixelMonitor._find_tight_bbox'
     `209` 'GreenPixelMonitor.check_and_act'
     `210` 'count_green_pixels'
     `211` 'GreenPixelMonitor.count_green_pixels'
     `212` {'__dict_items__': [['width', {'__builtin__': 'int'}], ['height', {'__builtin__': 'int'}], ['return', {'__builtin__': 'tuple'}]]}
     `213` 'main'
     `214` 'workers\\fishing\\casting_a_fishing_rod.py'
     `215` '<module workers.fishing.casting_a_fishing_rod>'
     `216` ['__class__']
     `217` ['self', 'roi']
     `218` ['self', 'process_name']
     `219` ['self', 'frame', 'x', 'y', 'w', 'h', 'region', 'hsv', 'mask']
     `220` ['self', 'frame', 'region', 'hsv', 'mask', 'coords', 'rx', 'ry', 'rw', 'rh']
     `221` ['hwnd', 'hwnds', '_', 'pid', 'process', 'self']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__casting_a_fishing_rod\23e6f76a0_GreenPixelMonitor._count_green.c`

### `GreenPixelMonitor._find_tight_bbox`

- implementation: `FUN_23e6f84f0`
- source line hint: `155`
- Nuitka codevar: `DAT_23eedb1d8`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `200` 10.0
     `201` 3.0
     `202` {'__dict_items__': [['roi', {'__builtin__': 'tuple'}]]}
     `203` 'GreenPixelMonitor.__init__'
     `204` 'frame'
     `205` 'y'
     `206` 'h'
     `207` 'GreenPixelMonitor._count_green'
  => `208` 'GreenPixelMonitor._find_tight_bbox'
     `209` 'GreenPixelMonitor.check_and_act'
     `210` 'count_green_pixels'
     `211` 'GreenPixelMonitor.count_green_pixels'
     `212` {'__dict_items__': [['width', {'__builtin__': 'int'}], ['height', {'__builtin__': 'int'}], ['return', {'__builtin__': 'tuple'}]]}
     `213` 'main'
     `214` 'workers\\fishing\\casting_a_fishing_rod.py'
     `215` '<module workers.fishing.casting_a_fishing_rod>'
     `216` ['__class__']
     `217` ['self', 'roi']
     `218` ['self', 'process_name']
     `219` ['self', 'frame', 'x', 'y', 'w', 'h', 'region', 'hsv', 'mask']
     `220` ['self', 'frame', 'region', 'hsv', 'mask', 'coords', 'rx', 'ry', 'rw', 'rh']
     `221` ['hwnd', 'hwnds', '_', 'pid', 'process', 'self']
     `222` ['self']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__casting_a_fishing_rod\23e6f84f0_GreenPixelMonitor._find_tight_bbox.c`

### `GreenPixelMonitor.check_and_act`

- implementation: `FUN_23e6f9e00`
- source line hint: `172`
- Nuitka codevar: `DAT_23eedb1c8`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `201` 3.0
     `202` {'__dict_items__': [['roi', {'__builtin__': 'tuple'}]]}
     `203` 'GreenPixelMonitor.__init__'
     `204` 'frame'
     `205` 'y'
     `206` 'h'
     `207` 'GreenPixelMonitor._count_green'
     `208` 'GreenPixelMonitor._find_tight_bbox'
  => `209` 'GreenPixelMonitor.check_and_act'
     `210` 'count_green_pixels'
     `211` 'GreenPixelMonitor.count_green_pixels'
     `212` {'__dict_items__': [['width', {'__builtin__': 'int'}], ['height', {'__builtin__': 'int'}], ['return', {'__builtin__': 'tuple'}]]}
     `213` 'main'
     `214` 'workers\\fishing\\casting_a_fishing_rod.py'
     `215` '<module workers.fishing.casting_a_fishing_rod>'
     `216` ['__class__']
     `217` ['self', 'roi']
     `218` ['self', 'process_name']
     `219` ['self', 'frame', 'x', 'y', 'w', 'h', 'region', 'hsv', 'mask']
     `220` ['self', 'frame', 'region', 'hsv', 'mask', 'coords', 'rx', 'ry', 'rw', 'rh']
     `221` ['hwnd', 'hwnds', '_', 'pid', 'process', 'self']
     `222` ['self']
     `223` ['self', 'left', 'top', 'right', 'bottom', 'width', 'height', 'hwndDC', 'mfcDC', 'saveDC', 'saveBitMap', 'bmpinfo', 'bmpstr', 'img', 'e']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__casting_a_fishing_rod\23e6f9e00_GreenPixelMonitor.check_and_act.c`

### `GreenPixelMonitor.count_green_pixels`

- implementation: `FUN_23e6fd930`
- source line hint: `232`
- Nuitka codevar: `_DAT_23eedb1b8`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `203` 'GreenPixelMonitor.__init__'
     `204` 'frame'
     `205` 'y'
     `206` 'h'
     `207` 'GreenPixelMonitor._count_green'
     `208` 'GreenPixelMonitor._find_tight_bbox'
     `209` 'GreenPixelMonitor.check_and_act'
     `210` 'count_green_pixels'
  => `211` 'GreenPixelMonitor.count_green_pixels'
     `212` {'__dict_items__': [['width', {'__builtin__': 'int'}], ['height', {'__builtin__': 'int'}], ['return', {'__builtin__': 'tuple'}]]}
     `213` 'main'
     `214` 'workers\\fishing\\casting_a_fishing_rod.py'
     `215` '<module workers.fishing.casting_a_fishing_rod>'
     `216` ['__class__']
     `217` ['self', 'roi']
     `218` ['self', 'process_name']
     `219` ['self', 'frame', 'x', 'y', 'w', 'h', 'region', 'hsv', 'mask']
     `220` ['self', 'frame', 'region', 'hsv', 'mask', 'coords', 'rx', 'ry', 'rw', 'rh']
     `221` ['hwnd', 'hwnds', '_', 'pid', 'process', 'self']
     `222` ['self']
     `223` ['self', 'left', 'top', 'right', 'bottom', 'width', 'height', 'hwndDC', 'mfcDC', 'saveDC', 'saveBitMap', 'bmpinfo', 'bmpstr', 'img', 'e']
     `224` ['self', 'frame', 'now', 'remaining', 'count', 'bbox', 'bx', 'by', 'bw', 'bh', 'elapsed']
     `225` ['self', 'frame']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__casting_a_fishing_rod\23e6fd930_GreenPixelMonitor.count_green_pixels.c`

### `?`

- implementation: `FUN_23e6fe010`
- source line hint: `236`
- Nuitka codevar: `_DAT_23eedb1a8`
- factory: `FUN_23e93df40`
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__casting_a_fishing_rod\23e6fe010_unknown.c`

### `?`

- implementation: `FUN_23e6fed40`
- source line hint: `250`
- Nuitka codevar: `_DAT_23eedb198`
- factory: `FUN_23e93df40`
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__casting_a_fishing_rod\23e6fed40_unknown.c`
