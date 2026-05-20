# Function Specification: `__parents_main__`

This is a reconstruction dossier from static Nuitka constants and Ghidra decompilation. It is not original Python source text.

## Docstrings / Long Text
- `18` '\n    Удалить временную папку Nuitka при закрытии приложения.\n    Вызывается автоматически через atexit.\n    '
- `28` '\n    Определить рабочую директорию для config и license.\n    Просто папка рядом с exe или main.py\n    '
- `72` '\n        Проверить лицензию и показать диалог активации если нужно\n        \n        Returns:\n            bool: True если лицензия валидна, False для выхода\n        '
- `83` '\n\nНеобходимо приобрести новый ключ для продолжения работы.\n\n📱 Telegram: @kortexm\n💳 FunPay: funpay.com/users/8394144/'
- `93` '\n        Показать диалог активации лицензии\n        \n        Args:\n            expired_message: Сообщение об истечении лицензии\n        \n        Returns:\n            bool: True если активация успешна, False для выхода\n        '
- `103` '\n        Callback при истечении лицензии во время работы (вызывается из фонового потока)\n        \n        Args:\n            reason: Причина истечения\n        '
- `124` '⛔ <b>Лицензия KortexWorker истекла</b>\n\n<b>Причина:</b> '
- `125` '\n\nБот остановлен. Необходимо приобрести новый ключ.\n\n🛒 <b>Где приобрести:</b>\n📱 Telegram: @kortexm\n💳 FunPay: funpay.com/users/8394144/'
- `153` '\n        Запустить приложение\n        \n        Returns:\n            int: Код выхода\n        '
- `187` '\nKortexWorker - GTA5 Fishing Bot\nГлавный файл запуска приложения с системой лицензирования\n\nДля запуска выполните: python main.py\n'

## Function Inventory
| Inferred qualname | Impl | Source line | Arg count | Decompiled C |
|---|---:|---:|---:|---|
| `icon.ico` | `FUN_23ab09180` | 51 | uVar24 | yes |
| `multiprocessing.spawn` | `FUN_23aab4840` | 79 | uVar24 | yes |
| `ui.main_window` | `FUN_23aab6ef0` | 117 | uVar24 | yes |
| `LicensedApplication.__init__` | `FUN_23aaba460` | 165 | uVar24 | yes |
| `LicensedApplication.check_and_activate_license` | `FUN_23aabb2a0` | 185 | 2 | yes |
| `LicensedApplication.show_activation_dialog` | `FUN_23aabc640` | 223 | 2 | yes |
| `LicensedApplication.on_license_expired` | `FUN_23aabd420` | 249 | uVar24 | yes |
| `LicensedApplication.handle_license_expiration` | `FUN_23aabdfa0` | 271 | 2 | yes |
| `LicensedApplication.send_license_expired_notification` | `FUN_23aac0e30` | 328 | 1 | yes |
| `LicensedApplication.run` | `FUN_23aac3030` | 374 | uVar24&0xffffffff00000000 | yes |
| `main.py` | `FUN_23aaff5a0` | 419 | uVar24 | yes |

## Local Variable Lists
- `243` `__class__`
- `244` `self, app_id, e, icon_path, icon, config_dir`
- `245` `sys, builtins, multiprocessing, kwds, args, arg, name, value`
- `246` `self, is_valid, message`
- `249` `self, reason, activated`
- `252` `self, reason, fishing_tab, fishing_bot`
- `254` `self, exit_code, e, msg_box`
- `255` `self, reason, telegram_settings, enabled, bot_token, chat_id, admin_ids_str, requests, message, url, payload, response, e`
- `256` `self, expired_message, msg_box, dialog, result`

## Structured Constants
- `14` {'__dict_items__': [['ignore_errors', True]]}
- `179` {'__slice__': [2, None, None]}
- `216` {'__dict_items__': [['work_dir', {'__builtin__': 'str'}], ['return', {'__builtin__': 'str'}]]}
- `227` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
- `229` [None]
- `230` {'__dict_items__': [['expired_message', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
- `232` {'__dict_items__': [['reason', {'__builtin__': 'str'}]]}
- `236` {'__dict_items__': [['return', {'__builtin__': 'int'}]]}

## Per-Function Context
### `icon.ico`

- implementation: `FUN_23ab09180`
- source line hint: `51`
- Nuitka codevar: `DAT_23ed90b28`
- factory: `FUN_23e93df40`
- nearby constants:
     `0` 'join'
     `1` 'resources'
  => `2` 'icon.ico'
     `3` 'executable'
     `4` 'Найти иконку приложения в dev/compiled режимах, включая onefile.'
     `5` 'frozen'
     `6` 'onefile_'
     `7` 'startswith'
     `8` ['onefile_']
     `9` 'logger'
     `10` 'info'
     `11` 'Cleaning up temporary directory: '
     `12` 'shutil'
     `13` 'rmtree'
     `14` {'__dict_items__': [['ignore_errors', True]]}
     `15` ['Temporary directory cleaned successfully']
     `16` 'error'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\__parents_main__\23ab09180_icon.ico.c`

### `multiprocessing.spawn`

- implementation: `FUN_23aab4840`
- source line hint: `79`
- Nuitka codevar: `DAT_23ed90b10`
- factory: `FUN_23e93df40`
- nearby constants:
     `165` ['✓ Anti-crack protection initialized (production mode)']
     `166` ['⚠ Anti-crack protection DISABLED (development mode)']
     `167` 'atexit'
     `168` 'cleanup_temp_directory'
     `169` 'LicensedApplication'
     `170` 'run'
     `171` 'Точка входа в приложение'
     `172` 'Runtime security threat: '
  => `173` 'multiprocessing.spawn'
     `174` '<lambda>'
     `175` '__nuitka_freeze_support.<locals>.<lambda>'
     `176` 'spawn'
     `177` '_fixup_main_from_path'
     `178` '__nuitka_original_args'
     `179` {'__slice__': [2, None, None]}
     `180` ['=']
     `181` 'pipe_handle'
     `182` 'None'
     `183` 'kwds'
     `184` 'modules'
     `185` '__parents_main__'
     `186` 'spawn_main'
     `187` '\nKortexWorker - GTA5 Fishing Bot\nГлавный файл запуска приложения с системой лицензирования\n\nДля запуска выполните: python main.py\n'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\__parents_main__\23aab4840_multiprocessing.spawn.c`

### `ui.main_window`

- implementation: `FUN_23aab6ef0`
- source line hint: `117`
- Nuitka codevar: `DAT_23ed90af8`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `195` ['QApplication', 'QMessageBox']
     `196` 'PyQt6.QtCore'
     `197` ['QTimer', 'QObject', 'pyqtSignal']
     `198` 'QTimer'
     `199` 'QObject'
     `200` 'pyqtSignal'
     `201` 'PyQt6.QtGui'
     `202` ['QIcon']
  => `203` 'ui.main_window'
     `204` ['MainWindow']
     `205` ['ConfigManager']
     `206` 'license'
     `207` ['LicenseClient', 'ActivationDialog']
     `208` 'anti_crack_advanced'
     `209` ['AntiCrack']
     `210` 'basicConfig'
     `211` 'INFO'
     `212` '%(asctime)s [%(levelname)s] %(name)s: %(message)s'
     `213` ['level', 'format']
     `214` 'getLogger'
     `215` ['Main']
     `216` {'__dict_items__': [['work_dir', {'__builtin__': 'str'}], ['return', {'__builtin__': 'str'}]]}
     `217` '__prepare__'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\__parents_main__\23aab6ef0_ui.main_window.c`

### `LicensedApplication.__init__`

- implementation: `FUN_23aaba460`
- source line hint: `165`
- Nuitka codevar: `DAT_23ed90ab0`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `218` '__getitem__'
     `219` '%s.__prepare__() must return a mapping, not %s'
     `220` '<metaclass>'
     `221` 'Сигнал для обработки истечения лицензии в главном потоке'
     `222` '__qualname__'
     `223` 'str'
     `224` '__orig_bases__'
     `225` 'Приложение с системой лицензирования'
  => `226` 'LicensedApplication.__init__'
     `227` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `228` 'LicensedApplication.check_and_activate_license'
     `229` [None]
     `230` {'__dict_items__': [['expired_message', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
     `231` 'LicensedApplication.show_activation_dialog'
     `232` {'__dict_items__': [['reason', {'__builtin__': 'str'}]]}
     `233` 'LicensedApplication.on_license_expired'
     `234` 'LicensedApplication.handle_license_expiration'
     `235` 'LicensedApplication.send_license_expired_notification'
     `236` {'__dict_items__': [['return', {'__builtin__': 'int'}]]}
     `237` 'LicensedApplication.run'
     `238` 'main'
     `239` '__nuitka_freeze_support'
     `240` 'main.py'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\__parents_main__\23aaba460_LicensedApplication.__init.c`

### `LicensedApplication.check_and_activate_license`

- implementation: `FUN_23aabb2a0`
- source line hint: `185`
- Nuitka codevar: `DAT_23ed90aa0`
- factory: `FUN_23e93e480`
- nearby constants:
     `220` '<metaclass>'
     `221` 'Сигнал для обработки истечения лицензии в главном потоке'
     `222` '__qualname__'
     `223` 'str'
     `224` '__orig_bases__'
     `225` 'Приложение с системой лицензирования'
     `226` 'LicensedApplication.__init__'
     `227` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
  => `228` 'LicensedApplication.check_and_activate_license'
     `229` [None]
     `230` {'__dict_items__': [['expired_message', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
     `231` 'LicensedApplication.show_activation_dialog'
     `232` {'__dict_items__': [['reason', {'__builtin__': 'str'}]]}
     `233` 'LicensedApplication.on_license_expired'
     `234` 'LicensedApplication.handle_license_expiration'
     `235` 'LicensedApplication.send_license_expired_notification'
     `236` {'__dict_items__': [['return', {'__builtin__': 'int'}]]}
     `237` 'LicensedApplication.run'
     `238` 'main'
     `239` '__nuitka_freeze_support'
     `240` 'main.py'
     `241` ['mod_name']
     `242` '<module __parents_main__>'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\__parents_main__\23aabb2a0_LicensedApplication.check_and_activate_license.c`

### `LicensedApplication.show_activation_dialog`

- implementation: `FUN_23aabc640`
- source line hint: `223`
- Nuitka codevar: `DAT_23ed90a88`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `223` 'str'
     `224` '__orig_bases__'
     `225` 'Приложение с системой лицензирования'
     `226` 'LicensedApplication.__init__'
     `227` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `228` 'LicensedApplication.check_and_activate_license'
     `229` [None]
     `230` {'__dict_items__': [['expired_message', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
  => `231` 'LicensedApplication.show_activation_dialog'
     `232` {'__dict_items__': [['reason', {'__builtin__': 'str'}]]}
     `233` 'LicensedApplication.on_license_expired'
     `234` 'LicensedApplication.handle_license_expiration'
     `235` 'LicensedApplication.send_license_expired_notification'
     `236` {'__dict_items__': [['return', {'__builtin__': 'int'}]]}
     `237` 'LicensedApplication.run'
     `238` 'main'
     `239` '__nuitka_freeze_support'
     `240` 'main.py'
     `241` ['mod_name']
     `242` '<module __parents_main__>'
     `243` ['__class__']
     `244` ['self', 'app_id', 'e', 'icon_path', 'icon', 'config_dir']
     `245` ['sys', 'builtins', 'multiprocessing', 'kwds', 'args', 'arg', 'name', 'value']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\__parents_main__\23aabc640_LicensedApplication.show_activation_dialog.c`

### `LicensedApplication.on_license_expired`

- implementation: `FUN_23aabd420`
- source line hint: `249`
- Nuitka codevar: `DAT_23ed90a78`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `225` 'Приложение с системой лицензирования'
     `226` 'LicensedApplication.__init__'
     `227` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `228` 'LicensedApplication.check_and_activate_license'
     `229` [None]
     `230` {'__dict_items__': [['expired_message', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
     `231` 'LicensedApplication.show_activation_dialog'
     `232` {'__dict_items__': [['reason', {'__builtin__': 'str'}]]}
  => `233` 'LicensedApplication.on_license_expired'
     `234` 'LicensedApplication.handle_license_expiration'
     `235` 'LicensedApplication.send_license_expired_notification'
     `236` {'__dict_items__': [['return', {'__builtin__': 'int'}]]}
     `237` 'LicensedApplication.run'
     `238` 'main'
     `239` '__nuitka_freeze_support'
     `240` 'main.py'
     `241` ['mod_name']
     `242` '<module __parents_main__>'
     `243` ['__class__']
     `244` ['self', 'app_id', 'e', 'icon_path', 'icon', 'config_dir']
     `245` ['sys', 'builtins', 'multiprocessing', 'kwds', 'args', 'arg', 'name', 'value']
     `246` ['self', 'is_valid', 'message']
     `247` ['is_compiled', 'exe_path', 'temp_dir', 'e']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\__parents_main__\23aabd420_LicensedApplication.on_license_expired.c`

### `LicensedApplication.handle_license_expiration`

- implementation: `FUN_23aabdfa0`
- source line hint: `271`
- Nuitka codevar: `DAT_23ed90a68`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `226` 'LicensedApplication.__init__'
     `227` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `228` 'LicensedApplication.check_and_activate_license'
     `229` [None]
     `230` {'__dict_items__': [['expired_message', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
     `231` 'LicensedApplication.show_activation_dialog'
     `232` {'__dict_items__': [['reason', {'__builtin__': 'str'}]]}
     `233` 'LicensedApplication.on_license_expired'
  => `234` 'LicensedApplication.handle_license_expiration'
     `235` 'LicensedApplication.send_license_expired_notification'
     `236` {'__dict_items__': [['return', {'__builtin__': 'int'}]]}
     `237` 'LicensedApplication.run'
     `238` 'main'
     `239` '__nuitka_freeze_support'
     `240` 'main.py'
     `241` ['mod_name']
     `242` '<module __parents_main__>'
     `243` ['__class__']
     `244` ['self', 'app_id', 'e', 'icon_path', 'icon', 'config_dir']
     `245` ['sys', 'builtins', 'multiprocessing', 'kwds', 'args', 'arg', 'name', 'value']
     `246` ['self', 'is_valid', 'message']
     `247` ['is_compiled', 'exe_path', 'temp_dir', 'e']
     `248` ['is_compiled', 'work_dir']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\__parents_main__\23aabdfa0_LicensedApplication.handle_license_expiration.c`

### `LicensedApplication.send_license_expired_notification`

- implementation: `FUN_23aac0e30`
- source line hint: `328`
- Nuitka codevar: `DAT_23ed90a58`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `227` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `228` 'LicensedApplication.check_and_activate_license'
     `229` [None]
     `230` {'__dict_items__': [['expired_message', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
     `231` 'LicensedApplication.show_activation_dialog'
     `232` {'__dict_items__': [['reason', {'__builtin__': 'str'}]]}
     `233` 'LicensedApplication.on_license_expired'
     `234` 'LicensedApplication.handle_license_expiration'
  => `235` 'LicensedApplication.send_license_expired_notification'
     `236` {'__dict_items__': [['return', {'__builtin__': 'int'}]]}
     `237` 'LicensedApplication.run'
     `238` 'main'
     `239` '__nuitka_freeze_support'
     `240` 'main.py'
     `241` ['mod_name']
     `242` '<module __parents_main__>'
     `243` ['__class__']
     `244` ['self', 'app_id', 'e', 'icon_path', 'icon', 'config_dir']
     `245` ['sys', 'builtins', 'multiprocessing', 'kwds', 'args', 'arg', 'name', 'value']
     `246` ['self', 'is_valid', 'message']
     `247` ['is_compiled', 'exe_path', 'temp_dir', 'e']
     `248` ['is_compiled', 'work_dir']
     `249` ['self', 'reason', 'activated']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\__parents_main__\23aac0e30_LicensedApplication.send_license_expired_notification.c`

### `LicensedApplication.run`

- implementation: `FUN_23aac3030`
- source line hint: `374`
- Nuitka codevar: `DAT_23ed90a40`
- factory: `FUN_23e93df40`
- nearby constants:
     `229` [None]
     `230` {'__dict_items__': [['expired_message', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
     `231` 'LicensedApplication.show_activation_dialog'
     `232` {'__dict_items__': [['reason', {'__builtin__': 'str'}]]}
     `233` 'LicensedApplication.on_license_expired'
     `234` 'LicensedApplication.handle_license_expiration'
     `235` 'LicensedApplication.send_license_expired_notification'
     `236` {'__dict_items__': [['return', {'__builtin__': 'int'}]]}
  => `237` 'LicensedApplication.run'
     `238` 'main'
     `239` '__nuitka_freeze_support'
     `240` 'main.py'
     `241` ['mod_name']
     `242` '<module __parents_main__>'
     `243` ['__class__']
     `244` ['self', 'app_id', 'e', 'icon_path', 'icon', 'config_dir']
     `245` ['sys', 'builtins', 'multiprocessing', 'kwds', 'args', 'arg', 'name', 'value']
     `246` ['self', 'is_valid', 'message']
     `247` ['is_compiled', 'exe_path', 'temp_dir', 'e']
     `248` ['is_compiled', 'work_dir']
     `249` ['self', 'reason', 'activated']
     `250` ['is_compiled', 'failed_checks', 'on_anti_crack_threat', 'app']
     `251` ['threats']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\__parents_main__\23aac3030_LicensedApplication.run.c`

### `main.py`

- implementation: `FUN_23aaff5a0`
- source line hint: `419`
- Nuitka codevar: `DAT_23ed90a08`
- factory: `FUN_23e93df40`
- nearby constants:
     `232` {'__dict_items__': [['reason', {'__builtin__': 'str'}]]}
     `233` 'LicensedApplication.on_license_expired'
     `234` 'LicensedApplication.handle_license_expiration'
     `235` 'LicensedApplication.send_license_expired_notification'
     `236` {'__dict_items__': [['return', {'__builtin__': 'int'}]]}
     `237` 'LicensedApplication.run'
     `238` 'main'
     `239` '__nuitka_freeze_support'
  => `240` 'main.py'
     `241` ['mod_name']
     `242` '<module __parents_main__>'
     `243` ['__class__']
     `244` ['self', 'app_id', 'e', 'icon_path', 'icon', 'config_dir']
     `245` ['sys', 'builtins', 'multiprocessing', 'kwds', 'args', 'arg', 'name', 'value']
     `246` ['self', 'is_valid', 'message']
     `247` ['is_compiled', 'exe_path', 'temp_dir', 'e']
     `248` ['is_compiled', 'work_dir']
     `249` ['self', 'reason', 'activated']
     `250` ['is_compiled', 'failed_checks', 'on_anti_crack_threat', 'app']
     `251` ['threats']
     `252` ['self', 'reason', 'fishing_tab', 'fishing_bot']
     `253` ['work_dir', 'candidates', 'p']
     `254` ['self', 'exit_code', 'e', 'msg_box']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\__parents_main__\23aaff5a0_main.py.c`
