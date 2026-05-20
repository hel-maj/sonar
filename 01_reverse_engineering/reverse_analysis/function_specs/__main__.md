# Function Specification: `__main__`

This is a reconstruction dossier from static Nuitka constants and Ghidra decompilation. It is not original Python source text.

## Docstrings / Long Text
- `18` '\n    Удалить временную папку Nuitka при закрытии приложения.\n    Вызывается автоматически через atexit.\n    '
- `28` '\n    Определить рабочую директорию для config и license.\n    Просто папка рядом с exe или main.py\n    '
- `74` '\n        Проверить лицензию и показать диалог активации если нужно\n        \n        Returns:\n            bool: True если лицензия валидна, False для выхода\n        '
- `85` '\n\nНеобходимо приобрести новый ключ для продолжения работы.\n\n📱 Telegram: @kortexm\n💳 FunPay: funpay.com/users/8394144/'
- `95` '\n        Показать диалог активации лицензии\n        \n        Args:\n            expired_message: Сообщение об истечении лицензии\n        \n        Returns:\n            bool: True если активация успешна, False для выхода\n        '
- `105` '\n        Callback при истечении лицензии во время работы (вызывается из фонового потока)\n        \n        Args:\n            reason: Причина истечения\n        '
- `126` '⛔ <b>Лицензия KortexWorker истекла</b>\n\n<b>Причина:</b> '
- `127` '\n\nБот остановлен. Необходимо приобрести новый ключ.\n\n🛒 <b>Где приобрести:</b>\n📱 Telegram: @kortexm\n💳 FunPay: funpay.com/users/8394144/'
- `155` '\n        Запустить приложение\n        \n        Returns:\n            int: Код выхода\n        '
- `185` '\nKortexWorker - GTA5 Fishing Bot\nГлавный файл запуска приложения с системой лицензирования\n\nДля запуска выполните: python main.py\n'

## Function Inventory
| Inferred qualname | Impl | Source line | Arg count | Decompiled C |
|---|---:|---:|---:|---|
| `icon.ico` | `FUN_23aaf7d20` | 51 | uVar24 | yes |
| `ui.main_window` | `FUN_23aaa2cd0` | 79 | uVar24 | yes |
| `LicensedApplication.__init__` | `FUN_23aaa5380` | 117 | uVar12 | yes |
| `LicensedApplication.check_and_activate_license` | `FUN_23aaa88f0` | 165 | uVar24 | yes |
| `LicensedApplication.show_activation_dialog` | `FUN_23aaa9730` | 185 | 2 | yes |
| `LicensedApplication.on_license_expired` | `FUN_23aaaaad0` | 223 | 2 | yes |
| `LicensedApplication.handle_license_expiration` | `FUN_23aaab8b0` | 249 | uVar24 | yes |
| `LicensedApplication.send_license_expired_notification` | `FUN_23aaac430` | 271 | 2 | yes |
| `LicensedApplication.run` | `FUN_23aaaf2c0` | 328 | 1 | yes |
| `main.py` | `FUN_23aab14c0` | 374 | uVar24&0xffffffff00000000 | yes |

## Local Variable Lists
- `236` `__class__`
- `237` `self, app_id, e, icon_path, icon, config_dir`
- `238` `self, is_valid, message`
- `241` `self, reason, activated`
- `244` `self, reason, fishing_tab, fishing_bot`
- `246` `self, exit_code, e, msg_box`
- `247` `self, reason, telegram_settings, enabled, bot_token, chat_id, admin_ids_str, requests, message, url, payload, response, e`
- `248` `self, expired_message, msg_box, dialog, result`

## Structured Constants
- `14` {'__dict_items__': [['ignore_errors', True]]}
- `212` {'__dict_items__': [['work_dir', {'__builtin__': 'str'}], ['return', {'__builtin__': 'str'}]]}
- `222` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
- `224` [None]
- `225` {'__dict_items__': [['expired_message', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
- `227` {'__dict_items__': [['reason', {'__builtin__': 'str'}]]}
- `231` {'__dict_items__': [['return', {'__builtin__': 'int'}]]}

## Per-Function Context
### `icon.ico`

- implementation: `FUN_23aaf7d20`
- source line hint: `51`
- Nuitka codevar: `_DAT_23ed90d00`
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
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\__main__\23aaf7d20_icon.ico.c`

### `ui.main_window`

- implementation: `FUN_23aaa2cd0`
- source line hint: `79`
- Nuitka codevar: `_DAT_23ed90ce8`
- factory: `FUN_23e93df40`
- nearby constants:
     `191` ['QApplication', 'QMessageBox']
     `192` 'PyQt6.QtCore'
     `193` ['QTimer', 'QObject', 'pyqtSignal']
     `194` 'QTimer'
     `195` 'QObject'
     `196` 'pyqtSignal'
     `197` 'PyQt6.QtGui'
     `198` ['QIcon']
  => `199` 'ui.main_window'
     `200` ['MainWindow']
     `201` ['ConfigManager']
     `202` 'license'
     `203` ['LicenseClient', 'ActivationDialog']
     `204` 'anti_crack_advanced'
     `205` ['AntiCrack']
     `206` 'basicConfig'
     `207` 'INFO'
     `208` '%(asctime)s [%(levelname)s] %(name)s: %(message)s'
     `209` ['level', 'format']
     `210` 'getLogger'
     `211` ['Main']
     `212` {'__dict_items__': [['work_dir', {'__builtin__': 'str'}], ['return', {'__builtin__': 'str'}]]}
     `213` '__prepare__'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\__main__\23aaa2cd0_ui.main_window.c`

### `LicensedApplication.__init__`

- implementation: `FUN_23aaa5380`
- source line hint: `117`
- Nuitka codevar: `_DAT_23ed90cd0`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `213` '__prepare__'
     `214` '%s.__prepare__() must return a mapping, not %s'
     `215` '<metaclass>'
     `216` 'Сигнал для обработки истечения лицензии в главном потоке'
     `217` '__qualname__'
     `218` 'str'
     `219` '__orig_bases__'
     `220` 'Приложение с системой лицензирования'
  => `221` 'LicensedApplication.__init__'
     `222` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `223` 'LicensedApplication.check_and_activate_license'
     `224` [None]
     `225` {'__dict_items__': [['expired_message', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
     `226` 'LicensedApplication.show_activation_dialog'
     `227` {'__dict_items__': [['reason', {'__builtin__': 'str'}]]}
     `228` 'LicensedApplication.on_license_expired'
     `229` 'LicensedApplication.handle_license_expiration'
     `230` 'LicensedApplication.send_license_expired_notification'
     `231` {'__dict_items__': [['return', {'__builtin__': 'int'}]]}
     `232` 'LicensedApplication.run'
     `233` 'main'
     `234` 'main.py'
     `235` '<module>'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\__main__\23aaa5380_LicensedApplication.__init.c`

### `LicensedApplication.check_and_activate_license`

- implementation: `FUN_23aaa88f0`
- source line hint: `165`
- Nuitka codevar: `DAT_23ed90c88`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `215` '<metaclass>'
     `216` 'Сигнал для обработки истечения лицензии в главном потоке'
     `217` '__qualname__'
     `218` 'str'
     `219` '__orig_bases__'
     `220` 'Приложение с системой лицензирования'
     `221` 'LicensedApplication.__init__'
     `222` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
  => `223` 'LicensedApplication.check_and_activate_license'
     `224` [None]
     `225` {'__dict_items__': [['expired_message', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
     `226` 'LicensedApplication.show_activation_dialog'
     `227` {'__dict_items__': [['reason', {'__builtin__': 'str'}]]}
     `228` 'LicensedApplication.on_license_expired'
     `229` 'LicensedApplication.handle_license_expiration'
     `230` 'LicensedApplication.send_license_expired_notification'
     `231` {'__dict_items__': [['return', {'__builtin__': 'int'}]]}
     `232` 'LicensedApplication.run'
     `233` 'main'
     `234` 'main.py'
     `235` '<module>'
     `236` ['__class__']
     `237` ['self', 'app_id', 'e', 'icon_path', 'icon', 'config_dir']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\__main__\23aaa88f0_LicensedApplication.check_and_activate_license.c`

### `LicensedApplication.show_activation_dialog`

- implementation: `FUN_23aaa9730`
- source line hint: `185`
- Nuitka codevar: `DAT_23ed90c78`
- factory: `FUN_23e93e480`
- nearby constants:
     `218` 'str'
     `219` '__orig_bases__'
     `220` 'Приложение с системой лицензирования'
     `221` 'LicensedApplication.__init__'
     `222` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `223` 'LicensedApplication.check_and_activate_license'
     `224` [None]
     `225` {'__dict_items__': [['expired_message', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
  => `226` 'LicensedApplication.show_activation_dialog'
     `227` {'__dict_items__': [['reason', {'__builtin__': 'str'}]]}
     `228` 'LicensedApplication.on_license_expired'
     `229` 'LicensedApplication.handle_license_expiration'
     `230` 'LicensedApplication.send_license_expired_notification'
     `231` {'__dict_items__': [['return', {'__builtin__': 'int'}]]}
     `232` 'LicensedApplication.run'
     `233` 'main'
     `234` 'main.py'
     `235` '<module>'
     `236` ['__class__']
     `237` ['self', 'app_id', 'e', 'icon_path', 'icon', 'config_dir']
     `238` ['self', 'is_valid', 'message']
     `239` ['is_compiled', 'exe_path', 'temp_dir', 'e']
     `240` ['is_compiled', 'work_dir']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\__main__\23aaa9730_LicensedApplication.show_activation_dialog.c`

### `LicensedApplication.on_license_expired`

- implementation: `FUN_23aaaaad0`
- source line hint: `223`
- Nuitka codevar: `DAT_23ed90c60`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `220` 'Приложение с системой лицензирования'
     `221` 'LicensedApplication.__init__'
     `222` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `223` 'LicensedApplication.check_and_activate_license'
     `224` [None]
     `225` {'__dict_items__': [['expired_message', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
     `226` 'LicensedApplication.show_activation_dialog'
     `227` {'__dict_items__': [['reason', {'__builtin__': 'str'}]]}
  => `228` 'LicensedApplication.on_license_expired'
     `229` 'LicensedApplication.handle_license_expiration'
     `230` 'LicensedApplication.send_license_expired_notification'
     `231` {'__dict_items__': [['return', {'__builtin__': 'int'}]]}
     `232` 'LicensedApplication.run'
     `233` 'main'
     `234` 'main.py'
     `235` '<module>'
     `236` ['__class__']
     `237` ['self', 'app_id', 'e', 'icon_path', 'icon', 'config_dir']
     `238` ['self', 'is_valid', 'message']
     `239` ['is_compiled', 'exe_path', 'temp_dir', 'e']
     `240` ['is_compiled', 'work_dir']
     `241` ['self', 'reason', 'activated']
     `242` ['is_compiled', 'failed_checks', 'on_anti_crack_threat', 'app']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\__main__\23aaaaad0_LicensedApplication.on_license_expired.c`

### `LicensedApplication.handle_license_expiration`

- implementation: `FUN_23aaab8b0`
- source line hint: `249`
- Nuitka codevar: `_DAT_23ed90c50`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `221` 'LicensedApplication.__init__'
     `222` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `223` 'LicensedApplication.check_and_activate_license'
     `224` [None]
     `225` {'__dict_items__': [['expired_message', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
     `226` 'LicensedApplication.show_activation_dialog'
     `227` {'__dict_items__': [['reason', {'__builtin__': 'str'}]]}
     `228` 'LicensedApplication.on_license_expired'
  => `229` 'LicensedApplication.handle_license_expiration'
     `230` 'LicensedApplication.send_license_expired_notification'
     `231` {'__dict_items__': [['return', {'__builtin__': 'int'}]]}
     `232` 'LicensedApplication.run'
     `233` 'main'
     `234` 'main.py'
     `235` '<module>'
     `236` ['__class__']
     `237` ['self', 'app_id', 'e', 'icon_path', 'icon', 'config_dir']
     `238` ['self', 'is_valid', 'message']
     `239` ['is_compiled', 'exe_path', 'temp_dir', 'e']
     `240` ['is_compiled', 'work_dir']
     `241` ['self', 'reason', 'activated']
     `242` ['is_compiled', 'failed_checks', 'on_anti_crack_threat', 'app']
     `243` ['threats']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\__main__\23aaab8b0_LicensedApplication.handle_license_expiration.c`

### `LicensedApplication.send_license_expired_notification`

- implementation: `FUN_23aaac430`
- source line hint: `271`
- Nuitka codevar: `_DAT_23ed90c40`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `222` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `223` 'LicensedApplication.check_and_activate_license'
     `224` [None]
     `225` {'__dict_items__': [['expired_message', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
     `226` 'LicensedApplication.show_activation_dialog'
     `227` {'__dict_items__': [['reason', {'__builtin__': 'str'}]]}
     `228` 'LicensedApplication.on_license_expired'
     `229` 'LicensedApplication.handle_license_expiration'
  => `230` 'LicensedApplication.send_license_expired_notification'
     `231` {'__dict_items__': [['return', {'__builtin__': 'int'}]]}
     `232` 'LicensedApplication.run'
     `233` 'main'
     `234` 'main.py'
     `235` '<module>'
     `236` ['__class__']
     `237` ['self', 'app_id', 'e', 'icon_path', 'icon', 'config_dir']
     `238` ['self', 'is_valid', 'message']
     `239` ['is_compiled', 'exe_path', 'temp_dir', 'e']
     `240` ['is_compiled', 'work_dir']
     `241` ['self', 'reason', 'activated']
     `242` ['is_compiled', 'failed_checks', 'on_anti_crack_threat', 'app']
     `243` ['threats']
     `244` ['self', 'reason', 'fishing_tab', 'fishing_bot']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\__main__\23aaac430_LicensedApplication.send_license_expired_notification.c`

### `LicensedApplication.run`

- implementation: `FUN_23aaaf2c0`
- source line hint: `328`
- Nuitka codevar: `_DAT_23ed90c30`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `224` [None]
     `225` {'__dict_items__': [['expired_message', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bool'}]]}
     `226` 'LicensedApplication.show_activation_dialog'
     `227` {'__dict_items__': [['reason', {'__builtin__': 'str'}]]}
     `228` 'LicensedApplication.on_license_expired'
     `229` 'LicensedApplication.handle_license_expiration'
     `230` 'LicensedApplication.send_license_expired_notification'
     `231` {'__dict_items__': [['return', {'__builtin__': 'int'}]]}
  => `232` 'LicensedApplication.run'
     `233` 'main'
     `234` 'main.py'
     `235` '<module>'
     `236` ['__class__']
     `237` ['self', 'app_id', 'e', 'icon_path', 'icon', 'config_dir']
     `238` ['self', 'is_valid', 'message']
     `239` ['is_compiled', 'exe_path', 'temp_dir', 'e']
     `240` ['is_compiled', 'work_dir']
     `241` ['self', 'reason', 'activated']
     `242` ['is_compiled', 'failed_checks', 'on_anti_crack_threat', 'app']
     `243` ['threats']
     `244` ['self', 'reason', 'fishing_tab', 'fishing_bot']
     `245` ['work_dir', 'candidates', 'p']
     `246` ['self', 'exit_code', 'e', 'msg_box']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\__main__\23aaaf2c0_LicensedApplication.run.c`

### `main.py`

- implementation: `FUN_23aab14c0`
- source line hint: `374`
- Nuitka codevar: `_DAT_23ed90c18`
- factory: `FUN_23e93df40`
- nearby constants:
     `226` 'LicensedApplication.show_activation_dialog'
     `227` {'__dict_items__': [['reason', {'__builtin__': 'str'}]]}
     `228` 'LicensedApplication.on_license_expired'
     `229` 'LicensedApplication.handle_license_expiration'
     `230` 'LicensedApplication.send_license_expired_notification'
     `231` {'__dict_items__': [['return', {'__builtin__': 'int'}]]}
     `232` 'LicensedApplication.run'
     `233` 'main'
  => `234` 'main.py'
     `235` '<module>'
     `236` ['__class__']
     `237` ['self', 'app_id', 'e', 'icon_path', 'icon', 'config_dir']
     `238` ['self', 'is_valid', 'message']
     `239` ['is_compiled', 'exe_path', 'temp_dir', 'e']
     `240` ['is_compiled', 'work_dir']
     `241` ['self', 'reason', 'activated']
     `242` ['is_compiled', 'failed_checks', 'on_anti_crack_threat', 'app']
     `243` ['threats']
     `244` ['self', 'reason', 'fishing_tab', 'fishing_bot']
     `245` ['work_dir', 'candidates', 'p']
     `246` ['self', 'exit_code', 'e', 'msg_box']
     `247` ['self', 'reason', 'telegram_settings', 'enabled', 'bot_token', 'chat_id', 'admin_ids_str', 'requests', 'message', 'url', 'payload', 'response', 'e']
     `248` ['self', 'expired_message', 'msg_box', 'dialog', 'result']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\__main__\23aab14c0_main.py.c`
