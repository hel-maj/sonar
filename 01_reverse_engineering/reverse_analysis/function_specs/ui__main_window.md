# Function Specification: `ui.main_window`

This is a reconstruction dossier from static Nuitka constants and Ghidra decompilation. It is not original Python source text.

## Source Path Hints
- `ui\main_window.py`

## Docstrings / Long Text
- `13` '\n        <span style="color: '
- `19` 'px; font-weight: 700;">Worker</span>\n        <span style="color: '
- `22` 'px; margin-left: 8px;">v1.2.9</span>\n        '
- `138` '\nГлавное окно KortexWorker\nБоковое меню с вкладками в iOS-стиле с неоновым заголовком\n'

## Function Inventory
| Inferred qualname | Impl | Source line | Arg count | Decompiled C |
|---|---:|---:|---:|---|
| `icon.ico` | `FUN_23e2fa540` | ? | ? | yes |
| `NeonLabel.__init__` | `FUN_23e2fca70` | ? | ? | yes |
| `NeonLabel.glow_intensity` | `FUN_23e2fce50` | ? | ? | yes |
| `NeonLabel.update_glow` | `FUN_23e2fd260` | ? | ? | yes |
| `MainWindow.__init__` | `FUN_23e2ff8a0` | ? | ? | yes |
| `MainWindow.init_ui` | `FUN_23e3069f0` | ? | ? | yes |

## Local Variable Lists
- `187` `self`
- `189` `__class__`
- `190` `self, license_client, current_app, app_icon, candidates, icon_path, icon, __class__`
- `191` `self, parent, __class__`
- `192` `self, text, btn, font`
- `193` `self, value`
- `194` `self, central_widget, main_layout, sidebar, sidebar_layout, title_label, info_label, content_area, content_layout`
- `195` `self, index, i, btn`
- `196` `self, blur_radius`

## Structured Constants
- `24` {'__bytes__': '676c6f775f696e74656e73697479', 'size': 14}
- `29` [0.0]
- `31` [1.0]
- `37` [-1]
- `48` [1000, 700]
- `66` [0, 0, 0, 0]
- `68` [0]
- `73` [250]
- `75` [16, 20, 16, 20]
- `76` [8]
- `80` [20]
- `92` [True]
- `122` [1]
- `123` [2]
- `124` [3]
- `129` [50]
- `132` [11]
- `172` [None]

## Per-Function Context
### `icon.ico`

- implementation: `FUN_23e2fa540`
- source line hint: `?`
- Nuitka codevar: `DAT_23eeac6a0`
- factory: `FUN_23e93e480`
- nearby constants:
     `49` 'QApplication'
     `50` 'instance'
     `51` 'windowIcon'
     `52` 'QIcon'
     `53` 'isNull'
     `54` 'setWindowIcon'
     `55` 'join'
     `56` 'resources'
  => `57` 'icon.ico'
     `58` 'executable'
     `59` 'init_ui'
     `60` 'setStyleSheet'
     `61` 'MAIN_STYLE'
     `62` 'QWidget'
     `63` 'setCentralWidget'
     `64` 'QHBoxLayout'
     `65` 'setContentsMargins'
     `66` [0, 0, 0, 0]
     `67` 'setSpacing'
     `68` [0]
     `69` 'QFrame'
     `70` 'setObjectName'
     `71` ['sidebar']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__main_window\23e2fa540_icon.ico.c`

### `NeonLabel.__init__`

- implementation: `FUN_23e2fca70`
- source line hint: `?`
- Nuitka codevar: `_DAT_23eeac690`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `165` '__prepare__'
     `166` '__getitem__'
     `167` '%s.__prepare__() must return a mapping, not %s'
     `168` '<metaclass>'
     `169` 'ui.main_window'
     `170` 'Анимированный неоновый заголовок'
     `171` '__qualname__'
     `172` [None]
  => `173` 'NeonLabel.__init__'
     `174` 'float'
     `175` 'glow_intensity'
     `176` 'NeonLabel.glow_intensity'
     `177` 'setter'
     `178` 'NeonLabel.update_glow'
     `179` '__orig_bases__'
     `180` 'MainWindow'
     `181` 'Главное окно приложения'
     `182` 'MainWindow.__init__'
     `183` 'MainWindow.init_ui'
     `184` 'MainWindow.create_menu_button'
     `185` 'MainWindow.switch_tab'
     `186` 'ui\\main_window.py'
     `187` ['self']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__main_window\23e2fca70_NeonLabel.__init.c`

### `NeonLabel.glow_intensity`

- implementation: `FUN_23e2fce50`
- source line hint: `?`
- Nuitka codevar: `_DAT_23eeac688`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `168` '<metaclass>'
     `169` 'ui.main_window'
     `170` 'Анимированный неоновый заголовок'
     `171` '__qualname__'
     `172` [None]
     `173` 'NeonLabel.__init__'
     `174` 'float'
     `175` 'glow_intensity'
  => `176` 'NeonLabel.glow_intensity'
     `177` 'setter'
     `178` 'NeonLabel.update_glow'
     `179` '__orig_bases__'
     `180` 'MainWindow'
     `181` 'Главное окно приложения'
     `182` 'MainWindow.__init__'
     `183` 'MainWindow.init_ui'
     `184` 'MainWindow.create_menu_button'
     `185` 'MainWindow.switch_tab'
     `186` 'ui\\main_window.py'
     `187` ['self']
     `188` '<module ui.main_window>'
     `189` ['__class__']
     `190` ['self', 'license_client', 'current_app', 'app_icon', 'candidates', 'icon_path', 'icon', '__class__']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__main_window\23e2fce50_NeonLabel.glow_intensity.c`

### `NeonLabel.update_glow`

- implementation: `FUN_23e2fd260`
- source line hint: `?`
- Nuitka codevar: `_DAT_23eeac670`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `170` 'Анимированный неоновый заголовок'
     `171` '__qualname__'
     `172` [None]
     `173` 'NeonLabel.__init__'
     `174` 'float'
     `175` 'glow_intensity'
     `176` 'NeonLabel.glow_intensity'
     `177` 'setter'
  => `178` 'NeonLabel.update_glow'
     `179` '__orig_bases__'
     `180` 'MainWindow'
     `181` 'Главное окно приложения'
     `182` 'MainWindow.__init__'
     `183` 'MainWindow.init_ui'
     `184` 'MainWindow.create_menu_button'
     `185` 'MainWindow.switch_tab'
     `186` 'ui\\main_window.py'
     `187` ['self']
     `188` '<module ui.main_window>'
     `189` ['__class__']
     `190` ['self', 'license_client', 'current_app', 'app_icon', 'candidates', 'icon_path', 'icon', '__class__']
     `191` ['self', 'parent', '__class__']
     `192` ['self', 'text', 'btn', 'font']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__main_window\23e2fd260_NeonLabel.update_glow.c`

### `MainWindow.__init__`

- implementation: `FUN_23e2ff8a0`
- source line hint: `?`
- Nuitka codevar: `_DAT_23eeac680`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `174` 'float'
     `175` 'glow_intensity'
     `176` 'NeonLabel.glow_intensity'
     `177` 'setter'
     `178` 'NeonLabel.update_glow'
     `179` '__orig_bases__'
     `180` 'MainWindow'
     `181` 'Главное окно приложения'
  => `182` 'MainWindow.__init__'
     `183` 'MainWindow.init_ui'
     `184` 'MainWindow.create_menu_button'
     `185` 'MainWindow.switch_tab'
     `186` 'ui\\main_window.py'
     `187` ['self']
     `188` '<module ui.main_window>'
     `189` ['__class__']
     `190` ['self', 'license_client', 'current_app', 'app_icon', 'candidates', 'icon_path', 'icon', '__class__']
     `191` ['self', 'parent', '__class__']
     `192` ['self', 'text', 'btn', 'font']
     `193` ['self', 'value']
     `194` ['self', 'central_widget', 'main_layout', 'sidebar', 'sidebar_layout', 'title_label', 'info_label', 'content_area', 'content_layout']
     `195` ['self', 'index', 'i', 'btn']
     `196` ['self', 'blur_radius']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__main_window\23e2ff8a0_MainWindow.__init.c`

### `MainWindow.init_ui`

- implementation: `FUN_23e3069f0`
- source line hint: `?`
- Nuitka codevar: `_DAT_23eeac698`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `175` 'glow_intensity'
     `176` 'NeonLabel.glow_intensity'
     `177` 'setter'
     `178` 'NeonLabel.update_glow'
     `179` '__orig_bases__'
     `180` 'MainWindow'
     `181` 'Главное окно приложения'
     `182` 'MainWindow.__init__'
  => `183` 'MainWindow.init_ui'
     `184` 'MainWindow.create_menu_button'
     `185` 'MainWindow.switch_tab'
     `186` 'ui\\main_window.py'
     `187` ['self']
     `188` '<module ui.main_window>'
     `189` ['__class__']
     `190` ['self', 'license_client', 'current_app', 'app_icon', 'candidates', 'icon_path', 'icon', '__class__']
     `191` ['self', 'parent', '__class__']
     `192` ['self', 'text', 'btn', 'font']
     `193` ['self', 'value']
     `194` ['self', 'central_widget', 'main_layout', 'sidebar', 'sidebar_layout', 'title_label', 'info_label', 'content_area', 'content_layout']
     `195` ['self', 'index', 'i', 'btn']
     `196` ['self', 'blur_radius']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__main_window\23e3069f0_MainWindow.init_ui.c`
