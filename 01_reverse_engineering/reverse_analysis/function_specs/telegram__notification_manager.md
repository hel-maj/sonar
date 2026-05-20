# Function Specification: `telegram.notification_manager`

This is a reconstruction dossier from static Nuitka constants and Ghidra decompilation. It is not original Python source text.

## Source Path Hints
- `telegram\notification_manager.py`

## Docstrings / Long Text
- `37` '🐟 <b>Поймал рыбу!</b>\n\n📦 <i>'
- `42` '\n        Уведомление о пойманной рыбе\n        :param fish_name: Название рыбы (английское имя файла)\n        :param screenshot_bytes: Байты скриншота области распознавания\n        '
- `54` '🛑 <b>Место в инвентаре закончилось</b>\n\nЯ останавливаюсь\n\n📊 <b>Статистика:</b>\n🐟 Поймано рыб: <b>'
- `55` '</b>\n\n💻 <b>Выключаю твой ПК, как ты и просил!</b>\nВыключение через 10 секунд...'
- `57` '\n        Уведомление: инвентарь заполнен, бот остановлен\n        :param fish_count: Количество пойманной рыбы\n        :param shutdown_pending: Если True — добавить предупреждение о выключении ПК\n        '
- `60` '✅ <b>Меня кто-то сбил</b>\n\nНо я сам справился и восстановил рыбалку'
- `62` '\n        Уведомление: рыбалка восстановлена после сбоя\n        :param screenshot_bytes: Скриншот игры\n        '
- `64` '❌ <b>Меня сбили</b>\n\nВосстановить не получилось, я остановился'
- `66` '\n        Уведомление: не удалось восстановить рыбалку\n        :param screenshot_bytes: Скриншот игры\n        '
- `75` '\nМенеджер уведомлений для Telegram бота\nОтправка уведомлений о событиях рыбалки\n'

## Function Inventory
| Inferred qualname | Impl | Source line | Arg count | Decompiled C |
|---|---:|---:|---:|---|
| `NotificationManager._send_message_async` | `LAB_23e12c310` | 17 | uVar9 | yes |
| `NotificationManager.__init__` | `FUN_23e12ca30` | 23 | 3 | yes |
| `NotificationManager.initialize` | `FUN_23e12da40` | 34 | uVar9 | yes |
| `NotificationManager._is_enabled` | `FUN_23e12e100` | 40 | uVar21 | yes |
| `NotificationManager._send_sync` | `FUN_23e130800` | 79 | uVar9 | yes |
| `NotificationManager.notify_caught_fish` | `FUN_23e130a70` | 94 | 3 | yes |
| `NotificationManager.notify_meal_eaten` | `FUN_23e1318c0` | 114 | 1 | yes |
| `NotificationManager.notify_meal_ended` | `FUN_23e131e80` | 122 | 1 | yes |
| `NotificationManager.notify_backpack_stored` | `FUN_23e132440` | 130 | 1 | yes |
| `NotificationManager.notify_backpack_full` | `FUN_23e132a00` | 138 | 1 | yes |
| `NotificationManager.notify_inventory_full` | `FUN_23e132fc0` | 146 | 3 | yes |
| `NotificationManager.notify_fishing_restored` | `FUN_23e133a90` | 166 | 2 | yes |
| `NotificationManager.notify_fishing_failed` | `FUN_23e1343f0` | 182 | 2 | yes |
| `NotificationManager.notify_tackle_ended` | `FUN_23e134d50` | 198 | 1 | yes |
| `NotificationManager.notify_bait_changed` | `FUN_23e135310` | 206 | 1 | yes |
| `?` | `FUN_23e1358d0` | ? | ? | yes |

## Local Variable Lists
- `132` `__class__`
- `133` `self`
- `134` `self, notification_type, settings, notifications`
- `135` `self, text, photo, admin_id, e`
- `136` `self, coro, running_loop, e`
- `137` `self, bot, admin_ids`
- `138` `self, text`
- `139` `self, fish_name, screenshot_bytes, fish_name_ru, text, photo`
- `140` `self, screenshot_bytes, text, photo`
- `141` `self, fish_count, shutdown_pending, text`

## Structured Constants
- `40` {'__dict_items__': [['filename', 'fish.png']]}
- `59` {'__dict_items__': [['filename', 'restored.png']]}
- `63` {'__dict_items__': [['filename', 'failed.png']]}
- `99` {'__dict_items__': [['notification_type', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
- `102` [None]
- `103` {'__dict_items__': [['text', {'__builtin__': 'str'}]]}
- `104` {'__dict_items__': [['fish_name', {'__builtin__': 'str'}], ['screenshot_bytes', {'__builtin__': 'bytes'}]]}
- `115` [0, False]
- `116` {'__dict_items__': [['fish_count', {'__builtin__': 'int'}], ['shutdown_pending', {'__builtin__': 'bool'}]]}
- `119` {'__dict_items__': [['screenshot_bytes', {'__builtin__': 'bytes'}]]}

## Per-Function Context
### `NotificationManager._send_message_async`

- implementation: `LAB_23e12c310`
- source line hint: `17`
- Nuitka codevar: `DAT_23eeaae00`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `25` 'send_photo'
     `26` 'text'
     `27` ['chat_id', 'photo', 'caption']
     `28` 'send_message'
     `29` ['chat_id', 'text']
     `30` '[TG] Ошибка отправки админу '
     `31` ': '
     `32` '_send_message_async'
  => `33` 'NotificationManager._send_message_async'
     `34` '_is_enabled'
     `35` ['caught_fish']
     `36` 'get_fish_name'
     `37` '🐟 <b>Поймал рыбу!</b>\n\n📦 <i>'
     `38` '</i>'
     `39` 'BufferedInputFile'
     `40` {'__dict_items__': [['filename', 'fish.png']]}
     `41` '_send_sync'
     `42` '\n        Уведомление о пойманной рыбе\n        :param fish_name: Название рыбы (английское имя файла)\n        :param screenshot_bytes: Байты скриншота области распознавания\n        '
     `43` ['meal']
     `44` ['🍔 Я покушал']
     `45` 'Уведомление: покушал'
     `46` ['⚠️ <b>Еда закончилась!</b>']
     `47` 'Уведомление: еда закончилась'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\telegram__notification_manager\23e12c310_NotificationManager._send_message_async.c`

### `NotificationManager.__init__`

- implementation: `FUN_23e12ca30`
- source line hint: `23`
- Nuitka codevar: `DAT_23eeaade8`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `88` ['ConfigManager']
     `89` 'telegram.handlers.fish_names_map'
     `90` ['get_fish_name']
     `91` 'io'
     `92` 'telegram.notification_manager'
     `93` 'Управление отправкой уведомлений в Telegram'
     `94` 'NotificationManager'
     `95` '__qualname__'
  => `96` 'NotificationManager.__init__'
     `97` 'initialize'
     `98` 'NotificationManager.initialize'
     `99` {'__dict_items__': [['notification_type', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
     `100` 'NotificationManager._is_enabled'
     `101` 'NotificationManager._send_sync'
     `102` [None]
     `103` {'__dict_items__': [['text', {'__builtin__': 'str'}]]}
     `104` {'__dict_items__': [['fish_name', {'__builtin__': 'str'}], ['screenshot_bytes', {'__builtin__': 'bytes'}]]}
     `105` 'notify_caught_fish'
     `106` 'NotificationManager.notify_caught_fish'
     `107` 'notify_meal_eaten'
     `108` 'NotificationManager.notify_meal_eaten'
     `109` 'notify_meal_ended'
     `110` 'NotificationManager.notify_meal_ended'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\telegram__notification_manager\23e12ca30_NotificationManager.__init.c`

### `NotificationManager.initialize`

- implementation: `FUN_23e12da40`
- source line hint: `34`
- Nuitka codevar: `DAT_23eeaadd8`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `90` ['get_fish_name']
     `91` 'io'
     `92` 'telegram.notification_manager'
     `93` 'Управление отправкой уведомлений в Telegram'
     `94` 'NotificationManager'
     `95` '__qualname__'
     `96` 'NotificationManager.__init__'
     `97` 'initialize'
  => `98` 'NotificationManager.initialize'
     `99` {'__dict_items__': [['notification_type', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
     `100` 'NotificationManager._is_enabled'
     `101` 'NotificationManager._send_sync'
     `102` [None]
     `103` {'__dict_items__': [['text', {'__builtin__': 'str'}]]}
     `104` {'__dict_items__': [['fish_name', {'__builtin__': 'str'}], ['screenshot_bytes', {'__builtin__': 'bytes'}]]}
     `105` 'notify_caught_fish'
     `106` 'NotificationManager.notify_caught_fish'
     `107` 'notify_meal_eaten'
     `108` 'NotificationManager.notify_meal_eaten'
     `109` 'notify_meal_ended'
     `110` 'NotificationManager.notify_meal_ended'
     `111` 'notify_backpack_stored'
     `112` 'NotificationManager.notify_backpack_stored'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\telegram__notification_manager\23e12da40_NotificationManager.initialize.c`

### `NotificationManager._is_enabled`

- implementation: `FUN_23e12e100`
- source line hint: `40`
- Nuitka codevar: `DAT_23eeaadc8`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `92` 'telegram.notification_manager'
     `93` 'Управление отправкой уведомлений в Telegram'
     `94` 'NotificationManager'
     `95` '__qualname__'
     `96` 'NotificationManager.__init__'
     `97` 'initialize'
     `98` 'NotificationManager.initialize'
     `99` {'__dict_items__': [['notification_type', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
  => `100` 'NotificationManager._is_enabled'
     `101` 'NotificationManager._send_sync'
     `102` [None]
     `103` {'__dict_items__': [['text', {'__builtin__': 'str'}]]}
     `104` {'__dict_items__': [['fish_name', {'__builtin__': 'str'}], ['screenshot_bytes', {'__builtin__': 'bytes'}]]}
     `105` 'notify_caught_fish'
     `106` 'NotificationManager.notify_caught_fish'
     `107` 'notify_meal_eaten'
     `108` 'NotificationManager.notify_meal_eaten'
     `109` 'notify_meal_ended'
     `110` 'NotificationManager.notify_meal_ended'
     `111` 'notify_backpack_stored'
     `112` 'NotificationManager.notify_backpack_stored'
     `113` 'notify_backpack_full'
     `114` 'NotificationManager.notify_backpack_full'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\telegram__notification_manager\23e12e100_NotificationManager._is_enabled.c`

### `NotificationManager._send_sync`

- implementation: `FUN_23e130800`
- source line hint: `79`
- Nuitka codevar: `DAT_23eeaadc0`
- factory: `FUN_23e93e480`
- nearby constants:
     `93` 'Управление отправкой уведомлений в Telegram'
     `94` 'NotificationManager'
     `95` '__qualname__'
     `96` 'NotificationManager.__init__'
     `97` 'initialize'
     `98` 'NotificationManager.initialize'
     `99` {'__dict_items__': [['notification_type', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
     `100` 'NotificationManager._is_enabled'
  => `101` 'NotificationManager._send_sync'
     `102` [None]
     `103` {'__dict_items__': [['text', {'__builtin__': 'str'}]]}
     `104` {'__dict_items__': [['fish_name', {'__builtin__': 'str'}], ['screenshot_bytes', {'__builtin__': 'bytes'}]]}
     `105` 'notify_caught_fish'
     `106` 'NotificationManager.notify_caught_fish'
     `107` 'notify_meal_eaten'
     `108` 'NotificationManager.notify_meal_eaten'
     `109` 'notify_meal_ended'
     `110` 'NotificationManager.notify_meal_ended'
     `111` 'notify_backpack_stored'
     `112` 'NotificationManager.notify_backpack_stored'
     `113` 'notify_backpack_full'
     `114` 'NotificationManager.notify_backpack_full'
     `115` [0, False]
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\telegram__notification_manager\23e130800_NotificationManager._send_sync.c`

### `NotificationManager.notify_caught_fish`

- implementation: `FUN_23e130a70`
- source line hint: `94`
- Nuitka codevar: `DAT_23eeaada8`
- factory: `FUN_23e93e480`
- nearby constants:
     `98` 'NotificationManager.initialize'
     `99` {'__dict_items__': [['notification_type', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
     `100` 'NotificationManager._is_enabled'
     `101` 'NotificationManager._send_sync'
     `102` [None]
     `103` {'__dict_items__': [['text', {'__builtin__': 'str'}]]}
     `104` {'__dict_items__': [['fish_name', {'__builtin__': 'str'}], ['screenshot_bytes', {'__builtin__': 'bytes'}]]}
     `105` 'notify_caught_fish'
  => `106` 'NotificationManager.notify_caught_fish'
     `107` 'notify_meal_eaten'
     `108` 'NotificationManager.notify_meal_eaten'
     `109` 'notify_meal_ended'
     `110` 'NotificationManager.notify_meal_ended'
     `111` 'notify_backpack_stored'
     `112` 'NotificationManager.notify_backpack_stored'
     `113` 'notify_backpack_full'
     `114` 'NotificationManager.notify_backpack_full'
     `115` [0, False]
     `116` {'__dict_items__': [['fish_count', {'__builtin__': 'int'}], ['shutdown_pending', {'__builtin__': 'bool'}]]}
     `117` 'notify_inventory_full'
     `118` 'NotificationManager.notify_inventory_full'
     `119` {'__dict_items__': [['screenshot_bytes', {'__builtin__': 'bytes'}]]}
     `120` 'notify_fishing_restored'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\telegram__notification_manager\23e130a70_NotificationManager.notify_caught_fish.c`

### `NotificationManager.notify_meal_eaten`

- implementation: `FUN_23e1318c0`
- source line hint: `114`
- Nuitka codevar: `DAT_23eeaad90`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `100` 'NotificationManager._is_enabled'
     `101` 'NotificationManager._send_sync'
     `102` [None]
     `103` {'__dict_items__': [['text', {'__builtin__': 'str'}]]}
     `104` {'__dict_items__': [['fish_name', {'__builtin__': 'str'}], ['screenshot_bytes', {'__builtin__': 'bytes'}]]}
     `105` 'notify_caught_fish'
     `106` 'NotificationManager.notify_caught_fish'
     `107` 'notify_meal_eaten'
  => `108` 'NotificationManager.notify_meal_eaten'
     `109` 'notify_meal_ended'
     `110` 'NotificationManager.notify_meal_ended'
     `111` 'notify_backpack_stored'
     `112` 'NotificationManager.notify_backpack_stored'
     `113` 'notify_backpack_full'
     `114` 'NotificationManager.notify_backpack_full'
     `115` [0, False]
     `116` {'__dict_items__': [['fish_count', {'__builtin__': 'int'}], ['shutdown_pending', {'__builtin__': 'bool'}]]}
     `117` 'notify_inventory_full'
     `118` 'NotificationManager.notify_inventory_full'
     `119` {'__dict_items__': [['screenshot_bytes', {'__builtin__': 'bytes'}]]}
     `120` 'notify_fishing_restored'
     `121` 'NotificationManager.notify_fishing_restored'
     `122` 'notify_fishing_failed'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\telegram__notification_manager\23e1318c0_NotificationManager.notify_meal_eaten.c`

### `NotificationManager.notify_meal_ended`

- implementation: `FUN_23e131e80`
- source line hint: `122`
- Nuitka codevar: `DAT_23eeaad80`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `102` [None]
     `103` {'__dict_items__': [['text', {'__builtin__': 'str'}]]}
     `104` {'__dict_items__': [['fish_name', {'__builtin__': 'str'}], ['screenshot_bytes', {'__builtin__': 'bytes'}]]}
     `105` 'notify_caught_fish'
     `106` 'NotificationManager.notify_caught_fish'
     `107` 'notify_meal_eaten'
     `108` 'NotificationManager.notify_meal_eaten'
     `109` 'notify_meal_ended'
  => `110` 'NotificationManager.notify_meal_ended'
     `111` 'notify_backpack_stored'
     `112` 'NotificationManager.notify_backpack_stored'
     `113` 'notify_backpack_full'
     `114` 'NotificationManager.notify_backpack_full'
     `115` [0, False]
     `116` {'__dict_items__': [['fish_count', {'__builtin__': 'int'}], ['shutdown_pending', {'__builtin__': 'bool'}]]}
     `117` 'notify_inventory_full'
     `118` 'NotificationManager.notify_inventory_full'
     `119` {'__dict_items__': [['screenshot_bytes', {'__builtin__': 'bytes'}]]}
     `120` 'notify_fishing_restored'
     `121` 'NotificationManager.notify_fishing_restored'
     `122` 'notify_fishing_failed'
     `123` 'NotificationManager.notify_fishing_failed'
     `124` 'notify_tackle_ended'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\telegram__notification_manager\23e131e80_NotificationManager.notify_meal_ended.c`

### `NotificationManager.notify_backpack_stored`

- implementation: `FUN_23e132440`
- source line hint: `130`
- Nuitka codevar: `DAT_23eeaad70`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `104` {'__dict_items__': [['fish_name', {'__builtin__': 'str'}], ['screenshot_bytes', {'__builtin__': 'bytes'}]]}
     `105` 'notify_caught_fish'
     `106` 'NotificationManager.notify_caught_fish'
     `107` 'notify_meal_eaten'
     `108` 'NotificationManager.notify_meal_eaten'
     `109` 'notify_meal_ended'
     `110` 'NotificationManager.notify_meal_ended'
     `111` 'notify_backpack_stored'
  => `112` 'NotificationManager.notify_backpack_stored'
     `113` 'notify_backpack_full'
     `114` 'NotificationManager.notify_backpack_full'
     `115` [0, False]
     `116` {'__dict_items__': [['fish_count', {'__builtin__': 'int'}], ['shutdown_pending', {'__builtin__': 'bool'}]]}
     `117` 'notify_inventory_full'
     `118` 'NotificationManager.notify_inventory_full'
     `119` {'__dict_items__': [['screenshot_bytes', {'__builtin__': 'bytes'}]]}
     `120` 'notify_fishing_restored'
     `121` 'NotificationManager.notify_fishing_restored'
     `122` 'notify_fishing_failed'
     `123` 'NotificationManager.notify_fishing_failed'
     `124` 'notify_tackle_ended'
     `125` 'NotificationManager.notify_tackle_ended'
     `126` 'notify_bait_changed'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\telegram__notification_manager\23e132440_NotificationManager.notify_backpack_stored.c`

### `NotificationManager.notify_backpack_full`

- implementation: `FUN_23e132a00`
- source line hint: `138`
- Nuitka codevar: `DAT_23eeaad60`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `106` 'NotificationManager.notify_caught_fish'
     `107` 'notify_meal_eaten'
     `108` 'NotificationManager.notify_meal_eaten'
     `109` 'notify_meal_ended'
     `110` 'NotificationManager.notify_meal_ended'
     `111` 'notify_backpack_stored'
     `112` 'NotificationManager.notify_backpack_stored'
     `113` 'notify_backpack_full'
  => `114` 'NotificationManager.notify_backpack_full'
     `115` [0, False]
     `116` {'__dict_items__': [['fish_count', {'__builtin__': 'int'}], ['shutdown_pending', {'__builtin__': 'bool'}]]}
     `117` 'notify_inventory_full'
     `118` 'NotificationManager.notify_inventory_full'
     `119` {'__dict_items__': [['screenshot_bytes', {'__builtin__': 'bytes'}]]}
     `120` 'notify_fishing_restored'
     `121` 'NotificationManager.notify_fishing_restored'
     `122` 'notify_fishing_failed'
     `123` 'NotificationManager.notify_fishing_failed'
     `124` 'notify_tackle_ended'
     `125` 'NotificationManager.notify_tackle_ended'
     `126` 'notify_bait_changed'
     `127` 'NotificationManager.notify_bait_changed'
     `128` 'return'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\telegram__notification_manager\23e132a00_NotificationManager.notify_backpack_full.c`

### `NotificationManager.notify_inventory_full`

- implementation: `FUN_23e132fc0`
- source line hint: `146`
- Nuitka codevar: `DAT_23eeaad50`
- factory: `FUN_23e93e480`
- nearby constants:
     `110` 'NotificationManager.notify_meal_ended'
     `111` 'notify_backpack_stored'
     `112` 'NotificationManager.notify_backpack_stored'
     `113` 'notify_backpack_full'
     `114` 'NotificationManager.notify_backpack_full'
     `115` [0, False]
     `116` {'__dict_items__': [['fish_count', {'__builtin__': 'int'}], ['shutdown_pending', {'__builtin__': 'bool'}]]}
     `117` 'notify_inventory_full'
  => `118` 'NotificationManager.notify_inventory_full'
     `119` {'__dict_items__': [['screenshot_bytes', {'__builtin__': 'bytes'}]]}
     `120` 'notify_fishing_restored'
     `121` 'NotificationManager.notify_fishing_restored'
     `122` 'notify_fishing_failed'
     `123` 'NotificationManager.notify_fishing_failed'
     `124` 'notify_tackle_ended'
     `125` 'NotificationManager.notify_tackle_ended'
     `126` 'notify_bait_changed'
     `127` 'NotificationManager.notify_bait_changed'
     `128` 'return'
     `129` 'get_notification_manager'
     `130` 'telegram\\notification_manager.py'
     `131` '<module telegram.notification_manager>'
     `132` ['__class__']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\telegram__notification_manager\23e132fc0_NotificationManager.notify_inventory_full.c`

### `NotificationManager.notify_fishing_restored`

- implementation: `FUN_23e133a90`
- source line hint: `166`
- Nuitka codevar: `DAT_23eeaad40`
- factory: `FUN_23e93e480`
- nearby constants:
     `113` 'notify_backpack_full'
     `114` 'NotificationManager.notify_backpack_full'
     `115` [0, False]
     `116` {'__dict_items__': [['fish_count', {'__builtin__': 'int'}], ['shutdown_pending', {'__builtin__': 'bool'}]]}
     `117` 'notify_inventory_full'
     `118` 'NotificationManager.notify_inventory_full'
     `119` {'__dict_items__': [['screenshot_bytes', {'__builtin__': 'bytes'}]]}
     `120` 'notify_fishing_restored'
  => `121` 'NotificationManager.notify_fishing_restored'
     `122` 'notify_fishing_failed'
     `123` 'NotificationManager.notify_fishing_failed'
     `124` 'notify_tackle_ended'
     `125` 'NotificationManager.notify_tackle_ended'
     `126` 'notify_bait_changed'
     `127` 'NotificationManager.notify_bait_changed'
     `128` 'return'
     `129` 'get_notification_manager'
     `130` 'telegram\\notification_manager.py'
     `131` '<module telegram.notification_manager>'
     `132` ['__class__']
     `133` ['self']
     `134` ['self', 'notification_type', 'settings', 'notifications']
     `135` ['self', 'text', 'photo', 'admin_id', 'e']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\telegram__notification_manager\23e133a90_NotificationManager.notify_fishing_restored.c`

### `NotificationManager.notify_fishing_failed`

- implementation: `FUN_23e1343f0`
- source line hint: `182`
- Nuitka codevar: `DAT_23eeaad30`
- factory: `FUN_23e93e480`
- nearby constants:
     `115` [0, False]
     `116` {'__dict_items__': [['fish_count', {'__builtin__': 'int'}], ['shutdown_pending', {'__builtin__': 'bool'}]]}
     `117` 'notify_inventory_full'
     `118` 'NotificationManager.notify_inventory_full'
     `119` {'__dict_items__': [['screenshot_bytes', {'__builtin__': 'bytes'}]]}
     `120` 'notify_fishing_restored'
     `121` 'NotificationManager.notify_fishing_restored'
     `122` 'notify_fishing_failed'
  => `123` 'NotificationManager.notify_fishing_failed'
     `124` 'notify_tackle_ended'
     `125` 'NotificationManager.notify_tackle_ended'
     `126` 'notify_bait_changed'
     `127` 'NotificationManager.notify_bait_changed'
     `128` 'return'
     `129` 'get_notification_manager'
     `130` 'telegram\\notification_manager.py'
     `131` '<module telegram.notification_manager>'
     `132` ['__class__']
     `133` ['self']
     `134` ['self', 'notification_type', 'settings', 'notifications']
     `135` ['self', 'text', 'photo', 'admin_id', 'e']
     `136` ['self', 'coro', 'running_loop', 'e']
     `137` ['self', 'bot', 'admin_ids']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\telegram__notification_manager\23e1343f0_NotificationManager.notify_fishing_failed.c`

### `NotificationManager.notify_tackle_ended`

- implementation: `FUN_23e134d50`
- source line hint: `198`
- Nuitka codevar: `DAT_23eeaad20`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `117` 'notify_inventory_full'
     `118` 'NotificationManager.notify_inventory_full'
     `119` {'__dict_items__': [['screenshot_bytes', {'__builtin__': 'bytes'}]]}
     `120` 'notify_fishing_restored'
     `121` 'NotificationManager.notify_fishing_restored'
     `122` 'notify_fishing_failed'
     `123` 'NotificationManager.notify_fishing_failed'
     `124` 'notify_tackle_ended'
  => `125` 'NotificationManager.notify_tackle_ended'
     `126` 'notify_bait_changed'
     `127` 'NotificationManager.notify_bait_changed'
     `128` 'return'
     `129` 'get_notification_manager'
     `130` 'telegram\\notification_manager.py'
     `131` '<module telegram.notification_manager>'
     `132` ['__class__']
     `133` ['self']
     `134` ['self', 'notification_type', 'settings', 'notifications']
     `135` ['self', 'text', 'photo', 'admin_id', 'e']
     `136` ['self', 'coro', 'running_loop', 'e']
     `137` ['self', 'bot', 'admin_ids']
     `138` ['self', 'text']
     `139` ['self', 'fish_name', 'screenshot_bytes', 'fish_name_ru', 'text', 'photo']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\telegram__notification_manager\23e134d50_NotificationManager.notify_tackle_ended.c`

### `NotificationManager.notify_bait_changed`

- implementation: `FUN_23e135310`
- source line hint: `206`
- Nuitka codevar: `DAT_23eeaad10`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `119` {'__dict_items__': [['screenshot_bytes', {'__builtin__': 'bytes'}]]}
     `120` 'notify_fishing_restored'
     `121` 'NotificationManager.notify_fishing_restored'
     `122` 'notify_fishing_failed'
     `123` 'NotificationManager.notify_fishing_failed'
     `124` 'notify_tackle_ended'
     `125` 'NotificationManager.notify_tackle_ended'
     `126` 'notify_bait_changed'
  => `127` 'NotificationManager.notify_bait_changed'
     `128` 'return'
     `129` 'get_notification_manager'
     `130` 'telegram\\notification_manager.py'
     `131` '<module telegram.notification_manager>'
     `132` ['__class__']
     `133` ['self']
     `134` ['self', 'notification_type', 'settings', 'notifications']
     `135` ['self', 'text', 'photo', 'admin_id', 'e']
     `136` ['self', 'coro', 'running_loop', 'e']
     `137` ['self', 'bot', 'admin_ids']
     `138` ['self', 'text']
     `139` ['self', 'fish_name', 'screenshot_bytes', 'fish_name_ru', 'text', 'photo']
     `140` ['self', 'screenshot_bytes', 'text', 'photo']
     `141` ['self', 'fish_count', 'shutdown_pending', 'text']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\telegram__notification_manager\23e135310_NotificationManager.notify_bait_changed.c`

### `?`

- implementation: `FUN_23e1358d0`
- source line hint: `?`
- Nuitka codevar: `DAT_23eeaad00`
- factory: `FUN_23e93df40`
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\telegram__notification_manager\23e1358d0_unknown.c`
