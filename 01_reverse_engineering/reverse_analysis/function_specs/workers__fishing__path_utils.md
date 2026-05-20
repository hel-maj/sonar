# Function Specification: `workers.fishing.path_utils`

This is a reconstruction dossier from static Nuitka constants and Ghidra decompilation. It is not original Python source text.

## Source Path Hints
- `workers\fishing\path_utils.py`

## Docstrings / Long Text
- `5` '\nApp dir: '
- `6` '\nFrozen: '
- `7` '\n    Получить путь к папке resources.\n    \n    Работает корректно в обоих режимах:\n    - Dev (python main.py): resources рядом с main.py\n    - Compiled (Nuitka --onefile): resources в %TEMP%\\onefile_XXX    \n    Returns:\n        Path: Абсолютный путь к папке resources\n    '
- `13` '\n    Получить путь к папке с шаблонами CV.\n    \n    Args:\n        template_type: Тип шаблонов (triger, fish_inv_2k, garbage и т.д.)\n    \n    Returns:\n        Path: Путь к папке с шаблонами\n    '
- `17` '\nУтилиты для работы с путями к ресурсам\nКорректно работает в dev режиме и после компиляции Nuitka --onefile\n'

## Function Inventory
| Inferred qualname | Impl | Source line | Arg count | Decompiled C |
|---|---:|---:|---:|---|
| `icon.jpeg` | `FUN_23e825840` | 10 | uVar19&0xffffffff00000000 | yes |
| `?` | `FUN_23e826c80` | 50 | 1 | yes |
| `?` | `FUN_23e827580` | 68 | uVar19 | yes |
| `?` | `FUN_23e826850` | ? | ? | yes |

## Per-Function Context
### `icon.jpeg`

- implementation: `FUN_23e825840`
- source line hint: `10`
- Nuitka codevar: `DAT_23eede770`
- factory: `FUN_23e93df40`
- nearby constants:
     `6` '\nFrozen: '
     `7` '\n    Получить путь к папке resources.\n    \n    Работает корректно в обоих режимах:\n    - Dev (python main.py): resources рядом с main.py\n    - Compiled (Nuitka --onefile): resources в %TEMP%\\onefile_XXX    \n    Returns:\n        Path: Абсолютный путь к папке resources\...
     `8` 'get_resources_dir'
     `9` 'fishing'
     `10` 'Получить путь к resources/fishing/'
     `11` 'get_fishing_resources'
     `12` 'Templates directory not found: '
     `13` '\n    Получить путь к папке с шаблонами CV.\n    \n    Args:\n        template_type: Тип шаблонов (triger, fish_inv_2k, garbage и т.д.)\n    \n    Returns:\n        Path: Путь к папке с шаблонами\n    '
  => `14` 'icon.jpeg'
     `15` 'Icon not found: '
     `16` 'Получить путь к иконке приложения'
     `17` '\nУтилиты для работы с путями к ресурсам\nКорректно работает в dev режиме и после компиляции Nuitka --onefile\n'
     `18` 'origin'
     `19` 'has_location'
     `20` 'sys'
     `21` 'os'
     `22` 'pathlib'
     `23` ['Path']
     `24` 'return'
     `25` ['triger']
     `26` 'template_type'
     `27` 'get_templates_dir'
     `28` 'get_icon_path'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__path_utils\23e825840_icon.jpeg.c`

### `?`

- implementation: `FUN_23e826c80`
- source line hint: `50`
- Nuitka codevar: `DAT_23eede748`
- factory: `FUN_23e93df40`
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__path_utils\23e826c80_unknown.c`

### `?`

- implementation: `FUN_23e827580`
- source line hint: `68`
- Nuitka codevar: `DAT_23eede730`
- factory: `FUN_23e93df40`
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__path_utils\23e827580_unknown.c`

### `?`

- implementation: `FUN_23e826850`
- source line hint: `?`
- Nuitka codevar: `DAT_23eede758`
- factory: `FUN_23e93df40`
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__path_utils\23e826850_unknown.c`
