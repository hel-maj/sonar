# Function Specification: `workers.fishing.store_fish`

This is a reconstruction dossier from static Nuitka constants and Ghidra decompilation. It is not original Python source text.

## Source Path Hints
- `workers\fishing\store_fish.py`

## Docstrings / Long Text
- `125` '\n        Найти шаблон на скриншоте\n        Возвращает (найдено, x_центр, y_центр, уверенность)\n        '
- `137` '\n        Найти все рыбы на скриншоте один раз и запомнить их позиции\n        Возвращает список словарей с информацией о найденных рыбах\n        '
- `138` '\n🐟 Обработка: '
- `154` '\n        Убрать рыбу в рюкзак по заранее известной позиции\n        Возвращает True если успешно\n        '
- `170` '\n✅ Найдено рыб: '
- `171` '\n['
- `190` '\nGTA5 Store Fish - Автоматическое убирание рыбы в рюкзак\n'

## Function Inventory
| Inferred qualname | Impl | Source line | Arg count | Decompiled C |
|---|---:|---:|---:|---|
| `remove.png` | `LAB_23e828a20` | 33 | 2 | yes |
| `WindowCapture.__init__` | `FUN_23e828ef0` | 37 | uVar8 | yes |
| `WindowCapture.find_window_by_process` | `FUN_23e82ad30` | 63 | uVar8 | yes |
| `WindowCapture.get_window_size` | `FUN_23e887a60` | 71 | uVar8 | yes |
| `WindowCapture.capture` | `FUN_23e82ba40` | 109 | uVar8 | yes |
| `WindowCapture.click_at` | `FUN_23e82e4a0` | 155 | 1 | yes |
| `FishStorer.__init__` | `FUN_23e88aa80` | 163 | uVar8 | yes |
| `FishStorer.initialize` | `FUN_23e88c3c0` | 198 | uVar22 | yes |
| `FishStorer.load_templates` | `FUN_23e88f040` | 243 | uVar8 | yes |
| `FishStorer.find_template` | `FUN_23e891f10` | 288 | uVar8 | yes |
| `FishStorer.find_all_fish` | `FUN_23e893cf0` | 314 | 2 | yes |
| `FishStorer.store_fish_by_position` | `FUN_23e896660` | 362 | 1 | yes |
| `FishStorer.run` | `FUN_23e82edd0` | 422 | uVar22&0xffffffff00000000 | yes |

## Local Variable Lists
- `235` `__class__`
- `236` `self`
- `237` `self, process_name`
- `238` `hwnd, hwnds, _, pid, process, self`
- `239` `self, left, top, right, bottom, width, height, hwndDC, mfcDC, saveDC, saveBitMap, bmpinfo, bmpstr, img, e`
- `240` `self, x, y, button, rect, client_rect, border_x, border_y, screen_x, screen_y, win32api, original_pos, e`
- `241` `self, screenshot, found_fish, fish_template, found, fish_x, fish_y, confidence, fish_info`
- `242` `self, screenshot, template, roi, search_area, search_gray, template_gray, result, min_val, max_val, min_loc, max_loc, h, w, center_x, center_y`
- `243` `self, callback, hwnds, hwnd, title`
- `244` `self, left, top, right, bottom`
- `245` `self, width, height`
- `246` `self, template_path, remove_path, fish_count, file_path, template`
- `248` `self, stored_count, screenshot, fish_positions, i, fish_info`
- `249` `self, fish_info, fish_name, fish_x, fish_y, new_screenshot, found_remove, remove_x, remove_y, remove_conf`

## Structured Constants
- `16` [0, 0]
- `31` [True]
- `58` [0.05]
- `110` {'__slice__': [None, 2, None]}
- `173` {'__dict_items__': [['end', '']]}
- `177` [0.3]
- `201` {'__dict_items__': [['x', 1077], ['y', 90], ['width', 538], ['height', 986]]}
- `202` {'__dict_items__': [['x', 1436], ['y', 99], ['width', 717], ['height', 1341]]}
- `209` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
- `211` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
- `213` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
- `219` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['button', {'__builtin__': 'str'}]]}
- `225` [None]
- `229` {'__dict_items__': [['fish_info', {'__builtin__': 'dict'}], ['return', {'__builtin__': 'bool'}]]}

## Per-Function Context
### `remove.png`

- implementation: `LAB_23e828a20`
- source line hint: `33`
- Nuitka codevar: `DAT_23eede700`
- factory: `FUN_23e93e480`
- nearby constants:
     `97` ', Width='
     `98` 'width'
     `99` ', Height='
     `100` 'height'
     `101` 'load_templates'
     `102` 'Инициализация системы'
     `103` '❌ Папка с шаблонами не найдена: '
     `104` 'Загрузка шаблонов из: '
  => `105` 'remove.png'
     `106` ['❌ Файл remove.png не найден!']
     `107` 'imread'
     `108` ['❌ Не удалось загрузить remove.png']
     `109` '✓ Загружен шаблон remove.png '
     `110` {'__slice__': [None, 2, None]}
     `111` 'glob'
     `112` ['*.png']
     `113` 'stem'
     `114` 'image'
     `115` 'fish_count'
     `116` '✓ Загружено '
     `117` ' шаблонов рыб'
     `118` ['❌ Не найдено ни одного шаблона рыбы!']
     `119` 'Загрузить шаблоны изображений рыб и кнопки remove'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__store_fish\23e828a20_remove.png.c`

### `WindowCapture.__init__`

- implementation: `FUN_23e828ef0`
- source line hint: `37`
- Nuitka codevar: `DAT_23eede6f0`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `202` {'__dict_items__': [['x', 1436], ['y', 99], ['width', 717], ['height', 1341]]}
     `203` 0.9
     `204` 0.1
     `205` 0.5
     `206` 'workers.fishing.store_fish'
     `207` 'Захват скриншотов окна по имени процесса'
     `208` '__qualname__'
     `209` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
  => `210` 'WindowCapture.__init__'
     `211` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `212` 'WindowCapture.find_window_by_process'
     `213` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `214` 'WindowCapture.get_window_size'
     `215` 'return'
     `216` 'ndarray'
     `217` 'WindowCapture.capture'
     `218` ['left']
     `219` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['button', {'__builtin__': 'str'}]]}
     `220` 'WindowCapture.click_at'
     `221` 'Класс для автоматического убирания рыбы в рюкзак'
     `222` 'FishStorer.__init__'
     `223` 'FishStorer.initialize'
     `224` 'FishStorer.load_templates'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__store_fish\23e828ef0_WindowCapture.__init.c`

### `WindowCapture.find_window_by_process`

- implementation: `FUN_23e82ad30`
- source line hint: `63`
- Nuitka codevar: `DAT_23eede6c0`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `204` 0.1
     `205` 0.5
     `206` 'workers.fishing.store_fish'
     `207` 'Захват скриншотов окна по имени процесса'
     `208` '__qualname__'
     `209` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
     `210` 'WindowCapture.__init__'
     `211` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
  => `212` 'WindowCapture.find_window_by_process'
     `213` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `214` 'WindowCapture.get_window_size'
     `215` 'return'
     `216` 'ndarray'
     `217` 'WindowCapture.capture'
     `218` ['left']
     `219` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['button', {'__builtin__': 'str'}]]}
     `220` 'WindowCapture.click_at'
     `221` 'Класс для автоматического убирания рыбы в рюкзак'
     `222` 'FishStorer.__init__'
     `223` 'FishStorer.initialize'
     `224` 'FishStorer.load_templates'
     `225` [None]
     `226` 'template'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__store_fish\23e82ad30_WindowCapture.find_window_by_process.c`

### `WindowCapture.get_window_size`

- implementation: `FUN_23e887a60`
- source line hint: `71`
- Nuitka codevar: `_DAT_23eede6b0`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `206` 'workers.fishing.store_fish'
     `207` 'Захват скриншотов окна по имени процесса'
     `208` '__qualname__'
     `209` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
     `210` 'WindowCapture.__init__'
     `211` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `212` 'WindowCapture.find_window_by_process'
     `213` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
  => `214` 'WindowCapture.get_window_size'
     `215` 'return'
     `216` 'ndarray'
     `217` 'WindowCapture.capture'
     `218` ['left']
     `219` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['button', {'__builtin__': 'str'}]]}
     `220` 'WindowCapture.click_at'
     `221` 'Класс для автоматического убирания рыбы в рюкзак'
     `222` 'FishStorer.__init__'
     `223` 'FishStorer.initialize'
     `224` 'FishStorer.load_templates'
     `225` [None]
     `226` 'template'
     `227` 'FishStorer.find_template'
     `228` 'FishStorer.find_all_fish'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__store_fish\23e887a60_WindowCapture.get_window_size.c`

### `WindowCapture.capture`

- implementation: `FUN_23e82ba40`
- source line hint: `109`
- Nuitka codevar: `_DAT_23eede698`
- factory: `FUN_23e93e480`
- nearby constants:
     `209` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
     `210` 'WindowCapture.__init__'
     `211` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `212` 'WindowCapture.find_window_by_process'
     `213` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `214` 'WindowCapture.get_window_size'
     `215` 'return'
     `216` 'ndarray'
  => `217` 'WindowCapture.capture'
     `218` ['left']
     `219` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['button', {'__builtin__': 'str'}]]}
     `220` 'WindowCapture.click_at'
     `221` 'Класс для автоматического убирания рыбы в рюкзак'
     `222` 'FishStorer.__init__'
     `223` 'FishStorer.initialize'
     `224` 'FishStorer.load_templates'
     `225` [None]
     `226` 'template'
     `227` 'FishStorer.find_template'
     `228` 'FishStorer.find_all_fish'
     `229` {'__dict_items__': [['fish_info', {'__builtin__': 'dict'}], ['return', {'__builtin__': 'bool'}]]}
     `230` 'FishStorer.store_fish_by_position'
     `231` 'FishStorer.run'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__store_fish\23e82ba40_WindowCapture.capture.c`

### `WindowCapture.click_at`

- implementation: `FUN_23e82e4a0`
- source line hint: `155`
- Nuitka codevar: `_DAT_23eede688`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `212` 'WindowCapture.find_window_by_process'
     `213` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `214` 'WindowCapture.get_window_size'
     `215` 'return'
     `216` 'ndarray'
     `217` 'WindowCapture.capture'
     `218` ['left']
     `219` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['button', {'__builtin__': 'str'}]]}
  => `220` 'WindowCapture.click_at'
     `221` 'Класс для автоматического убирания рыбы в рюкзак'
     `222` 'FishStorer.__init__'
     `223` 'FishStorer.initialize'
     `224` 'FishStorer.load_templates'
     `225` [None]
     `226` 'template'
     `227` 'FishStorer.find_template'
     `228` 'FishStorer.find_all_fish'
     `229` {'__dict_items__': [['fish_info', {'__builtin__': 'dict'}], ['return', {'__builtin__': 'bool'}]]}
     `230` 'FishStorer.store_fish_by_position'
     `231` 'FishStorer.run'
     `232` 'main'
     `233` 'workers\\fishing\\store_fish.py'
     `234` '<module workers.fishing.store_fish>'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__store_fish\23e82e4a0_WindowCapture.click_at.c`

### `FishStorer.__init__`

- implementation: `FUN_23e88aa80`
- source line hint: `163`
- Nuitka codevar: `DAT_23eede668`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `214` 'WindowCapture.get_window_size'
     `215` 'return'
     `216` 'ndarray'
     `217` 'WindowCapture.capture'
     `218` ['left']
     `219` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['button', {'__builtin__': 'str'}]]}
     `220` 'WindowCapture.click_at'
     `221` 'Класс для автоматического убирания рыбы в рюкзак'
  => `222` 'FishStorer.__init__'
     `223` 'FishStorer.initialize'
     `224` 'FishStorer.load_templates'
     `225` [None]
     `226` 'template'
     `227` 'FishStorer.find_template'
     `228` 'FishStorer.find_all_fish'
     `229` {'__dict_items__': [['fish_info', {'__builtin__': 'dict'}], ['return', {'__builtin__': 'bool'}]]}
     `230` 'FishStorer.store_fish_by_position'
     `231` 'FishStorer.run'
     `232` 'main'
     `233` 'workers\\fishing\\store_fish.py'
     `234` '<module workers.fishing.store_fish>'
     `235` ['__class__']
     `236` ['self']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__store_fish\23e88aa80_FishStorer.__init.c`

### `FishStorer.initialize`

- implementation: `FUN_23e88c3c0`
- source line hint: `198`
- Nuitka codevar: `_DAT_23eede648`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `215` 'return'
     `216` 'ndarray'
     `217` 'WindowCapture.capture'
     `218` ['left']
     `219` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['button', {'__builtin__': 'str'}]]}
     `220` 'WindowCapture.click_at'
     `221` 'Класс для автоматического убирания рыбы в рюкзак'
     `222` 'FishStorer.__init__'
  => `223` 'FishStorer.initialize'
     `224` 'FishStorer.load_templates'
     `225` [None]
     `226` 'template'
     `227` 'FishStorer.find_template'
     `228` 'FishStorer.find_all_fish'
     `229` {'__dict_items__': [['fish_info', {'__builtin__': 'dict'}], ['return', {'__builtin__': 'bool'}]]}
     `230` 'FishStorer.store_fish_by_position'
     `231` 'FishStorer.run'
     `232` 'main'
     `233` 'workers\\fishing\\store_fish.py'
     `234` '<module workers.fishing.store_fish>'
     `235` ['__class__']
     `236` ['self']
     `237` ['self', 'process_name']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__store_fish\23e88c3c0_FishStorer.initialize.c`

### `FishStorer.load_templates`

- implementation: `FUN_23e88f040`
- source line hint: `243`
- Nuitka codevar: `uVar2`
- factory: `FUN_23e93e480`
- nearby constants:
     `216` 'ndarray'
     `217` 'WindowCapture.capture'
     `218` ['left']
     `219` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['button', {'__builtin__': 'str'}]]}
     `220` 'WindowCapture.click_at'
     `221` 'Класс для автоматического убирания рыбы в рюкзак'
     `222` 'FishStorer.__init__'
     `223` 'FishStorer.initialize'
  => `224` 'FishStorer.load_templates'
     `225` [None]
     `226` 'template'
     `227` 'FishStorer.find_template'
     `228` 'FishStorer.find_all_fish'
     `229` {'__dict_items__': [['fish_info', {'__builtin__': 'dict'}], ['return', {'__builtin__': 'bool'}]]}
     `230` 'FishStorer.store_fish_by_position'
     `231` 'FishStorer.run'
     `232` 'main'
     `233` 'workers\\fishing\\store_fish.py'
     `234` '<module workers.fishing.store_fish>'
     `235` ['__class__']
     `236` ['self']
     `237` ['self', 'process_name']
     `238` ['hwnd', 'hwnds', '_', 'pid', 'process', 'self']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__store_fish\23e88f040_FishStorer.load_templates.c`

### `FishStorer.find_template`

- implementation: `FUN_23e891f10`
- source line hint: `288`
- Nuitka codevar: `_DAT_23eede620`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `219` {'__dict_items__': [['x', {'__builtin__': 'int'}], ['y', {'__builtin__': 'int'}], ['button', {'__builtin__': 'str'}]]}
     `220` 'WindowCapture.click_at'
     `221` 'Класс для автоматического убирания рыбы в рюкзак'
     `222` 'FishStorer.__init__'
     `223` 'FishStorer.initialize'
     `224` 'FishStorer.load_templates'
     `225` [None]
     `226` 'template'
  => `227` 'FishStorer.find_template'
     `228` 'FishStorer.find_all_fish'
     `229` {'__dict_items__': [['fish_info', {'__builtin__': 'dict'}], ['return', {'__builtin__': 'bool'}]]}
     `230` 'FishStorer.store_fish_by_position'
     `231` 'FishStorer.run'
     `232` 'main'
     `233` 'workers\\fishing\\store_fish.py'
     `234` '<module workers.fishing.store_fish>'
     `235` ['__class__']
     `236` ['self']
     `237` ['self', 'process_name']
     `238` ['hwnd', 'hwnds', '_', 'pid', 'process', 'self']
     `239` ['self', 'left', 'top', 'right', 'bottom', 'width', 'height', 'hwndDC', 'mfcDC', 'saveDC', 'saveBitMap', 'bmpinfo', 'bmpstr', 'img', 'e']
     `240` ['self', 'x', 'y', 'button', 'rect', 'client_rect', 'border_x', 'border_y', 'screen_x', 'screen_y', 'win32api', 'original_pos', 'e']
     `241` ['self', 'screenshot', 'found_fish', 'fish_template', 'found', 'fish_x', 'fish_y', 'confidence', 'fish_info']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__store_fish\23e891f10_FishStorer.find_template.c`

### `FishStorer.find_all_fish`

- implementation: `FUN_23e893cf0`
- source line hint: `314`
- Nuitka codevar: `_DAT_23eede610`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `220` 'WindowCapture.click_at'
     `221` 'Класс для автоматического убирания рыбы в рюкзак'
     `222` 'FishStorer.__init__'
     `223` 'FishStorer.initialize'
     `224` 'FishStorer.load_templates'
     `225` [None]
     `226` 'template'
     `227` 'FishStorer.find_template'
  => `228` 'FishStorer.find_all_fish'
     `229` {'__dict_items__': [['fish_info', {'__builtin__': 'dict'}], ['return', {'__builtin__': 'bool'}]]}
     `230` 'FishStorer.store_fish_by_position'
     `231` 'FishStorer.run'
     `232` 'main'
     `233` 'workers\\fishing\\store_fish.py'
     `234` '<module workers.fishing.store_fish>'
     `235` ['__class__']
     `236` ['self']
     `237` ['self', 'process_name']
     `238` ['hwnd', 'hwnds', '_', 'pid', 'process', 'self']
     `239` ['self', 'left', 'top', 'right', 'bottom', 'width', 'height', 'hwndDC', 'mfcDC', 'saveDC', 'saveBitMap', 'bmpinfo', 'bmpstr', 'img', 'e']
     `240` ['self', 'x', 'y', 'button', 'rect', 'client_rect', 'border_x', 'border_y', 'screen_x', 'screen_y', 'win32api', 'original_pos', 'e']
     `241` ['self', 'screenshot', 'found_fish', 'fish_template', 'found', 'fish_x', 'fish_y', 'confidence', 'fish_info']
     `242` ['self', 'screenshot', 'template', 'roi', 'search_area', 'search_gray', 'template_gray', 'result', 'min_val', 'max_val', 'min_loc', 'max_loc', 'h', 'w', 'center_x', 'center_y']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__store_fish\23e893cf0_FishStorer.find_all_fish.c`

### `FishStorer.store_fish_by_position`

- implementation: `FUN_23e896660`
- source line hint: `362`
- Nuitka codevar: `_DAT_23eede5f0`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `222` 'FishStorer.__init__'
     `223` 'FishStorer.initialize'
     `224` 'FishStorer.load_templates'
     `225` [None]
     `226` 'template'
     `227` 'FishStorer.find_template'
     `228` 'FishStorer.find_all_fish'
     `229` {'__dict_items__': [['fish_info', {'__builtin__': 'dict'}], ['return', {'__builtin__': 'bool'}]]}
  => `230` 'FishStorer.store_fish_by_position'
     `231` 'FishStorer.run'
     `232` 'main'
     `233` 'workers\\fishing\\store_fish.py'
     `234` '<module workers.fishing.store_fish>'
     `235` ['__class__']
     `236` ['self']
     `237` ['self', 'process_name']
     `238` ['hwnd', 'hwnds', '_', 'pid', 'process', 'self']
     `239` ['self', 'left', 'top', 'right', 'bottom', 'width', 'height', 'hwndDC', 'mfcDC', 'saveDC', 'saveBitMap', 'bmpinfo', 'bmpstr', 'img', 'e']
     `240` ['self', 'x', 'y', 'button', 'rect', 'client_rect', 'border_x', 'border_y', 'screen_x', 'screen_y', 'win32api', 'original_pos', 'e']
     `241` ['self', 'screenshot', 'found_fish', 'fish_template', 'found', 'fish_x', 'fish_y', 'confidence', 'fish_info']
     `242` ['self', 'screenshot', 'template', 'roi', 'search_area', 'search_gray', 'template_gray', 'result', 'min_val', 'max_val', 'min_loc', 'max_loc', 'h', 'w', 'center_x', 'center_y']
     `243` ['self', 'callback', 'hwnds', 'hwnd', 'title']
     `244` ['self', 'left', 'top', 'right', 'bottom']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__store_fish\23e896660_FishStorer.store_fish_by_position.c`

### `FishStorer.run`

- implementation: `FUN_23e82edd0`
- source line hint: `422`
- Nuitka codevar: `_DAT_23eede5e0`
- factory: `FUN_23e93df40`
- nearby constants:
     `223` 'FishStorer.initialize'
     `224` 'FishStorer.load_templates'
     `225` [None]
     `226` 'template'
     `227` 'FishStorer.find_template'
     `228` 'FishStorer.find_all_fish'
     `229` {'__dict_items__': [['fish_info', {'__builtin__': 'dict'}], ['return', {'__builtin__': 'bool'}]]}
     `230` 'FishStorer.store_fish_by_position'
  => `231` 'FishStorer.run'
     `232` 'main'
     `233` 'workers\\fishing\\store_fish.py'
     `234` '<module workers.fishing.store_fish>'
     `235` ['__class__']
     `236` ['self']
     `237` ['self', 'process_name']
     `238` ['hwnd', 'hwnds', '_', 'pid', 'process', 'self']
     `239` ['self', 'left', 'top', 'right', 'bottom', 'width', 'height', 'hwndDC', 'mfcDC', 'saveDC', 'saveBitMap', 'bmpinfo', 'bmpstr', 'img', 'e']
     `240` ['self', 'x', 'y', 'button', 'rect', 'client_rect', 'border_x', 'border_y', 'screen_x', 'screen_y', 'win32api', 'original_pos', 'e']
     `241` ['self', 'screenshot', 'found_fish', 'fish_template', 'found', 'fish_x', 'fish_y', 'confidence', 'fish_info']
     `242` ['self', 'screenshot', 'template', 'roi', 'search_area', 'search_gray', 'template_gray', 'result', 'min_val', 'max_val', 'min_loc', 'max_loc', 'h', 'w', 'center_x', 'center_y']
     `243` ['self', 'callback', 'hwnds', 'hwnd', 'title']
     `244` ['self', 'left', 'top', 'right', 'bottom']
     `245` ['self', 'width', 'height']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__store_fish\23e82edd0_FishStorer.run.c`
