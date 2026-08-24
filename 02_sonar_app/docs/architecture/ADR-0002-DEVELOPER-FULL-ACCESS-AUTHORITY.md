# ADR-0002: compile-isolated developer-full-access authority

Статус: accepted, 2026-08-24.

## Контекст

Владельцу продукта нужна локальная сборка, в которой можно проверять весь
доступный runtime без обращения к production licensing backend. Обычный
`-DevelopmentUnsigned` решает только вопрос подписи локального package и не
изменяет runtime authority. Превращать его в неявный обход лицензии нельзя:
такой bundle мог бы случайно попасть в install, update или production launch.

При этом licensing gate является только одним из уровней допуска. Exact GTA
build profile, coherent memory/capture snapshot, актуальные bounds окна,
foreground, input lease, packet budget и final safety gate должны оставаться
обязательными. Developer mode не должен подменять неподдерживаемый game build
guess-профилем и не должен воспроизводить runtime/input authority после crash.

## Решение

Вводится отдельный compile-time вариант Host и Engine с явным режимом
`developer-full-access`.

- Host принимает `--developer-full-access` только когда собран с
  `SonarFishingDeveloperFullAccess=true`.
- Engine принимает `SONAR_FISHING_ENGINE_MODE=developer-full-access` только
  когда собран с `SONAR_FISHING_DEVELOPER_FULL_ACCESS=ON`.
- Developer Host использует production composition и снимает только внешние
  signed startup availability/update-block, licensing admission, signed
  entitlement и feature entitlement gates. Сохранённое
  состояние лицензии может оставаться частью атомарного `state.dat` snapshot,
  но local authority его не применяет, не обновляет и не выдаёт Engine как
  signed entitlement.
- Engine получает bounded bootstrap entitlement только после успешной exact
  проверки developer manifest и pair identity. Все game/window/memory/capture,
  foreground, input и final safety gates остаются теми же, что в production.
- Ordinary production binaries не содержат compile symbol и отвергают
  developer argument/mode.

Это не общий пользовательский release channel. Он предназначен для локального
access bundle владельца и не подписывается production certificate.

## Bundle identity и изоляция

Обычные `development-unsigned` и `production-signed` manifests сохраняют
`schemaVersion: 1`. Local-access bundle использует отдельную identity:

```text
schemaVersion: 2
releaseMode: developer-full-access-unsigned
developerFullAccess: true
```

Manifest содержит exact SHA-256 и build id обоих EXE. Host передает Engine
только значения из уже проверенного colocated manifest, а Engine требует exact
developer mode и полную bootstrap identity. Production manifest loader,
`run_product.ps1` и local install/update/rollback verifier не принимают schema 2
или developer marker. Developer verifier, наоборот, требует оба признака и не
принимает ordinary bundle.

Отдельные entrypoints:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\build_developer_full_access.ps1
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\verify_developer_full_access.ps1
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\run_developer_full_access.ps1
```

Builder делает два clean deterministic build и по умолчанию кладет результат в
`build/developer-full-access/bundle` с версией `1.0.0-local`. Verify проверяет exact manifest, hashes,
обязательный `determinism.verified: true`, двухфайловый dependency closure,
no-Python ownership и отсутствие секретов.
Run всегда сначала выполняет быстрый launch admission, затем передает
единственный явный developer argument. Admission проверяет schema/channel,
local-access marker, canonical manifest, hashes/build IDs пары EXE,
deterministic marker, строгий bundle allowlist и Desktop Runtime, но не повторяет
offline suites, repository-wide no-Python scan, dependency closure или secret
scan. Полный verify остаётся отдельной явной командой. Launcher совместим с
Windows PowerShell 5.1 и имеет `-VerifyOnly`, чтобы regression-проверка могла
подтвердить admission и launch arguments без открытия UI.

Product presentation не показывает этот internal mode. License page отображает
активный `Локальный доступ`, скрывает key activation и заменяет raw feature IDs
понятными названиями только реально скомпонованных функций. Capability без
production owner, включая текущие Stream и stream chat, не попадает в local
feature set. Технический channel, marker и compile provenance
остаются в manifest и diagnostic log.

## Crash и recovery invariant

Неожиданное завершение Engine немедленно отзывает authority завершившегося
generation и публикует fail-closed idle snapshot. Supervisor создает replacement
с capped exponential backoff и передает ему последнюю полную settings snapshot.
Для developer bundle новое bootstrap authority создается только новым exact
Host/Engine handshake.

Supervisor не воспроизводит automation start/stop, input leases или runtime
commands. Он также отвергает конфликт, если session одновременно объявляет
bootstrap developer authority и cached signed entitlement. Этот no-replay
invariant одинаков для production и local-access mode.

Каждое поколение Engine получает заново построенное authority environment:
Host удаляет унаследованные reciprocal offline/production mode и build-identity
variables до записи режима текущей session. Поэтому stale parent environment не
может превратить recovery в повтор одного и того же bootstrap failure.

Coarse automation command имеет десятисекундный supervisor deadline. Потерянный
reply или correlated snapshot отзывает generation и authority, после чего
обычный capped recovery запускает свежий процесс без replay команды. Если новый
Engine отверг cached signed envelope, он остается живым без authority: cache
отзывается, а уже проверенный свежий envelope может быть применен в той же
activation/refresh operation без restart-loop.

## Последствия

Плюсы:

- владелец может проверять product runtime без production licensing backend;
- обычная production сборка физически не умеет принимать developer state;
- developer package нельзя случайно открыть ordinary launcher или провести
  через local release transaction;
- runtime safety model и unsupported-build admission не ослабляются.

Ограничения:

- режим не делает неподдерживаемый GTA build поддерживаемым;
- режим не добавляет отсутствующие Streaming, Telegram или update adapters;
- реальный capture, foreground и physical input по-прежнему требуют отдельный
  live gate и не являются частью offline build/verify;
- local-access bundle не предназначен для распространения пользователям.

## Проверки

Regression coverage обязана доказывать:

1. production Host и Engine отвергают developer mode;
2. developer-compiled Host и Engine принимают только exact marked bundle;
3. ordinary manifest verifier и local maintenance отвергают developer bundle;
4. developer verifier отвергает ordinary или partially marked bundle;
5. crash отзывает authority, восстанавливает settings и не воспроизводит
   automation/input commands;
6. package содержит только разрешенные файлы и не содержит Python runtime;
7. обычные production tests проходят без developer compile symbol.
8. local-access UI не запрашивает ключ и не показывает raw feature IDs или
   internal build terminology.

## Rollback и условие удаления

Rollback состоит в удалении трех developer entrypoints, schema 2 branch,
compile symbols и этой ADR. Ordinary schema 1 release pipeline при этом не
меняется. Режим можно удалить, когда production availability/licensing backend
и отдельный staging entitlement дают владельцу эквивалентный безопасный доступ
без локального bypass.

## Skills audit

Проверены `sonar-fishing-workflow` и `sonar-fishing-release-workflow`. Их
ownership и safety routing уже покрывают product authority, release verification
и live gates. Новый режим является product-specific implementation detail,
поэтому канонические skills менять не требуется.
