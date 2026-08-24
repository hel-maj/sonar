# Sonar Fishing Engine migration

Статус: native source/build/runtime cutover выполнен. WPF/C# Host и C++20
Engine являются единственным product runtime; no-argument launch выбирает
manifest-bound production composition без Python. Оставшиеся задачи относятся
к live GTA acceptance, незавершённым Telegram/streaming adapters, production
Authenticode и remote signed activation/install/update/uninstall/rollback,
а также release evidence, а не к возврату legacy runtime.

Ниже сохранён исторический implementation log: Phase 1 Python isolation,
Phase 2 C++ offline parity, Phase 3 inert WPF shell, Phase 4 offline Host/Engine IPC, Phase 5 Common
boundary hardening, Phase 6 catch-disposition parity, Phase 7 product UI parity
ledger и inert session summary, Phase 8 runnable offline WPF Host, Phase 9
nonshipping Python characterization seam, Phase 10 native session statistics +
real offline WPF snapshot, Phase 11 native fish identity/catch observation,
Phase 12 Common 0.1.1/runtime settings/state.dat/lifecycle, Phase 13 native
reeling replay policy, Phase 14 native meal/player-status recovery policy,
Phase 15 aggregate Statistics Host projection, Phase 16 native garbage
disposal policy, Phase 17 native equipment-recovery policy, Phase 18 managed
Telegram settings/state parity, Phase 19 inert Telegram inbound/menu protocol,
Phase 20-22 Common UI/statistics/Windows safety, Phase 23 Host streaming
snapshot/controller/page union, Phase 24 long-lived contained Engine session +
independent signed-entitlement verification, Phase 25 bounded cancellable
event delivery, Phase 26 native game-chat episode, Phase 27 bounded Engine
supervisor recovery, Phase 28 native chat detector/capture observation,
Phase 29 cancellable Telegram Host lifecycle, Phase 30 default-off native
chat mutation boundary, Phase 31 bounded signed startup admission and Phase 32
bounded embedded-only Host streaming lifecycle, Phase 33 native fishing-stage
visual detection, Phase 34 signed Host release transaction core, Phase 35
native inventory/menu/store-fish episode, Phase 36 native coherent memory
observation plus separated inventory-state recovery/characterization, Phase 39 native whole fishing episode, Phase 40 native
meal/garbage/equipment whole episodes, Phase 47 compile-isolated local-access
authority и Phase 48 bounded typed notification stream. Эти phase-описания
исторические; текущий
authoritative статус capability находится в
[production cutover checklist](PRODUCTION_CUTOVER_CHECKLIST.md).

Дата аудита: 2026-07-23

Дата последней implementation проверки: 2026-08-24

Managed migration builds pin .NET SDK 10.0.400 through root `global.json`;
package/feed hashes remain enforced by the product-owned test entrypoints.

Product decision: [ADR-0001](ADR-0001-WPF-CSHARP-CPP-ENGINE.md)

## 1. Проверенный baseline

- `src/sonar`: 88 Python files, около 35 575 физических строк.
- `tests`: 41 file, около 11 913 строк и 565 `test_*` functions.
- PySide runtime surface концентрирован в нескольких files, но
  `src/sonar/ui/main_window.py` имеет 4513 строк и является composition root.
- На момент baseline C#, C++, XAML и versioned IPC schema отсутствовали. Это
  только исторический baseline: текущий checkout содержит shipping WPF Host,
  C++ Engine, typed IPC, normal no-argument production mode и отдельные явные
  demo/offline diagnostics. Python product source и production composition
  удалены из target graph.
- Worktree был dirty до аудита; существующие изменения не являются частью
  этого документа.

Repository-wide inventory/import graph дополнен deep-read UI composition,
runtime owners, hot loops, hidden overrides, tests и build entrypoints. Перед
каждым slice owning module и его tests читаются повторно целиком.

## 2. Current traps

### MainWindow как composition/application owner

`ui/main_window.py:417` создает config, license, stats, history, bot, game chat
и streaming. UI около `:3111` сам проверяет license, запускает bot через
`skip_license_check=True` и читает private `_brain_thread`.

Target:

- `AppBootstrap` создает concrete Host services;
- ViewModels получают application ports;
- `EngineSessionService` владеет process/pipe lifecycle;
- UI не читает Engine internals.

### Hidden effective behavior

`fishing/__init__.py:3` устанавливает import hook, а
`fishing/bot_adjustments.py:54` заменяет методы `FishingBot`.
`chat_wip_gate.py:50` monkeypatch-ит UI, streaming и Telegram.

До порта нужен effective method/override manifest и characterization traces.
Текст одного `bot.py` не является полным source of behavior.

### Несколько config owners

`config/manager.py:18` load-ит и записывает три JSON files, а
`fishing/bot.py:1752` повторно читает config в catch path.

Target:

- C# Host single persistent writer;
- full immutable `ApplyRuntimeSettings(revision, snapshot)`;
- Engine accepted revision и atomic apply;
- no per-field config RPC и no Engine file reads.

## 3. WPF/MVVM decomposition

### Common UI platform consumption boundary

Общий UI kit является самостоятельной платформенной целью для всех Sonar
products, а не только местом удаления уже найденных duplicate controls. Sonar
Common владеет design tokens, themes, typography, spacing, generic controls,
accessibility, responsive behavior и visual regression kit. Fishing потребляет
versioned Common UI packages и владеет product composition, content, state,
branding и Fishing-specific behavior.

Расширение generic primitive выполняется через его documented semantic surface
или Fishing-owned composition/wrapper. Fishing не копирует shared primitive и
не теряет уже подтвержденные product extensions. Проверенный product delta и
parity rules находятся в `UI_PRIMITIVE_DELTA.md`; этот inventory является input
для платформенного design, но не Common implementation внутри Fishing repo.

ViewModels:

- `ShellViewModel` - navigation;
- `OverviewViewModel` - aggregate application snapshot;
- `FishingViewModel` - Start/Stop, phase, player/tackle, preview presentation;
- `SettingsViewModel` - editable draft, validation и Save;
- `StatisticsViewModel` - volatile current-session projection;
- `LicenseViewModel` - activation/status;
- `TelegramViewModel` - settings/connection state;
- `StreamingViewModel` - stream state и coarse chat commands;
- `AboutViewModel` - version/update/uninstall presentation.

Host services:

| Current responsibility | Target owner |
| --- | --- |
| Concrete service creation/callback wiring | `AppBootstrap` |
| Start/stop/stopping detection | `FishingControlUseCase` + `EngineSessionService` |
| License/startup block | `LicenseSessionService` |
| JSON config | `SettingsStore` |
| History/statistics/CSV | Legacy behavior is characterized, then persistent history/export is removed; session projection stays in memory |
| Global OS hotkeys | `GlobalHotkeyService` |
| Preview/screenshot request | `EngineArtifactService` |
| Telegram HTTP | C# `TelegramService` |
| FFmpeg/cloudflared/HTTP | C# `StreamingOrchestrator` |
| Game chat focus/click/type | C++ Engine |
| Shutdown/uninstall | `ApplicationLifecycleService` |
| Timers reading bot private fields | push snapshots and Host schedulers |

Current UI timer cadence является baseline observation, не основанием для
property-level polling. Pipe snapshots coalesce, ViewModels не запрашивают
каждое field отдельно.

## 4. Capability owners и slices

### F0. Bootstrap/supervision

Current: `app.py` + `MainWindow` + worker threads.

Target: WPF Host создает secured pipes, запускает exact signed Fishing Engine,
проверяет PID/build/schema и владеет Job Object. Engine владеет runtime epoch и
cleanup.

Gate: inert lifecycle, ACL, mismatch, saturation, disconnect, graceful
shutdown, forced unknown cleanup и indefinite capped read-only restart recovery.

### F1. Settings/hotkeys

IPC:

- `ApplyRuntimeSettings(full_snapshot, revision)`;
- accepted/rejected revision in aggregate Engine snapshot.

Persistence schema, atomic replace и legacy filename migration тестируются до
cutover. Physical gameplay keys остаются Engine gates; global UI hotkeys Host.

### F2. Licensing

Host владеет activation/network/cache/UX. Backend выдает signed short-lived
entitlement. Engine проверяет signature, product/build/feature/expiry перед
automation. Boolean `licensed=true` запрещен.

Current Keygen `LicenseStatus` и startup-block signature не являются готовым
Engine lease. Нужны audience/build/machine binding, offline grace, revocation и
key rotation semantics.

### F3. Fishing state machine

`FishingBot` и effective overrides фиксируются traces из
`tests/test_bot_behaviour.py`.

Coarse contract:

- `StartFishingSession`;
- `StopAutomation`;
- `RequestPlayerStatusScan`;
- `FishingSessionSnapshot`;
- `PhaseChanged`, `CommandRejected`, typed domain facts/faults.

Implementation выбирается до session start. Hot switch запрещен.

### F4. Window/capture/memory/input

Process handles, HWND, GDI/capture, memory reads, foreground validation и
`SendInput` находятся только в C++ Engine. Host может запросить bounded artifact,
но не `CaptureFrame` runtime service.

Два input adapters не запускаются. Host не является fallback input owner.

### F5. Casting/hooking/reeling

Current evidence:

- reeling requested control interval около 5 ms в
  `fishing/memory_reeling.py:42`, loop около `:366`, input около `:797`;
- casting requested poll около 1 ms и short Space tap в `fishing/bot.py:121`
  и `:1474`;
- preparation/storage/tackle объединяет capture, recognition, click и
  confirmation около `bot.py:2702` с override `bot_adjustments.py:127`.

Atomic C++ cluster:

```text
memory/capture sample
  -> stabilization/detection
  -> state transition
  -> final focus/physical/config/entitlement gate
  -> input
  -> confirmation/retry/cleanup
```

RPC `ReadTension`, `DetectHook`, `PressA`, `PressD`, `CastStep` запрещены.
`tests/test_memory_reeling.py`, action traces и p50/p95/max/missed deadlines
являются gates. Configured waits сами по себе latency не доказывают.

Temporary native module внутри Python LegacyEngine допускается только как whole
loop с coarse run/cancel/snapshot. Он не вызывает Python per sample, не считается
protection boundary и удаляется при Engine executable cutover.

### F6. CV/OCR

Runtime frame, ROI, candidates и detector chain остаются Engine-internal. Host
получает semantic result или сам выдает `ArtifactGrant` для preview/debug.
Host заранее создает file object и передает минимальный process-local duplicated
write capability. Engine возвращает opaque ID/metadata без path; Host проверяет
identity, reparse/hardlink, size/hash/type/expiry на retained handle того же file
object.

OpenCV/Tesseract versions и fixture corpus замораживаются. Сначала выполняется
language parity legacy geometry, затем отдельный resolution-independent
remediation. OCR/interpolation/threshold behavior и язык не меняются вместе.

### F7. Session statistics/catalog/audio

Engine публикует bounded in-memory events только для текущей process session.
Host обновляет volatile statistics projection и может воспроизвести configured
audio, но не создает history/CSV/outbox:

- `SessionStarted`;
- `CatchResolved`;
- `TackleScanCompleted`;
- `SessionStopped`.

Disconnect/crash во время side-effect session делает всю активную session
`OperationOutcomeUnknown`. Новый Engine не продолжает и не replay-ит side
effects. Read-only reconciliation не придумывает terminal result; новая
side-effect session требует нового explicit user intent.

### F8. Game chat

Detect -> focus -> click/type -> confirmation является одной Engine operation.
Host отправляет enter/exit/select/send/clear coarse commands. `SendChatMessage`
не replay-ится после ambiguous disconnect.

Chat остается WIP и не объявляется required production parity без отдельного
product decision.

### F9. Telegram/streaming

Telegram API/token и FFmpeg/cloudflared/HTTP остаются C# Host adapters. Remote
intent проходит тот же use case, а Engine повторно проверяет entitlement/safety.
HLS/video не пересылается через Engine pipe.

Current mutating streaming chat endpoints требуют authentication/privacy review
до переноса public tunnel behavior.

### F10. Build/protection

Final Fishing steady-state tree строго ограничен:

```text
Sonar.exe
Sonar.Engine.exe
bundle-manifest.json
config/
  state.dat
logs/
  *.log
```

`Sonar.exe` - framework-dependent `.NET 10` single-file с explicit Desktop
Runtime prerequisite и без `%TEMP%\.net` extraction. XAML/BAML, managed
resources, native dependencies, layouts/models/templates/catalogs встроены в
два signed EXE. Loose DLL/assets/data/SQLite/PDB/dumps/history запрещены.

External signed manifest содержит opaque IDs, required runtime, versions и
Host/Engine/schema/content hashes. File-level/delta download разрешен, но
activation всегда переключает whole verified pair. Staging/backup temporary и
удаляются после success/failure recovery; поздний rollback re-download-ит
предыдущий personalized bundle.

Mandatory allowlist release test выполняется после install, first activation,
normal launch/exit, crash recovery, successful update, interrupted update и
remote rollback. Любой лишний path, stale staging/backup либо изменение
`%TEMP%\.net` валит release.

Current `scripts/build_secure.ps1`/Nuitka path остается release authority до
фактического acceptance нового product-owned pipeline.

## 5. Ordered product migration

1. Behavior/override/config/performance/visual freeze.
2. In-process Python `EngineFacade` без behavior change.
3. C++ offline/read-only domain capabilities и aggregate state против Python
   oracle; никакого shipping Python transport.
4. WPF/MVVM Host против contained inert C++ Engine и Host-only services.
5. Native window, capture, memory, detectors и immutable settings/entitlement.
6. Whole native reeling/state-machine/input episode parity.
7. Standalone C++ Engine authority switch только между sessions.
8. PySide/Python production/Nuitka removal и no-Python bundle scan.
9. Signed App+Engine release, update, uninstall и rollback drill.

## 6. Проверенное состояние Phase 1 - Phase 19

### Phase 1 - Python isolation

- Effective import-hook и monkeypatch surface зафиксирован в
  `docs/migration/effective-python-behavior.json`; regression test сверяет
  manifest с фактическими assignments и dynamic `setattr` method set.
- `src/sonar/fishing_session` вводит immutable `EngineSessionSnapshot`, coarse
  `EngineFacade` и `LegacyEngineFacade`. `FishingBot` остается единственным
  production owner behavior, threads, state и side effects.
- Минимальный Qt control path start/async-stop/status использует facade.
  Остальные direct bot consumers, config loading, preview, chat и notification
  wiring остаются явно transitional и не объявляются migrated.
- `UI_PRIMITIVE_DELTA.md` фиксирует shared visual semantics и Fishing-specific
  extensions относительно Hunting и Poker до проектирования WPF/Common UI.
- На завершении Phase 1 C#, C++, XAML, product `.proto` и Common package
  references еще не были добавлены.
- Canonical skill audit выполнен: product commands, entrypoints и live/release
  gates в этом slice не изменились, поэтому `sonar-fishing-workflow` и
  `sonar-ecosystem-workflow` пока не требуют обновления.

Пункты 1 и 2 ordered migration выполнены частично. Config/performance/visual
freeze и полный composition-root isolation остаются отдельными gates.

### Phase 2 - offline catch-quality classifier

Первым native slice выбран не helper, а целостная read-only domain capability:
классификация OCR-текста качества улова, exact mapping label <-> stable key и
unknown fallback.

Owner и dependency direction:

- production oracle и единственный runtime owner остается
  `src/sonar/fishing/catch_quality.py`;
- реальные Python consumers остаются `fishing/catch_screen.py` и
  `fishing/statistics.py`;
- candidate implementation находится в `native/catch_quality` и собирается в
  C++20 static library target `SonarFishingCatchQuality`;
- native target не подключен к Python, WPF, Engine executable, UI, GTA, capture,
  memory, input, network, IPC или Common;
- UI palette `CATCH_SIZE_COLORS_BY_KEY` не переносилась: это presentation
  ownership, а не часть native classifier.

Shared deterministic corpus
`tests/fixtures/catch_quality/legacy_oracle.tsv` проверяется как effective
Python implementation, так и plain CTest harness. Corpus фиксирует null/empty
semantics, OCR fragments, punctuation removal, Cyrillic case normalization,
unknown whitespace fallback, classifier priority и exact key/label mapping.

Build и focused parity gate из `native`:

```powershell
cmake --preset windows-msvc-v143
cmake --build --preset windows-msvc-v143-release
ctest --preset windows-msvc-v143-release
```

Проверенная конфигурация: Visual Studio 2022, MSVC 19.44, toolset v143, x64,
C++20. CMake запрещает другой compiler/toolset, не использует FetchContent и не
выполняет network/install. Build output находится в ignored
`build/native/windows-msvc-v143`.

Migration gate: native classifier может получить production consumer только
как часть будущей целостной Engine-owned catch-resolution capability после
расширения corpus реальными OCR observations, differential parity, Engine
composition tests и отдельного authority decision. Вызов C++ classifier из
текущего Python hot path или новый fine-grained IPC request этим slice не
разрешены.

Removal gate:

- Python implementation нельзя удалить, пока standalone Engine не станет
  единственным accepted owner catch-resolution для production, Host не перестанет
  иметь Python consumer и не пройдет stable rollback window;
- offline C++ candidate удаляется, если следующий whole-capability slice не
  может потребить его без разделения OCR/classification invariant; shared corpus
  при этом сохраняется как characterization evidence;
- local duplicate UI primitives удаляются только после consumption Common UI
  package с visual, interaction, accessibility и responsive parity.

Known Common 0.1.0 package/target names не создают dependency этого pure slice:
`Sonar.Platform.Ipc.Contracts`, `Sonar.Platform.Ipc.NamedPipes`,
`Sonar::PlatformIpcContracts` и `Sonar::PlatformIpcTransport` здесь намеренно не
referenced. Product IPC DTO также не добавлялся.

Canonical skill audit Phase 2: `sonar-ecosystem-workflow` уже покрывает language
ownership и offline parity. `sonar-fishing-workflow` пока описывает только
Python product workflow и потребует Container-owned update до объявления native
workflow стандартным. Container не изменялся в этом product-only slice.

### Phase 3 - historical inert WPF Engine-status shell

Product-owned .NET 10 WPF consumer находится в
`src/dotnet/Sonar.Fishing.Host`. Phase 3 начинался как inert class
library без runtime composition; текущее Phase 30 состояние уже
имеет runnable explicit demo/offline WPF EXE, но production authority все
еще не переключен.

Dependency direction проверена по restore assets:

```text
Sonar.Fishing.Host
  -> exact PackageReference Sonar.UI.Wpf [0.2.19]
  -> Phase 4 Platform IPC PackageReference, currently pinned [0.1.1]
  -> product Sonar.Fishing.Ipc.Contracts ProjectReference
  -> Microsoft Windows Desktop Runtime/SDK references
```

`ProjectReference` или source copy из Common отсутствуют. Product-local
`ProjectReference` на Fishing contracts добавлен только в Phase 4. Текущий
UI package 0.2.19 проверен из accepted feed с SHA-256
`37BE4E2FB5C38B400640D3EB5CF91DC54BB8052C09D9C50BD67DBFE40F3AEB33`.
Phase 3 WPF tests ссылаются через `ProjectReference` только на product Host
project.

Feed выбирается в порядке:

1. MSBuild property `CommonFeed`, переданная script parameter `-CommonFeed`;
2. environment `SONAR_COMMON_FEED`;
3. workspace development fallback `.artifacts/sonar-feed`, вычисленный
   относительно product root.

Ни product project, ни tests не содержат path к checkout Sonar Common.
`scripts/test_dotnet.ps1` проверяет local hashes всех exact Common packages,
выполняет restore,
Release build и STA test harness. Restore сохраняет стандартные configured
NuGet sources для implicit `Microsoft.Windows.SDK.NET.Ref`; WPF tests сами не
делают network, GTA, process, capture, input или window operations.

Capability-first structure:

- `EngineStatus/EngineSessionSnapshot.cs` - bounded immutable demo snapshot;
- `EngineStatus/EngineStatusViewModel.cs` - pure presentation mapping для
  ready/running/stopping;
- `EngineStatus/EngineStatusScreen.xaml` - product content/composition;
- `FishingSessionState/FishingSessionStateSnapshot.cs` - defensively immutable
  aggregate mapping real inert C++ event для offline composition;
- `Shell/FishingHostShell.xaml` - responsive product shell region;
- `tests/dotnet/Sonar.Fishing.Host.Tests` - plain STA WPF contract harness.

Shell загружает package theme и использует Common `Card`, `StatusBadge`,
`SectionHeader` и `ActionButton`. Fishing владеет текстом, status mapping,
layout composition и presentation state. Demo создает immutable fake snapshot;
offline composition применяет immutable C++ aggregate на UI thread. Common
badge tone обновляется без копирования control template.

Mapping сохраняет текущую admitted-license presentation subset:

- ready: `Ожидание`, badge `Готов`, start enabled;
- running: `Работает`, current detected stage, badge `Активен`, stop enabled;
- stopping имеет priority над running: `Остановка`, warning tone, обе actions
  disabled.

Test gate проверяет exact package assembly/resource contract, mapping,
runtime tone update, отсутствие fixed width, narrow/wide layout, wrapped text,
automation names, heading levels и keyboard tab semantics. Test process создает
STA `Application` только для WPF resource resolution; `Window` и message loop не
создаются.

`CommunityToolkit.Mvvm` 8.4.2 подключен exact `PackageReference`: runnable Host
использует observable page/lifecycle ViewModels и не bind-ит generated IPC DTO
напрямую к XAML.

Migration/removal gate:

- demo fake snapshot/ViewModel не является IPC DTO или production session
  contract;
- offline transport gate применяет только inert C++ snapshot и не является
  production composition;
- Python `LegacyEngineFacade`, PySide UI и Nuitka release остаются production
  owners до отдельных parity, cutover и rollback gates;
- fake preview остается только explicit demo mode; production mode не появится,
  пока composition root не получает полный native snapshot и authority;
  package/resource/mapping/accessibility tests сохраняются как Host regressions.

Skill audit Phase 3: `sonar-ecosystem-workflow` и release safety boundary
актуальны. Появились реальные product-owned .NET entrypoint и WPF source, поэтому
canonical Container copy `sonar-fishing-workflow` теперь требует update triggers
и .NET test gate. `sonar-fishing-release-workflow` не меняется: WPF library не
является release pipeline или accepted `Sonar.exe`. Container/Common не
изменялись в этом product slice.

### Phase 4 - offline coarse Host-to-C++ Engine

Product contract находится в `contracts/ipc/v1/sonar_fishing.proto` и использует
canonical import `ipc/v1/sonar_platform.proto`. Root `Envelope` содержит Common
`EnvelopeHeader`, Common `PlatformPayload` первым typed payload и Fishing-owned
aggregate request/result pairs для catch quality и offline catch disposition.
`Any`, universal `Invoke`, hand-written wire DTO и parallel Common lifecycle DTO
не добавлены.

Aggregate command передает raw OCR text один раз. C++ Engine внутри одной
operation выполняет normalization, stable-key classification и recognized
decision через Phase 2 library. Host не может разделить или переупорядочить этот
invariant. Python implementation остается production oracle; IPC slice не
выполняет OCR и не подключен к catch path.

Dependency direction:

```text
Sonar.Fishing.Host
  -> exact NuGet Sonar.Platform.Ipc.Contracts [0.1.1]
  -> exact NuGet Sonar.Platform.Ipc.NamedPipes [0.1.1]
  -> exact NuGet Sonar.Platform.Processes [0.1.0]
  -> Sonar.Fishing.Ipc.Contracts -> exact Common Contracts [0.1.1]

SonarFishingOfflineEngine
  -> Sonar::FishingIpcContracts
  -> Sonar::FishingCatchQuality
  -> Sonar::FishingCatchDisposition
  -> installed Sonar::PlatformIpcContracts 0.1.1
  -> installed Sonar::PlatformIpcTransport 0.1.1
```

Private Engine executable composition is capability-first inside
`native/engine_ipc/src`: `engine_bootstrap` owns environment admission and
pair identity, `engine_protocol` owns framing/handshake/header validation,
`settings_commands` and `entitlement_commands` own their typed command
mapping, `session_commands` owns start/stop and aggregate snapshot projection,
`diagnostic_commands` owns read-only migration diagnostics, and
`engine_runtime` owns the serialized dispatch loop. `main.cpp` is only the
process entrypoint. These files are compiled into both production and explicit
offline targets with their existing target-specific authority definitions;
they do not add a public library or another runtime owner.

Native CMake использует только immutable installed prefix, переданный через
`SONAR_COMMON_NATIVE_PACKAGE`; Common source/include checkout paths отсутствуют.
Если parameter/environment не заданы, product test entrypoint использует
независимый workspace artifact `.artifacts/sonar-native/0.1.1`, а protoc -
`.artifacts/sonar-tools/protoc/35.1/bin/protoc.exe`; checkout Sonar Common не
является durable build fallback.
Protobuf генерируется exact `protoc 35.1`, C++20/MSVC v143, `/W4 /WX`, без
FetchContent или network. Product-local Win32 framing отсутствует:
`read_framed_payload` и `write_framed_payload`, exact overlapped transfer,
deadline и cancel принадлежат `Sonar::PlatformIpcTransport`.
Native Engine также использует Common `validate_session_header` для commands и
`validate_handshake_acceptance` для Host-authored acceptance; sender role
проверяется как `HOST`.

Deterministic integration gate `scripts/test_ipc.ps1`:

1. проверяет SHA-256 pinned managed packages и installed native prefix;
2. генерирует C# и C++ из одного product schema;
3. проверяет два product wire golden в managed и native harness;
4. создает bounded random current-user pipe и 32-byte nonce;
5. запускает только inert native test Engine, без WPF window;
6. назначает child в Common kill-on-close Job до handshake;
7. Host проверяет PID child, Engine проверяет PID pipe server;
8. Engine отправляет hello, Host согласует protocol 1.0 и запрещает side effects;
9. применяет полный revisioned runtime settings snapshot и проверяет exact
   accepted revision;
10. выполняет Common heartbeat roundtrip и запускает read-only session с
    aggregate snapshot на events channel;
11. выполняет aggregate catch-quality command/result;
12. выполняет pure catch-disposition diagnostic с полным immutable observation
    и selected-fish policy snapshot внутри одного request;
13. Host отправляет Common `ShutdownEngine`, получает `ShutdownReady` и проверяет
   normal process exit.

Gate не запускает Python, GTA, capture, OCR, input, network, game/process attach
или product UI. Native target выключен CMake option по умолчанию и без explicit
`SONAR_FISHING_OFFLINE_GATE=1` завершается fail-closed. Machine-readable
`docs/migration/runtime-authority.json` и Python regression доказывают, что
production composition создает `LegacyEngineFacade(self.bot)`, а Python sources
не ссылаются на offline Engine/Host gate.

Managed package hashes frozen workspace feed `.artifacts/sonar-feed` (его можно
переопределить явно через `-CommonFeed` или `SONAR_COMMON_FEED`):

- `Sonar.Platform.Ipc.Contracts.0.1.1.nupkg` -
  `33137FEBA79D2C7DD980E44189B73CB108231BCC443A2674853A2820466CFBD2`;
- `Sonar.Platform.Ipc.NamedPipes.0.1.1.nupkg` -
  `0CF50FDAFFF00608F0B5742C39A15B3AB24CF79329DA8B07A01404E9F7A45214`;
- `Sonar.Platform.Processes.0.1.0.nupkg` -
  `03DEE12DCB7F2C30A21921A9198CA5388D93A682B8CCE69658CAD0E1996AE5EB`;
- `Sonar.UI.Wpf.0.2.19.nupkg` -
  `37BE4E2FB5C38B400640D3EB5CF91DC54BB8052C09D9C50BD67DBFE40F3AEB33`.

Phase 5 removed temporary Common duplicates:

- managed generator получает canonical schema root из package
  `SonarPlatformIpcContractRoot`; legacy zip extraction и layout staging удалены;
- managed Host использует Common `HandshakeContract` и
  `SessionHeaderContract`; product-local nonce/protocol/capability/header
  validation удалена;
- child назначается в `Sonar.Platform.Processes.KillOnCloseJob` до handshake;
  product-local `Process.Kill` cleanup удален;
- private `engine_ipc/engine_bootstrap.cpp` читает product bootstrap
  environment; это остается product composition до отдельного safe bootstrap
  API. Generic accepted и session-header validation уже принадлежат Common.
  Fishing сохраняет typed command handlers и catch-quality invariant;
- Host сохраняет только product process arguments/environment composition,
  typed Fishing command/result, correlation и operation ordering.

Build scripts используют отдельный ignored NuGet package cache для exact
packages и
после restore повторно сверяют SHA-256 фактически consumed `.nupkg`. Это не дает
старому global cache незаметно подменить repacked package того же ID/version.

Проверенный после Phase 6 gate: CTest 4/4, managed IPC tests 3/3, Phase 3 STA
WPF tests 5/5, Release managed builds без warnings/errors, затронутые Python
regressions 176/176 и `git diff --check`.

Skill audit Phase 4: `sonar-ecosystem-workflow` корректно назначает Common
transport/process/handshake ownership и product schema ownership. Реальный
product-owned `scripts/test_ipc.ps1` расширяет повторяемый Fishing workflow;
canonical Container skill должен получить .NET/native offline test routing,
но release skill не меняется, потому что executable не публикуется и не входит
в release allowlist.

### Phase 6 - catch-disposition parity

Следующим cohesive offline/read-only capability выбрана policy выбора
`keep/release`, ранее встроенная в `FishingBot._do_fish_catch`. Это domain
decision, а не OCR, input или helper. Effective production oracle теперь явно
находится в `src/sonar/fishing/catch_disposition.py`; `FishingBot` вызывает его
перед прежним выбором кнопки и сохраняет существующие log/record/UI side effects.

Зафиксированная exact semantics:

1. `inventory_full` всегда дает release, даже для выбранной рыбы;
2. `None` и пустой ID считаются unrecognized и дают release;
3. любой другой ID сравнивается с selected set точно, case-sensitive и без
   trim/normalization;
4. exact membership дает keep, иначе release.

Shared corpus `tests/fixtures/catch_disposition/legacy_oracle.tsv` содержит 11
детерминированных cases: precedence, null/empty, whitespace truthiness, case
sensitivity, несколько selected IDs и arbitrary truthy ID. Его читают Python
regression и plain CTest target `SonarFishingCatchDispositionTests`.

Candidate implementation принадлежит `native/catch_disposition` и экспортирует
C++20 static library `SonarFishingCatchDisposition`. Library не зависит от
Common, protobuf, Win32, UI, capture, memory, OCR, input, GTA или network.
Production Python path остается oracle и единственным side-effect owner.

Product schema additive расширена typed aggregate
`EvaluateCatchDispositionRequest/Result`. Diagnostic request передает полный
immutable observation: optional fish ID, весь selected-fish policy snapshot и
inventory-full flag. Decision целиком выполняется внутри Engine. Это offline
parity diagnostic, а не production action command: Host не получает и не может
делегировать через него final safety gate или physical keep/release input.

Один bounded integration session теперь согласует две capability версии 1.0,
выполняет catch-quality и catch-disposition diagnostics, затем graceful
shutdown. Managed Host decomposition разделяет process bootstrap, Common-backed
session protocol, orchestration и immutable receipt по owning responsibility;
product-local framing, generic handshake validation и kill fallback не
возвращались. Второй wire golden фиксирует optional/repeated/bool product
payload в managed и native consumers.

WPF screen намеренно не менялся: catch disposition не является Engine lifecycle
status и не требует product composition. Вывод diagnostic decision в fake UI
создал бы ложный production action surface и смешал domain parity с presentation.

Migration gate: native policy может стать production consumer только внутри
будущей целостной Engine-owned catch-resolution operation, где detector result,
inventory snapshot, settings revision, decision, final foreground/entitlement
safety gate и input остаются в одном Engine lifecycle. Fine-grained Host RPC
между этими этапами запрещен.

Removal gate:

- Python oracle и его corpus не удаляются до explicit standalone Engine cutover,
  production parity, crash/unknown-outcome gates и stable rollback window;
- offline C++ candidate удаляется, если whole catch-resolution capability не
  может потребить его без разрыва stateful invariant; corpus остается
  characterization evidence;
- product diagnostic proto fields могут быть removed only before any accepted
  release contract; после acceptance применяются обычные protobuf compatibility
  rules и field numbers не переиспользуются.

Skill audit Phase 6: Common/UI/Container ownership и release gates не изменены.
Повторяемые product entrypoints остаются `scripts/test_dotnet.ps1` и
`scripts/test_ipc.ps1`; Container-owned `sonar-fishing-workflow` по-прежнему
требует отдельного sync для .NET/native triggers, но Common/Container code в
этом Fishing slice не создавался.

### Phase 7 - product UI parity ledger and session summary

Фактический PySide page catalog, product states, commands and ownership
зафиксированы в `docs/architecture/UI_PARITY_LEDGER.md`. Ledger отделяет
platform UI union (`Sonar.UI.Wpf` themes/tokens/generic controls,
accessibility/responsiveness/visual regressions) от Fishing page composition,
content, feature policy, state and adapters. Ни один Common template/control не
копировался в product.

Первым cohesive read-only surface выбран нижний summary page `Рыбалка`, потому
что он сохраняет meaningful current-session function without live side effect:

- duration, caught count, released count and income range;
- full scanned tackle list rod/reel/line/hook/bait/net;
- exact `Снаряжение ещё не сканировалось` state.

`src/dotnet/Sonar.Fishing.Host/FishingSessionSummary` содержит defensive
immutable snapshot, pure presentation mapping and WPF screen. Formatting
сохраняет current Python semantics `format_duration`/`format_money_range` and
`_format_tackle_items_html` content without carrying HTML into WPF. UI consumes
package `Card`, `SectionHeader` and `MetricCard`; product owns labels, grouping
and immutable fake values. Common source checkout, `ProjectReference`, copied
XAML, product icons and new generic controls отсутствуют.

Screen composed into inert `FishingHostShell` but no executable `App`/`Window`,
runtime command, Engine process, Python bridge, GTA/process memory, capture,
OCR, input, network or IPC source was added. Focused Release gate builds with 0
warnings/errors and passes 9/9 STA WPF tests for mapping, defensive immutability,
package primitive composition, empty/populated states, resizing and
accessibility.

Production gate: one future application adapter must receive an atomic,
revisioned read-only aggregate of session totals and tackle state. Fine-grained
Host-to-Engine polling is forbidden because it could mix revisions. Python
`FishingSessionStats`, `_refresh_stats_tab` and `tackle_items()` remain sole
production owner until characterization, reconnect/stale-state semantics,
visual/DPI regressions, explicit UI cutover and rollback acceptance.

Skill audit Phase 7: `sonar-fishing-workflow` continues to route Python and
product-owned .NET tests; `sonar-ecosystem-workflow` continues to assign Common
UI platform ownership and package-only dependency direction. No new persistent
workflow or release operation was introduced, so no Common/Container/release
skill code changed in this product slice.

### Phase 8 - runnable offline WPF Host

`Sonar.Fishing.Host` теперь является реально запускаемым `.NET 10` WPF `WinExe`,
а не class library. `App.xaml` является единственным executable composition
root: он разбирает явный migration mode, создает product shell, pages,
application lifecycle и concrete offline Engine health adapter. Service locator,
global Messenger и binding protobuf DTO к XAML не добавлены.

Запуск fail-closed и разрешает только два явных режима:

- `--demo` не создает Engine process и показывает только явно помеченные
  демонстрационные status/session/tackle snapshots;
- `--offline-engine <path>` запускает bounded inert Engine health session,
  показывает checking/healthy/failed state и автоматически выполняет graceful
  shutdown либо cancellation/containment cleanup;
- запуск без mode завершается до создания MainWindow и объясняет допустимые
  migration modes;
- ни один mode не подключается к Python production process, GTA, capture,
  memory, OCR, input, network, license, update или release pipeline.

Capability-first Host tree:

- `HostRuntime/` - argument contract, composition root result и application
  lifecycle coordinator;
- `Shell/` - product page catalog, selected state и navigation commands;
- `FishingPage/` - composition существующих Engine status и current-session /
  tackle surfaces;
- `EngineHealth/` - coarse use-case port, observable MVVM state и diagnostic
  page;
- `EngineIntegration/` - concrete contained IPC adapter; generated/wire DTO
  остаются внутри этой infrastructure boundary.

`CommunityToolkit.Mvvm` закреплен exact version `[8.4.2]` и SHA-256
`8CB4B5BE8E95F9F1EC26CF341D84FBEE8244E88102EBC7C88242E960E0E35805`.
Observable state и commands появились только вместе с первым реальным Host use
case. Product shell потребляет package `NavigationButton`, `Card`,
`StatusBadge`, `SectionHeader` и `ActionButton`; Fishing-owned XAML композирует
pages/content/state и не копирует Common templates или dictionaries.

Managed IPC boundary обновлен до Common 0.1.1. `LocalPipeServerPair` и
`AcceptExpectedClientAsync` создают control/events pipes с Common-owned
current-user DACL, remote-client rejection и PID gate. Native inert Engine
подключает оба канала через installed Common native 0.1.1
`local_pipe_client_pair`.
Product-local DACL, Win32 server framing, PID validator, handshake validator,
process containment или heartbeat tracker не добавлены. Long-lived heartbeat
liveness остается gate будущего production supervisor: текущая health session
ограничена одним timeout до 10 секунд и завершается после handshake, двух pure
diagnostics и shutdown.

Product-owned commands:

```powershell
powershell -ExecutionPolicy Bypass -File .\scripts\build_dotnet.ps1
powershell -ExecutionPolicy Bypass -File .\scripts\run_dotnet.ps1 -Demo
powershell -ExecutionPolicy Bypass -File .\scripts\run_dotnet.ps1 -OfflineEngine <path>
powershell -ExecutionPolicy Bypass -File .\scripts\test_dotnet.ps1
powershell -ExecutionPolicy Bypass -File .\scripts\test_ipc.ps1
```

`build_dotnet.ps1` и оба test gates используют fresh deterministic package
cache generation, exact package hashes, pinned protoc 35.1 и stable workspace
fallbacks. `run_dotnet.ps1` является единственным WPF window-launch entrypoint;
он не строит native Engine автоматически и требует explicit inert executable.

Focused acceptance после Common 0.1.1 repin:

- Release Host build: 0 warnings, 0 errors;
- WPF/package/navigation/lifecycle/settings tests: 27/27;
- native CTest: 10/10;
- managed Host-to-Engine tests: 3/3;
- Engine получает `side_effects_enabled=false`, child остается в Common
  kill-on-close Job, Python authority receipt остается
  `python-legacy-engine-facade`.

Это executable migration Host, но не WPF production authority. Legacy license
startup, полный 8-page catalog, settings, live session snapshot source,
production start/stop commands, long-lived supervisor и visual/DPI parity еще
не перенесены. Fake page state остается только explicit demo mode; offline mode
уже потребляет revisioned inert C++ snapshot. Production source заменяет оба
только после explicit WPF/C++ cutover и rollback window.

Skill audit Phase 8: Common ownership и release safety gates не изменились.
Новые durable product-owned `build_dotnet.ps1`/`run_dotnet.ps1` и executable Host
scope требуют синхронизации canonical Container copy
`sonar-fishing-workflow`; Common/Container code в Fishing repository не
создавался.

### Phase 9 - Python characterization seam (nonshipping)

`FishingSessionStats.aggregate_snapshot()` и `LegacyEngineFacade` фиксируют
revisioned aggregate bot/session/tackle projection и whole start/stop behavior
текущего Python owner. Current PySide composition по-прежнему явно включает
side effects, поэтому production behavior не изменен.

После окончательной границы продукта Python worker/pipe/setup был отвергнут:
`headless_legacy_engine.py`, `setup_legacy_engine.ps1` и transitional pipe note
удалены. Product не предлагает `--legacy-engine`, не pin-ит Python IPC wheel и
не содержит локальный Python framing/PID/security loop. Facade и Python tests
остаются только временным nonshipping parity oracle до полного C++ cutover.

### Phase 10 - native session statistics и реальный WPF snapshot

Product-owned C++20 `SonarFishingSessionStatistics` переносит session-only
totals, fish rows, catch-size counters, custom/default price calculation,
tackle projection, timer и reset. Один deterministic corpus читают Python
oracle и plain CTest; persistence/history намеренно не переносится.

Inert Engine после accepted read-only start публикует по events channel один
revisioned `FishingSessionSnapshot`. WPF offline page заменяет preview настоящим
immutable C++ aggregate для lifecycle, totals и tackle; demo mode сохраняет
явно fake state. Это read-only evidence, не production authority и не live
adapter. Handshake advertises `fishing-session.statistics` 1.0.

### Phase 11 - fish identity и цельная catch observation

`SonarFishingFishIdentity` переносит exact 31-fish catalog, normalization,
Python-compatible similarity/tie semantics и fail-closed 0.72 gate.
`SonarFishingCatchObservation` атомарно преобразует сырые OCR strings в
canonical fish identity/confidence, quality, legacy-compatible weight, XP,
max-level marker и validity. Capability остается внутри Engine domain: никаких
per-field IPC/RPC и authorization физического действия.

Shared corpora находятся в `tests/fixtures/fish_identity` и
`tests/fixtures/catch_observation`; Python production path остается oracle.
Focused gate после Phase 11: native CTest 7/7, managed Host-to-Engine 3/3,
WPF/managed 18/18 и focused Python corpora green. Полный текущий остаток до
authority cutover ведется в
[PRODUCTION_CUTOVER_CHECKLIST.md](PRODUCTION_CUTOVER_CHECKLIST.md).

Skill audit Phase 9-11: durable target workflow остается product-owned
WPF/C++ build/test поверх pinned Common packages. Common/Container source в
Fishing не добавлялся; временный Python package workflow удален.

### Phase 12 - Common 0.1.1, runtime settings, state.dat и lifecycle

Installed native Common pin обновлен на immutable `0.1.1`; product gate
проверяет SHA-256 манифеста
`695B6BFAD82A3052A5021BA55F9F833D81672DA755BF98626CC66CFB3DACAE0C`.
Engine потребляет Common `local_pipe_client_pair`, `session_header_factory`,
`incoming_sequence_gate`, `heartbeat_responder` и `peer_liveness_tracker`.
Два pipe подключаются all-or-none к exact Host PID с одним deadline; Fishing
не содержит product-local копий этих generic mechanisms.

`SonarFishingRuntimeSettings` атомарно принимает полный immutable snapshot,
отклоняет invalid/equal/stale revisions без partial mutation и сохраняет exact
accepted revision в session snapshot. WPF offline gate теперь отправляет
фактически загруженный persisted snapshot, а не diagnostic hardcode.

Host single-writer startup реально использует `config/state.dat`: versioned
binary container, payload SHA-256, strict schema, DPAPI CurrentUser для secrets,
write-through `state.dat.pending`, recovery и verified one-time migration трех
legacy JSON files. Поврежденный state останавливает startup fail-closed.

`SonarFishingLifecycle` содержит pure Engine-owned whole-episode state machine
для start, fishing stages, deferred meal/bait/inventory, player scan, chat pause,
stop и terminal cleanup. Внутренний `entitlement_valid` event пока только
interface seam: он не заменяет отсутствующий Common signed entitlement contract.

### Phase 13 - native reeling replay policy

`SonarFishingReelingControl` переносит из current characterization точные
fish-position velocity update/duplicate semantics, projected-velocity
EMA/deadband limits, fish-behind orientation, direction switch confirmation по
sample count и времени, stable-center hold и 0.55-second stale-input grace.
Stale/duplicate/non-finite observations не мутируют estimator; non-finite
velocity дает inert `invalid_sample`.

Модуль возвращает только typed input intent. Он не вызывает `SendInput`, не
читает GTA memory/window/capture и не получает physical authority. Final focus,
entitlement, settings revision и crash-safe key lease остаются обязательными
gate полного Engine reeling episode после Common F4 capability.

Current offline acceptance после Phase 19:

- `scripts/test_dotnet.ps1`: no-Python managed ownership scan, Release build
  0 warnings/errors и 46/46 tests;
- `scripts/test_ipc.ps1`: no-Python managed/native ownership scans, exact Common
  package hashes, native CTest 13/13 и managed Host-to-Engine 3/3;
- `tests/test_memory_reeling.py`: 46/46 current Python oracle tests;
- GTA, window, capture, memory attach, physical input, network и WPF window не
  запускались.

Release measurement baseline и решение не выполнять speculative optimization
зафиксированы в [MIGRATION_PERFORMANCE.md](MIGRATION_PERFORMANCE.md).

### Phase 14 - native meal/player-status recovery policy

`SonarFishingMealRecovery` переносит текущую observable policy как один pure
Engine-owned domain slice без I/O: optional player-status fields, exact
food/water decay clocks, trusted/untrusted core merge, inventory fish-weight
accumulation/reset, strict recovery thresholds и ближайший recovery timer.

Meal planner сохраняет current legacy precedence: disabled/satisfied,
fresh-status requirement, reeling deferral, HUD confirmation, inventory
consume, bounded backpack move attempts и confirmed depletion. Результат —
typed plan/facts/retry deadline; module не читает память/кадр, не вызывает input
и не принимает fine-grained Host commands. Product memory/capture observations,
bounded side-effect episode, final focus/entitlement/settings gate and crash
cleanup остаются до полного `E16` cutover.

Nonshipping Python characterization находится только в
`tests/test_player_status_migration_oracle.py`; shipping product source не
получил Python bridge. Focused oracle gate 6/6, native Release gate 11/11,
managed IPC 3/3 и WPF 35/35 green. На 1,000,000 mixed samples pure policy занял
45.130 ms (45.130 ns/sample); отдельного measured hotspot нет, поэтому
optimization не выполнялась.

### Phase 15 - aggregate Statistics Host projection

Единственный revisioned `FishingSessionSnapshot` расширен целыми native
`fish_rows` и `catch_sizes`; totals, rows, pricing, chart buckets and tackle
приходят одним events-frame, без per-field polling/RPC и без history store.
Offline Engine сериализует непосредственно immutable
`SessionStatisticsSnapshot`, а Host wire mapper fail-closed проверяет counts,
weights, price ranges, earnings and percentages before product presentation.

`StatisticsPage/CurrentSessionStatisticsViewModel` сохраняет current legacy
six-metric semantics, exact six table columns, stable fish icon key, base/custom
price text, income ranges and chart empty state. Общий formatting вынесен в
Fishing-owned presentation formatter and reused by existing Fishing summary;
Common templates/controls/XAML не копировались. Page XAML, mixed-cell editor
and responsive chart/container await exact immutable Common UI 0.2 package.

Host also has product-owned eight-page catalog, feature redirect, bounded
recent-event source (400 retained/80 presented) and revisioned settings draft
with exact dependency/dirty semantics. These are data/application projections,
not local substitutes for Common AppShell, grid, settings, table or feed
patterns.

Acceptance: WPF 35/35, native 11/11, managed IPC 3/3, 0 warnings/errors and
no-Python ownership scans green. Expanded IPC remains six coarse operations;
latest process/policy measurement and no-optimization decision are recorded in
[MIGRATION_PERFORMANCE.md](MIGRATION_PERFORMANCE.md).

### Phase 16 - native garbage-disposal policy

`SonarFishingGarbageDisposal` переносит фактические stable IDs/names
`corn`/`bag`/`pack`, selected-policy filtering and Python stable
confidence-descending order. Один language-neutral corpus читают current
nonshipping Python method и strict C++20 CTest; отдельная characterization
фиксирует observable action shape right-click -> 0.3 s -> discard key -> 0.1 s
без выполнения физического input.

Native slice принимает только validated normalized targets and returns an
internal ordered target plan. It does not capture inventory, expose a Host
stepwise RPC or click/press anything. Native detector, confirmation after
inventory reflow, final focus/signed-entitlement/settings gate, crash-safe input
lease and cleanup remain necessary before `E17` cutover.

Acceptance: focused Python 2/2, native CTest 12/12, managed IPC 3/3 and no-
Python scans green. The episode does not add IPC operations. No relevant
hotspot was demonstrated and no optimization was made; exact process baseline
is recorded in [MIGRATION_PERFORMANCE.md](MIGRATION_PERFORMANCE.md).

### Phase 17 - native equipment-recovery policy

`SonarFishingEquipmentRecovery` depends on the existing immutable native
runtime-settings contract and preserves the effective tackle/bait decisions
without creating another config owner. Tackle evaluation uses fixed
rod/reel/line/hook/bait/net priority, exact Russian reasons, allowed-without-
leader/net warnings, initial-net warning suppression and stop/exit/shutdown
mapping. Bait notice evaluation preserves the exact 3.0-second boundary and the
non-obvious legacy rule that an eligible probe advances cooldown before reeling
or no-notice rejection.

Focused nonshipping characterization exercises the actual effective Python
override and `_handle_tackle_depletion`: 15/15. Native CTest is 13/13, managed
IPC 3/3 and no-Python ownership scans are green. The pure policy does not
capture/read/click/press, expose fine RPC or execute terminal actions. Repeated
tackle confirmation, full bait exit/restart loop, detector, entitlement/focus/
settings gate, crash-safe input and cleanup remain before `E18` cutover.

The fixed six-slot policy adds no IPC operation and has no demonstrated
hotspot. No optimization was made; latest process evidence is recorded in
[MIGRATION_PERFORMANCE.md](MIGRATION_PERFORMANCE.md).

### Phase 18 - managed Telegram settings/state parity

Product-owned `TelegramPage` now preserves the effective settings semantics
without locally cloning Common form/shell controls: trimmed secret token,
digits-only comma-separated administrator IDs, exact threshold normalization,
seven notification toggles, feature/availability-signature enable gate,
enabled credential lock, Russian status/block copy, dirty/discard/save behavior
and the two external setup links. Availability is an inert typed input here;
this slice performs no Telegram/network operation and sends no token through
Engine IPC, logs or diagnostic snapshots.

The previous C# schema silently discarded seven `sound_*` flags changed by the
legacy Telegram inline keyboard. `config/state.dat` schema v2 now persists them,
reads schema v1 with the exact all-enabled legacy defaults, and imports all
seven values from legacy JSON. Protected bot-token storage remains in the
existing secret document; tests use fake credentials only.

Acceptance: WPF 41/41, native CTest 13/13, managed IPC 3/3, 0 warnings/errors
and both managed/native no-Python ownership scans green. The Host-only slice
adds no IPC operation and the process/policy baseline shows no new hotspot, so
no optimization was made.

### Phase 19 - Telegram inbound/menu protocol

`TelegramInboundRouter` parses one bounded Telegram JSON update into a typed
product intent only after runtime-enabled, settings-enabled and exact admin-ID
checks. It preserves the current first-token command table, callback
acknowledgement, menu new-vs-edit behavior, all action/stream callbacks and the
seven notification + seven sound callback allowlists. Malformed, oversized,
unauthorized and empty input fails closed. `TelegramSettingsReducer` performs
only immutable allowlisted toggles; `TelegramMenuPlanner` preserves the exact
capability-dependent main/notification/quality keyboards and Russian copy.

A language-neutral 45-case TSV is consumed by the current nonshipping Python
owner and the C# router. Characterization exposed and fixed an initial wrong
assumption: `stream:open` and every `action:*` callback send a new reply, while
menu/toggle/stream-control callbacks edit the source message. At this
characterization checkpoint focus, screenshot, shutdown, fishing and stream
intents remained inert typed data. Phase 29 connects them only to narrow
capability-gated Host ports; an intent never grants the capability itself.

Acceptance: focused current-Python corpus 45/45, WPF 46/46, native CTest 13/13,
managed IPC 3/3, 0 warnings/errors and no-Python ownership scans green. No IPC
operation was added and no measured hotspot exists.

### Phase 20-22 - Common UI, mutable statistics and Windows safety boundary

The complete eight-page WPF composition consumes frozen `Sonar.UI.Wpf 0.2.19`
without copied Common source. It uses the shared responsive AppShell/AppBrand,
4/8/12 grid and page/settings/table/master-detail/state patterns, embeds the
Fishing logo and 31 fish images, preserves plain-letter hotkeys through the
Common `HotkeyGesture` contract and renders 132 deterministic compact/medium/
expanded and DPI variants. Statistics owns atomic custom-price revisions and a
coarse session reset command.

Native target preflight consumes frozen `SonarPlatformWindows 0.1.6` for
least-rights process identity/generation, coherent window validation and the
pure packet budget. Product policy still owns entitlement/settings/lifecycle
ordering. No GTA process/window, capture or input action has run. Native CTest
is 14/14, managed IPC is 3/3 and the Engine's current typed diagnostic commands
are order-independent rather than tied to one scripted sequence.

### Phase 23 - Host streaming snapshot/controller and page union

One Host-owned immutable streaming snapshot and coarse controller boundary now
drive both the Stream page and Overview. The model preserves effective
480/720/1080 quality and 30/10-FPS bitrate tables, inactive-preparing
normalization, status/area/autostop/URL/uptime projection, start/stop/chat-mode
commands, chat zoom and atomic persistence of 10-FPS mode. A typed unavailable
adapter rejects every mutation without launching a process or network request;
it is a real fail-closed state, not a second streaming implementation.

The responsive Stream page maps the entire accepted product union to Common
controls and its compact/expanded 100% renders were inspected. WPF acceptance
is 81/81, the full render is 132/132, native remains 14/14 and managed IPC
remains 3/3. Real contained FFmpeg/HLS/tunnel lifecycle, authenticated public
surface and chat use-case bridge remain required before `H07` authority.

### Phase 24 - long-lived Engine session and signed entitlement proof

`OfflineEngineSession` now owns one Common Job-contained process, one dual-pipe
pair, serialized coarse commands, one monotonic heartbeat tracker and graceful
`ShutdownReady`/Job fallback. Repeated health checks retain the same verified
PID/session; duplicate heartbeat IDs no longer terminate the native responder.
This remains an inert diagnostic target with `side_effect_support=false`, not a
production supervisor claim.

Fishing pins frozen `Sonar.Licensing.Verification 0.1.3` and native
`SonarPlatformLicensing 0.1.2`. Host retains exact method/path/host,
Date/Digest/Keygen-Signature and raw body bytes, verifies transport first, then
parses duplicate-safe Fishing product claims. Engine receives the same raw
envelope in one coarse command and independently repeats RSA/digest/freshness
verification plus product, audience, machine, bundle, policy, feature, expiry
and monotonic-generation policy. One language-neutral signed fixture is
accepted by both and equal generation is rejected Engine-side.

The fixture key is explicitly nonproduction and compiled only into the inert
offline Engine target. Production Host/native policy constructors contain no
RSA key/key id and fail closed with `entitlement_trust_root_missing`; the
unrelated startup-block Ed25519 key is never reused. Package and smoke
entrypoints report this blocker before performing any build/launch. No license
or game network, GTA/window/capture/input action or release upload ran.

Acceptance after this slice: WPF 87/87, native CTest 15/15 and managed IPC 5/5.
The latest process/CPU/memory/policy measurements and no-optimization decision
are recorded in [MIGRATION_PERFORMANCE.md](MIGRATION_PERFORMANCE.md).

### Phase 31 - bounded signed startup admission

Host now owns a bounded HTTPS-only startup-block client and a strict Ed25519
response verifier through `Sonar.Licensing.Verification 0.1.3`. The verifier
reconstructs the exact canonical `{blocked,download_url}` bytes, rejects
malformed/tampered/oversized responses and permits a blocked download target
only when the signed absolute URL uses HTTPS without user information. Request
diagnostics redact the license key and build identity; cancellation and timeout
remain distinct stable outcomes.

Initial admission is fail-closed when the check is unavailable or invalid.
Once the application is already running, only a checked, valid signed block can
request shutdown; a transient network failure cannot stop it. Fixed Ed25519
parity vectors and fake HTTP handlers cover payload/header compatibility,
tampering, response bounds, HTTPS policy, timeout and caller cancellation with
no production network request. The shared-kit startup surface now projects
checking, blocked and unavailable states, and a sequential five-minute monitor
ignores transient failures while dispatching one valid signed block exactly
once. Production composition and guarded endpoint acceptance remain required
before H04 authority changes.

### Phase 32 - bounded embedded-only Host streaming lifecycle

`StreamingRuntimeController` now implements the existing coarse
`IStreamingController` boundary as one revisioned generation owner. Start,
stop, online quality/chat-zoom/10-FPS restart, unexpected failure retry,
no-viewer autostop and Host disposal are bounded and cancellation-aware. A
replacement generation waits for prior cleanup, so two encoder/tunnel/media
sets cannot overlap. Snapshot changes return to the captured Host context and
stale generations cannot overwrite a newer revision.

`ContainedStreamingSessionBackend` orders embedded executable acquisition,
coarse capture descriptor, authenticated loopback media session, encoder first
media, HTTPS tunnel discovery and coherent Online publication. Encoder and
tunnel processes use the product lifecycle wrapper over Common
`KillOnCloseJob`; startup rollback and stop clean tunnel, encoder, network and
tool lease in reverse order under one total budget. Loose executable origin,
unauthenticated/non-loopback viewer state, malformed capture data and unsafe
tunnel URLs fail closed. Exact output policy is 854x480/1280x720/1920x1080,
30 or 10 FPS and the frozen 1200/600, 2900/1500 and 5000/2300 kbit profiles.

Eleven new acceptance cases use only fake executable/process/capture/network
adapters; no process, socket, game window, capture, input or GTA operation ran.
Managed acceptance is 128/128 with zero warnings and no new Engine IPC. Full
design and remaining activation gates are recorded in
[H07_STREAMING_RUNTIME.md](H07_STREAMING_RUNTIME.md).

Production composition intentionally remains on
`UnavailableStreamingController`. Signed redistributable tool payloads and
hashes, guarded capture, authenticated viewer/network implementation, chat
bridge, stale transient-workspace recovery, privacy review and authorized real
process/network plus two-EXE lifecycle acceptance are still required.

### Phase 25 - bounded cancellable Engine event delivery

The Engine event channel now has exactly one product-owned writer. It consumes
Common 0.1.1 `priority_frame_queue` and `latest_frame_buffer`: accepted safety
and lifecycle payloads are ordered ahead of normal payloads and are never
silently discarded, queue saturation terminates admission with a stable reason,
and replaceable aggregate snapshots coalesce latest-only. Graceful shutdown
stops admission and drains accepted work; cancellation reaches the Common pipe
write so crash/teardown cannot leave an uncancellable writer thread.

The read-only session snapshot uses this real writer rather than writing the
events pipe inline. Focused outbox/writer tests cover priority order, snapshot
coalescing, explicit safety saturation, drain and closed admission. Native
CTest is 16/16 and managed IPC remains 5/5; no GTA/window/capture/input/network
action ran. Production notification producers and generation recovery were
closed later in Phase 48; this phase remains the historical transport baseline.

### Phase 26 - native coarse game-chat episode

`SonarFishingGameChat` ports the effective controller sequencing as one
Engine-owned episode rather than exposing focus/click/key steps through Host
RPC. Open and close require bounded native observations before reporting a
state transition. Clear, tab selection and send preserve the exact focus,
Ctrl+A, three-Backspace, clipboard-paste and Enter order. Plain text sent from
a non-All tab restores the Majestic prefix through the All tab; an explicit
slash command skips that restore. Every click is expressed in current-client
normalized coordinates, with invalid bounds rejected rather than replaced by
the legacy fixed fallback.

The product BGR24 capture and pixel-detector interfaces normalize only against
the current frame dimensions and reject malformed buffers, replayed sequences,
duplicate/inconsistent tabs and out-of-client rectangles. The exact 12-image
legacy chat corpus is SHA-256/size pinned by the product entrypoint; its active,
selected-tab and input-rectangle outputs are frozen by the nonshipping Python
oracle. No native detector algorithm or live capture source is claimed yet.

The platform boundary is one typed mutation intent at a time. One move-only
exclusive chat lease covers observation, decision, mutation and terminal
confirmation; another input episode can query the same coordinator and cannot
acquire it concurrently. The concrete `runtime_safety_chat_final_gate` re-reads
entitlement/settings/lifecycle and uses the frozen Common process/window/input
guard immediately before the sink call. Pause is non-mutating and bypasses the
packet gate; every real mutation has an explicit conservative packet budget.
Shipping capture, detector, final-gate and platform-mutation composition stays
disabled, so this code cannot activate a window, capture, alter clipboard state
or emit input.

Acceptance: focused Python oracle 2/2, WPF 91/91 with 132 renders, native CTest
18/18 and managed IPC 5/5. No game/window/capture/input/network action ran.
The actual native detector/capture implementation, crash-safe platform sink,
cross-episode lease consumers and terminal/key-up confirmation remain before
`E19` authority cutover.

### Phase 27 - bounded Engine supervisor recovery

The Host now routes its long-lived session through one product-owned
`EngineSessionSupervisor`; Common `KillOnCloseJob` remains the sole generic
process-containment mechanism. A healthy generation is reused, every heartbeat
has the existing bounded IPC deadline, and a dead process, failed heartbeat or
completed/faulted event pump retires the whole pipe/process generation before
replacement. There is no permanent circuit-open state: the heartbeat owner
starts before the first attempt, stays alive after any number of consecutive
failures and retries indefinitely with bounded delay. The rolling failure window
is telemetry/backoff input only. Caller cancellation does not count as a runtime
failure, while terminal cancellation prevents all later starts and concurrent
stops dispose the session once.

Current recovery policy withdraws the crashed generation's runtime authority
and publishes an empty fail-closed session snapshot before replacement. Restart
attempts use exponential `250 ms` -> `2 s` capped backoff. A successful
replacement restores the latest complete settings revision and reapplies the
still-valid signed entitlement once; it remains idle and does not replay a
previous automation start/stop command or any input lease.

The deterministic matrix covers healthy reuse, unexpected exit with authority
withdrawal/settings restoration/no command replay, more failures than the old
three-attempt limit followed by automatic recovery without another external
check, event-pump death with no old notification replay, caller cancellation,
uncontained candidate, in-flight bootstrap cancellation and concurrent terminal
cleanup. The managed/native
integration test also kills only the inert offline Engine and proves a new
Common-contained PID with the same complete runtime-settings revision. No GTA,
external window, capture, input or network action ran.

### Phase 28 - native game-chat visual observation

`majestic_chat_frame_detector` now owns the real product visual algorithm over
an immutable BGR24 frame. Its grayscale, Canny/hysteresis, morphology,
component and HSV masks are native C++ and express search regions, component
bounds and gaps relative to the current frame instead of a screen resolution.
Canonical visible tab identities remain product-owned (`Все`, `Семья`, then
the stable Majestic order); no Tesseract, OpenCV, Python or loose model is
required. A WIC test loader is nonshipping test code only.

All twelve frozen 1920x1080 screenshots match the legacy oracle exactly for
active/inactive state, selected tab, minimum tab union and pixel input bounds.
The corpus entrypoint still verifies every JPEG SHA-256 and byte count before
the native build. Authentic screenshots from additional game resolutions are
still required before live readiness; the current corpus resolution is evidence,
not a runtime geometry constant.

`win32_chat_capture_source` is the concrete product capture adapter. It accepts
one Common `window_client_snapshot`, validates identity and client geometry both
before and after a client-DC `BitBlt`, owns the converted BGR24 buffer and
monotonic sequence, and releases every GDI object through RAII. It remains
unconstructed in production composition; only the invalid-handle fail-closed
path ran. The platform mutation sink was added in Phase 30; cross-episode lease
consumers, authentic multi-resolution evidence and guarded production
composition still block `E19` authority.

### Phase 29 - cancellable Telegram Host lifecycle and guarded dispatch

`TelegramNetworkRunner` owns the bounded HTTPS client, bot API adapter, ordered
long poll, router and `TelegramCommandDispatcher` as one Host-side generation.
`TelegramRuntimeCoordinator` starts at most one generation, cancels it during
Host shutdown, replaces it after a token/admin/enablement change, does not
restart for notification-only changes and retries unexpected failure with a
bounded delay. Its diagnostic string always redacts the token; the token never
enters an Engine message, persisted diagnostic snapshot or log.

The dispatcher preserves callback edit-in-place and new-message semantics,
handles unchanged edits without duplicate replies, supports HTTPS stream URL
buttons, persists the exact seven notification and seven sound toggles,
projects current statistics/tackle/player status and routes fishing,
screenshot, focus, shutdown and scan commands through
`ITelegramProductUseCases`. Stream commands consume the existing coarse
`IStreamingController`. Missing entitlement or runtime capability fails closed
before any side effect, while API/action failures expose only stable copy.

The current demo/offline composition deliberately sets
`networkAllowed=false` and supplies `UnavailableTelegramProductUseCases`: no
live Telegram request, GTA/window/input action or OS shutdown ran. Production
activation still requires the licensed run mode and concrete capability
implementations. Managed acceptance is 106/106 with zero warnings, including
lifecycle, token rotation/redaction, edit fallback, media, settings, capability
and stream-controller tests under offline fakes.

### Phase 30 - default-off native chat mutation boundary

`win32_chat_platform_mutation_sink` now implements the product-owned side of
the coarse chat episode without adding a Host RPC. The existing final gate
continues to re-read entitlement/settings/lifecycle and reserve the exact
Common packet budget immediately before the sink. Activation validates the
same process/window identity and geometry before requesting focus; every later
mutation additionally requires that exact window to be foreground.

Press, hotkey and click are complete bounded `SendInput` pulse batches rather
than held-key state. An API-reported partial prefix is followed only by the
minimum required key-up or mouse-up cleanup for keys/buttons actually present
in that prefix; a cleanup failure remains a stable fail-closed result. Exact
packet-count shape, the legacy blocked `W`, normalized client-to-screen
conversion and the nine-key release union are independently enforced by the
sink. The clipboard path performs strict UTF-8 to `CF_UNICODETEXT` conversion
and closes clipboard ownership on every return path. It preserves the legacy
clipboard replacement semantics; user clipboard content rollback is not
claimed. Bounded waits use `stop_token`, including cancellation while blocked.

The Win32 implementation was never called by acceptance: tests inject a
recording backend and prove complete batch order, partial-prefix cleanup,
under-budget rejection, invalid UTF-8/geometry rejection and in-flight pause
cancellation. Demo/offline Engine composition still constructs only disabled
capture/final-gate/mutation adapters, so no window focus, cursor, clipboard or
input action ran. Current gates are native default 17/17, native IPC 20/20,
managed IPC 6/6 and WPF 106/106 with zero warnings.

Skill audit Phase 12-30: durable product build/test and final no-Python gates
остаются в `sonar-fishing-workflow`. Release workflow was applied only to
inspect the safe package/smoke boundary; both remain blocked before build or
launch and no upload ran. Shared supervision, licensing, process/window, input
and design-system ownership remains Common and is not duplicated locally.

### Phase 33 - native fishing-stage visual detection

`SonarFishingStageDetection` now owns the pure product detector for the five
effective stage triggers. It preserves the exact priority `ad`, `start2`,
`wait_tension`, `start1`, `start` and maps them to reeling, waiting, casting and
tackle-selection observations. The public boundary consumes one immutable
BGR24 frame view and returns trigger ID, confidence and normalized bounds. It
does not capture a frame, attach to a process/window, read memory, issue input,
use network or add a Host RPC.

Ten FHD/2K gray8 templates are language-neutral build inputs with exact
historical-source/current SHA-256, dimensions and byte counts in
`native/fishing_stage_detection/assets/manifest-v1.tsv`. CMake embeds them into
the native target; no loose image, OpenCV, Python interpreter, wheel or OCR
model becomes a runtime dependency. ROI and template scaling use actual frame
geometry. Compatible 4K frames are area-normalized to the 2K product viewport,
while all returned geometry remains normalized rather than tied to screen
coordinates.

The 30-image FHD/2K/4K corpus is independently SHA/size pinned by the product
test entrypoint. All `30/30` stages and legacy trigger precedence match; maximum
confidence delta against the current OpenCV characterization oracle is
`0.000287584`. Full normalized cross-correlation remains exact at every search
position: FFT accelerates only the raw correlation term, while local mean and
variance come from integral images. The detailed contract and evidence are in
[FISHING_STAGE_DETECTION.md](FISHING_STAGE_DETECTION.md).

The first correct Release baseline exposed a stage-loop latency hotspot. A
separate semantics-preserving optimization reused FFT twiddle plans and bounded
only the two large tension spectra. p50 changed `98.4974 -> 86.9563 ms`, p95
`216.366 -> 150.553 ms`, process CPU `4140.62 -> 3046.88 ms`; peak working set
changed `76,177,408 -> 84,627,456` bytes. Corpus/confidence output was unchanged.

Acceptance after the isolated optimization is native default CTest `18/18`,
native IPC CTest `21/21`, managed IPC `6/6`, `/W4 /WX`, managed warnings/errors
`0/0`, and green managed/native no-Python ownership scans. Live capture remains
uncomposed and `production_cutover=false`; no GTA/window/capture/input/network
action ran. Catch-screen and tackle/item-info OCR, production cast/hook cue
detectors and guarded episode composition, production entitlement and terminal
crash cleanup still block `E14`/production authority.

### Phase 34 - signed Host release transaction core

`UpdateRuntime` now owns one product-level signed release transaction rather
than exposing download, file replacement and cleanup as unrelated UI helpers.
The exact Ed25519-signed manifest admits only a canonical newer semantic
version and strictly newer generation, then fixes the ordered
`Sonar.Engine.exe`, `Sonar.exe`, `bundle-manifest.json` union with exact byte
counts, SHA-256 and HTTPS locations. Common supplies only the detached-signature
primitive; release policy, paths and user-facing failure reasons remain Fishing.

The HTTP adapter reads response headers first and staging streams bytes into one
validated direct-child transaction directory. A payload larger or shorter than
the signed length, a hash mismatch, redirect to an unsafe URI, unknown loose
path/directory, reparse point or ambiguous generation fails closed. Swap keeps
the old three-file generation in a matching rollback directory, preserves
`config/state.dat` and `logs/`, restores it after an exception, and recovers a
manually interrupted partial generation on the next safe startup. The uninstall
boundary currently emits only an exact-confirmation checked plan; it cannot
recursively delete an arbitrary directory or its own running executable.

Acceptance is `136/136` Host tests with zero warnings/errors. HTTP and file
tests use in-memory transport plus isolated temporary install roots; no external
network, installed build, update, uninstall or process launch ran. Production
authority still requires the real public key/metadata endpoint, licensed Host
composition, signed after-exit activator/uninstaller and the complete installed
two-EXE interruption/rollback/allowlist matrix. The detailed contract is
[H08_RELEASE_TRANSACTION.md](H08_RELEASE_TRANSACTION.md).

### Phase 35 - native inventory/menu/store-fish episode

Legacy `game_menu.py`, `inventory_stage.py`, `store_fish.py`, `item_info.py`,
the owning `FishingBot` methods and their characterization tests were traced
before the port. `SonarFishingInventoryStore` now owns one coarse cancellable
operation from a fresh monotonic observation through menu dismissal,
non-reeling stage exit, two-attempt inventory open, canonical fish selection,
context-action confirmation, per-removal reflow, close, optional fishing resume
and bounded failure cleanup. There is no Host frame/key/cursor RPC.

The observer contract reuses E14 stage and normalized-rectangle types but does
not duplicate rich item OCR: it accepts only canonical item identity,
confidence and current bounds. Every key or normalized target intent carries
the exact source observation sequence to `inventory_mutation_port`. A future
live port must hold the shared exclusive Engine input lease and immediately
revalidate entitlement, settings revision, lifecycle, process/window
generation, foreground identity and Common packet budget. The only current
composition is `disabled_inventory_mutation_port`, which rejects every action.

The exact language-neutral 26-row corpus
`tests/fixtures/inventory_store/episode-v1.tsv` has SHA-256
`FE747957DC7CEE960CB13BFC25D4D4725A9491F7D33A6E98C4A132688088E062` and
freezes five episodes: two-item removal with reflow and resume, already-open
empty inventory, stage exit, game-menu dismissal and reeling rejection with
zero input. Native regressions additionally cover stale observations, invalid
normalized geometry, final-gate rejection, disabled composition, bounded open
and removal timeout, cleanup and cancellation. Focused Release acceptance is
`1/1` CTest under MSVC v143 `/W4 /WX`.

Combined canonical acceptance is WPF `143/143`, native IPC CTest `23/23` and
managed IPC `6/6`, with build warnings/errors `0/0` and green managed/native
product source-ownership scans. No live GTA, window, capture, input or network
action ran.

Five equal 100,000-episode Release benchmark runs measured a median
`35.199 ms` / `351.994 ns` per already-open empty episode, with deterministic
checksum `252399995` and no IPC. No demonstrated hotspot justified an
optimization, so no timing, retry, allocation or algorithm semantics changed
after parity. Production still requires E14 menu/item observation, guarded
capture and shared-lease mutation composition, real target-loss and hard-crash
cleanup evidence, signed entitlement admission and the release allowlist. The
detailed boundary is [INVENTORY_STORE_EPISODE.md](INVENTORY_STORE_EPISODE.md).

### Phase 36 - native coherent memory observation

Legacy `memory_reeling.py`, `inventory_memory.py`, the memory half of
`player_status.py`, `find_chat_memory.py`/`dump_chat_history.py`, their direct
consumers and characterization tests were traced before the port.
`SonarFishingMemoryObservation` now owns bounded pure decoders for confirmed
reeling evidence, weighted inventory-open voting, typed player-status samples
plus WebEngine indicator/weight windows, and serialized/DOM chat state.

`memory_observer::capture` reads the four groups as one coarse aggregate. A
capture carries one monotonic sequence/time, exact profile id/revision and exact
Common `(pid, creation time)` generations for GTA and WebEngine. It validates
executable name plus SHA-256, limits one region to 256 KiB, one cycle to 96
regions/1 MiB, uses exact reads, and revalidates both generations after the
last byte. Hash/profile drift, PID reuse, partial reads, ambiguous decodes and
replayed sequences return no snapshot; no cached field is promoted to fresh
evidence.

The Windows adapter reuses frozen Common `readonly_process` for least-rights
process access, region enumeration and exact memory reads. Fishing adds only
product image-hash, bounded scan and decoder/profile policy; it contains no
local `OpenProcess`, `ReadProcessMemory` or process-enumeration clone. Normal
Engine instantiates this adapter. Reeling and inventory-state are explicit
separate scopes, so an inventory query no longer requires active fish.

Inventory binding state machine validates a cached masked signature on every
plan and performs one bounded cold rediscovery after drift. Incomplete scan,
ambiguous run or generation change stays fail-closed; failed cold discovery is
throttled for five seconds instead of rescanning every frame. Registry schema `2`
currently encodes no admitted inventory binding. The actual current hash first
returns `memory_game_build_unsupported`; the sole older admitted profile returns
`memory_inventory_binding_unavailable`. Decoder parity is not falsely reported
as production state authority.

The five-row language-neutral fixture
`tests/fixtures/memory_observation/e11-v1.tsv` has SHA-256
`ACB3FA6C1D9E7983344E53906E748DB9C7EED67E07695013A7D77166FF6DE8DD`.
MSVC v143 `/W4 /WX` focused CTest covers decoder plus inventory discovery,
cached-plan reuse, automatic relocation recovery, absent-profile and ambiguous
signature blockers. Negative coverage includes image/profile and process-generation drift,
short/oversize reads, unknown fish hash, ambiguous inventory vote, invalid
UTF-8 and sequence replay. Five equal Release decoder benchmark runs measured
a median `79.573 ms` for 250,000 aggregates (`318.290 ns` each), with no IPC.
No hotspot was demonstrated, so no semantic optimization followed parity.

E11 remains partial until the prepared non-shipping C++ characterization tool
collects one controlled current-build `CLOSED/OPEN` sequence and offline review
promotes a unique immutable binding. The tool never presses `TAB`, activates a
window or captures a frame. Player-status/chat and live target-loss remain
separate gates. The full boundary is
[MEMORY_OBSERVATION_NATIVE.md](MEMORY_OBSERVATION_NATIVE.md) and
[inventory characterization](INVENTORY_STATE_CHARACTERIZATION.md).

The first guarded read-only pass on 2026-08-24 confirmed target, executable
hash-read and capture, but the current GTA executable did not match the sole
embedded profile, so reeling memory remained fail-closed. A separate
OFF-by-default [build-profile compatibility probe](BUILD_PROFILE_COMPATIBILITY_PROBE.md)
now evaluates that unknown hash only as a distinct in-memory candidate with
complete unique anchor scans, bounded entity count, exact active-fish identity,
coherent snapshot and post-capture revalidation. It is not linked into Engine,
does not reuse registry admission identity/SHA semantics and cannot add a
profile or authorize input.

An additional zero-input read-only inventory scan found `0` exact legacy masked
signature matches on current hash, including all `13490` readable regions up to
16 MiB. The legacy anchor also had no module-rooted pointer and admitted several
sliding bases, so neither its address nor its pattern was copied into shipping.

### Phase 39 - native whole fishing episode

Effective `_prepare_fishing_start`, `_casting_control_loop`, `_do_hooking` and
`_run_reeling_module` paths plus their direct characterization tests were
traced before the port. `SonarFishingEpisode` now owns one coarse cancellable
casting, hooking and reeling operation inside C++ Engine. No frame, memory
field, detector step or `PressA`/`PressD`/Space command crosses the Host
boundary.

Each observation has one monotonic sequence/time and combines the E14 stage,
semantic cast/hook cue and exact-same-cycle E11 memory aggregate. The runner
freezes memory profile id/revision and GTA/WebEngine process generations on the
first memory sample. Stale or ambiguous cues, trigger/stage mismatch, missing
reeling memory, profile/target drift and unconfirmed stage loss fail closed
before another mutation. The existing native velocity tracker, projected
velocity policy, orientation, stabilizer and input projection remain the sole
reeling-policy owners.

One `fishing_mutation_session` holds the exclusive Engine input lease for the
whole episode; lease acquisition itself grants no authority. Every cast/hook
Space pulse and A/D transition carries the exact observation sequence plus
accepted settings, entitlement and lifecycle revisions to an immediate final
gate, which must also revalidate process/window generation, foreground identity
and Common packet budget. Normal, failed, cancelled and unexpected-exception
paths perform one bounded best-effort A/D cleanup. The only ready composition
is `disabled_fishing_mutation_port`, so no live observer, mutation adapter or
Host command is connected.

The 19-row / 6-episode language-neutral corpus
`tests/fixtures/fishing_episode/e13-v1.tsv` has SHA-256
`48BE8A7AEC802A0F9950A5C1E497DC204B5D09795E77527D17BBFFA47706B349`.
Focused MSVC v143 Release acceptance is CTest `1/1` under `/W4 /WX`; legacy
casting/hooking/reeling characterization is `149/149`. Negative coverage
includes final settings/entitlement/lifecycle/window/input-budget rejection,
cancellation after an accepted mutation, cleanup failure, stale sequence,
profile/process-generation drift, invalid cue values and observation-budget
exhaustion.

Five equal 100,000-episode replay runs measured median `83.9312 ms` /
`839.312 ns` per complete six-observation episode, range
`82.3207-85.5194 ms`, checksum `2300000`; the operation adds no IPC message or
byte. No measured hotspot justified an optimization. Production still requires
authentic E14 cast/hook cue corpora, a signed E11 target profile/resolver, the
shared live lease/final-gate adapter, target-loss and hard-crash cleanup
evidence, entitlement admission and the release allowlist. The detailed
boundary is [FISHING_EPISODE_NATIVE.md](FISHING_EPISODE_NATIVE.md).

Skill audit: `sonar-fishing-workflow` already routes native automation and its
offline/live safety boundary; product setup/test entrypoints and the separate
release workflow did not change, so no skill source update is required.

### Phase 40 - native meal, garbage and equipment whole episodes

Legacy `_do_meal_actions`, `_do_garbage`, `_check_tackle_before_start`,
`_do_change_bait`, `meal_system.py`, their pure native policies and direct
characterization tests were traced before the port. Phase 40 extends E15 with a
coarse `inventory_episode_operation` context instead of adding Host capture,
decision or key RPC. `SonarFishingMaintenanceEpisode` executes meal recovery,
garbage disposal, tackle confirmation and bait recovery inside the same E15
session and exact-observation-sequence mutation port.

Meal recovery consumes E11 typed food/water evidence or HUD need, preserves
`irp -> donut -> cocktail`, confirms exact item consumption or backpack
movement, bounds the loop and closes inventory for HUD/status confirmation.
Garbage disposal reuses the native stable confidence planner, reflows after
every confirmed exact-instance disappearance and has a 128-item bound. Tackle
scans retain the legacy obscured waits and need two fresh matching depletion
reads before a typed terminal outcome. Bait keeps the effective cooldown-first
precedence in a mutation-free preflight, stops sending `Esc` if reeling
appears, bounds stage exit and makes at most ten restart attempts.

The 27-row / 5-episode language-neutral corpus
`tests/fixtures/maintenance_episode/episode-v1.tsv` has SHA-256
`F4ED4238EEDB677620C4AFEABCAAEEA62F61EA97F33775567643269376BF7BBA`.
Focused MSVC v143 Release acceptance is E15 + maintenance CTest `2/2` under
`/W4 /WX`. Five equal 100,000-episode replay runs measured median `69.784 ms` /
`697.842 ns` per admitted tackle episode, range `68.888-69.949 ms`, checksum
`1699995`; no hotspot justified a semantic optimization.

Combined canonical Phase 39/40 acceptance is WPF `155/155`, native IPC CTest
`25/25` and managed IPC `6/6`, with warnings/errors `0/0` and green
managed/native source-ownership scans. The unchanged six-operation inert Engine
path measured `39.864 ms` bootstrap, `44.555 ms` scenario, `93.480 ms`
start-through-exit, `0.000 ms` sampled CPU and `7,254,016` bytes peak working
set. Maintenance has no offline Host command and adds `0` IPC operations/bytes.

This is offline parity, not production authority. There is no live observer,
mutation adapter, Host command, capture, input or network action. Signed
detector/profile composition, the shared exclusive mutation lease with
immediate entitlement/settings/lifecycle/process/window/foreground/Common
packet-budget validation, target-loss/hard-crash evidence and release allowlist
remain open. The detailed contract is
[MAINTENANCE_EPISODES.md](MAINTENANCE_EPISODES.md).

## 7. Blocking gates

- Hidden override method surface зафиксирован. Game-chat controller sequencing,
  native detector and inert concrete capture adapter have code-backed traces;
  authentic multi-resolution screenshots, the live-readiness composition and
  complete traces for every adjusted fishing method are not yet ready.
- `config/state.dat`, legacy settings migration/recovery, settings mutations
  and atomic product revisions are green offline; final activation/crash/update
  bundle lifecycle matrix is not implemented. Persistent history in target is
  intentionally absent.
- Engine-verifiable entitlement, embedded production Keygen RSA public key/key
  id, HTTPS activation/refresh/cache/revocation and independent raw-envelope
  verification are production-composed. Authorized expiry/revocation/live
  acceptance remains open; no test substitutes a trust root.
- Fishing-stage CV assets and FHD/2K/4K geometry corpus are frozen and green;
  catch-screen plus tackle/item-info OCR/native detector corpora remain open.
- Inventory/menu/store-fish sequencing, E14 menu/item observation and the
  guarded shared production mutation lease are composed. Authentic target-loss,
  multi-resolution confirmation and hard-crash evidence remain open.
- Reeling/inventory/player-status/chat memory decoding, exact embedded
  generation/hash profile admission, concrete Windows connector, target
  resolver, coherent capture/aggregation and guarded cast/hook/reel mutation
  are production-composed. Only the exact supported build is admitted;
  authorized live build/target-loss/hard-crash evidence remains open.
- Streaming lifecycle/order/cancellation/restart/cleanup and Common process
  containment are green under offline fakes, but signed embedded payloads,
  guarded capture, authenticated viewer/network/chat adapters, production
  composition and public-surface privacy/real-runtime acceptance remain.
- MSVC v143 dependency closure проверен для offline inert Engine. Standalone
  production Engine symbol policy, signing, containment и release allowlist еще
  не проверены.
- Broader `tests/test_catch_screen.py` в checkout path с пробелом блокируется
  существующим unquoted `--tessdata-dir`: Tesseract обрезает path до
  `P:/projects/neiro/Sonar` и не загружает `rus.traineddata`. Native/Python
  classifier parity и statistics regressions проходят; OCR path fix остается
  отдельным behavior-preserving slice.
- Broader license regression имеет отдельный test-data drift:
  `test_keygen_status_ignores_license_update_metadata` hardcode-ит expiry
  `2026-06-25T17:14:00Z`, уже прошедший к текущей дате, но ожидает
  `status.valid is True`. Production expiry check не ослаблялся; 19 остальных
  license tests и 102/102 bot behavior tests проходят. Fixture/time control
  исправляется отдельным test-maintenance slice.
- Held synthetic input crash safety не доказана.
- Queue count/byte bounds and per-frame Common limits are explicit; production
  p50/p95/max latency and pressure samples are not measured yet.

Runnable WPF Host и C++ Engine production authority cutover выполнен. Эти gaps
блокируют утверждение signed/live release readiness для конкретного окружения,
но не normal no-argument product launch и не explicit demo/offline diagnostics.

### Phase 47 - compile-isolated local-access authority

Локальная проверка владельца теперь имеет отдельные Host/C++ compile symbols,
явный `--developer-full-access`, schema 2 manifest с exact marker/channel и
собственные build/verify/run entrypoints. Production binaries не принимают этот
режим, ordinary run/install/update/rollback не принимают его bundle. Режим
снимает только внешние licensing/entitlement и signed startup
availability/update-block admission gates; exact supported GTA build,
coherent memory/capture, window/foreground, input lease, packet budget и final
safety gates не меняются.

Host supervisor при неожиданном завершении Engine сначала отзывает runtime
authority и публикует fail-closed idle state. Replacement получает только
последнюю settings snapshot и новое exact bootstrap authority после handshake;
automation start/stop, runtime commands и input leases не воспроизводятся.
Regression coverage выполняется в обычной production compile и отдельной
developer compile. Архитектурное решение и команды находятся в
[ADR-0002](ADR-0002-DEVELOPER-FULL-ACCESS-AUTHORITY.md).

Product presentation for this local build is intentionally non-technical. The
license page shows active `Локальный доступ`, hides key activation and maps
feature IDs to product labels. The default local bundle version is
`1.0.0-local`; compile/channel provenance remains in manifest and diagnostics.

### Phase 48 - bounded typed notification stream

Production Engine now emits typed occurrence events for catch, session
start/stop, meal recovery, inventory full/player status, bait tired and focus
loss. Facts originate inside the existing coarse production composition; Host
does not perform parallel GTA memory, capture, focus or input work. Product IPC
advertises exact capability `fishing-notifications.events`.

The native occurrence queue is in-memory, FIFO and capped at 64. It drops a new
notification under pressure with a diagnostic count, clears at new session
preparation and never persists/replays history. All notification frames use one
Common normal-priority FIFO. Aggregate snapshots keep their existing separate
latest-only coalescing. Host validates monotonic sequence independently for
notification and snapshot streams, then supervisor adds current Engine
generation and rejects late callbacks from a retired session.

The production Telegram generation owns a second bounded queue, deduplicates
`(generation, sequence)`, discards queued events from older Engine generations
and sends sequentially to configured admins through the existing planners.
Producer, projection, planner and individual transport failures cannot stop
Host or fishing runtime. Event-pump failure does withdraw the whole generation
and enters the same indefinite capped recovery from Phase 27.

Focused acceptance is native CTest 45/45, managed IPC 7/7 and WPF/managed
209/209. It covers bounded native order/no-replay, typed mapping, generation
dedupe, delivery failure isolation, inventory-low edge behavior, event-pump
recovery and local-access UI. No GTA, capture, focus, input, credentials or
network action ran. Architecture contract: [ADR-0003](ADR-0003-BOUNDED-ENGINE-NOTIFICATION-EVENTS.md).
