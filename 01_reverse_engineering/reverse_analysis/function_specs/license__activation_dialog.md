# Function Specification: `license.activation_dialog`

This is a reconstruction dossier from static Nuitka constants and Ghidra decompilation. It is not original Python source text.

## Source Path Hints
- `license\activation_dialog.py`

## Docstrings / Long Text
- `7` '\n        Args:\n            license_client: Экземпляр LicenseClient\n            parent: Родительский виджет\n        '
- `13` '\n            QDialog {\n                background-color: '
- `15` ';\n            }\n            QLabel {\n                color: '
- `17` ';\n            }\n            QLineEdit {\n                background-color: '
- `19` ';\n                border: 2px solid '
- `21` ';\n                border-radius: 12px;\n                padding: 14px 16px;\n                color: '
- `22` ";\n                font-size: 15px;\n                font-family: 'Consolas', 'Courier New', monospace;\n                font-weight: 600;\n            }\n            QLineEdit:focus {\n                border-color: "
- `24` ';\n            }\n            QPushButton {\n                background-color: '
- `25` ';\n                color: '
- `26` ';\n                border: none;\n                border-radius: 12px;\n                padding: 14px 24px;\n                font-size: 14px;\n                font-weight: 600;\n            }\n            QPushButton:hover {\n                background-color: #4A4A4C;\n            }\n            QPushButton:pressed {\n                background-color: #2A2A2C;\n            }\n            QPushButton:disabled {\n                background-color: #2A2A2C;\n                color: #5A5A5C;\n    ...
- `27` ';\n                color: white;\n            }\n            QPushButton#activateButton:hover {\n                background-color: #FF1A90;\n            }\n            QPushButton#activateButton:pressed {\n                background-color: #E00070;\n            }\n            QPushButton#closeButton {\n                background-color: '
- `28` ';\n            }\n            QPushButton#closeButton:hover {\n                background-color: #2C2C2E;\n            }\n            QTextEdit {\n                background-color: '
- `29` ';\n                border: 1px solid '
- `30` ';\n                border-radius: 12px;\n                padding: 12px;\n                color: '
- `31` ';\n                font-size: 12px;\n            }\n            QFrame#infoCard {\n                background-color: '
- `32` ';\n                border-radius: 12px;\n                padding: 12px;\n            }\n        '
- `40` '\n            font-size: 26px;\n            font-weight: bold;\n            color: '
- `41` ';\n            margin-bottom: 4px;\n        '
- `47` '\n            font-size: 13px;\n            color: '
- `49` ';\n            margin-bottom: 12px;\n        '
- ... 3 more

## Function Inventory
| Inferred qualname | Impl | Source line | Arg count | Decompiled C |
|---|---:|---:|---:|---|
| `ActivationDialog.__init__` | `FUN_23c60a570` | 46 | 1 | yes |
| `ActivationDialog.setup_ui` | `FUN_23c6178c0` | 281 | 2 | yes |
| `ActivationDialog._format_key_input` | `FUN_23c618600` | 298 | 1 | yes |
| `ActivationDialog._on_activate_clicked` | `FUN_23c619660` | 313 | 2 | yes |
| `ActivationDialog._do_activation` | `FUN_23c61ba20` | 333 | 3 | yes |
| `ActivationDialog._show_status` | `FUN_23c61c640` | 348 | 2 | yes |
| `ActivationDialog._open_url` | `FUN_23c609bc0` | ? | ? | yes |

## Local Variable Lists
- `232` `.0, c`
- `233` `.0, i, cleaned`
- `234` `self, key`
- `235` `key, self`
- `236` `self`
- `238` `__class__`
- `239` `self, license_client, parent, __class__`
- `240` `self, key, success, message, e`
- `241` `self, text, cleaned, formatted, cursor_pos`
- `242` `self, url`
- `243` `self, message, status_type, color, html, scrollbar`
- `244` `self, main_layout, title_label, subtitle_label, hwid_card, hwid_layout, hwid, hwid_title, hwid_value, key_label, button_layout, links_card, links_layout, links_title, tg_layout, tg_label, tg_link, fp_layout, fp_label, fp_link`

## Structured Constants
- `11` [550, 600]
- `35` [30, 30, 30, 30]
- `37` [16]
- `51` [True]
- `53` [8]
- `57` [12, 10, 12, 10]
- `58` [4]
- `63` {'__slice__': [None, 32, None]}
- `77` [19]
- `87` [80]
- `90` [12]
- `97` [48]
- `103` [16, 12, 16, 12]
- `104` [10]
- `136` [False]
- `218` [None]

## Per-Function Context
### `ActivationDialog.__init__`

- implementation: `FUN_23c60a570`
- source line hint: `46`
- Nuitka codevar: `DAT_23ee29f58`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `211` '__getitem__'
     `212` '%s.__prepare__() must return a mapping, not %s'
     `213` '<metaclass>'
     `214` 'license.activation_dialog'
     `215` 'Диалог активации лицензии'
     `216` '__qualname__'
     `217` 'str'
     `218` [None]
  => `219` 'ActivationDialog.__init__'
     `220` 'ActivationDialog.setup_ui'
     `221` 'ActivationDialog._format_key_input'
     `222` 'ActivationDialog._on_activate_clicked'
     `223` 'ActivationDialog._do_activation'
     `224` ['info']
     `225` 'message'
     `226` 'status_type'
     `227` 'ActivationDialog._show_status'
     `228` 'url'
     `229` 'ActivationDialog._open_url'
     `230` '__orig_bases__'
     `231` 'license\\activation_dialog.py'
     `232` ['.0', 'c']
     `233` ['.0', 'i', 'cleaned']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\license__activation_dialog\23c60a570_ActivationDialog.__init.c`

### `ActivationDialog.setup_ui`

- implementation: `FUN_23c6178c0`
- source line hint: `281`
- Nuitka codevar: `DAT_23ee29f00`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `212` '%s.__prepare__() must return a mapping, not %s'
     `213` '<metaclass>'
     `214` 'license.activation_dialog'
     `215` 'Диалог активации лицензии'
     `216` '__qualname__'
     `217` 'str'
     `218` [None]
     `219` 'ActivationDialog.__init__'
  => `220` 'ActivationDialog.setup_ui'
     `221` 'ActivationDialog._format_key_input'
     `222` 'ActivationDialog._on_activate_clicked'
     `223` 'ActivationDialog._do_activation'
     `224` ['info']
     `225` 'message'
     `226` 'status_type'
     `227` 'ActivationDialog._show_status'
     `228` 'url'
     `229` 'ActivationDialog._open_url'
     `230` '__orig_bases__'
     `231` 'license\\activation_dialog.py'
     `232` ['.0', 'c']
     `233` ['.0', 'i', 'cleaned']
     `234` ['self', 'key']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\license__activation_dialog\23c6178c0_ActivationDialog.setup_ui.c`

### `ActivationDialog._format_key_input`

- implementation: `FUN_23c618600`
- source line hint: `298`
- Nuitka codevar: `DAT_23ee29ed0`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `213` '<metaclass>'
     `214` 'license.activation_dialog'
     `215` 'Диалог активации лицензии'
     `216` '__qualname__'
     `217` 'str'
     `218` [None]
     `219` 'ActivationDialog.__init__'
     `220` 'ActivationDialog.setup_ui'
  => `221` 'ActivationDialog._format_key_input'
     `222` 'ActivationDialog._on_activate_clicked'
     `223` 'ActivationDialog._do_activation'
     `224` ['info']
     `225` 'message'
     `226` 'status_type'
     `227` 'ActivationDialog._show_status'
     `228` 'url'
     `229` 'ActivationDialog._open_url'
     `230` '__orig_bases__'
     `231` 'license\\activation_dialog.py'
     `232` ['.0', 'c']
     `233` ['.0', 'i', 'cleaned']
     `234` ['self', 'key']
     `235` ['key', 'self']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\license__activation_dialog\23c618600_ActivationDialog._format_key_input.c`

### `ActivationDialog._on_activate_clicked`

- implementation: `FUN_23c619660`
- source line hint: `313`
- Nuitka codevar: `DAT_23ee29eb0`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `214` 'license.activation_dialog'
     `215` 'Диалог активации лицензии'
     `216` '__qualname__'
     `217` 'str'
     `218` [None]
     `219` 'ActivationDialog.__init__'
     `220` 'ActivationDialog.setup_ui'
     `221` 'ActivationDialog._format_key_input'
  => `222` 'ActivationDialog._on_activate_clicked'
     `223` 'ActivationDialog._do_activation'
     `224` ['info']
     `225` 'message'
     `226` 'status_type'
     `227` 'ActivationDialog._show_status'
     `228` 'url'
     `229` 'ActivationDialog._open_url'
     `230` '__orig_bases__'
     `231` 'license\\activation_dialog.py'
     `232` ['.0', 'c']
     `233` ['.0', 'i', 'cleaned']
     `234` ['self', 'key']
     `235` ['key', 'self']
     `236` ['self']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\license__activation_dialog\23c619660_ActivationDialog._on_activate_clicked.c`

### `ActivationDialog._do_activation`

- implementation: `FUN_23c61ba20`
- source line hint: `333`
- Nuitka codevar: `uVar5`
- factory: `FUN_23e93e480`
- nearby constants:
     `215` 'Диалог активации лицензии'
     `216` '__qualname__'
     `217` 'str'
     `218` [None]
     `219` 'ActivationDialog.__init__'
     `220` 'ActivationDialog.setup_ui'
     `221` 'ActivationDialog._format_key_input'
     `222` 'ActivationDialog._on_activate_clicked'
  => `223` 'ActivationDialog._do_activation'
     `224` ['info']
     `225` 'message'
     `226` 'status_type'
     `227` 'ActivationDialog._show_status'
     `228` 'url'
     `229` 'ActivationDialog._open_url'
     `230` '__orig_bases__'
     `231` 'license\\activation_dialog.py'
     `232` ['.0', 'c']
     `233` ['.0', 'i', 'cleaned']
     `234` ['self', 'key']
     `235` ['key', 'self']
     `236` ['self']
     `237` '<module license.activation_dialog>'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\license__activation_dialog\23c61ba20_ActivationDialog._do_activation.c`

### `ActivationDialog._show_status`

- implementation: `FUN_23c61c640`
- source line hint: `348`
- Nuitka codevar: `DAT_23ee29e90`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `219` 'ActivationDialog.__init__'
     `220` 'ActivationDialog.setup_ui'
     `221` 'ActivationDialog._format_key_input'
     `222` 'ActivationDialog._on_activate_clicked'
     `223` 'ActivationDialog._do_activation'
     `224` ['info']
     `225` 'message'
     `226` 'status_type'
  => `227` 'ActivationDialog._show_status'
     `228` 'url'
     `229` 'ActivationDialog._open_url'
     `230` '__orig_bases__'
     `231` 'license\\activation_dialog.py'
     `232` ['.0', 'c']
     `233` ['.0', 'i', 'cleaned']
     `234` ['self', 'key']
     `235` ['key', 'self']
     `236` ['self']
     `237` '<module license.activation_dialog>'
     `238` ['__class__']
     `239` ['self', 'license_client', 'parent', '__class__']
     `240` ['self', 'key', 'success', 'message', 'e']
     `241` ['self', 'text', 'cleaned', 'formatted', 'cursor_pos']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\license__activation_dialog\23c61c640_ActivationDialog._show_status.c`

### `ActivationDialog._open_url`

- implementation: `FUN_23c609bc0`
- source line hint: `?`
- Nuitka codevar: `uVar10`
- factory: `FUN_23e93e480`
- nearby constants:
     `221` 'ActivationDialog._format_key_input'
     `222` 'ActivationDialog._on_activate_clicked'
     `223` 'ActivationDialog._do_activation'
     `224` ['info']
     `225` 'message'
     `226` 'status_type'
     `227` 'ActivationDialog._show_status'
     `228` 'url'
  => `229` 'ActivationDialog._open_url'
     `230` '__orig_bases__'
     `231` 'license\\activation_dialog.py'
     `232` ['.0', 'c']
     `233` ['.0', 'i', 'cleaned']
     `234` ['self', 'key']
     `235` ['key', 'self']
     `236` ['self']
     `237` '<module license.activation_dialog>'
     `238` ['__class__']
     `239` ['self', 'license_client', 'parent', '__class__']
     `240` ['self', 'key', 'success', 'message', 'e']
     `241` ['self', 'text', 'cleaned', 'formatted', 'cursor_pos']
     `242` ['self', 'url']
     `243` ['self', 'message', 'status_type', 'color', 'html', 'scrollbar']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\license__activation_dialog\23c609bc0_ActivationDialog._open_url.c`
