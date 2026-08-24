# Native memory observation (E11)

## Цель и границы

E11 переносит чтение memory evidence для reeling, inventory, player status и
chat из Python в product-owned C++20 capability. Capability владеет только
read-only observation. Она не нажимает клавиши, не управляет GTA, не открывает
сетевые соединения и не предоставляет Host мелкие RPC вроде `ReadTension` или
`ReadFood`.

Текущий slice построен как Ports and Adapters плюс Aggregate Snapshot:

```text
exact product target resolver
  -> explicit reeling or inventory_state capture scope
  -> capture_plan + expected process generations
  -> least-rights Windows memory_connector
  -> bounded exact reads
  -> pure domain decoders
  -> one coherent_memory_snapshot
  -> whole Engine episode policy
```

`memory_observer::capture` является одной coarse operation. Все четыре группы
evidence получают один sequence, monotonic capture time, profile id/revision и
точные process generations. Host не участвует между observation, decision и
будущим final side-effect gate.

## Ownership и зависимости

- Sonar Common `SonarPlatformWindows 0.1.6` владеет least-rights
  `readonly_process`, process generation и bounded exact `ReadProcessMemory`.
- Fishing владеет допустимыми executable names/hashes, адресным profile,
  decoder policy и смыслом evidence.
- Fishing adapter добавляет SHA-256 проверку image file, но не дублирует
  `OpenProcess`, `ReadProcessMemory`, enumeration или generation logic Common.
- Common target `Sonar::PlatformInventoryState` нормализует только общую
  трёхзначную семантику `unknown/closed/open`; Fishing по-прежнему владеет
  profile candidates, vote/confidence admission и surface geometry.
- Historical decoder semantics сохранены в language-neutral fixture; executable
  legacy oracle и runtime fallback удалены.

Windows connector использует Common `memory_regions` access profile. Это
добавляет только least-rights region enumeration к exact read; Fishing
по-прежнему владеет scan bounds, binding и admission.

Конкретный Windows connector создается без side effect. Process handle появляется
только внутри явно запущенной production fishing session, отдельного
non-shipping [live observation preflight](LIVE_OBSERVATION_PREFLIGHT.md) либо
явно подтверждённого inventory characterization tool.
Preflight использует тот же embedded build selection, resolver и observer, но
не создаёт input/mutation capability и наружу отдаёт только coarse readiness.

## Profile и coherent capture

`memory_observation_profile` фиксирует:

- ASCII `profile_id` и ненулевую revision;
- exact executable name и 64-hex SHA-256 для GTA и WebEngine;
- reeling layout и подтвержденный fish model hash;
- inventory vote candidates, минимум 6 matches и confidence 0.85;
- typed/scaled player-status candidates;
- required/optional domain policy.

Embedded registry schema `2` дополнительно фиксирует optional inventory
binding. У текущего shipping profile поле равно `-`: decoder/vote contract
существует, но production address authority не выдумывается из legacy bytes.

`capture_plan` содержит resolved addresses только для одной уже проверенной
process generation. Resolver обязан передать exact `(pid, creation time)` для
GTA и WebEngine. Observer сравнивает generation до чтения, делает только exact
reads и повторно проверяет обе generation после последнего read. PID reuse,
image/hash drift, short read, partial domain decode и replayed sequence
инвалидируют весь aggregate. Предыдущее значение не возвращается как свежее.

Один цикл ограничен следующими hard bounds:

| Contract | Limit |
| --- | ---: |
| regions per capture | 96 |
| bytes per region | 256 KiB |
| bytes per aggregate | 1 MiB |
| inventory candidates | 80 |
| player-status scalar candidates | 48 |

Common дополнительно ограничивает один exact read 1 MiB. E11 использует более
узкий product limit 256 KiB.

## Decoder parity

Language-neutral fixture
`tests/fixtures/memory_observation/e11-v1.tsv` фиксирует observable legacy
semantics:

- confirmed fish hash `802685111`, active byte, world positions и normalized
  player right vector;
- weighted inventory open/closed vote с legacy thresholds;
- WebEngine indicator records `(food, water, health)` и пары inventory/backpack
  weight;
- serialized и DOM chat evidence с active input, visibility и active tab.

Fixture читает current CTest. Negative CTest покрывает hash/profile drift,
short/oversize read, process-generation drift, invalid UTF-8, unknown fish
hash, ambiguous inventory vote и replayed sequence.

## Production admission и оставшиеся gaps

Normal Engine теперь маршрутизирует reeling и inventory разными capture scopes.
Inventory поэтому не требует active fish. Если exact build profile содержит
binding, resolver выполняет bounded cold discovery, revalidates cached masked
signatures на каждом плане и после drift делает ровно одну bounded rediscovery.
Неудачная cold discovery не повторяется каждый frame: typed failure удерживает
пятисекундный cooldown перед следующей bounded попыткой и оставляет state
`unknown`. Screenshot detector сохраняет только
item/context geometry и никогда не превращает неизвестность в closed.

Shipping registry пока не содержит ни одного admitted inventory binding, а
actual current hash вообще не admitted. Следовательно, current runtime
возвращает typed `profile_unavailable` / `memory_game_build_unsupported`;
`memory_inventory_binding_unavailable` относится к старому admitted profile без
binding. Ни один путь не публикует выдуманный `open/closed`. Полная
граница и подготовленный manual evidence entrypoint описаны в
[inventory-state characterization](INVENTORY_STATE_CHARACTERIZATION.md).
Player/status/chat поля также публикуются только при наличии admitted layout;
visual evidence не выдаётся за memory evidence. E11 остаётся partial live
acceptance. Оставшиеся gates:

1. Первый guarded read-only preflight 2026-08-24 подтвердил process/window,
   executable hash-read и capture, но exact profile selection fail-closed
   вернул `game_build_unsupported`; reeling memory не читалась.
2. Реальные profile-drift, target-loss и reeling captures.
3. Один controlled manual `CLOSED/OPEN` characterization current build,
   автономный signature/root review и immutable inventory binding promotion;
   authentic player status/chat captures остаются отдельными gaps.
4. Любой новый GTA build получает новый immutable profile/revision и regression
   evidence; silent wildcard profile запрещён.

Для сбора evidence по unsupported hash существует отдельный non-shipping
[compatibility probe](BUILD_PROFILE_COMPATIBILITY_PROBE.md). Он deep-clone-ит
frozen baseline только в памяти, использует distinct candidate identity,
требует полную уникальность anchors, bounded entity count, ровно одну active
fish identity, coherent snapshot и post-capture revalidation. Даже успешный
candidate result не изменяет registry и не является production admission.

Единственный live pass этого diagnostic 2026-08-24 подтвердил process/window,
hash и pinned baseline, но вернул `pattern_scan_incomplete`; identity и coherent
snapshot остались false. Production memory authority поэтому всё ещё не
принимает текущую build, а screenshot не подменяет open-state evidence.

Дополнительный zero-input scan legacy inventory signature на exact current hash
также вернул `0` matches даже по всем `13490` readable regions до 16 MiB.
Старый anchor имел sliding base и не имел module-rooted pointer, поэтому он
намеренно не promoted и current hash не добавлен wildcard-ом.

До выполнения этих пунктов отсутствие profile/plan дает fail-closed result, а
production bundle не включает Python memory runtime как fallback.
