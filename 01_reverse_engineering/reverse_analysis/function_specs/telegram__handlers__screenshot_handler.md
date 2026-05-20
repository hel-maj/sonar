# Function Specification: `telegram.handlers.screenshot_handler`

This is a reconstruction dossier from static Nuitka constants and Ghidra decompilation. It is not original Python source text.

## Source Path Hints
- `telegram\handlers\screenshot_handler.py`

## Docstrings / Long Text
- `79` '\nОбработчик скриншотов\n'

## Function Inventory
| Inferred qualname | Impl | Source line | Arg count | Decompiled C |
|---|---:|---:|---:|---|
| `workers.fishing.window_capture` | `FUN_23e144fc0` | 16 | uVar17&0xffffffff00000000 | yes |
| `?` | `FUN_23e0f0fd0` | 33 | uVar17&0xffffffff00000000 | yes |
| `?` | `LAB_23e125790` | 59 | 1 | yes |
| `?` | `FUN_23e125a00` | 79 | 2 | yes |

## Structured Constants
- `6` [None, None, None]
- `13` [1]
- `28` {'__dict_items__': [['format', 'PNG']]}
- `30` [0]
- `32` {'__dict_items__': [['filename', 'game_screenshot.png']]}
- `45` {'__dict_items__': [['user_id', {'__builtin__': 'int'}], ['return', {'__builtin__': 'bool'}]]}
- `97` {'__dict_items__': [['monitor_num', {'__builtin__': 'int'}]]}

## Per-Function Context
### `workers.fishing.window_capture`

- implementation: `FUN_23e144fc0`
- source line hint: `16`
- Nuitka codevar: `DAT_23eeaaf48`
- factory: `FUN_23e93df40`
- nearby constants:
     `86` 'aiogram.types'
     `87` ['CallbackQuery', 'BufferedInputFile']
     `88` 'aiogram.utils.keyboard'
     `89` ['InlineKeyboardBuilder']
     `90` 'aiogram.exceptions'
     `91` ['TelegramNetworkError']
     `92` 'PIL'
     `93` ['Image']
  => `94` 'workers.fishing.window_capture'
     `95` ['WindowCapture']
     `96` 'get_screenshot_menu_keyboard'
     `97` {'__dict_items__': [['monitor_num', {'__builtin__': 'int'}]]}
     `98` 'dp'
     `99` 'register_screenshot_handlers'
     `100` 'telegram\\handlers\\screenshot_handler.py'
     `101` '<module telegram.handlers.screenshot_handler>'
     `102` ['builder', 'sct', 'monitor_count', 'i']
     `103` ['user_id', 'admin_ids']
     `104` ['admin_ids']
     `105` ['dp', 'admin_ids', 'is_admin_user', 'screenshot_handler']
     `106` ['callback', 'parts', 'action', 'screenshot', 'monitor_num', 'is_admin_user']
     `107` ['is_admin_user']
     `108` ['cv2', 'capture', 'frame', 'frame_rgb', 'img', 'buf']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\telegram__handlers__screenshot_handler\23e144fc0_workers.fishing.window_capture.c`

### `?`

- implementation: `FUN_23e0f0fd0`
- source line hint: `33`
- Nuitka codevar: `DAT_23eeaaf38`
- factory: `FUN_23e93df40`
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\telegram__handlers__screenshot_handler\23e0f0fd0_unknown.c`

### `?`

- implementation: `LAB_23e125790`
- source line hint: `59`
- Nuitka codevar: `DAT_23eeaaf20`
- factory: `FUN_23e93df40`
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\telegram__handlers__screenshot_handler\23e125790_unknown.c`

### `?`

- implementation: `FUN_23e125a00`
- source line hint: `79`
- Nuitka codevar: `DAT_23eeaaf08`
- factory: `FUN_23e93df40`
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\telegram__handlers__screenshot_handler\23e125a00_unknown.c`
