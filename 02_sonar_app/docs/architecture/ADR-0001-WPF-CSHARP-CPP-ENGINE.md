# ADR-0001: Sonar Fishing WPF Host и C++ Engine

Статус: accepted

Дата: 2026-07-23

Владелец: Sonar Fishing

## Контекст

Текущий Sonar Fishing является одним Python/PySide process. `MainWindow`
одновременно создает config, license, statistics, history, bot, chat и
streaming, а `FishingBot` владеет capture, memory, vision, state machines и
input. Фактическое behavior дополнительно меняется import-hook и monkeypatch
overrides, поэтому прямой rewrite одного `bot.py` не даст parity.

Требуется сохранить текущий design и behavior, перенести UI на C#, повысить
стоимость reverse engineering product logic и не включить IPC в millisecond
game loops.

## Решение

Sonar Fishing выпускает один самостоятельный versioned bundle:

```text
Sonar.exe                   WPF / C# / .NET 10 LTS / MVVM
            |
            | secured versioned Named Pipe
            v
Sonar.Engine.exe            native x64 C++20 / MSVC
```

Это product-owned build, installer, update и rollback. Он не зависит от Sonar
Hunting build, общего установленного Engine, Container checkout или будущего
пользовательского Launcher. Возможный Launcher позже только запускает готовый
Fishing bundle и не становится runtime supervisor.

Shared transport/security/lifecycle semantics определяются Common:

- `Sonar Common/docs/architecture/ADR-0001-WPF-CSHARP-CPP-NAMED-PIPE.md`;
- `Sonar Common/docs/architecture/NAMED_PIPE_PROTOCOL.md`.

Fishing владеет product `.proto`, commands, snapshots, events, reasons,
automation policy, build/protection и release recipe.

## Host ownership

WPF Host использует MVVM и pinned `CommunityToolkit.Mvvm`.

- Views: XAML, templates, visual state и view-only behavior.
- ViewModels: presentation state, validation и coarse commands.
- Application: use cases, navigation, snapshot mapping и projections.
- Infrastructure: Engine supervisor/client, `config/state.dat`, licensing,
  update, Telegram, streaming и OS adapters.
- Composition root: единственное concrete wiring и explicit lifetimes.

Generated protobuf DTO не bind-ятся к XAML. ViewModel не содержит fishing
policy, capture/memory/input и не строит chain мелких RPC.

Host является single writer persisted config/license state. Persistent user
history не переносится; statistics существуют только в памяти текущей session.
Engine events bounded и in-memory, без cross-restart outbox.

Пользователь вводит license key один раз. Backend обменивает его на
machine-bound opaque refresh credential; raw key отбрасывается. Credential
защищается DPAPI в `config/state.dat`, а Engine получает только short-lived
signed entitlement одним coarse command.

## Engine ownership

C++ Engine владеет:

- process/window/capture/memory/input resources;
- player/inventory observations и vision/OCR detectors;
- complete fishing state machine;
- casting, hooking, catch и storage episodes;
- atomic reeling control loop;
- bait, meal, garbage и tackle policy;
- game chat focus/capture/click/type/confirmation;
- final entitlement/focus/physical/config safety gates;
- cleanup/release recovery, пока процесс жив.

Capture/memory sample, detection, decision, final gate и input не разделяются
Named Pipe. Hard native crash не гарантирует key-up; held-input capability
блокируется до отдельного crash-safe pulse/lease proof.

## Transitional architecture

1. Зафиксировать effective Python behavior со всеми overrides.
2. Выделить `EngineFacade`, immutable config/events и composition root без
   behavior change.
3. Запустить Python LegacyEngine за final coarse Named Pipe contract.
4. Перенести UI на WPF/MVVM против LegacyEngine.
5. Портировать C++ capabilities через offline replay и read-only shadow.
6. Переключать whole capability и затем final Engine только между sessions.

Временный target-quality native module внутри Python LegacyEngine допустим
только для whole atomic capability с coarse run/cancel/snapshot bridge. Он не
является protection boundary, не вызывает Python на каждый sample и имеет
removal criteria.

## Build и rollback

Fishing build выпускает одну совместимую activation unit со steady-state
allowlist:

```text
Sonar.exe
Sonar.Engine.exe
bundle-manifest.json
config/
  state.dat
logs/
  *.log
```

WPF Host - framework-dependent `.NET 10` single-file с explicit Microsoft .NET
Desktop Runtime prerequisite и без `%TEMP%\.net` extraction. XAML/BAML, managed
resources, native dependencies, layouts, models, templates и deterministic data
representations встроены в два Authenticode-signed EXE. Loose
DLL/assets/data/SQLite/PDB/dumps/history запрещены.

External signed manifest содержит opaque IDs, required runtime, versions,
Host/Engine и schema/content hashes без license/PII/raw variant. Download может
быть file-level или delta, но Host/Engine активируются только парой. Update
использует temporary staging/backup и удаляет их после success/failure recovery.
Поздний rollback повторно скачивает предыдущий персонализированный bundle.

Release pipeline обязан валить сборку, если allowlist нарушен после install,
first activation, normal launch/exit, crash recovery, successful/interrupted
update или remote rollback, либо если изменился `%TEMP%\.net`.

Nuitka onefile остается operational release truth до фактического принятия
нового pipeline.

## Consequences и gates

- C++ повышает стоимость анализа, но не хранит backend private keys.
- Два toolchains и process contract увеличивают build/test complexity.
- Python остается offline oracle/tooling после production removal.
- WPF cutover и C++ Engine cutover могут происходить в разных releases.
- UI redesign, resolution remediation и language port выполняются отдельно.
- Детальный порядок и evidence находятся в [ENGINE_MIGRATION.md](ENGINE_MIGRATION.md).
