# Function Specification: `config_manager`

This is a reconstruction dossier from static Nuitka constants and Ghidra decompilation. It is not original Python source text.

## Docstrings / Long Text
- `35` '\nМенеджер конфигурации для KortexWorker\nСохранение и загрузка настроек рыбалки\n'

## Function Inventory
| Inferred qualname | Impl | Source line | Arg count | Decompiled C |
|---|---:|---:|---:|---|
| `fishing_settings.json` | `FUN_23c04ae50` | 21 | 1 | yes |
| `telegram_settings.json` | `FUN_23c0002b0` | 59 | 2 | yes |
| `ConfigManager.__init__` | `FUN_23c0332d0` | 72 | 1 | yes |
| `ConfigManager.load_fishing_settings` | `FUN_23c034280` | 78 | 1 | yes |
| `ConfigManager.save_fishing_settings` | `FUN_23c035230` | 84 | 1 | yes |
| `ConfigManager.get_fish_to_keep` | `FUN_23c0361e0` | 90 | 1 | yes |
| `ConfigManager.get_fish_to_release` | `FUN_23c04cf50` | 100 | 1 | yes |
| `ConfigManager.get_garbage_to_eject` | `FUN_23c001f30` | 134 | 2 | yes |

## Local Variable Lists
- `62` `self, config_dir`
- `63` `self, settings, fish_settings`
- `64` `self, settings, garbage_settings`
- `65` `self, default_settings, f, settings, merged, e`
- `66` `self, settings, clean_settings, f, e`
- `67` `self, settings, f, e`

## Structured Constants
- `7` {'__dict_items__': [['auto_meal', True], ['auto_change_bait', False], ['store_in_backpack', True], ['store_in_trunk', False], ['shutdown_on_overweight', False], ['hotkey', 'F9'], ['fish_settings', {'__dict_items__': []}], ['garbage_settings', {'__dict_items__': [['bag', True], ['corn', True], ['pack', True]]}]]}
- `15` [None, None, None]
- `20` {'__dict_items__': [['ensure_ascii', False], ['indent', 4]]}
- `29` {'__dict_items__': [['bot_token', ''], ['chat_id', ''], ['admin_ids', ''], ['enabled', False], ['auto_start', False], ['notifications', {'__dict_items__': [['caught_fish', True], ['meal', True], ['backpack_storage', True], ['inventory_full', True], ['fishing_restored', True], ['tackle_ended', True], ['bait_changed', True]]}]]}

## Per-Function Context
### `fishing_settings.json`

- implementation: `FUN_23c04ae50`
- source line hint: `21`
- Nuitka codevar: `DAT_23ee0b658`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `0` 'config_dir'
     `1` 'join'
  => `2` 'fishing_settings.json'
     `3` 'fishing_settings_file'
     `4` 'telegram_settings.json'
     `5` 'telegram_settings_file'
     `6` 'makedirs'
     `7` {'__dict_items__': [['auto_meal', True], ['auto_change_bait', False], ['store_in_backpack', True], ['store_in_trunk', False], ['shutdown_on_overweight', False], ['hotkey', 'F9'], ['fish_settings', {'__dict_items__': []}], ['garbage_settings', {'__dict_items__': [['bag', True],...
     `8` 'utf-8'
     `9` 'json'
     `10` 'load'
     `11` 'garbage_settings'
     `12` 'fish_settings'
     `13` 'pop'
     `14` ['ocean_fishing', None]
     `15` [None, None, None]
     `16` 'Ошибка загрузки настроек: '
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\config_manager\23c04ae50_fishing_settings.json.c`

### `telegram_settings.json`

- implementation: `FUN_23c0002b0`
- source line hint: `59`
- Nuitka codevar: `_DAT_23ee0b648`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `0` 'config_dir'
     `1` 'join'
     `2` 'fishing_settings.json'
     `3` 'fishing_settings_file'
  => `4` 'telegram_settings.json'
     `5` 'telegram_settings_file'
     `6` 'makedirs'
     `7` {'__dict_items__': [['auto_meal', True], ['auto_change_bait', False], ['store_in_backpack', True], ['store_in_trunk', False], ['shutdown_on_overweight', False], ['hotkey', 'F9'], ['fish_settings', {'__dict_items__': []}], ['garbage_settings', {'__dict_items__': [['bag', True],...
     `8` 'utf-8'
     `9` 'json'
     `10` 'load'
     `11` 'garbage_settings'
     `12` 'fish_settings'
     `13` 'pop'
     `14` ['ocean_fishing', None]
     `15` [None, None, None]
     `16` 'Ошибка загрузки настроек: '
     `17` 'Загрузить настройки рыбалки'
     `18` 'ocean_fishing'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\config_manager\23c0002b0_telegram_settings.json.c`

### `ConfigManager.__init__`

- implementation: `FUN_23c0332d0`
- source line hint: `72`
- Nuitka codevar: `_DAT_23ee0b638`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `36` 'origin'
     `37` 'has_location'
     `38` 'os'
     `39` 'config_manager'
     `40` 'Управление файлами конфигурации'
     `41` 'ConfigManager'
     `42` '__qualname__'
     `43` ['config']
  => `44` 'ConfigManager.__init__'
     `45` 'ConfigManager.load_fishing_settings'
     `46` 'save_fishing_settings'
     `47` 'ConfigManager.save_fishing_settings'
     `48` 'get_fish_to_keep'
     `49` 'ConfigManager.get_fish_to_keep'
     `50` 'get_fish_to_release'
     `51` 'ConfigManager.get_fish_to_release'
     `52` 'get_garbage_to_eject'
     `53` 'ConfigManager.get_garbage_to_eject'
     `54` 'get_garbage_to_keep'
     `55` 'ConfigManager.get_garbage_to_keep'
     `56` 'load_telegram_settings'
     `57` 'ConfigManager.load_telegram_settings'
     `58` 'save_telegram_settings'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\config_manager\23c0332d0_ConfigManager.__init.c`

### `ConfigManager.load_fishing_settings`

- implementation: `FUN_23c034280`
- source line hint: `78`
- Nuitka codevar: `_DAT_23ee0b628`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `37` 'has_location'
     `38` 'os'
     `39` 'config_manager'
     `40` 'Управление файлами конфигурации'
     `41` 'ConfigManager'
     `42` '__qualname__'
     `43` ['config']
     `44` 'ConfigManager.__init__'
  => `45` 'ConfigManager.load_fishing_settings'
     `46` 'save_fishing_settings'
     `47` 'ConfigManager.save_fishing_settings'
     `48` 'get_fish_to_keep'
     `49` 'ConfigManager.get_fish_to_keep'
     `50` 'get_fish_to_release'
     `51` 'ConfigManager.get_fish_to_release'
     `52` 'get_garbage_to_eject'
     `53` 'ConfigManager.get_garbage_to_eject'
     `54` 'get_garbage_to_keep'
     `55` 'ConfigManager.get_garbage_to_keep'
     `56` 'load_telegram_settings'
     `57` 'ConfigManager.load_telegram_settings'
     `58` 'save_telegram_settings'
     `59` 'ConfigManager.save_telegram_settings'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\config_manager\23c034280_ConfigManager.load_fishing_settings.c`

### `ConfigManager.save_fishing_settings`

- implementation: `FUN_23c035230`
- source line hint: `84`
- Nuitka codevar: `_DAT_23ee0b618`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `39` 'config_manager'
     `40` 'Управление файлами конфигурации'
     `41` 'ConfigManager'
     `42` '__qualname__'
     `43` ['config']
     `44` 'ConfigManager.__init__'
     `45` 'ConfigManager.load_fishing_settings'
     `46` 'save_fishing_settings'
  => `47` 'ConfigManager.save_fishing_settings'
     `48` 'get_fish_to_keep'
     `49` 'ConfigManager.get_fish_to_keep'
     `50` 'get_fish_to_release'
     `51` 'ConfigManager.get_fish_to_release'
     `52` 'get_garbage_to_eject'
     `53` 'ConfigManager.get_garbage_to_eject'
     `54` 'get_garbage_to_keep'
     `55` 'ConfigManager.get_garbage_to_keep'
     `56` 'load_telegram_settings'
     `57` 'ConfigManager.load_telegram_settings'
     `58` 'save_telegram_settings'
     `59` 'ConfigManager.save_telegram_settings'
     `60` 'config_manager.py'
     `61` '<module config_manager>'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\config_manager\23c035230_ConfigManager.save_fishing_settings.c`

### `ConfigManager.get_fish_to_keep`

- implementation: `FUN_23c0361e0`
- source line hint: `90`
- Nuitka codevar: `_DAT_23ee0b608`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `41` 'ConfigManager'
     `42` '__qualname__'
     `43` ['config']
     `44` 'ConfigManager.__init__'
     `45` 'ConfigManager.load_fishing_settings'
     `46` 'save_fishing_settings'
     `47` 'ConfigManager.save_fishing_settings'
     `48` 'get_fish_to_keep'
  => `49` 'ConfigManager.get_fish_to_keep'
     `50` 'get_fish_to_release'
     `51` 'ConfigManager.get_fish_to_release'
     `52` 'get_garbage_to_eject'
     `53` 'ConfigManager.get_garbage_to_eject'
     `54` 'get_garbage_to_keep'
     `55` 'ConfigManager.get_garbage_to_keep'
     `56` 'load_telegram_settings'
     `57` 'ConfigManager.load_telegram_settings'
     `58` 'save_telegram_settings'
     `59` 'ConfigManager.save_telegram_settings'
     `60` 'config_manager.py'
     `61` '<module config_manager>'
     `62` ['self', 'config_dir']
     `63` ['self', 'settings', 'fish_settings']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\config_manager\23c0361e0_ConfigManager.get_fish_to_keep.c`

### `ConfigManager.get_fish_to_release`

- implementation: `FUN_23c04cf50`
- source line hint: `100`
- Nuitka codevar: `_DAT_23ee0b5f8`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `43` ['config']
     `44` 'ConfigManager.__init__'
     `45` 'ConfigManager.load_fishing_settings'
     `46` 'save_fishing_settings'
     `47` 'ConfigManager.save_fishing_settings'
     `48` 'get_fish_to_keep'
     `49` 'ConfigManager.get_fish_to_keep'
     `50` 'get_fish_to_release'
  => `51` 'ConfigManager.get_fish_to_release'
     `52` 'get_garbage_to_eject'
     `53` 'ConfigManager.get_garbage_to_eject'
     `54` 'get_garbage_to_keep'
     `55` 'ConfigManager.get_garbage_to_keep'
     `56` 'load_telegram_settings'
     `57` 'ConfigManager.load_telegram_settings'
     `58` 'save_telegram_settings'
     `59` 'ConfigManager.save_telegram_settings'
     `60` 'config_manager.py'
     `61` '<module config_manager>'
     `62` ['self', 'config_dir']
     `63` ['self', 'settings', 'fish_settings']
     `64` ['self', 'settings', 'garbage_settings']
     `65` ['self', 'default_settings', 'f', 'settings', 'merged', 'e']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\config_manager\23c04cf50_ConfigManager.get_fish_to_release.c`

### `ConfigManager.get_garbage_to_eject`

- implementation: `FUN_23c001f30`
- source line hint: `134`
- Nuitka codevar: `_DAT_23ee0b5e8`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `45` 'ConfigManager.load_fishing_settings'
     `46` 'save_fishing_settings'
     `47` 'ConfigManager.save_fishing_settings'
     `48` 'get_fish_to_keep'
     `49` 'ConfigManager.get_fish_to_keep'
     `50` 'get_fish_to_release'
     `51` 'ConfigManager.get_fish_to_release'
     `52` 'get_garbage_to_eject'
  => `53` 'ConfigManager.get_garbage_to_eject'
     `54` 'get_garbage_to_keep'
     `55` 'ConfigManager.get_garbage_to_keep'
     `56` 'load_telegram_settings'
     `57` 'ConfigManager.load_telegram_settings'
     `58` 'save_telegram_settings'
     `59` 'ConfigManager.save_telegram_settings'
     `60` 'config_manager.py'
     `61` '<module config_manager>'
     `62` ['self', 'config_dir']
     `63` ['self', 'settings', 'fish_settings']
     `64` ['self', 'settings', 'garbage_settings']
     `65` ['self', 'default_settings', 'f', 'settings', 'merged', 'e']
     `66` ['self', 'settings', 'clean_settings', 'f', 'e']
     `67` ['self', 'settings', 'f', 'e']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\config_manager\23c001f30_ConfigManager.get_garbage_to_eject.c`
