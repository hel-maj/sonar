# Sonar Fishing

Sonar Fishing работает на целевой native-архитектуре из двух процессов:

```text
Sonar.exe          WPF / C# / .NET 10
Sonar.Engine.exe   C++20 / MSVC x64
```

Product-owned исходники, тестовые entrypoints и build graph больше не содержат
Python, PySide6, Nuitka, wheelhouse или legacy launcher. Историческое поведение
сохранено только в language-neutral fixtures и архитектурных документах.

Обычный product entrypoint — `Sonar.exe` без аргументов. Он создаёт production
Host/Engine composition; запуск рыбалки остаётся fail-closed до действующей
подписанной лицензии, согласованного окна игры и всех runtime-safety gates.
`--demo` и `--offline-engine <path>` сохранены только как явные режимы разработки.

## Структура

- `src/dotnet/Sonar.Fishing.Host` - WPF Host, MVVM, настройки, licensing,
  глобальная start/stop hotkey, Telegram и process supervision. Streaming и
  general-update cores остаются fail-closed до перечисленных production
  prerequisites.
- `native` - C++ Engine, detectors, memory observations, state machines,
  guarded mutation boundaries и offline IPC executable.
- `contracts/ipc/v1` - versioned coarse Host/Engine contract.
- `tests/dotnet` - managed unit, WPF STA и IPC integration tests.
- `tests/fixtures` - language-neutral TSV, images, binary fixtures и signed
  envelopes. Fixtures не входят в shipping bundle.
- `scripts` - PowerShell entrypoints целевой версии.
- `docs/architecture` - ADR, migration evidence и production cutover checklist.

Общие IPC, process supervision, licensing verification и `Sonar.UI.Wpf 0.2.19`
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

Native gate собирает generated Visual Studio graph одним `ALL_BUILD` с
ограниченным parallelism. После configure скрипт проверяет, что каждый
обязательный target существует в solution и является уникальным прямым
`ProjectReference` в `ALL_BUILD.vcxproj`; обязательные имена CTest также должны
быть уникальны и присутствовать, а дополнительные найденные тесты разрешены и
тоже запускаются. Перед build удаляются только точные шесть benchmark EXE и два
Engine EXE внутри проверенного build root, после чего `ALL_BUILD` обязан создать
их заново. Старый бинарник не может подменить пересборку или успешный тест.

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

Одноразовая read-only проверка реального observation path выполняется только
после свежего явного подтверждения:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\run_live_observation_preflight.ps1 -ConfirmedLiveReadOnly
```

Она не запускает GTA и не отправляет input: проверяются exact target/focus,
supported build profile, один frame + detector и один bounded memory aggregate.
В stdout выходит только coarse readiness JSON. Полный протокол и причины
отказа описаны в
[live observation preflight](docs/architecture/LIVE_OBSERVATION_PREFLIGHT.md).

Если preflight вернул `game_build_unsupported`, новый hash не подставляется в
production автоматически. Для одной отдельной evidence-проверки существует
diagnostic-only команда:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\run_build_profile_compatibility_probe.ps1 -ConfirmedLiveBuildProfileCompatibility
```

Она требует foreground active-reeling state, выполняется без кадра и ввода и
только проверяет frozen layout как in-memory candidate. Даже успешный результат
не добавляет production profile. Точный контракт описан в
[build-profile compatibility probe](docs/architecture/BUILD_PROFILE_COMPATIBILITY_PROBE.md).

## Обычный запуск готовой версии

Сначала соберите локальный двухфайловый bundle, затем запустите его без
development-аргументов:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\package_native.ps1 -DevelopmentUnsigned -Version 0.0.0-dev
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\run_product.ps1 -BundleDirectory .\build\release\bundle
```

`run_product.ps1` проверяет canonical manifest, hashes и наличие .NET Desktop
Runtime 10 x64, после чего запускает `Sonar.exe` с пустым списком аргументов.
Это обычная версия приложения, а не demo/offline режим. Наличие команды запуска
не обходит лицензию, startup availability, target, foreground или input-safety
проверки.

Для локальной проверки владельцем существует отдельный compile-isolated bundle:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\build_developer_full_access.ps1
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\verify_developer_full_access.ps1
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\run_developer_full_access.ps1
```

`build_developer_full_access.ps1` принимает `-Version` и `-OutputDirectory`;
`-SkipOfflineTests` предназначен только для промежуточной разработки.
`verify_developer_full_access.ps1` и `run_developer_full_access.ps1` принимают
`-BundleDirectory`, а run дополнительно поддерживает `-Wait`. Внутренний
`-VerifyOnly` проверяет WinPS-compatible launch contract без запуска UI и
используется regression-тестом.

Builder по умолчанию использует стабильную локальную версию `1.0.0-local`.
Product UI показывает активный `Локальный доступ`, не просит ключ и не выводит
raw feature IDs или технический channel. В local feature set входят только
capabilities с реальным production owner; пока недоступные Stream и stream chat
не выдаются и не рекламируются как работающие. Техническая provenance остается
в manifest и diagnostic log.

Он собирается в `build/developer-full-access/bundle`, имеет manifest schema 2,
channel `developer-full-access-unsigned` и marker
`developerFullAccess: true`. Режим снимает только внешние licensing/entitlement
и signed startup availability/update-block admission gates:
verify требует подтвержденные одинаковые clean-build hashes;
exact game build, coherent memory/capture, актуальное окно, foreground, input
lease и final safety gates не ослабляются. Production EXE не принимает
`--developer-full-access`, а ordinary run/install/update/rollback entrypoints
отвергают такой bundle. Подробный контракт находится в
[ADR-0002](docs/architecture/ADR-0002-DEVELOPER-FULL-ACCESS-AUTHORITY.md).

Точная матрица того, что работает в normal launch, а что остаётся выключенным
до конкретного внешнего/архитектурного prerequisite, находится в
[production cutover checklist](docs/architecture/PRODUCTION_CUTOVER_CHECKLIST.md#матрица-доступных-функций-normal-launch).
Сопоставление каждой исторической пользовательской функции с native owner и
runtime dependency находится в
[product function audit](docs/architecture/PRODUCT_FUNCTION_AUDIT.md).

Устойчивость именно готового bundle можно проверить без отправки команд
автоматизации:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\test_product_lifecycle.ps1 -DevelopmentUnsigned -BundleDirectory .\build\release\bundle -DurationSeconds 30
```

Проверка запускает Host без аргументов, дожидается production Engine, наблюдает
оба процесса и закрывает Host штатно. Она использует реальный startup endpoint,
поэтому его signed admission остаётся обязательным.

## Package и smoke

Native cutover отражён в machine-readable authority manifest. Подписанный
package выполняет два clean build, сверяет unsigned hashes и требует
Authenticode обоих EXE:

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

Smoke по умолчанию выполняет три независимых network-inert demo start/exit и
три packaged production Engine crash/replacement цикла. Он не отправляет
команду рыбалки, не захватывает GTA и после каждого цикла проверяет отсутствие
процессов из изолированной копии.

Локальную development-unsigned установку, обновление, откат или interrupted
recovery выполняет только product-owned after-exit executor:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\invoke_local_release_maintenance.ps1 -Action Install -SourceBundle .\build\release\bundle -InstallDirectory .\build\sonar-fishing-local -DevelopmentUnsigned
```

Для `Update` и `Rollback` нужна новая пустая `-BackupDirectory`; `-DryRun`
проверяет точные source/target/backup без изменения файлов. One-time import
старой лицензии выполняется действием `ImportLicense`: переносится только ключ
в DPAPI `state.dat`, а неподписанные id/role/features/timestamps игнорируются и
должны быть повторно подтверждены backend.

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
- [Developer full-access authority](docs/architecture/ADR-0002-DEVELOPER-FULL-ACCESS-AUTHORITY.md)
- [Bounded Engine notification events](docs/architecture/ADR-0003-BOUNDED-ENGINE-NOTIFICATION-EVENTS.md)
- [Engine migration evidence](docs/architecture/ENGINE_MIGRATION.md)
- [Production cutover checklist](docs/architecture/PRODUCTION_CUTOVER_CHECKLIST.md)
- [Native release pipeline](docs/architecture/NATIVE_RELEASE_PIPELINE.md)
- [Live observation preflight](docs/architecture/LIVE_OBSERVATION_PREFLIGHT.md)
- [Build-profile compatibility probe](docs/architecture/BUILD_PROFILE_COMPATIBILITY_PROBE.md)
- [Product function audit](docs/architecture/PRODUCT_FUNCTION_AUDIT.md)
- [UI parity ledger](docs/architecture/UI_PARITY_LEDGER.md)
- [Code index](CODE_INDEX.md)

Bounded read-only process/memory probe без требуемого user state, foreground,
capture, overlay или input может выполняться автономно. Если требуется exact
game state/foreground, capture/recording, interactive overlay или input, одна
fresh readiness покрывает одну заранее подготовленную попытку; обычные
setup/test/build команды остаются offline.
