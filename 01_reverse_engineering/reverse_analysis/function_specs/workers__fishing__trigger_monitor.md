# Function Specification: `workers.fishing.trigger_monitor`

This is a reconstruction dossier from static Nuitka constants and Ghidra decompilation. It is not original Python source text.

## Source Path Hints
- `workers\fishing\trigger_monitor.py`

## Docstrings / Long Text
- `182` ')\n'
- `188` ' templates\n'
- `193` '\n'
- `221` '\nGTA5 Trigger Monitor System\nMonitors multiple regions for various game triggers (hunger, thirst, fishing stages, events, etc.)\nAutomatically detects resolution and uses appropriate templates\n'

## Function Inventory
| Inferred qualname | Impl | Source line | Arg count | Decompiled C |
|---|---:|---:|---:|---|
| `start.png` | `LAB_23e832330` | 48 | 2 | yes |
| `start1.png` | `FUN_23e832800` | 52 | uVar8 | yes |
| `start2.png` | `FUN_23e834640` | 78 | uVar20 | yes |
| `AD.png` | `FUN_23e89a0c0` | 86 | uVar8 | yes |
| `changeBait.png` | `FUN_23e835350` | 127 | 3 | yes |
| `gear.png` | `FUN_23e836bd0` | 158 | 1 | yes |
| `WindowCapture.__init__` | `FUN_23e83a540` | 190 | 2 | yes |
| `WindowCapture.find_window_by_process` | `FUN_23e83b350` | 203 | 3 | yes |
| `WindowCapture.get_window_size` | `FUN_23e89c9d0` | 220 | 3 | yes |
| `WindowCapture.capture` | `FUN_23e89d670` | 229 | uVar8 | yes |
| `TriggerMonitor.__init__` | `FUN_23e89ec50` | 254 | uVar8 | yes |
| `TriggerMonitor._load_templates` | `FUN_23e8a0230` | 279 | uVar8 | yes |
| `TriggerMonitor._load_template` | `FUN_23e8a0eb0` | 294 | uVar8 | yes |
| `TriggerMonitor._match_template` | `FUN_23e8a2490` | 319 | uVar8 | yes |
| `TriggerMonitor._extract_roi` | `FUN_23e83c3f0` | 339 | 2 | yes |
| `TriggerMonitor.check_region_needs` | `FUN_23e83d2f0` | 363 | uVar8 | yes |
| `TriggerMonitor.check_region_fishing_stages` | `FUN_23e8a3670` | 375 | uVar8 | yes |
| `TriggerMonitor.check_region_ad_buttons` | `FUN_23e83de30` | 418 | uVar20&0xffffffff00000000 | yes |

## Local Variable Lists
- `275` `.0, t`
- `277` `__class__`
- `278` `self, resolution, templates_dir`
- `279` `self, process_name`
- `280` `self, frame, roi, x, y, w, h`
- `281` `self, filename, filepath, template`
- `282` `self, templates, loaded`
- `283` `self, roi, template, roi_gray, result, min_val, max_val, min_loc, max_loc`
- `284` `hwnd, hwnds, _, pid, process, self`
- `285` `self`
- `286` `self, left, top, right, bottom, width, height, hwndDC, mfcDC, saveDC, saveBitMap, bmpinfo, bmpstr, img, e`
- `287` `self, frame, roi, detections, conf, loc`
- `289` `self, callback, hwnds, hwnd, title`
- `291` `self, left, top, right, bottom`
- `293` `self, frame, current_time, elapsed, all_detections`

## Structured Constants
- `16` [0, 0]
- `31` [True]
- `111` [0.0, None]
- `208` [1]
- `218` {'__dict_items__': [['end', ''], ['flush', True]]}
- `230` [4, 601, 679, 478]
- `231` [12, 819, 880, 616]
- `232` [1535, 1022, 372, 44]
- `233` [2052, 1365, 492, 55]
- `234` [838, 1018, 70, 37]
- `235` [1121, 1359, 87, 46]
- `236` [694, 663, 527, 414]
- `237` [925, 984, 708, 455]
- `238` [1170, 937, 60, 61]
- `239` [1557, 1249, 86, 82]
- `244` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
- `246` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
- `248` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
- `254` {'__dict_items__': [['resolution', {'__builtin__': 'str'}], ['templates_dir', {'__builtin__': 'str'}]]}
- `256` {'__dict_items__': [['return', {'__builtin__': 'dict'}]]}
- `271` {'__dict_items__': [['width', {'__builtin__': 'int'}], ['height', {'__builtin__': 'int'}], ['return', {'__builtin__': 'tuple'}]]}
- `272` {'__dict_items__': [['detections', {'__builtin__': 'dict'}], ['return', {'__builtin__': 'str'}]]}

## Per-Function Context
### `start.png`

- implementation: `LAB_23e832330`
- source line hint: `48`
- Nuitka codevar: `DAT_23eede598`
- factory: `FUN_23e93e480`
- nearby constants:
     `74` 'current_fps'
     `75` 'last_detections'
     `76` '_load_template'
     `77` 'thirst'
     `78` '.png'
     `79` 'hunger'
     `80` 'advantage'
     `81` 'start'
  => `82` 'start.png'
     `83` 'start1_'
     `84` 'start1.png'
     `85` 'start1'
     `86` 'start2_'
     `87` 'start2.png'
     `88` 'start2'
     `89` 'AD_'
     `90` 'AD.png'
     `91` 'ad_buttons'
     `92` 'pereves'
     `93` 'changed_Bait'
     `94` 'changeBait.png'
     `95` 'changed_bait'
     `96` 'gear_'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__trigger_monitor\23e832330_start.png.c`

### `start1.png`

- implementation: `FUN_23e832800`
- source line hint: `52`
- Nuitka codevar: `_DAT_23eede588`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `76` '_load_template'
     `77` 'thirst'
     `78` '.png'
     `79` 'hunger'
     `80` 'advantage'
     `81` 'start'
     `82` 'start.png'
     `83` 'start1_'
  => `84` 'start1.png'
     `85` 'start1'
     `86` 'start2_'
     `87` 'start2.png'
     `88` 'start2'
     `89` 'AD_'
     `90` 'AD.png'
     `91` 'ad_buttons'
     `92` 'pereves'
     `93` 'changed_Bait'
     `94` 'changeBait.png'
     `95` 'changed_bait'
     `96` 'gear_'
     `97` 'gear.png'
     `98` 'gear'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__trigger_monitor\23e832800_start1.png.c`

### `start2.png`

- implementation: `FUN_23e834640`
- source line hint: `78`
- Nuitka codevar: `_DAT_23eede558`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `79` 'hunger'
     `80` 'advantage'
     `81` 'start'
     `82` 'start.png'
     `83` 'start1_'
     `84` 'start1.png'
     `85` 'start1'
     `86` 'start2_'
  => `87` 'start2.png'
     `88` 'start2'
     `89` 'AD_'
     `90` 'AD.png'
     `91` 'ad_buttons'
     `92` 'pereves'
     `93` 'changed_Bait'
     `94` 'changeBait.png'
     `95` 'changed_bait'
     `96` 'gear_'
     `97` 'gear.png'
     `98` 'gear'
     `99` 'boat'
     `100` 'human'
     `101` '[DEBUG] Загружено '
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__trigger_monitor\23e834640_start2.png.c`

### `AD.png`

- implementation: `FUN_23e89a0c0`
- source line hint: `86`
- Nuitka codevar: `DAT_23eede548`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `82` 'start.png'
     `83` 'start1_'
     `84` 'start1.png'
     `85` 'start1'
     `86` 'start2_'
     `87` 'start2.png'
     `88` 'start2'
     `89` 'AD_'
  => `90` 'AD.png'
     `91` 'ad_buttons'
     `92` 'pereves'
     `93` 'changed_Bait'
     `94` 'changeBait.png'
     `95` 'changed_bait'
     `96` 'gear_'
     `97` 'gear.png'
     `98` 'gear'
     `99` 'boat'
     `100` 'human'
     `101` '[DEBUG] Загружено '
     `102` ' шаблонов'
     `103` 'Load all template images for the current resolution'
     `104` '<genexpr>'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__trigger_monitor\23e89a0c0_AD.png.c`

### `changeBait.png`

- implementation: `FUN_23e835350`
- source line hint: `127`
- Nuitka codevar: `_DAT_23eede530`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `86` 'start2_'
     `87` 'start2.png'
     `88` 'start2'
     `89` 'AD_'
     `90` 'AD.png'
     `91` 'ad_buttons'
     `92` 'pereves'
     `93` 'changed_Bait'
  => `94` 'changeBait.png'
     `95` 'changed_bait'
     `96` 'gear_'
     `97` 'gear.png'
     `98` 'gear'
     `99` 'boat'
     `100` 'human'
     `101` '[DEBUG] Загружено '
     `102` ' шаблонов'
     `103` 'Load all template images for the current resolution'
     `104` '<genexpr>'
     `105` 'TriggerMonitor._load_templates.<locals>.<genexpr>'
     `106` '[WARNING] Template not found: '
     `107` 'imread'
     `108` 'IMREAD_GRAYSCALE'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__trigger_monitor\23e835350_changeBait.png.c`

### `gear.png`

- implementation: `FUN_23e836bd0`
- source line hint: `158`
- Nuitka codevar: `_DAT_23eede4c8`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `89` 'AD_'
     `90` 'AD.png'
     `91` 'ad_buttons'
     `92` 'pereves'
     `93` 'changed_Bait'
     `94` 'changeBait.png'
     `95` 'changed_bait'
     `96` 'gear_'
  => `97` 'gear.png'
     `98` 'gear'
     `99` 'boat'
     `100` 'human'
     `101` '[DEBUG] Загружено '
     `102` ' шаблонов'
     `103` 'Load all template images for the current resolution'
     `104` '<genexpr>'
     `105` 'TriggerMonitor._load_templates.<locals>.<genexpr>'
     `106` '[WARNING] Template not found: '
     `107` 'imread'
     `108` 'IMREAD_GRAYSCALE'
     `109` '[WARNING] Failed to load template: '
     `110` 'Load a single template image in grayscale'
     `111` [0.0, None]
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__trigger_monitor\23e836bd0_gear.png.c`

### `WindowCapture.__init__`

- implementation: `FUN_23e83a540`
- source line hint: `190`
- Nuitka codevar: `DAT_23eede4a8`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `237` [925, 984, 708, 455]
     `238` [1170, 937, 60, 61]
     `239` [1557, 1249, 86, 82]
     `240` 0.95
     `241` 'workers.fishing.trigger_monitor'
     `242` 'Captures window screenshots by process name'
     `243` '__qualname__'
     `244` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
  => `245` 'WindowCapture.__init__'
     `246` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `247` 'WindowCapture.find_window_by_process'
     `248` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `249` 'WindowCapture.get_window_size'
     `250` 'return'
     `251` 'ndarray'
     `252` 'WindowCapture.capture'
     `253` 'Monitors multiple regions for various game triggers'
     `254` {'__dict_items__': [['resolution', {'__builtin__': 'str'}], ['templates_dir', {'__builtin__': 'str'}]]}
     `255` 'TriggerMonitor.__init__'
     `256` {'__dict_items__': [['return', {'__builtin__': 'dict'}]]}
     `257` 'TriggerMonitor._load_templates'
     `258` 'filename'
     `259` 'TriggerMonitor._load_template'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__trigger_monitor\23e83a540_WindowCapture.__init.c`

### `WindowCapture.find_window_by_process`

- implementation: `FUN_23e83b350`
- source line hint: `203`
- Nuitka codevar: `_DAT_23eede498`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `239` [1557, 1249, 86, 82]
     `240` 0.95
     `241` 'workers.fishing.trigger_monitor'
     `242` 'Captures window screenshots by process name'
     `243` '__qualname__'
     `244` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
     `245` 'WindowCapture.__init__'
     `246` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
  => `247` 'WindowCapture.find_window_by_process'
     `248` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `249` 'WindowCapture.get_window_size'
     `250` 'return'
     `251` 'ndarray'
     `252` 'WindowCapture.capture'
     `253` 'Monitors multiple regions for various game triggers'
     `254` {'__dict_items__': [['resolution', {'__builtin__': 'str'}], ['templates_dir', {'__builtin__': 'str'}]]}
     `255` 'TriggerMonitor.__init__'
     `256` {'__dict_items__': [['return', {'__builtin__': 'dict'}]]}
     `257` 'TriggerMonitor._load_templates'
     `258` 'filename'
     `259` 'TriggerMonitor._load_template'
     `260` 'roi'
     `261` 'template'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__trigger_monitor\23e83b350_WindowCapture.find_window_by_process.c`

### `WindowCapture.get_window_size`

- implementation: `FUN_23e89c9d0`
- source line hint: `220`
- Nuitka codevar: `_DAT_23eede488`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `241` 'workers.fishing.trigger_monitor'
     `242` 'Captures window screenshots by process name'
     `243` '__qualname__'
     `244` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
     `245` 'WindowCapture.__init__'
     `246` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `247` 'WindowCapture.find_window_by_process'
     `248` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
  => `249` 'WindowCapture.get_window_size'
     `250` 'return'
     `251` 'ndarray'
     `252` 'WindowCapture.capture'
     `253` 'Monitors multiple regions for various game triggers'
     `254` {'__dict_items__': [['resolution', {'__builtin__': 'str'}], ['templates_dir', {'__builtin__': 'str'}]]}
     `255` 'TriggerMonitor.__init__'
     `256` {'__dict_items__': [['return', {'__builtin__': 'dict'}]]}
     `257` 'TriggerMonitor._load_templates'
     `258` 'filename'
     `259` 'TriggerMonitor._load_template'
     `260` 'roi'
     `261` 'template'
     `262` 'TriggerMonitor._match_template'
     `263` 'frame'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__trigger_monitor\23e89c9d0_WindowCapture.get_window_size.c`

### `WindowCapture.capture`

- implementation: `FUN_23e89d670`
- source line hint: `229`
- Nuitka codevar: `_DAT_23eede478`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `244` {'__dict_items__': [['process_name', {'__builtin__': 'str'}]]}
     `245` 'WindowCapture.__init__'
     `246` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `247` 'WindowCapture.find_window_by_process'
     `248` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `249` 'WindowCapture.get_window_size'
     `250` 'return'
     `251` 'ndarray'
  => `252` 'WindowCapture.capture'
     `253` 'Monitors multiple regions for various game triggers'
     `254` {'__dict_items__': [['resolution', {'__builtin__': 'str'}], ['templates_dir', {'__builtin__': 'str'}]]}
     `255` 'TriggerMonitor.__init__'
     `256` {'__dict_items__': [['return', {'__builtin__': 'dict'}]]}
     `257` 'TriggerMonitor._load_templates'
     `258` 'filename'
     `259` 'TriggerMonitor._load_template'
     `260` 'roi'
     `261` 'template'
     `262` 'TriggerMonitor._match_template'
     `263` 'frame'
     `264` 'TriggerMonitor._extract_roi'
     `265` 'TriggerMonitor.check_region_needs'
     `266` 'TriggerMonitor.check_region_fishing_stages'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__trigger_monitor\23e89d670_WindowCapture.capture.c`

### `TriggerMonitor.__init__`

- implementation: `FUN_23e89ec50`
- source line hint: `254`
- Nuitka codevar: `_DAT_23eede468`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `247` 'WindowCapture.find_window_by_process'
     `248` {'__dict_items__': [['return', {'__builtin__': 'tuple'}]]}
     `249` 'WindowCapture.get_window_size'
     `250` 'return'
     `251` 'ndarray'
     `252` 'WindowCapture.capture'
     `253` 'Monitors multiple regions for various game triggers'
     `254` {'__dict_items__': [['resolution', {'__builtin__': 'str'}], ['templates_dir', {'__builtin__': 'str'}]]}
  => `255` 'TriggerMonitor.__init__'
     `256` {'__dict_items__': [['return', {'__builtin__': 'dict'}]]}
     `257` 'TriggerMonitor._load_templates'
     `258` 'filename'
     `259` 'TriggerMonitor._load_template'
     `260` 'roi'
     `261` 'template'
     `262` 'TriggerMonitor._match_template'
     `263` 'frame'
     `264` 'TriggerMonitor._extract_roi'
     `265` 'TriggerMonitor.check_region_needs'
     `266` 'TriggerMonitor.check_region_fishing_stages'
     `267` 'TriggerMonitor.check_region_ad_buttons'
     `268` 'TriggerMonitor.check_region_events'
     `269` 'TriggerMonitor.check_region_boat_human'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__trigger_monitor\23e89ec50_TriggerMonitor.__init.c`

### `TriggerMonitor._load_templates`

- implementation: `FUN_23e8a0230`
- source line hint: `279`
- Nuitka codevar: `_DAT_23eede458`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `249` 'WindowCapture.get_window_size'
     `250` 'return'
     `251` 'ndarray'
     `252` 'WindowCapture.capture'
     `253` 'Monitors multiple regions for various game triggers'
     `254` {'__dict_items__': [['resolution', {'__builtin__': 'str'}], ['templates_dir', {'__builtin__': 'str'}]]}
     `255` 'TriggerMonitor.__init__'
     `256` {'__dict_items__': [['return', {'__builtin__': 'dict'}]]}
  => `257` 'TriggerMonitor._load_templates'
     `258` 'filename'
     `259` 'TriggerMonitor._load_template'
     `260` 'roi'
     `261` 'template'
     `262` 'TriggerMonitor._match_template'
     `263` 'frame'
     `264` 'TriggerMonitor._extract_roi'
     `265` 'TriggerMonitor.check_region_needs'
     `266` 'TriggerMonitor.check_region_fishing_stages'
     `267` 'TriggerMonitor.check_region_ad_buttons'
     `268` 'TriggerMonitor.check_region_events'
     `269` 'TriggerMonitor.check_region_boat_human'
     `270` 'TriggerMonitor.monitor_all_regions'
     `271` {'__dict_items__': [['width', {'__builtin__': 'int'}], ['height', {'__builtin__': 'int'}], ['return', {'__builtin__': 'tuple'}]]}
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__trigger_monitor\23e8a0230_TriggerMonitor._load_templates.c`

### `TriggerMonitor._load_template`

- implementation: `FUN_23e8a0eb0`
- source line hint: `294`
- Nuitka codevar: `_DAT_23eede448`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `251` 'ndarray'
     `252` 'WindowCapture.capture'
     `253` 'Monitors multiple regions for various game triggers'
     `254` {'__dict_items__': [['resolution', {'__builtin__': 'str'}], ['templates_dir', {'__builtin__': 'str'}]]}
     `255` 'TriggerMonitor.__init__'
     `256` {'__dict_items__': [['return', {'__builtin__': 'dict'}]]}
     `257` 'TriggerMonitor._load_templates'
     `258` 'filename'
  => `259` 'TriggerMonitor._load_template'
     `260` 'roi'
     `261` 'template'
     `262` 'TriggerMonitor._match_template'
     `263` 'frame'
     `264` 'TriggerMonitor._extract_roi'
     `265` 'TriggerMonitor.check_region_needs'
     `266` 'TriggerMonitor.check_region_fishing_stages'
     `267` 'TriggerMonitor.check_region_ad_buttons'
     `268` 'TriggerMonitor.check_region_events'
     `269` 'TriggerMonitor.check_region_boat_human'
     `270` 'TriggerMonitor.monitor_all_regions'
     `271` {'__dict_items__': [['width', {'__builtin__': 'int'}], ['height', {'__builtin__': 'int'}], ['return', {'__builtin__': 'tuple'}]]}
     `272` {'__dict_items__': [['detections', {'__builtin__': 'dict'}], ['return', {'__builtin__': 'str'}]]}
     `273` 'main'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__trigger_monitor\23e8a0eb0_TriggerMonitor._load_template.c`

### `TriggerMonitor._match_template`

- implementation: `FUN_23e8a2490`
- source line hint: `319`
- Nuitka codevar: `_DAT_23eede438`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `254` {'__dict_items__': [['resolution', {'__builtin__': 'str'}], ['templates_dir', {'__builtin__': 'str'}]]}
     `255` 'TriggerMonitor.__init__'
     `256` {'__dict_items__': [['return', {'__builtin__': 'dict'}]]}
     `257` 'TriggerMonitor._load_templates'
     `258` 'filename'
     `259` 'TriggerMonitor._load_template'
     `260` 'roi'
     `261` 'template'
  => `262` 'TriggerMonitor._match_template'
     `263` 'frame'
     `264` 'TriggerMonitor._extract_roi'
     `265` 'TriggerMonitor.check_region_needs'
     `266` 'TriggerMonitor.check_region_fishing_stages'
     `267` 'TriggerMonitor.check_region_ad_buttons'
     `268` 'TriggerMonitor.check_region_events'
     `269` 'TriggerMonitor.check_region_boat_human'
     `270` 'TriggerMonitor.monitor_all_regions'
     `271` {'__dict_items__': [['width', {'__builtin__': 'int'}], ['height', {'__builtin__': 'int'}], ['return', {'__builtin__': 'tuple'}]]}
     `272` {'__dict_items__': [['detections', {'__builtin__': 'dict'}], ['return', {'__builtin__': 'str'}]]}
     `273` 'main'
     `274` 'workers\\fishing\\trigger_monitor.py'
     `275` ['.0', 't']
     `276` '<module workers.fishing.trigger_monitor>'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__trigger_monitor\23e8a2490_TriggerMonitor._match_template.c`

### `TriggerMonitor._extract_roi`

- implementation: `FUN_23e83c3f0`
- source line hint: `339`
- Nuitka codevar: `_DAT_23eede428`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `256` {'__dict_items__': [['return', {'__builtin__': 'dict'}]]}
     `257` 'TriggerMonitor._load_templates'
     `258` 'filename'
     `259` 'TriggerMonitor._load_template'
     `260` 'roi'
     `261` 'template'
     `262` 'TriggerMonitor._match_template'
     `263` 'frame'
  => `264` 'TriggerMonitor._extract_roi'
     `265` 'TriggerMonitor.check_region_needs'
     `266` 'TriggerMonitor.check_region_fishing_stages'
     `267` 'TriggerMonitor.check_region_ad_buttons'
     `268` 'TriggerMonitor.check_region_events'
     `269` 'TriggerMonitor.check_region_boat_human'
     `270` 'TriggerMonitor.monitor_all_regions'
     `271` {'__dict_items__': [['width', {'__builtin__': 'int'}], ['height', {'__builtin__': 'int'}], ['return', {'__builtin__': 'tuple'}]]}
     `272` {'__dict_items__': [['detections', {'__builtin__': 'dict'}], ['return', {'__builtin__': 'str'}]]}
     `273` 'main'
     `274` 'workers\\fishing\\trigger_monitor.py'
     `275` ['.0', 't']
     `276` '<module workers.fishing.trigger_monitor>'
     `277` ['__class__']
     `278` ['self', 'resolution', 'templates_dir']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__trigger_monitor\23e83c3f0_TriggerMonitor._extract_roi.c`

### `TriggerMonitor.check_region_needs`

- implementation: `FUN_23e83d2f0`
- source line hint: `363`
- Nuitka codevar: `_DAT_23eede418`
- factory: `FUN_23e93df40`
- nearby constants:
     `257` 'TriggerMonitor._load_templates'
     `258` 'filename'
     `259` 'TriggerMonitor._load_template'
     `260` 'roi'
     `261` 'template'
     `262` 'TriggerMonitor._match_template'
     `263` 'frame'
     `264` 'TriggerMonitor._extract_roi'
  => `265` 'TriggerMonitor.check_region_needs'
     `266` 'TriggerMonitor.check_region_fishing_stages'
     `267` 'TriggerMonitor.check_region_ad_buttons'
     `268` 'TriggerMonitor.check_region_events'
     `269` 'TriggerMonitor.check_region_boat_human'
     `270` 'TriggerMonitor.monitor_all_regions'
     `271` {'__dict_items__': [['width', {'__builtin__': 'int'}], ['height', {'__builtin__': 'int'}], ['return', {'__builtin__': 'tuple'}]]}
     `272` {'__dict_items__': [['detections', {'__builtin__': 'dict'}], ['return', {'__builtin__': 'str'}]]}
     `273` 'main'
     `274` 'workers\\fishing\\trigger_monitor.py'
     `275` ['.0', 't']
     `276` '<module workers.fishing.trigger_monitor>'
     `277` ['__class__']
     `278` ['self', 'resolution', 'templates_dir']
     `279` ['self', 'process_name']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__trigger_monitor\23e83d2f0_TriggerMonitor.check_region_needs.c`

### `TriggerMonitor.check_region_fishing_stages`

- implementation: `FUN_23e8a3670`
- source line hint: `375`
- Nuitka codevar: `_DAT_23eede408`
- factory: `FUN_23e93df40`
- nearby constants:
     `258` 'filename'
     `259` 'TriggerMonitor._load_template'
     `260` 'roi'
     `261` 'template'
     `262` 'TriggerMonitor._match_template'
     `263` 'frame'
     `264` 'TriggerMonitor._extract_roi'
     `265` 'TriggerMonitor.check_region_needs'
  => `266` 'TriggerMonitor.check_region_fishing_stages'
     `267` 'TriggerMonitor.check_region_ad_buttons'
     `268` 'TriggerMonitor.check_region_events'
     `269` 'TriggerMonitor.check_region_boat_human'
     `270` 'TriggerMonitor.monitor_all_regions'
     `271` {'__dict_items__': [['width', {'__builtin__': 'int'}], ['height', {'__builtin__': 'int'}], ['return', {'__builtin__': 'tuple'}]]}
     `272` {'__dict_items__': [['detections', {'__builtin__': 'dict'}], ['return', {'__builtin__': 'str'}]]}
     `273` 'main'
     `274` 'workers\\fishing\\trigger_monitor.py'
     `275` ['.0', 't']
     `276` '<module workers.fishing.trigger_monitor>'
     `277` ['__class__']
     `278` ['self', 'resolution', 'templates_dir']
     `279` ['self', 'process_name']
     `280` ['self', 'frame', 'roi', 'x', 'y', 'w', 'h']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__trigger_monitor\23e8a3670_TriggerMonitor.check_region_fishing_stages.c`

### `TriggerMonitor.check_region_ad_buttons`

- implementation: `FUN_23e83de30`
- source line hint: `418`
- Nuitka codevar: `_DAT_23eede3f8`
- factory: `FUN_23e93df40`
- nearby constants:
     `259` 'TriggerMonitor._load_template'
     `260` 'roi'
     `261` 'template'
     `262` 'TriggerMonitor._match_template'
     `263` 'frame'
     `264` 'TriggerMonitor._extract_roi'
     `265` 'TriggerMonitor.check_region_needs'
     `266` 'TriggerMonitor.check_region_fishing_stages'
  => `267` 'TriggerMonitor.check_region_ad_buttons'
     `268` 'TriggerMonitor.check_region_events'
     `269` 'TriggerMonitor.check_region_boat_human'
     `270` 'TriggerMonitor.monitor_all_regions'
     `271` {'__dict_items__': [['width', {'__builtin__': 'int'}], ['height', {'__builtin__': 'int'}], ['return', {'__builtin__': 'tuple'}]]}
     `272` {'__dict_items__': [['detections', {'__builtin__': 'dict'}], ['return', {'__builtin__': 'str'}]]}
     `273` 'main'
     `274` 'workers\\fishing\\trigger_monitor.py'
     `275` ['.0', 't']
     `276` '<module workers.fishing.trigger_monitor>'
     `277` ['__class__']
     `278` ['self', 'resolution', 'templates_dir']
     `279` ['self', 'process_name']
     `280` ['self', 'frame', 'roi', 'x', 'y', 'w', 'h']
     `281` ['self', 'filename', 'filepath', 'template']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__trigger_monitor\23e83de30_TriggerMonitor.check_region_ad_buttons.c`
