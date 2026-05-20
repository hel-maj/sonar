# Function Specification: `ui.ios_toggle`

This is a reconstruction dossier from static Nuitka constants and Ghidra decompilation. It is not original Python source text.

## Source Path Hints
- `ui\ios_toggle.py`

## Docstrings / Long Text
- `58` '\niOS-стиль переключатель (Toggle Switch) для PyQt6\n'

## Function Inventory
| Inferred qualname | Impl | Source line | Arg count | Decompiled C |
|---|---:|---:|---:|---|
| `IOSToggle.__init__` | `FUN_23e2f3b90` | 46 | 2 | yes |
| `IOSToggle.on_state_changed` | `FUN_23e2f4330` | 56 | 1 | yes |
| `IOSToggle.circle_position` | `FUN_23e2f4710` | 60 | 2 | yes |
| `IOSToggle.hitButton` | `FUN_23e2f4bd0` | 64 | 2 | yes |
| `IOSToggle.paintEvent` | `FUN_23e2f5010` | 68 | 2 | yes |
| `IOSToggle.sizeHint` | `FUN_23e2f69b0` | 89 | 1 | yes |
| `IOSToggle.minimumSizeHint` | `FUN_23e2f6e70` | 92 | 1 | yes |
| `?` | `LAB_23e2f26d0` | ? | ? | yes |

## Local Variable Lists
- `101` `__class__`
- `102` `self, parent, small, tiny, __class__`
- `103` `self`
- `104` `self, pos`
- `105` `self, value`
- `106` `self, event, painter, circle_y`

## Structured Constants
- `22` {'__bytes__': '636972636c655f706f736974696f6e', 'size': 15}
- `29` [200]
- `49` [57, 57, 61]
- `55` [255, 255, 255]
- `80` [None, False, False]

## Per-Function Context
### `IOSToggle.__init__`

- implementation: `FUN_23e2f3b90`
- source line hint: `46`
- Nuitka codevar: `_DAT_23eeb0050`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `73` 'IOSToggle'
     `74` '__getitem__'
     `75` '%s.__prepare__() must return a mapping, not %s'
     `76` '<metaclass>'
     `77` 'ui.ios_toggle'
     `78` 'iOS-стиль переключатель с анимацией'
     `79` '__qualname__'
     `80` [None, False, False]
  => `81` 'IOSToggle.__init__'
     `82` 'IOSToggle.on_state_changed'
     `83` 'float'
     `84` 'circle_position'
     `85` 'IOSToggle.circle_position'
     `86` 'setter'
     `87` 'pos'
     `88` 'return'
     `89` 'bool'
     `90` 'hitButton'
     `91` 'IOSToggle.hitButton'
     `92` 'paintEvent'
     `93` 'IOSToggle.paintEvent'
     `94` 'sizeHint'
     `95` 'IOSToggle.sizeHint'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__ios_toggle\23e2f3b90_IOSToggle.__init.c`

### `IOSToggle.on_state_changed`

- implementation: `FUN_23e2f4330`
- source line hint: `56`
- Nuitka codevar: `_DAT_23eeb0040`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `74` '__getitem__'
     `75` '%s.__prepare__() must return a mapping, not %s'
     `76` '<metaclass>'
     `77` 'ui.ios_toggle'
     `78` 'iOS-стиль переключатель с анимацией'
     `79` '__qualname__'
     `80` [None, False, False]
     `81` 'IOSToggle.__init__'
  => `82` 'IOSToggle.on_state_changed'
     `83` 'float'
     `84` 'circle_position'
     `85` 'IOSToggle.circle_position'
     `86` 'setter'
     `87` 'pos'
     `88` 'return'
     `89` 'bool'
     `90` 'hitButton'
     `91` 'IOSToggle.hitButton'
     `92` 'paintEvent'
     `93` 'IOSToggle.paintEvent'
     `94` 'sizeHint'
     `95` 'IOSToggle.sizeHint'
     `96` 'minimumSizeHint'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__ios_toggle\23e2f4330_IOSToggle.on_state_changed.c`

### `IOSToggle.circle_position`

- implementation: `FUN_23e2f4710`
- source line hint: `60`
- Nuitka codevar: `_DAT_23eeb0030`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `77` 'ui.ios_toggle'
     `78` 'iOS-стиль переключатель с анимацией'
     `79` '__qualname__'
     `80` [None, False, False]
     `81` 'IOSToggle.__init__'
     `82` 'IOSToggle.on_state_changed'
     `83` 'float'
     `84` 'circle_position'
  => `85` 'IOSToggle.circle_position'
     `86` 'setter'
     `87` 'pos'
     `88` 'return'
     `89` 'bool'
     `90` 'hitButton'
     `91` 'IOSToggle.hitButton'
     `92` 'paintEvent'
     `93` 'IOSToggle.paintEvent'
     `94` 'sizeHint'
     `95` 'IOSToggle.sizeHint'
     `96` 'minimumSizeHint'
     `97` 'IOSToggle.minimumSizeHint'
     `98` '__orig_bases__'
     `99` 'ui\\ios_toggle.py'
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__ios_toggle\23e2f4710_IOSToggle.circle_position.c`

### `IOSToggle.hitButton`

- implementation: `FUN_23e2f4bd0`
- source line hint: `64`
- Nuitka codevar: `_DAT_23eeb0020`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `83` 'float'
     `84` 'circle_position'
     `85` 'IOSToggle.circle_position'
     `86` 'setter'
     `87` 'pos'
     `88` 'return'
     `89` 'bool'
     `90` 'hitButton'
  => `91` 'IOSToggle.hitButton'
     `92` 'paintEvent'
     `93` 'IOSToggle.paintEvent'
     `94` 'sizeHint'
     `95` 'IOSToggle.sizeHint'
     `96` 'minimumSizeHint'
     `97` 'IOSToggle.minimumSizeHint'
     `98` '__orig_bases__'
     `99` 'ui\\ios_toggle.py'
     `100` '<module ui.ios_toggle>'
     `101` ['__class__']
     `102` ['self', 'parent', 'small', 'tiny', '__class__']
     `103` ['self']
     `104` ['self', 'pos']
     `105` ['self', 'value']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__ios_toggle\23e2f4bd0_IOSToggle.hitButton.c`

### `IOSToggle.paintEvent`

- implementation: `FUN_23e2f5010`
- source line hint: `68`
- Nuitka codevar: `_DAT_23eeb0010`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `85` 'IOSToggle.circle_position'
     `86` 'setter'
     `87` 'pos'
     `88` 'return'
     `89` 'bool'
     `90` 'hitButton'
     `91` 'IOSToggle.hitButton'
     `92` 'paintEvent'
  => `93` 'IOSToggle.paintEvent'
     `94` 'sizeHint'
     `95` 'IOSToggle.sizeHint'
     `96` 'minimumSizeHint'
     `97` 'IOSToggle.minimumSizeHint'
     `98` '__orig_bases__'
     `99` 'ui\\ios_toggle.py'
     `100` '<module ui.ios_toggle>'
     `101` ['__class__']
     `102` ['self', 'parent', 'small', 'tiny', '__class__']
     `103` ['self']
     `104` ['self', 'pos']
     `105` ['self', 'value']
     `106` ['self', 'event', 'painter', 'circle_y']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__ios_toggle\23e2f5010_IOSToggle.paintEvent.c`

### `IOSToggle.sizeHint`

- implementation: `FUN_23e2f69b0`
- source line hint: `89`
- Nuitka codevar: `_DAT_23eeafff8`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `87` 'pos'
     `88` 'return'
     `89` 'bool'
     `90` 'hitButton'
     `91` 'IOSToggle.hitButton'
     `92` 'paintEvent'
     `93` 'IOSToggle.paintEvent'
     `94` 'sizeHint'
  => `95` 'IOSToggle.sizeHint'
     `96` 'minimumSizeHint'
     `97` 'IOSToggle.minimumSizeHint'
     `98` '__orig_bases__'
     `99` 'ui\\ios_toggle.py'
     `100` '<module ui.ios_toggle>'
     `101` ['__class__']
     `102` ['self', 'parent', 'small', 'tiny', '__class__']
     `103` ['self']
     `104` ['self', 'pos']
     `105` ['self', 'value']
     `106` ['self', 'event', 'painter', 'circle_y']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__ios_toggle\23e2f69b0_IOSToggle.sizeHint.c`

### `IOSToggle.minimumSizeHint`

- implementation: `FUN_23e2f6e70`
- source line hint: `92`
- Nuitka codevar: `_DAT_23eeaffe8`
- factory: `FUN_23e93e1e0`
- nearby constants:
     `89` 'bool'
     `90` 'hitButton'
     `91` 'IOSToggle.hitButton'
     `92` 'paintEvent'
     `93` 'IOSToggle.paintEvent'
     `94` 'sizeHint'
     `95` 'IOSToggle.sizeHint'
     `96` 'minimumSizeHint'
  => `97` 'IOSToggle.minimumSizeHint'
     `98` '__orig_bases__'
     `99` 'ui\\ios_toggle.py'
     `100` '<module ui.ios_toggle>'
     `101` ['__class__']
     `102` ['self', 'parent', 'small', 'tiny', '__class__']
     `103` ['self']
     `104` ['self', 'pos']
     `105` ['self', 'value']
     `106` ['self', 'event', 'painter', 'circle_y']
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__ios_toggle\23e2f6e70_IOSToggle.minimumSizeHint.c`

### `?`

- implementation: `LAB_23e2f26d0`
- source line hint: `?`
- Nuitka codevar: `uVar3`
- factory: `FUN_23e93e480`
- decompiled C file: `P:\projects\Majestic\Sonar\01_reverse_engineering\reverse_analysis\function_specs\decompiled_impls\ui__ios_toggle\23e2f26d0_unknown.c`
