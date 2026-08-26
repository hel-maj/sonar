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

Native configure exact-pins installed
`SonarMajesticCefInventory 0.1.19` / `Sonar::MajesticCefInventory` /
`Sonar::MajesticCefInventoryContent`. Setup, full
offline gate и оба clean release build проверяют SHA-256 manifest
`1426967DC010CCDA80749DF15B6C3ADE8C3318A7FE63A21E6378FD69F787A612` и каждый
listed payload. Sibling Common checkout и loose runtime dependency запрещены.

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

Отдельный compile-isolated local-access channel не является вариантом обычного
`-DevelopmentUnsigned`:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\build_developer_full_access.ps1
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\verify_developer_full_access.ps1
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\run_developer_full_access.ps1
```

Эта пара снимает только внешние licensing/entitlement и signed startup
availability/update-block admission gates и сохраняет production window,
process/generation, foreground, capture, input и final safety gates.
Inventory-open использует тот же Common trusted-publisher runtime, что и
ordinary shipping; exact client profiles остаются forensic-only. Builder по
умолчанию маркирует версию как `1.0.0-local`; product UI
показывает `Локальный доступ` без key activation, raw feature IDs или internal
channel. Ordinary `run_product.ps1` и ordinary maintenance channel намеренно
отвергают её; отдельный maintenance channel требует оба явных switch
`-DevelopmentUnsigned -DeveloperFullAccess`.
Local-access run выполняет только быстрый manifest/hash/allowlist/runtime
admission; offline suites, source ownership, dependency closure и secret scan
остаются в build и отдельной verify-команде.
Полный security contract описан в
[ADR-0002](ADR-0002-DEVELOPER-FULL-ACCESS-AUTHORITY.md).
Inventory dependency/retry contract: [ADR-0004](ADR-0004-COMMON-CEF-INVENTORY-OPEN.md).

Product-owned local maintenance для той же development-unsigned пары:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\invoke_local_release_maintenance.ps1 `
  -Action Install -SourceBundle .\build\release\bundle `
  -InstallDirectory .\build\sonar-fishing-local -DevelopmentUnsigned
```

Product-owned local maintenance для compile-isolated local-access пары:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\invoke_local_release_maintenance.ps1 `
  -Action Install -SourceBundle .\build\developer-full-access\bundle `
  -InstallDirectory .\build\sonar-fishing-local-access `
  -DevelopmentUnsigned -DeveloperFullAccess
```

Manifest schema/channel проверяются повторно внутри самого `Sonar.exe`;
cross-channel source/target/backup отклоняются до swap.

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

Compile-isolated local-access bundle проходит тот же crash/recovery и повторный
запуск с явным launch contract:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\test_product_lifecycle.ps1 `
  -DeveloperFullAccess -BundleDirectory .\build\developer-full-access\bundle -DurationSeconds 30
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

Обычный `bundle-manifest.json` имеет `schemaVersion: 1`, canonical compact
UTF-8/LF encoding и строгий порядок/набор полей. Отдельный local-access manifest
имеет `schemaVersion: 2`, release mode
`developer-full-access-unsigned` и обязательный marker
`developerFullAccess: true`. Обычный reader не принимает schema 2; developer
reader требует exact schema, mode и marker. Каждый вариант связывает:

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

## Offline acceptance receipts 2026-08-24

- Host/WPF focused gate: `209/209`, warnings/errors `0/0`;
- native CTest: `48/48`; typed IPC integration: `7/7`;
- deterministic offscreen UI matrix: 180 PNG для compact/medium/expanded
  layouts и 100/125/150/200% DPI в `build/ui-gallery-0219-final/`; manifest
  фиксирует Common UI `0.2.20` и имеет SHA-256
  `FD257489E58A3F69A154A54AD176447775981A51FCE0D1744EF6A8369305AD49`;
- network-inert demo Host прошёл три start/normal-exit цикла, а packaged
  manifest-bound Engine — три crash/replacement/cleanup цикла;
- lifecycle-labelled exact allowlist/no-Python gates зелены для package,
  first activation, normal exit, crash recovery, update, interrupted-update
  recovery и remote rollback fixtures;
- product navigation/focus и hotkey suppression regressions покрывают
  Alt-Tab/focus-loss policy offline; установленная local-access сборка также
  прошла фактический foreground round-trip, шесть размеров окна и два
  minimize/restore без смены Engine generation;
- product-visible XAML/view-model copy и regression
  `all_product_pages_hide_implementation_copy` не содержат migration,
  language, Host/Engine/IPC или architecture status;
- previous ordinary development bundle был проверен как exact
  two-EXE/no-Python package до текущего notification/local-access rebuild;
  оба EXE имеют ожидаемый `NotSigned`. Exact SHA-256:
  `Sonar.exe=36D1B588BFFE4B30E125D126F2B22C8AC641526968510D71B87BD2E28D5866C1`,
  `Sonar.Engine.exe=D162D5A403296085D18D4F18B5E60F178B5FDBB2F603BA11FD84FA96E1B2B6D5`,
  `bundle-manifest.json=E941F958DF0FC455DBA5F8181D0F8223D9C2435687CBA0425FC6A8F75032766B`.
- historical compile-isolated local-access bundle `1.0.2-local` собран без
  `SkipOfflineTests`, verified как deterministic exact two-EXE/no-Python pair:
  `Sonar.exe=C8AD5AEE5EFB793BAB7E780D5C84C90FF6409761F316893B99CBDDD39A56450E`,
  `Sonar.Engine.exe=6706F65B7E5518A658A55F873C148EDA4288F07A2AFF3B0A82FC72BA44602D74`,
  `bundle-manifest.json=A7F4CEC3AC6C13CE772A534BF2256806E2715073A97A24D47007CC211E9B4942`.
  На установленной копии выполнены 100 последовательных navigation actions и
  100 toggle actions: Host оставался responsive, save-toast не появлялся,
  исходное значение настройки сохранилось. Принудительное завершение Engine
  создало новое поколение, после чего вернулись coherent inventory snapshot с
  `45` позициями и весом `21,72 / 40 кг` и все catalog images;
- current compile-isolated local-access bundle `1.0.3-local` собран после exact
  repin на `SonarMajesticCefInventory 0.1.18` и `Sonar.UI.Wpf 0.2.21` без
  `SkipOfflineTests`: `216/216` WPF, `50/50` native CTest и `7/7` typed IPC
  tests зелёные, две независимые сборки детерминированы, exact two-EXE
  allowlist/no-Python gate пройден. Bundle hashes:
  `Sonar.exe=566DEEE058F0AAB5BD7CAE6701120AB09BE6FC7657C2F32561E4234CD58BEE9E`,
  `Sonar.Engine.exe=1219052544A02A6F98AB8FD37F014E2B48DC4602CFC606FAD84F87A0BF32B4AD`,
  `bundle-manifest.json=248076B764D7986EA9526E246A18ABAE839965B69D6983B483C513EDF0658E7F`.
  Фактический update установленной `1.0.2-local` принят как `1.0.3-local`, а
  отдельный 30-секундный lifecycle подтвердил Engine crash/replacement, два
  normal exit и повторный exact allowlist/no-Python gate;
- current Common UI 0.2.21 visual artifact находится в
  `build/ui-gallery-0221-final/`: 204 PNG для всех product pages/variants,
  compact/medium/expanded layouts и 100/125/150/200% DPI. Manifest фиксирует
  `CommonUiVersion=0.2.21` и имеет SHA-256
  `43A2D07AEACEC9ACFE493DBF8D204EBA23333467B9C3DE3C7C7F9FE1F58DA00C`;

- local development-unsigned wrapper исторически прошёл atomic install,
  update с Common UI `0.2.17` на `0.2.18`, rollback и synthetic interrupted
  recovery; этот historical exact repin `0.2.20` отдельно прошёл package-hash,
  build, `215/215` WPF tests и 180-image UI gate. Каждый выполненный transaction
  stage повторял exact allowlist/no-Python gate и не оставил residue;
- новых Fishing Application Error 1000 или .NET Runtime 1026 после финальных
  package/lifecycle gates не зарегистрировано.

Production signing сейчас заблокирован отсутствием
`SONAR_FISHING_SIGNING_CERT_THUMBPRINT` и `SONAR_FISHING_TIMESTAMP_URL`.
Также ещё нет production metadata endpoint/public key, licensed update
composition и принятого подписанного after-exit activator/uninstaller; локальный
development-unsigned executor не является этим production доказательством.
Поэтому signed install/update/interrupted-update/remote-rollback не помечаются
как выполненные. Исторический forensic pass вернул
`pattern_scan_incomplete`, но после ADR-0005 exact GTA profile не управляет
shipping availability. Свежая trusted/semantic active-reeling и inventory
read-only acceptance, а затем отдельная physical-input acceptance, ещё не
выполнялись.
