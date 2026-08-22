# Sonar Fishing code index

Этот индекс описывает только текущую WPF/C++ product architecture. Удаленный
Python/PySide/Nuitka owner доступен в Git history и в историческом migration
evidence, но не является частью исходников, тестов или build graph продукта.

## Product tree

```text
02_sonar_app/
  src/dotnet/Sonar.Fishing.Host/   WPF Host
  native/                          C++20 Engine capabilities
  contracts/ipc/v1/                coarse typed IPC
  tests/dotnet/                    managed/WPF/IPC tests
  tests/fixtures/                  language-neutral offline corpora
  scripts/                         PowerShell setup/test/build/run/package
  docs/architecture/               ADR, evidence, cutover checklist
  product-commands.json            Container command manifest
```

## WPF Host

### `src/dotnet/Sonar.Fishing.Host`

Runnable .NET 10 WPF application. Main owners:

- `App.xaml` and composition code - process-level application lifetime.
- `Shell/` - responsive Common app shell and page navigation.
- `HostRuntime/` - inert/demo production-facing service composition.
- `EngineIntegration/` - contained Engine generation, typed session protocol,
  heartbeat, reconnect and coarse snapshots.
- `SettingsPersistence/` - validated single-writer `config/state.dat`.
- `Licensing/` and `StartupGate/` - fail-closed admission and signed envelope
  verification through pinned Common packages.
- `FishingPage/`, `OverviewPage/`, `StatisticsPage/`, `SettingsPage/`,
  `LicensePage/`, `TelegramPage/`, `StreamingPage/`, `AboutPage/` -
  product-owned page content and actions over Common UI patterns.
- `UpdateRuntime/` - signed release transaction planning and recovery.
- `Assets/` - embedded product logo and fish images. No loose release assets.

Generated transport DTOs are not bound directly to XAML. Pages consume
presentation models and coarse runtime snapshots; no detector/frame/input step
RPC is exposed.

## C++ Engine

### `native/engine_ipc`

Offline executable and typed Host/Engine session boundary. It consumes frozen
Common native IPC, Windows safety and licensing packages. Side-effect support
remains disabled unless the explicit production admission chain is complete.

### Read-only observations

- `fishing_stage_detection/` - embedded PGM template detector.
- `game_chat/` - bounded capture/detector contracts and guarded chat episode.
- `memory_observation/` - coherent reeling, inventory, player-status and chat
  memory aggregate with generation checks.
- `catch_quality/`, `fish_identity/`, `catch_observation/` - catch identity and
  quality projections.
- `player_status/`, `inventory_stage/`, `tackle_detection/` - domain evidence
  consumed inside coarse episodes.

### Engine-owned episodes

- `fishing_episode/` - casting, hooking and reeling as one cancellable episode.
- `inventory_store/` - menu, inventory and store-fish workflow.
- `maintenance_episode/` - meal, garbage and equipment recovery workflow.
- `fishing_state_machine/` - lifecycle selection, deferral and cleanup.
- `reeling/`, `meal_system/`, `garbage_disposal/`, `equipment_recovery/` - pure
  policy components reused by whole-episode owners.

Every physical intent remains behind exact-sequence final revalidation and an
exclusive mutation lease. Offline tests do not compose live observers or Win32
mutation adapters.

### Shared session state

- `runtime_settings/` - immutable revisioned settings snapshot.
- `entitlement/` - independent raw signed-envelope verification and product
  claims policy.
- `session_statistics/` - volatile current-session metrics only.
- `catch_disposition/` - selected-fish keep/release policy.
- `input_safety/` - product admission policy over Common packet budgets.
- `runtime_preflight/` and `runtime_capture/` - target/window/capture guards,
  default-off in production composition until readiness acceptance.

## IPC contract

`contracts/ipc/v1/sonar_fishing.proto` contains only versioned coarse commands,
snapshots and events. `scripts/generate_ipc_contracts.ps1` verifies generated
managed/native artifacts with the pinned protoc executable.

## Tests and fixtures

- `tests/dotnet/Sonar.Fishing.Host.Tests` - managed units, WPF STA composition,
  rendering and lifecycle tests.
- `tests/dotnet/Sonar.Fishing.Ipc.IntegrationTests` - real contained offline
  Host/Engine handshake, settings, entitlement and crash/recovery checks.
- `tests/fixtures` - immutable TSV/image/hex/PEM corpora consumed by native and
  managed tests. They are test inputs, not runtime resources.
- Each native capability owns a focused CMake target and CTest registered under
  `native/CMakeLists.txt` and `native/CMakePresets.json`.

There are no executable oracle scripts. Accepted legacy observations are frozen
in language-neutral fixtures and asserted by current C++/C# tests.

## Product entrypoints

- `scripts/setup_native.ps1` - toolchain and immutable dependency hash gate.
- `scripts/test_no_python_runtime.ps1` - repo-wide product ownership,
  composition, bundle allowlist, EXE marker and dependency scan.
- `scripts/test_dotnet.ps1` - WPF/managed test gate.
- `scripts/test_ipc.ps1` - native build, CTest, fixture hashes, benchmarks and
  typed IPC integration.
- `scripts/test_native.ps1` - canonical combined offline test workflow.
- `scripts/test.ps1` - stable alias for `test_native.ps1`.
- `scripts/build_dotnet.ps1` - WPF Host build.
- `scripts/build_native.ps1` - checked Host/Engine build.
- `scripts/run_native.ps1` - explicit safe offline Host/Engine launch.
- `scripts/release_common.ps1` - canonical manifest, allowlist, dependency,
  signing-status, secret-marker and `%TEMP%\.net` primitives.
- `scripts/build_release_native.ps1` - two-clean-root deterministic
  framework-dependent single-file Host plus native Engine builder; production
  signing is fail closed, explicit unsigned development is supported.
- `scripts/package_native.ps1` - fail-closed release package entrypoint.
- `scripts/smoke_release_native.ps1` - packaged offline launch/exit,
  child-cleanup and crash/recovery implementation.
- `scripts/smoke_native.ps1` - fail-closed release smoke entrypoint.
- `scripts/test_release_plumbing.ps1` - manifest, lifecycle allowlist,
  tamper, csproj and PowerShell parser regression gate.
- `product-commands.json` - Russian Container-visible setup/test/build/package/
  run/smoke command manifest with no legacy adapter.

## Where to change behavior

| Задача | Owner |
| --- | --- |
| WPF page/presentation | matching `src/dotnet/Sonar.Fishing.Host/*Page/` |
| Host composition/lifecycle | `HostRuntime/`, `EngineIntegration/` |
| Engine session contract | `contracts/ipc/v1`, `native/engine_ipc`, managed integration |
| Fishing lifecycle | `native/fishing_state_machine`, `native/fishing_episode` |
| Inventory/store | `native/inventory_store` |
| Meal/garbage/equipment | `native/maintenance_episode` and focused policy modules |
| Memory observation | `native/memory_observation` |
| UI design primitive | pinned Sonar Common UI package, not local copy |
| Product branding | WPF `Assets/` and Host resource declarations |
| No-Python/build ownership | `scripts/test_no_python_runtime.ps1` |
| Production admission | `docs/migration/runtime-authority.json` and cutover checklist |
| Release bundle/signing/smoke | `scripts/*release_native.ps1`, `release_common.ps1`, [release pipeline](docs/architecture/NATIVE_RELEASE_PIPELINE.md) |

## Canonical offline gate

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\setup_native.ps1
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\test.ps1
```

Neither command opens GTA, captures a window, sends input or performs network
requests. Package, signing, live adapters and publication use separate explicit
gates.
