# Function Specification: `ui.telegram_tab`

This is a reconstruction dossier from static Nuitka constants and Ghidra decompilation. It is not original Python source text.

## Source Path Hints
- `ui\telegram_tab.py`

## Docstrings / Long Text
- `115` '\nВкладка "Телеграм бот" для KortexWorker\nУправление Telegram ботом через UI\n'

## Function Inventory
| Inferred qualname | Impl | Source line | Arg count | Decompiled C |
|---|---:|---:|---:|---|
| `TelegramTab.__init__` | `FUN_23e317480` | 34 | 1 | yes |
| `TelegramTab.init_ui` | `FUN_23e31de70` | 191 | 1 | yes |
| `TelegramTab.load_settings` | `FUN_23e31e5e0` | 197 | 1 | yes |
| `TelegramTab.save_settings` | `FUN_23e31ece0` | 206 | 1 | yes |
| `TelegramTab.auto_start_enabled` | `FUN_23e31f490` | 213 | 1 | yes |
| `TelegramTab.toggle_bot` | `FUN_23e31fa60` | 220 | 1 | yes |
| `TelegramTab.start_bot` | `FUN_23e322240` | 264 | 1 | yes |
| `TelegramTab.stop_bot` | `FUN_23e322ae0` | 275 | 2 | yes |
| `TelegramTab.log` | `FUN_23e322f50` | 279 | 2 | yes |
| `TelegramTab.closeEvent` | `LAB_23e316a60` | ? | ? | yes |

## Local Variable Lists
- `164` `__class__`
- `165` `self, fishing_tab, __class__`
- `166` `self, settings`
- `167` `self, event`
- `168` `self, main_layout, scroll, scroll_widget, scroll_layout, title, title_font, instruction_frame, instruction_layout, instr_title, instr_title_font, instruction_text, settings_frame, settings_layout, token_label, token_label_font, ids_label, ids_label_font, ids_hint`
- `169` `self, message`
- `170` `self, token, admin_ids_str, admin_ids, fishing_bot`
- `171` `self`

## Structured Constants
- `10` [5, 30, 5, 30]
- `12` [8]
- `15` [True]
- `21` [0, 0, 0, 0]
- `28` [16]
- `33` [10]
- `35` [16, 16, 16, 16]
- `37` [13]
- `41` [150]
- `46` [15]
- `47` [12]
- `54` [40]
- `65` [50]
- `145` [None]

## Per-Function Context
### `TelegramTab.__init__`

- implementation: `FUN_23e317480`
- source line hint: `34`
- Nuitka codevar: `_DAT_23eeb4cd0`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `138` 'TelegramTab'
     `139` '__getitem__'
     `140` '%s.__prepare__() must return a mapping, not %s'
     `141` '<metaclass>'
     `142` 'ui.telegram_tab'
     `143` 'Вкладка управления Telegram ботом'
     `144` '__qualname__'
     `145` [None]
  => `146` 'TelegramTab.__init__'
     `147` 'TelegramTab.init_ui'
     `148` 'TelegramTab.load_settings'
     `149` 'TelegramTab.save_settings'
     `150` 'return'
     `151` 'bool'
     `152` 'TelegramTab.auto_start_enabled'
     `153` 'TelegramTab.toggle_bot'
     `154` 'TelegramTab.start_bot'
     `155` 'TelegramTab.stop_bot'
     `156` 'message'
     `157` 'str'
     `158` 'TelegramTab.log'
     `159` 'closeEvent'
     `160` 'TelegramTab.closeEvent'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__telegram_tab\23e317480_TelegramTab.__init.c`

### `TelegramTab.init_ui`

- implementation: `FUN_23e31de70`
- source line hint: `191`
- Nuitka codevar: `_DAT_23eeb4ca8`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `139` '__getitem__'
     `140` '%s.__prepare__() must return a mapping, not %s'
     `141` '<metaclass>'
     `142` 'ui.telegram_tab'
     `143` 'Вкладка управления Telegram ботом'
     `144` '__qualname__'
     `145` [None]
     `146` 'TelegramTab.__init__'
  => `147` 'TelegramTab.init_ui'
     `148` 'TelegramTab.load_settings'
     `149` 'TelegramTab.save_settings'
     `150` 'return'
     `151` 'bool'
     `152` 'TelegramTab.auto_start_enabled'
     `153` 'TelegramTab.toggle_bot'
     `154` 'TelegramTab.start_bot'
     `155` 'TelegramTab.stop_bot'
     `156` 'message'
     `157` 'str'
     `158` 'TelegramTab.log'
     `159` 'closeEvent'
     `160` 'TelegramTab.closeEvent'
     `161` '__orig_bases__'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__telegram_tab\23e31de70_TelegramTab.init_ui.c`

### `TelegramTab.load_settings`

- implementation: `FUN_23e31e5e0`
- source line hint: `197`
- Nuitka codevar: `_DAT_23eeb4c98`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `140` '%s.__prepare__() must return a mapping, not %s'
     `141` '<metaclass>'
     `142` 'ui.telegram_tab'
     `143` 'Вкладка управления Telegram ботом'
     `144` '__qualname__'
     `145` [None]
     `146` 'TelegramTab.__init__'
     `147` 'TelegramTab.init_ui'
  => `148` 'TelegramTab.load_settings'
     `149` 'TelegramTab.save_settings'
     `150` 'return'
     `151` 'bool'
     `152` 'TelegramTab.auto_start_enabled'
     `153` 'TelegramTab.toggle_bot'
     `154` 'TelegramTab.start_bot'
     `155` 'TelegramTab.stop_bot'
     `156` 'message'
     `157` 'str'
     `158` 'TelegramTab.log'
     `159` 'closeEvent'
     `160` 'TelegramTab.closeEvent'
     `161` '__orig_bases__'
     `162` 'ui\\telegram_tab.py'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__telegram_tab\23e31e5e0_TelegramTab.load_settings.c`

### `TelegramTab.save_settings`

- implementation: `FUN_23e31ece0`
- source line hint: `206`
- Nuitka codevar: `_DAT_23eeb4c88`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `141` '<metaclass>'
     `142` 'ui.telegram_tab'
     `143` 'Вкладка управления Telegram ботом'
     `144` '__qualname__'
     `145` [None]
     `146` 'TelegramTab.__init__'
     `147` 'TelegramTab.init_ui'
     `148` 'TelegramTab.load_settings'
  => `149` 'TelegramTab.save_settings'
     `150` 'return'
     `151` 'bool'
     `152` 'TelegramTab.auto_start_enabled'
     `153` 'TelegramTab.toggle_bot'
     `154` 'TelegramTab.start_bot'
     `155` 'TelegramTab.stop_bot'
     `156` 'message'
     `157` 'str'
     `158` 'TelegramTab.log'
     `159` 'closeEvent'
     `160` 'TelegramTab.closeEvent'
     `161` '__orig_bases__'
     `162` 'ui\\telegram_tab.py'
     `163` '<module ui.telegram_tab>'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__telegram_tab\23e31ece0_TelegramTab.save_settings.c`

### `TelegramTab.auto_start_enabled`

- implementation: `FUN_23e31f490`
- source line hint: `213`
- Nuitka codevar: `_DAT_23eeb4c78`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `144` '__qualname__'
     `145` [None]
     `146` 'TelegramTab.__init__'
     `147` 'TelegramTab.init_ui'
     `148` 'TelegramTab.load_settings'
     `149` 'TelegramTab.save_settings'
     `150` 'return'
     `151` 'bool'
  => `152` 'TelegramTab.auto_start_enabled'
     `153` 'TelegramTab.toggle_bot'
     `154` 'TelegramTab.start_bot'
     `155` 'TelegramTab.stop_bot'
     `156` 'message'
     `157` 'str'
     `158` 'TelegramTab.log'
     `159` 'closeEvent'
     `160` 'TelegramTab.closeEvent'
     `161` '__orig_bases__'
     `162` 'ui\\telegram_tab.py'
     `163` '<module ui.telegram_tab>'
     `164` ['__class__']
     `165` ['self', 'fishing_tab', '__class__']
     `166` ['self', 'settings']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__telegram_tab\23e31f490_TelegramTab.auto_start_enabled.c`

### `TelegramTab.toggle_bot`

- implementation: `FUN_23e31fa60`
- source line hint: `220`
- Nuitka codevar: `_DAT_23eeb4c68`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `145` [None]
     `146` 'TelegramTab.__init__'
     `147` 'TelegramTab.init_ui'
     `148` 'TelegramTab.load_settings'
     `149` 'TelegramTab.save_settings'
     `150` 'return'
     `151` 'bool'
     `152` 'TelegramTab.auto_start_enabled'
  => `153` 'TelegramTab.toggle_bot'
     `154` 'TelegramTab.start_bot'
     `155` 'TelegramTab.stop_bot'
     `156` 'message'
     `157` 'str'
     `158` 'TelegramTab.log'
     `159` 'closeEvent'
     `160` 'TelegramTab.closeEvent'
     `161` '__orig_bases__'
     `162` 'ui\\telegram_tab.py'
     `163` '<module ui.telegram_tab>'
     `164` ['__class__']
     `165` ['self', 'fishing_tab', '__class__']
     `166` ['self', 'settings']
     `167` ['self', 'event']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__telegram_tab\23e31fa60_TelegramTab.toggle_bot.c`

### `TelegramTab.start_bot`

- implementation: `FUN_23e322240`
- source line hint: `264`
- Nuitka codevar: `_DAT_23eeb4c48`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `146` 'TelegramTab.__init__'
     `147` 'TelegramTab.init_ui'
     `148` 'TelegramTab.load_settings'
     `149` 'TelegramTab.save_settings'
     `150` 'return'
     `151` 'bool'
     `152` 'TelegramTab.auto_start_enabled'
     `153` 'TelegramTab.toggle_bot'
  => `154` 'TelegramTab.start_bot'
     `155` 'TelegramTab.stop_bot'
     `156` 'message'
     `157` 'str'
     `158` 'TelegramTab.log'
     `159` 'closeEvent'
     `160` 'TelegramTab.closeEvent'
     `161` '__orig_bases__'
     `162` 'ui\\telegram_tab.py'
     `163` '<module ui.telegram_tab>'
     `164` ['__class__']
     `165` ['self', 'fishing_tab', '__class__']
     `166` ['self', 'settings']
     `167` ['self', 'event']
     `168` ['self', 'main_layout', 'scroll', 'scroll_widget', 'scroll_layout', 'title', 'title_font', 'instruction_frame', 'instruction_layout', 'instr_title', 'instr_title_font', 'instruction_text', 'settings_frame', 'settings_layout', 'token_label', 'token_label_font', 'ids_label', 'id...
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__telegram_tab\23e322240_TelegramTab.start_bot.c`

### `TelegramTab.stop_bot`

- implementation: `FUN_23e322ae0`
- source line hint: `275`
- Nuitka codevar: `_DAT_23eeb4c38`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `147` 'TelegramTab.init_ui'
     `148` 'TelegramTab.load_settings'
     `149` 'TelegramTab.save_settings'
     `150` 'return'
     `151` 'bool'
     `152` 'TelegramTab.auto_start_enabled'
     `153` 'TelegramTab.toggle_bot'
     `154` 'TelegramTab.start_bot'
  => `155` 'TelegramTab.stop_bot'
     `156` 'message'
     `157` 'str'
     `158` 'TelegramTab.log'
     `159` 'closeEvent'
     `160` 'TelegramTab.closeEvent'
     `161` '__orig_bases__'
     `162` 'ui\\telegram_tab.py'
     `163` '<module ui.telegram_tab>'
     `164` ['__class__']
     `165` ['self', 'fishing_tab', '__class__']
     `166` ['self', 'settings']
     `167` ['self', 'event']
     `168` ['self', 'main_layout', 'scroll', 'scroll_widget', 'scroll_layout', 'title', 'title_font', 'instruction_frame', 'instruction_layout', 'instr_title', 'instr_title_font', 'instruction_text', 'settings_frame', 'settings_layout', 'token_label', 'token_label_font', 'ids_label', 'id...
     `169` ['self', 'message']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__telegram_tab\23e322ae0_TelegramTab.stop_bot.c`

### `TelegramTab.log`

- implementation: `FUN_23e322f50`
- source line hint: `279`
- Nuitka codevar: `_DAT_23eeb4c28`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `150` 'return'
     `151` 'bool'
     `152` 'TelegramTab.auto_start_enabled'
     `153` 'TelegramTab.toggle_bot'
     `154` 'TelegramTab.start_bot'
     `155` 'TelegramTab.stop_bot'
     `156` 'message'
     `157` 'str'
  => `158` 'TelegramTab.log'
     `159` 'closeEvent'
     `160` 'TelegramTab.closeEvent'
     `161` '__orig_bases__'
     `162` 'ui\\telegram_tab.py'
     `163` '<module ui.telegram_tab>'
     `164` ['__class__']
     `165` ['self', 'fishing_tab', '__class__']
     `166` ['self', 'settings']
     `167` ['self', 'event']
     `168` ['self', 'main_layout', 'scroll', 'scroll_widget', 'scroll_layout', 'title', 'title_font', 'instruction_frame', 'instruction_layout', 'instr_title', 'instr_title_font', 'instruction_text', 'settings_frame', 'settings_layout', 'token_label', 'token_label_font', 'ids_label', 'id...
     `169` ['self', 'message']
     `170` ['self', 'token', 'admin_ids_str', 'admin_ids', 'fishing_bot']
     `171` ['self']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__telegram_tab\23e322f50_TelegramTab.log.c`

### `TelegramTab.closeEvent`

- implementation: `LAB_23e316a60`
- source line hint: `?`
- Nuitka codevar: `uVar8`
- factory: `FUN_23e93e480`
- nearby constants:
     `152` 'TelegramTab.auto_start_enabled'
     `153` 'TelegramTab.toggle_bot'
     `154` 'TelegramTab.start_bot'
     `155` 'TelegramTab.stop_bot'
     `156` 'message'
     `157` 'str'
     `158` 'TelegramTab.log'
     `159` 'closeEvent'
  => `160` 'TelegramTab.closeEvent'
     `161` '__orig_bases__'
     `162` 'ui\\telegram_tab.py'
     `163` '<module ui.telegram_tab>'
     `164` ['__class__']
     `165` ['self', 'fishing_tab', '__class__']
     `166` ['self', 'settings']
     `167` ['self', 'event']
     `168` ['self', 'main_layout', 'scroll', 'scroll_widget', 'scroll_layout', 'title', 'title_font', 'instruction_frame', 'instruction_layout', 'instr_title', 'instr_title_font', 'instruction_text', 'settings_frame', 'settings_layout', 'token_label', 'token_label_font', 'ids_label', 'id...
     `169` ['self', 'message']
     `170` ['self', 'token', 'admin_ids_str', 'admin_ids', 'fishing_bot']
     `171` ['self']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__telegram_tab\23e316a60_TelegramTab.closeEvent.c`
