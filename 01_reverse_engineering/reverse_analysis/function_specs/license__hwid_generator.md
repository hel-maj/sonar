# Function Specification: `license.hwid_generator`

This is a reconstruction dossier from static Nuitka constants and Ghidra decompilation. It is not original Python source text.

## Source Path Hints
- `license\hwid_generator.py`

## Docstrings / Long Text
- `74` '\n    Генерирует уникальный HWID устройства.\n    SHA256(MachineGuid|VolumeSerial)\n\n    Returns:\n        str: SHA256 хеш\n    '
- `80` '\nHWID Generator для KortexWorker\nГенерирует уникальный идентификатор устройства на основе:\n- Windows Machine GUID   (winreg)\n- Volume Serial системного диска (ctypes Win32 API)\n\nТолько winreg + ctypes + os — никакого WMI, subprocess, pywin32.\nРаботает мгновенно на любой Windows 10/11 без исключений.\nСистемный диск определяется автоматически (C:, D: и т.д.).\n'

## Function Inventory
| Inferred qualname | Impl | Source line | Arg count | Decompiled C |
|---|---:|---:|---:|---|
| `?` | `FUN_23c65bd40` | 22 | uVar17&0xffffffff00000000 | yes |
| `?` | `FUN_23c65e4c0` | 48 | uVar17 | yes |
| `?` | `FUN_23c61f120` | 116 | uVar17 | yes |
| `?` | `FUN_23c6218f0` | ? | ? | yes |

## Structured Constants
- `10` [None, None, None]
- `32` {'__slice__': [None, 2, None]}
- `36` [0]
- `55` {'__slice__': [None, 32, None]}
- `88` {'__dict_items__': [['return', {'__builtin__': 'str'}]]}
- `89` {'__dict_items__': [['return', {'__builtin__': 'dict'}]]}

## Per-Function Context
### `?`

- implementation: `FUN_23c65bd40`
- source line hint: `22`
- Nuitka codevar: `_DAT_23ee29d90`
- factory: `FUN_23e93df40`
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\license__hwid_generator\23c65bd40_unknown.c`

### `?`

- implementation: `FUN_23c65e4c0`
- source line hint: `48`
- Nuitka codevar: `_DAT_23ee29d80`
- factory: `FUN_23e93df40`
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\license__hwid_generator\23c65e4c0_unknown.c`

### `?`

- implementation: `FUN_23c61f120`
- source line hint: `116`
- Nuitka codevar: `_DAT_23ee29d60`
- factory: `FUN_23e93df40`
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\license__hwid_generator\23c61f120_unknown.c`

### `?`

- implementation: `FUN_23c6218f0`
- source line hint: `?`
- Nuitka codevar: `_DAT_23ee29d48`
- factory: `FUN_23e93df40`
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\license__hwid_generator\23c6218f0_unknown.c`
