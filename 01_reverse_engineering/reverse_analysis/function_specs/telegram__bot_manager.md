# Function Specification: `telegram.bot_manager`

This is a reconstruction dossier from static Nuitka constants and Ghidra decompilation. It is not original Python source text.

## Source Path Hints
- `telegram\bot_manager.py`

## Docstrings / Long Text
- `64` '\nМенеджер Telegram ботов\nЦентральный класс для запуска и управления ботом\n'
- `93` '\n    Менеджер Telegram бота\n    Управляет запуском и остановкой бота\n    '

## Function Inventory
| Inferred qualname | Impl | Source line | Arg count | Decompiled C |
|---|---:|---:|---:|---|
| `TelegramBotManager._run_bot` | `FUN_23e10d9e0` | 43 | 2 | yes |
| `handlers.menu_handler` | `FUN_23e10e0d0` | 49 | 1 | yes |
| `handlers.fishing_handler` | `FUN_23e10f2e0` | 66 | 1 | yes |
| `handlers.screenshot_handler` | `FUN_23e10fd40` | 83 | 1 | yes |
| `handlers.system_handler` | `FUN_23e1117f0` | 99 | 1 | yes |
| `handlers.notifications_handler` | `FUN_23e10d3c0` | ? | ? | yes |

## Local Variable Lists
- `105` `__class__`
- `106` `self, token, admin_ids, log_callback`
- `107` `self, message`
- `109` `self, notification_manager, _network_error_handler, e`
- `110` `self, e`
- `111` `self`

## Structured Constants
- `26` [2.0]
- `55` {'__dict_items__': [['exception', {'__builtin_exception__': 'Exception'}]]}
- `96` [None]
- `98` {'__dict_items__': [['message', {'__builtin__': 'str'}]]}

## Per-Function Context
### `TelegramBotManager._run_bot`

- implementation: `FUN_23e10d9e0`
- source line hint: `43`
- Nuitka codevar: `_DAT_23eeab458`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `53` 'register_notifications_handlers'
     `54` 'errors'
     `55` {'__dict_items__': [['exception', {'__builtin_exception__': 'Exception'}]]}
     `56` '_network_error_handler'
     `57` 'TelegramBotManager._run_bot.<locals>._network_error_handler'
     `58` ['🔄 Запуск polling...']
     `59` 'start_polling'
     `60` '❌ Ошибка бота: '
  => `61` 'TelegramBotManager._run_bot'
     `62` 'exception'
     `63` 'TelegramNetworkError'
     `64` '\nМенеджер Telegram ботов\nЦентральный класс для запуска и управления ботом\n'
     `65` 'origin'
     `66` 'has_location'
     `67` 'logging'
     `68` 'Optional'
     `69` 'Callable'
     `70` 'aiogram'
     `71` ['Bot', 'Dispatcher']
     `72` 'aiogram.client.default'
     `73` ['DefaultBotProperties']
     `74` 'aiogram.enums'
     `75` ['ParseMode']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\telegram__bot_manager\23e10d9e0_TelegramBotManager._run_bot.c`

### `handlers.menu_handler`

- implementation: `FUN_23e10e0d0`
- source line hint: `49`
- Nuitka codevar: `_DAT_23eeab440`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `70` 'aiogram'
     `71` ['Bot', 'Dispatcher']
     `72` 'aiogram.client.default'
     `73` ['DefaultBotProperties']
     `74` 'aiogram.enums'
     `75` ['ParseMode']
     `76` 'aiogram.exceptions'
     `77` ['TelegramNetworkError']
  => `78` 'handlers.menu_handler'
     `79` ['register_menu_handlers']
     `80` 'handlers.fishing_handler'
     `81` ['register_fishing_handlers']
     `82` 'handlers.screenshot_handler'
     `83` ['register_screenshot_handlers']
     `84` 'handlers.system_handler'
     `85` ['register_system_handlers']
     `86` 'handlers.notifications_handler'
     `87` ['register_notifications_handlers']
     `88` 'notification_manager'
     `89` ['get_notification_manager']
     `90` 'getLogger'
     `91` ['TelegramBot']
     `92` 'telegram.bot_manager'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\telegram__bot_manager\23e10e0d0_handlers.menu_handler.c`

### `handlers.fishing_handler`

- implementation: `FUN_23e10f2e0`
- source line hint: `66`
- Nuitka codevar: `_DAT_23eeab428`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `72` 'aiogram.client.default'
     `73` ['DefaultBotProperties']
     `74` 'aiogram.enums'
     `75` ['ParseMode']
     `76` 'aiogram.exceptions'
     `77` ['TelegramNetworkError']
     `78` 'handlers.menu_handler'
     `79` ['register_menu_handlers']
  => `80` 'handlers.fishing_handler'
     `81` ['register_fishing_handlers']
     `82` 'handlers.screenshot_handler'
     `83` ['register_screenshot_handlers']
     `84` 'handlers.system_handler'
     `85` ['register_system_handlers']
     `86` 'handlers.notifications_handler'
     `87` ['register_notifications_handlers']
     `88` 'notification_manager'
     `89` ['get_notification_manager']
     `90` 'getLogger'
     `91` ['TelegramBot']
     `92` 'telegram.bot_manager'
     `93` '\n    Менеджер Telegram бота\n    Управляет запуском и остановкой бота\n    '
     `94` 'TelegramBotManager'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\telegram__bot_manager\23e10f2e0_handlers.fishing_handler.c`

### `handlers.screenshot_handler`

- implementation: `FUN_23e10fd40`
- source line hint: `83`
- Nuitka codevar: `_DAT_23eeab418`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `74` 'aiogram.enums'
     `75` ['ParseMode']
     `76` 'aiogram.exceptions'
     `77` ['TelegramNetworkError']
     `78` 'handlers.menu_handler'
     `79` ['register_menu_handlers']
     `80` 'handlers.fishing_handler'
     `81` ['register_fishing_handlers']
  => `82` 'handlers.screenshot_handler'
     `83` ['register_screenshot_handlers']
     `84` 'handlers.system_handler'
     `85` ['register_system_handlers']
     `86` 'handlers.notifications_handler'
     `87` ['register_notifications_handlers']
     `88` 'notification_manager'
     `89` ['get_notification_manager']
     `90` 'getLogger'
     `91` ['TelegramBot']
     `92` 'telegram.bot_manager'
     `93` '\n    Менеджер Telegram бота\n    Управляет запуском и остановкой бота\n    '
     `94` 'TelegramBotManager'
     `95` '__qualname__'
     `96` [None]
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\telegram__bot_manager\23e10fd40_handlers.screenshot_handler.c`

### `handlers.system_handler`

- implementation: `FUN_23e1117f0`
- source line hint: `99`
- Nuitka codevar: `DAT_23eeab410`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `76` 'aiogram.exceptions'
     `77` ['TelegramNetworkError']
     `78` 'handlers.menu_handler'
     `79` ['register_menu_handlers']
     `80` 'handlers.fishing_handler'
     `81` ['register_fishing_handlers']
     `82` 'handlers.screenshot_handler'
     `83` ['register_screenshot_handlers']
  => `84` 'handlers.system_handler'
     `85` ['register_system_handlers']
     `86` 'handlers.notifications_handler'
     `87` ['register_notifications_handlers']
     `88` 'notification_manager'
     `89` ['get_notification_manager']
     `90` 'getLogger'
     `91` ['TelegramBot']
     `92` 'telegram.bot_manager'
     `93` '\n    Менеджер Telegram бота\n    Управляет запуском и остановкой бота\n    '
     `94` 'TelegramBotManager'
     `95` '__qualname__'
     `96` [None]
     `97` 'TelegramBotManager.__init__'
     `98` {'__dict_items__': [['message', {'__builtin__': 'str'}]]}
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\telegram__bot_manager\23e1117f0_handlers.system_handler.c`

### `handlers.notifications_handler`

- implementation: `FUN_23e10d3c0`
- source line hint: `?`
- Nuitka codevar: `uVar5`
- factory: `FUN_23e93e480`
- nearby constants:
     `78` 'handlers.menu_handler'
     `79` ['register_menu_handlers']
     `80` 'handlers.fishing_handler'
     `81` ['register_fishing_handlers']
     `82` 'handlers.screenshot_handler'
     `83` ['register_screenshot_handlers']
     `84` 'handlers.system_handler'
     `85` ['register_system_handlers']
  => `86` 'handlers.notifications_handler'
     `87` ['register_notifications_handlers']
     `88` 'notification_manager'
     `89` ['get_notification_manager']
     `90` 'getLogger'
     `91` ['TelegramBot']
     `92` 'telegram.bot_manager'
     `93` '\n    Менеджер Telegram бота\n    Управляет запуском и остановкой бота\n    '
     `94` 'TelegramBotManager'
     `95` '__qualname__'
     `96` [None]
     `97` 'TelegramBotManager.__init__'
     `98` {'__dict_items__': [['message', {'__builtin__': 'str'}]]}
     `99` 'TelegramBotManager._log'
     `100` 'TelegramBotManager.start'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\telegram__bot_manager\23e10d3c0_handlers.notifications_handler.c`
