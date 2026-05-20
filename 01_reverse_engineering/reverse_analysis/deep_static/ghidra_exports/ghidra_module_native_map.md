# Ghidra native module map

Direct xrefs from Ghidra string labels to Nuitka module init functions.

| Module/string | Function entry | Size | Decompile | Ref from |
|---|---:|---:|---|---:|
| `config_manager` | `23c003b30` | 4719 | ok | `23c004b30` |
| `telegram.bot_manager` | `23e152d50` | 11573 | ok | `23e1539b0` |
| `telegram.handlers.fish_names_map` | `23e113b10` | 1917 | ok | `23e114180` |
| `telegram.handlers.fishing_handle` | `23e1194c0` | 6818 | ok | `23e11a320` |
| `telegram.handlers.menu_handler` | `23e11e9d0` | 6388 | ok | `23e11f610` |
| `telegram.handlers.notifications_` | `23e1243e0` | 4881 | ok | `23e124f00` |
| `telegram.handlers.screenshot_han` | `23e126df0` | 6346 | ok | `23e127a00` |
| `telegram.handlers.system_handler` | `23e12b100` | 4515 | ok | `23e12bc40` |
| `telegram.notification_manager` | `23e135d90` | 10341 | ok | `23e136ed0` |
| `ui.fish_settings_dialog` | `23e27d000` | 14327 | ok | `23e27d9b8` |
| `ui.fishing_tab` | `23e29f090` | 27510 | ok | `23e29fa40` |
| `ui.garbage_settings_dialog` | `23e2b1cd0` | 14327 | ok | `23e2b2688` |
| `ui.home_tab` | `23e2d6140` | 13996 | ok | `23e2d7100` |
| `ui.hotkey_dialog` | `23e2e37c0` | 11236 | ok | `23e2e4540` |
| `ui.hotkey_listener` | `23e2f1040` | 5641 | ok | `23e2f2330` |
| `ui.ios_toggle` | `23e2f7330` | 12640 | ok | `23e2f8098` |
| `ui.main_window` | `23e311500` | 17330 | ok | `23e311eb7` |
| `ui.styles` | `23e315970` | 4111 | ok | `23e316580` |
| `ui.telegram_tab` | `23e3235b0` | 13241 | ok | `23e324360` |
| `workers.fishing.casting_a_fishin` | `23e707a40` | 10924 | ok | `23e709858` |
| `workers.fishing.fish_recognition` | `23e71b350` | 11328 | ok | `23e71c268` |
| `workers.fishing.fishing_bot` | `23e780c30` | 39494 | failed | `23e781730` |
| `workers.fishing.garbage_disposal` | `23e7a69a0` | 12769 | ok | `23e7a7a78` |
| `workers.fishing.hooking` | `23e7c0770` | 11768 | ok | `23e7c1630` |
| `workers.fishing.meal_system` | `23e7ddc40` | 13326 | ok | `23e7dedd0` |
| `workers.fishing.memory_fish_read` | `23e7fb4a0` | 13598 | ok | `23e7fc280` |
| `workers.fishing.memory_reeling` | `23e81e380` | 29723 | ok | `23e8231c0` |
| `workers.fishing.path_utils` | `23e827d60` | 3180 | ok | `23e828790` |
| `workers.fishing.store_fish` | `23e82f430` | 11837 | ok | `23e830408` |
| `workers.fishing.trigger_monitor` | `23e843640` | 14208 | ok | `23e844778` |
| `workers.fishing.window_activator` | `23e8549f0` | 7214 | ok | `23e855a80` |
| `workers.fishing.window_capture` | `23e85df00` | 7832 | ok | `23e85f658` |
