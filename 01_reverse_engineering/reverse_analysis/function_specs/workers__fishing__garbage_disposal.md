# Function Specification: `workers.fishing.garbage_disposal`

This is a reconstruction dossier from static Nuitka constants and Ghidra decompilation. It is not original Python source text.

## Source Path Hints
- `workers\fishing\garbage_disposal.py`

## Docstrings / Long Text
- `118` '\n        Найти шаблон на скриншоте (первое вхождение)\n        Возвращает (найдено, x_центр, y_центр, уверенность)\n        '
- `126` '\n        Найти ВСЕ вхождения шаблона на скриншоте\n        Возвращает список кортежей (x_центр, y_центр, уверенность)\n        '
- `135` '\n        Удалить перекрывающиеся совпадения, оставить только лучшие\n        '
- `155` '\n        Найти весь мусор в инвентаре один раз и запомнить ВСЕ позиции\n        Возвращает список словарей с информацией о найденном мусоре\n        '
- `157` '\n🗑️ Выбрасывание: '
- `174` '\n        Выбросить мусор по заранее известной позиции\n        Возвращает True если успешно\n        '
- `192` '\n📋 Найдено предметов мусора: '
- `193` '\n['
- `210` '\nGTA5 Garbage Disposal - Автоматическое выбрасывание мусора\nНаходит и выбрасывает: банку кукурузы, пустой мешок, пустую пачку сигарет\n'

## Function Inventory
| Inferred qualname | Impl | Source line | Arg count | Decompiled C |
|---|---:|---:|---:|---|
| `WindowCapture.__init__` | `FUN_23e78a760` | 34 | 2 | yes |
| `WindowCapture.find_window_by_process` | `FUN_23e78ac30` | 38 | uVar9 | yes |
| `WindowCapture.get_window_size` | `FUN_23e78ca70` | 64 | uVar9 | yes |
| `WindowCapture.capture` | `FUN_23e78d780` | 72 | uVar9 | yes |
| `WindowCapture.click_at` | `FUN_23e7907a0` | 110 | uVar9 | yes |
| `GarbageDisposal.__init__` | `FUN_23e793050` | 156 | 1 | yes |
| `GarbageDisposal.initialize` | `FUN_23e793a60` | 180 | uVar9 | yes |
| `GarbageDisposal.load_templates` | `FUN_23e795020` | 212 | uVar22 | yes |
| `GarbageDisposal.find_template` | `FUN_23e7974c0` | 251 | uVar9 | yes |
| `GarbageDisposal.find_all_template_matches` | `FUN_23e7996c0` | 285 | uVar9 | yes |
| `GarbageDisposal.remove_overlapping_matches` | `FUN_23e79c1b0` | 326 | 4 | yes |
| `GarbageDisposal.find_all_garbage` | `FUN_23e7c8c60` | 356 | uVar9 | yes |
| `GarbageDisposal.dispose_garbage_by_position` | `FUN_23e79f360` | 399 | uVar9 | yes |
| `GarbageDisposal.run` | `FUN_23e7a1d20` | 443 | 1 | yes |
| `?` | `FUN_23e7a6340` | 501 | uVar22&0xffffffff00000000 | yes |

## Local Variable Lists
- `261` `__class__`
- `262` `self`
- `263` `self, process_name`
- `264` `hwnd, hwnds, _, pid, process, self`
- `265` `self, left, top, right, bottom, width, height, hwndDC, mfcDC, saveDC, saveBitMap, bmpinfo, bmpstr, img, e`
- `266` `self, x, y, button, rect, client_rect, border_x, border_y, screen_x, screen_y, top_right_x, top_right_y, e`
- `267` `self, garbage_info, garbage_name, garbage_x, garbage_y, garbage_num, key_to_press, e`
- `268` `self, screenshot, found_garbage, garbage_types_to_search, garbage_key, matches, i, x, y, conf, garbage_info`
- `269` `self, screenshot, template, roi, search_area, offset_x, offset_y, result, locations, matches, h, w, pt, confidence, center_x, center_y`
- `270` `self, screenshot, template, roi, search_area, result, min_val, max_val, min_loc, max_loc, h, w, center_x, center_y`
- `271` `self, callback, hwnds, hwnd, title`
- `272` `self, left, top, right, bottom`
- `273` `self, width, height`
- `274` `self, template_files, key, filename, file_path, template`
- `276` `self, matches, template_w, template_h, filtered, min_distance, match, x, y, conf, is_overlap, existing, ex, ey, _, distance`
- `277` `self, key, name, screenshot, garbage_positions, disposed_count, i, garbage_info`

## Structured Constants
- `16` [0, 0]
- `31` [True]
- `57` [0.05]
- `72` {'__dict_items__': [['bag', True], ['corn', True], ['pack', True]]}
- `76` {'__dict_items__': [['corn', 'Банка кукурузы'], ['bag', 'Пустой мешок'], ['pack', 'Пустая пачка сигарет']]}
- `102` {'__dict_items__': [['corn', 'corn.png'], ['bag', 'bag.png'], ['pack', 'pack.png']]}
- `103` {'__dict_items__': [['corn', 'corn2k.png'], ['bag', 'bag2k.png'], ['pack', 'pack2k.png']]}
- `117` {'__slice__': [None, 2, None]}
- `120` {'__slice__': [None, None, -1]}
- `164` [1.0]
- `195` {'__dict_items__': [['end', '']]}
- `221` {'__dict_items__': [['x', 1077], ['y', 90], ['width', 538], ['height', 986]]}
- `222` {'__dict_items__': [['x', 1436], ['y', 99], ['width', 717], ['height', 1341]]}
- `229` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
- `231` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
- `233` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
- `239` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['button', {'__builtin__': 'str'}]]}
- `245` [None]
- `251` {'__dict_items__': [['matches', {'__builtin__': 'list'}], ['template_w', {'__builtin__': 'int'}], ['template_h', {'__builtin__': 'int'}], ['return', {'__builtin__': 'list'}]]}
- `254` {'__dict_items__': [['garbage_info', {'__builtin__': 'dict'}], ['return', {'__builtin__': 'bool'}]]}

## Per-Function Context
### `WindowCapture.__init__`

- implementation: `FUN_23e78a760`
- source line hint: `34`
- Nuitka codevar: `DAT_23eedacf0`
- factory: `FUN_23e93e480`
- nearby constants:
     `222` {'__dict_items__': [['x', 1436], ['y', 99], ['width', 717], ['height', 1341]]}
     `223` 0.8
     `224` 'DELAY_AFTER_RIGHT_CLICK'
     `225` 'DELAY_AFTER_KEY_PRESS'
     `226` 'workers.fishing.garbage_disposal'
     `227` 'Захват скриншотов окна по имени процесса'
     `228` '__qualname__'
     `229` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
  => `230` 'WindowCapture.__init__'
     `231` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `232` 'WindowCapture.find_window_by_process'
     `233` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `234` 'WindowCapture.get_window_size'
     `235` 'return'
     `236` 'ndarray'
     `237` 'WindowCapture.capture'
     `238` ['left']
     `239` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['button', {'__builtin__': 'str'}]]}
     `240` 'WindowCapture.click_at'
     `241` 'Класс для автоматического выбрасывания мусора'
     `242` 'GarbageDisposal.__init__'
     `243` 'GarbageDisposal.initialize'
     `244` 'GarbageDisposal.load_templates'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__garbage_disposal\23e78a760_WindowCapture.__init.c`

### `WindowCapture.find_window_by_process`

- implementation: `FUN_23e78ac30`
- source line hint: `38`
- Nuitka codevar: `DAT_23eedace0`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `224` 'DELAY_AFTER_RIGHT_CLICK'
     `225` 'DELAY_AFTER_KEY_PRESS'
     `226` 'workers.fishing.garbage_disposal'
     `227` 'Захват скриншотов окна по имени процесса'
     `228` '__qualname__'
     `229` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
     `230` 'WindowCapture.__init__'
     `231` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
  => `232` 'WindowCapture.find_window_by_process'
     `233` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `234` 'WindowCapture.get_window_size'
     `235` 'return'
     `236` 'ndarray'
     `237` 'WindowCapture.capture'
     `238` ['left']
     `239` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['button', {'__builtin__': 'str'}]]}
     `240` 'WindowCapture.click_at'
     `241` 'Класс для автоматического выбрасывания мусора'
     `242` 'GarbageDisposal.__init__'
     `243` 'GarbageDisposal.initialize'
     `244` 'GarbageDisposal.load_templates'
     `245` [None]
     `246` 'template'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__garbage_disposal\23e78ac30_WindowCapture.find_window_by_process.c`

### `WindowCapture.get_window_size`

- implementation: `FUN_23e78ca70`
- source line hint: `64`
- Nuitka codevar: `DAT_23eedacb0`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `226` 'workers.fishing.garbage_disposal'
     `227` 'Захват скриншотов окна по имени процесса'
     `228` '__qualname__'
     `229` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
     `230` 'WindowCapture.__init__'
     `231` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `232` 'WindowCapture.find_window_by_process'
     `233` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
  => `234` 'WindowCapture.get_window_size'
     `235` 'return'
     `236` 'ndarray'
     `237` 'WindowCapture.capture'
     `238` ['left']
     `239` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['button', {'__builtin__': 'str'}]]}
     `240` 'WindowCapture.click_at'
     `241` 'Класс для автоматического выбрасывания мусора'
     `242` 'GarbageDisposal.__init__'
     `243` 'GarbageDisposal.initialize'
     `244` 'GarbageDisposal.load_templates'
     `245` [None]
     `246` 'template'
     `247` 'roi'
     `248` 'find_template'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__garbage_disposal\23e78ca70_WindowCapture.get_window_size.c`

### `WindowCapture.capture`

- implementation: `FUN_23e78d780`
- source line hint: `72`
- Nuitka codevar: `DAT_23eedaca0`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `229` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
     `230` 'WindowCapture.__init__'
     `231` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `232` 'WindowCapture.find_window_by_process'
     `233` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `234` 'WindowCapture.get_window_size'
     `235` 'return'
     `236` 'ndarray'
  => `237` 'WindowCapture.capture'
     `238` ['left']
     `239` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['button', {'__builtin__': 'str'}]]}
     `240` 'WindowCapture.click_at'
     `241` 'Класс для автоматического выбрасывания мусора'
     `242` 'GarbageDisposal.__init__'
     `243` 'GarbageDisposal.initialize'
     `244` 'GarbageDisposal.load_templates'
     `245` [None]
     `246` 'template'
     `247` 'roi'
     `248` 'find_template'
     `249` 'GarbageDisposal.find_template'
     `250` 'GarbageDisposal.find_all_template_matches'
     `251` {'__dict_items__': [['matches', {'__builtin__': 'list'}], ['template_w', {'__builtin__': 'int'}], ['template_h', {'__builtin__': 'int'}], ['return', {'__builtin__': 'list'}]]}
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__garbage_disposal\23e78d780_WindowCapture.capture.c`

### `WindowCapture.click_at`

- implementation: `FUN_23e7907a0`
- source line hint: `110`
- Nuitka codevar: `DAT_23eedac88`
- factory: `FUN_23e93e480`
- nearby constants:
     `232` 'WindowCapture.find_window_by_process'
     `233` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `234` 'WindowCapture.get_window_size'
     `235` 'return'
     `236` 'ndarray'
     `237` 'WindowCapture.capture'
     `238` ['left']
     `239` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['button', {'__builtin__': 'str'}]]}
  => `240` 'WindowCapture.click_at'
     `241` 'Класс для автоматического выбрасывания мусора'
     `242` 'GarbageDisposal.__init__'
     `243` 'GarbageDisposal.initialize'
     `244` 'GarbageDisposal.load_templates'
     `245` [None]
     `246` 'template'
     `247` 'roi'
     `248` 'find_template'
     `249` 'GarbageDisposal.find_template'
     `250` 'GarbageDisposal.find_all_template_matches'
     `251` {'__dict_items__': [['matches', {'__builtin__': 'list'}], ['template_w', {'__builtin__': 'int'}], ['template_h', {'__builtin__': 'int'}], ['return', {'__builtin__': 'list'}]]}
     `252` 'GarbageDisposal.remove_overlapping_matches'
     `253` 'GarbageDisposal.find_all_garbage'
     `254` {'__dict_items__': [['garbage_info', {'__builtin__': 'dict'}], ['return', {'__builtin__': 'bool'}]]}
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__garbage_disposal\23e7907a0_WindowCapture.click_at.c`

### `GarbageDisposal.__init__`

- implementation: `FUN_23e793050`
- source line hint: `156`
- Nuitka codevar: `DAT_23eedac78`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `234` 'WindowCapture.get_window_size'
     `235` 'return'
     `236` 'ndarray'
     `237` 'WindowCapture.capture'
     `238` ['left']
     `239` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['button', {'__builtin__': 'str'}]]}
     `240` 'WindowCapture.click_at'
     `241` 'Класс для автоматического выбрасывания мусора'
  => `242` 'GarbageDisposal.__init__'
     `243` 'GarbageDisposal.initialize'
     `244` 'GarbageDisposal.load_templates'
     `245` [None]
     `246` 'template'
     `247` 'roi'
     `248` 'find_template'
     `249` 'GarbageDisposal.find_template'
     `250` 'GarbageDisposal.find_all_template_matches'
     `251` {'__dict_items__': [['matches', {'__builtin__': 'list'}], ['template_w', {'__builtin__': 'int'}], ['template_h', {'__builtin__': 'int'}], ['return', {'__builtin__': 'list'}]]}
     `252` 'GarbageDisposal.remove_overlapping_matches'
     `253` 'GarbageDisposal.find_all_garbage'
     `254` {'__dict_items__': [['garbage_info', {'__builtin__': 'dict'}], ['return', {'__builtin__': 'bool'}]]}
     `255` 'GarbageDisposal.dispose_garbage_by_position'
     `256` 'GarbageDisposal.run'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__garbage_disposal\23e793050_GarbageDisposal.__init.c`

### `GarbageDisposal.initialize`

- implementation: `FUN_23e793a60`
- source line hint: `180`
- Nuitka codevar: `DAT_23eedac58`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `235` 'return'
     `236` 'ndarray'
     `237` 'WindowCapture.capture'
     `238` ['left']
     `239` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['button', {'__builtin__': 'str'}]]}
     `240` 'WindowCapture.click_at'
     `241` 'Класс для автоматического выбрасывания мусора'
     `242` 'GarbageDisposal.__init__'
  => `243` 'GarbageDisposal.initialize'
     `244` 'GarbageDisposal.load_templates'
     `245` [None]
     `246` 'template'
     `247` 'roi'
     `248` 'find_template'
     `249` 'GarbageDisposal.find_template'
     `250` 'GarbageDisposal.find_all_template_matches'
     `251` {'__dict_items__': [['matches', {'__builtin__': 'list'}], ['template_w', {'__builtin__': 'int'}], ['template_h', {'__builtin__': 'int'}], ['return', {'__builtin__': 'list'}]]}
     `252` 'GarbageDisposal.remove_overlapping_matches'
     `253` 'GarbageDisposal.find_all_garbage'
     `254` {'__dict_items__': [['garbage_info', {'__builtin__': 'dict'}], ['return', {'__builtin__': 'bool'}]]}
     `255` 'GarbageDisposal.dispose_garbage_by_position'
     `256` 'GarbageDisposal.run'
     `257` 'main'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__garbage_disposal\23e793a60_GarbageDisposal.initialize.c`

### `GarbageDisposal.load_templates`

- implementation: `FUN_23e795020`
- source line hint: `212`
- Nuitka codevar: `DAT_23eedac38`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `236` 'ndarray'
     `237` 'WindowCapture.capture'
     `238` ['left']
     `239` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['button', {'__builtin__': 'str'}]]}
     `240` 'WindowCapture.click_at'
     `241` 'Класс для автоматического выбрасывания мусора'
     `242` 'GarbageDisposal.__init__'
     `243` 'GarbageDisposal.initialize'
  => `244` 'GarbageDisposal.load_templates'
     `245` [None]
     `246` 'template'
     `247` 'roi'
     `248` 'find_template'
     `249` 'GarbageDisposal.find_template'
     `250` 'GarbageDisposal.find_all_template_matches'
     `251` {'__dict_items__': [['matches', {'__builtin__': 'list'}], ['template_w', {'__builtin__': 'int'}], ['template_h', {'__builtin__': 'int'}], ['return', {'__builtin__': 'list'}]]}
     `252` 'GarbageDisposal.remove_overlapping_matches'
     `253` 'GarbageDisposal.find_all_garbage'
     `254` {'__dict_items__': [['garbage_info', {'__builtin__': 'dict'}], ['return', {'__builtin__': 'bool'}]]}
     `255` 'GarbageDisposal.dispose_garbage_by_position'
     `256` 'GarbageDisposal.run'
     `257` 'main'
     `258` 'workers\\fishing\\garbage_disposal.py'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__garbage_disposal\23e795020_GarbageDisposal.load_templates.c`

### `GarbageDisposal.find_template`

- implementation: `FUN_23e7974c0`
- source line hint: `251`
- Nuitka codevar: `uVar2`
- factory: `FUN_23e93e480`
- nearby constants:
     `241` 'Класс для автоматического выбрасывания мусора'
     `242` 'GarbageDisposal.__init__'
     `243` 'GarbageDisposal.initialize'
     `244` 'GarbageDisposal.load_templates'
     `245` [None]
     `246` 'template'
     `247` 'roi'
     `248` 'find_template'
  => `249` 'GarbageDisposal.find_template'
     `250` 'GarbageDisposal.find_all_template_matches'
     `251` {'__dict_items__': [['matches', {'__builtin__': 'list'}], ['template_w', {'__builtin__': 'int'}], ['template_h', {'__builtin__': 'int'}], ['return', {'__builtin__': 'list'}]]}
     `252` 'GarbageDisposal.remove_overlapping_matches'
     `253` 'GarbageDisposal.find_all_garbage'
     `254` {'__dict_items__': [['garbage_info', {'__builtin__': 'dict'}], ['return', {'__builtin__': 'bool'}]]}
     `255` 'GarbageDisposal.dispose_garbage_by_position'
     `256` 'GarbageDisposal.run'
     `257` 'main'
     `258` 'workers\\fishing\\garbage_disposal.py'
     `259` ['x']
     `260` '<module workers.fishing.garbage_disposal>'
     `261` ['__class__']
     `262` ['self']
     `263` ['self', 'process_name']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__garbage_disposal\23e7974c0_GarbageDisposal.find_template.c`

### `GarbageDisposal.find_all_template_matches`

- implementation: `FUN_23e7996c0`
- source line hint: `285`
- Nuitka codevar: `uVar2`
- factory: `FUN_23e93e480`
- nearby constants:
     `242` 'GarbageDisposal.__init__'
     `243` 'GarbageDisposal.initialize'
     `244` 'GarbageDisposal.load_templates'
     `245` [None]
     `246` 'template'
     `247` 'roi'
     `248` 'find_template'
     `249` 'GarbageDisposal.find_template'
  => `250` 'GarbageDisposal.find_all_template_matches'
     `251` {'__dict_items__': [['matches', {'__builtin__': 'list'}], ['template_w', {'__builtin__': 'int'}], ['template_h', {'__builtin__': 'int'}], ['return', {'__builtin__': 'list'}]]}
     `252` 'GarbageDisposal.remove_overlapping_matches'
     `253` 'GarbageDisposal.find_all_garbage'
     `254` {'__dict_items__': [['garbage_info', {'__builtin__': 'dict'}], ['return', {'__builtin__': 'bool'}]]}
     `255` 'GarbageDisposal.dispose_garbage_by_position'
     `256` 'GarbageDisposal.run'
     `257` 'main'
     `258` 'workers\\fishing\\garbage_disposal.py'
     `259` ['x']
     `260` '<module workers.fishing.garbage_disposal>'
     `261` ['__class__']
     `262` ['self']
     `263` ['self', 'process_name']
     `264` ['hwnd', 'hwnds', '_', 'pid', 'process', 'self']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__garbage_disposal\23e7996c0_GarbageDisposal.find_all_template_matches.c`

### `GarbageDisposal.remove_overlapping_matches`

- implementation: `FUN_23e79c1b0`
- source line hint: `326`
- Nuitka codevar: `DAT_23eedac08`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `244` 'GarbageDisposal.load_templates'
     `245` [None]
     `246` 'template'
     `247` 'roi'
     `248` 'find_template'
     `249` 'GarbageDisposal.find_template'
     `250` 'GarbageDisposal.find_all_template_matches'
     `251` {'__dict_items__': [['matches', {'__builtin__': 'list'}], ['template_w', {'__builtin__': 'int'}], ['template_h', {'__builtin__': 'int'}], ['return', {'__builtin__': 'list'}]]}
  => `252` 'GarbageDisposal.remove_overlapping_matches'
     `253` 'GarbageDisposal.find_all_garbage'
     `254` {'__dict_items__': [['garbage_info', {'__builtin__': 'dict'}], ['return', {'__builtin__': 'bool'}]]}
     `255` 'GarbageDisposal.dispose_garbage_by_position'
     `256` 'GarbageDisposal.run'
     `257` 'main'
     `258` 'workers\\fishing\\garbage_disposal.py'
     `259` ['x']
     `260` '<module workers.fishing.garbage_disposal>'
     `261` ['__class__']
     `262` ['self']
     `263` ['self', 'process_name']
     `264` ['hwnd', 'hwnds', '_', 'pid', 'process', 'self']
     `265` ['self', 'left', 'top', 'right', 'bottom', 'width', 'height', 'hwndDC', 'mfcDC', 'saveDC', 'saveBitMap', 'bmpinfo', 'bmpstr', 'img', 'e']
     `266` ['self', 'x', 'y', 'button', 'rect', 'client_rect', 'border_x', 'border_y', 'screen_x', 'screen_y', 'top_right_x', 'top_right_y', 'e']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__garbage_disposal\23e79c1b0_GarbageDisposal.remove_overlapping_matches.c`

### `GarbageDisposal.find_all_garbage`

- implementation: `FUN_23e7c8c60`
- source line hint: `356`
- Nuitka codevar: `DAT_23eedabe8`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `245` [None]
     `246` 'template'
     `247` 'roi'
     `248` 'find_template'
     `249` 'GarbageDisposal.find_template'
     `250` 'GarbageDisposal.find_all_template_matches'
     `251` {'__dict_items__': [['matches', {'__builtin__': 'list'}], ['template_w', {'__builtin__': 'int'}], ['template_h', {'__builtin__': 'int'}], ['return', {'__builtin__': 'list'}]]}
     `252` 'GarbageDisposal.remove_overlapping_matches'
  => `253` 'GarbageDisposal.find_all_garbage'
     `254` {'__dict_items__': [['garbage_info', {'__builtin__': 'dict'}], ['return', {'__builtin__': 'bool'}]]}
     `255` 'GarbageDisposal.dispose_garbage_by_position'
     `256` 'GarbageDisposal.run'
     `257` 'main'
     `258` 'workers\\fishing\\garbage_disposal.py'
     `259` ['x']
     `260` '<module workers.fishing.garbage_disposal>'
     `261` ['__class__']
     `262` ['self']
     `263` ['self', 'process_name']
     `264` ['hwnd', 'hwnds', '_', 'pid', 'process', 'self']
     `265` ['self', 'left', 'top', 'right', 'bottom', 'width', 'height', 'hwndDC', 'mfcDC', 'saveDC', 'saveBitMap', 'bmpinfo', 'bmpstr', 'img', 'e']
     `266` ['self', 'x', 'y', 'button', 'rect', 'client_rect', 'border_x', 'border_y', 'screen_x', 'screen_y', 'top_right_x', 'top_right_y', 'e']
     `267` ['self', 'garbage_info', 'garbage_name', 'garbage_x', 'garbage_y', 'garbage_num', 'key_to_press', 'e']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__garbage_disposal\23e7c8c60_GarbageDisposal.find_all_garbage.c`

### `GarbageDisposal.dispose_garbage_by_position`

- implementation: `FUN_23e79f360`
- source line hint: `399`
- Nuitka codevar: `DAT_23eedabd8`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `247` 'roi'
     `248` 'find_template'
     `249` 'GarbageDisposal.find_template'
     `250` 'GarbageDisposal.find_all_template_matches'
     `251` {'__dict_items__': [['matches', {'__builtin__': 'list'}], ['template_w', {'__builtin__': 'int'}], ['template_h', {'__builtin__': 'int'}], ['return', {'__builtin__': 'list'}]]}
     `252` 'GarbageDisposal.remove_overlapping_matches'
     `253` 'GarbageDisposal.find_all_garbage'
     `254` {'__dict_items__': [['garbage_info', {'__builtin__': 'dict'}], ['return', {'__builtin__': 'bool'}]]}
  => `255` 'GarbageDisposal.dispose_garbage_by_position'
     `256` 'GarbageDisposal.run'
     `257` 'main'
     `258` 'workers\\fishing\\garbage_disposal.py'
     `259` ['x']
     `260` '<module workers.fishing.garbage_disposal>'
     `261` ['__class__']
     `262` ['self']
     `263` ['self', 'process_name']
     `264` ['hwnd', 'hwnds', '_', 'pid', 'process', 'self']
     `265` ['self', 'left', 'top', 'right', 'bottom', 'width', 'height', 'hwndDC', 'mfcDC', 'saveDC', 'saveBitMap', 'bmpinfo', 'bmpstr', 'img', 'e']
     `266` ['self', 'x', 'y', 'button', 'rect', 'client_rect', 'border_x', 'border_y', 'screen_x', 'screen_y', 'top_right_x', 'top_right_y', 'e']
     `267` ['self', 'garbage_info', 'garbage_name', 'garbage_x', 'garbage_y', 'garbage_num', 'key_to_press', 'e']
     `268` ['self', 'screenshot', 'found_garbage', 'garbage_types_to_search', 'garbage_key', 'matches', 'i', 'x', 'y', 'conf', 'garbage_info']
     `269` ['self', 'screenshot', 'template', 'roi', 'search_area', 'offset_x', 'offset_y', 'result', 'locations', 'matches', 'h', 'w', 'pt', 'confidence', 'center_x', 'center_y']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__garbage_disposal\23e79f360_GarbageDisposal.dispose_garbage_by_position.c`

### `GarbageDisposal.run`

- implementation: `FUN_23e7a1d20`
- source line hint: `443`
- Nuitka codevar: `DAT_23eedabc8`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `248` 'find_template'
     `249` 'GarbageDisposal.find_template'
     `250` 'GarbageDisposal.find_all_template_matches'
     `251` {'__dict_items__': [['matches', {'__builtin__': 'list'}], ['template_w', {'__builtin__': 'int'}], ['template_h', {'__builtin__': 'int'}], ['return', {'__builtin__': 'list'}]]}
     `252` 'GarbageDisposal.remove_overlapping_matches'
     `253` 'GarbageDisposal.find_all_garbage'
     `254` {'__dict_items__': [['garbage_info', {'__builtin__': 'dict'}], ['return', {'__builtin__': 'bool'}]]}
     `255` 'GarbageDisposal.dispose_garbage_by_position'
  => `256` 'GarbageDisposal.run'
     `257` 'main'
     `258` 'workers\\fishing\\garbage_disposal.py'
     `259` ['x']
     `260` '<module workers.fishing.garbage_disposal>'
     `261` ['__class__']
     `262` ['self']
     `263` ['self', 'process_name']
     `264` ['hwnd', 'hwnds', '_', 'pid', 'process', 'self']
     `265` ['self', 'left', 'top', 'right', 'bottom', 'width', 'height', 'hwndDC', 'mfcDC', 'saveDC', 'saveBitMap', 'bmpinfo', 'bmpstr', 'img', 'e']
     `266` ['self', 'x', 'y', 'button', 'rect', 'client_rect', 'border_x', 'border_y', 'screen_x', 'screen_y', 'top_right_x', 'top_right_y', 'e']
     `267` ['self', 'garbage_info', 'garbage_name', 'garbage_x', 'garbage_y', 'garbage_num', 'key_to_press', 'e']
     `268` ['self', 'screenshot', 'found_garbage', 'garbage_types_to_search', 'garbage_key', 'matches', 'i', 'x', 'y', 'conf', 'garbage_info']
     `269` ['self', 'screenshot', 'template', 'roi', 'search_area', 'offset_x', 'offset_y', 'result', 'locations', 'matches', 'h', 'w', 'pt', 'confidence', 'center_x', 'center_y']
     `270` ['self', 'screenshot', 'template', 'roi', 'search_area', 'result', 'min_val', 'max_val', 'min_loc', 'max_loc', 'h', 'w', 'center_x', 'center_y']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__garbage_disposal\23e7a1d20_GarbageDisposal.run.c`

### `?`

- implementation: `FUN_23e7a6340`
- source line hint: `501`
- Nuitka codevar: `uVar9`
- factory: `FUN_23e93df40`
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__garbage_disposal\23e7a6340_unknown.c`
