# Function Specification: `ui.home_tab`

This is a reconstruction dossier from static Nuitka constants and Ghidra decompilation. It is not original Python source text.

## Source Path Hints
- `ui\home_tab.py`

## Docstrings / Long Text
- `10` '\n        Args:\n            license_client: Экземпляр LicenseClient для работы с лицензией\n            parent: Родительский виджет\n        '
- `41` '\n            QLabel {\n                background-color: '
- `43` ';\n                border: 1px solid #48484A;\n                border-radius: 8px;\n                padding: 12px;\n            }\n        '
- `54` '\n            QLineEdit {\n                background-color: '
- `55` ';\n                color: '
- `57` ';\n                border: 1px solid #48484A;\n                border-radius: 8px;\n                padding: 12px;\n                font-size: 13px;\n            }\n            QLineEdit:focus {\n                border: 1px solid '
- `59` ';\n            }\n        '
- `66` '\n            QPushButton {\n                background-color: '
- `67` ';\n                color: white;\n                border: none;\n                border-radius: 8px;\n                font-size: 13px;\n                font-weight: 600;\n                padding: 0 20px;\n            }\n            QPushButton:hover {\n                background-color: #FF1A90;\n            }\n            QPushButton:pressed {\n                background-color: #E0006E;\n            }\n            QPushButton:disabled {\n                background-color: #48484A;\n          ...
- `110` '\n            QFrame#infoCard {\n                background-color: '
- `112` ';\n                border-radius: 12px;\n            }\n        '
- `114` '\n            font-size: 15px;\n            font-weight: 600;\n            color: '
- `115` ';\n            margin-bottom: 4px;\n        '
- `121` '\n            QPushButton {\n                background-color: transparent;\n                color: '
- `122` ';\n                text-decoration: underline;\n                text-align: left;\n                padding: 8px;\n                border: none;\n                font-size: 13px;\n                font-weight: 600;\n            }\n            QPushButton:hover {\n                color: #FF1A90;\n                background-color: rgba(255, 0, 128, 0.1);\n                border-radius: 6px;\n            }\n        '
- `205` '<a href="\\1" style="color: #FF0080; font-weight: 700; text-decoration: none;">\\1</a>'
- `206` '<div style="color: #FFFFFF; font-weight: 600; line-height: 1.8; font-size: 13px;">'
- `234` '\nВкладка "Главная" для KortexWorker\nИнформация о лицензии, промокоды, информация с сервера\n'

## Function Inventory
| Inferred qualname | Impl | Source line | Arg count | Decompiled C |
|---|---:|---:|---:|---|
| `HomeTab.__init__` | `FUN_23e2b6010` | 54 | 1 | yes |
| `HomeTab.init_ui` | `FUN_23e2c3530` | 219 | 2 | yes |
| `HomeTab._create_card` | `FUN_23e2c46d0` | 247 | 3 | yes |
| `HomeTab._create_info_row` | `FUN_23e2c5810` | 264 | 1 | yes |
| `HomeTab._get_link_button_style` | `FUN_23e2c5dd0` | 284 | 2 | yes |
| `HomeTab._open_url` | `FUN_23e2c6870` | 289 | 1 | yes |
| `HomeTab.update_license_info` | `FUN_23e2cc5b0` | 375 | 1 | yes |
| `HomeTab.load_server_info` | `FUN_23e2cf8f0` | 406 | 2 | yes |
| `HomeTab._convert_text_to_html` | `FUN_23e2d0320` | 429 | 1 | yes |
| `HomeTab.apply_promocode` | `FUN_23e2b5580` | ? | ? | yes |

## Local Variable Lists
- `287` `self`
- `289` `__class__`
- `290` `self, license_client, parent, __class__`
- `291` `self, text, re, url_pattern, html`
- `292` `self, title, card, card_layout, title_label`
- `293` `self, label_text, value_text, layout, label, value`
- `294` `self, url`
- `295` `self, promocode, requests, LicenseClient, response, data, message, error, e`
- `296` `self, main_layout, scroll, scroll_content, scroll_layout, server_info_card, server_info_layout, promo_card, promo_layout, promo_input_layout, license_card, license_layout, status_row, expires_row, remaining_row, key_row, links_card, links_layout, tg_layout, tg_icon, tg_link, fp_layout, fp_icon, fp_link`
- `297` `self, requests, LicenseClient, url, response, data, info_text, html_text, error_msg, e`
- `298` `self, license_data, expires_at, expires_dt, local_dt, formatted_date, now, remaining, days, hours, minutes, remaining_text, e, key, masked_key`

## Structured Constants
- `8` [5000]
- `13` [30, 30, 30, 30]
- `15` [20]
- `18` [True]
- `26` [0, 0, 10, 0]
- `49` [12]
- `65` [44]
- `90` [30]
- `113` [16, 16, 16, 16]
- `167` {'__slice__': [None, 4, None]}
- `169` {'__slice__': [-4, None, None]}
- `172` {'__dict_items__': [['exc_info', True]]}
- `181` {'__dict_items__': [['timeout', 10]]}
- `214` [False]
- `268` [None]

## Per-Function Context
### `HomeTab.__init__`

- implementation: `FUN_23e2b6010`
- source line hint: `54`
- Nuitka codevar: `DAT_23eeb0368`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `261` 'HomeTab'
     `262` '__getitem__'
     `263` '%s.__prepare__() must return a mapping, not %s'
     `264` '<metaclass>'
     `265` 'ui.home_tab'
     `266` 'Вкладка с информацией о лицензии'
     `267` '__qualname__'
     `268` [None]
  => `269` 'HomeTab.__init__'
     `270` 'HomeTab.init_ui'
     `271` 'title'
     `272` 'str'
     `273` 'HomeTab._create_card'
     `274` 'label_text'
     `275` 'value_text'
     `276` 'HomeTab._create_info_row'
     `277` 'return'
     `278` 'HomeTab._get_link_button_style'
     `279` 'url'
     `280` 'HomeTab._open_url'
     `281` 'HomeTab.update_license_info'
     `282` 'HomeTab.load_server_info'
     `283` 'HomeTab._convert_text_to_html'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__home_tab\23e2b6010_HomeTab.__init.c`

### `HomeTab.init_ui`

- implementation: `FUN_23e2c3530`
- source line hint: `219`
- Nuitka codevar: `DAT_23eeb0328`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `262` '__getitem__'
     `263` '%s.__prepare__() must return a mapping, not %s'
     `264` '<metaclass>'
     `265` 'ui.home_tab'
     `266` 'Вкладка с информацией о лицензии'
     `267` '__qualname__'
     `268` [None]
     `269` 'HomeTab.__init__'
  => `270` 'HomeTab.init_ui'
     `271` 'title'
     `272` 'str'
     `273` 'HomeTab._create_card'
     `274` 'label_text'
     `275` 'value_text'
     `276` 'HomeTab._create_info_row'
     `277` 'return'
     `278` 'HomeTab._get_link_button_style'
     `279` 'url'
     `280` 'HomeTab._open_url'
     `281` 'HomeTab.update_license_info'
     `282` 'HomeTab.load_server_info'
     `283` 'HomeTab._convert_text_to_html'
     `284` 'HomeTab.apply_promocode'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__home_tab\23e2c3530_HomeTab.init_ui.c`

### `HomeTab._create_card`

- implementation: `FUN_23e2c46d0`
- source line hint: `247`
- Nuitka codevar: `DAT_23eeb0310`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `265` 'ui.home_tab'
     `266` 'Вкладка с информацией о лицензии'
     `267` '__qualname__'
     `268` [None]
     `269` 'HomeTab.__init__'
     `270` 'HomeTab.init_ui'
     `271` 'title'
     `272` 'str'
  => `273` 'HomeTab._create_card'
     `274` 'label_text'
     `275` 'value_text'
     `276` 'HomeTab._create_info_row'
     `277` 'return'
     `278` 'HomeTab._get_link_button_style'
     `279` 'url'
     `280` 'HomeTab._open_url'
     `281` 'HomeTab.update_license_info'
     `282` 'HomeTab.load_server_info'
     `283` 'HomeTab._convert_text_to_html'
     `284` 'HomeTab.apply_promocode'
     `285` '__orig_bases__'
     `286` 'ui\\home_tab.py'
     `287` ['self']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__home_tab\23e2c46d0_HomeTab._create_card.c`

### `HomeTab._create_info_row`

- implementation: `FUN_23e2c5810`
- source line hint: `264`
- Nuitka codevar: `DAT_23eeb0300`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `268` [None]
     `269` 'HomeTab.__init__'
     `270` 'HomeTab.init_ui'
     `271` 'title'
     `272` 'str'
     `273` 'HomeTab._create_card'
     `274` 'label_text'
     `275` 'value_text'
  => `276` 'HomeTab._create_info_row'
     `277` 'return'
     `278` 'HomeTab._get_link_button_style'
     `279` 'url'
     `280` 'HomeTab._open_url'
     `281` 'HomeTab.update_license_info'
     `282` 'HomeTab.load_server_info'
     `283` 'HomeTab._convert_text_to_html'
     `284` 'HomeTab.apply_promocode'
     `285` '__orig_bases__'
     `286` 'ui\\home_tab.py'
     `287` ['self']
     `288` '<module ui.home_tab>'
     `289` ['__class__']
     `290` ['self', 'license_client', 'parent', '__class__']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__home_tab\23e2c5810_HomeTab._create_info_row.c`

### `HomeTab._get_link_button_style`

- implementation: `FUN_23e2c5dd0`
- source line hint: `284`
- Nuitka codevar: `DAT_23eeb02f0`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `270` 'HomeTab.init_ui'
     `271` 'title'
     `272` 'str'
     `273` 'HomeTab._create_card'
     `274` 'label_text'
     `275` 'value_text'
     `276` 'HomeTab._create_info_row'
     `277` 'return'
  => `278` 'HomeTab._get_link_button_style'
     `279` 'url'
     `280` 'HomeTab._open_url'
     `281` 'HomeTab.update_license_info'
     `282` 'HomeTab.load_server_info'
     `283` 'HomeTab._convert_text_to_html'
     `284` 'HomeTab.apply_promocode'
     `285` '__orig_bases__'
     `286` 'ui\\home_tab.py'
     `287` ['self']
     `288` '<module ui.home_tab>'
     `289` ['__class__']
     `290` ['self', 'license_client', 'parent', '__class__']
     `291` ['self', 'text', 're', 'url_pattern', 'html']
     `292` ['self', 'title', 'card', 'card_layout', 'title_label']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__home_tab\23e2c5dd0_HomeTab._get_link_button_style.c`

### `HomeTab._open_url`

- implementation: `FUN_23e2c6870`
- source line hint: `289`
- Nuitka codevar: `DAT_23eeb02d0`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `272` 'str'
     `273` 'HomeTab._create_card'
     `274` 'label_text'
     `275` 'value_text'
     `276` 'HomeTab._create_info_row'
     `277` 'return'
     `278` 'HomeTab._get_link_button_style'
     `279` 'url'
  => `280` 'HomeTab._open_url'
     `281` 'HomeTab.update_license_info'
     `282` 'HomeTab.load_server_info'
     `283` 'HomeTab._convert_text_to_html'
     `284` 'HomeTab.apply_promocode'
     `285` '__orig_bases__'
     `286` 'ui\\home_tab.py'
     `287` ['self']
     `288` '<module ui.home_tab>'
     `289` ['__class__']
     `290` ['self', 'license_client', 'parent', '__class__']
     `291` ['self', 'text', 're', 'url_pattern', 'html']
     `292` ['self', 'title', 'card', 'card_layout', 'title_label']
     `293` ['self', 'label_text', 'value_text', 'layout', 'label', 'value']
     `294` ['self', 'url']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__home_tab\23e2c6870_HomeTab._open_url.c`

### `HomeTab.update_license_info`

- implementation: `FUN_23e2cc5b0`
- source line hint: `375`
- Nuitka codevar: `DAT_23eeb02b8`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `273` 'HomeTab._create_card'
     `274` 'label_text'
     `275` 'value_text'
     `276` 'HomeTab._create_info_row'
     `277` 'return'
     `278` 'HomeTab._get_link_button_style'
     `279` 'url'
     `280` 'HomeTab._open_url'
  => `281` 'HomeTab.update_license_info'
     `282` 'HomeTab.load_server_info'
     `283` 'HomeTab._convert_text_to_html'
     `284` 'HomeTab.apply_promocode'
     `285` '__orig_bases__'
     `286` 'ui\\home_tab.py'
     `287` ['self']
     `288` '<module ui.home_tab>'
     `289` ['__class__']
     `290` ['self', 'license_client', 'parent', '__class__']
     `291` ['self', 'text', 're', 'url_pattern', 'html']
     `292` ['self', 'title', 'card', 'card_layout', 'title_label']
     `293` ['self', 'label_text', 'value_text', 'layout', 'label', 'value']
     `294` ['self', 'url']
     `295` ['self', 'promocode', 'requests', 'LicenseClient', 'response', 'data', 'message', 'error', 'e']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__home_tab\23e2cc5b0_HomeTab.update_license_info.c`

### `HomeTab.load_server_info`

- implementation: `FUN_23e2cf8f0`
- source line hint: `406`
- Nuitka codevar: `DAT_23eeb02a8`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `274` 'label_text'
     `275` 'value_text'
     `276` 'HomeTab._create_info_row'
     `277` 'return'
     `278` 'HomeTab._get_link_button_style'
     `279` 'url'
     `280` 'HomeTab._open_url'
     `281` 'HomeTab.update_license_info'
  => `282` 'HomeTab.load_server_info'
     `283` 'HomeTab._convert_text_to_html'
     `284` 'HomeTab.apply_promocode'
     `285` '__orig_bases__'
     `286` 'ui\\home_tab.py'
     `287` ['self']
     `288` '<module ui.home_tab>'
     `289` ['__class__']
     `290` ['self', 'license_client', 'parent', '__class__']
     `291` ['self', 'text', 're', 'url_pattern', 'html']
     `292` ['self', 'title', 'card', 'card_layout', 'title_label']
     `293` ['self', 'label_text', 'value_text', 'layout', 'label', 'value']
     `294` ['self', 'url']
     `295` ['self', 'promocode', 'requests', 'LicenseClient', 'response', 'data', 'message', 'error', 'e']
     `296` ['self', 'main_layout', 'scroll', 'scroll_content', 'scroll_layout', 'server_info_card', 'server_info_layout', 'promo_card', 'promo_layout', 'promo_input_layout', 'license_card', 'license_layout', 'status_row', 'expires_row', 'remaining_row', 'key_row', 'links_card', 'links_la...
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__home_tab\23e2cf8f0_HomeTab.load_server_info.c`

### `HomeTab._convert_text_to_html`

- implementation: `FUN_23e2d0320`
- source line hint: `429`
- Nuitka codevar: `DAT_23eeb0298`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `275` 'value_text'
     `276` 'HomeTab._create_info_row'
     `277` 'return'
     `278` 'HomeTab._get_link_button_style'
     `279` 'url'
     `280` 'HomeTab._open_url'
     `281` 'HomeTab.update_license_info'
     `282` 'HomeTab.load_server_info'
  => `283` 'HomeTab._convert_text_to_html'
     `284` 'HomeTab.apply_promocode'
     `285` '__orig_bases__'
     `286` 'ui\\home_tab.py'
     `287` ['self']
     `288` '<module ui.home_tab>'
     `289` ['__class__']
     `290` ['self', 'license_client', 'parent', '__class__']
     `291` ['self', 'text', 're', 'url_pattern', 'html']
     `292` ['self', 'title', 'card', 'card_layout', 'title_label']
     `293` ['self', 'label_text', 'value_text', 'layout', 'label', 'value']
     `294` ['self', 'url']
     `295` ['self', 'promocode', 'requests', 'LicenseClient', 'response', 'data', 'message', 'error', 'e']
     `296` ['self', 'main_layout', 'scroll', 'scroll_content', 'scroll_layout', 'server_info_card', 'server_info_layout', 'promo_card', 'promo_layout', 'promo_input_layout', 'license_card', 'license_layout', 'status_row', 'expires_row', 'remaining_row', 'key_row', 'links_card', 'links_la...
     `297` ['self', 'requests', 'LicenseClient', 'url', 'response', 'data', 'info_text', 'html_text', 'error_msg', 'e']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__home_tab\23e2d0320_HomeTab._convert_text_to_html.c`

### `HomeTab.apply_promocode`

- implementation: `FUN_23e2b5580`
- source line hint: `?`
- Nuitka codevar: `uVar4`
- factory: `FUN_23e93e480`
- nearby constants:
     `276` 'HomeTab._create_info_row'
     `277` 'return'
     `278` 'HomeTab._get_link_button_style'
     `279` 'url'
     `280` 'HomeTab._open_url'
     `281` 'HomeTab.update_license_info'
     `282` 'HomeTab.load_server_info'
     `283` 'HomeTab._convert_text_to_html'
  => `284` 'HomeTab.apply_promocode'
     `285` '__orig_bases__'
     `286` 'ui\\home_tab.py'
     `287` ['self']
     `288` '<module ui.home_tab>'
     `289` ['__class__']
     `290` ['self', 'license_client', 'parent', '__class__']
     `291` ['self', 'text', 're', 'url_pattern', 'html']
     `292` ['self', 'title', 'card', 'card_layout', 'title_label']
     `293` ['self', 'label_text', 'value_text', 'layout', 'label', 'value']
     `294` ['self', 'url']
     `295` ['self', 'promocode', 'requests', 'LicenseClient', 'response', 'data', 'message', 'error', 'e']
     `296` ['self', 'main_layout', 'scroll', 'scroll_content', 'scroll_layout', 'server_info_card', 'server_info_layout', 'promo_card', 'promo_layout', 'promo_input_layout', 'license_card', 'license_layout', 'status_row', 'expires_row', 'remaining_row', 'key_row', 'links_card', 'links_la...
     `297` ['self', 'requests', 'LicenseClient', 'url', 'response', 'data', 'info_text', 'html_text', 'error_msg', 'e']
     `298` ['self', 'license_data', 'expires_at', 'expires_dt', 'local_dt', 'formatted_date', 'now', 'remaining', 'days', 'hours', 'minutes', 'remaining_text', 'e', 'key', 'masked_key']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__home_tab\23e2b5580_HomeTab.apply_promocode.c`
