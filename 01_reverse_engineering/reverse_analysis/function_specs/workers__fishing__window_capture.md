# Function Specification: `workers.fishing.window_capture`

This is a reconstruction dossier from static Nuitka constants and Ghidra decompilation. It is not original Python source text.

## Source Path Hints
- `workers\fishing\window_capture.py`

## Docstrings / Long Text
- `75` '\nОбщий модуль захвата окна GTA5\nИспользуется всеми модулями бота рыбалки\n'

## Function Inventory
| Inferred qualname | Impl | Source line | Arg count | Decompiled C |
|---|---:|---:|---:|---|
| `WindowCapture.__init__` | `LAB_23e8566e0` | 20 | 2 | yes |
| `WindowCapture.find_window_by_process` | `FUN_23e856d00` | 26 | 1 | yes |
| `WindowCapture.get_window_size` | `FUN_23e858b40` | 52 | 1 | yes |
| `WindowCapture.capture` | `FUN_23e8a9110` | 59 | 1 | yes |
| `WindowCapture._to_screen_coords` | `FUN_23e859850` | 96 | 3 | yes |
| `WindowCapture.click_at` | `FUN_23e85a8f0` | 104 | 4 | yes |
| `WindowCapture.double_click_at` | `FUN_23e85bc50` | 121 | 3 | yes |
| `WindowCapture.press_key` | `FUN_23e85cf40` | 137 | 2 | yes |
| `WindowCapture.key_down` | `FUN_23e85d480` | 142 | 2 | yes |
| `WindowCapture.key_up` | `FUN_23e85d9c0` | 147 | 2 | yes |
| `WindowCapture.release_all_keys` | `FUN_23e86bd20` | 152 | 1 | yes |

## Local Variable Lists
- `116` `__class__`
- `117` `self, process_name`
- `118` `self, x, y, rect, client_rect, border_x, border_y`
- `119` `hwnd, hwnds, _, pid, process, self`
- `120` `self`
- `121` `self, left, top, right, bottom, width, height, hwndDC, mfcDC, saveDC, saveBitMap, bmpinfo, bmpstr, img`
- `122` `self, x, y, button, screen_x, screen_y`
- `123` `self, x, y, screen_x, screen_y`
- `124` `self, callback, hwnds, hwnd, title`
- `125` `self, left, top, right, bottom`
- `126` `self, key`

## Structured Constants
- `19` [0, 0]
- `34` [True]
- `59` [0.05]
- `65` [0.1]
- `84` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
- `86` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
- `89` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
- `96` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['return', {'__builtin__': 'tuple'}]]}
- `99` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['button', {'__builtin__': 'str'}]]}
- `102` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}]]}
- `105` {'__dict_items__': [['key', {'__builtin__': 'str'}]]}

## Per-Function Context
### `WindowCapture.__init__`

- implementation: `LAB_23e8566e0`
- source line hint: `20`
- Nuitka codevar: `DAT_23eede300`
- factory: `FUN_23e93e480`
- nearby constants:
     `77` 'has_location'
     `78` 'numpy'
     `79` 'workers.fishing.window_capture'
     `80` 'Захват скриншотов окна по имени процесса + клики/ввод'
     `81` 'WindowCapture'
     `82` '__qualname__'
     `83` ['gta5.exe']
     `84` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
  => `85` 'WindowCapture.__init__'
     `86` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `87` 'find_window_by_process'
     `88` 'WindowCapture.find_window_by_process'
     `89` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `90` 'get_window_size'
     `91` 'WindowCapture.get_window_size'
     `92` 'return'
     `93` 'ndarray'
     `94` 'capture'
     `95` 'WindowCapture.capture'
     `96` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['return', {'__builtin__': 'tuple'}]]}
     `97` 'WindowCapture._to_screen_coords'
     `98` ['left']
     `99` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['button', {'__builtin__': 'str'}]]}
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__window_capture\23e8566e0_WindowCapture.__init.c`

### `WindowCapture.find_window_by_process`

- implementation: `FUN_23e856d00`
- source line hint: `26`
- Nuitka codevar: `_DAT_23eede2f0`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `80` 'Захват скриншотов окна по имени процесса + клики/ввод'
     `81` 'WindowCapture'
     `82` '__qualname__'
     `83` ['gta5.exe']
     `84` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
     `85` 'WindowCapture.__init__'
     `86` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `87` 'find_window_by_process'
  => `88` 'WindowCapture.find_window_by_process'
     `89` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `90` 'get_window_size'
     `91` 'WindowCapture.get_window_size'
     `92` 'return'
     `93` 'ndarray'
     `94` 'capture'
     `95` 'WindowCapture.capture'
     `96` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['return', {'__builtin__': 'tuple'}]]}
     `97` 'WindowCapture._to_screen_coords'
     `98` ['left']
     `99` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['button', {'__builtin__': 'str'}]]}
     `100` 'click_at'
     `101` 'WindowCapture.click_at'
     `102` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}]]}
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__window_capture\23e856d00_WindowCapture.find_window_by_process.c`

### `WindowCapture.get_window_size`

- implementation: `FUN_23e858b40`
- source line hint: `52`
- Nuitka codevar: `DAT_23eede2c0`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `83` ['gta5.exe']
     `84` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
     `85` 'WindowCapture.__init__'
     `86` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `87` 'find_window_by_process'
     `88` 'WindowCapture.find_window_by_process'
     `89` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `90` 'get_window_size'
  => `91` 'WindowCapture.get_window_size'
     `92` 'return'
     `93` 'ndarray'
     `94` 'capture'
     `95` 'WindowCapture.capture'
     `96` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['return', {'__builtin__': 'tuple'}]]}
     `97` 'WindowCapture._to_screen_coords'
     `98` ['left']
     `99` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['button', {'__builtin__': 'str'}]]}
     `100` 'click_at'
     `101` 'WindowCapture.click_at'
     `102` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}]]}
     `103` 'double_click_at'
     `104` 'WindowCapture.double_click_at'
     `105` {'__dict_items__': [['key', {'__builtin__': 'str'}]]}
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__window_capture\23e858b40_WindowCapture.get_window_size.c`

### `WindowCapture.capture`

- implementation: `FUN_23e8a9110`
- source line hint: `59`
- Nuitka codevar: `DAT_23eede2b0`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `87` 'find_window_by_process'
     `88` 'WindowCapture.find_window_by_process'
     `89` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `90` 'get_window_size'
     `91` 'WindowCapture.get_window_size'
     `92` 'return'
     `93` 'ndarray'
     `94` 'capture'
  => `95` 'WindowCapture.capture'
     `96` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['return', {'__builtin__': 'tuple'}]]}
     `97` 'WindowCapture._to_screen_coords'
     `98` ['left']
     `99` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['button', {'__builtin__': 'str'}]]}
     `100` 'click_at'
     `101` 'WindowCapture.click_at'
     `102` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}]]}
     `103` 'double_click_at'
     `104` 'WindowCapture.double_click_at'
     `105` {'__dict_items__': [['key', {'__builtin__': 'str'}]]}
     `106` 'press_key'
     `107` 'WindowCapture.press_key'
     `108` 'key_down'
     `109` 'WindowCapture.key_down'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__window_capture\23e8a9110_WindowCapture.capture.c`

### `WindowCapture._to_screen_coords`

- implementation: `FUN_23e859850`
- source line hint: `96`
- Nuitka codevar: `DAT_23eede298`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `89` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `90` 'get_window_size'
     `91` 'WindowCapture.get_window_size'
     `92` 'return'
     `93` 'ndarray'
     `94` 'capture'
     `95` 'WindowCapture.capture'
     `96` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['return', {'__builtin__': 'tuple'}]]}
  => `97` 'WindowCapture._to_screen_coords'
     `98` ['left']
     `99` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['button', {'__builtin__': 'str'}]]}
     `100` 'click_at'
     `101` 'WindowCapture.click_at'
     `102` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}]]}
     `103` 'double_click_at'
     `104` 'WindowCapture.double_click_at'
     `105` {'__dict_items__': [['key', {'__builtin__': 'str'}]]}
     `106` 'press_key'
     `107` 'WindowCapture.press_key'
     `108` 'key_down'
     `109` 'WindowCapture.key_down'
     `110` 'key_up'
     `111` 'WindowCapture.key_up'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__window_capture\23e859850_WindowCapture._to_screen_coords.c`

### `WindowCapture.click_at`

- implementation: `FUN_23e85a8f0`
- source line hint: `104`
- Nuitka codevar: `DAT_23eede288`
- factory: `FUN_23e93e480`
- nearby constants:
     `93` 'ndarray'
     `94` 'capture'
     `95` 'WindowCapture.capture'
     `96` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['return', {'__builtin__': 'tuple'}]]}
     `97` 'WindowCapture._to_screen_coords'
     `98` ['left']
     `99` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['button', {'__builtin__': 'str'}]]}
     `100` 'click_at'
  => `101` 'WindowCapture.click_at'
     `102` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}]]}
     `103` 'double_click_at'
     `104` 'WindowCapture.double_click_at'
     `105` {'__dict_items__': [['key', {'__builtin__': 'str'}]]}
     `106` 'press_key'
     `107` 'WindowCapture.press_key'
     `108` 'key_down'
     `109` 'WindowCapture.key_down'
     `110` 'key_up'
     `111` 'WindowCapture.key_up'
     `112` 'release_all_keys'
     `113` 'WindowCapture.release_all_keys'
     `114` 'workers\\fishing\\window_capture.py'
     `115` '<module workers.fishing.window_capture>'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__window_capture\23e85a8f0_WindowCapture.click_at.c`

### `WindowCapture.double_click_at`

- implementation: `FUN_23e85bc50`
- source line hint: `121`
- Nuitka codevar: `_DAT_23eede278`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `96` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['return', {'__builtin__': 'tuple'}]]}
     `97` 'WindowCapture._to_screen_coords'
     `98` ['left']
     `99` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['button', {'__builtin__': 'str'}]]}
     `100` 'click_at'
     `101` 'WindowCapture.click_at'
     `102` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}]]}
     `103` 'double_click_at'
  => `104` 'WindowCapture.double_click_at'
     `105` {'__dict_items__': [['key', {'__builtin__': 'str'}]]}
     `106` 'press_key'
     `107` 'WindowCapture.press_key'
     `108` 'key_down'
     `109` 'WindowCapture.key_down'
     `110` 'key_up'
     `111` 'WindowCapture.key_up'
     `112` 'release_all_keys'
     `113` 'WindowCapture.release_all_keys'
     `114` 'workers\\fishing\\window_capture.py'
     `115` '<module workers.fishing.window_capture>'
     `116` ['__class__']
     `117` ['self', 'process_name']
     `118` ['self', 'x', 'y', 'rect', 'client_rect', 'border_x', 'border_y']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__window_capture\23e85bc50_WindowCapture.double_click_at.c`

### `WindowCapture.press_key`

- implementation: `FUN_23e85cf40`
- source line hint: `137`
- Nuitka codevar: `_DAT_23eede268`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `99` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['button', {'__builtin__': 'str'}]]}
     `100` 'click_at'
     `101` 'WindowCapture.click_at'
     `102` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}]]}
     `103` 'double_click_at'
     `104` 'WindowCapture.double_click_at'
     `105` {'__dict_items__': [['key', {'__builtin__': 'str'}]]}
     `106` 'press_key'
  => `107` 'WindowCapture.press_key'
     `108` 'key_down'
     `109` 'WindowCapture.key_down'
     `110` 'key_up'
     `111` 'WindowCapture.key_up'
     `112` 'release_all_keys'
     `113` 'WindowCapture.release_all_keys'
     `114` 'workers\\fishing\\window_capture.py'
     `115` '<module workers.fishing.window_capture>'
     `116` ['__class__']
     `117` ['self', 'process_name']
     `118` ['self', 'x', 'y', 'rect', 'client_rect', 'border_x', 'border_y']
     `119` ['hwnd', 'hwnds', '_', 'pid', 'process', 'self']
     `120` ['self']
     `121` ['self', 'left', 'top', 'right', 'bottom', 'width', 'height', 'hwndDC', 'mfcDC', 'saveDC', 'saveBitMap', 'bmpinfo', 'bmpstr', 'img']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__window_capture\23e85cf40_WindowCapture.press_key.c`

### `WindowCapture.key_down`

- implementation: `FUN_23e85d480`
- source line hint: `142`
- Nuitka codevar: `_DAT_23eede258`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `101` 'WindowCapture.click_at'
     `102` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}]]}
     `103` 'double_click_at'
     `104` 'WindowCapture.double_click_at'
     `105` {'__dict_items__': [['key', {'__builtin__': 'str'}]]}
     `106` 'press_key'
     `107` 'WindowCapture.press_key'
     `108` 'key_down'
  => `109` 'WindowCapture.key_down'
     `110` 'key_up'
     `111` 'WindowCapture.key_up'
     `112` 'release_all_keys'
     `113` 'WindowCapture.release_all_keys'
     `114` 'workers\\fishing\\window_capture.py'
     `115` '<module workers.fishing.window_capture>'
     `116` ['__class__']
     `117` ['self', 'process_name']
     `118` ['self', 'x', 'y', 'rect', 'client_rect', 'border_x', 'border_y']
     `119` ['hwnd', 'hwnds', '_', 'pid', 'process', 'self']
     `120` ['self']
     `121` ['self', 'left', 'top', 'right', 'bottom', 'width', 'height', 'hwndDC', 'mfcDC', 'saveDC', 'saveBitMap', 'bmpinfo', 'bmpstr', 'img']
     `122` ['self', 'x', 'y', 'button', 'screen_x', 'screen_y']
     `123` ['self', 'x', 'y', 'screen_x', 'screen_y']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__window_capture\23e85d480_WindowCapture.key_down.c`

### `WindowCapture.key_up`

- implementation: `FUN_23e85d9c0`
- source line hint: `147`
- Nuitka codevar: `_DAT_23eede248`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `103` 'double_click_at'
     `104` 'WindowCapture.double_click_at'
     `105` {'__dict_items__': [['key', {'__builtin__': 'str'}]]}
     `106` 'press_key'
     `107` 'WindowCapture.press_key'
     `108` 'key_down'
     `109` 'WindowCapture.key_down'
     `110` 'key_up'
  => `111` 'WindowCapture.key_up'
     `112` 'release_all_keys'
     `113` 'WindowCapture.release_all_keys'
     `114` 'workers\\fishing\\window_capture.py'
     `115` '<module workers.fishing.window_capture>'
     `116` ['__class__']
     `117` ['self', 'process_name']
     `118` ['self', 'x', 'y', 'rect', 'client_rect', 'border_x', 'border_y']
     `119` ['hwnd', 'hwnds', '_', 'pid', 'process', 'self']
     `120` ['self']
     `121` ['self', 'left', 'top', 'right', 'bottom', 'width', 'height', 'hwndDC', 'mfcDC', 'saveDC', 'saveBitMap', 'bmpinfo', 'bmpstr', 'img']
     `122` ['self', 'x', 'y', 'button', 'screen_x', 'screen_y']
     `123` ['self', 'x', 'y', 'screen_x', 'screen_y']
     `124` ['self', 'callback', 'hwnds', 'hwnd', 'title']
     `125` ['self', 'left', 'top', 'right', 'bottom']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__window_capture\23e85d9c0_WindowCapture.key_up.c`

### `WindowCapture.release_all_keys`

- implementation: `FUN_23e86bd20`
- source line hint: `152`
- Nuitka codevar: `_DAT_23eede238`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `105` {'__dict_items__': [['key', {'__builtin__': 'str'}]]}
     `106` 'press_key'
     `107` 'WindowCapture.press_key'
     `108` 'key_down'
     `109` 'WindowCapture.key_down'
     `110` 'key_up'
     `111` 'WindowCapture.key_up'
     `112` 'release_all_keys'
  => `113` 'WindowCapture.release_all_keys'
     `114` 'workers\\fishing\\window_capture.py'
     `115` '<module workers.fishing.window_capture>'
     `116` ['__class__']
     `117` ['self', 'process_name']
     `118` ['self', 'x', 'y', 'rect', 'client_rect', 'border_x', 'border_y']
     `119` ['hwnd', 'hwnds', '_', 'pid', 'process', 'self']
     `120` ['self']
     `121` ['self', 'left', 'top', 'right', 'bottom', 'width', 'height', 'hwndDC', 'mfcDC', 'saveDC', 'saveBitMap', 'bmpinfo', 'bmpstr', 'img']
     `122` ['self', 'x', 'y', 'button', 'screen_x', 'screen_y']
     `123` ['self', 'x', 'y', 'screen_x', 'screen_y']
     `124` ['self', 'callback', 'hwnds', 'hwnd', 'title']
     `125` ['self', 'left', 'top', 'right', 'bottom']
     `126` ['self', 'key']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__window_capture\23e86bd20_WindowCapture.release_all_keys.c`
