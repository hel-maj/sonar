# Native memory observation (E11)

## Цель и границы

E11 переносит чтение memory evidence для reeling, inventory, player status и
chat из Python в product-owned C++20 capability. Capability владеет только
read-only observation. Она не нажимает клавиши, не управляет GTA, не открывает
сетевые соединения и не предоставляет Host мелкие RPC вроде `ReadTension` или
`ReadFood`.

Текущий slice построен как Ports and Adapters плюс Aggregate Snapshot:

```text
versioned target resolver (pending production profile)
  -> capture_plan + expected process generations
  -> memory_connector (disabled by default)
  -> bounded exact reads
  -> pure domain decoders
  -> one coherent_memory_snapshot
  -> Engine episode policy (pending composition)
```

`memory_observer::capture` является одной coarse operation. Все четыре группы
evidence получают один sequence, monotonic capture time, profile id/revision и
точные process generations. Host не участвует между observation, decision и
будущим final side-effect gate.

## Ownership и зависимости

- Sonar Common `SonarPlatformWindows 0.1.1` владеет least-rights
  `readonly_process`, process generation и bounded exact `ReadProcessMemory`.
- Fishing владеет допустимыми executable names/hashes, адресным profile,
  decoder policy и смыслом evidence.
- Fishing adapter добавляет SHA-256 проверку image file, но не дублирует
  `OpenProcess`, `ReadProcessMemory`, enumeration или generation logic Common.
- Historical decoder semantics сохранены в language-neutral fixture; executable
  legacy oracle и runtime fallback удалены.

Конкретный Windows connector создается без side effect. Он получает process
handle только после явного вызова `capture` с валидным profile и plan.
Production Engine composition сейчас вообще не создает Windows connector;
единственная готовая default composition seam - `disabled_memory_connector`.

## Profile и coherent capture

`memory_observation_profile` фиксирует:

- ASCII `profile_id` и ненулевую revision;
- exact executable name и 64-hex SHA-256 для GTA и WebEngine;
- reeling layout и подтвержденный fish model hash;
- inventory vote candidates, минимум 6 matches и confidence 0.85;
- typed/scaled player-status candidates;
- required/optional domain policy.

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

E11 offline capability и platform adapter готовы, но live composition намеренно
закрыта. До изменения статуса E11 на done нужны:

1. Подписанный и воспроизводимый profile для точных production builds GTA и
   Majestic WebEngine: executable hashes, resolver strategy и decoder layouts.
2. Product target resolver, который получает process generations через Common и
   создает bounded address plan без абсолютных stale addresses.
3. Engine composition внутри whole fishing episode, без Host field RPC.
4. Guarded live-readiness review и отдельное разрешение пользователя перед
   первым GTA attach. Offline tests не являются таким разрешением.
5. Реальные multi-build/profile-drift captures и capture-loss recovery evidence.

До выполнения этих пунктов отсутствие profile/plan дает fail-closed result, а
production bundle не включает Python memory runtime как fallback.
