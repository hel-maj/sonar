# Native release pipeline

## Цель и границы

Product repository владеет воспроизводимой сборкой и проверкой целевого
Fishing bundle. Pipeline не выполняет upload и не меняет release metadata на
сервере. Детерминированные package/smoke gates не подключают GTA, захват, ввод
или сетевые product adapters; отдельная normal-lifecycle проверка использует
фактический no-argument Host и поэтому сохраняет production startup/network
admission без отправки команд автоматизации.

Shipping layout ограничен пятью корневыми entry:

```text
Sonar.exe
Sonar.Engine.exe
bundle-manifest.json
config/
logs/
```

`Sonar.exe` — framework-dependent WPF single-file. Assembly identity остаётся
`Sonar.Fishing.Host`, а готовый single-file получает release-имя `Sonar.exe`.
Это сохраняет embedded WPF pack resources без loose assets. На машине нужен
глобальный `Microsoft.WindowsDesktop.App` 10 x64; self-contained extraction в
`%TEMP%\.net` запрещён.

`Sonar.Engine.exe` — один native C++20 executable. Managed/native packages,
protobuf code, logo, fish catalog и изображения встроены в два EXE.

## Entrypoints

Production package:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\package_native.ps1 `
  -Version 1.2.3
```

Production smoke существующего bundle:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\smoke_native.ps1 `
  -BundleDirectory .\build\release\bundle
```

Machine-readable authority подтверждает native Host/Engine cutover. Production
package дополнительно требует валидные значения
следующих environment-bound inputs:

- `SONAR_FISHING_SIGNTOOL` — точный локальный `signtool.exe`;
- `SONAR_FISHING_SIGNING_CERT_THUMBPRINT` — SHA-1 thumbprint сертификата в
  Windows certificate store;
- `SONAR_FISHING_TIMESTAMP_URL` — HTTPS timestamp endpoint без credentials.

Секретный ключ не передаётся скрипту и не сохраняется в репозитории. Production
режим требует `Valid` Authenticode у обоих EXE. Timestamp/signing являются
отдельной внешней границей; обычные setup/test команды их не вызывают.

Явный локальный unsigned режим предназначен только для разработки:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\package_native.ps1 `
  -DevelopmentUnsigned -Version 0.0.0-dev
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\smoke_native.ps1 `
  -DevelopmentUnsigned -BundleDirectory .\build\release\bundle
```

`-SkipOfflineTests` разрешён только вместе с `-DevelopmentUnsigned` и нужен
для повторной локальной диагностики сразу после отдельно зафиксированного full
gate. Production не позволяет пропускать тесты. `-StaticOnly` также доступен
только для unsigned development smoke.

Product-owned local maintenance для той же development-unsigned пары:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\invoke_local_release_maintenance.ps1 `
  -Action Install -SourceBundle .\build\release\bundle `
  -InstallDirectory .\build\sonar-fishing-local -DevelopmentUnsigned
```

`Update`/`Rollback` требуют новый внешний backup, `Recover` принимает только
одну точную interrupted generation, а `-DryRun` не меняет состояние. Wrapper
запускает bounded maintenance mode самого проверенного `Sonar.exe`; UI,
production runtime, сеть и GTA при этом не создаются.

`SourceBundle`, `InstallDirectory` и `BackupDirectory` допускаются только как
строгие потомки канонического ignored `build/`. Wrapper до создания receipt и
запуска executor отклоняет сам build-root, `scripts/`, `src/`, внешний путь,
неверный тип пути и любой существующий reparse-компонент. Отклонение не меняет
ни целевой каталог, ни receipt state.

Обычный запуск проверенного bundle:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\run_product.ps1 `
  -BundleDirectory .\build\release\bundle
```

Скрипт проверяет manifest/hashes/runtime и запускает `Sonar.exe` без аргументов.
Он не подменяет normal composition на demo/offline и не ослабляет product gates.

Sustained normal-lifecycle acceptance готового unsigned bundle:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\test_product_lifecycle.ps1 `
  -DevelopmentUnsigned -BundleDirectory .\build\release\bundle -DurationSeconds 30
```

Проверка использует чистый copied state, дожидается дочернего production Engine,
наблюдает Host/Engine 30, 60 или 120 секунд и закрывает Host через normal window
lifecycle. Signed startup admission остаётся обязательным; отсутствие допуска
или production Engine является честным failure, а не поводом перейти в demo.

## Clean-build и manifest

`build_release_native.ps1` создаёт два чистых build root под `build/`,
восстанавливает managed dependencies только из локального immutable feed,
публикует Host через isolated `.NET --artifacts-path` и собирает Engine через
MSVC `/Brepro`. Source и generated-output paths отображаются в канонические
виртуальные корни. До signing SHA-256 обоих EXE обязан совпасть между build A и
build B в production режиме.

`bundle-manifest.json` имеет `schemaVersion: 1`, canonical compact UTF-8/LF
encoding и строгий порядок/набор полей. Он связывает:

- product, release mode и semantic version;
- Git commit и dirty-state build input;
- exact IPC schema path/hash;
- Host/Engine path, final hash, unsigned hash и derived build ID;
- required Desktop Runtime topology;
- second-build hashes и determinism result;
- Authenticode requirement/status обоих EXE.

Reader отклоняет unknown/missing/reordered fields, неканоничные bytes,
несовпадающий mode/path/hash/schema и недоказанный production determinism или
signature status.

## Static и lifecycle gates

Package stage требует пустые `config/` и `logs/`. `config/state.dat` не является
shipping input: его атомарно создаёт первый запуск Host для текущего
Windows-пользователя, поскольку секретные поля защищены DPAPI CurrentUser.
Installed stage требует ровно `config/state.dat`; внутри `logs/` разрешены
только прямые `*.log`. Reparse points, DLL/assets/PDB/dumps/databases/history и
любой другой loose entry отклоняются.

Каждый package/smoke выполняет:

1. repository-wide no-Python ownership self-test и scan;
2. canonical manifest и exact SHA-256 validation;
3. allowlist и reparse-point validation для текущей lifecycle stage;
4. PE marker/dependency scan без Python/PySide/Nuitka/interpreter imports;
5. strict system-DLL dependency closure обоих EXE;
6. high-confidence private-key/Telegram-token marker scan;
7. production Authenticode validation.

Полный offline smoke копирует bundle в новый install root и по умолчанию трижды
запускает настоящий packaged Host в network-inert `--demo`, ждёт `state.dat` и
окно, затем закрывает Host штатно с нулевым exit code. Packaged production Engine намеренно не
получает offline-diagnostic authority: отдельный managed probe загружает
идентичность прямо из фактического manifest/Host/Engine pair, применяет полный
settings snapshot, проверяет containment и heartbeat, доказывает fail-closed
отказ Start без signed entitlement, принудительно завершает процесс и поднимает
новый contained PID; этот crash/replacement probe также повторяется в каждом
цикле. После каждого bounded disposal процессов из exact bundle не остаётся. До/после
сравнивается `%TEMP%\.net`; update/rollback residue запрещён.

Закрытием окна владеет один Host lifecycle owner. Повторный `Close` всегда
откладывается как минимум до следующего dispatcher turn, поэтому синхронный
`StopAsync` не входит повторно в WPF closing state machine. На lifecycle stop
выделено 10 секунд: fault или timeout завершают Host с fail-closed exit code 6,
а release smoke отклоняет любой ненулевой код и оставшийся процесс. Regression
tests отдельно покрывают синхронное завершение, fault и never-completing stop.
Startup fault проходит отдельный controlled shutdown с exit code 7; поздний
`ContentRendered` после terminal stop не перезапускает Telegram/license/Engine.

Local development-unsigned install/update/rollback/interrupted recovery теперь
имеют отдельный product-owned after-exit executor и offline acceptance.
Remote production update, signed activation/uninstall и production-signed
installation остаются отдельными gates. Native cutover уже зафиксирован;
unsigned smoke не является доказательством signing или live GTA acceptance.

## Offline acceptance receipt 2026-08-24

- Host/WPF focused gate: `194/194`, warnings/errors `0/0`;
- native CTest: `41/41`; typed IPC integration: `7/7`;
- deterministic offscreen UI matrix: 180 PNG для compact/medium/expanded
  layouts и 100/125/150/200% DPI в `build/ui-gallery-0218-final/`; manifest
  фиксирует Common UI `0.2.18` и имеет SHA-256
  `6487F1A9783BD7DD4EB7A7805F90402500FC4A3D914BF60E8A98C9A840BA0386`;
- network-inert demo Host прошёл три start/normal-exit цикла, а packaged
  manifest-bound Engine — три crash/replacement/cleanup цикла;
- lifecycle-labelled exact allowlist/no-Python gates зелены для package,
  first activation, normal exit, crash recovery, update, interrupted-update
  recovery и remote rollback fixtures;
- product navigation/focus и hotkey suppression regressions покрывают
  Alt-Tab/focus-loss policy offline; фактическое foreground switching не
  выполнялось;
- product-visible XAML/view-model copy и regression
  `all_product_pages_hide_implementation_copy` не содержат migration,
  language, Host/Engine/IPC или architecture status;
- development bundle проверен как exact two-EXE/no-Python package;
  оба EXE имеют ожидаемый `NotSigned`. Exact SHA-256:
  `Sonar.exe=36D1B588BFFE4B30E125D126F2B22C8AC641526968510D71B87BD2E28D5866C1`,
  `Sonar.Engine.exe=D162D5A403296085D18D4F18B5E60F178B5FDBB2F603BA11FD84FA96E1B2B6D5`,
  `bundle-manifest.json=E941F958DF0FC455DBA5F8181D0F8223D9C2435687CBA0425FC6A8F75032766B`.

- local development-unsigned wrapper фактически прошёл atomic install,
  update с Common UI `0.2.17` на `0.2.18`, rollback и synthetic interrupted
  recovery; каждый этап повторил exact allowlist/no-Python gate и не оставил
  transaction residue;
- новых Fishing Application Error 1000 или .NET Runtime 1026 после финальных
  package/lifecycle gates не зарегистрировано.

Production signing сейчас заблокирован отсутствием
`SONAR_FISHING_SIGNING_CERT_THUMBPRINT` и `SONAR_FISHING_TIMESTAMP_URL`.
Также ещё нет production metadata endpoint/public key, licensed update
composition и принятого подписанного after-exit activator/uninstaller; локальный
development-unsigned executor не является этим production доказательством.
Поэтому signed install/update/interrupted-update/remote-rollback не помечаются
как выполненные. Единственный read-only build-compatibility pass вернул
`pattern_scan_incomplete`, поэтому текущий GTA profile не admitted и
active-reeling/inventory physical-input acceptance не выполнялась.
