# Coverage Report

Mapped/decompiled implementation functions: 367
Modules in constant blob: 44

## Modules With Decompiled Implementations

| Module | Implementations |
|---|---:|
| `workers.fishing.fishing_bot` | 35 |
| `workers.fishing.memory_reeling` | 21 |
| `workers.fishing.meal_system` | 18 |
| `workers.fishing.trigger_monitor` | 18 |
| `telegram.notification_manager` | 16 |
| `license.license_client` | 15 |
| `workers.fishing.garbage_disposal` | 15 |
| `workers.fishing.memory_fish_reader` | 15 |
| `workers.fishing.store_fish` | 13 |
| `workers.fishing.fish_recognition` | 12 |
| `__parents_main__` | 11 |
| `ui.fish_settings_dialog` | 11 |
| `ui.garbage_settings_dialog` | 11 |
| `ui.hotkey_dialog` | 11 |
| `workers.fishing.casting_a_fishing_rod` | 11 |
| `workers.fishing.window_capture` | 11 |
| `__main__` | 10 |
| `ui.home_tab` | 10 |
| `ui.hotkey_listener` | 10 |
| `ui.telegram_tab` | 10 |
| `workers.fishing.hooking` | 10 |
| `config_manager` | 8 |
| `ui.ios_toggle` | 8 |
| `license.activation_dialog` | 7 |
| `telegram.bot_manager` | 6 |
| `telegram.handlers.fishing_handler` | 6 |
| `ui.main_window` | 6 |
| `workers.fishing.window_activator` | 6 |
| `telegram.handlers.menu_handler` | 5 |
| `license.hwid_generator` | 4 |
| `telegram.handlers.screenshot_handler` | 4 |
| `workers.fishing.path_utils` | 4 |
| `telegram.handlers.system_handler` | 3 |
| `ui.fishing_tab` | 3 |
| `telegram.handlers.notifications_handler` | 2 |
| `telegram.handlers.fish_names_map` | 1 |

## Known Gaps / Notes

- Package-only modules (`license`, `telegram`, `ui`, `workers`, `workers.fishing`) have no implementation bodies because they only initialise package namespaces.
- `workers.fishing.memory_reeling` has 21 recovered native implementation bodies while constants list 25 `MemoryReelingTracker.*` qualnames; the remaining methods are still represented by constants/local-variable lists and may be inlined or require a lower-level pass.
- `workers.fishing.fishing_bot` is covered through inferred address-range mapping because its module init does not use the standard Nuitka function factories, even after successful decompilation.
- Exact original Python text is not present in the Nuitka binary; reports combine constants, local variable names, source-line hints where available, and Ghidra C pseudocode.
