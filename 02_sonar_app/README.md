# Sonar Fishing

Sonar Fishing переносится на целевую архитектуру из двух процессов:

```text
Sonar.exe          WPF / C# / .NET 10
Sonar.Engine.exe   C++20 / MSVC x64
```

Product-owned исходники, тестовые entrypoints и build graph больше не содержат
Python, PySide6, Nuitka, wheelhouse или legacy launcher. Историческое поведение
сохранено только в language-neutral fixtures и архитектурных документах.

Текущая WPF/C++ версия запускается в безопасном offline режиме. Production
package и smoke остаются fail-closed, пока machine-readable authority manifest
не подтвердит полный cutover и release pipeline. Это не мешает собирать,
тестировать и запускать offline Host/Engine без GTA, capture, input и сети.

## Структура

- `src/dotnet/Sonar.Fishing.Host` - WPF Host, MVVM, настройки, licensing,
  Telegram, streaming, update и process supervision.
- `native` - C++ Engine, detectors, memory observations, state machines,
  guarded mutation boundaries и offline IPC executable.
- `contracts/ipc/v1` - versioned coarse Host/Engine contract.
- `tests/dotnet` - managed unit, WPF STA и IPC integration tests.
- `tests/fixtures` - language-neutral TSV, images, binary fixtures и signed
  envelopes. Fixtures не входят в shipping bundle.
- `scripts` - PowerShell entrypoints целевой версии.
- `docs/architecture` - ADR, migration evidence и production cutover checklist.

Общие IPC, process supervision, licensing verification и WPF design system
потребляются как точные immutable Sonar Common packages. Исходники Common в
Fishing не копируются.

## Безопасные команды

Проверка .NET, CMake, MSVC, protoc и точных package hashes:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\setup_native.ps1
```

Полный offline test gate:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\test.ps1
```

Он запускает repository-wide no-Python ownership gate, WPF/managed tests,
native CTest и typed IPC integration. Эквивалентный явный entrypoint:
`scripts/test_native.ps1`.

Сборка текущих Host и Engine:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\build_native.ps1
```

Безопасный запуск WPF Host с inert offline Engine:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\run_native.ps1 -NoBuild
```

Команда не подключается к GTA и не разрешает capture, physical input или
network adapters.

## Package и smoke

Production-команды fail closed, пока machine-readable authority manifest не
подтвердит полный cutover. После admission package выполняет два clean build,
сверяет unsigned hashes и требует Authenticode обоих EXE:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\package_native.ps1 -Version 1.2.3
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\smoke_native.ps1 -BundleDirectory .\build\release\bundle
```

Явный unsigned dev-mode собирает тот же layout без signing и production
authority claim:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\package_native.ps1 -DevelopmentUnsigned -Version 0.0.0-dev
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\smoke_native.ps1 -DevelopmentUnsigned -BundleDirectory .\build\release\bundle
```

Перед build/launch обе команды проверяют repository-wide source ownership.
Package stage содержит пустые `config/` и `logs/`; после первого запуска
installed allowlist имеет вид:

```text
Sonar.exe
Sonar.Engine.exe
bundle-manifest.json
config/state.dat
logs/*
```

Отсутствие `config/state.dat` в свежем package является обязательным: файл
создаёт первый запуск Host для текущего Windows-пользователя, потому что его
секретные поля защищены DPAPI CurrentUser. Переносить заранее созданный
`state.dat` между пользователями или включать его в release bundle запрещено.

Loose DLL, source, wheel, interpreter, PDB, asset, database, dump и history
запрещены. Managed/native resources встраиваются в два EXE.
`Sonar.exe` требует установленный Microsoft .NET Desktop Runtime 10 x64 и не
извлекает runtime в `%TEMP%\.net`. Package/smoke ничего не публикуют и не
обновляют на сервере. Полный контракт описан в
[native release pipeline](docs/architecture/NATIVE_RELEASE_PIPELINE.md).

## Документация

- [Architecture decision](docs/architecture/ADR-0001-WPF-CSHARP-CPP-ENGINE.md)
- [Engine migration evidence](docs/architecture/ENGINE_MIGRATION.md)
- [Production cutover checklist](docs/architecture/PRODUCTION_CUTOVER_CHECKLIST.md)
- [Native release pipeline](docs/architecture/NATIVE_RELEASE_PIPELINE.md)
- [UI parity ledger](docs/architecture/UI_PARITY_LEDGER.md)
- [Code index](CODE_INDEX.md)

Live GTA/window/capture/input/network проверки требуют отдельного readiness
gate и не входят в обычные setup/test/build команды.
