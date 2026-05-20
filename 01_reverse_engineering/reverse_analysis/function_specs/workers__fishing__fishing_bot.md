# Function Specification: `workers.fishing.fishing_bot`

This is a reconstruction dossier from static Nuitka constants and Ghidra decompilation. It is not original Python source text.

## Source Path Hints
- `workers\fishing\fishing_bot.py`

## Docstrings / Long Text
- `62` '\n        Перезагрузить настройки из конфига\n        Можно вызывать во время работы бота для применения изменений\n        '
- `376` 'ESC→3s→ESC→5s→I→5s → рюкзак → (мусор) → ESC→2s→E - ИСПОЛЬЗУЕМ ОРИГИНАЛЬНУЮ ЛОГИКУ'
- `445` 'Попытаться восстановить рыбалку: W 0.5s + E, ждём boat/human/start, макс 3 раза с паузой 10 сек'
- `480` '\nFishingBot — центральная логика управления рыбалкой\nМозг бота: мониторинг триггеров → принятие решений → вызов модулей\n'
- `541` '\n    Центральная логика бота рыбалки.\n    Запускает мониторинг триггеров в отдельном потоке,\n    принимает решения и вызывает нужные модули.\n    '

## Function Inventory
| Inferred qualname | Impl | Source line | Arg count | Decompiled C |
|---|---:|---:|---:|---|
| `FishingBot` | `FUN_23e71f6d0` | ? | ? | yes |
| `FishingBot.__init__` | `FUN_23e71fc80` | ? | ? | yes |
| `FishingBot.reload_settings` | `FUN_23e723410` | ? | ? | yes |
| `FishingBot.start` | `FUN_23e723fb0` | ? | ? | yes |
| `FishingBot.stop` | `FUN_23e725c90` | ? | ? | yes |
| `FishingBot._monitor_loop` | `FUN_23e726bf0` | ? | ? | yes |
| `FishingBot._get_triggers` | `FUN_23e7280f0` | ? | ? | yes |
| `FishingBot._is_trigger_active` | `FUN_23e7491b0` | ? | ? | yes |
| `FishingBot._brain_loop` | `FUN_23e749a20` | ? | ? | yes |
| `FishingBot._run_casting_module` | `FUN_23e74bd70` | ? | ? | yes |
| `FishingBot._run_hooking_module` | `FUN_23e750d60` | ? | ? | yes |
| `FishingBot._run_reeling_module` | `FUN_23e7528d0` | ? | ? | yes |
| `FishingBot._do_casting` | `FUN_23e754cd0` | ? | ? | yes |
| `FishingBot._do_hooking` | `FUN_23e7582c0` | ? | ? | yes |
| `FishingBot._do_fish_catch` | `FUN_23e75b480` | ? | ? | yes |
| `FishingBot._handle_pending_tasks` | `FUN_23e75c120` | ? | ? | yes |
| `FishingBot._do_combined_inventory_tasks` | `FUN_23e75d510` | ? | ? | yes |
| `FishingBot._do_meal_actions` | `FUN_23e75dc10` | ? | ? | yes |
| `FishingBot._do_backpack_actions` | `FUN_23e7610e0` | ? | ? | yes |
| `FishingBot._do_meal_routine` | `FUN_23e764e30` | ? | ? | yes |
| `FishingBot._do_store_backpack_routine` | `FUN_23e769800` | ? | ? | yes |
| `FishingBot._do_garbage` | `FUN_23e769f00` | ? | ? | yes |
| `FishingBot._do_change_bait` | `FUN_23e76e6f0` | ? | ? | yes |
| `FishingBot._do_store_trunk` | `FUN_23e76edf0` | ? | ? | yes |
| `FishingBot._do_exit_fishing_on_pereves` | `FUN_23e7724a0` | ? | ? | yes |
| `FishingBot._wait_for_start_phase` | `FUN_23e773110` | ? | ? | yes |
| `FishingBot._exit_fishing` | `FUN_23e778710` | ? | ? | yes |
| `FishingBot._open_inventory` | `FUN_23e7790f0` | ? | ? | yes |
| `FishingBot._return_to_fishing` | `FUN_23e779790` | ? | ? | yes |
| `FishingBot._try_recover` | `FUN_23e779ca0` | ? | ? | yes |
| `FishingBot._sleep` | `FUN_23e77a2d0` | ? | ? | yes |
| `FishingBot._load_fish_names` | `FUN_23e77ae10` | ? | ? | yes |
| `FishingBot._get_fish_name_ru` | `FUN_23e77e4b0` | ? | ? | yes |
| `FishingBot._log` | `FUN_23e77e960` | ? | ? | yes |
| `FishingBot._capture_screenshot_bytes` | `FUN_23e77f390` | ? | ? | yes |

## Local Variable Lists
- `593` `.0, t, current_triggers`
- `594` `.0, v`
- `596` `__class__`
- `597` `self, log_callback`
- `598` `self, triggers, boat_human, fishing_stages, ad_buttons, is_compiled, failed, has_boat, has_human, needs, current_hunger, current_thirst, events, current_advantage, current_pereves, e, notif_mgr, shutdown_pending, _time, os, current_changed_bait, current_gear, current_triggers, priority_trigger, now, wait_elapsed, prev_trigger, elapsed, finished_trigger`
- `599` `self, Image, frame, frame_rgb, img, buf, e`
- `600` `self, storer, STORE_ROI_2K, STORE_ROI_FHD, fish_stored_count, backpack_full, screenshot, fish_positions, total_fish_count, notif_mgr, fish_info, success, e`
- `601` `self, roi, monitor, timeout, frame, green_count, _, pressed`
- `602` `self, notif_mgr`
- `603` `self, do_meal, do_backpack, garbage_settings, has_garbage_to_eject`
- `604` `self`
- `605` `self, fish_to_keep, fish_to_release, all_release, take_coord, release_coord, catch, eng_key, ru_name, weight, screenshot_bytes, notif_mgr`
- `606` `self, disposal, GARB_ROI_2K, GARB_ROI_FHD, screenshot, garbage_list, g, e`
- `607` `self, roi1, roi2, resolution_str, monitor, timeout, frame, red_count, color_diff, red_detected, change_detected, pressed, trigger_reason, fps, paused`
- `608` `self, meal, INVENTORY_ROI_2K, FOOD_CHECK_ROI_2K, THIRST_CHECK_ROI_2K, INVENTORY_ROI_FULLHD, FOOD_CHECK_ROI_FULLHD, THIRST_CHECK_ROI_FULLHD, food_found, donuts_ok, cocktails_ok, e, notif_mgr`
- `609` `self, meal, INVENTORY_ROI_2K, FOOD_CHECK_ROI_2K, THIRST_CHECK_ROI_2K, INVENTORY_ROI_FULLHD, FOOD_CHECK_ROI_FULLHD, THIRST_CHECK_ROI_FULLHD, food_found, donuts_ok, cocktails_ok, e, notif_mgr, garbage_settings, has_garbage_to_eject`
- `610` `self, storer, STORE_ROI_2K, STORE_ROI_FHD, fish_stored_count, backpack_full, screenshot, fish_positions, fish_info, success, e, notif_mgr, garbage_settings, has_garbage_to_eject`
- `611` `self, triggers, boat_human, triger_dir, change_boat_file, cv2, ROI_BOAT_HUMAN_FULLHD, ROI_BOAT_HUMAN_2K, roi, cx, cy, change_template, screenshot, result, _, max_val, max_loc, h, w, click_x, click_y`
- `612` `self, fish_name_eng`
- `613` `self, has_meal, has_backpack`
- `614` `self, trigger_name, triggers, now, is_detected, last_seen, time_since_last, is_active`
- `615` `self, fish_names_file, f, line, eng_name_with_png, ru_name, eng_name, e`
- `616` `self, msg, ts, full_msg`
- `617` `self, triger_dir, monitor, frame, detections`
- `618` `self, roi, monitor, iterations, frame, result, e`
- `619` `self, w, h, _, roi1, roi2, res_suffix, monitor, iterations, frame, red_conf, bubles_conf, red_det, bubles_det, pressed, reason, fps, paused, e`
- `620` `self, tracker, iterations, state`
- `621` `self, seconds, end`
- `622` `self, WindowActivator, attempt, deadline, triggers, boat_human, stages, screenshot_bytes, notif_mgr`
- `623` `self, max_retries, attempt, triggers, stages, deadline`
- `624` `self, garbage_settings, WindowActivator, e, w, h, _`

## Structured Constants
- `83` {'__dict_items__': [['max_attempts', 3]]}
- `95` [0.3]
- `99` [0.5]
- `112` [1.0]
- `125` [0.1]
- `128` [None, None, None]
- `147` [3.0]
- `163` [0.05]
- `190` [5.0]
- `198` [5]
- `230` [2.0]
- `259` [0.01]
- `269` [0.005]
- `290` [10.0]
- `417` {'__slice__': [None, 2, None]}
- `425` {'__range__': [0, 5, 1]}
- `435` {'__range__': [0, 3, 1]}
- `475` {'__dict_items__': [['format', 'PNG']]}
- `477` [0]
- `530` {'__dict_items__': [['2k', [1134, 968]], ['fullhd', [864, 728]]]}
- `531` {'__dict_items__': [['2k', [1397, 972]], ['fullhd', [1056, 727]]]}
- `543` [None]
- `550` {'__dict_items__': [['return', {'__builtin__': 'dict'}]]}
- `552` {'__dict_items__': [['trigger_name', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
- `564` {'__dict_items__': [['do_meal', {'__builtin__': 'bool'}], ['do_backpack', {'__builtin__': 'bool'}]]}
- `580` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
- `582` {'__dict_items__': [['seconds', {'__builtin__': 'float'}]]}
- `585` {'__dict_items__': [['fish_name_eng', {'__builtin__': 'str'}], ['return', {'__builtin__': 'str'}]]}
- `588` {'__dict_items__': [['msg', {'__builtin__': 'str'}]]}
- `590` {'__dict_items__': [['return', {'__builtin__': 'bytes'}]]}

## Per-Function Context
### `FishingBot`

- implementation: `FUN_23e71f6d0`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fishing_bot\23e71f6d0_FishingBot.c`

### `FishingBot.__init__`

- implementation: `FUN_23e71fc80`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `536` 'workers.fishing.fishing_bot'
     `537` 'Текущая фаза рыбалки'
     `538` '__qualname__'
     `539` 'GARBAGE'
     `540` '__orig_bases__'
     `541` '\n    Центральная логика бота рыбалки.\n    Запускает мониторинг триггеров в отдельном потоке,\n    принимает решения и вызывает нужные модули.\n    '
     `542` 'FishingBot'
     `543` [None]
  => `544` 'FishingBot.__init__'
     `545` 'reload_settings'
     `546` 'FishingBot.reload_settings'
     `547` 'FishingBot.start'
     `548` 'FishingBot.stop'
     `549` 'FishingBot._monitor_loop'
     `550` {'__dict_items__': [['return', {'__builtin__': 'dict'}]]}
     `551` 'FishingBot._get_triggers'
     `552` {'__dict_items__': [['trigger_name', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
     `553` 'FishingBot._is_trigger_active'
     `554` 'FishingBot._brain_loop'
     `555` 'FishingBot._run_casting_module'
     `556` 'FishingBot._run_hooking_module'
     `557` 'FishingBot._run_reeling_module'
     `558` '_do_casting'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fishing_bot\23e71fc80_FishingBot.__init.c`

### `FishingBot.reload_settings`

- implementation: `FUN_23e723410`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `538` '__qualname__'
     `539` 'GARBAGE'
     `540` '__orig_bases__'
     `541` '\n    Центральная логика бота рыбалки.\n    Запускает мониторинг триггеров в отдельном потоке,\n    принимает решения и вызывает нужные модули.\n    '
     `542` 'FishingBot'
     `543` [None]
     `544` 'FishingBot.__init__'
     `545` 'reload_settings'
  => `546` 'FishingBot.reload_settings'
     `547` 'FishingBot.start'
     `548` 'FishingBot.stop'
     `549` 'FishingBot._monitor_loop'
     `550` {'__dict_items__': [['return', {'__builtin__': 'dict'}]]}
     `551` 'FishingBot._get_triggers'
     `552` {'__dict_items__': [['trigger_name', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
     `553` 'FishingBot._is_trigger_active'
     `554` 'FishingBot._brain_loop'
     `555` 'FishingBot._run_casting_module'
     `556` 'FishingBot._run_hooking_module'
     `557` 'FishingBot._run_reeling_module'
     `558` '_do_casting'
     `559` 'FishingBot._do_casting'
     `560` '_do_hooking'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fishing_bot\23e723410_FishingBot.reload_settings.c`

### `FishingBot.start`

- implementation: `FUN_23e723fb0`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `539` 'GARBAGE'
     `540` '__orig_bases__'
     `541` '\n    Центральная логика бота рыбалки.\n    Запускает мониторинг триггеров в отдельном потоке,\n    принимает решения и вызывает нужные модули.\n    '
     `542` 'FishingBot'
     `543` [None]
     `544` 'FishingBot.__init__'
     `545` 'reload_settings'
     `546` 'FishingBot.reload_settings'
  => `547` 'FishingBot.start'
     `548` 'FishingBot.stop'
     `549` 'FishingBot._monitor_loop'
     `550` {'__dict_items__': [['return', {'__builtin__': 'dict'}]]}
     `551` 'FishingBot._get_triggers'
     `552` {'__dict_items__': [['trigger_name', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
     `553` 'FishingBot._is_trigger_active'
     `554` 'FishingBot._brain_loop'
     `555` 'FishingBot._run_casting_module'
     `556` 'FishingBot._run_hooking_module'
     `557` 'FishingBot._run_reeling_module'
     `558` '_do_casting'
     `559` 'FishingBot._do_casting'
     `560` '_do_hooking'
     `561` 'FishingBot._do_hooking'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fishing_bot\23e723fb0_FishingBot.start.c`

### `FishingBot.stop`

- implementation: `FUN_23e725c90`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `540` '__orig_bases__'
     `541` '\n    Центральная логика бота рыбалки.\n    Запускает мониторинг триггеров в отдельном потоке,\n    принимает решения и вызывает нужные модули.\n    '
     `542` 'FishingBot'
     `543` [None]
     `544` 'FishingBot.__init__'
     `545` 'reload_settings'
     `546` 'FishingBot.reload_settings'
     `547` 'FishingBot.start'
  => `548` 'FishingBot.stop'
     `549` 'FishingBot._monitor_loop'
     `550` {'__dict_items__': [['return', {'__builtin__': 'dict'}]]}
     `551` 'FishingBot._get_triggers'
     `552` {'__dict_items__': [['trigger_name', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
     `553` 'FishingBot._is_trigger_active'
     `554` 'FishingBot._brain_loop'
     `555` 'FishingBot._run_casting_module'
     `556` 'FishingBot._run_hooking_module'
     `557` 'FishingBot._run_reeling_module'
     `558` '_do_casting'
     `559` 'FishingBot._do_casting'
     `560` '_do_hooking'
     `561` 'FishingBot._do_hooking'
     `562` 'FishingBot._do_fish_catch'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fishing_bot\23e725c90_FishingBot.stop.c`

### `FishingBot._monitor_loop`

- implementation: `FUN_23e726bf0`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `541` '\n    Центральная логика бота рыбалки.\n    Запускает мониторинг триггеров в отдельном потоке,\n    принимает решения и вызывает нужные модули.\n    '
     `542` 'FishingBot'
     `543` [None]
     `544` 'FishingBot.__init__'
     `545` 'reload_settings'
     `546` 'FishingBot.reload_settings'
     `547` 'FishingBot.start'
     `548` 'FishingBot.stop'
  => `549` 'FishingBot._monitor_loop'
     `550` {'__dict_items__': [['return', {'__builtin__': 'dict'}]]}
     `551` 'FishingBot._get_triggers'
     `552` {'__dict_items__': [['trigger_name', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
     `553` 'FishingBot._is_trigger_active'
     `554` 'FishingBot._brain_loop'
     `555` 'FishingBot._run_casting_module'
     `556` 'FishingBot._run_hooking_module'
     `557` 'FishingBot._run_reeling_module'
     `558` '_do_casting'
     `559` 'FishingBot._do_casting'
     `560` '_do_hooking'
     `561` 'FishingBot._do_hooking'
     `562` 'FishingBot._do_fish_catch'
     `563` 'FishingBot._handle_pending_tasks'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fishing_bot\23e726bf0_FishingBot._monitor_loop.c`

### `FishingBot._get_triggers`

- implementation: `FUN_23e7280f0`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `543` [None]
     `544` 'FishingBot.__init__'
     `545` 'reload_settings'
     `546` 'FishingBot.reload_settings'
     `547` 'FishingBot.start'
     `548` 'FishingBot.stop'
     `549` 'FishingBot._monitor_loop'
     `550` {'__dict_items__': [['return', {'__builtin__': 'dict'}]]}
  => `551` 'FishingBot._get_triggers'
     `552` {'__dict_items__': [['trigger_name', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
     `553` 'FishingBot._is_trigger_active'
     `554` 'FishingBot._brain_loop'
     `555` 'FishingBot._run_casting_module'
     `556` 'FishingBot._run_hooking_module'
     `557` 'FishingBot._run_reeling_module'
     `558` '_do_casting'
     `559` 'FishingBot._do_casting'
     `560` '_do_hooking'
     `561` 'FishingBot._do_hooking'
     `562` 'FishingBot._do_fish_catch'
     `563` 'FishingBot._handle_pending_tasks'
     `564` {'__dict_items__': [['do_meal', {'__builtin__': 'bool'}], ['do_backpack', {'__builtin__': 'bool'}]]}
     `565` 'FishingBot._do_combined_inventory_tasks'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fishing_bot\23e7280f0_FishingBot._get_triggers.c`

### `FishingBot._is_trigger_active`

- implementation: `FUN_23e7491b0`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `545` 'reload_settings'
     `546` 'FishingBot.reload_settings'
     `547` 'FishingBot.start'
     `548` 'FishingBot.stop'
     `549` 'FishingBot._monitor_loop'
     `550` {'__dict_items__': [['return', {'__builtin__': 'dict'}]]}
     `551` 'FishingBot._get_triggers'
     `552` {'__dict_items__': [['trigger_name', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
  => `553` 'FishingBot._is_trigger_active'
     `554` 'FishingBot._brain_loop'
     `555` 'FishingBot._run_casting_module'
     `556` 'FishingBot._run_hooking_module'
     `557` 'FishingBot._run_reeling_module'
     `558` '_do_casting'
     `559` 'FishingBot._do_casting'
     `560` '_do_hooking'
     `561` 'FishingBot._do_hooking'
     `562` 'FishingBot._do_fish_catch'
     `563` 'FishingBot._handle_pending_tasks'
     `564` {'__dict_items__': [['do_meal', {'__builtin__': 'bool'}], ['do_backpack', {'__builtin__': 'bool'}]]}
     `565` 'FishingBot._do_combined_inventory_tasks'
     `566` 'FishingBot._do_meal_actions'
     `567` 'FishingBot._do_backpack_actions'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fishing_bot\23e7491b0_FishingBot._is_trigger_active.c`

### `FishingBot._brain_loop`

- implementation: `FUN_23e749a20`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `546` 'FishingBot.reload_settings'
     `547` 'FishingBot.start'
     `548` 'FishingBot.stop'
     `549` 'FishingBot._monitor_loop'
     `550` {'__dict_items__': [['return', {'__builtin__': 'dict'}]]}
     `551` 'FishingBot._get_triggers'
     `552` {'__dict_items__': [['trigger_name', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
     `553` 'FishingBot._is_trigger_active'
  => `554` 'FishingBot._brain_loop'
     `555` 'FishingBot._run_casting_module'
     `556` 'FishingBot._run_hooking_module'
     `557` 'FishingBot._run_reeling_module'
     `558` '_do_casting'
     `559` 'FishingBot._do_casting'
     `560` '_do_hooking'
     `561` 'FishingBot._do_hooking'
     `562` 'FishingBot._do_fish_catch'
     `563` 'FishingBot._handle_pending_tasks'
     `564` {'__dict_items__': [['do_meal', {'__builtin__': 'bool'}], ['do_backpack', {'__builtin__': 'bool'}]]}
     `565` 'FishingBot._do_combined_inventory_tasks'
     `566` 'FishingBot._do_meal_actions'
     `567` 'FishingBot._do_backpack_actions'
     `568` '_do_meal_routine'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fishing_bot\23e749a20_FishingBot._brain_loop.c`

### `FishingBot._run_casting_module`

- implementation: `FUN_23e74bd70`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `547` 'FishingBot.start'
     `548` 'FishingBot.stop'
     `549` 'FishingBot._monitor_loop'
     `550` {'__dict_items__': [['return', {'__builtin__': 'dict'}]]}
     `551` 'FishingBot._get_triggers'
     `552` {'__dict_items__': [['trigger_name', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
     `553` 'FishingBot._is_trigger_active'
     `554` 'FishingBot._brain_loop'
  => `555` 'FishingBot._run_casting_module'
     `556` 'FishingBot._run_hooking_module'
     `557` 'FishingBot._run_reeling_module'
     `558` '_do_casting'
     `559` 'FishingBot._do_casting'
     `560` '_do_hooking'
     `561` 'FishingBot._do_hooking'
     `562` 'FishingBot._do_fish_catch'
     `563` 'FishingBot._handle_pending_tasks'
     `564` {'__dict_items__': [['do_meal', {'__builtin__': 'bool'}], ['do_backpack', {'__builtin__': 'bool'}]]}
     `565` 'FishingBot._do_combined_inventory_tasks'
     `566` 'FishingBot._do_meal_actions'
     `567` 'FishingBot._do_backpack_actions'
     `568` '_do_meal_routine'
     `569` 'FishingBot._do_meal_routine'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fishing_bot\23e74bd70_FishingBot._run_casting_module.c`

### `FishingBot._run_hooking_module`

- implementation: `FUN_23e750d60`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `548` 'FishingBot.stop'
     `549` 'FishingBot._monitor_loop'
     `550` {'__dict_items__': [['return', {'__builtin__': 'dict'}]]}
     `551` 'FishingBot._get_triggers'
     `552` {'__dict_items__': [['trigger_name', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
     `553` 'FishingBot._is_trigger_active'
     `554` 'FishingBot._brain_loop'
     `555` 'FishingBot._run_casting_module'
  => `556` 'FishingBot._run_hooking_module'
     `557` 'FishingBot._run_reeling_module'
     `558` '_do_casting'
     `559` 'FishingBot._do_casting'
     `560` '_do_hooking'
     `561` 'FishingBot._do_hooking'
     `562` 'FishingBot._do_fish_catch'
     `563` 'FishingBot._handle_pending_tasks'
     `564` {'__dict_items__': [['do_meal', {'__builtin__': 'bool'}], ['do_backpack', {'__builtin__': 'bool'}]]}
     `565` 'FishingBot._do_combined_inventory_tasks'
     `566` 'FishingBot._do_meal_actions'
     `567` 'FishingBot._do_backpack_actions'
     `568` '_do_meal_routine'
     `569` 'FishingBot._do_meal_routine'
     `570` '_do_store_backpack_routine'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fishing_bot\23e750d60_FishingBot._run_hooking_module.c`

### `FishingBot._run_reeling_module`

- implementation: `FUN_23e7528d0`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `549` 'FishingBot._monitor_loop'
     `550` {'__dict_items__': [['return', {'__builtin__': 'dict'}]]}
     `551` 'FishingBot._get_triggers'
     `552` {'__dict_items__': [['trigger_name', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
     `553` 'FishingBot._is_trigger_active'
     `554` 'FishingBot._brain_loop'
     `555` 'FishingBot._run_casting_module'
     `556` 'FishingBot._run_hooking_module'
  => `557` 'FishingBot._run_reeling_module'
     `558` '_do_casting'
     `559` 'FishingBot._do_casting'
     `560` '_do_hooking'
     `561` 'FishingBot._do_hooking'
     `562` 'FishingBot._do_fish_catch'
     `563` 'FishingBot._handle_pending_tasks'
     `564` {'__dict_items__': [['do_meal', {'__builtin__': 'bool'}], ['do_backpack', {'__builtin__': 'bool'}]]}
     `565` 'FishingBot._do_combined_inventory_tasks'
     `566` 'FishingBot._do_meal_actions'
     `567` 'FishingBot._do_backpack_actions'
     `568` '_do_meal_routine'
     `569` 'FishingBot._do_meal_routine'
     `570` '_do_store_backpack_routine'
     `571` 'FishingBot._do_store_backpack_routine'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fishing_bot\23e7528d0_FishingBot._run_reeling_module.c`

### `FishingBot._do_casting`

- implementation: `FUN_23e754cd0`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `551` 'FishingBot._get_triggers'
     `552` {'__dict_items__': [['trigger_name', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
     `553` 'FishingBot._is_trigger_active'
     `554` 'FishingBot._brain_loop'
     `555` 'FishingBot._run_casting_module'
     `556` 'FishingBot._run_hooking_module'
     `557` 'FishingBot._run_reeling_module'
     `558` '_do_casting'
  => `559` 'FishingBot._do_casting'
     `560` '_do_hooking'
     `561` 'FishingBot._do_hooking'
     `562` 'FishingBot._do_fish_catch'
     `563` 'FishingBot._handle_pending_tasks'
     `564` {'__dict_items__': [['do_meal', {'__builtin__': 'bool'}], ['do_backpack', {'__builtin__': 'bool'}]]}
     `565` 'FishingBot._do_combined_inventory_tasks'
     `566` 'FishingBot._do_meal_actions'
     `567` 'FishingBot._do_backpack_actions'
     `568` '_do_meal_routine'
     `569` 'FishingBot._do_meal_routine'
     `570` '_do_store_backpack_routine'
     `571` 'FishingBot._do_store_backpack_routine'
     `572` 'FishingBot._do_garbage'
     `573` 'FishingBot._do_change_bait'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fishing_bot\23e754cd0_FishingBot._do_casting.c`

### `FishingBot._do_hooking`

- implementation: `FUN_23e7582c0`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `553` 'FishingBot._is_trigger_active'
     `554` 'FishingBot._brain_loop'
     `555` 'FishingBot._run_casting_module'
     `556` 'FishingBot._run_hooking_module'
     `557` 'FishingBot._run_reeling_module'
     `558` '_do_casting'
     `559` 'FishingBot._do_casting'
     `560` '_do_hooking'
  => `561` 'FishingBot._do_hooking'
     `562` 'FishingBot._do_fish_catch'
     `563` 'FishingBot._handle_pending_tasks'
     `564` {'__dict_items__': [['do_meal', {'__builtin__': 'bool'}], ['do_backpack', {'__builtin__': 'bool'}]]}
     `565` 'FishingBot._do_combined_inventory_tasks'
     `566` 'FishingBot._do_meal_actions'
     `567` 'FishingBot._do_backpack_actions'
     `568` '_do_meal_routine'
     `569` 'FishingBot._do_meal_routine'
     `570` '_do_store_backpack_routine'
     `571` 'FishingBot._do_store_backpack_routine'
     `572` 'FishingBot._do_garbage'
     `573` 'FishingBot._do_change_bait'
     `574` 'FishingBot._do_store_trunk'
     `575` 'FishingBot._do_exit_fishing_on_pereves'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fishing_bot\23e7582c0_FishingBot._do_hooking.c`

### `FishingBot._do_fish_catch`

- implementation: `FUN_23e75b480`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `554` 'FishingBot._brain_loop'
     `555` 'FishingBot._run_casting_module'
     `556` 'FishingBot._run_hooking_module'
     `557` 'FishingBot._run_reeling_module'
     `558` '_do_casting'
     `559` 'FishingBot._do_casting'
     `560` '_do_hooking'
     `561` 'FishingBot._do_hooking'
  => `562` 'FishingBot._do_fish_catch'
     `563` 'FishingBot._handle_pending_tasks'
     `564` {'__dict_items__': [['do_meal', {'__builtin__': 'bool'}], ['do_backpack', {'__builtin__': 'bool'}]]}
     `565` 'FishingBot._do_combined_inventory_tasks'
     `566` 'FishingBot._do_meal_actions'
     `567` 'FishingBot._do_backpack_actions'
     `568` '_do_meal_routine'
     `569` 'FishingBot._do_meal_routine'
     `570` '_do_store_backpack_routine'
     `571` 'FishingBot._do_store_backpack_routine'
     `572` 'FishingBot._do_garbage'
     `573` 'FishingBot._do_change_bait'
     `574` 'FishingBot._do_store_trunk'
     `575` 'FishingBot._do_exit_fishing_on_pereves'
     `576` 'FishingBot._wait_for_start_phase'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fishing_bot\23e75b480_FishingBot._do_fish_catch.c`

### `FishingBot._handle_pending_tasks`

- implementation: `FUN_23e75c120`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `555` 'FishingBot._run_casting_module'
     `556` 'FishingBot._run_hooking_module'
     `557` 'FishingBot._run_reeling_module'
     `558` '_do_casting'
     `559` 'FishingBot._do_casting'
     `560` '_do_hooking'
     `561` 'FishingBot._do_hooking'
     `562` 'FishingBot._do_fish_catch'
  => `563` 'FishingBot._handle_pending_tasks'
     `564` {'__dict_items__': [['do_meal', {'__builtin__': 'bool'}], ['do_backpack', {'__builtin__': 'bool'}]]}
     `565` 'FishingBot._do_combined_inventory_tasks'
     `566` 'FishingBot._do_meal_actions'
     `567` 'FishingBot._do_backpack_actions'
     `568` '_do_meal_routine'
     `569` 'FishingBot._do_meal_routine'
     `570` '_do_store_backpack_routine'
     `571` 'FishingBot._do_store_backpack_routine'
     `572` 'FishingBot._do_garbage'
     `573` 'FishingBot._do_change_bait'
     `574` 'FishingBot._do_store_trunk'
     `575` 'FishingBot._do_exit_fishing_on_pereves'
     `576` 'FishingBot._wait_for_start_phase'
     `577` 'FishingBot._exit_fishing'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fishing_bot\23e75c120_FishingBot._handle_pending_tasks.c`

### `FishingBot._do_combined_inventory_tasks`

- implementation: `FUN_23e75d510`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `557` 'FishingBot._run_reeling_module'
     `558` '_do_casting'
     `559` 'FishingBot._do_casting'
     `560` '_do_hooking'
     `561` 'FishingBot._do_hooking'
     `562` 'FishingBot._do_fish_catch'
     `563` 'FishingBot._handle_pending_tasks'
     `564` {'__dict_items__': [['do_meal', {'__builtin__': 'bool'}], ['do_backpack', {'__builtin__': 'bool'}]]}
  => `565` 'FishingBot._do_combined_inventory_tasks'
     `566` 'FishingBot._do_meal_actions'
     `567` 'FishingBot._do_backpack_actions'
     `568` '_do_meal_routine'
     `569` 'FishingBot._do_meal_routine'
     `570` '_do_store_backpack_routine'
     `571` 'FishingBot._do_store_backpack_routine'
     `572` 'FishingBot._do_garbage'
     `573` 'FishingBot._do_change_bait'
     `574` 'FishingBot._do_store_trunk'
     `575` 'FishingBot._do_exit_fishing_on_pereves'
     `576` 'FishingBot._wait_for_start_phase'
     `577` 'FishingBot._exit_fishing'
     `578` 'FishingBot._open_inventory'
     `579` 'FishingBot._return_to_fishing'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fishing_bot\23e75d510_FishingBot._do_combined_inventory_tasks.c`

### `FishingBot._do_meal_actions`

- implementation: `FUN_23e75dc10`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `558` '_do_casting'
     `559` 'FishingBot._do_casting'
     `560` '_do_hooking'
     `561` 'FishingBot._do_hooking'
     `562` 'FishingBot._do_fish_catch'
     `563` 'FishingBot._handle_pending_tasks'
     `564` {'__dict_items__': [['do_meal', {'__builtin__': 'bool'}], ['do_backpack', {'__builtin__': 'bool'}]]}
     `565` 'FishingBot._do_combined_inventory_tasks'
  => `566` 'FishingBot._do_meal_actions'
     `567` 'FishingBot._do_backpack_actions'
     `568` '_do_meal_routine'
     `569` 'FishingBot._do_meal_routine'
     `570` '_do_store_backpack_routine'
     `571` 'FishingBot._do_store_backpack_routine'
     `572` 'FishingBot._do_garbage'
     `573` 'FishingBot._do_change_bait'
     `574` 'FishingBot._do_store_trunk'
     `575` 'FishingBot._do_exit_fishing_on_pereves'
     `576` 'FishingBot._wait_for_start_phase'
     `577` 'FishingBot._exit_fishing'
     `578` 'FishingBot._open_inventory'
     `579` 'FishingBot._return_to_fishing'
     `580` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fishing_bot\23e75dc10_FishingBot._do_meal_actions.c`

### `FishingBot._do_backpack_actions`

- implementation: `FUN_23e7610e0`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `559` 'FishingBot._do_casting'
     `560` '_do_hooking'
     `561` 'FishingBot._do_hooking'
     `562` 'FishingBot._do_fish_catch'
     `563` 'FishingBot._handle_pending_tasks'
     `564` {'__dict_items__': [['do_meal', {'__builtin__': 'bool'}], ['do_backpack', {'__builtin__': 'bool'}]]}
     `565` 'FishingBot._do_combined_inventory_tasks'
     `566` 'FishingBot._do_meal_actions'
  => `567` 'FishingBot._do_backpack_actions'
     `568` '_do_meal_routine'
     `569` 'FishingBot._do_meal_routine'
     `570` '_do_store_backpack_routine'
     `571` 'FishingBot._do_store_backpack_routine'
     `572` 'FishingBot._do_garbage'
     `573` 'FishingBot._do_change_bait'
     `574` 'FishingBot._do_store_trunk'
     `575` 'FishingBot._do_exit_fishing_on_pereves'
     `576` 'FishingBot._wait_for_start_phase'
     `577` 'FishingBot._exit_fishing'
     `578` 'FishingBot._open_inventory'
     `579` 'FishingBot._return_to_fishing'
     `580` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `581` 'FishingBot._try_recover'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fishing_bot\23e7610e0_FishingBot._do_backpack_actions.c`

### `FishingBot._do_meal_routine`

- implementation: `FUN_23e764e30`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `561` 'FishingBot._do_hooking'
     `562` 'FishingBot._do_fish_catch'
     `563` 'FishingBot._handle_pending_tasks'
     `564` {'__dict_items__': [['do_meal', {'__builtin__': 'bool'}], ['do_backpack', {'__builtin__': 'bool'}]]}
     `565` 'FishingBot._do_combined_inventory_tasks'
     `566` 'FishingBot._do_meal_actions'
     `567` 'FishingBot._do_backpack_actions'
     `568` '_do_meal_routine'
  => `569` 'FishingBot._do_meal_routine'
     `570` '_do_store_backpack_routine'
     `571` 'FishingBot._do_store_backpack_routine'
     `572` 'FishingBot._do_garbage'
     `573` 'FishingBot._do_change_bait'
     `574` 'FishingBot._do_store_trunk'
     `575` 'FishingBot._do_exit_fishing_on_pereves'
     `576` 'FishingBot._wait_for_start_phase'
     `577` 'FishingBot._exit_fishing'
     `578` 'FishingBot._open_inventory'
     `579` 'FishingBot._return_to_fishing'
     `580` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `581` 'FishingBot._try_recover'
     `582` {'__dict_items__': [['seconds', {'__builtin__': 'float'}]]}
     `583` 'FishingBot._sleep'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fishing_bot\23e764e30_FishingBot._do_meal_routine.c`

### `FishingBot._do_store_backpack_routine`

- implementation: `FUN_23e769800`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `563` 'FishingBot._handle_pending_tasks'
     `564` {'__dict_items__': [['do_meal', {'__builtin__': 'bool'}], ['do_backpack', {'__builtin__': 'bool'}]]}
     `565` 'FishingBot._do_combined_inventory_tasks'
     `566` 'FishingBot._do_meal_actions'
     `567` 'FishingBot._do_backpack_actions'
     `568` '_do_meal_routine'
     `569` 'FishingBot._do_meal_routine'
     `570` '_do_store_backpack_routine'
  => `571` 'FishingBot._do_store_backpack_routine'
     `572` 'FishingBot._do_garbage'
     `573` 'FishingBot._do_change_bait'
     `574` 'FishingBot._do_store_trunk'
     `575` 'FishingBot._do_exit_fishing_on_pereves'
     `576` 'FishingBot._wait_for_start_phase'
     `577` 'FishingBot._exit_fishing'
     `578` 'FishingBot._open_inventory'
     `579` 'FishingBot._return_to_fishing'
     `580` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `581` 'FishingBot._try_recover'
     `582` {'__dict_items__': [['seconds', {'__builtin__': 'float'}]]}
     `583` 'FishingBot._sleep'
     `584` 'FishingBot._load_fish_names'
     `585` {'__dict_items__': [['fish_name_eng', {'__builtin__': 'str'}], ['return', {'__builtin__': 'str'}]]}
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fishing_bot\23e769800_FishingBot._do_store_backpack_routine.c`

### `FishingBot._do_garbage`

- implementation: `FUN_23e769f00`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `564` {'__dict_items__': [['do_meal', {'__builtin__': 'bool'}], ['do_backpack', {'__builtin__': 'bool'}]]}
     `565` 'FishingBot._do_combined_inventory_tasks'
     `566` 'FishingBot._do_meal_actions'
     `567` 'FishingBot._do_backpack_actions'
     `568` '_do_meal_routine'
     `569` 'FishingBot._do_meal_routine'
     `570` '_do_store_backpack_routine'
     `571` 'FishingBot._do_store_backpack_routine'
  => `572` 'FishingBot._do_garbage'
     `573` 'FishingBot._do_change_bait'
     `574` 'FishingBot._do_store_trunk'
     `575` 'FishingBot._do_exit_fishing_on_pereves'
     `576` 'FishingBot._wait_for_start_phase'
     `577` 'FishingBot._exit_fishing'
     `578` 'FishingBot._open_inventory'
     `579` 'FishingBot._return_to_fishing'
     `580` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `581` 'FishingBot._try_recover'
     `582` {'__dict_items__': [['seconds', {'__builtin__': 'float'}]]}
     `583` 'FishingBot._sleep'
     `584` 'FishingBot._load_fish_names'
     `585` {'__dict_items__': [['fish_name_eng', {'__builtin__': 'str'}], ['return', {'__builtin__': 'str'}]]}
     `586` '_get_fish_name_ru'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fishing_bot\23e769f00_FishingBot._do_garbage.c`

### `FishingBot._do_change_bait`

- implementation: `FUN_23e76e6f0`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `565` 'FishingBot._do_combined_inventory_tasks'
     `566` 'FishingBot._do_meal_actions'
     `567` 'FishingBot._do_backpack_actions'
     `568` '_do_meal_routine'
     `569` 'FishingBot._do_meal_routine'
     `570` '_do_store_backpack_routine'
     `571` 'FishingBot._do_store_backpack_routine'
     `572` 'FishingBot._do_garbage'
  => `573` 'FishingBot._do_change_bait'
     `574` 'FishingBot._do_store_trunk'
     `575` 'FishingBot._do_exit_fishing_on_pereves'
     `576` 'FishingBot._wait_for_start_phase'
     `577` 'FishingBot._exit_fishing'
     `578` 'FishingBot._open_inventory'
     `579` 'FishingBot._return_to_fishing'
     `580` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `581` 'FishingBot._try_recover'
     `582` {'__dict_items__': [['seconds', {'__builtin__': 'float'}]]}
     `583` 'FishingBot._sleep'
     `584` 'FishingBot._load_fish_names'
     `585` {'__dict_items__': [['fish_name_eng', {'__builtin__': 'str'}], ['return', {'__builtin__': 'str'}]]}
     `586` '_get_fish_name_ru'
     `587` 'FishingBot._get_fish_name_ru'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fishing_bot\23e76e6f0_FishingBot._do_change_bait.c`

### `FishingBot._do_store_trunk`

- implementation: `FUN_23e76edf0`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `566` 'FishingBot._do_meal_actions'
     `567` 'FishingBot._do_backpack_actions'
     `568` '_do_meal_routine'
     `569` 'FishingBot._do_meal_routine'
     `570` '_do_store_backpack_routine'
     `571` 'FishingBot._do_store_backpack_routine'
     `572` 'FishingBot._do_garbage'
     `573` 'FishingBot._do_change_bait'
  => `574` 'FishingBot._do_store_trunk'
     `575` 'FishingBot._do_exit_fishing_on_pereves'
     `576` 'FishingBot._wait_for_start_phase'
     `577` 'FishingBot._exit_fishing'
     `578` 'FishingBot._open_inventory'
     `579` 'FishingBot._return_to_fishing'
     `580` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `581` 'FishingBot._try_recover'
     `582` {'__dict_items__': [['seconds', {'__builtin__': 'float'}]]}
     `583` 'FishingBot._sleep'
     `584` 'FishingBot._load_fish_names'
     `585` {'__dict_items__': [['fish_name_eng', {'__builtin__': 'str'}], ['return', {'__builtin__': 'str'}]]}
     `586` '_get_fish_name_ru'
     `587` 'FishingBot._get_fish_name_ru'
     `588` {'__dict_items__': [['msg', {'__builtin__': 'str'}]]}
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fishing_bot\23e76edf0_FishingBot._do_store_trunk.c`

### `FishingBot._do_exit_fishing_on_pereves`

- implementation: `FUN_23e7724a0`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `567` 'FishingBot._do_backpack_actions'
     `568` '_do_meal_routine'
     `569` 'FishingBot._do_meal_routine'
     `570` '_do_store_backpack_routine'
     `571` 'FishingBot._do_store_backpack_routine'
     `572` 'FishingBot._do_garbage'
     `573` 'FishingBot._do_change_bait'
     `574` 'FishingBot._do_store_trunk'
  => `575` 'FishingBot._do_exit_fishing_on_pereves'
     `576` 'FishingBot._wait_for_start_phase'
     `577` 'FishingBot._exit_fishing'
     `578` 'FishingBot._open_inventory'
     `579` 'FishingBot._return_to_fishing'
     `580` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `581` 'FishingBot._try_recover'
     `582` {'__dict_items__': [['seconds', {'__builtin__': 'float'}]]}
     `583` 'FishingBot._sleep'
     `584` 'FishingBot._load_fish_names'
     `585` {'__dict_items__': [['fish_name_eng', {'__builtin__': 'str'}], ['return', {'__builtin__': 'str'}]]}
     `586` '_get_fish_name_ru'
     `587` 'FishingBot._get_fish_name_ru'
     `588` {'__dict_items__': [['msg', {'__builtin__': 'str'}]]}
     `589` 'FishingBot._log'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fishing_bot\23e7724a0_FishingBot._do_exit_fishing_on_pereves.c`

### `FishingBot._wait_for_start_phase`

- implementation: `FUN_23e773110`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `568` '_do_meal_routine'
     `569` 'FishingBot._do_meal_routine'
     `570` '_do_store_backpack_routine'
     `571` 'FishingBot._do_store_backpack_routine'
     `572` 'FishingBot._do_garbage'
     `573` 'FishingBot._do_change_bait'
     `574` 'FishingBot._do_store_trunk'
     `575` 'FishingBot._do_exit_fishing_on_pereves'
  => `576` 'FishingBot._wait_for_start_phase'
     `577` 'FishingBot._exit_fishing'
     `578` 'FishingBot._open_inventory'
     `579` 'FishingBot._return_to_fishing'
     `580` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `581` 'FishingBot._try_recover'
     `582` {'__dict_items__': [['seconds', {'__builtin__': 'float'}]]}
     `583` 'FishingBot._sleep'
     `584` 'FishingBot._load_fish_names'
     `585` {'__dict_items__': [['fish_name_eng', {'__builtin__': 'str'}], ['return', {'__builtin__': 'str'}]]}
     `586` '_get_fish_name_ru'
     `587` 'FishingBot._get_fish_name_ru'
     `588` {'__dict_items__': [['msg', {'__builtin__': 'str'}]]}
     `589` 'FishingBot._log'
     `590` {'__dict_items__': [['return', {'__builtin__': 'bytes'}]]}
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fishing_bot\23e773110_FishingBot._wait_for_start_phase.c`

### `FishingBot._exit_fishing`

- implementation: `FUN_23e778710`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `569` 'FishingBot._do_meal_routine'
     `570` '_do_store_backpack_routine'
     `571` 'FishingBot._do_store_backpack_routine'
     `572` 'FishingBot._do_garbage'
     `573` 'FishingBot._do_change_bait'
     `574` 'FishingBot._do_store_trunk'
     `575` 'FishingBot._do_exit_fishing_on_pereves'
     `576` 'FishingBot._wait_for_start_phase'
  => `577` 'FishingBot._exit_fishing'
     `578` 'FishingBot._open_inventory'
     `579` 'FishingBot._return_to_fishing'
     `580` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `581` 'FishingBot._try_recover'
     `582` {'__dict_items__': [['seconds', {'__builtin__': 'float'}]]}
     `583` 'FishingBot._sleep'
     `584` 'FishingBot._load_fish_names'
     `585` {'__dict_items__': [['fish_name_eng', {'__builtin__': 'str'}], ['return', {'__builtin__': 'str'}]]}
     `586` '_get_fish_name_ru'
     `587` 'FishingBot._get_fish_name_ru'
     `588` {'__dict_items__': [['msg', {'__builtin__': 'str'}]]}
     `589` 'FishingBot._log'
     `590` {'__dict_items__': [['return', {'__builtin__': 'bytes'}]]}
     `591` 'FishingBot._capture_screenshot_bytes'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fishing_bot\23e778710_FishingBot._exit_fishing.c`

### `FishingBot._open_inventory`

- implementation: `FUN_23e7790f0`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `570` '_do_store_backpack_routine'
     `571` 'FishingBot._do_store_backpack_routine'
     `572` 'FishingBot._do_garbage'
     `573` 'FishingBot._do_change_bait'
     `574` 'FishingBot._do_store_trunk'
     `575` 'FishingBot._do_exit_fishing_on_pereves'
     `576` 'FishingBot._wait_for_start_phase'
     `577` 'FishingBot._exit_fishing'
  => `578` 'FishingBot._open_inventory'
     `579` 'FishingBot._return_to_fishing'
     `580` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `581` 'FishingBot._try_recover'
     `582` {'__dict_items__': [['seconds', {'__builtin__': 'float'}]]}
     `583` 'FishingBot._sleep'
     `584` 'FishingBot._load_fish_names'
     `585` {'__dict_items__': [['fish_name_eng', {'__builtin__': 'str'}], ['return', {'__builtin__': 'str'}]]}
     `586` '_get_fish_name_ru'
     `587` 'FishingBot._get_fish_name_ru'
     `588` {'__dict_items__': [['msg', {'__builtin__': 'str'}]]}
     `589` 'FishingBot._log'
     `590` {'__dict_items__': [['return', {'__builtin__': 'bytes'}]]}
     `591` 'FishingBot._capture_screenshot_bytes'
     `592` 'workers\\fishing\\fishing_bot.py'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fishing_bot\23e7790f0_FishingBot._open_inventory.c`

### `FishingBot._return_to_fishing`

- implementation: `FUN_23e779790`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `571` 'FishingBot._do_store_backpack_routine'
     `572` 'FishingBot._do_garbage'
     `573` 'FishingBot._do_change_bait'
     `574` 'FishingBot._do_store_trunk'
     `575` 'FishingBot._do_exit_fishing_on_pereves'
     `576` 'FishingBot._wait_for_start_phase'
     `577` 'FishingBot._exit_fishing'
     `578` 'FishingBot._open_inventory'
  => `579` 'FishingBot._return_to_fishing'
     `580` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `581` 'FishingBot._try_recover'
     `582` {'__dict_items__': [['seconds', {'__builtin__': 'float'}]]}
     `583` 'FishingBot._sleep'
     `584` 'FishingBot._load_fish_names'
     `585` {'__dict_items__': [['fish_name_eng', {'__builtin__': 'str'}], ['return', {'__builtin__': 'str'}]]}
     `586` '_get_fish_name_ru'
     `587` 'FishingBot._get_fish_name_ru'
     `588` {'__dict_items__': [['msg', {'__builtin__': 'str'}]]}
     `589` 'FishingBot._log'
     `590` {'__dict_items__': [['return', {'__builtin__': 'bytes'}]]}
     `591` 'FishingBot._capture_screenshot_bytes'
     `592` 'workers\\fishing\\fishing_bot.py'
     `593` ['.0', 't', 'current_triggers']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fishing_bot\23e779790_FishingBot._return_to_fishing.c`

### `FishingBot._try_recover`

- implementation: `FUN_23e779ca0`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `573` 'FishingBot._do_change_bait'
     `574` 'FishingBot._do_store_trunk'
     `575` 'FishingBot._do_exit_fishing_on_pereves'
     `576` 'FishingBot._wait_for_start_phase'
     `577` 'FishingBot._exit_fishing'
     `578` 'FishingBot._open_inventory'
     `579` 'FishingBot._return_to_fishing'
     `580` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
  => `581` 'FishingBot._try_recover'
     `582` {'__dict_items__': [['seconds', {'__builtin__': 'float'}]]}
     `583` 'FishingBot._sleep'
     `584` 'FishingBot._load_fish_names'
     `585` {'__dict_items__': [['fish_name_eng', {'__builtin__': 'str'}], ['return', {'__builtin__': 'str'}]]}
     `586` '_get_fish_name_ru'
     `587` 'FishingBot._get_fish_name_ru'
     `588` {'__dict_items__': [['msg', {'__builtin__': 'str'}]]}
     `589` 'FishingBot._log'
     `590` {'__dict_items__': [['return', {'__builtin__': 'bytes'}]]}
     `591` 'FishingBot._capture_screenshot_bytes'
     `592` 'workers\\fishing\\fishing_bot.py'
     `593` ['.0', 't', 'current_triggers']
     `594` ['.0', 'v']
     `595` '<module workers.fishing.fishing_bot>'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fishing_bot\23e779ca0_FishingBot._try_recover.c`

### `FishingBot._sleep`

- implementation: `FUN_23e77a2d0`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `575` 'FishingBot._do_exit_fishing_on_pereves'
     `576` 'FishingBot._wait_for_start_phase'
     `577` 'FishingBot._exit_fishing'
     `578` 'FishingBot._open_inventory'
     `579` 'FishingBot._return_to_fishing'
     `580` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `581` 'FishingBot._try_recover'
     `582` {'__dict_items__': [['seconds', {'__builtin__': 'float'}]]}
  => `583` 'FishingBot._sleep'
     `584` 'FishingBot._load_fish_names'
     `585` {'__dict_items__': [['fish_name_eng', {'__builtin__': 'str'}], ['return', {'__builtin__': 'str'}]]}
     `586` '_get_fish_name_ru'
     `587` 'FishingBot._get_fish_name_ru'
     `588` {'__dict_items__': [['msg', {'__builtin__': 'str'}]]}
     `589` 'FishingBot._log'
     `590` {'__dict_items__': [['return', {'__builtin__': 'bytes'}]]}
     `591` 'FishingBot._capture_screenshot_bytes'
     `592` 'workers\\fishing\\fishing_bot.py'
     `593` ['.0', 't', 'current_triggers']
     `594` ['.0', 'v']
     `595` '<module workers.fishing.fishing_bot>'
     `596` ['__class__']
     `597` ['self', 'log_callback']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fishing_bot\23e77a2d0_FishingBot._sleep.c`

### `FishingBot._load_fish_names`

- implementation: `FUN_23e77ae10`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `576` 'FishingBot._wait_for_start_phase'
     `577` 'FishingBot._exit_fishing'
     `578` 'FishingBot._open_inventory'
     `579` 'FishingBot._return_to_fishing'
     `580` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `581` 'FishingBot._try_recover'
     `582` {'__dict_items__': [['seconds', {'__builtin__': 'float'}]]}
     `583` 'FishingBot._sleep'
  => `584` 'FishingBot._load_fish_names'
     `585` {'__dict_items__': [['fish_name_eng', {'__builtin__': 'str'}], ['return', {'__builtin__': 'str'}]]}
     `586` '_get_fish_name_ru'
     `587` 'FishingBot._get_fish_name_ru'
     `588` {'__dict_items__': [['msg', {'__builtin__': 'str'}]]}
     `589` 'FishingBot._log'
     `590` {'__dict_items__': [['return', {'__builtin__': 'bytes'}]]}
     `591` 'FishingBot._capture_screenshot_bytes'
     `592` 'workers\\fishing\\fishing_bot.py'
     `593` ['.0', 't', 'current_triggers']
     `594` ['.0', 'v']
     `595` '<module workers.fishing.fishing_bot>'
     `596` ['__class__']
     `597` ['self', 'log_callback']
     `598` ['self', 'triggers', 'boat_human', 'fishing_stages', 'ad_buttons', 'is_compiled', 'failed', 'has_boat', 'has_human', 'needs', 'current_hunger', 'current_thirst', 'events', 'current_advantage', 'current_pereves', 'e', 'notif_mgr', 'shutdown_pending', '_time', 'os', 'current_cha...
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fishing_bot\23e77ae10_FishingBot._load_fish_names.c`

### `FishingBot._get_fish_name_ru`

- implementation: `FUN_23e77e4b0`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `579` 'FishingBot._return_to_fishing'
     `580` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `581` 'FishingBot._try_recover'
     `582` {'__dict_items__': [['seconds', {'__builtin__': 'float'}]]}
     `583` 'FishingBot._sleep'
     `584` 'FishingBot._load_fish_names'
     `585` {'__dict_items__': [['fish_name_eng', {'__builtin__': 'str'}], ['return', {'__builtin__': 'str'}]]}
     `586` '_get_fish_name_ru'
  => `587` 'FishingBot._get_fish_name_ru'
     `588` {'__dict_items__': [['msg', {'__builtin__': 'str'}]]}
     `589` 'FishingBot._log'
     `590` {'__dict_items__': [['return', {'__builtin__': 'bytes'}]]}
     `591` 'FishingBot._capture_screenshot_bytes'
     `592` 'workers\\fishing\\fishing_bot.py'
     `593` ['.0', 't', 'current_triggers']
     `594` ['.0', 'v']
     `595` '<module workers.fishing.fishing_bot>'
     `596` ['__class__']
     `597` ['self', 'log_callback']
     `598` ['self', 'triggers', 'boat_human', 'fishing_stages', 'ad_buttons', 'is_compiled', 'failed', 'has_boat', 'has_human', 'needs', 'current_hunger', 'current_thirst', 'events', 'current_advantage', 'current_pereves', 'e', 'notif_mgr', 'shutdown_pending', '_time', 'os', 'current_cha...
     `599` ['self', 'Image', 'frame', 'frame_rgb', 'img', 'buf', 'e']
     `600` ['self', 'storer', 'STORE_ROI_2K', 'STORE_ROI_FHD', 'fish_stored_count', 'backpack_full', 'screenshot', 'fish_positions', 'total_fish_count', 'notif_mgr', 'fish_info', 'success', 'e']
     `601` ['self', 'roi', 'monitor', 'timeout', 'frame', 'green_count', '_', 'pressed']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fishing_bot\23e77e4b0_FishingBot._get_fish_name_ru.c`

### `FishingBot._log`

- implementation: `FUN_23e77e960`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `581` 'FishingBot._try_recover'
     `582` {'__dict_items__': [['seconds', {'__builtin__': 'float'}]]}
     `583` 'FishingBot._sleep'
     `584` 'FishingBot._load_fish_names'
     `585` {'__dict_items__': [['fish_name_eng', {'__builtin__': 'str'}], ['return', {'__builtin__': 'str'}]]}
     `586` '_get_fish_name_ru'
     `587` 'FishingBot._get_fish_name_ru'
     `588` {'__dict_items__': [['msg', {'__builtin__': 'str'}]]}
  => `589` 'FishingBot._log'
     `590` {'__dict_items__': [['return', {'__builtin__': 'bytes'}]]}
     `591` 'FishingBot._capture_screenshot_bytes'
     `592` 'workers\\fishing\\fishing_bot.py'
     `593` ['.0', 't', 'current_triggers']
     `594` ['.0', 'v']
     `595` '<module workers.fishing.fishing_bot>'
     `596` ['__class__']
     `597` ['self', 'log_callback']
     `598` ['self', 'triggers', 'boat_human', 'fishing_stages', 'ad_buttons', 'is_compiled', 'failed', 'has_boat', 'has_human', 'needs', 'current_hunger', 'current_thirst', 'events', 'current_advantage', 'current_pereves', 'e', 'notif_mgr', 'shutdown_pending', '_time', 'os', 'current_cha...
     `599` ['self', 'Image', 'frame', 'frame_rgb', 'img', 'buf', 'e']
     `600` ['self', 'storer', 'STORE_ROI_2K', 'STORE_ROI_FHD', 'fish_stored_count', 'backpack_full', 'screenshot', 'fish_positions', 'total_fish_count', 'notif_mgr', 'fish_info', 'success', 'e']
     `601` ['self', 'roi', 'monitor', 'timeout', 'frame', 'green_count', '_', 'pressed']
     `602` ['self', 'notif_mgr']
     `603` ['self', 'do_meal', 'do_backpack', 'garbage_settings', 'has_garbage_to_eject']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fishing_bot\23e77e960_FishingBot._log.c`

### `FishingBot._capture_screenshot_bytes`

- implementation: `FUN_23e77f390`
- source line hint: `?`
- Nuitka codevar: `?`
- factory: `INFERRED_ADDRESS_RANGE`
- nearby constants:
     `583` 'FishingBot._sleep'
     `584` 'FishingBot._load_fish_names'
     `585` {'__dict_items__': [['fish_name_eng', {'__builtin__': 'str'}], ['return', {'__builtin__': 'str'}]]}
     `586` '_get_fish_name_ru'
     `587` 'FishingBot._get_fish_name_ru'
     `588` {'__dict_items__': [['msg', {'__builtin__': 'str'}]]}
     `589` 'FishingBot._log'
     `590` {'__dict_items__': [['return', {'__builtin__': 'bytes'}]]}
  => `591` 'FishingBot._capture_screenshot_bytes'
     `592` 'workers\\fishing\\fishing_bot.py'
     `593` ['.0', 't', 'current_triggers']
     `594` ['.0', 'v']
     `595` '<module workers.fishing.fishing_bot>'
     `596` ['__class__']
     `597` ['self', 'log_callback']
     `598` ['self', 'triggers', 'boat_human', 'fishing_stages', 'ad_buttons', 'is_compiled', 'failed', 'has_boat', 'has_human', 'needs', 'current_hunger', 'current_thirst', 'events', 'current_advantage', 'current_pereves', 'e', 'notif_mgr', 'shutdown_pending', '_time', 'os', 'current_cha...
     `599` ['self', 'Image', 'frame', 'frame_rgb', 'img', 'buf', 'e']
     `600` ['self', 'storer', 'STORE_ROI_2K', 'STORE_ROI_FHD', 'fish_stored_count', 'backpack_full', 'screenshot', 'fish_positions', 'total_fish_count', 'notif_mgr', 'fish_info', 'success', 'e']
     `601` ['self', 'roi', 'monitor', 'timeout', 'frame', 'green_count', '_', 'pressed']
     `602` ['self', 'notif_mgr']
     `603` ['self', 'do_meal', 'do_backpack', 'garbage_settings', 'has_garbage_to_eject']
     `604` ['self']
     `605` ['self', 'fish_to_keep', 'fish_to_release', 'all_release', 'take_coord', 'release_coord', 'catch', 'eng_key', 'ru_name', 'weight', 'screenshot_bytes', 'notif_mgr']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\workers__fishing__fishing_bot\23e77f390_FishingBot._capture_screenshot_bytes.c`
