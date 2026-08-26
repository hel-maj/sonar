# Sonar Fishing product UI parity ledger

Статус: exhaustive historical ledger + verified WPF/Common 0.2.22 production
overlay; legacy UI owner retired, native production cutover выполнен, live и
signed-release acceptance остаются отдельными gates

Дата: 2026-08-24

## 1. Граница ledger

Этот документ фиксирует исторически собранный Python/PySide6 baseline и
назначает владельца каждой observable product semantics в текущем WPF UI.
Он дополняет primitive-level inventory
`docs/architecture/UI_PRIMITIVE_DELTA.md`: delta отвечает на вопрос «каким
должен быть общий control», а ledger — «какая Fishing-функция обязана остаться
в product composition».

Указанные ниже `src/sonar` paths являются только Git-history evidence: legacy
UI/services удалены из product graph. Текущий runnable owner - WPF Host и C++
Engine. Normal no-argument production composition активна; отдельные внешние и
неподтверждённые capabilities остаются явно fail closed.
Детальные строки ниже сохраняют exhaustive legacy union; их исторические
phase-status читаются вместе с этим текущим code-backed overlay:

- exact frozen UI consumer: `Sonar.UI.Wpf 0.2.22`, SHA-256
  `A2B33A8D7E6F7F4803F8A5D4F703CF091D8D4A18B51F4147413A8D90837BA6A8`;
- 8/8 product pages consume Common AppShell/AppBrand/page/grid/dashboard/
  settings/table/master-detail/state patterns without copied Common XAML;
- 180 deterministic renders cover compact/medium/expanded and
  100/125/150/200%, plus threshold-slider, fish-selection, hotkey-conflict and
  startup checking/blocked/unavailable variants;
- statistics, settings, native fishing, hotkeys, licensing and Telegram subset
  have production owners; Stream, general update and unverified Telegram/game
  actions remain unavailable with exact prerequisites in the cutover matrix.

В ledger:

- **Python** - функция существовала в историческом production UI baseline;
- **WPF inert** — demo использует immutable fake state либо offline mode
  получает настоящую, но side-effect-free C++ diagnostic state;
- **Pending** — перенос не выполнен;
- **Do not copy** — legacy-механизм противоречит target architecture либо не
  имеет фактического consumer.

Общий `Sonar.UI.Wpf` владеет Inter, tokens, themes, spacing, generic controls,
accessibility, responsive contracts и visual regression kit. Fishing владеет
текстом, page catalog, composition, feature policy, состояниями, командами,
иконками продукта и adapter-ами. Product не копирует XAML/templates Common и не
создает локальный generic control только ради обхода package API.

## 2. Page и shell ledger

Status cells in this exhaustive table preserve the phase evidence available
when each row was first migrated; they are historical provenance, not the
current release verdict. The current code-backed status and remaining gates are
owned by `PRODUCT_FUNCTION_AUDIT.md` and `PRODUCTION_CUTOVER_CHECKLIST.md`, with
the current overlay in section 1 above.

| ID | Фактическая PySide6 функция | Common consumption boundary | Fishing-owned semantics, которые нельзя потерять | Historical phase status and gate |
| --- | --- | --- | --- | --- |
| `START-01` | `StartupLoader` показывает этап проверки лицензии/доступности версии; `StartupBlockedWindow` закрывает основной UI и дает download action | `Card`, `StatusBadge`, shared `ProgressBar`, `ActionButton`, hyperlink и typography | Порядок license/startup-block checks, fail-closed launch, download URL policy и lifecycle окна | **Done offline / production wiring pending.** WPF surface сохраняет embedded logo, checking/blocked/unavailable union и HTTPS-only download action; fixed signatures, fake transports and runtime-monitor tests are green. Main shell wiring waits for production composition and entitlement authority; fake success is not used |
| `SHELL-01` | `MainWindow._build_ui` создает sidebar + content stack; sidebar содержит Sonar branding, 8 navigation items, license summary/manage action, version и update link | `NavigationButton`, `Card`, `ActionButton`, theme/tokens, responsive shell regions | Page catalog/order, selected page, initial `Лицензия`, branding, license/version/update content | **WPF migration Phase 8 partial.** Запускаемый shell имеет Common navigation и реальные `Рыбалка`/`Диагностика` pages без fixed sidebar width. Остальные 6 pages, initial `Лицензия`, license/version/update content и feature redirect pending; two-page offline catalog не считается полной parity |
| `SHELL-02` | `_select_page` перенаправляет запрещенную feature page на `Лицензия`, обновляет selected nav state и запускает page-specific refresh | Common предоставляет только navigation visual state | Feature keys, entitlement decision, refresh ownership и safe redirect принадлежат Fishing | **Pending.** Требуется accepted managed entitlement source; UI не решает entitlement самостоятельно |
| `SHELL-03` | `_page`, `_scroll_page`, `eventFilter` и `_forward_page_wheel` дают page header, outer scroll и Fishing-specific nested-wheel policy | Common владеет responsive scroll shell и accessibility; package 0.1.0 еще не заменяет весь policy | Не перехватывать wheel у nested lists; `ContainedScrollArea` должен consume локальный wheel | **Pending.** Перенос после Common scroll contract/interaction tests, без копии Qt helper |
| `OVR-01` | `Обзор`: control card рыбалки и компактное `Состояние системы` без снастей | `Card`, `StatusBadge`, `ActionButton`, `MetricCard`, `SectionHeader` | Две product projections одного bot/session state, preview content и exact game/player statuses | **Pending**, кроме inert control mapping из Phase 3; нужен один revisioned read-only snapshot adapter |
| `OVR-02` | `Текущая сессия`: время, поймано, **оставлено** (`kept_count`), доход и доход/час; premium gate скрывает четыре metric | `MetricCard` либо product compact composition поверх Common tokens | В Overview третья metric намеренно показывает kept, а не released; premium visibility policy и income/hour | **Pending.** Не переиспользовать Phase 7 `Отпущено` с другой семантикой |
| `OVR-03` | Telegram summary: enabled badge, Chat ID, runtime status, notification summary, переход в настройки | `Card`, `StatusBadge`, `ActionButton` | Credential-safe content, feature gate, availability state, navigation callback | **Managed model partial.** Credential-safe Host draft/status/signature and seven-notification count are ready; Overview projection/navigation and Common 0.2 composition remain |
| `OVR-04` | Stream summary: on/off badge, status, quality, mode и переход в настройки | `Card`, `StatusBadge`, `ActionButton` | Stream lifecycle snapshot, feature gate и navigation callback | **Phase 23 offline done / runtime partial.** Overview and Stream consume one immutable Host snapshot; real process/network lifecycle and settings-navigation action remain |
| `OVR-05` | `Последние события`: in-memory ordered rows time/level/message/extra, empty state, nested scrolling и `Очистить` | `Card`, `ActionButton`, typography/scroll contract | In-memory event ownership, order, level tone, clear command и bounded retention | **Pending.** Presenter возможен после typed event snapshot; clear остается отдельной command boundary |
| `LIC-01` | `Лицензия`: masked key activation form, status/errors; account status, tier и expiry metrics | `Card`, `ActionButton`, `MetricCard`, text-input/accessibility primitives | Secret handling, activation lifecycle, feature catalog, account copy and error mapping | **Pending.** Network/license operations не входят в inert UI; key нельзя помещать в logs/snapshots |
| `FISH-01` | Две копии control card показывают ready/running/stopping, detected stage, `Старт/Стоп`, hotkey badge и 192x108 game preview | `Card`, `StatusBadge`, `ActionButton`, generic image surface | Bot lifecycle mapping, hotkey content, preview source/refresh, start/stop commands and safety gate | **WPF migration partial.** Demo явно fake и скрывает actions. Offline mode получает real revision/stage/running flags от contained inert C++ Engine event; это доказывает mapper, но не production lifecycle. Preview/hotkey/live commands и complete state-machine authority pending |
| `FISH-02` | `Состояние системы`: игра, inventory, food, water, bait, leader/hook, net; value/subtitle и red/green state dot | `Card`, `MetricCard` or product tile composition, `StatusBadge` semantic tone | Exact unknown/present/count formatting, game availability and session tackle mapping | **Pending.** Нужен atomic snapshot from game/player/tackle sources; нельзя собирать inconsistent UI state несколькими fine RPC |
| `FISH-03` | Нижняя сводка: `Время`, `Поймано`, `Отпущено`, `Доход`; рядом полный список rod/reel/line/hook/bait/net или exact empty text | Package `Card`, `SectionHeader`, `MetricCard`; Common owns adaptive value sizing and accessible names | Exact `format_duration`, exact money range threshold/rounding, released (не kept) count, slot names/order/count text | **WPF migration partial.** C++ `SessionStatistics` и shared corpus переносят semantics; offline page получает real revisioned C++ aggregate and mapper, demo остается fake. Inert Engine сейчас публикует только корректное пустое session state, поэтому non-zero/live parity, full visual matrix и production cutover pending |
| `SET-01` | Behavior grid: auto-meal, depleted food/overweight/equipment actions, auto-bait, trunk, sound, leader/net fallback and dependent enable/visibility rules | `Card`, `ToggleSwitch`, `NonScrollingComboBox` | Settings schema, allowed option IDs, dependency rules and destructive action copy | **Partial.** Managed `config/state.dat`, round-trip, recovery and legacy migration готовы offline; editable WPF page, dependency rules and revisioned save/apply pending |
| `SET-02` | Food/water recovery threshold sliders | Generic slider/tokens/accessibility принадлежат Common UI platform | Units, limits, persistence and application timing | **Pending.** Contract должен быть resolution-independent and keyboard accessible |
| `SET-03` | Fish keep list: sorted localized fish cards, select all/clear all, contained scroll; drives exact selected-ID policy | Common card/toggle/scroll primitives | Fish catalog snapshot, stable fish IDs, selection semantics and catch-disposition policy revision | **Pending.** Нельзя отправлять отдельные stateful decisions; Host передает immutable policy snapshot coarse Engine operation |
| `SET-04` | Six `HotkeyButton` bindings implement capture, normalization, Escape/focus cancel and suppress-until-release; save applies config immediately | Common 0.2.22 `HotkeyCapture`/`HotkeyGesture` own generic capture, focus and presentation | Command names, defaults, conflicts, persistence and runtime application | **Done native / live acceptance pending.** Capture/save/conflict UX is shared; normal Host reads the latest persisted start/stop gesture in one bounded lifecycle, suppresses while its own window is foreground, requires full release and invokes the existing coarse entitlement-gated automation command once per press |
| `SET-05` | Danger uninstall card performs availability check, confirmation and self-removal | `Card` danger variant and `ActionButton` danger role | Product install topology, warning copy, confirmation and destructive operation | **Pending / release boundary.** Не входит в offline migration slice |
| `STAT-01` | Actions `Новая сессия` и CSV export; filter supports current, saved session, date, range and since-date | `ActionButton`, `NonScrollingComboBox`, input primitives | Filter grammar/errors, export schema and session reset command | **Target split.** Current-session filter may move; persistent saved-session history is **Do not copy** because target WPF release keeps session statistics in memory only |
| `STAT-02` | Six aggregate metrics: duration, caught, kept, kept weight, income, income/hour | Common metric/dashboard pattern | Fishing aggregation and price policy | **WPF data parity partial.** One revisioned native aggregate maps exact six presentation values; Common 0.2 screen composition/visual matrix pending |
| `STAT-03` | Fish table shows icon/name/caught/kept/default price/custom editable price/income | Common mixed-editor table pattern | Row identity by fish ID, numeric validation, custom-price mutation and recalculation | **WPF read projection partial.** Coarse proto + mapper + exact 6-column row ViewModel ready; edit preservation/save/apply and Common 0.2 table UI pending |
| `STAT-04` | Catch-size donut plus legend | Common chart/legend/content region and visual-regression infrastructure | Size buckets, totals, labels and chart composition | **WPF data parity partial.** Native stable buckets and product legend/empty-state ViewModel ready; responsive chart rendering pending Common 0.2 |
| `TG-01` | Telegram page manages enabled/token/admin IDs, availability status, seven notification switches, inventory threshold and external setup links | `Card`, `ToggleSwitch`, `ActionButton`, generic secure input/link primitives | Credential secrecy, validation, notification policy, feature gate and navigation security | **Production transport + native fishing adapter composed / remaining actions partial.** Common 0.2.22 page, exact parsing/normalization, credential lock, availability/feature gates, settings, 45 routes, bounded HTTPS/long poll, callback edit/new/ack, native fishing start/stop, statistics and tackle projections are covered. Demo/offline remains network-denied; player scan, screenshot, focus and shutdown have no native adapter and stay hidden/fail-closed |
| `STREAM-01` | Stream page shows status/area/quality/autostop/public URL; start/stop/chat-mode; quality, chat zoom, 10fps toggles; four session metrics | `Card`, `StatusBadge`, `ActionButton`, `ToggleSwitch`, `NonScrollingComboBox`, `MetricCard` | Stream subprocess/network lifecycle, URL policy, feature gate, quality profile and settings | **Local Access composition done offline / live acceptance pending.** The compile-isolated local bundle embeds exact hash-pinned FFmpeg/cloudflared and wires current-HWND capture, authenticated secret-path loopback HLS/viewer and Common-contained public tunnel lifecycle. Chat remains unavailable and hidden. Ordinary licensed composition keeps the typed unavailable state pending payload policy; no live capture/network acceptance is claimed |
| `ABOUT-01` | Current version/build, subscription note, update card/download action | `Card`, `ActionButton`, typography/link primitives | Build metadata, subscription/update policy, download URL and uninstall availability | **Truthful production surface.** Current version/short build, subscription projection and owned-log clear are wired. The disabled/unavailable download card is removed; it returns only after a production signed manifest endpoint/key and after-exit executor exist |
| `DEAD-01` | `_build_player_status_card` can build five metrics and a `Сканировать` action but has no call from `_build_ui`, Overview or Fishing composition | Ничего не извлекать по неиспользуемому code | Preserve only as audit evidence until owner decides removal | **Do not copy.** A constructed-but-unconsumed helper is not product parity scope |

## 2.1. Evidence и правило union

Ledger проверен не по названиям helpers, а по фактически построенному дереву
`MainWindow`, reusable widgets и двум tracked вариантам UI screenshots в
`outputs/ui_screens`. Source является authority для текущей интерактивности;
screenshot является evidence ранее доступной композиции. Если screenshot
показывает surface, который current builder больше не создает, его данные и
пользовательская цель входят в union только как одна проекция существующего
owner, а не как второй service/store.

Применены три outcome:

- **retain** — observable content/action/state нужен в WPF product;
- **merge projection** — раньше surface повторял тот же state на другой page;
  WPF использует один immutable source и несколько read-only projections;
- **do not copy** — helper/dead refresh hook не имеет constructed consumer либо
  противоречит target policy.

Фактический nav order: `Обзор`, `Лицензия`, `Рыбалка`, `Настройки`,
`Статистика`, `Стрим`, `Telegram`, `О программе`. Initial selection —
`Лицензия`; после accepted feature policy разрешен redirect/fallback. Скрытая
`Диагностика` migration page не является девятым production nav item.

## 2.2. Shell, branding и global interaction inventory

| Surface | Exact observable union | Owner / migration rule |
| --- | --- | --- |
| Brand | Embedded Fishing image logo рядом с `Sonar`; compact state сохраняет image-only mark; loader также показывает image + `Sonar` | Product owns `sonar_logo.png` and embeds it into `Sonar.exe`; Common `AppBrand` owns `ImageSource`, `CompactLogoSource`, text fallback, `Stretch=Uniform`, accessibility and compact layout. Loose asset forbidden |
| Sidebar | Eight ordered items with product icon, selected/hover state, full-row keyboard target | Common responsive AppShell/nav; Fishing owns catalog/order/icon keys/feature keys/selection command |
| Account card | Animated shield tone, license/account title and subtitle, manage action | One managed license snapshot; Common owns account-card pattern, Fishing owns copy/state/command |
| Footer | Version and clickable update link/state | One signed build/update snapshot; no second update checker in view |
| Page region | Title, subtitle, scrollable content and page command bar | Common 4/8/12 available-content grid and nested-scroll policy; no fixed screen width/resolution |
| Feature navigation | Disabled page redirects safely to License and stops disallowed runtime when required | Fishing application policy; Common never receives entitlement catalog or stop callback |

## 2.3. Обзор — exhaustive union

| Region | Content / interaction / state | Retention rule |
| --- | --- | --- |
| Fishing control | ready/running/stopping/unavailable/license state, stage text, start/stop action and configured hotkey | Same lifecycle snapshot/commands as Fishing page; distinct compact projection, never second control owner |
| System summary | Current source deliberately shows concise game/inventory/food/water projection without tackle; older screenshot includes tackle tiles | Keep concise current projection. Tackle remains available on Fishing from same atomic system snapshot, not duplicated service |
| Current session | duration always; caught, kept, income and income/hour feature gated | Exact kept semantics distinct from Fishing page released metric; one revisioned session aggregate |
| Telegram summary | enabled badge, status, at most two admin IDs plus remaining count, seven-notification enabled count, settings navigation | Read-only projection of one Telegram state; credentials never included |
| Stream summary | enabled/active badge, status, quality, area/mode and settings navigation | Read-only projection of one Streaming state; no network/process work in view |
| Recent events | icon/tone, message, optional detail, optional green/red extra, timestamp and divider; max 400 retained, newest 80 rendered; empty and clear | Product owns event facts/bounds/clear command. Common owns feed/empty/scroll visuals. Refresh preserves manual position unless already following bottom; delayed tooltip only on actual elision |

## 2.4. Лицензия — exhaustive union

- masked license-key editor; activate command and checking/active/inactive/error
  states;
- account status, subscription/tier and expiry metrics;
- activation/network failures mapped to user-facing, non-secret text;
- accepted entitlement controls nav visibility/redirect and related runtime
  stop policy;
- legacy role metric builder exists but is not consumed by constructed account
  surface: **do not copy** without a deliberate new product decision.

Common owns secure-input, form, metric, loading/error/unavailable patterns.
Fishing owns secret lifetime, endpoint/channel policy, feature catalog, error
mapping and commands. License key never enters snapshot, event feed or log.

## 2.5. Рыбалка — exhaustive union

| Region | Exact content/state | Migration rule |
| --- | --- | --- |
| Control | ready/running/stopping/license/unavailable mapping, start/stop, configured hotkey, detected phase | Same coarse application use case as Overview. Current source has hotkey-badge hook but never populates its list; target restores the intended visible binding from settings instead of copying the wiring defect |
| Preview | Game content in 16:9 surface, rounded/overflow-clipped | Common aspect-media pattern; product preview grant/source. Legacy 192x108 is ratio evidence, not fixed layout dimensions; no cover crop may hide semantic game content without explicit decision |
| Full system state | game, inventory, food, water, bait, leader/hook and net, each with value/subtitle and valid/problem dot | One atomic revisioned snapshot; no per-tile RPC or mixed revisions |
| Session metrics | duration, caught, released and income; introductory license may hide caught/income | Preserve released (not Overview kept) semantics and feature visibility |
| Tackle | six semantic slots: rod, reel, line, hook/leader, bait/lure and landing net; count/list or exact empty `Снаряжение ещё не сканировалось` | Single tackle projection. Older Statistics tackle card is merged here; do not maintain duplicate mutable list |

## 2.6. Настройки — exhaustive union

Behavior settings form contains:

1. auto meal and food-depleted action (`continue`, `stop`, `exit`,
   `shutdown`);
2. auto bait, store in trunk and start/stop sound;
3. overweight action (`release`, `stop`, `exit`);
4. fish without leader plus leader-depleted fallback;
5. fish without landing net plus net-depleted fallback;
6. equipment-depleted action (`stop`, `exit`, `shutdown`).

Dependency semantics are part of parity: disabling auto meal disables its
depleted-action control and three thresholds; leader/net toggles control their
fallback editors. Food/water/health sliders use inclusive 1..90 values, unit
step 1 and page step 5, with a live value badge.

Fish keep policy is a localized, stable-ID sorted list in two responsive
columns, each row containing the embedded fish image and a toggle whose
accessible/tooltip intent is `Оставлять`. It has select-all, clear-all and a
contained local scroll region. Legacy 56x29 image geometry is content-aspect
evidence, not a fixed screen-layout contract.

Six hotkey fields are distinct bindings: start/stop, inventory, use item,
backpack move, discard and chat. Capture includes normalized modifier ordering,
Escape cancel, focus-loss cancel and suppress-until-all-keys-released. It must
be an accessible binding editor, not an `ActionButton` pretending to capture.

Save is enabled only for a dirty Fishing draft and persists one complete next
revision before coarse runtime apply. The danger uninstall action shows exact
target, availability/unavailable explanation, warning confirmation with default
`No`, and critical failure state. `garbage_checks` currently has no constructed
rows and the five-metric player-status helper is also unconsumed: neither is
copied as phantom UI. Their settings/domain data remain only where an actual
runtime consumer exists.

## 2.7. Статистика — exhaustive union

Target surface is session-only: persistent history filters/saved sessions/date
range/since-date and file CSV export are **do not copy** under the accepted
no-history release policy. `Новая сессия`/reset remains a coarse explicit
command; any future export needs a separate product decision consistent with
the two-EXE allowlist.

The current-session union contains six metrics: duration, caught, kept, kept
weight, income and income/hour. The table has exact columns `Рыба`, `Поймано`,
`Оставлено`, `Цена`, `Своя цена`, `Доход`; row identity is stable `fish_id`,
fish icon/name are product-owned, alternate rows and overflow remain readable,
and only custom price is digits-only editable. A refresh cannot overwrite a
cell while it is being edited; commit updates one new policy revision and
recalculates the row/aggregates.

The product donut has modest/good/record/trophy/unknown buckets, center total,
legend entries only for non-zero buckets and exact empty state
`Уловов пока нет`. Common owns the chart/content-region/empty pattern and
accessible legend mechanics, while Fishing owns buckets, labels, colors and
values. The tackle card seen in an older screenshot is a merged projection of
the Fishing-page tackle source, not a second Statistics owner.

## 2.8. Telegram — exhaustive union

- enabled toggle; password token editor; admin-ID editor; availability
  checking/available/unavailable/error states and explanatory tooltips;
- token/admin fields locked while enabled; save only when draft is dirty;
- seven notification toggles: catch, automation start/stop, meal, inventory
  full, inventory space low, bait tired and focus lost;
- low-space threshold accepts comma or period, minimum 1.00 kg and two-decimal
  normalized display;
- external BotFather and ID-helper links use product allowlisted destinations;
- availability scheduling is product networking policy (700 ms debounce,
  5-second interval, 4-second timeout in legacy), not a UI/Common timer.

## 2.9. Стрим — exhaustive union

Status card covers off/starting/preparing/active/error, capture area
window/chat, quality, no-viewer autostop countdown and public URL with actual
elision tooltip. Commands are start, stop and chat mode; settings are
480/720/1080 quality, chat zoom and 10-fps mode. Metrics are target FPS,
bitrate, mode and uptime. Feature/runtime state determines exact command and
editor enablement.

One tracked screenshot also shows Telegram and License/account summaries on
Stream. Current builder no longer constructs those cards although dead refresh
hooks remain. Preserve their useful information only as read-only projections
of the existing Telegram/license sources if the final product composition keeps
them; never create Stream-owned credential/license services. Unconsumed
`stream_*` labels are not parity by themselves.

## 2.10. О программе, startup и dialogs

- About: current version/short build, subscription and diagnostics clear. It
  does not expose a disabled download action; general update UI returns only
  when signed update state and an after-exit executor are production-composed.
- Startup loader: centered shared raised surface, embedded logo + `Sonar`, stage
  caption and shared indeterminate progress. Window translucency is not copied:
  it risks clipped/aliased edges and does not add product semantics.
- Hard block: embedded branding, explanatory shared hyperlink, primary download
  and close actions;
  main shell is never constructed behind a fail-closed startup decision.
- Uninstall warning (default `No`) and critical error use Common dialog/error
  patterns with Fishing-owned target/copy/lifecycle.

## 2.11. Exact generic vs product-owned control inventory

| Common design-system contract needed | Fishing-owned semantics passed into it |
| --- | --- |
| `AppBrand` with embedded image/full/compact/text fallback | Fishing logo resources, `Sonar` label, accessible product name |
| responsive AppShell/sidebar/nav/page header/content regions/command bar | eight-page catalog/order/icon keys, feature policy, selection/navigation actions, footer snapshots |
| 4/8/12 available-content grid, gutters/padding/max width/vertical rhythm and dashboard/form/master-detail/table containers | page-specific spans and product data; never physical display resolution |
| cards including normal/soft/danger, status badges/tiles, metric groups and detail lists | product copy, state mapping, icons and commands |
| settings rows with toggle/combo/slider/secure/numeric/binding-editor slots and dependent disabled state | field IDs, allowed values, validation/dependency rules and immutable draft/revision |
| data table with mixed read/edit cells, edit preservation, keyboard/overflow states | fish rows/columns/stable ID/custom-price policy |
| bounded event-feed presentation with loading/empty/error/unavailable states | event retention/order/tone/content and clear command |
| 16:9 aspect-media surface and chart/legend region | preview grant/image and catch-size chart semantics |
| dialogs, notifications, blocked loader and external/elided link primitives | lifecycle decision, target, copy and allowlisted navigation policy |

Product assets—Fishing logo, fish images and product icons—stay embedded in
`Sonar.exe`; Common receives `ImageSource`/content and never owns their catalog.
Emoji/glyph fallbacks seen in legacy rows remain product content, but a missing
licensed icon is shown as an explicit accessible fallback, not silently
replaced with a different meaning. Shadows, rounded clipping and overflow are
verified through Common visual states and offscreen matrix rather than copied
styles.

## 3. Primitive union и запрет дублирования

| Need из фактического Fishing UI | Common 0.1.0 consumer | Fishing extension/composition | Что запрещено |
| --- | --- | --- | --- |
| Normal/soft/danger surfaces | `Card` variants | Page grouping and product danger copy | Локальный `FishingCard` с копией template |
| Runtime semantic states | `StatusBadge` mutable `Tone` | ready/running/stopping, license/stream/game meanings | Product color enum or copied badge style |
| Page/card headings | `SectionHeader` | Russian title/subtitle, heading hierarchy | Копия font/margins from Common dictionary |
| Product commands | `ActionButton` role/size/icon slots | Command, enablement, confirmation and safety policy | Generic Common callback that knows Fishing services |
| Session/account/stream metrics | `MetricCard` label/value/icon/alignment/adaptive sizing | Which metrics exist, their values and compact grouping | Product metric template fork; loss of adaptive/accessibility behavior |
| Navigation | `NavigationButton` | Page catalog, feature redirect and selected page | Common owning license/page registry |
| Boolean settings | `ToggleSwitch` | Settings field and dependent policy | Local animation/control copy |
| Combobox in scroll pages | `NonScrollingComboBox` | Option IDs, labels and validation | Restoring wheel selection in product wrapper |
| Icons and previews | Generic content/icon slots only | Fishing icon catalog, branding, preview data and fallback | Moving product assets/catalog into Common |
| Nested scrolling, hotkey capture, table, donut | No accepted complete package primitive yet | Keep current product behavior pending explicit Common contract or product-owned composition | Guessing a lowest-common-denominator control or copying another product implementation |

### Common design-system package needs before final WPF composition

Fishing не создает локальные аналоги следующих shared patterns, пока additive
immutable Common UI package не опубликован и не закреплен exact hash:

- responsive app shell/sidebar/nav/page-header/content regions/command bar;
- dashboard metrics, settings/form, table/master-detail and standard content
  containers;
- loading, empty, error and unavailable states, dialogs and notifications;
- DPI, keyboard, focus, automation/accessibility and nested-scroll behavior;
- starter composition/template shared всеми products.

Grid определяется available content width, не screen resolution: compact uses
4 columns, medium 8, expanded 12. Common владеет breakpoints, gutters, page
padding, maximum content width, vertical rhythm, responsive span/start и
standard dashboard/form/master-detail/table containers. Fishing владеет page
names, rows, labels, data, actions, feature policy and branding.

Mapping final pages к shared grid:

| Fishing surface | Shared grid/container need | Product-owned content |
| --- | --- | --- |
| `Обзор`, `Рыбалка` | dashboard metrics + responsive content regions | control state, game/system/session/Telegram/stream/event facts and actions |
| `Лицензия`, `Настройки`, `Telegram`, `Стрим`, `О программе` | form/settings regions + command bar + standard unavailable/error states | validation, dependencies, credentials, feature and lifecycle policy |
| `Статистика` | metrics + table/master-detail + chart content region | fish identity, prices, aggregates, chart buckets, reset/export policy |

No page may hardcode display resolution, DPI or aspect ratio. Compact/medium/
expanded selection comes only from current available content width; product
preview/game geometry remains a separate runtime observation contract.

## 4. Что в WPF новое, а что является parity

Новые platform qualities не считаются новым Fishing behavior:

- verified Inter resources, theme/tokens and per-control dictionaries приходят
  только из exact `Sonar.UI.Wpf` package;
- automation names, heading levels, keyboard reachability, adaptive metric text
  and layout without fixed physical width extend accessibility/responsiveness;
- immutable snapshots make presentation deterministic; demo state остается
  fake, а offline state приходит по real contained C++ IPC без side effects.

Product data semantics Phase 7 не расширялись: labels, duration/money
formatting, released count, six tackle slots and empty text already exist in
Python. Presentation prototype при этом не является visual parity: внутренний
heading `Текущая сессия` и vertical composition отсутствуют в legacy lower
card, first paint сейчас показывает `0 мин` вместо Python `00:00`, а four-column
metric layout ещё не доказан на narrow/DPI matrix. Эти различия требуют
отдельного product visual decision; они не становятся новой accepted функцией
только потому, что WPF surface responsive и данные не изменились.
Product icons пока намеренно отсутствуют: их перенос требует product-owned
packaging and visual parity, а Unicode/placeholder icons не подменяют catalog.

Phase 3 contains explicit migration-only explanatory copy and inert buttons.
Оно доказывает package behavior, но не принимается как final product copy or
live action surface; перед UI cutover required separate product copy/command
review.

Phase 8 добавляет executable shell, но не повышает parity автоматически.
Navigation содержит только две migration pages вместо legacy 8-page catalog,
offline mode открывает `Диагностика` вместо initial `Лицензия`, а demo page
скрывает start/stop actions. Это честные migration differences: они не удаляют
legacy requirements из ledger и не объявляются final product interaction.

## 5. Historical Phase 7/8 adapter и removal gate

`src/dotnet/Sonar.Fishing.Host/FishingSessionSummary` содержит только:

- defensive immutable `FishingSessionSummarySnapshot`;
- pure `FishingSessionSummaryViewModel` with Python-equivalent presentation
  formatting;
- `FishingSessionSummaryScreen` из package `Card`, `SectionHeader` и
  `MetricCard` plus standard WPF layout/text/items composition.

`FishingPageViewModel.MigrationPreview` дает неизменяемый fake demo state.
Offline composition запускает только inert contained C++ Engine: после
read-only start он получает один revisioned `FishingSessionSnapshot` по events
channel и атомарно заменяет lifecycle, totals и tackle presentation. Engine не
читает Python, files, GTA/process memory, capture/OCR, input или network.

At that phase a live adapter was permitted only after one accepted read-only
session snapshot contract with revision/generation, atomically containing totals
and tackle items. UI could not query duration, counts, prices and tackle through
separate fine-grained RPCs or mix revisions. Before the native cutover, Python
`FishingSessionStats`, `_refresh_stats_tab` and `tackle_items()` were the sole
production owner; they are no longer part of the product graph.

Phase 9 оставила Python aggregate только nonshipping oracle. Phase 10 добавила
C++ session owner, final product proto shape, product mapper и real offline
ViewModel update. Python transport намеренно не существует: финальный runtime
должен быть WPF Host + C++ Engine. Ни одна строка ledger не переводится в
complete, пока inert zero-state не заменен полным production snapshot и не
пройдены visual/interaction/cutover gates.

Fake preview и duplicate C# formatting удаляются либо становятся accepted
consumer only after:

1. exact Python/C# characterization for boundary, rounding, empty and six-slot
   cases, включая initial paint и enforced slot order/cardinality;
2. accepted coarse snapshot owner and reconnect/stale-state semantics;
3. WPF visual/accessibility regression at narrow/wide/DPI variants, включая
   отсутствие clipping у four-metric row;
4. explicit UI authority cutover, rollback window and removal approval.

Current focused acceptance: Release build 0 warnings/errors, 209/209
STA/lifecycle WPF tests, 7/7 managed IPC integration tests and native CTest
48/48. Tests do not open the product window or run a live GTA/input/network
adapter.
