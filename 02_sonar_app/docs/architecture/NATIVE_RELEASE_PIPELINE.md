# Native release pipeline

## Цель и границы

Product repository владеет воспроизводимой сборкой и проверкой целевого
Fishing bundle. Pipeline не выполняет upload, не меняет release metadata на
сервере и не подключает GTA, захват, ввод или сетевые product adapters.

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

Обе команды fail closed, пока machine-readable authority не подтверждает Host
и Engine cutover. Production package дополнительно требует валидные значения
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

Полный offline smoke копирует bundle в новый install root, запускает настоящий
packaged Host в network-inert `--demo`, ждёт `state.dat` и окно, затем закрывает
Host штатно с нулевым exit code. Packaged production Engine намеренно не
получает offline-diagnostic authority: отдельный managed probe загружает
идентичность прямо из фактического manifest/Host/Engine pair, применяет полный
settings snapshot, проверяет containment и heartbeat, доказывает fail-closed
отказ Start без signed entitlement, принудительно завершает процесс и поднимает
новый contained PID. После bounded disposal процессов не остаётся. До/после
сравнивается `%TEMP%\.net`; update/rollback residue запрещён.

Закрытием окна владеет один Host lifecycle owner. Повторный `Close` всегда
откладывается как минимум до следующего dispatcher turn, поэтому синхронный
`StopAsync` не входит повторно в WPF closing state machine. На lifecycle stop
выделено 10 секунд: fault или timeout завершают Host с fail-closed exit code 6,
а release smoke отклоняет любой ненулевой код и оставшийся процесс. Regression
tests отдельно покрывают синхронное завершение, fault и never-completing stop.

Update, interrupted update, remote rollback, after-exit activation/uninstall и
production-signed installation остаются отдельными acceptance gates. Успешный
unsigned development smoke не переводит `production_cutover` в `true`.
