# Sonar Fishing production cutover checklist

Статус: активный code-backed checklist до нуля

Дата проверки: 2026-08-22

## Граница результата

Финальный runtime и bundle состоят только из WPF/C# Host и C++20 Engine.
Python, PySide6, Nuitka, interpreter/DLL, wheel, product Python source и
`--legacy-engine` запрещены в shipping graph. Исполняемые legacy tests/oracles
удалены; parity corpora сохранены только как language-neutral nonshipping
fixtures.

Статусы ниже означают:

- **done offline** — порт и deterministic parity готовы, но production
  authority еще не переключен;
- **partial** — существует только часть observable contract;
- **pending** — production-owned capability/page отсутствует;
- **removal** — legacy путь должен исчезнуть после accepted parity/cutover.

## C++ Engine capabilities

| ID | Цельная capability | Текущий статус | Gate до production authority |
| --- | --- | --- | --- |
| `E00` | Common-owned dual-pipe connect, PID/session/handshake, framing | **done offline** | принять production supervisor/liveness API Common; не копировать mechanism в продукт |
| `E01` | Catch quality classification | **done offline** | потребить внутри полного catch episode; удалить diagnostic command из production schema |
| `E02` | Selected-fish catch disposition | **done offline** | держать policy revision и final input gate внутри Engine catch episode |
| `E03` | In-memory session statistics/prices/tackle projection | **done offline** | обновлять из real native state machine и публиковать bounded aggregate events |
| `E04` | Fish identity + aggregate catch observation | **done offline** | подключить real native OCR detector corpus/output, не выставлять fine RPC |
| `E05` | Long-lived Engine process lifecycle, heartbeat, sequence, bounded event queues, reconnect/terminal cleanup | **done offline** - one product supervisor owns a Common Job-contained dual-pipe generation, serialized commands, bounded heartbeat deadline, rolling 3-failure/1-minute restart circuit and terminal cancellation. Unit coverage proves healthy reuse, one crash replacement, open-circuit admission, caller cancellation, uncontained rejection and concurrent stop; an integration gate kills the inert Engine and proves a new contained PID with the full settings revision. The cancellable event writer preserves priority/latest saturation and drain semantics | consume the same supervisor under production authority; repeat crash/recovery and pressure gates against the signed release pair |
| `E06` | Revisioned immutable runtime settings/policy application | **done offline** - persisted Host snapshot maps whole over IPC; invalid/equal/stale and semantic hotkey conflicts reject atomically | consume actual settings revision at production session boundary; runtime mutation/reconnect corpus |
| `E07` | Signed short-lived entitlement verification and side-effect gate | **partial** - exact raw HTTP bytes pass independently through frozen Common managed 0.1.3/native 0.1.2 verifiers and duplicate-safe product claim parsers; product/machine/bundle/policy/features/expiry/generation and replay gates are green against one shared signed fixture | exact production Keygen RSA public key/key id are absent, so both production policies remain intentionally invalid and automation admission is blocked; add real activation/refresh/cache/revocation lifecycle without network in offline gates |
| `E08` | Whole fishing lifecycle state machine and stage transitions | **partial** - pure Engine owner covers whole episode selection, deferral, chat, stop/error cleanup | complete effective override replay corpus, Engine composition and signed entitlement input; no Host fine RPC |
| `E09` | GTA process/window/client-area ownership and focus gate | **partial** - exact frozen `SonarPlatformWindows 0.1.1` supplies least-rights process generation and coherent foreground/client snapshot; product preflight composes it without local Win32 copy | product target resolver/profile, real observation adapters and guarded live-readiness gate; no GTA attach has run |
| `E10` | Capture source and frame ownership | **partial** - product GDI client capture converts one coherent Common window snapshot into owned BGR24, validates identity/geometry before and after `BitBlt`, advances a non-replayable sequence and fails closed on every resource/target change; production composition remains disabled | connect through the versioned target resolver only after readiness, prove real multi-resolution/DPI replay and capture-loss recovery for all detector consumers; no Python/OpenCV shipping dependency |
| `E11` | Memory readers: reeling, inventory, player status/chat evidence | **partial** - product C++20 owns pure legacy-parity decoders and one 96-region/1-MiB coherent aggregate; frozen Common supplies least-rights exact reads, while Fishing validates exact executable names/SHA-256, profile revision, non-replayed sequence and both `(pid, creation time)` generations before/after; every partial/ambiguous/drift result fails closed and the concrete connector is unwired/default-off | issue an approved signed build/address profile and bounded target resolver, compose only the aggregate inside the whole Engine episode, then prove guarded multi-build/target-loss behavior; no live GTA attach has run |
| `E12` | Input controller and crash-safe action ownership | **partial** - product policy orders entitlement/settings/lifecycle checks and consumes Common `input_packet_budget`; the default-off Win32 chat sink enforces exact packet shape, complete pulse batches, partial-prefix key/button release cleanup, strict UTF-16 clipboard ownership and cancellable pauses behind one immediate final gate | connect the same exclusive lease to every Engine input episode, prove hard-crash/restart cleanup and signed production admission; real adapter remains unwired |
| `E13` | Casting, hooking and atomic reeling episodes | **partial** - one coarse cancellable C++ Engine operation now consumes coherent E14 stage/semantic-cue plus exact-same-cycle E11 memory observations, freezes profile/process generations, preserves bounded legacy timing, reuses the native reeling policy, sends typed Space/A/D intents through one exclusive session with exact-sequence settings/entitlement/lifecycle/window/input final gates and always attempts bounded cleanup; the only ready adapter is disabled | add authentic cast/hook cue corpora and signed E11 profile/resolver, compose the shared guarded live lease only after readiness, then prove target loss, hard-crash key release, real multi-build confirmation and release allowlist without Host step/frame RPC |
| `E14` | Trigger, catch screen and tackle/item-info CV/OCR | **partial** - native stage detector preserves five-trigger precedence and matches all 30 exact SHA/size-pinned FHD/2K/4K screenshots; ten gray8 templates are embedded language-neutral assets, normalized geometry has no screen-coordinate constant, and no Python/OpenCV/loose model is required | compose guarded capture only after readiness; port catch-screen and tackle/item-info OCR/native alternatives with frozen corpora, then consume all observations inside whole episodes rather than Host/frame RPC |
| `E15` | Inventory/menu/store-fish episode | **partial** - one native Engine-owned episode now dismisses the game menu, exits non-reeling stages, opens inventory with two bounded attempts, selects canonical item identities at `>=0.90`, confirms context/remove targets against fresh monotonic observations, tolerates inventory reflow, closes inventory, optionally resumes fishing and performs bounded cleanup; every intent carries the exact observation sequence to one final mutation port, while the shipping adapter remains disabled | compose the E14 item/menu observer and the shared exclusive input lease only after entitlement/readiness; prove target loss, hard-crash cleanup and real multi-resolution confirmation without adding Host/frame/step RPC |
| `E16` | Meal/player-status recovery episode | **partial** - one coarse native maintenance operation now consumes E11 status/HUD evidence inside the E15 session, preserves `irp -> donut -> cocktail`, confirms exact consume/backpack movement, bounds 10 consumes/5 moves, closes for HUD confirmation and maps all depleted outcomes through the same exact-sequence final port; offline adapter remains disabled | compose product detector/E11 evidence and the shared exclusive live lease only after entitlement/readiness; prove real stacked-item confirmation, target loss and hard-crash cleanup without Host step/frame RPC |
| `E17` | Garbage disposal episode | **partial** - one coarse native maintenance operation now applies the existing stable confidence policy, recomputes normalized targets after every reflow, requires exact instance disappearance plus selected-count decrease and bounds disposal to 128 confirmed items through the E15 final port; offline adapter remains disabled | compose product candidates and the shared exclusive live lease only after entitlement/readiness; prove real multi-resolution reflow/target loss and crash cleanup |
| `E18` | Bait/tackle depletion and equipment policy | **partial** - one coarse native maintenance operation now owns obscured-scan retries, two-fresh-read depletion confirmation, warnings/terminal outcomes, effective bait cooldown, bounded ~5-second stage exit, reeling interruption and 10-attempt restart through the E15 final port; offline adapter remains disabled | compose product tackle/trigger observations and the shared exclusive live lease only after entitlement/readiness; prove terminal/process-loss cleanup and multi-resolution live confirmation |
| `E19` | Game chat focus/capture/type/confirmation | **partial** - one native coarse episode owns open/close/clear/tab/send sequencing, bounded confirmation, normalized geometry, exact prefix restore and slash-command bypass. The native detector has no OpenCV/OCR runtime and matches all 12 exact SHA/size-pinned legacy screenshots. Coherent GDI capture and a default-off Win32 mutation sink now cover observation through complete key/hotkey/click pulse, strict clipboard write, cancellable pause, immediate final gate and partial-prefix release cleanup under one move-only lease | connect guarded production composition only after entitlement/readiness, connect every other Engine input episode to the shared lease, prove real terminal/hard-crash recovery and add authentic non-1920 multi-resolution corpus; no fine Host RPC |
| `E20` | Aggregate runtime events/audio/tackle/session feed | **partial** - one coarse revisioned snapshot includes totals, fish rows, prices, catch-size buckets and tackle; Host bounded recent-event model retains 400/presents 80; Engine sends it through a Common latest-only buffer while safety/lifecycle frames use strict priority queues and explicit saturation | replace inert zero-state with bounded revisioned real events; add typed safety/lifecycle event producers and audio adapter |

## C# Host capabilities

| ID | Host-owned capability | Статус | Gate |
| --- | --- | --- | --- |
| `H00` | Runnable .NET 10 WPF EXE, explicit demo/offline composition | **done offline** | production mode remains absent until `E05-E20` accepted |
| `H01` | Contained Engine launch, Job assignment and offline handshake | **done offline** | adopt final Common long-lived pair/gate/liveness APIs and restart policy |
| `H02` | `config/state.dat` schema, migration, DPAPI secret handling, atomic writes | **done offline** - real WPF startup owns exact path and fails closed | settings-page save/revision lifecycle and install/activation/crash/update bundle matrix; no legacy loose JSON |
| `H03` | License activation/refresh, entitlement issuance and feature policy | **partial** - Host retains an immutable raw signed response envelope, verifies Common transport before JSON claims, and sends the same raw bytes through one coarse Engine command; no key/raw response enters logs or persisted state | production HTTPS raw capture, exact RSA trust root, secure short lease/cache/refresh/revocation and UI activation remain pending |
| `H04` | Startup availability/update block and safe navigation | **done offline / partial production composition** - bounded HTTPS-only client preserves the legacy request contract; Common 0.1.3 verifies exact Ed25519 canonical bytes; malformed, tampered, oversized and unsafe-navigation responses fail closed; initial admission, shared-kit loader/blocked surface and sequential five-minute runtime monitor are separately tested with fixed signatures and fake transports | wire coordinator/monitor into the future production composition and run guarded endpoint acceptance only after release authority exists |
| `H05` | Hotkey capture/conflicts/suppress-until-release | **done offline / partial production activation** - Common 0.2.13 `HotkeyGesture`/`HotkeyCapture.Shortcut` preserves unmodified product keys, C#/C++ canonical semantic conflict gate is green, WPF blocks save with a Common warning state, and a product state machine preserves rising-edge, capture suppression until full release, ineligible reset and stopping-notice behavior; the separate Win32 state reader is default-off and only its deterministic VK mapping is tested | bind the reader to a bounded cancellable Host lifecycle and one coarse entitlement-gated start/stop command, then run authorized real key-state/reconfiguration/shutdown acceptance |
| `H06` | Telegram settings, availability, polling/notifications/commands | **done offline / partial production activation** - Host owns credential-safe settings/state, bounded HTTPS client, ordered long poll, cancellable/reconfigurable generation, exact router/admin/callback allowlists, callback new/edit/ack semantics, 7+7 reducer, media/statistics/tackle planners, HTTPS stream links and capability-gated product/stream dispatch under offline fakes; token is redacted and never enters logs/snapshots/Engine IPC | licensed production run mode, real `ITelegramProductUseCases` adapters and live Telegram acceptance; demo/offline composition remains network-denied and action-inert |
| `H07` | Streaming settings and FFmpeg/HLS/cloudflared lifecycle/chat mode | **done offline / partial production activation** - one coarse revisioned controller owns embedded-only tool admission, Common Job-contained encoder/tunnel order, authenticated-loopback boundary, bounded start/stop/retry/restart/autostop/cleanup and exact 480/720/1080 + 30/10-FPS policy; 11 fake-only lifecycle tests are green | freeze/embed signed tool payloads, implement guarded capture + authenticated viewer/network + chat adapters, wire licensed production composition, then run authorized process/network and crash-recovery/two-EXE gates; see [H07 runtime](H07_STREAMING_RUNTIME.md) |
| `H08` | Update/download/activation unit, uninstall and rollback | **done offline / partial production activation** - exact Ed25519-signed manifest, HTTPS headers-only source, byte/hash-bounded staging, monotonic version+generation, transactional three-file swap, exception/crash rollback, exact steady-state allowlist and confirmation-gated uninstall plan are green under fake filesystem/transport tests | production public key/metadata endpoint, licensed composition, signed after-exit activator/uninstaller and complete installed two-EXE update/interruption/rollback matrix; see [H08 transaction](H08_RELEASE_TRANSACTION.md) |
| `H09` | Logs/in-memory events and diagnostics | **done offline / partial production composition** - recent events retain 400/present 80 and clear atomically; Host startup/exit writes redacted JSONL through a 4 x 1 MiB rotating owner under exact `logs/`, rejects unsafe/reparse roots, and the About-page clear action deletes only exact `sonar*.log` generations | route remaining typed runtime failures/events through the same sink and repeat crash/allowlist/secret scans on the signed bundle |

## WPF page parity

Точный observable ledger находится в [UI_PARITY_LEDGER.md](UI_PARITY_LEDGER.md).
До cutover должны закрыться все строки ниже; helper `DEAD-01` не переносится.

| ID | Page/shell | Статус |
| --- | --- | --- |
| `U00` | 8-item shell, branding, version/update/license regions, feature redirect, nested scroll policy | **done offline** — Common 0.2.13 AppShell/AppBrand, embedded Fishing logo, exact 8-item catalog, feature redirect, navigation footer and responsive page scroll are composed; production license/update sources remain separate rows |
| `U01` | Startup loader/blocked surface | **done offline** - embedded Fishing logo, Common Card/StatusBadge/ProgressBar/ActionButton and shared hyperlink style preserve checking, blocked and unavailable states; download command repeats HTTPS/no-userinfo validation and the surface remains outside the main shell |
| `U02` | Обзор: fishing control, system, session, Telegram, stream, recent events | **partial** — full Common composition and bounded event/session projections exist; stream and live system authority remain inert |
| `U03` | Лицензия activation/account surface | **partial** — account/activation composition exists and unvalidated state shows a neutral em dash instead of internal `legacy` migration copy; real managed activation/refresh remains `H03` partial |
| `U04` | Рыбалка control/status/preview/system/session/tackle | **partial** — real inert C++ session aggregate, без live preview/actions/full tiles |
| `U05` | Настройки behavior/depletion/thresholds/fish/hotkeys/uninstall | **partial** — state.dat atomic save, dependencies, 31-fish embedded selector, bulk actions, Common 0.2.13 styled inputs/wheel-safe combo (including `DisplayMemberPath` selection projection), threshold sliders and plain-letter hotkey conflict UX are composed; H08 provides an exact-confirmation safe uninstall plan, while after-exit execution remains pending |
| `U06` | Статистика current-session metrics/table/prices/chart/reset | **done offline / partial authority** — populated responsive Common DataGrid, embedded fish images, six metrics, chart, atomic custom-price revision and coarse reset contract are green; production Engine reset/source is not wired, history/CSV intentionally absent |
| `U07` | Стрим page | **done offline / partial production activation** — responsive Common page preserves status/area/quality/autostop/URL, start/stop/chat commands, quality/chat zoom/10-FPS settings and four metrics from one typed snapshot; the H07 lifecycle controller now has fake-backed offline acceptance | production composition intentionally still supplies the fail-closed unavailable adapter until embedded tools, guarded capture, authenticated viewer/network and chat bridge pass their gates |
| `U08` | Telegram page | **done offline / partial production activation** — Common composition, credential editors/icons, settings, router/polling/planners, cancellable transport generation and guarded dispatch are green; demo/offline remains network-denied and concrete production use cases remain `H06` |
| `U09` | О программе/update/uninstall | **done offline / partial production activation** — Common composition and product copy exist; H08 verifies and stages one signed monotonic three-file release and provides rollback/uninstall plans, while production endpoint/key, licensed wiring and after-exit execution remain pending |

UI completion gate currently renders 180 deterministic offscreen STA screenshots:
all 8 pages at 100/125/150/200% for compact/medium/expanded content plus
responsive threshold-slider, fish-selection, hotkey-conflict and startup
checking/blocked/unavailable variants. They are compared against current legacy screenshots and
[UI_PARITY_LEDGER.md](UI_PARITY_LEDGER.md). Tests must cover keyboard/focus,
automation names, wrapping/clipping, mutable tones and Common primitive usage.
No live GTA/network/input/window launch is allowed for this visual gate.

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
Production remains blocked until both machine-readable cutover flags are true,
signing inputs are present and the signed install/update/interruption/rollback
matrix is accepted. See [native release pipeline](NATIVE_RELEASE_PIPELINE.md).

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
