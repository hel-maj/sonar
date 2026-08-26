# Sonar Fishing UI primitive delta

Статус: verified migration inventory; frozen Common 0.2.21 adopted

Дата: 2026-08-22

## 1. Назначение

Этот inventory фиксирует observable semantics исторических PySide primitives,
по которым был принят перенос интерфейса на WPF. Legacy sources удалены после
parity gate. Документ не назначает Fishing источником истины для общей
UI-библиотеки и не разрешает копировать product behavior в Sonar Common.
Точный page/surface status и ownership каждого product behavior находятся в
`docs/architecture/UI_PARITY_LEDGER.md`.

Sonar Common UI kit является самостоятельной платформенной целью для всех
products, а не только результатом dedupe существующих controls. Его scope
включает tokens, themes, typography, spacing, generic controls, accessibility,
responsive behavior и visual regression kit, в том числе новые platform
primitives, которых пока нет во всех legacy UI. Fishing владеет только product
composition, content, state, branding и Fishing-specific extensions.

Consumption boundary: Fishing получает versioned Common UI package, задает
product content/state через public semantic contracts и расширяет primitive
composition или documented properties. Fishing не копирует shared XAML/code и
не отбрасывает product behavior ради наименьшего общего API. Этот документ
передает Common evidence и requirements, но не размещает Common code в Fishing.

Проверенный snapshot:

- Fishing `fe9b5ec1f0f38fa21ca1bc1b2099adc588faa000`;
- Hunting `728eba97fdb693d43a329e100c75f33f762d1377`;
- Poker `326aa656132d56891950546f87af0e18f90bb073`;
- существующие dirty изменения Poker training не относятся к UI и не
  использовались как evidence.

Исторические baseline sources:

- Fishing: удаленные `src/sonar/ui/widgets.py` и
  `src/sonar/ui/main_window.py` доступны в Git history;
- Fishing visual union: обе tracked variants в `outputs/ui_screens/` и
  текущий embedded `src/dotnet/Sonar.Fishing.Host/Assets/sonar_logo.png`;
- Hunting: `versions/02-screen-space-runtime-marker/ui/sonar_widgets.py`,
  `ui/main_window.py`;
- Poker: `src/sonar_poker/ui/primitives.py`, `ui/toggle_switch.py`,
  `ui/theme.py`, `ui/shell.py`.

## 2. Delta duplicated primitives

| Primitive | Подтвержденная общая семантика | Fishing delta, которую нельзя потерять | Отличие Hunting/Poker | Migration rule |
| --- | --- | --- | --- | --- |
| Font bootstrap | Все три продукта встраивают одинаковый Inter 4.1 payload и предпочитают `Inter -> Segoe UI Variable -> Segoe UI -> Arial` | Fishing загружает fonts до построения окна и применяет выбранное family ко всему `QApplication` | Hunting держит loader рядом с widgets; Poker выделил `font_setup.py` | Common может владеть licensed font package, hash verification и generic family selection. Product владеет bootstrap timing и fallback UX |
| `ToggleSwitch` | Full-row hit target, animated 150 ms track, 34 x 19 geometry, disabled tone, optional text | Fishing использует программный `setChecked` с немедленной синхронизацией animation position при blocked signals | Hunting реализация семантически совпадает; Poker вынес constants и typing в отдельный module без изменения contract | Один общий contract допустим. Обязательны tests для click area, blocked signals, disabled palette и animation end state |
| `Card` | Expandable card/soft-card surface | Fishing поддерживает `danger`, `soft`, normal variants, background fill, shadow и product QSS properties | Hunting совпадает по variants; Poker использует custom rounded frame overlay и не имеет `danger` | Common primitive должен иметь semantic variants и optional frame renderer. Нельзя заменить Poker overlay обычной QSS border или удалить Fishing danger/shadow |
| `SectionHeader` | Title, optional wrapped subtitle, vertical layout | Fishing имеет нижний spacing 7 и subtitle spacing 2, используемые в плотных settings/statistics pages | Hunting совпадает; Poker использует margins 0 и spacing 3 | Common задает slots и tokens, а product density передается style profile, не hardcoded fork |
| `Badge` | Centered text с semantic color property | Fishing меняет tone после создания через `set_tone` с forced repolish; это используется running/stopping/license states | Hunting имеет тот же mutable tone; Poker badge immutable после создания и ограничен maximum width | Общий contract обязан поддерживать runtime semantic-state change. Poker sizing остается product style option |
| `NavButton` | Selected state, icon, full button click, repolish | Fishing tint-ит SVG icon при selection и поддерживает animated hover shadow | Hunting сохраняет hover, но не tint-ит Path icons; Poker tint-ит selection icon, но не использует Fishing hover class | Common может предоставить selected/icon contract и visual states. Hover, tint palette и shadow являются composable style behaviors |
| `ActionButton` | Semantic action button с pointer cursor | Fishing имеет roles, size variants, optional tinted icon и hover animation | Hunting принимает те же arguments, но не рисует passed icon; Poker поддерживает только default/primary | Нельзя унифицировать по наименьшему Poker API. Common surface должен допускать role, size, icon и visual-state strategy; product profile выбирает реально используемые variants |
| `MetricCard` | Soft card с metric value и label | Fishing поддерживает optional icon и уменьшает font size по длине value; отдельный `CompactMetric` дает более плотную Fishing-specific форму | Hunting сохраняет adaptive value, но намеренно убрал icon slot; Poker metric центрирован и не имеет runtime setter | Общими являются content slots и semantic tokens. Adaptive sizing, alignment, icon slot и compact composition остаются options или product wrappers |
| `NonScrollingComboBox` | Wheel не меняет selection случайно | Fishing использует его внутри прокручиваемых settings pages | Hunting имеет тот же behavior; Poker пока не имеет consumer | Подходит для Common после появления WPF consumer с тем же input contract; отсутствие Poker consumer не основание удалять behavior |
| Page scroll | Scrollable page с transparent viewport | Fishing `PageScrollArea` форвардит wheel от descendants, но не перехватывает nested `QScrollArea`; `ContainedScrollArea` всегда consumes wheel внутри локального списка | Hunting pages сейчас не имеют этого helper; Poker `make_scroll_page` создает простой `QScrollArea` без forwarding policy | Общий scroll shell должен иметь explicit nested-scroll policy. Простая замена Fishing implementation на Poker helper ломает fish list, recent events и settings scrolling |
| SVG/icon rendering | Product resources превращаются в Qt icons | Fishing имеет cached renderer, attribute tinting, `SvgIcon` с animated color и fallback label path | Hunting nav Path фактически не получает icon; Poker имеет отдельный `svg_icon` и selection tint | Common может владеть generic SVG rendering/tint mechanism. Icon catalog, fallback glyph, palette и animation принадлежат product presentation |
| Elided/clickable links | Label может показывать bounded text и реагировать на click | Fishing `ElidedLabel` показывает delayed tooltip только при реальном elision; `ExternalLinkLabel` хранит URL, меняет cursor/style и открывает его через desktop service | Hunting и Poker не имеют эквивалентного contract | Не удалять как supposedly duplicate label. При выделении Common отделить text measurement от product navigation/security policy |
| `SettingCard` | Card может содержать title/subtitle/icon и control content | Fishing дает `add_widget` и `add_layout`, сохраняет consistent settings composition | Hunting строит cards вручную; Poker settings page использует свои page helpers | Common candidate только после второго consumer. До этого это Fishing-owned presentation composition |
| `HotkeyButton` | Action surface отображает текущее key binding | Fishing владеет capture lifecycle, modifier normalization, Escape cancel, focus-out cancel и signals `hotkeyChanged`/`captureStateChanged` | Hunting hotkey polling находится в window и не использует capture widget; Poker capability отсутствует | Не переносить в generic button. Это отдельная input-binding capability с собственным contract и tests |
| `DataTable` | Table surface использует общие palette/card tokens | Fishing statistics table остается обычным `QTableWidget` с numeric delegate и product calculations | Hunting inventory имеет собственные grid/table/hover semantics; Poker `DataTable` добавляет custom header painting, typed sort values, delete context menu и selection rules | Не создавать один generic table путем копирования Poker в Common. Сначала отделить generic header/sort primitives от product row identity, deletion, hover и statistics policy |

## 3. Shell и stylesheet ownership

Общая визуальная форма подтверждена только для следующих mechanisms:

- light-blue application background;
- sidebar + content shell layout;
- card, muted text, badge и button design tokens;
- navigation selected state;
- Inter font payload и family fallback;
- layout-driven resizing.

Product shell semantics различаются:

- Fishing sidebar показывает license, update state и product version, а page
  registration применяет feature gates;
- Hunting shell владеет overlay, inventory, vehicle runtimes и их lifecycle;
- Poker shell владеет live-table presence, replaceable live/history pages и
  deferred deletion rebuilds.

Поэтому общий shell может предоставить только regions, navigation composition
и visual states. Он не владеет page catalog, license, runtime status, live-table
identity или process lifecycle.

В Common stylesheet допускаются reset, tokens и selectors подтвержденных
generic primitives. Fishing selectors для `fishingPreview`, `fishKeepCard`,
`recentEventsScroll`, status tiles, stream/license/settings и statistics
остаются рядом с Fishing capabilities. Hunting inventory/vehicle selectors и
Poker table/delete-menu selectors также остаются в своих продуктах.

## 4. Target WPF extraction rules

1. Переносить observable contract, а не совпадающее имя Python class.
2. Common primitive расширяется через properties, visual states, templates и
   composition; product не копирует shared XAML для добавления одного variant.
3. Product wrapper допустим, если behavior имеет только одного consumer или
   содержит product policy.
4. Нельзя унифицировать по наименьшему API и потерять Fishing icon, runtime
   tone, nested wheel, adaptive metric или hotkey capture semantics.
5. Нельзя расширять Common product callbacks, license state, navigation rules,
   game input или persistent settings.
6. Каждый extracted primitive получает parity tests минимум от реальных
   consumers, а не только screenshot comparison.
7. После перехода consumer удаляет локальную duplicate implementation только
   после visual and interaction parity и rollback window.
8. Accessibility, keyboard/focus semantics, DPI/responsive layout и visual
   regression fixtures входят в Common acceptance, даже если legacy duplicate
   control не содержал полной реализации этих platform qualities.

## 5. WPF slices

Phase 3 реализует inert Engine-status screen в
`src/dotnet/Sonar.Fishing.Host` как exact package consumer `Sonar.UI.Wpf`
0.1.0. Common checkout, `ProjectReference` на Common и copy XAML отсутствуют.
Shell загружает package theme и использует Common `Card`, `StatusBadge`,
`ActionButton` и `SectionHeader`.

Fishing сохраняет product ownership для текста, ready/running/stopping mapping,
layout composition и immutable fake state. Замена immutable ViewModel обновляет
runtime mutable badge tone. STA tests проверяют package resources, responsive
narrow/wide layout без fixed width, wrapping, automation names, heading levels
и keyboard tab semantics.

Это не visual parity всего PySide shell и не authority cutover. Hotkey capture,
nested scrolling, metrics, icons, navigation, license state и остальные
Fishing-specific extensions остаются в inventory до следующих slices.

Phase 7 добавляет второй bounded read-only surface:
`FishingSessionSummary/FishingSessionSummaryScreen`. Он переносит фактическую
нижнюю сводку страницы `Рыбалка`: четыре metrics (`Время`, `Поймано`,
`Отпущено`, `Доход`) и полный список снастей либо exact empty state. Screen
использует только package `Card`, `SectionHeader`, `MetricCard` и стандартную
WPF composition; product-local копий Common templates/controls нет.

Fishing владеет immutable snapshot, Python-equivalent formatting, labels and
composition. Phase 8 перенесла fake source в
`FishingPageViewModel.MigrationPreview`; он остается transport-independent.
Live `FishingSessionStats` adapter, product icons and UI cutover не добавлены;
их acceptance/removal gate зафиксирован в product parity ledger.

Phase 9 оставляет revisioned Python snapshot/start-stop только nonshipping
characterization oracle; Python transport adapter не является target. Phase 10
добавляет real inert C++ session event и product mapper: offline WPF surface
потребляет immutable aggregate, demo остается fake. Shared controls не получают
Fishing transport semantics; Common по-прежнему владеет только generic UI
contract, а Fishing — state mapping и composition.

Phase 8 превращает Host в запускаемый WPF migration executable и потребляет
Common `NavigationButton` для двух product-owned pages: `Рыбалка` и
`Диагностика`. Shell сохраняет layout-driven width, keyboard navigation и
runtime selected state без копии Common template. Fishing владеет page catalog,
mode labels, navigation commands и content composition.

Executable shell не означает full visual parity. Legacy 8-page catalog,
license redirect, update/version regions, product icons, hotkeys, nested scroll
policy и live start/stop commands остаются в ledger как Pending. Demo page
скрывает отсутствующие actions, а offline health page показывает только реальный
contained diagnostic receipt. Эти migration states не меняют Common primitive
contract и не стирают Fishing-specific requirements.

Fishing now consumes frozen `Sonar.UI.Wpf 0.2.21`, SHA-256
`BCF274F21A2BBBB0BC21799D489881AF086929AEA26547EEF4E816590D2D2675`.
No local responsive shell/sidebar/nav/page-header, dashboard/settings/table/
master-detail, loading/empty/error/unavailable/dialog/notification or grid
template was copied. The package supplies available-content-width compact 4,
medium 8 and expanded 12 columns with Common-owned gutters, page padding,
maximum content width, vertical rhythm and span/start behavior.

Current adoption gate is 8/8 pages and 180 deterministic renders across three
available-width layouts and four DPI targets, including product threshold-slider,
fish-selection, hotkey-conflict and three startup-admission variants. Fishing passes only page names, Russian copy,
data, commands, feature policy and embedded product assets into the shared
patterns. Exact remaining runtime authority gaps stay in
[UI_PARITY_LEDGER.md](UI_PARITY_LEDGER.md); a local source fork remains
forbidden.

### Exact additive Common needs from Fishing

Adopted immutable package covers the generic contract rather than a Fishing
copy: `AppBrand` with full/compact embedded `ImageSource` and text fallback;
responsive 8-item-capable AppShell regions; account/version/update slots;
page header/command bar; 4/8/12 available-width grid; dashboard, settings/form,
table/master-detail and aspect-media containers; mixed-editor table with edit
preservation; bounded feed; chart/legend; loading/empty/error/unavailable;
dialogs/notifications; secure/numeric/hotkey input patterns; DPI, keyboard,
focus, automation, overflow/elision, nested-scroll and shadow/clipping states.

Fishing передает в эти contracts только product page names/order, Russian copy,
data, feature policy, commands, icons, embedded logo/fish assets and chart/table
semantics. Common не получает license/network/process services or product asset
catalog. Полный control/state/interaction mapping находится в sections 2.1-2.11
[UI_PARITY_LEDGER.md](UI_PARITY_LEDGER.md).
