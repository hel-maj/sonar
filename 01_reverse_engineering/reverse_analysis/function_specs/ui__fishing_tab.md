# Function Specification: `ui.fishing_tab`

This is a reconstruction dossier from static Nuitka constants and Ghidra decompilation. It is not original Python source text.

## Source Path Hints
- `ui\fishing_tab.py`

## Docstrings / Long Text
- `184` '\n        Убедиться что слушатель хоткеев активен и работает.\n        Вызывается после остановки бота для восстановления работы хоткеев.\n        '
- `208` '\n        Периодическая проверка здоровья hotkey listener.\n        Вызывается таймером каждые 5 секунд.\n        '
- `234` '\nВкладка "Рыбалка" для KortexWorker\nСодержит все настройки рыбалки в iOS-стиле\n'
- `289` '@pyqtSlot()\ndef _on_bot_finished(self):\n    """Бот завершился (аварийно или по ошибке)"""\n    if self.is_running:\n        self.is_running = False\n        self.start_stop_btn.setText(\'▶ ЗАПУСТИТЬ\')\n        self.start_stop_btn.setStyleSheet(\'\\n                QPushButton {\\n                    background-color: #FF0080;\\n                    color: #FFFFFF;\\n                    border: none;\\n                    border-radius: 14px;\\n                    font-size: 14px;\\n       ...

## Function Inventory
| Inferred qualname | Impl | Source line | Arg count | Decompiled C |
|---|---:|---:|---:|---|
| `workers.fishing.fishing_bot` | `FUN_23e2808b0` | ? | ? | yes |
| `workers.fishing.window_activator` | `FUN_23e280ed0` | ? | ? | yes |
| `BotWorkerThread.__init__` | `FUN_23e281710` | ? | ? | yes |

## Local Variable Lists
- `306` `self`
- `308` `__class__`
- `309` `self, fishing_bot, parent, __class__`
- `310` `self, parent, FishingBot, set_fishing_bot, __class__`
- `311` `self, settings, hotkey, listener_exists, has_is_alive, is_alive, is_running, has_callback, has_hotkey, listener_healthy, time, current_time, e, traceback`
- `312` `self, is_alive, e, new_is_alive, traceback`
- `313` `self, current_key, dialog, new_key, settings`
- `314` `self, current_hotkey, dialog, new_hotkey, settings`
- `315` `self, event, __class__`
- `316` `self, title, description, layout, text_layout, title_label, desc_label, toggle`
- `317` `self, main_layout, scroll, scroll_widget, scroll_layout, font, main_title, bait_layout, fish_settings_btn, garbage_settings_btn, meal_layout, backpack_layout, trunk_layout, shutdown_layout, hotkey_title, hotkey_btn, discard_key_btn`
- `318` `self, settings, discard_key`
- `319` `self, FishSettingsDialog, dialog`
- `320` `self, GarbageSettingsDialog, dialog`
- `321` `self, settings, current_config`
- `322` `self, settings`
- `323` `self, settings, hotkey`
- `324` `self, initial_state, main_window, WindowActivator, e`

## Structured Constants
- `5` [200]
- `31` [5000]
- `39` [0]
- `42` [True]
- `114` [2]
- `160` {'__dict_items__': [['title', 'Назначение клавиши выброса']]}
- `199` [None, None, None]
- `215` {'__dict_items__': [['bag', True], ['corn', True], ['pack', True]]}
- `257` [5, 30, 5, 30]
- `258` [0, 0, 0, 0]
- `264` [0, 8, 0, 8]
- `277` [None]

## Per-Function Context
### `workers.fishing.fishing_bot`

- implementation: `FUN_23e2808b0`
- source line hint: `?`
- Nuitka codevar: `uVar12`
- factory: `FUN_23e93e480`
- nearby constants:
     `9` 'is_running'
     `10` '_toggling'
     `11` 'ConfigManager'
     `12` 'config_manager'
     `13` 'get_global_listener'
     `14` 'hotkey_listener'
     `15` 'hotkey_label'
     `16` '_bot_thread'
  => `17` 'workers.fishing.fishing_bot'
     `18` ['FishingBot']
     `19` 'FishingBot'
     `20` 'telegram.handlers.fishing_handler'
     `21` ['set_fishing_bot']
     `22` 'set_fishing_bot'
     `23` '_fishing_bot'
     `24` 'hotkey_pressed_signal'
     `25` 'connect'
     `26` 'toggle_bot'
     `27` 'QTimer'
     `28` '_hotkey_monitor_timer'
     `29` 'timeout'
     `30` '_check_hotkey_listener_health'
     `31` [5000]
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__fishing_tab\23e2808b0_workers.fishing.fishing_bot.c`

### `workers.fishing.window_activator`

- implementation: `FUN_23e280ed0`
- source line hint: `?`
- Nuitka codevar: `_DAT_23eeb0638`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `124` 'setText'
     `125` ['\n                    QPushButton {\n                        background-color: #FF0080;\n                        color: #FFFFFF;\n                        border: none;\n                        border-radius: 14px;\n                        font-size: 14px;\n                  ...
     `126` 'stop_bot'
     `127` 'stop_bot_signal'
     `128` ['⏹ ОСТАНОВИТЬ']
     `129` ['\n                    QPushButton {\n                        background-color: #FF3B30;\n                        color: #FFFFFF;\n                        border: none;\n                        border-radius: 14px;\n                        font-size: 14px;\n                  ...
     `130` 'window'
     `131` 'showMinimized'
  => `132` 'workers.fishing.window_activator'
     `133` ['WindowActivator']
     `134` 'WindowActivator'
     `135` 'force_activate_gta5'
     `136` '[ERROR] Ошибка при активации окна GTA5: '
     `137` 'BotWorkerThread'
     `138` '_on_bot_finished'
     `139` 'start_bot_signal'
     `140` 'Переключить состояние бота (thread-safe для hotkey)'
     `141` 'fish_settings_dialog'
     `142` ['FishSettingsDialog']
     `143` 'FishSettingsDialog'
     `144` 'exec'
     `145` 'Открыть диалог настроек рыбы'
     `146` 'garbage_settings_dialog'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__fishing_tab\23e280ed0_workers.fishing.window_activator.c`

### `BotWorkerThread.__init__`

- implementation: `FUN_23e281710`
- source line hint: `?`
- Nuitka codevar: `_DAT_23eeb0618`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `270` '__prepare__'
     `271` '__getitem__'
     `272` '%s.__prepare__() must return a mapping, not %s'
     `273` '<metaclass>'
     `274` 'ui.fishing_tab'
     `275` 'Рабочий поток для запуска бота рыбалки'
     `276` '__qualname__'
     `277` [None]
  => `278` 'BotWorkerThread.__init__'
     `279` 'run'
     `280` 'BotWorkerThread.run'
     `281` 'BotWorkerThread.stop_bot'
     `282` '__orig_bases__'
     `283` 'FishingTab'
     `284` 'Вкладка настроек рыбалки'
     `285` 'FishingTab.__init__'
     `286` 'FishingTab.init_ui'
     `287` 'FishingTab.create_toggle_row'
     `288` 'FishingTab.toggle_bot'
     `289` '@pyqtSlot()\ndef _on_bot_finished(self):\n    """Бот завершился (аварийно или по ошибке)"""\n    if self.is_running:\n        self.is_running = False\n        self.start_stop_btn.setText(\'▶ ЗАПУСТИТЬ\')\n        self.start_stop_btn.setStyleSheet(\'\\n                QPushBut...
     `290` '<string>'
     `291` 'FishingTab.open_fish_settings'
     `292` 'FishingTab.open_garbage_settings'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__fishing_tab\23e281710_BotWorkerThread.__init.c`
