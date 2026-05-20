# Function Specification: `workers.fishing.window_activator`

This is a reconstruction dossier from static Nuitka constants and Ghidra decompilation. It is not original Python source text.

## Source Path Hints
- `workers\fishing\window_activator.py`

## Docstrings / Long Text
- `72` '\n        Активировать окно с гарантией (несколько методов + retry)\n        Возвращает True если окно активировано успешно\n        \n        ВАЖНО: Windows не позволяет приложению активировать другое окно\n        если пользователь не взаимодействовал с приложением недавно.\n        Используем комбинацию методов для обхода этого ограничения.\n        '
- `79` '\n        Найти и активировать окно GTA5\n        Возвращает True если успешно\n        '
- `80` '\nНадёжная активация окна GTA5\nИспользует 5 различных методов для 100% гарантии активации окна\n\nМЕТОДЫ АКТИВАЦИИ (в порядке применения):\n1. Подготовка окна (ShowWindow, BringWindowToTop) - подготовить окно к активации\n2. AttachThreadInput - КЛЮЧЕВОЙ метод обхода ограничений Windows\n3. SendInput (Alt key) - имитация пользовательского ввода для разблокировки\n4. AllowSetForegroundWindow - явное разрешение активации целевому процессу\n5. SwitchToThisWindow - недокументированный API, работ...

## Function Inventory
| Inferred qualname | Impl | Source line | Arg count | Decompiled C |
|---|---:|---:|---:|---|
| `WindowActivator.find_window_by_process` | `FUN_23e846e80` | 44 | uVar22 | yes |
| `WindowActivator.activate_window` | `FUN_23e848360` | 69 | 2 | yes |
| `WindowActivator.force_activate_gta5` | `FUN_23e854310` | 249 | uVar22&0xffffffff00000000 | yes |
| `?` | `FUN_23e846e80` | ? | ? | yes |
| `?` | `FUN_23e848360` | ? | ? | yes |
| `?` | `FUN_23e854310` | ? | ? | yes |

## Local Variable Lists
- `97` `__class__`

## Structured Constants
- `21` [0.1]
- `23` [0.05]
- `53` [0]
- `58` [0.01]
- `61` [0.02]
- `68` [0.2]
- `78` {'__dict_items__': [['max_attempts', 3]]}
- `86` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
- `88` [3]
- `89` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}

## Per-Function Context
### `WindowActivator.find_window_by_process`

- implementation: `FUN_23e846e80`
- source line hint: `44`
- Nuitka codevar: `uVar6`
- factory: `FUN_23e93e480`
- nearby constants:
     `79` '\n        Найти и активировать окно GTA5\n        Возвращает True если успешно\n        '
     `80` '\nНадёжная активация окна GTA5\nИспользует 5 различных методов для 100% гарантии активации окна\n\nМЕТОДЫ АКТИВАЦИИ (в порядке применения):\n1. Подготовка окна (ShowWindow, BringWindowToTop) - подготовить окно к активации\n2. AttachThreadInput - КЛЮЧЕВОЙ метод обхода ограниче...
     `81` 'origin'
     `82` 'has_location'
     `83` 'ctypes'
     `84` 'wintypes'
     `85` 'Класс для надёжной активации окна процесса'
     `86` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
  => `87` 'WindowActivator.find_window_by_process'
     `88` [3]
     `89` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `90` 'WindowActivator.activate_window'
     `91` 'force_activate_gta5'
     `92` 'WindowActivator.force_activate_gta5'
     `93` 'workers\\fishing\\window_activator.py'
     `94` '<module workers.fishing.window_activator>'
     `95` ['__class__', 'KEYBDINPUT']
     `96` ['__class__', 'PUL']
     `97` ['__class__']
     `98` ['hwnd', 'max_attempts', 'attempt', 'foreground_hwnd', 'foreground_thread_id', '_', 'target_thread_id', 'result', 'e', 'PUL', 'KEYBDINPUT', 'INPUT', 'extra', 'ii_', 'target_pid']
     `99` ['hwnd', 'hwnds', '_', 'pid', 'process', 'title', 'process_name']
     `100` ['process_name']
     `101` ['process_name', 'callback', 'hwnds']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__window_activator\23e846e80_WindowActivator.find_window_by_process.c`

### `WindowActivator.activate_window`

- implementation: `FUN_23e848360`
- source line hint: `69`
- Nuitka codevar: `uVar6`
- factory: `FUN_23e93e480`
- nearby constants:
     `82` 'has_location'
     `83` 'ctypes'
     `84` 'wintypes'
     `85` 'Класс для надёжной активации окна процесса'
     `86` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
     `87` 'WindowActivator.find_window_by_process'
     `88` [3]
     `89` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
  => `90` 'WindowActivator.activate_window'
     `91` 'force_activate_gta5'
     `92` 'WindowActivator.force_activate_gta5'
     `93` 'workers\\fishing\\window_activator.py'
     `94` '<module workers.fishing.window_activator>'
     `95` ['__class__', 'KEYBDINPUT']
     `96` ['__class__', 'PUL']
     `97` ['__class__']
     `98` ['hwnd', 'max_attempts', 'attempt', 'foreground_hwnd', 'foreground_thread_id', '_', 'target_thread_id', 'result', 'e', 'PUL', 'KEYBDINPUT', 'INPUT', 'extra', 'ii_', 'target_pid']
     `99` ['hwnd', 'hwnds', '_', 'pid', 'process', 'title', 'process_name']
     `100` ['process_name']
     `101` ['process_name', 'callback', 'hwnds']
     `102` ['hwnd']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__window_activator\23e848360_WindowActivator.activate_window.c`

### `WindowActivator.force_activate_gta5`

- implementation: `FUN_23e854310`
- source line hint: `249`
- Nuitka codevar: `_DAT_23eede338`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `84` 'wintypes'
     `85` 'Класс для надёжной активации окна процесса'
     `86` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
     `87` 'WindowActivator.find_window_by_process'
     `88` [3]
     `89` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `90` 'WindowActivator.activate_window'
     `91` 'force_activate_gta5'
  => `92` 'WindowActivator.force_activate_gta5'
     `93` 'workers\\fishing\\window_activator.py'
     `94` '<module workers.fishing.window_activator>'
     `95` ['__class__', 'KEYBDINPUT']
     `96` ['__class__', 'PUL']
     `97` ['__class__']
     `98` ['hwnd', 'max_attempts', 'attempt', 'foreground_hwnd', 'foreground_thread_id', '_', 'target_thread_id', 'result', 'e', 'PUL', 'KEYBDINPUT', 'INPUT', 'extra', 'ii_', 'target_pid']
     `99` ['hwnd', 'hwnds', '_', 'pid', 'process', 'title', 'process_name']
     `100` ['process_name']
     `101` ['process_name', 'callback', 'hwnds']
     `102` ['hwnd']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__window_activator\23e854310_WindowActivator.force_activate_gta5.c`

### `?`

- implementation: `FUN_23e846e80`
- source line hint: `?`
- Nuitka codevar: `uVar6`
- factory: `FUN_23e93e480`
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__window_activator\23e846e80_unknown.c`

### `?`

- implementation: `FUN_23e848360`
- source line hint: `?`
- Nuitka codevar: `uVar6`
- factory: `FUN_23e93e480`
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__window_activator\23e848360_unknown.c`

### `?`

- implementation: `FUN_23e854310`
- source line hint: `?`
- Nuitka codevar: `_DAT_23eede338`
- factory: `FUN_23e93e1e0`
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__window_activator\23e854310_unknown.c`
