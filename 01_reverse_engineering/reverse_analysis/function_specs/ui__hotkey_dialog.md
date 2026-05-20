# Function Specification: `ui.hotkey_dialog`

This is a reconstruction dossier from static Nuitka constants and Ghidra decompilation. It is not original Python source text.

## Source Path Hints
- `ui\hotkey_dialog.py`

## Docstrings / Long Text
- `116` '\nДиалог назначения горячей клавиши для запуска/остановки бота\n'

## Function Inventory
| Inferred qualname | Impl | Source line | Arg count | Decompiled C |
|---|---:|---:|---:|---|
| `pynput.keyboard` | `FUN_23e2da250` | 27 | 1 | yes |
| `HotkeyDialog.__init__` | `FUN_23e2dcfa0` | 103 | 1 | yes |
| `HotkeyDialog.init_ui` | `FUN_23e2dd5c0` | 111 | 1 | yes |
| `HotkeyDialog.start_listening` | `FUN_23e2ddb00` | 117 | 2 | yes |
| `HotkeyDialog.stop_listening` | `FUN_23e2de990` | 129 | 2 | yes |
| `HotkeyDialog.on_key_press` | `FUN_23e2e0080` | 162 | 1 | yes |
| `HotkeyDialog.on_key_release` | `FUN_23e2e0830` | 171 | 2 | yes |
| `HotkeyDialog.update_display` | `FUN_23e24f640` | 199 | 2 | yes |
| `HotkeyDialog.format_hotkey` | `FUN_23e2e33e0` | 243 | 1 | yes |
| `HotkeyDialog.get_key_name` | `FUN_23e2d98a0` | ? | ? | yes |
| `HotkeyDialog.closeEvent` | `FUN_23e2e2dc0` | ? | ? | yes |

## Local Variable Lists
- `151` `__class__`
- `152` `self, current_hotkey, parent, title, __class__`
- `153` `self, event, __class__`
- `154` `self, keys, modifiers, regular_keys, key, key_name, parts`
- `155` `self`
- `156` `self, key, name, special`
- `157` `self, layout, title, font, current, instructions, line, cancel_btn`
- `158` `self, key, e`
- `159` `self, display_text`

## Structured Constants
- `6` [True]
- `8` [500, 300]
- `13` [20, 20, 20, 20]
- `15` [15]
- `24` [14]
- `34` [80]
- `49` [35]
- `109` {'__dict_items__': [['space', 'Space'], ['enter', 'Enter'], ['tab', 'Tab'], ['caps_lock', 'CapsLock'], ['num_lock', 'NumLock'], ['scroll_lock', 'ScrollLock'], ['insert', 'Insert'], ['delete', 'Delete'], ['home', 'Home'], ['end', 'End'], ['page_up', 'PageUp'], ['page_down', 'PageDown'], ['up', 'Up'], ['down', 'Down'], ['left', 'Left'], ['right', 'Right']]}

## Per-Function Context
### `pynput.keyboard`

- implementation: `FUN_23e2da250`
- source line hint: `27`
- Nuitka codevar: `DAT_23eeb0250`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `118` 'has_location'
     `119` 'PyQt6.QtWidgets'
     `120` ['QDialog', 'QVBoxLayout', 'QLabel', 'QPushButton', 'QFrame']
     `121` 'QDialog'
     `122` 'PyQt6.QtCore'
     `123` ['Qt', 'QTimer']
     `124` 'PyQt6.QtGui'
     `125` ['QFont']
  => `126` 'pynput.keyboard'
     `127` '__prepare__'
     `128` 'HotkeyDialog'
     `129` '__getitem__'
     `130` '%s.__prepare__() must return a mapping, not %s'
     `131` '<metaclass>'
     `132` 'ui.hotkey_dialog'
     `133` 'Диалог для назначения горячей клавиши'
     `134` '__qualname__'
     `135` ['', None, 'Назначить горячую клавишу']
     `136` 'HotkeyDialog.__init__'
     `137` 'HotkeyDialog.init_ui'
     `138` 'HotkeyDialog.start_listening'
     `139` 'HotkeyDialog.stop_listening'
     `140` 'HotkeyDialog.on_key_press'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__hotkey_dialog\23e2da250_pynput.keyboard.c`

### `HotkeyDialog.__init__`

- implementation: `FUN_23e2dcfa0`
- source line hint: `103`
- Nuitka codevar: `_DAT_23eeb0228`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `128` 'HotkeyDialog'
     `129` '__getitem__'
     `130` '%s.__prepare__() must return a mapping, not %s'
     `131` '<metaclass>'
     `132` 'ui.hotkey_dialog'
     `133` 'Диалог для назначения горячей клавиши'
     `134` '__qualname__'
     `135` ['', None, 'Назначить горячую клавишу']
  => `136` 'HotkeyDialog.__init__'
     `137` 'HotkeyDialog.init_ui'
     `138` 'HotkeyDialog.start_listening'
     `139` 'HotkeyDialog.stop_listening'
     `140` 'HotkeyDialog.on_key_press'
     `141` 'HotkeyDialog.on_key_release'
     `142` 'HotkeyDialog.update_display'
     `143` 'HotkeyDialog.format_hotkey'
     `144` 'HotkeyDialog.get_key_name'
     `145` 'HotkeyDialog.closeEvent'
     `146` 'get_hotkey'
     `147` 'HotkeyDialog.get_hotkey'
     `148` '__orig_bases__'
     `149` 'ui\\hotkey_dialog.py'
     `150` '<module ui.hotkey_dialog>'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__hotkey_dialog\23e2dcfa0_HotkeyDialog.__init.c`

### `HotkeyDialog.init_ui`

- implementation: `FUN_23e2dd5c0`
- source line hint: `111`
- Nuitka codevar: `_DAT_23eeb0218`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `129` '__getitem__'
     `130` '%s.__prepare__() must return a mapping, not %s'
     `131` '<metaclass>'
     `132` 'ui.hotkey_dialog'
     `133` 'Диалог для назначения горячей клавиши'
     `134` '__qualname__'
     `135` ['', None, 'Назначить горячую клавишу']
     `136` 'HotkeyDialog.__init__'
  => `137` 'HotkeyDialog.init_ui'
     `138` 'HotkeyDialog.start_listening'
     `139` 'HotkeyDialog.stop_listening'
     `140` 'HotkeyDialog.on_key_press'
     `141` 'HotkeyDialog.on_key_release'
     `142` 'HotkeyDialog.update_display'
     `143` 'HotkeyDialog.format_hotkey'
     `144` 'HotkeyDialog.get_key_name'
     `145` 'HotkeyDialog.closeEvent'
     `146` 'get_hotkey'
     `147` 'HotkeyDialog.get_hotkey'
     `148` '__orig_bases__'
     `149` 'ui\\hotkey_dialog.py'
     `150` '<module ui.hotkey_dialog>'
     `151` ['__class__']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__hotkey_dialog\23e2dd5c0_HotkeyDialog.init_ui.c`

### `HotkeyDialog.start_listening`

- implementation: `FUN_23e2ddb00`
- source line hint: `117`
- Nuitka codevar: `_DAT_23eeb0208`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `130` '%s.__prepare__() must return a mapping, not %s'
     `131` '<metaclass>'
     `132` 'ui.hotkey_dialog'
     `133` 'Диалог для назначения горячей клавиши'
     `134` '__qualname__'
     `135` ['', None, 'Назначить горячую клавишу']
     `136` 'HotkeyDialog.__init__'
     `137` 'HotkeyDialog.init_ui'
  => `138` 'HotkeyDialog.start_listening'
     `139` 'HotkeyDialog.stop_listening'
     `140` 'HotkeyDialog.on_key_press'
     `141` 'HotkeyDialog.on_key_release'
     `142` 'HotkeyDialog.update_display'
     `143` 'HotkeyDialog.format_hotkey'
     `144` 'HotkeyDialog.get_key_name'
     `145` 'HotkeyDialog.closeEvent'
     `146` 'get_hotkey'
     `147` 'HotkeyDialog.get_hotkey'
     `148` '__orig_bases__'
     `149` 'ui\\hotkey_dialog.py'
     `150` '<module ui.hotkey_dialog>'
     `151` ['__class__']
     `152` ['self', 'current_hotkey', 'parent', 'title', '__class__']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__hotkey_dialog\23e2ddb00_HotkeyDialog.start_listening.c`

### `HotkeyDialog.stop_listening`

- implementation: `FUN_23e2de990`
- source line hint: `129`
- Nuitka codevar: `_DAT_23eeb01f8`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `131` '<metaclass>'
     `132` 'ui.hotkey_dialog'
     `133` 'Диалог для назначения горячей клавиши'
     `134` '__qualname__'
     `135` ['', None, 'Назначить горячую клавишу']
     `136` 'HotkeyDialog.__init__'
     `137` 'HotkeyDialog.init_ui'
     `138` 'HotkeyDialog.start_listening'
  => `139` 'HotkeyDialog.stop_listening'
     `140` 'HotkeyDialog.on_key_press'
     `141` 'HotkeyDialog.on_key_release'
     `142` 'HotkeyDialog.update_display'
     `143` 'HotkeyDialog.format_hotkey'
     `144` 'HotkeyDialog.get_key_name'
     `145` 'HotkeyDialog.closeEvent'
     `146` 'get_hotkey'
     `147` 'HotkeyDialog.get_hotkey'
     `148` '__orig_bases__'
     `149` 'ui\\hotkey_dialog.py'
     `150` '<module ui.hotkey_dialog>'
     `151` ['__class__']
     `152` ['self', 'current_hotkey', 'parent', 'title', '__class__']
     `153` ['self', 'event', '__class__']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__hotkey_dialog\23e2de990_HotkeyDialog.stop_listening.c`

### `HotkeyDialog.on_key_press`

- implementation: `FUN_23e2e0080`
- source line hint: `162`
- Nuitka codevar: `_DAT_23eeb01e0`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `132` 'ui.hotkey_dialog'
     `133` 'Диалог для назначения горячей клавиши'
     `134` '__qualname__'
     `135` ['', None, 'Назначить горячую клавишу']
     `136` 'HotkeyDialog.__init__'
     `137` 'HotkeyDialog.init_ui'
     `138` 'HotkeyDialog.start_listening'
     `139` 'HotkeyDialog.stop_listening'
  => `140` 'HotkeyDialog.on_key_press'
     `141` 'HotkeyDialog.on_key_release'
     `142` 'HotkeyDialog.update_display'
     `143` 'HotkeyDialog.format_hotkey'
     `144` 'HotkeyDialog.get_key_name'
     `145` 'HotkeyDialog.closeEvent'
     `146` 'get_hotkey'
     `147` 'HotkeyDialog.get_hotkey'
     `148` '__orig_bases__'
     `149` 'ui\\hotkey_dialog.py'
     `150` '<module ui.hotkey_dialog>'
     `151` ['__class__']
     `152` ['self', 'current_hotkey', 'parent', 'title', '__class__']
     `153` ['self', 'event', '__class__']
     `154` ['self', 'keys', 'modifiers', 'regular_keys', 'key', 'key_name', 'parts']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__hotkey_dialog\23e2e0080_HotkeyDialog.on_key_press.c`

### `HotkeyDialog.on_key_release`

- implementation: `FUN_23e2e0830`
- source line hint: `171`
- Nuitka codevar: `_DAT_23eeb01d0`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `133` 'Диалог для назначения горячей клавиши'
     `134` '__qualname__'
     `135` ['', None, 'Назначить горячую клавишу']
     `136` 'HotkeyDialog.__init__'
     `137` 'HotkeyDialog.init_ui'
     `138` 'HotkeyDialog.start_listening'
     `139` 'HotkeyDialog.stop_listening'
     `140` 'HotkeyDialog.on_key_press'
  => `141` 'HotkeyDialog.on_key_release'
     `142` 'HotkeyDialog.update_display'
     `143` 'HotkeyDialog.format_hotkey'
     `144` 'HotkeyDialog.get_key_name'
     `145` 'HotkeyDialog.closeEvent'
     `146` 'get_hotkey'
     `147` 'HotkeyDialog.get_hotkey'
     `148` '__orig_bases__'
     `149` 'ui\\hotkey_dialog.py'
     `150` '<module ui.hotkey_dialog>'
     `151` ['__class__']
     `152` ['self', 'current_hotkey', 'parent', 'title', '__class__']
     `153` ['self', 'event', '__class__']
     `154` ['self', 'keys', 'modifiers', 'regular_keys', 'key', 'key_name', 'parts']
     `155` ['self']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__hotkey_dialog\23e2e0830_HotkeyDialog.on_key_release.c`

### `HotkeyDialog.update_display`

- implementation: `FUN_23e24f640`
- source line hint: `199`
- Nuitka codevar: `_DAT_23eeb01c0`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `134` '__qualname__'
     `135` ['', None, 'Назначить горячую клавишу']
     `136` 'HotkeyDialog.__init__'
     `137` 'HotkeyDialog.init_ui'
     `138` 'HotkeyDialog.start_listening'
     `139` 'HotkeyDialog.stop_listening'
     `140` 'HotkeyDialog.on_key_press'
     `141` 'HotkeyDialog.on_key_release'
  => `142` 'HotkeyDialog.update_display'
     `143` 'HotkeyDialog.format_hotkey'
     `144` 'HotkeyDialog.get_key_name'
     `145` 'HotkeyDialog.closeEvent'
     `146` 'get_hotkey'
     `147` 'HotkeyDialog.get_hotkey'
     `148` '__orig_bases__'
     `149` 'ui\\hotkey_dialog.py'
     `150` '<module ui.hotkey_dialog>'
     `151` ['__class__']
     `152` ['self', 'current_hotkey', 'parent', 'title', '__class__']
     `153` ['self', 'event', '__class__']
     `154` ['self', 'keys', 'modifiers', 'regular_keys', 'key', 'key_name', 'parts']
     `155` ['self']
     `156` ['self', 'key', 'name', 'special']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__hotkey_dialog\23e24f640_HotkeyDialog.update_display.c`

### `HotkeyDialog.format_hotkey`

- implementation: `FUN_23e2e33e0`
- source line hint: `243`
- Nuitka codevar: `_DAT_23eeb01a0`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `135` ['', None, 'Назначить горячую клавишу']
     `136` 'HotkeyDialog.__init__'
     `137` 'HotkeyDialog.init_ui'
     `138` 'HotkeyDialog.start_listening'
     `139` 'HotkeyDialog.stop_listening'
     `140` 'HotkeyDialog.on_key_press'
     `141` 'HotkeyDialog.on_key_release'
     `142` 'HotkeyDialog.update_display'
  => `143` 'HotkeyDialog.format_hotkey'
     `144` 'HotkeyDialog.get_key_name'
     `145` 'HotkeyDialog.closeEvent'
     `146` 'get_hotkey'
     `147` 'HotkeyDialog.get_hotkey'
     `148` '__orig_bases__'
     `149` 'ui\\hotkey_dialog.py'
     `150` '<module ui.hotkey_dialog>'
     `151` ['__class__']
     `152` ['self', 'current_hotkey', 'parent', 'title', '__class__']
     `153` ['self', 'event', '__class__']
     `154` ['self', 'keys', 'modifiers', 'regular_keys', 'key', 'key_name', 'parts']
     `155` ['self']
     `156` ['self', 'key', 'name', 'special']
     `157` ['self', 'layout', 'title', 'font', 'current', 'instructions', 'line', 'cancel_btn']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__hotkey_dialog\23e2e33e0_HotkeyDialog.format_hotkey.c`

### `HotkeyDialog.get_key_name`

- implementation: `FUN_23e2d98a0`
- source line hint: `?`
- Nuitka codevar: `uVar5`
- factory: `FUN_23e93e480`
- nearby constants:
     `136` 'HotkeyDialog.__init__'
     `137` 'HotkeyDialog.init_ui'
     `138` 'HotkeyDialog.start_listening'
     `139` 'HotkeyDialog.stop_listening'
     `140` 'HotkeyDialog.on_key_press'
     `141` 'HotkeyDialog.on_key_release'
     `142` 'HotkeyDialog.update_display'
     `143` 'HotkeyDialog.format_hotkey'
  => `144` 'HotkeyDialog.get_key_name'
     `145` 'HotkeyDialog.closeEvent'
     `146` 'get_hotkey'
     `147` 'HotkeyDialog.get_hotkey'
     `148` '__orig_bases__'
     `149` 'ui\\hotkey_dialog.py'
     `150` '<module ui.hotkey_dialog>'
     `151` ['__class__']
     `152` ['self', 'current_hotkey', 'parent', 'title', '__class__']
     `153` ['self', 'event', '__class__']
     `154` ['self', 'keys', 'modifiers', 'regular_keys', 'key', 'key_name', 'parts']
     `155` ['self']
     `156` ['self', 'key', 'name', 'special']
     `157` ['self', 'layout', 'title', 'font', 'current', 'instructions', 'line', 'cancel_btn']
     `158` ['self', 'key', 'e']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__hotkey_dialog\23e2d98a0_HotkeyDialog.get_key_name.c`

### `HotkeyDialog.closeEvent`

- implementation: `FUN_23e2e2dc0`
- source line hint: `?`
- Nuitka codevar: `_DAT_23eeb01b0`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `137` 'HotkeyDialog.init_ui'
     `138` 'HotkeyDialog.start_listening'
     `139` 'HotkeyDialog.stop_listening'
     `140` 'HotkeyDialog.on_key_press'
     `141` 'HotkeyDialog.on_key_release'
     `142` 'HotkeyDialog.update_display'
     `143` 'HotkeyDialog.format_hotkey'
     `144` 'HotkeyDialog.get_key_name'
  => `145` 'HotkeyDialog.closeEvent'
     `146` 'get_hotkey'
     `147` 'HotkeyDialog.get_hotkey'
     `148` '__orig_bases__'
     `149` 'ui\\hotkey_dialog.py'
     `150` '<module ui.hotkey_dialog>'
     `151` ['__class__']
     `152` ['self', 'current_hotkey', 'parent', 'title', '__class__']
     `153` ['self', 'event', '__class__']
     `154` ['self', 'keys', 'modifiers', 'regular_keys', 'key', 'key_name', 'parts']
     `155` ['self']
     `156` ['self', 'key', 'name', 'special']
     `157` ['self', 'layout', 'title', 'font', 'current', 'instructions', 'line', 'cancel_btn']
     `158` ['self', 'key', 'e']
     `159` ['self', 'display_text']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__hotkey_dialog\23e2e2dc0_HotkeyDialog.closeEvent.c`
