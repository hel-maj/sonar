# Function Specification: `workers.fishing.meal_system`

This is a reconstruction dossier from static Nuitka constants and Ghidra decompilation. It is not original Python source text.

## Source Path Hints
- `workers\fishing\meal_system.py`

## Docstrings / Long Text
- `118` '\n        Найти шаблон на скриншоте\n        Возвращает (найдено, x_центр, y_центр, уверенность)\n        '
- `123` '\n        Найти предмет в инвентаре\n        Возвращает (найдено, x, y, уверенность)\n        '
- `201` '\nGTA5 Meal System - Автоматическое употребление еды и напитков\nУправляет сытостью и жаждой персонажа\n'

## Function Inventory
| Inferred qualname | Impl | Source line | Arg count | Decompiled C |
|---|---:|---:|---:|---|
| `WindowCapture.__init__` | `FUN_23e7c3620` | 43 | 2 | yes |
| `WindowCapture.find_window_by_process` | `FUN_23e7ccb30` | 47 | uVar8 | yes |
| `WindowCapture.get_window_size` | `FUN_23e7ce9d0` | 73 | uVar8 | yes |
| `WindowCapture.capture` | `FUN_23e86c4b0` | 81 | uVar8 | yes |
| `WindowCapture.double_click_at` | `FUN_23e7cf6d0` | 119 | uVar8 | yes |
| `MealSystem.__init__` | `FUN_23e7d2360` | 165 | 1 | yes |
| `MealSystem.initialize` | `FUN_23e7d2ce0` | 174 | uVar8 | yes |
| `MealSystem.load_templates` | `FUN_23e7d48b0` | 210 | uVar22 | yes |
| `MealSystem.find_template` | `FUN_23e871880` | 285 | uVar8 | yes |
| `MealSystem.check_food_full` | `FUN_23e8721f0` | 292 | uVar8 | yes |
| `MealSystem.check_thirst_full` | `FUN_23e872b60` | 299 | uVar8 | yes |
| `MealSystem.find_item_in_inventory` | `FUN_23e7d6e30` | 308 | uVar8 | yes |
| `MealSystem.consume_item` | `FUN_23e7d7fc0` | 321 | uVar8 | yes |
| `MealSystem.consume_irp` | `FUN_23e7d9190` | 341 | uVar8 | yes |
| `MealSystem.consume_donuts_until_full` | `FUN_23e7db3b0` | 375 | uVar8 | yes |
| `MealSystem.consume_cocktails_until_full` | `FUN_23e873160` | 409 | 1 | yes |
| `MealSystem.run` | `FUN_23e7dd5d0` | 484 | uVar22&0xffffffff00000000 | yes |
| `?` | `FUN_23e86f5e0` | ? | ? | yes |

## Local Variable Lists
- `257` `__class__`
- `258` `self`
- `259` `self, process_name`
- `260` `hwnd, hwnds, _, pid, process, self`
- `261` `self, left, top, right, bottom, width, height, hwndDC, mfcDC, saveDC, saveBitMap, bmpinfo, bmpstr, img, e`
- `262` `self, screenshot, found, _, conf`
- `263` `self, consumed_count, screenshot, found, x, y, conf`
- `264` `self, screenshot, found, x, y, conf`
- `265` `self, x, y, item_name`
- `266` `self, x, y, rect, client_rect, border_x, border_y, screen_x, screen_y, win32api, original_pos, e`
- `267` `self, screenshot, item_key`
- `268` `self, screenshot, template, roi, search_area, result, min_val, max_val, min_loc, max_loc, h, w, center_x, center_y`
- `269` `self, callback, hwnds, hwnd, title`
- `270` `self, left, top, right, bottom`
- `271` `self, width, height`
- `272` `self, template_files, key, filename, file_path, template`
- `274` `self, screenshot, has_donut, _, has_cocktail, food_full, thirst_full`

## Structured Constants
- `16` [0, 0]
- `31` [True]
- `58` [0.05]
- `102` {'__dict_items__': [['irp', 'irp.png'], ['donut', 'donut.png'], ['cocktail', 'cocktail.png'], ['full_indicator', '100%.png']]}
- `103` {'__dict_items__': [['irp', 'irp2k.png'], ['donut', 'donut2k.png'], ['cocktail', 'cocktail2k.png'], ['full_indicator', '100%_2k.png']]}
- `117` {'__slice__': [None, 2, None]}
- `212` {'__dict_items__': [['x', 1077], ['y', 90], ['width', 538], ['height', 986]]}
- `213` {'__dict_items__': [['x', 1436], ['y', 99], ['width', 717], ['height', 1341]]}
- `214` {'__dict_items__': [['x', 1106], ['y', 482], ['width', 53], ['height', 22]]}
- `215` {'__dict_items__': [['x', 1472], ['y', 641], ['width', 72], ['height', 35]]}
- `216` {'__dict_items__': [['x', 1106], ['y', 507], ['width', 60], ['height', 26]]}
- `217` {'__dict_items__': [['x', 1472], ['y', 676], ['width', 80], ['height', 35]]}
- `224` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
- `226` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
- `228` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
- `233` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}]]}
- `239` [None]
- `248` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['item_name', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}

## Per-Function Context
### `WindowCapture.__init__`

- implementation: `FUN_23e7c3620`
- source line hint: `43`
- Nuitka codevar: `_DAT_23eed7938`
- factory: `FUN_23e93e480`
- nearby constants:
     `217` {'__dict_items__': [['x', 1472], ['y', 676], ['width', 80], ['height', 35]]}
     `218` 0.75
     `219` 0.1
     `220` 10
     `221` 'workers.fishing.meal_system'
     `222` 'Захват скриншотов окна по имени процесса'
     `223` '__qualname__'
     `224` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
  => `225` 'WindowCapture.__init__'
     `226` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `227` 'WindowCapture.find_window_by_process'
     `228` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `229` 'WindowCapture.get_window_size'
     `230` 'return'
     `231` 'ndarray'
     `232` 'WindowCapture.capture'
     `233` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}]]}
     `234` 'WindowCapture.double_click_at'
     `235` 'Класс для автоматического управления едой и напитками'
     `236` 'MealSystem.__init__'
     `237` 'MealSystem.initialize'
     `238` 'MealSystem.load_templates'
     `239` [None]
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__meal_system\23e7c3620_WindowCapture.__init.c`

### `WindowCapture.find_window_by_process`

- implementation: `FUN_23e7ccb30`
- source line hint: `47`
- Nuitka codevar: `_DAT_23eeded78`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `219` 0.1
     `220` 10
     `221` 'workers.fishing.meal_system'
     `222` 'Захват скриншотов окна по имени процесса'
     `223` '__qualname__'
     `224` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
     `225` 'WindowCapture.__init__'
     `226` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
  => `227` 'WindowCapture.find_window_by_process'
     `228` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `229` 'WindowCapture.get_window_size'
     `230` 'return'
     `231` 'ndarray'
     `232` 'WindowCapture.capture'
     `233` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}]]}
     `234` 'WindowCapture.double_click_at'
     `235` 'Класс для автоматического управления едой и напитками'
     `236` 'MealSystem.__init__'
     `237` 'MealSystem.initialize'
     `238` 'MealSystem.load_templates'
     `239` [None]
     `240` 'screenshot'
     `241` 'template'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__meal_system\23e7ccb30_WindowCapture.find_window_by_process.c`

### `WindowCapture.get_window_size`

- implementation: `FUN_23e7ce9d0`
- source line hint: `73`
- Nuitka codevar: `_DAT_23eeded48`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `221` 'workers.fishing.meal_system'
     `222` 'Захват скриншотов окна по имени процесса'
     `223` '__qualname__'
     `224` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
     `225` 'WindowCapture.__init__'
     `226` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `227` 'WindowCapture.find_window_by_process'
     `228` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
  => `229` 'WindowCapture.get_window_size'
     `230` 'return'
     `231` 'ndarray'
     `232` 'WindowCapture.capture'
     `233` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}]]}
     `234` 'WindowCapture.double_click_at'
     `235` 'Класс для автоматического управления едой и напитками'
     `236` 'MealSystem.__init__'
     `237` 'MealSystem.initialize'
     `238` 'MealSystem.load_templates'
     `239` [None]
     `240` 'screenshot'
     `241` 'template'
     `242` 'roi'
     `243` 'MealSystem.find_template'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__meal_system\23e7ce9d0_WindowCapture.get_window_size.c`

### `WindowCapture.capture`

- implementation: `FUN_23e86c4b0`
- source line hint: `81`
- Nuitka codevar: `_DAT_23eeded38`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `224` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
     `225` 'WindowCapture.__init__'
     `226` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `227` 'WindowCapture.find_window_by_process'
     `228` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `229` 'WindowCapture.get_window_size'
     `230` 'return'
     `231` 'ndarray'
  => `232` 'WindowCapture.capture'
     `233` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}]]}
     `234` 'WindowCapture.double_click_at'
     `235` 'Класс для автоматического управления едой и напитками'
     `236` 'MealSystem.__init__'
     `237` 'MealSystem.initialize'
     `238` 'MealSystem.load_templates'
     `239` [None]
     `240` 'screenshot'
     `241` 'template'
     `242` 'roi'
     `243` 'MealSystem.find_template'
     `244` 'MealSystem.check_food_full'
     `245` 'MealSystem.check_thirst_full'
     `246` 'item_key'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__meal_system\23e86c4b0_WindowCapture.capture.c`

### `WindowCapture.double_click_at`

- implementation: `FUN_23e7cf6d0`
- source line hint: `119`
- Nuitka codevar: `_DAT_23eeded20`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `226` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `227` 'WindowCapture.find_window_by_process'
     `228` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `229` 'WindowCapture.get_window_size'
     `230` 'return'
     `231` 'ndarray'
     `232` 'WindowCapture.capture'
     `233` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}]]}
  => `234` 'WindowCapture.double_click_at'
     `235` 'Класс для автоматического управления едой и напитками'
     `236` 'MealSystem.__init__'
     `237` 'MealSystem.initialize'
     `238` 'MealSystem.load_templates'
     `239` [None]
     `240` 'screenshot'
     `241` 'template'
     `242` 'roi'
     `243` 'MealSystem.find_template'
     `244` 'MealSystem.check_food_full'
     `245` 'MealSystem.check_thirst_full'
     `246` 'item_key'
     `247` 'MealSystem.find_item_in_inventory'
     `248` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['item_name', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__meal_system\23e7cf6d0_WindowCapture.double_click_at.c`

### `MealSystem.__init__`

- implementation: `FUN_23e7d2360`
- source line hint: `165`
- Nuitka codevar: `_DAT_23eeded08`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `228` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `229` 'WindowCapture.get_window_size'
     `230` 'return'
     `231` 'ndarray'
     `232` 'WindowCapture.capture'
     `233` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}]]}
     `234` 'WindowCapture.double_click_at'
     `235` 'Класс для автоматического управления едой и напитками'
  => `236` 'MealSystem.__init__'
     `237` 'MealSystem.initialize'
     `238` 'MealSystem.load_templates'
     `239` [None]
     `240` 'screenshot'
     `241` 'template'
     `242` 'roi'
     `243` 'MealSystem.find_template'
     `244` 'MealSystem.check_food_full'
     `245` 'MealSystem.check_thirst_full'
     `246` 'item_key'
     `247` 'MealSystem.find_item_in_inventory'
     `248` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['item_name', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
     `249` 'MealSystem.consume_item'
     `250` 'MealSystem.consume_irp'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__meal_system\23e7d2360_MealSystem.__init.c`

### `MealSystem.initialize`

- implementation: `FUN_23e7d2ce0`
- source line hint: `174`
- Nuitka codevar: `_DAT_23eedece8`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `229` 'WindowCapture.get_window_size'
     `230` 'return'
     `231` 'ndarray'
     `232` 'WindowCapture.capture'
     `233` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}]]}
     `234` 'WindowCapture.double_click_at'
     `235` 'Класс для автоматического управления едой и напитками'
     `236` 'MealSystem.__init__'
  => `237` 'MealSystem.initialize'
     `238` 'MealSystem.load_templates'
     `239` [None]
     `240` 'screenshot'
     `241` 'template'
     `242` 'roi'
     `243` 'MealSystem.find_template'
     `244` 'MealSystem.check_food_full'
     `245` 'MealSystem.check_thirst_full'
     `246` 'item_key'
     `247` 'MealSystem.find_item_in_inventory'
     `248` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['item_name', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
     `249` 'MealSystem.consume_item'
     `250` 'MealSystem.consume_irp'
     `251` 'MealSystem.consume_donuts_until_full'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__meal_system\23e7d2ce0_MealSystem.initialize.c`

### `MealSystem.load_templates`

- implementation: `FUN_23e7d48b0`
- source line hint: `210`
- Nuitka codevar: `_DAT_23eedeca8`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `230` 'return'
     `231` 'ndarray'
     `232` 'WindowCapture.capture'
     `233` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}]]}
     `234` 'WindowCapture.double_click_at'
     `235` 'Класс для автоматического управления едой и напитками'
     `236` 'MealSystem.__init__'
     `237` 'MealSystem.initialize'
  => `238` 'MealSystem.load_templates'
     `239` [None]
     `240` 'screenshot'
     `241` 'template'
     `242` 'roi'
     `243` 'MealSystem.find_template'
     `244` 'MealSystem.check_food_full'
     `245` 'MealSystem.check_thirst_full'
     `246` 'item_key'
     `247` 'MealSystem.find_item_in_inventory'
     `248` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['item_name', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
     `249` 'MealSystem.consume_item'
     `250` 'MealSystem.consume_irp'
     `251` 'MealSystem.consume_donuts_until_full'
     `252` 'MealSystem.consume_cocktails_until_full'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__meal_system\23e7d48b0_MealSystem.load_templates.c`

### `MealSystem.find_template`

- implementation: `FUN_23e871880`
- source line hint: `285`
- Nuitka codevar: `_DAT_23eedec80`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `235` 'Класс для автоматического управления едой и напитками'
     `236` 'MealSystem.__init__'
     `237` 'MealSystem.initialize'
     `238` 'MealSystem.load_templates'
     `239` [None]
     `240` 'screenshot'
     `241` 'template'
     `242` 'roi'
  => `243` 'MealSystem.find_template'
     `244` 'MealSystem.check_food_full'
     `245` 'MealSystem.check_thirst_full'
     `246` 'item_key'
     `247` 'MealSystem.find_item_in_inventory'
     `248` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['item_name', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
     `249` 'MealSystem.consume_item'
     `250` 'MealSystem.consume_irp'
     `251` 'MealSystem.consume_donuts_until_full'
     `252` 'MealSystem.consume_cocktails_until_full'
     `253` 'MealSystem.run'
     `254` 'main'
     `255` 'workers\\fishing\\meal_system.py'
     `256` '<module workers.fishing.meal_system>'
     `257` ['__class__']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__meal_system\23e871880_MealSystem.find_template.c`

### `MealSystem.check_food_full`

- implementation: `FUN_23e8721f0`
- source line hint: `292`
- Nuitka codevar: `_DAT_23eedec70`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `236` 'MealSystem.__init__'
     `237` 'MealSystem.initialize'
     `238` 'MealSystem.load_templates'
     `239` [None]
     `240` 'screenshot'
     `241` 'template'
     `242` 'roi'
     `243` 'MealSystem.find_template'
  => `244` 'MealSystem.check_food_full'
     `245` 'MealSystem.check_thirst_full'
     `246` 'item_key'
     `247` 'MealSystem.find_item_in_inventory'
     `248` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['item_name', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
     `249` 'MealSystem.consume_item'
     `250` 'MealSystem.consume_irp'
     `251` 'MealSystem.consume_donuts_until_full'
     `252` 'MealSystem.consume_cocktails_until_full'
     `253` 'MealSystem.run'
     `254` 'main'
     `255` 'workers\\fishing\\meal_system.py'
     `256` '<module workers.fishing.meal_system>'
     `257` ['__class__']
     `258` ['self']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__meal_system\23e8721f0_MealSystem.check_food_full.c`

### `MealSystem.check_thirst_full`

- implementation: `FUN_23e872b60`
- source line hint: `299`
- Nuitka codevar: `_DAT_23eedec60`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `237` 'MealSystem.initialize'
     `238` 'MealSystem.load_templates'
     `239` [None]
     `240` 'screenshot'
     `241` 'template'
     `242` 'roi'
     `243` 'MealSystem.find_template'
     `244` 'MealSystem.check_food_full'
  => `245` 'MealSystem.check_thirst_full'
     `246` 'item_key'
     `247` 'MealSystem.find_item_in_inventory'
     `248` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['item_name', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
     `249` 'MealSystem.consume_item'
     `250` 'MealSystem.consume_irp'
     `251` 'MealSystem.consume_donuts_until_full'
     `252` 'MealSystem.consume_cocktails_until_full'
     `253` 'MealSystem.run'
     `254` 'main'
     `255` 'workers\\fishing\\meal_system.py'
     `256` '<module workers.fishing.meal_system>'
     `257` ['__class__']
     `258` ['self']
     `259` ['self', 'process_name']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__meal_system\23e872b60_MealSystem.check_thirst_full.c`

### `MealSystem.find_item_in_inventory`

- implementation: `FUN_23e7d6e30`
- source line hint: `308`
- Nuitka codevar: `_DAT_23eedec50`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `239` [None]
     `240` 'screenshot'
     `241` 'template'
     `242` 'roi'
     `243` 'MealSystem.find_template'
     `244` 'MealSystem.check_food_full'
     `245` 'MealSystem.check_thirst_full'
     `246` 'item_key'
  => `247` 'MealSystem.find_item_in_inventory'
     `248` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['item_name', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
     `249` 'MealSystem.consume_item'
     `250` 'MealSystem.consume_irp'
     `251` 'MealSystem.consume_donuts_until_full'
     `252` 'MealSystem.consume_cocktails_until_full'
     `253` 'MealSystem.run'
     `254` 'main'
     `255` 'workers\\fishing\\meal_system.py'
     `256` '<module workers.fishing.meal_system>'
     `257` ['__class__']
     `258` ['self']
     `259` ['self', 'process_name']
     `260` ['hwnd', 'hwnds', '_', 'pid', 'process', 'self']
     `261` ['self', 'left', 'top', 'right', 'bottom', 'width', 'height', 'hwndDC', 'mfcDC', 'saveDC', 'saveBitMap', 'bmpinfo', 'bmpstr', 'img', 'e']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__meal_system\23e7d6e30_MealSystem.find_item_in_inventory.c`

### `MealSystem.consume_item`

- implementation: `FUN_23e7d7fc0`
- source line hint: `321`
- Nuitka codevar: `_DAT_23eedec40`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `241` 'template'
     `242` 'roi'
     `243` 'MealSystem.find_template'
     `244` 'MealSystem.check_food_full'
     `245` 'MealSystem.check_thirst_full'
     `246` 'item_key'
     `247` 'MealSystem.find_item_in_inventory'
     `248` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['item_name', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
  => `249` 'MealSystem.consume_item'
     `250` 'MealSystem.consume_irp'
     `251` 'MealSystem.consume_donuts_until_full'
     `252` 'MealSystem.consume_cocktails_until_full'
     `253` 'MealSystem.run'
     `254` 'main'
     `255` 'workers\\fishing\\meal_system.py'
     `256` '<module workers.fishing.meal_system>'
     `257` ['__class__']
     `258` ['self']
     `259` ['self', 'process_name']
     `260` ['hwnd', 'hwnds', '_', 'pid', 'process', 'self']
     `261` ['self', 'left', 'top', 'right', 'bottom', 'width', 'height', 'hwndDC', 'mfcDC', 'saveDC', 'saveBitMap', 'bmpinfo', 'bmpstr', 'img', 'e']
     `262` ['self', 'screenshot', 'found', '_', 'conf']
     `263` ['self', 'consumed_count', 'screenshot', 'found', 'x', 'y', 'conf']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__meal_system\23e7d7fc0_MealSystem.consume_item.c`

### `MealSystem.consume_irp`

- implementation: `FUN_23e7d9190`
- source line hint: `341`
- Nuitka codevar: `DAT_23eedec30`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `242` 'roi'
     `243` 'MealSystem.find_template'
     `244` 'MealSystem.check_food_full'
     `245` 'MealSystem.check_thirst_full'
     `246` 'item_key'
     `247` 'MealSystem.find_item_in_inventory'
     `248` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['item_name', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
     `249` 'MealSystem.consume_item'
  => `250` 'MealSystem.consume_irp'
     `251` 'MealSystem.consume_donuts_until_full'
     `252` 'MealSystem.consume_cocktails_until_full'
     `253` 'MealSystem.run'
     `254` 'main'
     `255` 'workers\\fishing\\meal_system.py'
     `256` '<module workers.fishing.meal_system>'
     `257` ['__class__']
     `258` ['self']
     `259` ['self', 'process_name']
     `260` ['hwnd', 'hwnds', '_', 'pid', 'process', 'self']
     `261` ['self', 'left', 'top', 'right', 'bottom', 'width', 'height', 'hwndDC', 'mfcDC', 'saveDC', 'saveBitMap', 'bmpinfo', 'bmpstr', 'img', 'e']
     `262` ['self', 'screenshot', 'found', '_', 'conf']
     `263` ['self', 'consumed_count', 'screenshot', 'found', 'x', 'y', 'conf']
     `264` ['self', 'screenshot', 'found', 'x', 'y', 'conf']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__meal_system\23e7d9190_MealSystem.consume_irp.c`

### `MealSystem.consume_donuts_until_full`

- implementation: `FUN_23e7db3b0`
- source line hint: `375`
- Nuitka codevar: `_DAT_23eedec20`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `243` 'MealSystem.find_template'
     `244` 'MealSystem.check_food_full'
     `245` 'MealSystem.check_thirst_full'
     `246` 'item_key'
     `247` 'MealSystem.find_item_in_inventory'
     `248` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['item_name', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
     `249` 'MealSystem.consume_item'
     `250` 'MealSystem.consume_irp'
  => `251` 'MealSystem.consume_donuts_until_full'
     `252` 'MealSystem.consume_cocktails_until_full'
     `253` 'MealSystem.run'
     `254` 'main'
     `255` 'workers\\fishing\\meal_system.py'
     `256` '<module workers.fishing.meal_system>'
     `257` ['__class__']
     `258` ['self']
     `259` ['self', 'process_name']
     `260` ['hwnd', 'hwnds', '_', 'pid', 'process', 'self']
     `261` ['self', 'left', 'top', 'right', 'bottom', 'width', 'height', 'hwndDC', 'mfcDC', 'saveDC', 'saveBitMap', 'bmpinfo', 'bmpstr', 'img', 'e']
     `262` ['self', 'screenshot', 'found', '_', 'conf']
     `263` ['self', 'consumed_count', 'screenshot', 'found', 'x', 'y', 'conf']
     `264` ['self', 'screenshot', 'found', 'x', 'y', 'conf']
     `265` ['self', 'x', 'y', 'item_name']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__meal_system\23e7db3b0_MealSystem.consume_donuts_until_full.c`

### `MealSystem.consume_cocktails_until_full`

- implementation: `FUN_23e873160`
- source line hint: `409`
- Nuitka codevar: `_DAT_23eedec10`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `244` 'MealSystem.check_food_full'
     `245` 'MealSystem.check_thirst_full'
     `246` 'item_key'
     `247` 'MealSystem.find_item_in_inventory'
     `248` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['item_name', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
     `249` 'MealSystem.consume_item'
     `250` 'MealSystem.consume_irp'
     `251` 'MealSystem.consume_donuts_until_full'
  => `252` 'MealSystem.consume_cocktails_until_full'
     `253` 'MealSystem.run'
     `254` 'main'
     `255` 'workers\\fishing\\meal_system.py'
     `256` '<module workers.fishing.meal_system>'
     `257` ['__class__']
     `258` ['self']
     `259` ['self', 'process_name']
     `260` ['hwnd', 'hwnds', '_', 'pid', 'process', 'self']
     `261` ['self', 'left', 'top', 'right', 'bottom', 'width', 'height', 'hwndDC', 'mfcDC', 'saveDC', 'saveBitMap', 'bmpinfo', 'bmpstr', 'img', 'e']
     `262` ['self', 'screenshot', 'found', '_', 'conf']
     `263` ['self', 'consumed_count', 'screenshot', 'found', 'x', 'y', 'conf']
     `264` ['self', 'screenshot', 'found', 'x', 'y', 'conf']
     `265` ['self', 'x', 'y', 'item_name']
     `266` ['self', 'x', 'y', 'rect', 'client_rect', 'border_x', 'border_y', 'screen_x', 'screen_y', 'win32api', 'original_pos', 'e']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__meal_system\23e873160_MealSystem.consume_cocktails_until_full.c`

### `MealSystem.run`

- implementation: `FUN_23e7dd5d0`
- source line hint: `484`
- Nuitka codevar: `_DAT_23eedec00`
- factory: `FUN_23e93df40`
- nearby constants:
     `245` 'MealSystem.check_thirst_full'
     `246` 'item_key'
     `247` 'MealSystem.find_item_in_inventory'
     `248` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['item_name', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
     `249` 'MealSystem.consume_item'
     `250` 'MealSystem.consume_irp'
     `251` 'MealSystem.consume_donuts_until_full'
     `252` 'MealSystem.consume_cocktails_until_full'
  => `253` 'MealSystem.run'
     `254` 'main'
     `255` 'workers\\fishing\\meal_system.py'
     `256` '<module workers.fishing.meal_system>'
     `257` ['__class__']
     `258` ['self']
     `259` ['self', 'process_name']
     `260` ['hwnd', 'hwnds', '_', 'pid', 'process', 'self']
     `261` ['self', 'left', 'top', 'right', 'bottom', 'width', 'height', 'hwndDC', 'mfcDC', 'saveDC', 'saveBitMap', 'bmpinfo', 'bmpstr', 'img', 'e']
     `262` ['self', 'screenshot', 'found', '_', 'conf']
     `263` ['self', 'consumed_count', 'screenshot', 'found', 'x', 'y', 'conf']
     `264` ['self', 'screenshot', 'found', 'x', 'y', 'conf']
     `265` ['self', 'x', 'y', 'item_name']
     `266` ['self', 'x', 'y', 'rect', 'client_rect', 'border_x', 'border_y', 'screen_x', 'screen_y', 'win32api', 'original_pos', 'e']
     `267` ['self', 'screenshot', 'item_key']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__meal_system\23e7dd5d0_MealSystem.run.c`

### `?`

- implementation: `FUN_23e86f5e0`
- source line hint: `?`
- Nuitka codevar: `uVar2`
- factory: `FUN_23e93e480`
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__meal_system\23e86f5e0_unknown.c`
