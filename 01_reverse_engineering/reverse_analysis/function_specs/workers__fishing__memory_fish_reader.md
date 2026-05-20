# Function Specification: `workers.fishing.memory_fish_reader`

This is a reconstruction dossier from static Nuitka constants and Ghidra decompilation. It is not original Python source text.

## Source Path Hints
- `workers\fishing\memory_fish_reader.py`

## Docstrings / Long Text
- `78` 'Строит маппинг: русское_название → eng_key.\n    Сначала пробует FISH_NAMES из telegram/handlers, потом fish_names231.txt.'
- `113` '\n        Ждать нового улова до timeout секунд.\n        Возвращает (eng_key, ru_name, weight) или None.\n        eng_key — ключ для сравнения с fish_to_keep/fish_to_release.\n        '
- `127` '\nЧтение пойманной рыбы из памяти majestic-webengine.\nИспользуется в fishing_bot.py вместо CV-распознавания.\n\nСтратегия: count-based — срабатывает только когда в памяти\nпоявляется НОВАЯ запись об улове (count увеличился).\n'
- `161` '\n    Фоновый монитор памяти webengine.\n    Запускается как daemon-поток, обнаруживает новые уловы\n    и кладёт их в очередь `_new_catches`.\n\n    Использование:\n        reader = MemoryFishReader()\n        reader.start()\n        reader.wait_ready()          # ждём Фазу 1\n\n        # В цикле рыбалки:\n        reader.clear_pending()       # сбросить старые уловы перед ожиданием\n        catch = reader.wait_catch(timeout=10.0)  # (eng_key, ru_name, weight) или None\n        reader.stop()...

## Function Inventory
| Inferred qualname | Impl | Source line | Arg count | Decompiled C |
|---|---:|---:|---:|---|
| `fish_names231.txt` | `FUN_23e7e1110` | 45 | uVar27&0xffffffff00000000 | yes |
| `MemoryFishReader.__init__` | `FUN_23e7e24b0` | 58 | 1 | yes |
| `MemoryFishReader.start` | `FUN_23e876760` | 63 | 3 | yes |
| `MemoryFishReader.stop` | `FUN_23e7e2d00` | 71 | 1 | yes |
| `MemoryFishReader.wait_ready` | `FUN_23e7e6b30` | 99 | uVar27 | yes |
| `MemoryFishReader.clear_pending` | `FUN_23e7eaea0` | 126 | uVar27 | yes |
| `MemoryFishReader.wait_catch` | `FUN_23e7ee8c0` | 165 | uVar27 | yes |
| `MemoryFishReader._run` | `FUN_23e7ef2c0` | 175 | 1 | yes |
| `?` | `FUN_23e7f0b40` | 194 | 1 | yes |
| `?` | `FUN_23e7f1ee0` | 208 | 2 | yes |
| `?` | `FUN_23e7f2380` | 213 | 1 | yes |
| `?` | `FUN_23e7f3420` | 219 | 2 | yes |
| `?` | `FUN_23e7f5660` | 241 | 1 | yes |
| `?` | `FUN_23e7e4bc0` | ? | ? | yes |
| `?` | `FUN_23e7e8670` | ? | ? | yes |

## Local Variable Lists
- `179` `__class__`
- `180` `self`
- `189` `self, pids, targets, pid, h, regions, base, size, known_counts, current_counts, new_items, key, cnt, ru_name, weight, eng_key, _`
- `190` `self, timeout, deadline, remaining, result`
- `191` `self, timeout`

## Structured Constants
- `5` [['powershell', '-Command', 'Get-Process majestic-webengine | Select-Object -ExpandProperty Id']]
- `16` [0]
- `51` [1]
- `54` [2]
- `77` [None, None, None]
- `94` [1.5]
- `126` [0.1]
- `160` [524288]
- `167` [90.0]
- `168` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
- `173` [10.0]

## Per-Function Context
### `fish_names231.txt`

- implementation: `FUN_23e7e1110`
- source line hint: `45`
- Nuitka codevar: `_DAT_23eedebb8`
- factory: `FUN_23e93df40`
- nearby constants:
     `63` ':'
     `64` 'counts'
     `65` 'telegram.handlers.fish_names_map'
     `66` ['FISH_NAMES']
     `67` 'FISH_NAMES'
     `68` 'items'
     `69` 'Path'
     `70` 'tools'
  => `71` 'fish_names231.txt'
     `72` 'utf-8'
     `73` '\t'
     `74` ['\t', 1]
     `75` ['.png', '']
     `76` 'ru_to_eng'
     `77` [None, None, None]
     `78` 'Строит маппинг: русское_название → eng_key.\n    Сначала пробует FISH_NAMES из telegram/handlers, потом fish_names231.txt.'
     `79` '_build_reverse_map'
     `80` '_ru_to_eng'
     `81` 'threading'
     `82` 'Lock'
     `83` '_lock'
     `84` '_new_catches'
     `85` 'Event'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__memory_fish_reader\23e7e1110_fish_names231.txt.c`

### `MemoryFishReader.__init__`

- implementation: `FUN_23e7e24b0`
- source line hint: `58`
- Nuitka codevar: `_DAT_23eedeba8`
- factory: `FUN_23e93df40`
- nearby constants:
     `155` 'PartitionId'
     `156` 'WORD'
     `157` 'Type'
     `158` '_fields_'
     `159` '__orig_bases__'
     `160` [524288]
     `161` '\n    Фоновый монитор памяти webengine.\n    Запускается как daemon-поток, обнаруживает новые уловы\n    и кладёт их в очередь `_new_catches`.\n\n    Использование:\n        reader = MemoryFishReader()\n        reader.start()\n        reader.wait_ready()          # ждём Фазу ...
     `162` 'MemoryFishReader'
  => `163` 'MemoryFishReader.__init__'
     `164` 'MemoryFishReader.start'
     `165` 'stop'
     `166` 'MemoryFishReader.stop'
     `167` [90.0]
     `168` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `169` 'wait_ready'
     `170` 'MemoryFishReader.wait_ready'
     `171` 'clear_pending'
     `172` 'MemoryFishReader.clear_pending'
     `173` [10.0]
     `174` 'wait_catch'
     `175` 'MemoryFishReader.wait_catch'
     `176` 'MemoryFishReader._run'
     `177` 'workers\\fishing\\memory_fish_reader.py'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__memory_fish_reader\23e7e24b0_MemoryFishReader.__init.c`

### `MemoryFishReader.start`

- implementation: `FUN_23e876760`
- source line hint: `63`
- Nuitka codevar: `_DAT_23eedeb88`
- factory: `FUN_23e93df40`
- nearby constants:
     `156` 'WORD'
     `157` 'Type'
     `158` '_fields_'
     `159` '__orig_bases__'
     `160` [524288]
     `161` '\n    Фоновый монитор памяти webengine.\n    Запускается как daemon-поток, обнаруживает новые уловы\n    и кладёт их в очередь `_new_catches`.\n\n    Использование:\n        reader = MemoryFishReader()\n        reader.start()\n        reader.wait_ready()          # ждём Фазу ...
     `162` 'MemoryFishReader'
     `163` 'MemoryFishReader.__init__'
  => `164` 'MemoryFishReader.start'
     `165` 'stop'
     `166` 'MemoryFishReader.stop'
     `167` [90.0]
     `168` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `169` 'wait_ready'
     `170` 'MemoryFishReader.wait_ready'
     `171` 'clear_pending'
     `172` 'MemoryFishReader.clear_pending'
     `173` [10.0]
     `174` 'wait_catch'
     `175` 'MemoryFishReader.wait_catch'
     `176` 'MemoryFishReader._run'
     `177` 'workers\\fishing\\memory_fish_reader.py'
     `178` '<module workers.fishing.memory_fish_reader>'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__memory_fish_reader\23e876760_MemoryFishReader.start.c`

### `MemoryFishReader.stop`

- implementation: `FUN_23e7e2d00`
- source line hint: `71`
- Nuitka codevar: `_DAT_23eedeb80`
- factory: `FUN_23e93df40`
- nearby constants:
     `158` '_fields_'
     `159` '__orig_bases__'
     `160` [524288]
     `161` '\n    Фоновый монитор памяти webengine.\n    Запускается как daemon-поток, обнаруживает новые уловы\n    и кладёт их в очередь `_new_catches`.\n\n    Использование:\n        reader = MemoryFishReader()\n        reader.start()\n        reader.wait_ready()          # ждём Фазу ...
     `162` 'MemoryFishReader'
     `163` 'MemoryFishReader.__init__'
     `164` 'MemoryFishReader.start'
     `165` 'stop'
  => `166` 'MemoryFishReader.stop'
     `167` [90.0]
     `168` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `169` 'wait_ready'
     `170` 'MemoryFishReader.wait_ready'
     `171` 'clear_pending'
     `172` 'MemoryFishReader.clear_pending'
     `173` [10.0]
     `174` 'wait_catch'
     `175` 'MemoryFishReader.wait_catch'
     `176` 'MemoryFishReader._run'
     `177` 'workers\\fishing\\memory_fish_reader.py'
     `178` '<module workers.fishing.memory_fish_reader>'
     `179` ['__class__']
     `180` ['self']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__memory_fish_reader\23e7e2d00_MemoryFishReader.stop.c`

### `MemoryFishReader.wait_ready`

- implementation: `FUN_23e7e6b30`
- source line hint: `99`
- Nuitka codevar: `_DAT_23eedeb30`
- factory: `FUN_23e93df40`
- nearby constants:
     `162` 'MemoryFishReader'
     `163` 'MemoryFishReader.__init__'
     `164` 'MemoryFishReader.start'
     `165` 'stop'
     `166` 'MemoryFishReader.stop'
     `167` [90.0]
     `168` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `169` 'wait_ready'
  => `170` 'MemoryFishReader.wait_ready'
     `171` 'clear_pending'
     `172` 'MemoryFishReader.clear_pending'
     `173` [10.0]
     `174` 'wait_catch'
     `175` 'MemoryFishReader.wait_catch'
     `176` 'MemoryFishReader._run'
     `177` 'workers\\fishing\\memory_fish_reader.py'
     `178` '<module workers.fishing.memory_fish_reader>'
     `179` ['__class__']
     `180` ['self']
     `181` ['FISH_NAMES', 'ru_to_eng', 'names_file', 'f', 'line', 'png_name', 'ru_name']
     `182` ['targets', 'chunk', 'counts', '_pid', 'h', 'base', 'size', 'offset', 'data', 'fish', 'weight', 'key']
     `183` ['handle', 'needle', 'chunk', 'found', 'base', 'size', 'offset', 'data']
     `184` ['data', 'text', 'result', 'm', 'fish', 'weight']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__memory_fish_reader\23e7e6b30_MemoryFishReader.wait_ready.c`

### `MemoryFishReader.clear_pending`

- implementation: `FUN_23e7eaea0`
- source line hint: `126`
- Nuitka codevar: `DAT_23eedeb00`
- factory: `FUN_23e93df40`
- nearby constants:
     `164` 'MemoryFishReader.start'
     `165` 'stop'
     `166` 'MemoryFishReader.stop'
     `167` [90.0]
     `168` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `169` 'wait_ready'
     `170` 'MemoryFishReader.wait_ready'
     `171` 'clear_pending'
  => `172` 'MemoryFishReader.clear_pending'
     `173` [10.0]
     `174` 'wait_catch'
     `175` 'MemoryFishReader.wait_catch'
     `176` 'MemoryFishReader._run'
     `177` 'workers\\fishing\\memory_fish_reader.py'
     `178` '<module workers.fishing.memory_fish_reader>'
     `179` ['__class__']
     `180` ['self']
     `181` ['FISH_NAMES', 'ru_to_eng', 'names_file', 'f', 'line', 'png_name', 'ru_name']
     `182` ['targets', 'chunk', 'counts', '_pid', 'h', 'base', 'size', 'offset', 'data', 'fish', 'weight', 'key']
     `183` ['handle', 'needle', 'chunk', 'found', 'base', 'size', 'offset', 'data']
     `184` ['data', 'text', 'result', 'm', 'fish', 'weight']
     `185` ['out']
     `186` ['handle', 'mbi', 'addr']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__memory_fish_reader\23e7eaea0_MemoryFishReader.clear_pending.c`

### `MemoryFishReader.wait_catch`

- implementation: `FUN_23e7ee8c0`
- source line hint: `165`
- Nuitka codevar: `_DAT_23eedeae0`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `167` [90.0]
     `168` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `169` 'wait_ready'
     `170` 'MemoryFishReader.wait_ready'
     `171` 'clear_pending'
     `172` 'MemoryFishReader.clear_pending'
     `173` [10.0]
     `174` 'wait_catch'
  => `175` 'MemoryFishReader.wait_catch'
     `176` 'MemoryFishReader._run'
     `177` 'workers\\fishing\\memory_fish_reader.py'
     `178` '<module workers.fishing.memory_fish_reader>'
     `179` ['__class__']
     `180` ['self']
     `181` ['FISH_NAMES', 'ru_to_eng', 'names_file', 'f', 'line', 'png_name', 'ru_name']
     `182` ['targets', 'chunk', 'counts', '_pid', 'h', 'base', 'size', 'offset', 'data', 'fish', 'weight', 'key']
     `183` ['handle', 'needle', 'chunk', 'found', 'base', 'size', 'offset', 'data']
     `184` ['data', 'text', 'result', 'm', 'fish', 'weight']
     `185` ['out']
     `186` ['handle', 'mbi', 'addr']
     `187` ['pid', 'h']
     `188` ['handle', 'addr', 'size', 'buf', 'read']
     `189` ['self', 'pids', 'targets', 'pid', 'h', 'regions', 'base', 'size', 'known_counts', 'current_counts', 'new_items', 'key', 'cnt', 'ru_name', 'weight', 'eng_key', '_']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__memory_fish_reader\23e7ee8c0_MemoryFishReader.wait_catch.c`

### `MemoryFishReader._run`

- implementation: `FUN_23e7ef2c0`
- source line hint: `175`
- Nuitka codevar: `_DAT_23eedeac8`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `168` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `169` 'wait_ready'
     `170` 'MemoryFishReader.wait_ready'
     `171` 'clear_pending'
     `172` 'MemoryFishReader.clear_pending'
     `173` [10.0]
     `174` 'wait_catch'
     `175` 'MemoryFishReader.wait_catch'
  => `176` 'MemoryFishReader._run'
     `177` 'workers\\fishing\\memory_fish_reader.py'
     `178` '<module workers.fishing.memory_fish_reader>'
     `179` ['__class__']
     `180` ['self']
     `181` ['FISH_NAMES', 'ru_to_eng', 'names_file', 'f', 'line', 'png_name', 'ru_name']
     `182` ['targets', 'chunk', 'counts', '_pid', 'h', 'base', 'size', 'offset', 'data', 'fish', 'weight', 'key']
     `183` ['handle', 'needle', 'chunk', 'found', 'base', 'size', 'offset', 'data']
     `184` ['data', 'text', 'result', 'm', 'fish', 'weight']
     `185` ['out']
     `186` ['handle', 'mbi', 'addr']
     `187` ['pid', 'h']
     `188` ['handle', 'addr', 'size', 'buf', 'read']
     `189` ['self', 'pids', 'targets', 'pid', 'h', 'regions', 'base', 'size', 'known_counts', 'current_counts', 'new_items', 'key', 'cnt', 'ru_name', 'weight', 'eng_key', '_']
     `190` ['self', 'timeout', 'deadline', 'remaining', 'result']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__memory_fish_reader\23e7ef2c0_MemoryFishReader._run.c`

### `?`

- implementation: `FUN_23e7f0b40`
- source line hint: `194`
- Nuitka codevar: `_DAT_23eedeab8`
- factory: `FUN_23e93e1e0`
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__memory_fish_reader\23e7f0b40_unknown.c`

### `?`

- implementation: `FUN_23e7f1ee0`
- source line hint: `208`
- Nuitka codevar: `_DAT_23eedeaa8`
- factory: `FUN_23e93e480`
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__memory_fish_reader\23e7f1ee0_unknown.c`

### `?`

- implementation: `FUN_23e7f2380`
- source line hint: `213`
- Nuitka codevar: `_DAT_23eedea98`
- factory: `FUN_23e93e1e0`
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__memory_fish_reader\23e7f2380_unknown.c`

### `?`

- implementation: `FUN_23e7f3420`
- source line hint: `219`
- Nuitka codevar: `uVar4`
- factory: `FUN_23e93e480`
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__memory_fish_reader\23e7f3420_unknown.c`

### `?`

- implementation: `FUN_23e7f5660`
- source line hint: `241`
- Nuitka codevar: `_DAT_23eedea78`
- factory: `FUN_23e93e1e0`
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__memory_fish_reader\23e7f5660_unknown.c`

### `?`

- implementation: `FUN_23e7e4bc0`
- source line hint: `?`
- Nuitka codevar: `uVar9`
- factory: `FUN_23e93df40`
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__memory_fish_reader\23e7e4bc0_unknown.c`

### `?`

- implementation: `FUN_23e7e8670`
- source line hint: `?`
- Nuitka codevar: `DAT_23eedeb18`
- factory: `FUN_23e93df40`
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__memory_fish_reader\23e7e8670_unknown.c`
