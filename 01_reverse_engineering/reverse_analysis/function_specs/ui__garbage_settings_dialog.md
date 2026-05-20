# Function Specification: `ui.garbage_settings_dialog`

This is a reconstruction dossier from static Nuitka constants and Ghidra decompilation. It is not original Python source text.

## Source Path Hints
- `ui\garbage_settings_dialog.py`

## Docstrings / Long Text
- `126` '\nДиалог настройки мусора - что выбрасывать автоматически\nИспользует изображения из папки resources/fishing/garbage/\n'

## Function Inventory
| Inferred qualname | Impl | Source line | Arg count | Decompiled C |
|---|---:|---:|---:|---|
| `GarbageCard.__init__` | `FUN_23e2a5cb0` | ? | ? | yes |
| `GarbageCard.is_eject` | `FUN_23e2a9df0` | ? | ? | yes |
| `GarbageCard.set_eject` | `FUN_23e2aa200` | ? | ? | yes |
| `GarbageSettingsDialog.__init__` | `FUN_23e2aa670` | ? | ? | yes |
| `GarbageSettingsDialog.init_ui` | `FUN_23e2ab080` | ? | ? | yes |
| `GarbageSettingsDialog.save_and_close` | `FUN_23e2ae3f0` | ? | ? | yes |
| `GarbageSettingsDialog.load_saved_settings` | `FUN_23e2aea00` | ? | ? | yes |
| `GarbageSettingsDialog.load_garbage_list` | `FUN_23e2af050` | ? | ? | yes |
| `GarbageSettingsDialog.select_all` | `FUN_23e2af890` | ? | ? | yes |
| `GarbageSettingsDialog.deselect_all` | `FUN_23e2b00d0` | ? | ? | yes |
| `GarbageSettingsDialog.get_settings` | `FUN_23e30b240` | ? | ? | yes |

## Local Variable Lists
- `169` `__class__`
- `170` `self, garbage_name, garbage_display_name, image_path, parent, layout, image_label, pixmap, scaled_pixmap, name_label, toggle_layout, keep_label, eject_label, __class__`
- `171` `self, parent, __class__`
- `172` `self, card`
- `173` `self, settings, garbage_name, card`
- `174` `self, layout, title, desc, quick_actions, select_all_btn, deselect_all_btn, scroll, scroll_widget, grid_layout, buttons_layout, cancel_btn, save_btn`
- `175` `self`
- `176` `self, grid_layout, garbage_images_dir, garbage_list, row, col, max_cols, garbage_name, garbage_display_name, garbage_filename, image_path, card`
- `177` `self, config, garbage_settings`
- `178` `self, garbage_settings, config`
- `179` `self, eject`
- `180` `self, settings, garbage_name, eject`

## Structured Constants
- `10` [6]
- `12` [8, 8, 8, 8]
- `32` [80]
- `35` [True]
- `55` [600, 400]
- `61` [12, 16, 12, 16]
- `62` [12]
- `81` [0, 0, 0, 0]
- `87` [120]
- `107` [0, 0]
- `119` [False]
- `151` [None]

## Per-Function Context
### `GarbageCard.__init__`

- implementation: `FUN_23e2a5cb0`
- source line hint: `?`
- Nuitka codevar: `_DAT_23eeb0490`
- factory: `FUN_23e93e480`
- nearby constants:
     `144` '__prepare__'
     `145` '__getitem__'
     `146` '%s.__prepare__() must return a mapping, not %s'
     `147` '<metaclass>'
     `148` 'ui.garbage_settings_dialog'
     `149` 'Карточка с мусором'
     `150` '__qualname__'
     `151` [None]
  => `152` 'GarbageCard.__init__'
     `153` 'GarbageCard.is_eject'
     `154` 'GarbageCard.set_eject'
     `155` '__orig_bases__'
     `156` 'GarbageSettingsDialog'
     `157` 'Диалог настройки мусора'
     `158` 'GarbageSettingsDialog.__init__'
     `159` 'GarbageSettingsDialog.init_ui'
     `160` 'GarbageSettingsDialog.save_and_close'
     `161` 'GarbageSettingsDialog.load_saved_settings'
     `162` 'GarbageSettingsDialog.load_garbage_list'
     `163` 'GarbageSettingsDialog.select_all'
     `164` 'GarbageSettingsDialog.deselect_all'
     `165` 'GarbageSettingsDialog.get_settings'
     `166` 'GarbageSettingsDialog.set_settings'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__garbage_settings_dialog\23e2a5cb0_GarbageCard.__init.c`

### `GarbageCard.is_eject`

- implementation: `FUN_23e2a9df0`
- source line hint: `?`
- Nuitka codevar: `DAT_23eeb0468`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `145` '__getitem__'
     `146` '%s.__prepare__() must return a mapping, not %s'
     `147` '<metaclass>'
     `148` 'ui.garbage_settings_dialog'
     `149` 'Карточка с мусором'
     `150` '__qualname__'
     `151` [None]
     `152` 'GarbageCard.__init__'
  => `153` 'GarbageCard.is_eject'
     `154` 'GarbageCard.set_eject'
     `155` '__orig_bases__'
     `156` 'GarbageSettingsDialog'
     `157` 'Диалог настройки мусора'
     `158` 'GarbageSettingsDialog.__init__'
     `159` 'GarbageSettingsDialog.init_ui'
     `160` 'GarbageSettingsDialog.save_and_close'
     `161` 'GarbageSettingsDialog.load_saved_settings'
     `162` 'GarbageSettingsDialog.load_garbage_list'
     `163` 'GarbageSettingsDialog.select_all'
     `164` 'GarbageSettingsDialog.deselect_all'
     `165` 'GarbageSettingsDialog.get_settings'
     `166` 'GarbageSettingsDialog.set_settings'
     `167` 'ui\\garbage_settings_dialog.py'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__garbage_settings_dialog\23e2a9df0_GarbageCard.is_eject.c`

### `GarbageCard.set_eject`

- implementation: `FUN_23e2aa200`
- source line hint: `?`
- Nuitka codevar: `DAT_23eeb0440`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `146` '%s.__prepare__() must return a mapping, not %s'
     `147` '<metaclass>'
     `148` 'ui.garbage_settings_dialog'
     `149` 'Карточка с мусором'
     `150` '__qualname__'
     `151` [None]
     `152` 'GarbageCard.__init__'
     `153` 'GarbageCard.is_eject'
  => `154` 'GarbageCard.set_eject'
     `155` '__orig_bases__'
     `156` 'GarbageSettingsDialog'
     `157` 'Диалог настройки мусора'
     `158` 'GarbageSettingsDialog.__init__'
     `159` 'GarbageSettingsDialog.init_ui'
     `160` 'GarbageSettingsDialog.save_and_close'
     `161` 'GarbageSettingsDialog.load_saved_settings'
     `162` 'GarbageSettingsDialog.load_garbage_list'
     `163` 'GarbageSettingsDialog.select_all'
     `164` 'GarbageSettingsDialog.deselect_all'
     `165` 'GarbageSettingsDialog.get_settings'
     `166` 'GarbageSettingsDialog.set_settings'
     `167` 'ui\\garbage_settings_dialog.py'
     `168` '<module ui.garbage_settings_dialog>'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__garbage_settings_dialog\23e2aa200_GarbageCard.set_eject.c`

### `GarbageSettingsDialog.__init__`

- implementation: `FUN_23e2aa670`
- source line hint: `?`
- Nuitka codevar: `uVar14`
- factory: `FUN_23e93e480`
- nearby constants:
     `150` '__qualname__'
     `151` [None]
     `152` 'GarbageCard.__init__'
     `153` 'GarbageCard.is_eject'
     `154` 'GarbageCard.set_eject'
     `155` '__orig_bases__'
     `156` 'GarbageSettingsDialog'
     `157` 'Диалог настройки мусора'
  => `158` 'GarbageSettingsDialog.__init__'
     `159` 'GarbageSettingsDialog.init_ui'
     `160` 'GarbageSettingsDialog.save_and_close'
     `161` 'GarbageSettingsDialog.load_saved_settings'
     `162` 'GarbageSettingsDialog.load_garbage_list'
     `163` 'GarbageSettingsDialog.select_all'
     `164` 'GarbageSettingsDialog.deselect_all'
     `165` 'GarbageSettingsDialog.get_settings'
     `166` 'GarbageSettingsDialog.set_settings'
     `167` 'ui\\garbage_settings_dialog.py'
     `168` '<module ui.garbage_settings_dialog>'
     `169` ['__class__']
     `170` ['self', 'garbage_name', 'garbage_display_name', 'image_path', 'parent', 'layout', 'image_label', 'pixmap', 'scaled_pixmap', 'name_label', 'toggle_layout', 'keep_label', 'eject_label', '__class__']
     `171` ['self', 'parent', '__class__']
     `172` ['self', 'card']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__garbage_settings_dialog\23e2aa670_GarbageSettingsDialog.__init.c`

### `GarbageSettingsDialog.init_ui`

- implementation: `FUN_23e2ab080`
- source line hint: `?`
- Nuitka codevar: `_DAT_23eeb0470`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `151` [None]
     `152` 'GarbageCard.__init__'
     `153` 'GarbageCard.is_eject'
     `154` 'GarbageCard.set_eject'
     `155` '__orig_bases__'
     `156` 'GarbageSettingsDialog'
     `157` 'Диалог настройки мусора'
     `158` 'GarbageSettingsDialog.__init__'
  => `159` 'GarbageSettingsDialog.init_ui'
     `160` 'GarbageSettingsDialog.save_and_close'
     `161` 'GarbageSettingsDialog.load_saved_settings'
     `162` 'GarbageSettingsDialog.load_garbage_list'
     `163` 'GarbageSettingsDialog.select_all'
     `164` 'GarbageSettingsDialog.deselect_all'
     `165` 'GarbageSettingsDialog.get_settings'
     `166` 'GarbageSettingsDialog.set_settings'
     `167` 'ui\\garbage_settings_dialog.py'
     `168` '<module ui.garbage_settings_dialog>'
     `169` ['__class__']
     `170` ['self', 'garbage_name', 'garbage_display_name', 'image_path', 'parent', 'layout', 'image_label', 'pixmap', 'scaled_pixmap', 'name_label', 'toggle_layout', 'keep_label', 'eject_label', '__class__']
     `171` ['self', 'parent', '__class__']
     `172` ['self', 'card']
     `173` ['self', 'settings', 'garbage_name', 'card']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__garbage_settings_dialog\23e2ab080_GarbageSettingsDialog.init_ui.c`

### `GarbageSettingsDialog.save_and_close`

- implementation: `FUN_23e2ae3f0`
- source line hint: `?`
- Nuitka codevar: `_DAT_23eeb0450`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `152` 'GarbageCard.__init__'
     `153` 'GarbageCard.is_eject'
     `154` 'GarbageCard.set_eject'
     `155` '__orig_bases__'
     `156` 'GarbageSettingsDialog'
     `157` 'Диалог настройки мусора'
     `158` 'GarbageSettingsDialog.__init__'
     `159` 'GarbageSettingsDialog.init_ui'
  => `160` 'GarbageSettingsDialog.save_and_close'
     `161` 'GarbageSettingsDialog.load_saved_settings'
     `162` 'GarbageSettingsDialog.load_garbage_list'
     `163` 'GarbageSettingsDialog.select_all'
     `164` 'GarbageSettingsDialog.deselect_all'
     `165` 'GarbageSettingsDialog.get_settings'
     `166` 'GarbageSettingsDialog.set_settings'
     `167` 'ui\\garbage_settings_dialog.py'
     `168` '<module ui.garbage_settings_dialog>'
     `169` ['__class__']
     `170` ['self', 'garbage_name', 'garbage_display_name', 'image_path', 'parent', 'layout', 'image_label', 'pixmap', 'scaled_pixmap', 'name_label', 'toggle_layout', 'keep_label', 'eject_label', '__class__']
     `171` ['self', 'parent', '__class__']
     `172` ['self', 'card']
     `173` ['self', 'settings', 'garbage_name', 'card']
     `174` ['self', 'layout', 'title', 'desc', 'quick_actions', 'select_all_btn', 'deselect_all_btn', 'scroll', 'scroll_widget', 'grid_layout', 'buttons_layout', 'cancel_btn', 'save_btn']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__garbage_settings_dialog\23e2ae3f0_GarbageSettingsDialog.save_and_close.c`

### `GarbageSettingsDialog.load_saved_settings`

- implementation: `FUN_23e2aea00`
- source line hint: `?`
- Nuitka codevar: `_DAT_23eeb0458`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `153` 'GarbageCard.is_eject'
     `154` 'GarbageCard.set_eject'
     `155` '__orig_bases__'
     `156` 'GarbageSettingsDialog'
     `157` 'Диалог настройки мусора'
     `158` 'GarbageSettingsDialog.__init__'
     `159` 'GarbageSettingsDialog.init_ui'
     `160` 'GarbageSettingsDialog.save_and_close'
  => `161` 'GarbageSettingsDialog.load_saved_settings'
     `162` 'GarbageSettingsDialog.load_garbage_list'
     `163` 'GarbageSettingsDialog.select_all'
     `164` 'GarbageSettingsDialog.deselect_all'
     `165` 'GarbageSettingsDialog.get_settings'
     `166` 'GarbageSettingsDialog.set_settings'
     `167` 'ui\\garbage_settings_dialog.py'
     `168` '<module ui.garbage_settings_dialog>'
     `169` ['__class__']
     `170` ['self', 'garbage_name', 'garbage_display_name', 'image_path', 'parent', 'layout', 'image_label', 'pixmap', 'scaled_pixmap', 'name_label', 'toggle_layout', 'keep_label', 'eject_label', '__class__']
     `171` ['self', 'parent', '__class__']
     `172` ['self', 'card']
     `173` ['self', 'settings', 'garbage_name', 'card']
     `174` ['self', 'layout', 'title', 'desc', 'quick_actions', 'select_all_btn', 'deselect_all_btn', 'scroll', 'scroll_widget', 'grid_layout', 'buttons_layout', 'cancel_btn', 'save_btn']
     `175` ['self']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__garbage_settings_dialog\23e2aea00_GarbageSettingsDialog.load_saved_settings.c`

### `GarbageSettingsDialog.load_garbage_list`

- implementation: `FUN_23e2af050`
- source line hint: `?`
- Nuitka codevar: `_DAT_23eeb0448`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `154` 'GarbageCard.set_eject'
     `155` '__orig_bases__'
     `156` 'GarbageSettingsDialog'
     `157` 'Диалог настройки мусора'
     `158` 'GarbageSettingsDialog.__init__'
     `159` 'GarbageSettingsDialog.init_ui'
     `160` 'GarbageSettingsDialog.save_and_close'
     `161` 'GarbageSettingsDialog.load_saved_settings'
  => `162` 'GarbageSettingsDialog.load_garbage_list'
     `163` 'GarbageSettingsDialog.select_all'
     `164` 'GarbageSettingsDialog.deselect_all'
     `165` 'GarbageSettingsDialog.get_settings'
     `166` 'GarbageSettingsDialog.set_settings'
     `167` 'ui\\garbage_settings_dialog.py'
     `168` '<module ui.garbage_settings_dialog>'
     `169` ['__class__']
     `170` ['self', 'garbage_name', 'garbage_display_name', 'image_path', 'parent', 'layout', 'image_label', 'pixmap', 'scaled_pixmap', 'name_label', 'toggle_layout', 'keep_label', 'eject_label', '__class__']
     `171` ['self', 'parent', '__class__']
     `172` ['self', 'card']
     `173` ['self', 'settings', 'garbage_name', 'card']
     `174` ['self', 'layout', 'title', 'desc', 'quick_actions', 'select_all_btn', 'deselect_all_btn', 'scroll', 'scroll_widget', 'grid_layout', 'buttons_layout', 'cancel_btn', 'save_btn']
     `175` ['self']
     `176` ['self', 'grid_layout', 'garbage_images_dir', 'garbage_list', 'row', 'col', 'max_cols', 'garbage_name', 'garbage_display_name', 'garbage_filename', 'image_path', 'card']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__garbage_settings_dialog\23e2af050_GarbageSettingsDialog.load_garbage_list.c`

### `GarbageSettingsDialog.select_all`

- implementation: `FUN_23e2af890`
- source line hint: `?`
- Nuitka codevar: `_DAT_23eeb0480`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `155` '__orig_bases__'
     `156` 'GarbageSettingsDialog'
     `157` 'Диалог настройки мусора'
     `158` 'GarbageSettingsDialog.__init__'
     `159` 'GarbageSettingsDialog.init_ui'
     `160` 'GarbageSettingsDialog.save_and_close'
     `161` 'GarbageSettingsDialog.load_saved_settings'
     `162` 'GarbageSettingsDialog.load_garbage_list'
  => `163` 'GarbageSettingsDialog.select_all'
     `164` 'GarbageSettingsDialog.deselect_all'
     `165` 'GarbageSettingsDialog.get_settings'
     `166` 'GarbageSettingsDialog.set_settings'
     `167` 'ui\\garbage_settings_dialog.py'
     `168` '<module ui.garbage_settings_dialog>'
     `169` ['__class__']
     `170` ['self', 'garbage_name', 'garbage_display_name', 'image_path', 'parent', 'layout', 'image_label', 'pixmap', 'scaled_pixmap', 'name_label', 'toggle_layout', 'keep_label', 'eject_label', '__class__']
     `171` ['self', 'parent', '__class__']
     `172` ['self', 'card']
     `173` ['self', 'settings', 'garbage_name', 'card']
     `174` ['self', 'layout', 'title', 'desc', 'quick_actions', 'select_all_btn', 'deselect_all_btn', 'scroll', 'scroll_widget', 'grid_layout', 'buttons_layout', 'cancel_btn', 'save_btn']
     `175` ['self']
     `176` ['self', 'grid_layout', 'garbage_images_dir', 'garbage_list', 'row', 'col', 'max_cols', 'garbage_name', 'garbage_display_name', 'garbage_filename', 'image_path', 'card']
     `177` ['self', 'config', 'garbage_settings']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__garbage_settings_dialog\23e2af890_GarbageSettingsDialog.select_all.c`

### `GarbageSettingsDialog.deselect_all`

- implementation: `FUN_23e2b00d0`
- source line hint: `?`
- Nuitka codevar: `_DAT_23eeb0478`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `156` 'GarbageSettingsDialog'
     `157` 'Диалог настройки мусора'
     `158` 'GarbageSettingsDialog.__init__'
     `159` 'GarbageSettingsDialog.init_ui'
     `160` 'GarbageSettingsDialog.save_and_close'
     `161` 'GarbageSettingsDialog.load_saved_settings'
     `162` 'GarbageSettingsDialog.load_garbage_list'
     `163` 'GarbageSettingsDialog.select_all'
  => `164` 'GarbageSettingsDialog.deselect_all'
     `165` 'GarbageSettingsDialog.get_settings'
     `166` 'GarbageSettingsDialog.set_settings'
     `167` 'ui\\garbage_settings_dialog.py'
     `168` '<module ui.garbage_settings_dialog>'
     `169` ['__class__']
     `170` ['self', 'garbage_name', 'garbage_display_name', 'image_path', 'parent', 'layout', 'image_label', 'pixmap', 'scaled_pixmap', 'name_label', 'toggle_layout', 'keep_label', 'eject_label', '__class__']
     `171` ['self', 'parent', '__class__']
     `172` ['self', 'card']
     `173` ['self', 'settings', 'garbage_name', 'card']
     `174` ['self', 'layout', 'title', 'desc', 'quick_actions', 'select_all_btn', 'deselect_all_btn', 'scroll', 'scroll_widget', 'grid_layout', 'buttons_layout', 'cancel_btn', 'save_btn']
     `175` ['self']
     `176` ['self', 'grid_layout', 'garbage_images_dir', 'garbage_list', 'row', 'col', 'max_cols', 'garbage_name', 'garbage_display_name', 'garbage_filename', 'image_path', 'card']
     `177` ['self', 'config', 'garbage_settings']
     `178` ['self', 'garbage_settings', 'config']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__garbage_settings_dialog\23e2b00d0_GarbageSettingsDialog.deselect_all.c`

### `GarbageSettingsDialog.get_settings`

- implementation: `FUN_23e30b240`
- source line hint: `?`
- Nuitka codevar: `_DAT_23eeb0460`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `157` 'Диалог настройки мусора'
     `158` 'GarbageSettingsDialog.__init__'
     `159` 'GarbageSettingsDialog.init_ui'
     `160` 'GarbageSettingsDialog.save_and_close'
     `161` 'GarbageSettingsDialog.load_saved_settings'
     `162` 'GarbageSettingsDialog.load_garbage_list'
     `163` 'GarbageSettingsDialog.select_all'
     `164` 'GarbageSettingsDialog.deselect_all'
  => `165` 'GarbageSettingsDialog.get_settings'
     `166` 'GarbageSettingsDialog.set_settings'
     `167` 'ui\\garbage_settings_dialog.py'
     `168` '<module ui.garbage_settings_dialog>'
     `169` ['__class__']
     `170` ['self', 'garbage_name', 'garbage_display_name', 'image_path', 'parent', 'layout', 'image_label', 'pixmap', 'scaled_pixmap', 'name_label', 'toggle_layout', 'keep_label', 'eject_label', '__class__']
     `171` ['self', 'parent', '__class__']
     `172` ['self', 'card']
     `173` ['self', 'settings', 'garbage_name', 'card']
     `174` ['self', 'layout', 'title', 'desc', 'quick_actions', 'select_all_btn', 'deselect_all_btn', 'scroll', 'scroll_widget', 'grid_layout', 'buttons_layout', 'cancel_btn', 'save_btn']
     `175` ['self']
     `176` ['self', 'grid_layout', 'garbage_images_dir', 'garbage_list', 'row', 'col', 'max_cols', 'garbage_name', 'garbage_display_name', 'garbage_filename', 'image_path', 'card']
     `177` ['self', 'config', 'garbage_settings']
     `178` ['self', 'garbage_settings', 'config']
     `179` ['self', 'eject']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__garbage_settings_dialog\23e30b240_GarbageSettingsDialog.get_settings.c`
