# Function Specification: `workers.fishing.fish_recognition`

This is a reconstruction dossier from static Nuitka constants and Ghidra decompilation. It is not original Python source text.

## Source Path Hints
- `workers\fishing\fish_recognition.py`

## Docstrings / Long Text
- `105` '\n        Найти шаблон на скриншоте\n        Возвращает (найдено, x_центр, y_центр, уверенность)\n        '
- `110` '\n        Распознать рыбу на скриншоте\n        Возвращает (имя_рыбы, уверенность) или (None, 0)\n        '
- `116` '\n✅ Распознана рыба: '
- `121` '\n        Одноразовое распознавание рыбы\n        Возвращает (имя_рыбы, уверенность) или (None, 0)\n        '
- `141` '\nGTA5 Fish Recognition - Распознавание пойманной рыбы\nАвтоматически определяет какая рыба была поймана\n'

## Function Inventory
| Inferred qualname | Impl | Source line | Arg count | Decompiled C |
|---|---:|---:|---:|---|
| `WindowCapture.__init__` | `FUN_23e70a5b0` | 31 | 2 | yes |
| `WindowCapture.find_window_by_process` | `FUN_23e70aa80` | 35 | uVar8 | yes |
| `WindowCapture.get_window_size` | `FUN_23e70c8c0` | 61 | uVar8 | yes |
| `WindowCapture.capture` | `FUN_23e70d5d0` | 69 | uVar8 | yes |
| `FishRecognition.__init__` | `FUN_23e7105f0` | 111 | 1 | yes |
| `FishRecognition.initialize` | `FUN_23e710eb0` | 119 | uVar8 | yes |
| `FishRecognition.load_templates` | `FUN_23e7127f0` | 154 | uVar22 | yes |
| `FishRecognition.find_template` | `FUN_23e714780` | 184 | uVar8 | yes |
| `FishRecognition.recognize_fish` | `FUN_23e716990` | 218 | 2 | yes |
| `FishRecognition.recognize_once` | `FUN_23e718390` | 238 | 1 | yes |
| `FishRecognition.run` | `FUN_23e719590` | 262 | 1 | yes |
| `?` | `FUN_23e71acf0` | 286 | uVar22&0xffffffff00000000 | yes |

## Local Variable Lists
- `181` `__class__`
- `182` `self`
- `183` `self, process_name`
- `184` `hwnd, hwnds, _, pid, process, self`
- `185` `self, left, top, right, bottom, width, height, hwndDC, mfcDC, saveDC, saveBitMap, bmpinfo, bmpstr, img, e`
- `186` `self, screenshot, template, roi, search_area, result, min_val, max_val, min_loc, max_loc, h, w, center_x, center_y`
- `187` `self, callback, hwnds, hwnd, title`
- `188` `self, left, top, right, bottom`
- `189` `self, width, height`
- `190` `self, template_path, fish_count, file_path, template`
- `192` `self, screenshot, best_match, best_confidence, fish_template, found, x, y, confidence`
- `193` `self, screenshot, fish_name, confidence`
- `194` `self, fish_name, confidence`

## Structured Constants
- `16` [0, 0]
- `31` [True]
- `103` {'__slice__': [None, 2, None]}
- `113` [None, 0.0]
- `153` {'__dict_items__': [['x', 778], ['y', 373], ['width', 368], ['height', 232]]}
- `154` {'__dict_items__': [['x', 1037], ['y', 497], ['width', 492], ['height', 310]]}
- `159` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
- `161` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
- `163` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
- `172` [None]

## Per-Function Context
### `WindowCapture.__init__`

- implementation: `FUN_23e70a5b0`
- source line hint: `31`
- Nuitka codevar: `DAT_23eedb140`
- factory: `FUN_23e93e480`
- nearby constants:
     `152` ['get_fishing_resources']
     `153` {'__dict_items__': [['x', 778], ['y', 373], ['width', 368], ['height', 232]]}
     `154` {'__dict_items__': [['x', 1037], ['y', 497], ['width', 492], ['height', 310]]}
     `155` 0.63
     `156` 'workers.fishing.fish_recognition'
     `157` 'Захват скриншотов окна по имени процесса'
     `158` '__qualname__'
     `159` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
  => `160` 'WindowCapture.__init__'
     `161` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `162` 'WindowCapture.find_window_by_process'
     `163` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `164` 'WindowCapture.get_window_size'
     `165` 'return'
     `166` 'ndarray'
     `167` 'WindowCapture.capture'
     `168` 'Класс для распознавания пойманной рыбы'
     `169` 'FishRecognition.__init__'
     `170` 'FishRecognition.initialize'
     `171` 'FishRecognition.load_templates'
     `172` [None]
     `173` 'template'
     `174` 'FishRecognition.find_template'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fish_recognition\23e70a5b0_WindowCapture.__init.c`

### `WindowCapture.find_window_by_process`

- implementation: `FUN_23e70aa80`
- source line hint: `35`
- Nuitka codevar: `DAT_23eedb130`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `154` {'__dict_items__': [['x', 1037], ['y', 497], ['width', 492], ['height', 310]]}
     `155` 0.63
     `156` 'workers.fishing.fish_recognition'
     `157` 'Захват скриншотов окна по имени процесса'
     `158` '__qualname__'
     `159` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
     `160` 'WindowCapture.__init__'
     `161` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
  => `162` 'WindowCapture.find_window_by_process'
     `163` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `164` 'WindowCapture.get_window_size'
     `165` 'return'
     `166` 'ndarray'
     `167` 'WindowCapture.capture'
     `168` 'Класс для распознавания пойманной рыбы'
     `169` 'FishRecognition.__init__'
     `170` 'FishRecognition.initialize'
     `171` 'FishRecognition.load_templates'
     `172` [None]
     `173` 'template'
     `174` 'FishRecognition.find_template'
     `175` 'FishRecognition.recognize_fish'
     `176` 'FishRecognition.recognize_once'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fish_recognition\23e70aa80_WindowCapture.find_window_by_process.c`

### `WindowCapture.get_window_size`

- implementation: `FUN_23e70c8c0`
- source line hint: `61`
- Nuitka codevar: `_DAT_23eedb100`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `156` 'workers.fishing.fish_recognition'
     `157` 'Захват скриншотов окна по имени процесса'
     `158` '__qualname__'
     `159` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
     `160` 'WindowCapture.__init__'
     `161` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `162` 'WindowCapture.find_window_by_process'
     `163` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
  => `164` 'WindowCapture.get_window_size'
     `165` 'return'
     `166` 'ndarray'
     `167` 'WindowCapture.capture'
     `168` 'Класс для распознавания пойманной рыбы'
     `169` 'FishRecognition.__init__'
     `170` 'FishRecognition.initialize'
     `171` 'FishRecognition.load_templates'
     `172` [None]
     `173` 'template'
     `174` 'FishRecognition.find_template'
     `175` 'FishRecognition.recognize_fish'
     `176` 'FishRecognition.recognize_once'
     `177` 'FishRecognition.run'
     `178` 'main'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fish_recognition\23e70c8c0_WindowCapture.get_window_size.c`

### `WindowCapture.capture`

- implementation: `FUN_23e70d5d0`
- source line hint: `69`
- Nuitka codevar: `_DAT_23eedb0f0`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `159` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
     `160` 'WindowCapture.__init__'
     `161` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `162` 'WindowCapture.find_window_by_process'
     `163` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `164` 'WindowCapture.get_window_size'
     `165` 'return'
     `166` 'ndarray'
  => `167` 'WindowCapture.capture'
     `168` 'Класс для распознавания пойманной рыбы'
     `169` 'FishRecognition.__init__'
     `170` 'FishRecognition.initialize'
     `171` 'FishRecognition.load_templates'
     `172` [None]
     `173` 'template'
     `174` 'FishRecognition.find_template'
     `175` 'FishRecognition.recognize_fish'
     `176` 'FishRecognition.recognize_once'
     `177` 'FishRecognition.run'
     `178` 'main'
     `179` 'workers\\fishing\\fish_recognition.py'
     `180` '<module workers.fishing.fish_recognition>'
     `181` ['__class__']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fish_recognition\23e70d5d0_WindowCapture.capture.c`

### `FishRecognition.__init__`

- implementation: `FUN_23e7105f0`
- source line hint: `111`
- Nuitka codevar: `_DAT_23eedb0d8`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `161` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `162` 'WindowCapture.find_window_by_process'
     `163` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `164` 'WindowCapture.get_window_size'
     `165` 'return'
     `166` 'ndarray'
     `167` 'WindowCapture.capture'
     `168` 'Класс для распознавания пойманной рыбы'
  => `169` 'FishRecognition.__init__'
     `170` 'FishRecognition.initialize'
     `171` 'FishRecognition.load_templates'
     `172` [None]
     `173` 'template'
     `174` 'FishRecognition.find_template'
     `175` 'FishRecognition.recognize_fish'
     `176` 'FishRecognition.recognize_once'
     `177` 'FishRecognition.run'
     `178` 'main'
     `179` 'workers\\fishing\\fish_recognition.py'
     `180` '<module workers.fishing.fish_recognition>'
     `181` ['__class__']
     `182` ['self']
     `183` ['self', 'process_name']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fish_recognition\23e7105f0_FishRecognition.__init.c`

### `FishRecognition.initialize`

- implementation: `FUN_23e710eb0`
- source line hint: `119`
- Nuitka codevar: `_DAT_23eedb0b8`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `162` 'WindowCapture.find_window_by_process'
     `163` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `164` 'WindowCapture.get_window_size'
     `165` 'return'
     `166` 'ndarray'
     `167` 'WindowCapture.capture'
     `168` 'Класс для распознавания пойманной рыбы'
     `169` 'FishRecognition.__init__'
  => `170` 'FishRecognition.initialize'
     `171` 'FishRecognition.load_templates'
     `172` [None]
     `173` 'template'
     `174` 'FishRecognition.find_template'
     `175` 'FishRecognition.recognize_fish'
     `176` 'FishRecognition.recognize_once'
     `177` 'FishRecognition.run'
     `178` 'main'
     `179` 'workers\\fishing\\fish_recognition.py'
     `180` '<module workers.fishing.fish_recognition>'
     `181` ['__class__']
     `182` ['self']
     `183` ['self', 'process_name']
     `184` ['hwnd', 'hwnds', '_', 'pid', 'process', 'self']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fish_recognition\23e710eb0_FishRecognition.initialize.c`

### `FishRecognition.load_templates`

- implementation: `FUN_23e7127f0`
- source line hint: `154`
- Nuitka codevar: `_DAT_23eedb098`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `163` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `164` 'WindowCapture.get_window_size'
     `165` 'return'
     `166` 'ndarray'
     `167` 'WindowCapture.capture'
     `168` 'Класс для распознавания пойманной рыбы'
     `169` 'FishRecognition.__init__'
     `170` 'FishRecognition.initialize'
  => `171` 'FishRecognition.load_templates'
     `172` [None]
     `173` 'template'
     `174` 'FishRecognition.find_template'
     `175` 'FishRecognition.recognize_fish'
     `176` 'FishRecognition.recognize_once'
     `177` 'FishRecognition.run'
     `178` 'main'
     `179` 'workers\\fishing\\fish_recognition.py'
     `180` '<module workers.fishing.fish_recognition>'
     `181` ['__class__']
     `182` ['self']
     `183` ['self', 'process_name']
     `184` ['hwnd', 'hwnds', '_', 'pid', 'process', 'self']
     `185` ['self', 'left', 'top', 'right', 'bottom', 'width', 'height', 'hwndDC', 'mfcDC', 'saveDC', 'saveBitMap', 'bmpinfo', 'bmpstr', 'img', 'e']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fish_recognition\23e7127f0_FishRecognition.load_templates.c`

### `FishRecognition.find_template`

- implementation: `FUN_23e714780`
- source line hint: `184`
- Nuitka codevar: `uVar2`
- factory: `FUN_23e93e480`
- nearby constants:
     `166` 'ndarray'
     `167` 'WindowCapture.capture'
     `168` 'Класс для распознавания пойманной рыбы'
     `169` 'FishRecognition.__init__'
     `170` 'FishRecognition.initialize'
     `171` 'FishRecognition.load_templates'
     `172` [None]
     `173` 'template'
  => `174` 'FishRecognition.find_template'
     `175` 'FishRecognition.recognize_fish'
     `176` 'FishRecognition.recognize_once'
     `177` 'FishRecognition.run'
     `178` 'main'
     `179` 'workers\\fishing\\fish_recognition.py'
     `180` '<module workers.fishing.fish_recognition>'
     `181` ['__class__']
     `182` ['self']
     `183` ['self', 'process_name']
     `184` ['hwnd', 'hwnds', '_', 'pid', 'process', 'self']
     `185` ['self', 'left', 'top', 'right', 'bottom', 'width', 'height', 'hwndDC', 'mfcDC', 'saveDC', 'saveBitMap', 'bmpinfo', 'bmpstr', 'img', 'e']
     `186` ['self', 'screenshot', 'template', 'roi', 'search_area', 'result', 'min_val', 'max_val', 'min_loc', 'max_loc', 'h', 'w', 'center_x', 'center_y']
     `187` ['self', 'callback', 'hwnds', 'hwnd', 'title']
     `188` ['self', 'left', 'top', 'right', 'bottom']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fish_recognition\23e714780_FishRecognition.find_template.c`

### `FishRecognition.recognize_fish`

- implementation: `FUN_23e716990`
- source line hint: `218`
- Nuitka codevar: `_DAT_23eedb070`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `167` 'WindowCapture.capture'
     `168` 'Класс для распознавания пойманной рыбы'
     `169` 'FishRecognition.__init__'
     `170` 'FishRecognition.initialize'
     `171` 'FishRecognition.load_templates'
     `172` [None]
     `173` 'template'
     `174` 'FishRecognition.find_template'
  => `175` 'FishRecognition.recognize_fish'
     `176` 'FishRecognition.recognize_once'
     `177` 'FishRecognition.run'
     `178` 'main'
     `179` 'workers\\fishing\\fish_recognition.py'
     `180` '<module workers.fishing.fish_recognition>'
     `181` ['__class__']
     `182` ['self']
     `183` ['self', 'process_name']
     `184` ['hwnd', 'hwnds', '_', 'pid', 'process', 'self']
     `185` ['self', 'left', 'top', 'right', 'bottom', 'width', 'height', 'hwndDC', 'mfcDC', 'saveDC', 'saveBitMap', 'bmpinfo', 'bmpstr', 'img', 'e']
     `186` ['self', 'screenshot', 'template', 'roi', 'search_area', 'result', 'min_val', 'max_val', 'min_loc', 'max_loc', 'h', 'w', 'center_x', 'center_y']
     `187` ['self', 'callback', 'hwnds', 'hwnd', 'title']
     `188` ['self', 'left', 'top', 'right', 'bottom']
     `189` ['self', 'width', 'height']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fish_recognition\23e716990_FishRecognition.recognize_fish.c`

### `FishRecognition.recognize_once`

- implementation: `FUN_23e718390`
- source line hint: `238`
- Nuitka codevar: `DAT_23eedb060`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `168` 'Класс для распознавания пойманной рыбы'
     `169` 'FishRecognition.__init__'
     `170` 'FishRecognition.initialize'
     `171` 'FishRecognition.load_templates'
     `172` [None]
     `173` 'template'
     `174` 'FishRecognition.find_template'
     `175` 'FishRecognition.recognize_fish'
  => `176` 'FishRecognition.recognize_once'
     `177` 'FishRecognition.run'
     `178` 'main'
     `179` 'workers\\fishing\\fish_recognition.py'
     `180` '<module workers.fishing.fish_recognition>'
     `181` ['__class__']
     `182` ['self']
     `183` ['self', 'process_name']
     `184` ['hwnd', 'hwnds', '_', 'pid', 'process', 'self']
     `185` ['self', 'left', 'top', 'right', 'bottom', 'width', 'height', 'hwndDC', 'mfcDC', 'saveDC', 'saveBitMap', 'bmpinfo', 'bmpstr', 'img', 'e']
     `186` ['self', 'screenshot', 'template', 'roi', 'search_area', 'result', 'min_val', 'max_val', 'min_loc', 'max_loc', 'h', 'w', 'center_x', 'center_y']
     `187` ['self', 'callback', 'hwnds', 'hwnd', 'title']
     `188` ['self', 'left', 'top', 'right', 'bottom']
     `189` ['self', 'width', 'height']
     `190` ['self', 'template_path', 'fish_count', 'file_path', 'template']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fish_recognition\23e718390_FishRecognition.recognize_once.c`

### `FishRecognition.run`

- implementation: `FUN_23e719590`
- source line hint: `262`
- Nuitka codevar: `DAT_23eedb050`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `169` 'FishRecognition.__init__'
     `170` 'FishRecognition.initialize'
     `171` 'FishRecognition.load_templates'
     `172` [None]
     `173` 'template'
     `174` 'FishRecognition.find_template'
     `175` 'FishRecognition.recognize_fish'
     `176` 'FishRecognition.recognize_once'
  => `177` 'FishRecognition.run'
     `178` 'main'
     `179` 'workers\\fishing\\fish_recognition.py'
     `180` '<module workers.fishing.fish_recognition>'
     `181` ['__class__']
     `182` ['self']
     `183` ['self', 'process_name']
     `184` ['hwnd', 'hwnds', '_', 'pid', 'process', 'self']
     `185` ['self', 'left', 'top', 'right', 'bottom', 'width', 'height', 'hwndDC', 'mfcDC', 'saveDC', 'saveBitMap', 'bmpinfo', 'bmpstr', 'img', 'e']
     `186` ['self', 'screenshot', 'template', 'roi', 'search_area', 'result', 'min_val', 'max_val', 'min_loc', 'max_loc', 'h', 'w', 'center_x', 'center_y']
     `187` ['self', 'callback', 'hwnds', 'hwnd', 'title']
     `188` ['self', 'left', 'top', 'right', 'bottom']
     `189` ['self', 'width', 'height']
     `190` ['self', 'template_path', 'fish_count', 'file_path', 'template']
     `191` ['recognizer']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fish_recognition\23e719590_FishRecognition.run.c`

### `?`

- implementation: `FUN_23e71acf0`
- source line hint: `286`
- Nuitka codevar: `DAT_23eedb040`
- factory: `FUN_23e93df40`
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fish_recognition\23e71acf0_unknown.c`
