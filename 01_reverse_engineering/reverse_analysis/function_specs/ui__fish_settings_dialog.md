# Function Specification: `ui.fish_settings_dialog`

This is a reconstruction dossier from static Nuitka constants and Ghidra decompilation. It is not original Python source text.

## Source Path Hints
- `ui\fish_settings_dialog.py`

## Docstrings / Long Text
- `124` '\nДиалог настроек рыбы - какую оставлять, какую отпускать\nИспользует изображения из папки resources/fishing/fish2k/\n'

## Function Inventory
| Inferred qualname | Impl | Source line | Arg count | Decompiled C |
|---|---:|---:|---:|---|
| `FishCard.__init__` | `FUN_23e275120` | ? | ? | yes |
| `FishCard.is_keep` | `FUN_23e275530` | ? | ? | yes |
| `FishCard.set_keep` | `FUN_23e2759a0` | ? | ? | yes |
| `FishSettingsDialog.__init__` | `FUN_23e2763b0` | ? | ? | yes |
| `FishSettingsDialog.init_ui` | `FUN_23e279720` | ? | ? | yes |
| `FishSettingsDialog.save_and_close` | `FUN_23e279d30` | ? | ? | yes |
| `FishSettingsDialog.load_saved_settings` | `FUN_23e27a380` | ? | ? | yes |
| `FishSettingsDialog.load_fish_list` | `FUN_23e27abc0` | ? | ? | yes |
| `FishSettingsDialog.select_all` | `FUN_23e27b400` | ? | ? | yes |
| `FishSettingsDialog.deselect_all` | `FUN_23e308230` | ? | ? | yes |
| `FishSettingsDialog.get_settings` | `LAB_23e270fe0` | ? | ? | yes |

## Local Variable Lists
- `167` `__class__`
- `168` `self, fish_name, fish_display_name, image_path, parent, layout, image_label, pixmap, scaled_pixmap, name_label, toggle_layout, release_label, keep_label, __class__`
- `169` `self, parent, __class__`
- `170` `self, card`
- `171` `self, settings, fish_name, card`
- `172` `self, layout, title, desc, quick_actions, select_all_btn, deselect_all_btn, scroll, scroll_widget, grid_layout, buttons_layout, cancel_btn, save_btn`
- `173` `self`
- `174` `self, grid_layout, fish_images_dir, fish_list, row, col, max_cols, fish_name, fish_display_name, fish_filename, image_path, card`
- `175` `self, config, fish_settings`
- `176` `self, fish_settings, config`
- `177` `self, keep`
- `178` `self, settings, fish_name, keep`

## Structured Constants
- `10` [6]
- `12` [8, 8, 8, 8]
- `32` [80]
- `35` [True]
- `55` [800, 600]
- `61` [12, 16, 12, 16]
- `62` [12]
- `81` [0, 0, 0, 0]
- `87` [120]
- `104` [['rudd_krasnoperka', 'Краснопёрка', 'rudd_krasnoperka.png'], ['bream_leshch', 'Лещ', 'bream_leshch.png'], ['roach_plotva', 'Плотва', 'roach_plotva.png'], ['roach_vobla', 'Вобла', 'roach_vobla.png'], ['korichnevy_som', 'Коричневый сом', 'korichnevy_som.png'], ['serebryany_karas', 'Серебряный карась', 'serebryany_karas.png'], ['rechnoy_okun', 'Речной окунь', 'rechnoy_okun.png'], ['obyknovennaya_shchuka', 'Обыкновенная щука', 'obyknovennaya_shchuka.png'], ['raduzhnaya_forel', 'Радужная форель', 'raduzhnaya_forel.p...
- `105` [0, 0]
- `117` [False]
- `149` [None]

## Per-Function Context
### `FishCard.__init__`

- implementation: `FUN_23e275120`
- source line hint: `?`
- Nuitka codevar: `_DAT_23eeb07b0`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `142` '__prepare__'
     `143` '__getitem__'
     `144` '%s.__prepare__() must return a mapping, not %s'
     `145` '<metaclass>'
     `146` 'ui.fish_settings_dialog'
     `147` 'Карточка с рыбой'
     `148` '__qualname__'
     `149` [None]
  => `150` 'FishCard.__init__'
     `151` 'FishCard.is_keep'
     `152` 'FishCard.set_keep'
     `153` '__orig_bases__'
     `154` 'FishSettingsDialog'
     `155` 'Диалог настройки рыбы'
     `156` 'FishSettingsDialog.__init__'
     `157` 'FishSettingsDialog.init_ui'
     `158` 'FishSettingsDialog.save_and_close'
     `159` 'FishSettingsDialog.load_saved_settings'
     `160` 'FishSettingsDialog.load_fish_list'
     `161` 'FishSettingsDialog.select_all'
     `162` 'FishSettingsDialog.deselect_all'
     `163` 'FishSettingsDialog.get_settings'
     `164` 'FishSettingsDialog.set_settings'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__fish_settings_dialog\23e275120_FishCard.__init.c`

### `FishCard.is_keep`

- implementation: `FUN_23e275530`
- source line hint: `?`
- Nuitka codevar: `_DAT_23eeb0788`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `143` '__getitem__'
     `144` '%s.__prepare__() must return a mapping, not %s'
     `145` '<metaclass>'
     `146` 'ui.fish_settings_dialog'
     `147` 'Карточка с рыбой'
     `148` '__qualname__'
     `149` [None]
     `150` 'FishCard.__init__'
  => `151` 'FishCard.is_keep'
     `152` 'FishCard.set_keep'
     `153` '__orig_bases__'
     `154` 'FishSettingsDialog'
     `155` 'Диалог настройки рыбы'
     `156` 'FishSettingsDialog.__init__'
     `157` 'FishSettingsDialog.init_ui'
     `158` 'FishSettingsDialog.save_and_close'
     `159` 'FishSettingsDialog.load_saved_settings'
     `160` 'FishSettingsDialog.load_fish_list'
     `161` 'FishSettingsDialog.select_all'
     `162` 'FishSettingsDialog.deselect_all'
     `163` 'FishSettingsDialog.get_settings'
     `164` 'FishSettingsDialog.set_settings'
     `165` 'ui\\fish_settings_dialog.py'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__fish_settings_dialog\23e275530_FishCard.is_keep.c`

### `FishCard.set_keep`

- implementation: `FUN_23e2759a0`
- source line hint: `?`
- Nuitka codevar: `uVar14`
- factory: `FUN_23e93e480`
- nearby constants:
     `144` '%s.__prepare__() must return a mapping, not %s'
     `145` '<metaclass>'
     `146` 'ui.fish_settings_dialog'
     `147` 'Карточка с рыбой'
     `148` '__qualname__'
     `149` [None]
     `150` 'FishCard.__init__'
     `151` 'FishCard.is_keep'
  => `152` 'FishCard.set_keep'
     `153` '__orig_bases__'
     `154` 'FishSettingsDialog'
     `155` 'Диалог настройки рыбы'
     `156` 'FishSettingsDialog.__init__'
     `157` 'FishSettingsDialog.init_ui'
     `158` 'FishSettingsDialog.save_and_close'
     `159` 'FishSettingsDialog.load_saved_settings'
     `160` 'FishSettingsDialog.load_fish_list'
     `161` 'FishSettingsDialog.select_all'
     `162` 'FishSettingsDialog.deselect_all'
     `163` 'FishSettingsDialog.get_settings'
     `164` 'FishSettingsDialog.set_settings'
     `165` 'ui\\fish_settings_dialog.py'
     `166` '<module ui.fish_settings_dialog>'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__fish_settings_dialog\23e2759a0_FishCard.set_keep.c`

### `FishSettingsDialog.__init__`

- implementation: `FUN_23e2763b0`
- source line hint: `?`
- Nuitka codevar: `_DAT_23eeb07b8`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `148` '__qualname__'
     `149` [None]
     `150` 'FishCard.__init__'
     `151` 'FishCard.is_keep'
     `152` 'FishCard.set_keep'
     `153` '__orig_bases__'
     `154` 'FishSettingsDialog'
     `155` 'Диалог настройки рыбы'
  => `156` 'FishSettingsDialog.__init__'
     `157` 'FishSettingsDialog.init_ui'
     `158` 'FishSettingsDialog.save_and_close'
     `159` 'FishSettingsDialog.load_saved_settings'
     `160` 'FishSettingsDialog.load_fish_list'
     `161` 'FishSettingsDialog.select_all'
     `162` 'FishSettingsDialog.deselect_all'
     `163` 'FishSettingsDialog.get_settings'
     `164` 'FishSettingsDialog.set_settings'
     `165` 'ui\\fish_settings_dialog.py'
     `166` '<module ui.fish_settings_dialog>'
     `167` ['__class__']
     `168` ['self', 'fish_name', 'fish_display_name', 'image_path', 'parent', 'layout', 'image_label', 'pixmap', 'scaled_pixmap', 'name_label', 'toggle_layout', 'release_label', 'keep_label', '__class__']
     `169` ['self', 'parent', '__class__']
     `170` ['self', 'card']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__fish_settings_dialog\23e2763b0_FishSettingsDialog.__init.c`

### `FishSettingsDialog.init_ui`

- implementation: `FUN_23e279720`
- source line hint: `?`
- Nuitka codevar: `DAT_23eeb0798`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `149` [None]
     `150` 'FishCard.__init__'
     `151` 'FishCard.is_keep'
     `152` 'FishCard.set_keep'
     `153` '__orig_bases__'
     `154` 'FishSettingsDialog'
     `155` 'Диалог настройки рыбы'
     `156` 'FishSettingsDialog.__init__'
  => `157` 'FishSettingsDialog.init_ui'
     `158` 'FishSettingsDialog.save_and_close'
     `159` 'FishSettingsDialog.load_saved_settings'
     `160` 'FishSettingsDialog.load_fish_list'
     `161` 'FishSettingsDialog.select_all'
     `162` 'FishSettingsDialog.deselect_all'
     `163` 'FishSettingsDialog.get_settings'
     `164` 'FishSettingsDialog.set_settings'
     `165` 'ui\\fish_settings_dialog.py'
     `166` '<module ui.fish_settings_dialog>'
     `167` ['__class__']
     `168` ['self', 'fish_name', 'fish_display_name', 'image_path', 'parent', 'layout', 'image_label', 'pixmap', 'scaled_pixmap', 'name_label', 'toggle_layout', 'release_label', 'keep_label', '__class__']
     `169` ['self', 'parent', '__class__']
     `170` ['self', 'card']
     `171` ['self', 'settings', 'fish_name', 'card']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__fish_settings_dialog\23e279720_FishSettingsDialog.init_ui.c`

### `FishSettingsDialog.save_and_close`

- implementation: `FUN_23e279d30`
- source line hint: `?`
- Nuitka codevar: `DAT_23eeb07a0`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `150` 'FishCard.__init__'
     `151` 'FishCard.is_keep'
     `152` 'FishCard.set_keep'
     `153` '__orig_bases__'
     `154` 'FishSettingsDialog'
     `155` 'Диалог настройки рыбы'
     `156` 'FishSettingsDialog.__init__'
     `157` 'FishSettingsDialog.init_ui'
  => `158` 'FishSettingsDialog.save_and_close'
     `159` 'FishSettingsDialog.load_saved_settings'
     `160` 'FishSettingsDialog.load_fish_list'
     `161` 'FishSettingsDialog.select_all'
     `162` 'FishSettingsDialog.deselect_all'
     `163` 'FishSettingsDialog.get_settings'
     `164` 'FishSettingsDialog.set_settings'
     `165` 'ui\\fish_settings_dialog.py'
     `166` '<module ui.fish_settings_dialog>'
     `167` ['__class__']
     `168` ['self', 'fish_name', 'fish_display_name', 'image_path', 'parent', 'layout', 'image_label', 'pixmap', 'scaled_pixmap', 'name_label', 'toggle_layout', 'release_label', 'keep_label', '__class__']
     `169` ['self', 'parent', '__class__']
     `170` ['self', 'card']
     `171` ['self', 'settings', 'fish_name', 'card']
     `172` ['self', 'layout', 'title', 'desc', 'quick_actions', 'select_all_btn', 'deselect_all_btn', 'scroll', 'scroll_widget', 'grid_layout', 'buttons_layout', 'cancel_btn', 'save_btn']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__fish_settings_dialog\23e279d30_FishSettingsDialog.save_and_close.c`

### `FishSettingsDialog.load_saved_settings`

- implementation: `FUN_23e27a380`
- source line hint: `?`
- Nuitka codevar: `DAT_23eeb0790`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `151` 'FishCard.is_keep'
     `152` 'FishCard.set_keep'
     `153` '__orig_bases__'
     `154` 'FishSettingsDialog'
     `155` 'Диалог настройки рыбы'
     `156` 'FishSettingsDialog.__init__'
     `157` 'FishSettingsDialog.init_ui'
     `158` 'FishSettingsDialog.save_and_close'
  => `159` 'FishSettingsDialog.load_saved_settings'
     `160` 'FishSettingsDialog.load_fish_list'
     `161` 'FishSettingsDialog.select_all'
     `162` 'FishSettingsDialog.deselect_all'
     `163` 'FishSettingsDialog.get_settings'
     `164` 'FishSettingsDialog.set_settings'
     `165` 'ui\\fish_settings_dialog.py'
     `166` '<module ui.fish_settings_dialog>'
     `167` ['__class__']
     `168` ['self', 'fish_name', 'fish_display_name', 'image_path', 'parent', 'layout', 'image_label', 'pixmap', 'scaled_pixmap', 'name_label', 'toggle_layout', 'release_label', 'keep_label', '__class__']
     `169` ['self', 'parent', '__class__']
     `170` ['self', 'card']
     `171` ['self', 'settings', 'fish_name', 'card']
     `172` ['self', 'layout', 'title', 'desc', 'quick_actions', 'select_all_btn', 'deselect_all_btn', 'scroll', 'scroll_widget', 'grid_layout', 'buttons_layout', 'cancel_btn', 'save_btn']
     `173` ['self']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__fish_settings_dialog\23e27a380_FishSettingsDialog.load_saved_settings.c`

### `FishSettingsDialog.load_fish_list`

- implementation: `FUN_23e27abc0`
- source line hint: `?`
- Nuitka codevar: `DAT_23eeb07c8`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `152` 'FishCard.set_keep'
     `153` '__orig_bases__'
     `154` 'FishSettingsDialog'
     `155` 'Диалог настройки рыбы'
     `156` 'FishSettingsDialog.__init__'
     `157` 'FishSettingsDialog.init_ui'
     `158` 'FishSettingsDialog.save_and_close'
     `159` 'FishSettingsDialog.load_saved_settings'
  => `160` 'FishSettingsDialog.load_fish_list'
     `161` 'FishSettingsDialog.select_all'
     `162` 'FishSettingsDialog.deselect_all'
     `163` 'FishSettingsDialog.get_settings'
     `164` 'FishSettingsDialog.set_settings'
     `165` 'ui\\fish_settings_dialog.py'
     `166` '<module ui.fish_settings_dialog>'
     `167` ['__class__']
     `168` ['self', 'fish_name', 'fish_display_name', 'image_path', 'parent', 'layout', 'image_label', 'pixmap', 'scaled_pixmap', 'name_label', 'toggle_layout', 'release_label', 'keep_label', '__class__']
     `169` ['self', 'parent', '__class__']
     `170` ['self', 'card']
     `171` ['self', 'settings', 'fish_name', 'card']
     `172` ['self', 'layout', 'title', 'desc', 'quick_actions', 'select_all_btn', 'deselect_all_btn', 'scroll', 'scroll_widget', 'grid_layout', 'buttons_layout', 'cancel_btn', 'save_btn']
     `173` ['self']
     `174` ['self', 'grid_layout', 'fish_images_dir', 'fish_list', 'row', 'col', 'max_cols', 'fish_name', 'fish_display_name', 'fish_filename', 'image_path', 'card']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__fish_settings_dialog\23e27abc0_FishSettingsDialog.load_fish_list.c`

### `FishSettingsDialog.select_all`

- implementation: `FUN_23e27b400`
- source line hint: `?`
- Nuitka codevar: `_DAT_23eeb07c0`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `153` '__orig_bases__'
     `154` 'FishSettingsDialog'
     `155` 'Диалог настройки рыбы'
     `156` 'FishSettingsDialog.__init__'
     `157` 'FishSettingsDialog.init_ui'
     `158` 'FishSettingsDialog.save_and_close'
     `159` 'FishSettingsDialog.load_saved_settings'
     `160` 'FishSettingsDialog.load_fish_list'
  => `161` 'FishSettingsDialog.select_all'
     `162` 'FishSettingsDialog.deselect_all'
     `163` 'FishSettingsDialog.get_settings'
     `164` 'FishSettingsDialog.set_settings'
     `165` 'ui\\fish_settings_dialog.py'
     `166` '<module ui.fish_settings_dialog>'
     `167` ['__class__']
     `168` ['self', 'fish_name', 'fish_display_name', 'image_path', 'parent', 'layout', 'image_label', 'pixmap', 'scaled_pixmap', 'name_label', 'toggle_layout', 'release_label', 'keep_label', '__class__']
     `169` ['self', 'parent', '__class__']
     `170` ['self', 'card']
     `171` ['self', 'settings', 'fish_name', 'card']
     `172` ['self', 'layout', 'title', 'desc', 'quick_actions', 'select_all_btn', 'deselect_all_btn', 'scroll', 'scroll_widget', 'grid_layout', 'buttons_layout', 'cancel_btn', 'save_btn']
     `173` ['self']
     `174` ['self', 'grid_layout', 'fish_images_dir', 'fish_list', 'row', 'col', 'max_cols', 'fish_name', 'fish_display_name', 'fish_filename', 'image_path', 'card']
     `175` ['self', 'config', 'fish_settings']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__fish_settings_dialog\23e27b400_FishSettingsDialog.select_all.c`

### `FishSettingsDialog.deselect_all`

- implementation: `FUN_23e308230`
- source line hint: `?`
- Nuitka codevar: `DAT_23eeb07a8`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `154` 'FishSettingsDialog'
     `155` 'Диалог настройки рыбы'
     `156` 'FishSettingsDialog.__init__'
     `157` 'FishSettingsDialog.init_ui'
     `158` 'FishSettingsDialog.save_and_close'
     `159` 'FishSettingsDialog.load_saved_settings'
     `160` 'FishSettingsDialog.load_fish_list'
     `161` 'FishSettingsDialog.select_all'
  => `162` 'FishSettingsDialog.deselect_all'
     `163` 'FishSettingsDialog.get_settings'
     `164` 'FishSettingsDialog.set_settings'
     `165` 'ui\\fish_settings_dialog.py'
     `166` '<module ui.fish_settings_dialog>'
     `167` ['__class__']
     `168` ['self', 'fish_name', 'fish_display_name', 'image_path', 'parent', 'layout', 'image_label', 'pixmap', 'scaled_pixmap', 'name_label', 'toggle_layout', 'release_label', 'keep_label', '__class__']
     `169` ['self', 'parent', '__class__']
     `170` ['self', 'card']
     `171` ['self', 'settings', 'fish_name', 'card']
     `172` ['self', 'layout', 'title', 'desc', 'quick_actions', 'select_all_btn', 'deselect_all_btn', 'scroll', 'scroll_widget', 'grid_layout', 'buttons_layout', 'cancel_btn', 'save_btn']
     `173` ['self']
     `174` ['self', 'grid_layout', 'fish_images_dir', 'fish_list', 'row', 'col', 'max_cols', 'fish_name', 'fish_display_name', 'fish_filename', 'image_path', 'card']
     `175` ['self', 'config', 'fish_settings']
     `176` ['self', 'fish_settings', 'config']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__fish_settings_dialog\23e308230_FishSettingsDialog.deselect_all.c`

### `FishSettingsDialog.get_settings`

- implementation: `LAB_23e270fe0`
- source line hint: `?`
- Nuitka codevar: `DAT_23eeb07d8`
- factory: `FUN_23e93e480`
- nearby constants:
     `155` 'Диалог настройки рыбы'
     `156` 'FishSettingsDialog.__init__'
     `157` 'FishSettingsDialog.init_ui'
     `158` 'FishSettingsDialog.save_and_close'
     `159` 'FishSettingsDialog.load_saved_settings'
     `160` 'FishSettingsDialog.load_fish_list'
     `161` 'FishSettingsDialog.select_all'
     `162` 'FishSettingsDialog.deselect_all'
  => `163` 'FishSettingsDialog.get_settings'
     `164` 'FishSettingsDialog.set_settings'
     `165` 'ui\\fish_settings_dialog.py'
     `166` '<module ui.fish_settings_dialog>'
     `167` ['__class__']
     `168` ['self', 'fish_name', 'fish_display_name', 'image_path', 'parent', 'layout', 'image_label', 'pixmap', 'scaled_pixmap', 'name_label', 'toggle_layout', 'release_label', 'keep_label', '__class__']
     `169` ['self', 'parent', '__class__']
     `170` ['self', 'card']
     `171` ['self', 'settings', 'fish_name', 'card']
     `172` ['self', 'layout', 'title', 'desc', 'quick_actions', 'select_all_btn', 'deselect_all_btn', 'scroll', 'scroll_widget', 'grid_layout', 'buttons_layout', 'cancel_btn', 'save_btn']
     `173` ['self']
     `174` ['self', 'grid_layout', 'fish_images_dir', 'fish_list', 'row', 'col', 'max_cols', 'fish_name', 'fish_display_name', 'fish_filename', 'image_path', 'card']
     `175` ['self', 'config', 'fish_settings']
     `176` ['self', 'fish_settings', 'config']
     `177` ['self', 'keep']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__fish_settings_dialog\23e270fe0_FishSettingsDialog.get_settings.c`
