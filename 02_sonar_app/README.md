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
  глобальная start/stop hotkey, Telegram и process supervision. Compile-isolated
  Local Access также владеет embedded streaming composition; ordinary licensed
  streaming, stream chat и general-update activation остаются fail-closed до
  перечисленных production prerequisites.
- `native` - C++ Engine, detectors, memory observations, state machines,
  guarded mutation boundaries и offline IPC executable.
- `contracts/ipc/v1` - versioned coarse Host/Engine contract.
- `tests/dotnet` - managed unit, WPF STA и IPC integration tests.
- `tests/fixtures` - language-neutral TSV, images, binary fixtures и signed
  envelopes. Fixtures не входят в shipping bundle.
- `scripts` - PowerShell entrypoints целевой версии.
- `docs/architecture` - ADR, migration evidence и production cutover checklist.

Общие IPC, process supervision, licensing verification,
`Sonar.UI.Wpf 0.2.21`, `SonarPlatformWindows 0.1.9`,
`SonarMajesticCatalog 1.0.0` и CEF inventory facade
`SonarMajesticCefInventory 0.1.19` потребляются как точные immutable Sonar
Common packages. Setup/release проверяют manifest facade с SHA-256
`1426967DC010CCDA80749DF15B6C3ADE8C3318A7FE63A21E6378FD69F787A612`
из Sonar Common commit `0c4baf0391134f05edd9a62e154001decb593c49` и все
перечисленные payloads; исходники или sibling checkout Common не используются.
Inventory content и GTA reeling runtime используют Common trusted-publisher
facades: точная версия, hash, размер, PE timestamp и заранее известный loaded
image size остаются forensic evidence и не являются availability gate. Reeling
дополнительно требует unique executable-section player/replay/fish anchors и
coherent capture под тем же Common authority fingerprint. Inventory facade
выводит semantic binding из bounded coherent proof и публикует product-neutral
open/weight/grid/item snapshot через отдельный Engine worker; неполный или
нестабильный proof fail-closed возвращает unavailable без last-known replay.

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
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\run_native.ps1
```

Команда не подключается к GTA и не разрешает capture, physical input или
network adapters. По умолчанию она сначала собирает актуальные Host и offline
Engine, поэтому старый output не может получить новые аргументы запуска.
`-NoBuild` предназначен только для файлов, уже собранных из текущего checkout.

Одноразовая read-only проверка реального observation path запускается явной
командой; отдельный confirmation toggle не дублируется:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\run_live_observation_preflight.ps1
```

Она не запускает GTA и не отправляет input: проверяются exact target/focus,
Common trusted module, unique semantic anchors, один frame + detector и один
bounded memory aggregate.
В stdout выходит только coarse readiness JSON. Полный протокол и причины
отказа описаны в
[live observation preflight](docs/architecture/LIVE_OBSERVATION_PREFLIGHT.md).

Exact hash не подставляется в production: он вообще не является runtime gate.
Для отдельной forensic evidence-проверки существует diagnostic-only команда:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\run_build_profile_compatibility_probe.ps1
```

Она требует foreground active-reeling state, выполняется без кадра и ввода и
только проверяет frozen layout как in-memory candidate. Даже успешный результат
не выдаёт production authority: shipping resolver выполняет собственную
trusted/semantic проверку. Точный контракт описан в
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

Run не повторяет offline suites, repository-wide no-Python scan, dependency
closure и secret scan. Перед каждым стартом он выполняет только launch admission:
проверяет exact local-access manifest, hashes и build IDs пары EXE,
deterministic marker, строгий allowlist bundle и Desktop Runtime. Полная
проверка остаётся отдельной командой `verify_developer_full_access.ps1`.

Builder по умолчанию использует стабильную локальную версию `1.0.0-local`.
Product UI показывает активный `Локальный доступ`, не просит ключ и не выводит
raw feature IDs или технический channel. В local feature set входят только
capabilities с реальным owner: Stream доступен через exact embedded-tool
composition, а пока отсутствующий stream chat не выдаётся и не рекламируется
как работающий. Техническая provenance остается в manifest и diagnostic log.

Он собирается в `build/developer-full-access/bundle`, имеет manifest schema 2,
channel `developer-full-access-unsigned` и marker
`developerFullAccess: true`. Режим снимает только внешние licensing/entitlement
и signed startup availability/update-block admission gates:
verify требует подтвержденные одинаковые clean-build hashes;
exact game build, coherent memory/capture, актуальное окно, foreground, input
lease и final safety gates не ослабляются. Production EXE не принимает
`--developer-full-access`, а ordinary run и ordinary maintenance channel
отвергают такой bundle. Тот же product-owned maintenance executor принимает
его только при одновременных явных `-DevelopmentUnsigned` и
`-DeveloperFullAccess`; смешивание каналов запрещено. Подробный контракт находится в
[ADR-0002](docs/architecture/ADR-0002-DEVELOPER-FULL-ACCESS-AUTHORITY.md).

Отдельная проверка локальной сборки запускает её дважды, принудительно завершает
только точную дочернюю Engine первого запуска и требует автоматического
восстановления, сохранения настроек и штатной очистки процессов:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\test_product_lifecycle.ps1 -DeveloperFullAccess -BundleDirectory .\build\developer-full-access\bundle -DurationSeconds 30
```

Inventory-open в обычной и compile-isolated композиции использует один и тот же
Common trusted-publisher runtime. Локальный доступ не меняет publisher,
file/process identity, generation или semantic gates. Exact profile 1.20.7
сохранён только для forensic replay и characterization и не является runtime
fallback. Детали coarse capture и retry находятся в
[ADR-0004](docs/architecture/ADR-0004-COMMON-CEF-INVENTORY-OPEN.md).

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

Для постоянно используемой сборки с локальным доступом действует отдельный
канал той же атомарной транзакции:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\invoke_local_release_maintenance.ps1 -Action Install -SourceBundle .\build\developer-full-access\bundle -InstallDirectory .\build\sonar-fishing-local-access -DevelopmentUnsigned -DeveloperFullAccess
```

Обычная команда не принимает local-access manifest, а local-access команда не
принимает ordinary manifest. Обе повторно проверяют exact manifest, hashes,
build IDs, allowlist и отсутствие Python после каждого изменяющего этапа.

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
