# Sonar Fishing production cutover checklist

Статус: native source/build/runtime cutover выполнен; live и signed-release gates активны

Дата проверки: 2026-08-26

## Граница результата

Финальный runtime и bundle состоят только из WPF/C# Host и C++20 Engine.
Python, PySide6, Nuitka, interpreter/DLL, wheel, product Python source и
`--legacy-engine` запрещены в shipping graph. Исполняемые legacy tests/oracles
удалены; parity corpora сохранены только как language-neutral nonshipping
fixtures.

Статусы ниже означают:

- **done native** — capability подключена к normal no-argument composition;
- **done offline** — deterministic parity готова, но capability не подключена
  к production composition;
- **partial** — существует только часть observable contract;
- **pending** — production-owned capability/page отсутствует;
- **removal** — legacy путь должен исчезнуть после accepted parity/cutover.

## C++ Engine capabilities

| ID | Цельная capability | Текущий статус | Gate до production authority |
| --- | --- | --- | --- |
| `E00` | Common-owned dual-pipe connect, PID/session/handshake, framing | **done native** — normal Host запускает только manifest-bound contained Engine pair | signed-bundle crash/recovery acceptance |
| `E01` | Catch quality classification | **done native / live acceptance pending** — native catch observation and disposition path consumes the classifier inside the whole production episode | prove authentic catch corpus in an authorized live session |
| `E02` | Selected-fish catch disposition | **done native / live acceptance pending** — accepted immutable settings and the final mutation gate stay inside the Engine catch episode | prove keep/release and inventory-full policies against the supported live build |
| `E03` | In-memory session statistics/prices/tackle projection | **done native / live acceptance pending** — production progress records catches, prices and tackle into revisioned bounded session snapshots | validate a sustained real session; persistence remains intentionally absent |
| `E04` | Fish identity + aggregate catch observation | **done native / live acceptance pending** — embedded visual/text assets produce one aggregate catch fact inside Engine | extend and prove authentic multi-resolution catch evidence |
| `E05` | Long-lived Engine process lifecycle, heartbeat, sequence, bounded event queues, reconnect/terminal cleanup | **done native** - production Host owns one Common Job-contained pair. Unexpected process exit, heartbeat failure or event-pump death immediately withdraws runtime authority and publishes fail-closed idle state. The heartbeat owner never enters a permanent inert circuit: it retries indefinitely with exponential `250 ms` -> `2 s` capped backoff. Replacement receives the latest full settings snapshot and the still-valid signed entitlement exactly once, but never replays automation start/stop, notifications or input leases. Regression exceeds the old three-failure limit and proves later automatic recovery without another external check | repeat sustained normal lifecycle and crash/recovery against signed release pair; verify the same authority withdrawal and no-replay invariant with signed production artifacts |
| `E06` | Revisioned immutable runtime settings/policy application | **done native / live acceptance pending** — persisted Host snapshot maps whole over IPC, is pinned at production-session admission and is repeated by the final mutation gate; invalid/equal/stale and semantic hotkey conflicts reject atomically | runtime settings mutation/reconnect acceptance |
| `E07` | Signed short-lived entitlement verification and side-effect gate | **done native** - embedded production RSA trust root, HTTPS activation/refresh/cache/revocation and independent Host/Engine raw-envelope verification gate every automation start | authorized live activation/expiry/revocation acceptance; no trust bypass |
| `E08` | Whole fishing lifecycle state machine and stage transitions | **done native / live acceptance pending** — production loop owns fishing, catch, inventory, maintenance, cancellation and cleanup as coarse operations | complete authentic replay/live episode evidence; no Host fine RPC |
| `E09` | GTA process/window/client-area ownership and focus gate | **done native / live acceptance pending** — exact `GTA5.exe` resolver, Common trusted-module generation snapshot and runtime target/foreground/client guard are production-composed | prove trusted current GTA process, focus loss and window-generation changes under the authorized live gate |
| `E10` | Capture source and frame ownership | **done native / live acceptance pending** - production session composes coherent GDI client capture and revalidates identity/geometry before and after every frame | prove real multi-resolution/DPI and capture-loss recovery under the authorized live gate |
| `E11` | Memory readers: reeling, inventory, player status/chat evidence | **partial production** - positive same-frame reeling uses Common 0.1.9 trusted GTA lease plus Fishing full executable-section scan, unique player/replay endpoints, bounded replay count, one exact active-fish identity and authority-bound coherent capture. Independent Engine worker uses Common 0.1.19 trusted-publisher content provider and publishes changed-only open/weight/grid/item snapshots without blocking A/D/control IPC. Neither path gates availability on client version/hash/size/timestamp/profile; Common drift/read failure becomes unavailable without stale replay. Confirmed fish `1 -> 0` remains pending across one failed capture and is cleared only after coherent success. Player-status/chat production plans are absent | accept both trusted/semantic paths read-only, then separately authenticate current live content/weight and WebEngine fields; unknown/partial evidence remains fail-closed. See `RUNTIME_OBSERVATION_PARITY.md` |
| `E12` | Input controller and crash-safe action ownership | **done native / live acceptance pending** — every production episode shares one exclusive move-only lease and guarded Win32 sink with packet budgets, fresh final gate and bounded cleanup | prove held-input hard-crash/restart cleanup in the authorized environment |
| `E13` | Casting, hooking and atomic reeling episodes | **done native / live acceptance pending** — the production loop consumes stage/cue and same-cycle memory, then sends typed Space/A/D intents only through E12 | prove authentic cast/hook/reel cycles, target loss and hard-crash cleanup |
| `E14` | Trigger, catch screen and tackle/item-info CV/OCR | **done native / live acceptance pending** — embedded stage, inventory/tackle visual assets and Windows text recognizer are consumed through coherent production capture without Python/OpenCV/loose models | expand authentic multi-resolution corpus and validate supported live UI changes |
| `E15` | Inventory/menu/store-fish episode | **partial production** - production composes the native observer, reflow-aware episode runner and E12 mutation lease. Both ordinary and Local Access builds obtain tri-state only through the same Common trusted-publisher authority; screenshot remains geometry-only | prove read-only inventory/context confirmation, target loss and cleanup before any live mutation acceptance |
| `E16` | Meal/player-status recovery episode | **done native / live acceptance pending** — production maintenance consumes coherent status/HUD evidence and guarded inventory actions | prove stacked items, depletion and target-loss cleanup |
| `E17` | Garbage disposal episode | **done native / live acceptance pending** — stable candidate policy, reflow observation and bounded guarded disposal are production-composed | prove authentic multi-resolution inventory reflow and crash cleanup |
| `E18` | Bait/tackle depletion and equipment policy | **done native / live acceptance pending** — production maintenance owns fresh-read depletion, cooldown, restart and terminal outcomes | prove authentic tackle changes and process-loss cleanup |
| `E19` | Game chat focus/capture/type/confirmation | **done offline** — the native chat episode and deterministic tests exist, but normal production composition does not instantiate it or expose a coarse Host command | compose it only with the existing target/focus/input safety owner, then prove real focus/restore, non-FHD corpus and hard-crash recovery |
| `E20` | Aggregate runtime events/audio/tackle/session feed | **production notification stream composed / audio partial** - real production progress publishes revisioned session statistics/tackle plus bounded typed catch, start/stop, meal, inventory, bait and focus occurrence events. Events are generation/sequence-gated, never persisted/replayed and feed Telegram through a failure-isolated publisher; recent UI events retain 400/present 80 | authorized live event/Telegram acceptance and product audio adapter |

## C# Host capabilities

| ID | Host-owned capability | Статус | Gate |
| --- | --- | --- | --- |
| `H00` | Runnable .NET 10 WPF EXE, normal + explicit development compositions | **done native** — no arguments selects production; `--demo` and `--offline-engine` remain development-only | sustained signed normal launch acceptance |
| `H01` | Contained Engine launch, Job assignment and handshake | **done native** — production pair identity is loaded from canonical bundle manifest and hashes | signed-bundle crash/recovery acceptance |
| `H02` | `config/state.dat` schema, migration, DPAPI secret handling, atomic writes | **done offline** - real WPF startup owns exact path and fails closed | settings-page save/revision lifecycle and install/activation/crash/update bundle matrix; no legacy loose JSON |
| `H03` | License activation/refresh, entitlement issuance and feature policy | **done native / live acceptance pending** - production HTTPS activation, embedded RSA trust root, secure short cache/refresh/revocation and one coarse Engine entitlement sink are composed; key/raw response never enters logs or plain state | authorized activation/expiry/revocation acceptance |
| `H04` | Startup availability/update block and safe navigation | **done native / live acceptance pending** - normal launch performs signed initial admission before main composition and runs the sequential five-minute monitor | sustained normal launch against current signed endpoint and blocked-transition acceptance |
| `H05` | Hotkey capture/conflicts/suppress-until-release | **done native / live acceptance pending** - Common 0.2.22 owns capture/presentation, C#/C++ reject semantic conflicts, and normal Host owns one bounded Win32 polling lifecycle. It reads the latest persisted start/stop gesture, triggers the existing coarse entitlement-gated command once per press, suppresses while the product window is foreground and requires release before re-arming | authorized real key-state/reconfiguration/shutdown acceptance |
| `H06` | Telegram settings, availability, polling/notifications/commands | **production transport + native actions/events composed / remaining actions partial** - licensed normal mode owns bounded long poll, reconfiguration, native fishing start/stop, current statistics/tackle and typed automatic catch/start-stop/meal/inventory/bait/focus notifications. Publisher is bounded, generation/sequence-deduplicated and failure-isolated. Missing on-demand player scan/screenshot/focus/shutdown adapters are hidden and fail closed | live Telegram acceptance; implement only real product-owned native adapters for the remaining actions |
| `H07` | Streaming settings and FFmpeg/HLS/cloudflared lifecycle/chat mode | **Local Access composition done offline / live acceptance pending** - compile-isolated Local Access embeds hash-pinned FFmpeg 8.1.1 and cloudflared 2026.5.2, resolves one current GTA HWND, owns authenticated secret-path loopback HLS/viewer, launches both processes in Common kill-on-close Jobs and publishes a bounded HTTPS tunnel URL. The coarse revisioned controller retains exact 480/720/1080 + 30/10-FPS policy and bounded start/stop/retry/restart/autostop/cleanup. Ordinary licensed composition remains unavailable; chat bridge remains unavailable | run real capture/network, DPI/resize/alt-tab, process-loss/restart, public-viewer and two-EXE lifecycle acceptance; settle third-party redistribution/signing for ordinary licensed composition and add the coarse chat use case; see [H07 runtime](H07_STREAMING_RUNTIME.md) |
| `H08` | Update/download/activation unit, uninstall and rollback | **done offline + local development maintenance / partial production activation** - signed-manifest/staging/swap/recovery core, exact allowlist and uninstall plan are green; a product-owned after-exit executor now performs explicit development-unsigned install/update/rollback/recovery and key-only legacy-license import with external backup, sanitized receipt and repeated no-Python gate | production public key/metadata endpoint, signing certificate/timestamp, licensed composition, signed remote activation/uninstall and complete signed installed matrix; see [H08 transaction](H08_RELEASE_TRANSACTION.md) |
| `H09` | Logs/in-memory events and diagnostics | **done offline / partial production composition** - recent events retain 400/present 80 and clear atomically; Host startup/exit writes redacted JSONL through a 4 x 1 MiB rotating owner under exact `logs/`, rejects unsafe/reparse roots, and the About-page clear action deletes only exact `sonar*.log` generations | route remaining typed runtime failures/events through the same sink and repeat crash/allowlist/secret scans on the signed bundle |

## WPF page parity

Точный observable ledger находится в [UI_PARITY_LEDGER.md](UI_PARITY_LEDGER.md).
До cutover должны закрыться все строки ниже; helper `DEAD-01` не переносится.

| ID | Page/shell | Статус |
| --- | --- | --- |
| `U00` | 8-item shell, branding, version/update/license regions, feature redirect, nested scroll policy | **done offline** - Common 0.2.22 AppShell/AppBrand, embedded Fishing logo, exact 8-item catalog, feature redirect, navigation footer and responsive page scroll are composed; production license/update sources remain separate rows |
| `U01` | Startup loader/blocked surface | **done offline** - embedded Fishing logo, Common Card/StatusBadge/ProgressBar/ActionButton and shared hyperlink style preserve checking, blocked and unavailable states; download command repeats HTTPS/no-userinfo validation and the surface remains outside the main shell |
| `U02` | Обзор: fishing control, system, session, Telegram, stream, recent events | **partial** — full Common composition and bounded event/session projections exist; stream and live system authority remain inert |
| `U03` | Лицензия activation/account surface | **partial production / local-access complete** - production account/activation composition exists and unvalidated state hides internal migration copy; compile-isolated local build shows active `Локальный доступ`, hides key activation and raw feature IDs. Real production activation/refresh remains `H03` live acceptance |
| `U04` | Рыбалка control/status/session/tackle | **done native / live acceptance pending** — start/stop commands use the production Engine and real aggregate session events behind entitlement/safety gates |
| `U05` | Настройки behavior/depletion/thresholds/fish/hotkeys/uninstall | **partial** - state.dat atomic save, dependencies, 31-fish embedded selector, bulk actions, Common 0.2.22 styled inputs/wheel-safe combo (including `DisplayMemberPath` selection projection), threshold sliders and plain-letter hotkey conflict UX are composed; H08 provides an exact-confirmation safe uninstall plan, while after-exit execution remains pending |
| `U06` | Статистика current-session metrics/table/prices/chart/reset | **done offline / partial authority** — populated responsive Common DataGrid, embedded fish images, six metrics, chart, atomic custom-price revision and coarse reset contract are green; production Engine reset/source is not wired, history/CSV intentionally absent |
| `U07` | Стрим page | **Local Access wired / live acceptance pending** — responsive Common page preserves status/area/quality/autostop/URL, quality/chat zoom/10-FPS settings and four metrics from one typed snapshot. Local Access receives the real embedded-tool/capture/HLS/tunnel controller when all exact resources are present; chat action stays hidden/unavailable. Ordinary licensed composition still receives the fail-closed unavailable adapter | accept the Local Access process/network lifecycle and decide ordinary licensed payload policy; add chat only with a real coarse bridge |
| `U08` | Telegram page | **production transport / partial action parity** — Common composition, credential editors, settings, router/polling/planners and native fishing/statistics/tackle actions are wired; unavailable OS/game actions are not advertised |
| `U09` | О программе/update/uninstall | **truthful production surface / update activation pending** — About shows only real version/build, subscription projection and diagnostics clear. The unavailable download card/button is removed until H08 has production endpoint, trust and after-exit execution; startup signed admission remains separately active |

UI completion gate currently renders 180 deterministic offscreen STA screenshots:
all 8 pages at 100/125/150/200% for compact/medium/expanded content plus
responsive threshold-slider, fish-selection, hotkey-conflict and startup
checking/blocked/unavailable variants. They are compared against current legacy screenshots and
[UI_PARITY_LEDGER.md](UI_PARITY_LEDGER.md). Tests must cover keyboard/focus,
automation names, wrapping/clipping, mutable tones and Common primitive usage.
No live GTA/network/input/window launch is allowed for this visual gate.
The historical 2026-08-24 local review artifact is
`build/ui-gallery-0219-final/`; its
`gallery-manifest.json` records every rendered surface and DPI, pins Common UI
`0.2.20` and has SHA-256
`FD257489E58A3F69A154A54AD176447775981A51FCE0D1744EF6A8369305AD49`.
The last completed product visual corpus before the Common UI 0.2.22 repin was
rendered from 0.2.21 into
`build/ui-gallery-0221-final/`: 204 PNG cover every product page/variant at all
three layouts and four DPI targets. Its historical manifest pins `0.2.21` and has SHA-256
`43A2D07AEACEC9ACFE493DBF8D204EBA23333467B9C3DE3C7C7F9FE1F58DA00C`.
Current source exact-pins immutable 0.2.22 and passes a zero-warning build; the
product visual corpus remains a separate acceptance gate and must not be
represented by the historical 0.2.21 renders.

E09-E11 имеют отдельный non-shipping
[read-only live preflight](LIVE_OBSERVATION_PREFLIGHT.md). Он повторно использует
production resolver/capture/detector/memory path, не создаёт input lease или
mutation sink и возвращает только coarse readiness. Offline implementation и
regressions приняты. Live pass 2026-08-24 относится к прежнему SHA-gated
admission и остаётся historical provenance. Текущий production path требует
свежий Common lease и unique semantic anchors без hash enrollment. Отдельный non-shipping
[compatibility probe](BUILD_PROFILE_COMPATIBILITY_PROBE.md) подготовлен offline;
его единственный live pass вернул candidate hash, но fail-closed остановился на
`pattern_scan_incomplete`. Этот forensic receipt не управляет shipping
availability; physical input по нему не разрешён.

## Матрица доступных функций normal launch

| Surface/capability | Состояние обычного `Sonar.exe` | Точный prerequisite либо ограничение |
| --- | --- | --- |
| Запуск и состояние | **working** — no-argument production composition, persisted `config/state.dat`, supervised Engine restart and repeat launch over the same state are covered by the bundle lifecycle gate | signed distribution remains a separate release gate |
| Лицензия | **working** — activation, refresh/cache/revocation and independent signed entitlement admission are wired fail closed | valid backend response and product entitlement are required |
| Рыбалка | **working behind safety gates** — UI, global start/stop hotkey and Telegram start/stop call the same coarse native automation runtime | real trusted target, unique current semantic anchors, foreground and current entitlement are mandatory; live side effects were not triggered by the offline gate |
| Настройки | **working** — atomic save, revision checks, hotkey reconfiguration and DPAPI-protected secrets are wired | corrupt/unreadable settings stop startup with a user-facing recovery error |
| Telegram | **working subset** — HTTPS long polling, settings, fishing start/stop, current statistics and tackle are wired | player scan lacks a verified production status profile/IPC result; screenshot, focus and game/PC shutdown lack coarse Engine-owned safety contracts. Those commands are not advertised and direct calls reject |
| Стрим | **Local Access implemented offline / ordinary licensed unavailable** — the local bundle embeds exact hash-pinned tools and composes HWND capture, authenticated loopback HLS/viewer, contained encoder/tunnel and HTTPS public URL. Chat remains unavailable | no live capture/network or restart acceptance has been recorded yet; ordinary licensed release still needs redistribution/signing policy and chat needs a real coarse bridge. See H07 |
| Обновление | **local development workflow works / remote production fail-closed** — product command performs verified install/update/rollback/recovery after exit; startup signed admission/block works and About contains no dead download control | remote production still needs signed metadata endpoint/key, certificate/timestamp and accepted signed activation composition |
| Диагностика | **working** — bounded redacted rotating log and exact owned-log clear action | logs remain inside the release allowlist |

## Authority, removal and release gates

1. Every `pending` Engine episode is native and preserves observation,
   decision, final gate and side effect in one owner.
2. WPF receives only revisioned aggregate snapshots/events and sends coarse
   whole-session/config commands; no per-sample or per-input RPC exists.
3. `docs/migration/runtime-authority.json` changes production authority only
   after parity, crash/reconnect/safety and rollback acceptance.
4. **done** - Python/PySide/Nuitka production entrypoints, package metadata,
   `LegacyEngineFacade`, wheelhouse and Python-era build/test scripts are
   removed.
5. **done** - parity evidence is language-neutral; repository-owned `.py`,
   wheel and Python setup/runtime script count is zero.
6. Build final framework-dependent single-file `Sonar.exe` and native
   `Sonar.Engine.exe`, signed and activated as one versioned pair.
7. Smoke install/activation/launch/exit/crash/update/interrupted-update/rollback
   against exact allowlist: `Sonar.exe`, `Sonar.Engine.exe`,
   `bundle-manifest.json`, `config/state.dat`, `logs/*`.
8. Scan EXEs/bundle/process tree for Python/PySide/Nuitka markers, interpreter,
   wheels, DLLs, source and `%TEMP%\.net`; any match fails release.
9. Run complete deterministic tests, offline replay, visual matrix, signing and
   no-Python/allowlist gates before any release upload or live action approval.
10. After each accepted parity slice record startup/CPU/memory/IPC and relevant
    hot-path baseline. Optimize only a demonstrated hotspot as a separate
    semantics-preserving change with before/after evidence and repeated gates.

`package_native.ps1` now owns a real two-clean-root framework-dependent
single-file Host/native Engine build, canonical pair manifest, exact allowlist,
dependency/secret/no-Python scans and an optional fail-closed Authenticode
boundary. `smoke_native.ps1` validates the packaged pair, performs a
network-inert real Host start/normal-exit, then loads the actual manifest-bound
production Engine identity and proves containment, fail-closed no-entitlement
admission, crash/replacement and bounded process cleanup through the managed
IPC runner without GTA, capture, input or network. Explicit
`-DevelopmentUnsigned` acceptance is green but does not change authority.
Отдельный compile-isolated `developer-full-access-unsigned` local-access bundle
снимает только внешние licensing/entitlement и signed startup
availability/update-block admission gates и не является production evidence.
Production binary, ordinary manifest reader и local maintenance отвергают его;
game build, memory/window/capture, foreground, input и final safety gates в нем
остаются обязательными. Контракт и no-replay recovery зафиксированы в
[ADR-0002](ADR-0002-DEVELOPER-FULL-ACCESS-AUTHORITY.md).
Both machine-readable cutover flags are true. Production-signed distribution
still requires certificate/timestamp inputs plus the signed normal-launch/live GTA/install/
update/interruption/rollback acceptance matrix. See
[native release pipeline](NATIVE_RELEASE_PIPELINE.md).

The repository-wide source-ownership gate is wired into `test_dotnet.ps1`,
`test_ipc.ps1`, `package_native.ps1` and `smoke_native.ps1`. It inventories all
tracked and nonignored product files, rejects Python/PySide/Nuitka/legacy
composition, and keeps the final two-EXE allowlist/dependency scan. Current
inventory is zero repository-owned `.py` and wheel files; the legacy source
root, package metadata, test/build scripts and wheelhouse are absent.

## Отдельные inherited failures

Legacy Tesseract invocation и expired Python license test fixture были удалены
вместе с legacy test owner. Current managed/native expiry validation остается
fail closed и покрывается отдельными signed fixture gates.
