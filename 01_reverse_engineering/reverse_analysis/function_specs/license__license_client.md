# Function Specification: `license.license_client`

This is a reconstruction dossier from static Nuitka constants and Ghidra decompilation. It is not original Python source text.

## Source Path Hints
- `license\license_client.py`

## Docstrings / Long Text
- `26` '\n        Инициализация клиента лицензий\n        \n        Args:\n            config_dir: Путь к директории с конфигурацией\n        '
- `135` '\n        Активировать лицензию на сервере\n        \n        Args:\n            license_key: Лицензионный ключ (16 символов)\n        \n        Returns:\n            (success: bool, message: str)\n        '
- `171` '\n        Проверить лицензию на сервере\n        \n        Returns:\n            (is_valid: bool, message: str)\n        '
- `186` '\n        Запустить фоновую проверку лицензии каждые 5 минут\n        \n        Args:\n            expiration_callback: Функция, вызываемая при истечении лицензии\n        '
- `211` '\nLicense Client для KortexWorker\nУправление лицензиями с проверкой на сервере каждые 5 минут\n'

## Function Inventory
| Inferred qualname | Impl | Source line | Arg count | Decompiled C |
|---|---:|---:|---:|---|
| `license.enc` | `LAB_23c623f90` | 71 | 2 | yes |
| `cryptography.fernet` | `FUN_23c6244a0` | 75 | 2 | yes |
| `LicenseClient.__init__` | `FUN_23c624960` | 79 | 2 | yes |
| `LicenseClient._encrypt_data` | `FUN_23c626700` | 97 | 1 | yes |
| `LicenseClient._decrypt_data` | `FUN_23c62a0e0` | 146 | 1 | yes |
| `LicenseClient._save_local_license` | `FUN_23c62b1b0` | 158 | 1 | yes |
| `LicenseClient._load_local_license` | `FUN_23c62d3d0` | 192 | 2 | yes |
| `LicenseClient._delete_local_license` | `FUN_23c630900` | 262 | 1 | yes |
| `LicenseClient._check_local_expiration` | `FUN_23c6350e0` | 355 | 2 | yes |
| `LicenseClient.activate` | `FUN_23c636410` | 369 | 2 | yes |
| `LicenseClient.validate` | `FUN_23c637110` | 392 | 1 | yes |
| `LicenseClient._handle_license_invalid` | `FUN_23c637910` | 400 | 1 | yes |
| `LicenseClient.start_background_check` | `FUN_23c63ab20` | 432 | 1 | yes |
| `LicenseClient.stop_background_check` | `FUN_23c63af70` | 436 | 1 | yes |
| `LicenseClient._background_check_loop` | `FUN_23c63b6d0` | 449 | 1 | yes |

## Local Variable Lists
- `275` `__class__`
- `276` `self, config_dir`
- `277` `self, is_valid, message, e`
- `278` `self, expires_at_str, expires_at, now, now_naive, is_valid, e`
- `279` `self, encrypted_data`
- `280` `self, e`
- `281` `self, data`
- `282` `self, reason, e`
- `283` `self, f, encrypted, json_data, data, e, traceback`
- `284` `self, license_data, json_data, encrypted, f, e`
- `285` `self, license_key, url, data, response, result, expires_str, detail, e`
- `286` `self`
- `287` `self, expiration_callback`
- `288` `self, url, data, response, result, detail, user_msg, frozen_msg, e`

## Structured Constants
- `5` [True, True]
- `46` [None, None, None]
- `89` [None]
- `100` {'__slice__': [None, 4, None]}
- `190` [5]
- `241` {'__bytes__': '4c384d6c736b4a762d4568505575333368337278454d486b312d66363859596f383933357150354b6168453d', 'size': 44}
- `242` {'__dict_items__': [['config_dir', {'__builtin__': 'str'}]]}
- `244` {'__dict_items__': [['data', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bytes'}]]}
- `246` {'__dict_items__': [['encrypted_data', {'__builtin__': 'bytes'}], ['return', {'__builtin__': 'str'}]]}
- `250` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
- `254` {'__dict_items__': [['license_key', {'__builtin__': 'str'}], ['return', {'__generic_alias__': [{'__builtin__': 'tuple'}, [{'__builtin__': 'bool'}, {'__builtin__': 'str'}]]}]]}
- `257` {'__dict_items__': [['return', {'__generic_alias__': [{'__builtin__': 'tuple'}, [{'__builtin__': 'bool'}, {'__builtin__': 'str'}]]}]]}
- `259` {'__dict_items__': [['reason', {'__builtin__': 'str'}]]}
- `271` {'__dict_items__': [['return', {'__builtin__': 'str'}]]}

## Per-Function Context
### `license.enc`

- implementation: `LAB_23c623f90`
- source line hint: `71`
- Nuitka codevar: `DAT_23ee29ce8`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `0` 'Path'
     `1` 'config_dir'
  => `2` 'license.enc'
     `3` 'license_file'
     `4` 'mkdir'
     `5` [True, True]
     `6` ['parents', 'exist_ok']
     `7` 'Fernet'
     `8` '_ENCRYPTION_KEY'
     `9` '_cipher'
     `10` '_license_key'
     `11` 'get_hwid'
     `12` '_hwid'
     `13` '_license_data'
     `14` '_is_valid'
     `15` '_check_thread'
     `16` 'threading'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\license__license_client\23c623f90_license.enc.c`

### `cryptography.fernet`

- implementation: `FUN_23c6244a0`
- source line hint: `75`
- Nuitka codevar: `_DAT_23ee29cd8`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `214` 'logging'
     `215` 'os'
     `216` 'time'
     `217` ['datetime', 'timezone']
     `218` 'Optional'
     `219` 'Dict'
     `220` 'Any'
     `221` 'Callable'
  => `222` 'cryptography.fernet'
     `223` ['Fernet']
     `224` 'pathlib'
     `225` ['Path']
     `226` 'hwid_generator'
     `227` ['get_hwid']
     `228` 'anti_crack_advanced'
     `229` ['AntiCrack', 'protected']
     `230` 'AntiCrack'
     `231` 'protected'
     `232` 'getLogger'
     `233` ['LicenseClient']
     `234` 'license.license_client'
     `235` 'Клиент для работы с системой лицензирования'
     `236` 'LicenseClient'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\license__license_client\23c6244a0_cryptography.fernet.c`

### `LicenseClient.__init__`

- implementation: `FUN_23c624960`
- source line hint: `79`
- Nuitka codevar: `_DAT_23ee29cc8`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `235` 'Клиент для работы с системой лицензирования'
     `236` 'LicenseClient'
     `237` '__qualname__'
     `238` 'https://kortexg-gream.waw0.amvera.tech'
     `239` 'kortexworker'
     `240` 300
     `241` {'__bytes__': '4c384d6c736b4a762d4568505575333368337278454d486b312d66363859596f383933357150354b6168453d', 'size': 44}
     `242` {'__dict_items__': [['config_dir', {'__builtin__': 'str'}]]}
  => `243` 'LicenseClient.__init__'
     `244` {'__dict_items__': [['data', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bytes'}]]}
     `245` 'LicenseClient._encrypt_data'
     `246` {'__dict_items__': [['encrypted_data', {'__builtin__': 'bytes'}], ['return', {'__builtin__': 'str'}]]}
     `247` 'LicenseClient._decrypt_data'
     `248` 'license_data'
     `249` 'LicenseClient._save_local_license'
     `250` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `251` 'LicenseClient._load_local_license'
     `252` 'LicenseClient._delete_local_license'
     `253` 'LicenseClient._check_local_expiration'
     `254` {'__dict_items__': [['license_key', {'__builtin__': 'str'}], ['return', {'__generic_alias__': [{'__builtin__': 'tuple'}, [{'__builtin__': 'bool'}, {'__builtin__': 'str'}]]}]]}
     `255` 'activate'
     `256` 'LicenseClient.activate'
     `257` {'__dict_items__': [['return', {'__generic_alias__': [{'__builtin__': 'tuple'}, [{'__builtin__': 'bool'}, {'__builtin__': 'str'}]]}]]}
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\license__license_client\23c624960_LicenseClient.__init.c`

### `LicenseClient._encrypt_data`

- implementation: `FUN_23c626700`
- source line hint: `97`
- Nuitka codevar: `_DAT_23ee29cb8`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `237` '__qualname__'
     `238` 'https://kortexg-gream.waw0.amvera.tech'
     `239` 'kortexworker'
     `240` 300
     `241` {'__bytes__': '4c384d6c736b4a762d4568505575333368337278454d486b312d66363859596f383933357150354b6168453d', 'size': 44}
     `242` {'__dict_items__': [['config_dir', {'__builtin__': 'str'}]]}
     `243` 'LicenseClient.__init__'
     `244` {'__dict_items__': [['data', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bytes'}]]}
  => `245` 'LicenseClient._encrypt_data'
     `246` {'__dict_items__': [['encrypted_data', {'__builtin__': 'bytes'}], ['return', {'__builtin__': 'str'}]]}
     `247` 'LicenseClient._decrypt_data'
     `248` 'license_data'
     `249` 'LicenseClient._save_local_license'
     `250` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `251` 'LicenseClient._load_local_license'
     `252` 'LicenseClient._delete_local_license'
     `253` 'LicenseClient._check_local_expiration'
     `254` {'__dict_items__': [['license_key', {'__builtin__': 'str'}], ['return', {'__generic_alias__': [{'__builtin__': 'tuple'}, [{'__builtin__': 'bool'}, {'__builtin__': 'str'}]]}]]}
     `255` 'activate'
     `256` 'LicenseClient.activate'
     `257` {'__dict_items__': [['return', {'__generic_alias__': [{'__builtin__': 'tuple'}, [{'__builtin__': 'bool'}, {'__builtin__': 'str'}]]}]]}
     `258` 'LicenseClient.validate'
     `259` {'__dict_items__': [['reason', {'__builtin__': 'str'}]]}
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\license__license_client\23c626700_LicenseClient._encrypt_data.c`

### `LicenseClient._decrypt_data`

- implementation: `FUN_23c62a0e0`
- source line hint: `146`
- Nuitka codevar: `DAT_23ee29ca8`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `239` 'kortexworker'
     `240` 300
     `241` {'__bytes__': '4c384d6c736b4a762d4568505575333368337278454d486b312d66363859596f383933357150354b6168453d', 'size': 44}
     `242` {'__dict_items__': [['config_dir', {'__builtin__': 'str'}]]}
     `243` 'LicenseClient.__init__'
     `244` {'__dict_items__': [['data', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bytes'}]]}
     `245` 'LicenseClient._encrypt_data'
     `246` {'__dict_items__': [['encrypted_data', {'__builtin__': 'bytes'}], ['return', {'__builtin__': 'str'}]]}
  => `247` 'LicenseClient._decrypt_data'
     `248` 'license_data'
     `249` 'LicenseClient._save_local_license'
     `250` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `251` 'LicenseClient._load_local_license'
     `252` 'LicenseClient._delete_local_license'
     `253` 'LicenseClient._check_local_expiration'
     `254` {'__dict_items__': [['license_key', {'__builtin__': 'str'}], ['return', {'__generic_alias__': [{'__builtin__': 'tuple'}, [{'__builtin__': 'bool'}, {'__builtin__': 'str'}]]}]]}
     `255` 'activate'
     `256` 'LicenseClient.activate'
     `257` {'__dict_items__': [['return', {'__generic_alias__': [{'__builtin__': 'tuple'}, [{'__builtin__': 'bool'}, {'__builtin__': 'str'}]]}]]}
     `258` 'LicenseClient.validate'
     `259` {'__dict_items__': [['reason', {'__builtin__': 'str'}]]}
     `260` 'LicenseClient._handle_license_invalid'
     `261` 'expiration_callback'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\license__license_client\23c62a0e0_LicenseClient._decrypt_data.c`

### `LicenseClient._save_local_license`

- implementation: `FUN_23c62b1b0`
- source line hint: `158`
- Nuitka codevar: `_DAT_23ee29c98`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `241` {'__bytes__': '4c384d6c736b4a762d4568505575333368337278454d486b312d66363859596f383933357150354b6168453d', 'size': 44}
     `242` {'__dict_items__': [['config_dir', {'__builtin__': 'str'}]]}
     `243` 'LicenseClient.__init__'
     `244` {'__dict_items__': [['data', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bytes'}]]}
     `245` 'LicenseClient._encrypt_data'
     `246` {'__dict_items__': [['encrypted_data', {'__builtin__': 'bytes'}], ['return', {'__builtin__': 'str'}]]}
     `247` 'LicenseClient._decrypt_data'
     `248` 'license_data'
  => `249` 'LicenseClient._save_local_license'
     `250` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `251` 'LicenseClient._load_local_license'
     `252` 'LicenseClient._delete_local_license'
     `253` 'LicenseClient._check_local_expiration'
     `254` {'__dict_items__': [['license_key', {'__builtin__': 'str'}], ['return', {'__generic_alias__': [{'__builtin__': 'tuple'}, [{'__builtin__': 'bool'}, {'__builtin__': 'str'}]]}]]}
     `255` 'activate'
     `256` 'LicenseClient.activate'
     `257` {'__dict_items__': [['return', {'__generic_alias__': [{'__builtin__': 'tuple'}, [{'__builtin__': 'bool'}, {'__builtin__': 'str'}]]}]]}
     `258` 'LicenseClient.validate'
     `259` {'__dict_items__': [['reason', {'__builtin__': 'str'}]]}
     `260` 'LicenseClient._handle_license_invalid'
     `261` 'expiration_callback'
     `262` 'start_background_check'
     `263` 'LicenseClient.start_background_check'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\license__license_client\23c62b1b0_LicenseClient._save_local_license.c`

### `LicenseClient._load_local_license`

- implementation: `FUN_23c62d3d0`
- source line hint: `192`
- Nuitka codevar: `_DAT_23ee29c88`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `243` 'LicenseClient.__init__'
     `244` {'__dict_items__': [['data', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bytes'}]]}
     `245` 'LicenseClient._encrypt_data'
     `246` {'__dict_items__': [['encrypted_data', {'__builtin__': 'bytes'}], ['return', {'__builtin__': 'str'}]]}
     `247` 'LicenseClient._decrypt_data'
     `248` 'license_data'
     `249` 'LicenseClient._save_local_license'
     `250` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
  => `251` 'LicenseClient._load_local_license'
     `252` 'LicenseClient._delete_local_license'
     `253` 'LicenseClient._check_local_expiration'
     `254` {'__dict_items__': [['license_key', {'__builtin__': 'str'}], ['return', {'__generic_alias__': [{'__builtin__': 'tuple'}, [{'__builtin__': 'bool'}, {'__builtin__': 'str'}]]}]]}
     `255` 'activate'
     `256` 'LicenseClient.activate'
     `257` {'__dict_items__': [['return', {'__generic_alias__': [{'__builtin__': 'tuple'}, [{'__builtin__': 'bool'}, {'__builtin__': 'str'}]]}]]}
     `258` 'LicenseClient.validate'
     `259` {'__dict_items__': [['reason', {'__builtin__': 'str'}]]}
     `260` 'LicenseClient._handle_license_invalid'
     `261` 'expiration_callback'
     `262` 'start_background_check'
     `263` 'LicenseClient.start_background_check'
     `264` 'stop_background_check'
     `265` 'LicenseClient.stop_background_check'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\license__license_client\23c62d3d0_LicenseClient._load_local_license.c`

### `LicenseClient._delete_local_license`

- implementation: `FUN_23c630900`
- source line hint: `262`
- Nuitka codevar: `_DAT_23ee29c78`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `244` {'__dict_items__': [['data', {'__builtin__': 'str'}], ['return', {'__builtin__': 'bytes'}]]}
     `245` 'LicenseClient._encrypt_data'
     `246` {'__dict_items__': [['encrypted_data', {'__builtin__': 'bytes'}], ['return', {'__builtin__': 'str'}]]}
     `247` 'LicenseClient._decrypt_data'
     `248` 'license_data'
     `249` 'LicenseClient._save_local_license'
     `250` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `251` 'LicenseClient._load_local_license'
  => `252` 'LicenseClient._delete_local_license'
     `253` 'LicenseClient._check_local_expiration'
     `254` {'__dict_items__': [['license_key', {'__builtin__': 'str'}], ['return', {'__generic_alias__': [{'__builtin__': 'tuple'}, [{'__builtin__': 'bool'}, {'__builtin__': 'str'}]]}]]}
     `255` 'activate'
     `256` 'LicenseClient.activate'
     `257` {'__dict_items__': [['return', {'__generic_alias__': [{'__builtin__': 'tuple'}, [{'__builtin__': 'bool'}, {'__builtin__': 'str'}]]}]]}
     `258` 'LicenseClient.validate'
     `259` {'__dict_items__': [['reason', {'__builtin__': 'str'}]]}
     `260` 'LicenseClient._handle_license_invalid'
     `261` 'expiration_callback'
     `262` 'start_background_check'
     `263` 'LicenseClient.start_background_check'
     `264` 'stop_background_check'
     `265` 'LicenseClient.stop_background_check'
     `266` 'LicenseClient._background_check_loop'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\license__license_client\23c630900_LicenseClient._delete_local_license.c`

### `LicenseClient._check_local_expiration`

- implementation: `FUN_23c6350e0`
- source line hint: `355`
- Nuitka codevar: `_DAT_23ee29c68`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `245` 'LicenseClient._encrypt_data'
     `246` {'__dict_items__': [['encrypted_data', {'__builtin__': 'bytes'}], ['return', {'__builtin__': 'str'}]]}
     `247` 'LicenseClient._decrypt_data'
     `248` 'license_data'
     `249` 'LicenseClient._save_local_license'
     `250` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `251` 'LicenseClient._load_local_license'
     `252` 'LicenseClient._delete_local_license'
  => `253` 'LicenseClient._check_local_expiration'
     `254` {'__dict_items__': [['license_key', {'__builtin__': 'str'}], ['return', {'__generic_alias__': [{'__builtin__': 'tuple'}, [{'__builtin__': 'bool'}, {'__builtin__': 'str'}]]}]]}
     `255` 'activate'
     `256` 'LicenseClient.activate'
     `257` {'__dict_items__': [['return', {'__generic_alias__': [{'__builtin__': 'tuple'}, [{'__builtin__': 'bool'}, {'__builtin__': 'str'}]]}]]}
     `258` 'LicenseClient.validate'
     `259` {'__dict_items__': [['reason', {'__builtin__': 'str'}]]}
     `260` 'LicenseClient._handle_license_invalid'
     `261` 'expiration_callback'
     `262` 'start_background_check'
     `263` 'LicenseClient.start_background_check'
     `264` 'stop_background_check'
     `265` 'LicenseClient.stop_background_check'
     `266` 'LicenseClient._background_check_loop'
     `267` 'LicenseClient.is_valid'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\license__license_client\23c6350e0_LicenseClient._check_local_expiration.c`

### `LicenseClient.activate`

- implementation: `FUN_23c636410`
- source line hint: `369`
- Nuitka codevar: `_DAT_23ee29c58`
- factory: `FUN_23e93e480`
- nearby constants:
     `248` 'license_data'
     `249` 'LicenseClient._save_local_license'
     `250` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `251` 'LicenseClient._load_local_license'
     `252` 'LicenseClient._delete_local_license'
     `253` 'LicenseClient._check_local_expiration'
     `254` {'__dict_items__': [['license_key', {'__builtin__': 'str'}], ['return', {'__generic_alias__': [{'__builtin__': 'tuple'}, [{'__builtin__': 'bool'}, {'__builtin__': 'str'}]]}]]}
     `255` 'activate'
  => `256` 'LicenseClient.activate'
     `257` {'__dict_items__': [['return', {'__generic_alias__': [{'__builtin__': 'tuple'}, [{'__builtin__': 'bool'}, {'__builtin__': 'str'}]]}]]}
     `258` 'LicenseClient.validate'
     `259` {'__dict_items__': [['reason', {'__builtin__': 'str'}]]}
     `260` 'LicenseClient._handle_license_invalid'
     `261` 'expiration_callback'
     `262` 'start_background_check'
     `263` 'LicenseClient.start_background_check'
     `264` 'stop_background_check'
     `265` 'LicenseClient.stop_background_check'
     `266` 'LicenseClient._background_check_loop'
     `267` 'LicenseClient.is_valid'
     `268` 'return'
     `269` 'get_license_info'
     `270` 'LicenseClient.get_license_info'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\license__license_client\23c636410_LicenseClient.activate.c`

### `LicenseClient.validate`

- implementation: `FUN_23c637110`
- source line hint: `392`
- Nuitka codevar: `_DAT_23ee29c48`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `250` {'__dict_items__': [['return', {'__builtin__': 'bool'}]]}
     `251` 'LicenseClient._load_local_license'
     `252` 'LicenseClient._delete_local_license'
     `253` 'LicenseClient._check_local_expiration'
     `254` {'__dict_items__': [['license_key', {'__builtin__': 'str'}], ['return', {'__generic_alias__': [{'__builtin__': 'tuple'}, [{'__builtin__': 'bool'}, {'__builtin__': 'str'}]]}]]}
     `255` 'activate'
     `256` 'LicenseClient.activate'
     `257` {'__dict_items__': [['return', {'__generic_alias__': [{'__builtin__': 'tuple'}, [{'__builtin__': 'bool'}, {'__builtin__': 'str'}]]}]]}
  => `258` 'LicenseClient.validate'
     `259` {'__dict_items__': [['reason', {'__builtin__': 'str'}]]}
     `260` 'LicenseClient._handle_license_invalid'
     `261` 'expiration_callback'
     `262` 'start_background_check'
     `263` 'LicenseClient.start_background_check'
     `264` 'stop_background_check'
     `265` 'LicenseClient.stop_background_check'
     `266` 'LicenseClient._background_check_loop'
     `267` 'LicenseClient.is_valid'
     `268` 'return'
     `269` 'get_license_info'
     `270` 'LicenseClient.get_license_info'
     `271` {'__dict_items__': [['return', {'__builtin__': 'str'}]]}
     `272` 'LicenseClient.get_hwid'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\license__license_client\23c637110_LicenseClient.validate.c`

### `LicenseClient._handle_license_invalid`

- implementation: `FUN_23c637910`
- source line hint: `400`
- Nuitka codevar: `_DAT_23ee29c38`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `252` 'LicenseClient._delete_local_license'
     `253` 'LicenseClient._check_local_expiration'
     `254` {'__dict_items__': [['license_key', {'__builtin__': 'str'}], ['return', {'__generic_alias__': [{'__builtin__': 'tuple'}, [{'__builtin__': 'bool'}, {'__builtin__': 'str'}]]}]]}
     `255` 'activate'
     `256` 'LicenseClient.activate'
     `257` {'__dict_items__': [['return', {'__generic_alias__': [{'__builtin__': 'tuple'}, [{'__builtin__': 'bool'}, {'__builtin__': 'str'}]]}]]}
     `258` 'LicenseClient.validate'
     `259` {'__dict_items__': [['reason', {'__builtin__': 'str'}]]}
  => `260` 'LicenseClient._handle_license_invalid'
     `261` 'expiration_callback'
     `262` 'start_background_check'
     `263` 'LicenseClient.start_background_check'
     `264` 'stop_background_check'
     `265` 'LicenseClient.stop_background_check'
     `266` 'LicenseClient._background_check_loop'
     `267` 'LicenseClient.is_valid'
     `268` 'return'
     `269` 'get_license_info'
     `270` 'LicenseClient.get_license_info'
     `271` {'__dict_items__': [['return', {'__builtin__': 'str'}]]}
     `272` 'LicenseClient.get_hwid'
     `273` 'license\\license_client.py'
     `274` '<module license.license_client>'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\license__license_client\23c637910_LicenseClient._handle_license_invalid.c`

### `LicenseClient.start_background_check`

- implementation: `FUN_23c63ab20`
- source line hint: `432`
- Nuitka codevar: `DAT_23ee29c28`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `255` 'activate'
     `256` 'LicenseClient.activate'
     `257` {'__dict_items__': [['return', {'__generic_alias__': [{'__builtin__': 'tuple'}, [{'__builtin__': 'bool'}, {'__builtin__': 'str'}]]}]]}
     `258` 'LicenseClient.validate'
     `259` {'__dict_items__': [['reason', {'__builtin__': 'str'}]]}
     `260` 'LicenseClient._handle_license_invalid'
     `261` 'expiration_callback'
     `262` 'start_background_check'
  => `263` 'LicenseClient.start_background_check'
     `264` 'stop_background_check'
     `265` 'LicenseClient.stop_background_check'
     `266` 'LicenseClient._background_check_loop'
     `267` 'LicenseClient.is_valid'
     `268` 'return'
     `269` 'get_license_info'
     `270` 'LicenseClient.get_license_info'
     `271` {'__dict_items__': [['return', {'__builtin__': 'str'}]]}
     `272` 'LicenseClient.get_hwid'
     `273` 'license\\license_client.py'
     `274` '<module license.license_client>'
     `275` ['__class__']
     `276` ['self', 'config_dir']
     `277` ['self', 'is_valid', 'message', 'e']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\license__license_client\23c63ab20_LicenseClient.start_background_check.c`

### `LicenseClient.stop_background_check`

- implementation: `FUN_23c63af70`
- source line hint: `436`
- Nuitka codevar: `DAT_23ee29c18`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `257` {'__dict_items__': [['return', {'__generic_alias__': [{'__builtin__': 'tuple'}, [{'__builtin__': 'bool'}, {'__builtin__': 'str'}]]}]]}
     `258` 'LicenseClient.validate'
     `259` {'__dict_items__': [['reason', {'__builtin__': 'str'}]]}
     `260` 'LicenseClient._handle_license_invalid'
     `261` 'expiration_callback'
     `262` 'start_background_check'
     `263` 'LicenseClient.start_background_check'
     `264` 'stop_background_check'
  => `265` 'LicenseClient.stop_background_check'
     `266` 'LicenseClient._background_check_loop'
     `267` 'LicenseClient.is_valid'
     `268` 'return'
     `269` 'get_license_info'
     `270` 'LicenseClient.get_license_info'
     `271` {'__dict_items__': [['return', {'__builtin__': 'str'}]]}
     `272` 'LicenseClient.get_hwid'
     `273` 'license\\license_client.py'
     `274` '<module license.license_client>'
     `275` ['__class__']
     `276` ['self', 'config_dir']
     `277` ['self', 'is_valid', 'message', 'e']
     `278` ['self', 'expires_at_str', 'expires_at', 'now', 'now_naive', 'is_valid', 'e']
     `279` ['self', 'encrypted_data']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\license__license_client\23c63af70_LicenseClient.stop_background_check.c`

### `LicenseClient._background_check_loop`

- implementation: `FUN_23c63b6d0`
- source line hint: `449`
- Nuitka codevar: `_DAT_23ee29c08`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `258` 'LicenseClient.validate'
     `259` {'__dict_items__': [['reason', {'__builtin__': 'str'}]]}
     `260` 'LicenseClient._handle_license_invalid'
     `261` 'expiration_callback'
     `262` 'start_background_check'
     `263` 'LicenseClient.start_background_check'
     `264` 'stop_background_check'
     `265` 'LicenseClient.stop_background_check'
  => `266` 'LicenseClient._background_check_loop'
     `267` 'LicenseClient.is_valid'
     `268` 'return'
     `269` 'get_license_info'
     `270` 'LicenseClient.get_license_info'
     `271` {'__dict_items__': [['return', {'__builtin__': 'str'}]]}
     `272` 'LicenseClient.get_hwid'
     `273` 'license\\license_client.py'
     `274` '<module license.license_client>'
     `275` ['__class__']
     `276` ['self', 'config_dir']
     `277` ['self', 'is_valid', 'message', 'e']
     `278` ['self', 'expires_at_str', 'expires_at', 'now', 'now_naive', 'is_valid', 'e']
     `279` ['self', 'encrypted_data']
     `280` ['self', 'e']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\license__license_client\23c63b6d0_LicenseClient._background_check_loop.c`
