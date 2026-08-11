# Sonar Fishing Engine migration

Статус: product planning baseline, implementation не начата

Дата аудита: 2026-07-23

Product decision: [ADR-0001](ADR-0001-WPF-CSHARP-CPP-ENGINE.md)

## 1. Проверенный baseline

- `src/sonar`: 88 Python files, около 35 575 физических строк.
- `tests`: 41 file, около 11 913 строк и 565 `test_*` functions.
- PySide runtime surface концентрирован в нескольких files, но
  `src/sonar/ui/main_window.py` имеет 4513 строк и является composition root.
- C#, C++, XAML и versioned IPC schema отсутствуют.
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
shutdown, forced unknown cleanup и read-only restart circuit breaker.

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
3. Python LegacyEngine за final coarse pipe contract.
4. WPF/MVVM Host против LegacyEngine.
5. C++ offline/read-only window, capture, memory и detectors.
6. Whole native reeling/state-machine capability parity.
7. Standalone C++ Engine switch только между sessions.
8. Signed App+Engine release, update, uninstall и rollback drill.
9. PySide/Python production/Nuitka removal после stable rollback window.

## 6. Blocking gates

- Effective hidden overrides не зафиксированы.
- Legacy config/history behavior не зафиксирован; target `config/state.dat`
  schema и atomic writes не готовы.
- Engine-verifiable entitlement contract отсутствует.
- CV/OCR dependency and geometry parity corpus не frozen.
- Streaming public mutation security не reviewed.
- Native toolchain/static dependency closure/symbol policy не проверена.
- Held synthetic input crash safety не доказана.
- Exact latency/queue/payload budgets не измерены.

Эти gaps не блокируют inert walking skeleton и WPF fake screen. Они блокируют
соответствующий production authority cutover.
