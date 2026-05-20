# Function Specification: `ui.hotkey_listener`

This is a reconstruction dossier from static Nuitka constants and Ghidra decompilation. It is not original Python source text.

## Source Path Hints
- `ui\hotkey_listener.py`

## Docstrings / Long Text
- `64` '\nГлобальный слушатель горячих клавиш для управления ботом\nРаботает через опрос GetAsyncKeyState — надёжно, без Windows hook.\npynput/WH_KEYBOARD_LL снимается Windows при интенсивной синтетической клавиатуре\n(pydirectinput), GetAsyncKeyState лишён этой проблемы.\n'
- `72` '\n    Глобальный слушатель горячих клавиш на основе опроса GetAsyncKeyState.\n    Не использует Windows hook — надёжно работает даже при интенсивной\n    синтетической клавиатуре (pydirectinput).\n    '

## Function Inventory
| Inferred qualname | Impl | Source line | Arg count | Decompiled C |
|---|---:|---:|---:|---|
| `HotkeyListener.__init__` | `FUN_23e2e6460` | 43 | uVar11 | yes |
| `HotkeyListener.set_hotkey` | `FUN_23e2e6bf0` | 54 | 3 | yes |
| `HotkeyListener.clear_hotkey` | `FUN_23e2e7d90` | 62 | uVar20 | yes |
| `HotkeyListener._parse_hotkey` | `FUN_23e2e8e20` | 69 | uVar11 | yes |
| `HotkeyListener.start` | `FUN_23e2e9ec0` | 83 | 1 | yes |
| `HotkeyListener.stop` | `FUN_23e2eab40` | 103 | 1 | yes |
| `HotkeyListener._is_key_down` | `FUN_23e2eb260` | 111 | uVar11 | yes |
| `HotkeyListener._poll_loop` | `FUN_23e2eb880` | 115 | uVar11 | yes |
| `HotkeyListener._format_current_combo` | `FUN_23e2f0660` | 157 | uVar11 | yes |
| `HotkeyListener._get_key_name` | `FUN_23e2f0aa0` | ? | ? | yes |

## Local Variable Lists
- `94` `.0, vk, self`
- `96` `self`
- `97` `self, key`
- `98` `self, vk`
- `99` `self, hotkey_string, vks, part, key, vk`
- `100` `self, vk_codes, callback, hotkey_name, triggered, all_down, e, traceback`
- `101` `self, hotkey_string, callback`

## Structured Constants
- `12` [None, None, None]
- `23` [0.5]
- `56` [0.05]
- `70` {'__dict_items__': [['F1', 112], ['F2', 113], ['F3', 114], ['F4', 115], ['F5', 116], ['F6', 117], ['F7', 118], ['F8', 119], ['F9', 120], ['F10', 121], ['F11', 122], ['F12', 123], ['CTRL', 17], ['ALT', 18], ['SHIFT', 16], ['WIN', 91], ['SPACE', 32], ['ENTER', 13], ['ESC', 27], ['DELETE', 46], ['HOME', 36], ['END', 35], ['PAGEUP', 33], ['PAGEDOWN', 34], ['INSERT', 45], ['UP', 38], ['DOWN', 40], ['LEFT', 37], ['RIGHT', 39], ['TAB', 9], ['CAPSLOCK', 20], ['A', 65], ['B', 66], ['C', 67], ['D', 68], ['E', 69], ['F', 7...
- `75` {'__dict_items__': [['hotkey_string', {'__builtin__': 'str'}]]}
- `80` {'__dict_items__': [['hotkey_string', {'__builtin__': 'str'}], ['return', {'__builtin__': 'list'}]]}
- `85` {'__dict_items__': [['vk', {'__builtin__': 'int'}], ['return', {'__builtin__': 'bool'}]]}

## Per-Function Context
### `HotkeyListener.__init__`

- implementation: `FUN_23e2e6460`
- source line hint: `43`
- Nuitka codevar: `_DAT_23eeb0168`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `66` 'has_location'
     `67` 'ctypes'
     `68` 'windll'
     `69` 'user32'
     `70` {'__dict_items__': [['F1', 112], ['F2', 113], ['F3', 114], ['F4', 115], ['F5', 116], ['F6', 117], ['F7', 118], ['F8', 119], ['F9', 120], ['F10', 121], ['F11', 122], ['F12', 123], ['CTRL', 17], ['ALT', 18], ['SHIFT', 16], ['WIN', 91], ['SPACE', 32], ['ENTER', 13], ['ESC', 27], ...
     `71` 'ui.hotkey_listener'
     `72` '\n    Глобальный слушатель горячих клавиш на основе опроса GetAsyncKeyState.\n    Не использует Windows hook — надёжно работает даже при интенсивной\n    синтетической клавиатуре (pydirectinput).\n    '
     `73` '__qualname__'
  => `74` 'HotkeyListener.__init__'
     `75` {'__dict_items__': [['hotkey_string', {'__builtin__': 'str'}]]}
     `76` 'set_hotkey'
     `77` 'HotkeyListener.set_hotkey'
     `78` 'clear_hotkey'
     `79` 'HotkeyListener.clear_hotkey'
     `80` {'__dict_items__': [['hotkey_string', {'__builtin__': 'str'}], ['return', {'__builtin__': 'list'}]]}
     `81` 'HotkeyListener._parse_hotkey'
     `82` 'HotkeyListener.start'
     `83` 'stop'
     `84` 'HotkeyListener.stop'
     `85` {'__dict_items__': [['vk', {'__builtin__': 'int'}], ['return', {'__builtin__': 'bool'}]]}
     `86` 'HotkeyListener._is_key_down'
     `87` 'HotkeyListener._poll_loop'
     `88` '_format_current_combo'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__hotkey_listener\23e2e6460_HotkeyListener.__init.c`

### `HotkeyListener.set_hotkey`

- implementation: `FUN_23e2e6bf0`
- source line hint: `54`
- Nuitka codevar: `_DAT_23eeb0158`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `69` 'user32'
     `70` {'__dict_items__': [['F1', 112], ['F2', 113], ['F3', 114], ['F4', 115], ['F5', 116], ['F6', 117], ['F7', 118], ['F8', 119], ['F9', 120], ['F10', 121], ['F11', 122], ['F12', 123], ['CTRL', 17], ['ALT', 18], ['SHIFT', 16], ['WIN', 91], ['SPACE', 32], ['ENTER', 13], ['ESC', 27], ...
     `71` 'ui.hotkey_listener'
     `72` '\n    Глобальный слушатель горячих клавиш на основе опроса GetAsyncKeyState.\n    Не использует Windows hook — надёжно работает даже при интенсивной\n    синтетической клавиатуре (pydirectinput).\n    '
     `73` '__qualname__'
     `74` 'HotkeyListener.__init__'
     `75` {'__dict_items__': [['hotkey_string', {'__builtin__': 'str'}]]}
     `76` 'set_hotkey'
  => `77` 'HotkeyListener.set_hotkey'
     `78` 'clear_hotkey'
     `79` 'HotkeyListener.clear_hotkey'
     `80` {'__dict_items__': [['hotkey_string', {'__builtin__': 'str'}], ['return', {'__builtin__': 'list'}]]}
     `81` 'HotkeyListener._parse_hotkey'
     `82` 'HotkeyListener.start'
     `83` 'stop'
     `84` 'HotkeyListener.stop'
     `85` {'__dict_items__': [['vk', {'__builtin__': 'int'}], ['return', {'__builtin__': 'bool'}]]}
     `86` 'HotkeyListener._is_key_down'
     `87` 'HotkeyListener._poll_loop'
     `88` '_format_current_combo'
     `89` 'HotkeyListener._format_current_combo'
     `90` '_get_key_name'
     `91` 'HotkeyListener._get_key_name'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__hotkey_listener\23e2e6bf0_HotkeyListener.set_hotkey.c`

### `HotkeyListener.clear_hotkey`

- implementation: `FUN_23e2e7d90`
- source line hint: `62`
- Nuitka codevar: `_DAT_23eeb0148`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `71` 'ui.hotkey_listener'
     `72` '\n    Глобальный слушатель горячих клавиш на основе опроса GetAsyncKeyState.\n    Не использует Windows hook — надёжно работает даже при интенсивной\n    синтетической клавиатуре (pydirectinput).\n    '
     `73` '__qualname__'
     `74` 'HotkeyListener.__init__'
     `75` {'__dict_items__': [['hotkey_string', {'__builtin__': 'str'}]]}
     `76` 'set_hotkey'
     `77` 'HotkeyListener.set_hotkey'
     `78` 'clear_hotkey'
  => `79` 'HotkeyListener.clear_hotkey'
     `80` {'__dict_items__': [['hotkey_string', {'__builtin__': 'str'}], ['return', {'__builtin__': 'list'}]]}
     `81` 'HotkeyListener._parse_hotkey'
     `82` 'HotkeyListener.start'
     `83` 'stop'
     `84` 'HotkeyListener.stop'
     `85` {'__dict_items__': [['vk', {'__builtin__': 'int'}], ['return', {'__builtin__': 'bool'}]]}
     `86` 'HotkeyListener._is_key_down'
     `87` 'HotkeyListener._poll_loop'
     `88` '_format_current_combo'
     `89` 'HotkeyListener._format_current_combo'
     `90` '_get_key_name'
     `91` 'HotkeyListener._get_key_name'
     `92` 'get_global_listener'
     `93` 'ui\\hotkey_listener.py'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__hotkey_listener\23e2e7d90_HotkeyListener.clear_hotkey.c`

### `HotkeyListener._parse_hotkey`

- implementation: `FUN_23e2e8e20`
- source line hint: `69`
- Nuitka codevar: `DAT_23eeb0138`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `73` '__qualname__'
     `74` 'HotkeyListener.__init__'
     `75` {'__dict_items__': [['hotkey_string', {'__builtin__': 'str'}]]}
     `76` 'set_hotkey'
     `77` 'HotkeyListener.set_hotkey'
     `78` 'clear_hotkey'
     `79` 'HotkeyListener.clear_hotkey'
     `80` {'__dict_items__': [['hotkey_string', {'__builtin__': 'str'}], ['return', {'__builtin__': 'list'}]]}
  => `81` 'HotkeyListener._parse_hotkey'
     `82` 'HotkeyListener.start'
     `83` 'stop'
     `84` 'HotkeyListener.stop'
     `85` {'__dict_items__': [['vk', {'__builtin__': 'int'}], ['return', {'__builtin__': 'bool'}]]}
     `86` 'HotkeyListener._is_key_down'
     `87` 'HotkeyListener._poll_loop'
     `88` '_format_current_combo'
     `89` 'HotkeyListener._format_current_combo'
     `90` '_get_key_name'
     `91` 'HotkeyListener._get_key_name'
     `92` 'get_global_listener'
     `93` 'ui\\hotkey_listener.py'
     `94` ['.0', 'vk', 'self']
     `95` '<module ui.hotkey_listener>'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__hotkey_listener\23e2e8e20_HotkeyListener._parse_hotkey.c`

### `HotkeyListener.start`

- implementation: `FUN_23e2e9ec0`
- source line hint: `83`
- Nuitka codevar: `DAT_23eeb0120`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `74` 'HotkeyListener.__init__'
     `75` {'__dict_items__': [['hotkey_string', {'__builtin__': 'str'}]]}
     `76` 'set_hotkey'
     `77` 'HotkeyListener.set_hotkey'
     `78` 'clear_hotkey'
     `79` 'HotkeyListener.clear_hotkey'
     `80` {'__dict_items__': [['hotkey_string', {'__builtin__': 'str'}], ['return', {'__builtin__': 'list'}]]}
     `81` 'HotkeyListener._parse_hotkey'
  => `82` 'HotkeyListener.start'
     `83` 'stop'
     `84` 'HotkeyListener.stop'
     `85` {'__dict_items__': [['vk', {'__builtin__': 'int'}], ['return', {'__builtin__': 'bool'}]]}
     `86` 'HotkeyListener._is_key_down'
     `87` 'HotkeyListener._poll_loop'
     `88` '_format_current_combo'
     `89` 'HotkeyListener._format_current_combo'
     `90` '_get_key_name'
     `91` 'HotkeyListener._get_key_name'
     `92` 'get_global_listener'
     `93` 'ui\\hotkey_listener.py'
     `94` ['.0', 'vk', 'self']
     `95` '<module ui.hotkey_listener>'
     `96` ['self']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__hotkey_listener\23e2e9ec0_HotkeyListener.start.c`

### `HotkeyListener.stop`

- implementation: `FUN_23e2eab40`
- source line hint: `103`
- Nuitka codevar: `DAT_23eeb0110`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `76` 'set_hotkey'
     `77` 'HotkeyListener.set_hotkey'
     `78` 'clear_hotkey'
     `79` 'HotkeyListener.clear_hotkey'
     `80` {'__dict_items__': [['hotkey_string', {'__builtin__': 'str'}], ['return', {'__builtin__': 'list'}]]}
     `81` 'HotkeyListener._parse_hotkey'
     `82` 'HotkeyListener.start'
     `83` 'stop'
  => `84` 'HotkeyListener.stop'
     `85` {'__dict_items__': [['vk', {'__builtin__': 'int'}], ['return', {'__builtin__': 'bool'}]]}
     `86` 'HotkeyListener._is_key_down'
     `87` 'HotkeyListener._poll_loop'
     `88` '_format_current_combo'
     `89` 'HotkeyListener._format_current_combo'
     `90` '_get_key_name'
     `91` 'HotkeyListener._get_key_name'
     `92` 'get_global_listener'
     `93` 'ui\\hotkey_listener.py'
     `94` ['.0', 'vk', 'self']
     `95` '<module ui.hotkey_listener>'
     `96` ['self']
     `97` ['self', 'key']
     `98` ['self', 'vk']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__hotkey_listener\23e2eab40_HotkeyListener.stop.c`

### `HotkeyListener._is_key_down`

- implementation: `FUN_23e2eb260`
- source line hint: `111`
- Nuitka codevar: `_DAT_23eeb0100`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `78` 'clear_hotkey'
     `79` 'HotkeyListener.clear_hotkey'
     `80` {'__dict_items__': [['hotkey_string', {'__builtin__': 'str'}], ['return', {'__builtin__': 'list'}]]}
     `81` 'HotkeyListener._parse_hotkey'
     `82` 'HotkeyListener.start'
     `83` 'stop'
     `84` 'HotkeyListener.stop'
     `85` {'__dict_items__': [['vk', {'__builtin__': 'int'}], ['return', {'__builtin__': 'bool'}]]}
  => `86` 'HotkeyListener._is_key_down'
     `87` 'HotkeyListener._poll_loop'
     `88` '_format_current_combo'
     `89` 'HotkeyListener._format_current_combo'
     `90` '_get_key_name'
     `91` 'HotkeyListener._get_key_name'
     `92` 'get_global_listener'
     `93` 'ui\\hotkey_listener.py'
     `94` ['.0', 'vk', 'self']
     `95` '<module ui.hotkey_listener>'
     `96` ['self']
     `97` ['self', 'key']
     `98` ['self', 'vk']
     `99` ['self', 'hotkey_string', 'vks', 'part', 'key', 'vk']
     `100` ['self', 'vk_codes', 'callback', 'hotkey_name', 'triggered', 'all_down', 'e', 'traceback']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__hotkey_listener\23e2eb260_HotkeyListener._is_key_down.c`

### `HotkeyListener._poll_loop`

- implementation: `FUN_23e2eb880`
- source line hint: `115`
- Nuitka codevar: `_DAT_23eeb00e8`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `79` 'HotkeyListener.clear_hotkey'
     `80` {'__dict_items__': [['hotkey_string', {'__builtin__': 'str'}], ['return', {'__builtin__': 'list'}]]}
     `81` 'HotkeyListener._parse_hotkey'
     `82` 'HotkeyListener.start'
     `83` 'stop'
     `84` 'HotkeyListener.stop'
     `85` {'__dict_items__': [['vk', {'__builtin__': 'int'}], ['return', {'__builtin__': 'bool'}]]}
     `86` 'HotkeyListener._is_key_down'
  => `87` 'HotkeyListener._poll_loop'
     `88` '_format_current_combo'
     `89` 'HotkeyListener._format_current_combo'
     `90` '_get_key_name'
     `91` 'HotkeyListener._get_key_name'
     `92` 'get_global_listener'
     `93` 'ui\\hotkey_listener.py'
     `94` ['.0', 'vk', 'self']
     `95` '<module ui.hotkey_listener>'
     `96` ['self']
     `97` ['self', 'key']
     `98` ['self', 'vk']
     `99` ['self', 'hotkey_string', 'vks', 'part', 'key', 'vk']
     `100` ['self', 'vk_codes', 'callback', 'hotkey_name', 'triggered', 'all_down', 'e', 'traceback']
     `101` ['self', 'hotkey_string', 'callback']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__hotkey_listener\23e2eb880_HotkeyListener._poll_loop.c`

### `HotkeyListener._format_current_combo`

- implementation: `FUN_23e2f0660`
- source line hint: `157`
- Nuitka codevar: `_DAT_23eeb00c0`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `81` 'HotkeyListener._parse_hotkey'
     `82` 'HotkeyListener.start'
     `83` 'stop'
     `84` 'HotkeyListener.stop'
     `85` {'__dict_items__': [['vk', {'__builtin__': 'int'}], ['return', {'__builtin__': 'bool'}]]}
     `86` 'HotkeyListener._is_key_down'
     `87` 'HotkeyListener._poll_loop'
     `88` '_format_current_combo'
  => `89` 'HotkeyListener._format_current_combo'
     `90` '_get_key_name'
     `91` 'HotkeyListener._get_key_name'
     `92` 'get_global_listener'
     `93` 'ui\\hotkey_listener.py'
     `94` ['.0', 'vk', 'self']
     `95` '<module ui.hotkey_listener>'
     `96` ['self']
     `97` ['self', 'key']
     `98` ['self', 'vk']
     `99` ['self', 'hotkey_string', 'vks', 'part', 'key', 'vk']
     `100` ['self', 'vk_codes', 'callback', 'hotkey_name', 'triggered', 'all_down', 'e', 'traceback']
     `101` ['self', 'hotkey_string', 'callback']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__hotkey_listener\23e2f0660_HotkeyListener._format_current_combo.c`

### `HotkeyListener._get_key_name`

- implementation: `FUN_23e2f0aa0`
- source line hint: `?`
- Nuitka codevar: `_DAT_23eeb00b0`
- factory: `FUN_23e93df40`
- nearby constants:
     `83` 'stop'
     `84` 'HotkeyListener.stop'
     `85` {'__dict_items__': [['vk', {'__builtin__': 'int'}], ['return', {'__builtin__': 'bool'}]]}
     `86` 'HotkeyListener._is_key_down'
     `87` 'HotkeyListener._poll_loop'
     `88` '_format_current_combo'
     `89` 'HotkeyListener._format_current_combo'
     `90` '_get_key_name'
  => `91` 'HotkeyListener._get_key_name'
     `92` 'get_global_listener'
     `93` 'ui\\hotkey_listener.py'
     `94` ['.0', 'vk', 'self']
     `95` '<module ui.hotkey_listener>'
     `96` ['self']
     `97` ['self', 'key']
     `98` ['self', 'vk']
     `99` ['self', 'hotkey_string', 'vks', 'part', 'key', 'vk']
     `100` ['self', 'vk_codes', 'callback', 'hotkey_name', 'triggered', 'all_down', 'e', 'traceback']
     `101` ['self', 'hotkey_string', 'callback']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__hotkey_listener\23e2f0aa0_HotkeyListener._get_key_name.c`
