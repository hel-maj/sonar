# Native memory observation (E11)

## Цель и границы

E11 переносит чтение memory evidence для reeling, inventory, player status и
chat из Python в product-owned C++20 capability. Capability владеет только
read-only observation. Она не нажимает клавиши, не управляет GTA, не открывает
сетевые соединения и не предоставляет Host мелкие RPC вроде `ReadTension` или
`ReadFood`.

Текущий slice построен как Ports and Adapters плюс Aggregate Snapshot:

```text
trusted GTA module lease + same-frame visual stage
  -> reeling: Fishing capture_plan + bounded exact reads
  -> one coherent_memory_snapshot
  -> whole Engine episode policy

Common trusted Majestic content provider
  -> cancellable 500 ms inventory worker
  -> changed revisioned InventoryStateSnapshot event
```

`memory_observer::capture` является одной coarse operation. Все четыре группы
evidence получают один sequence, monotonic capture time, profile id/revision и
точные process generations. Host не участвует между observation, decision и
будущим final side-effect gate.

Inventory content намеренно не входит в latency-critical reeling capture. Его
отдельный Engine worker владеет полным Common sample, cancellation и latest-only
publication; через IPC проходит один immutable product-neutral snapshot, а не
серия V8/property RPC.

## Ownership и зависимости

- Sonar Common `SonarPlatformWindows 0.1.9` владеет least-rights
  `readonly_process`, process generation, bounded exact `ReadProcessMemory` и
  bounded `unique_top_level_client_observer` для exact process generation.
- Fishing владеет допустимыми executable names/publishers, semantic layout,
  decoder policy, cross-process ambiguity и смыслом evidence. Product policy
  требует visible non-minimized client, но сохраняет прежнюю eligibility для
  owned/tool windows; обязательный Common cap 64 fail-closed при exhaustion.
- Common `Sonar::PlatformWindowsTrustedModule` проверяет unique module,
  nonzero bounds, disk PE/loaded-size coherence, WinTrust signer/timestamp и
  cold/hot fingerprint на pinned handle. Shipping adapter не вычисляет SHA-256;
  Rockstar publisher policy остаётся product-owned. Offline ownership scan
  запрещает возвращение локального signer verifier или window enumeration.
- Common target `Sonar::PlatformInventoryState` сохраняет общую трёхзначную
  семантику `unknown/closed/open` для legacy/coarse consumers.
- Exact-pinned Common `SonarMajesticCefInventory 0.1.18` владеет production CEF
  renderer discovery, version-independent trusted-publisher identity admission,
  V8/content decoding, coherent read transaction, hot binding/provider и stable
  inventory snapshot semantics. Continuous provider отдельно включает proven
  closed-state bootstrap, поэтому закрытый inventory UI не блокирует content
  snapshot; general acquisition default остаётся strict. Fishing вызывает только public content factory
  и владеет worker cadence, product reason mapping, columns, commands, feature
  policy, IPC projection и surface composition. Manifest pin:
  `EC109F38E0F0BF1428EA63505B186022CE2116301014E0578AB0886DF7CFCF7D`.
- Historical decoder semantics сохранены в language-neutral fixture; executable
  legacy oracle и runtime fallback удалены.
- Полная разбивка historical memory/visual owners и полей находится в
  [runtime observation parity matrix](RUNTIME_OBSERVATION_PARITY.md).

Windows connector использует Common `memory_regions` access profile. Это
добавляет только least-rights region enumeration к exact read; Fishing
по-прежнему владеет scan bounds, binding и admission.

Конкретный Windows connector создается без side effect. Inventory process handle
может появиться только внутри production Engine после verified Host/Engine
handshake, отдельного non-shipping
[live observation preflight](LIVE_OBSERVATION_PREFLIGHT.md) либо forensic
characterization tool; construction и offline Engine остаются inert.
Preflight использует тот же trusted lease, semantic resolver и observer, но
не создаёт input/mutation capability и наружу отдаёт только coarse readiness.

## Profile и coherent capture

`memory_observation_profile` фиксирует:

- ASCII `profile_id` и ненулевую revision;
- executable name, admission kind и Common authority fingerprint для runtime;
  64-hex SHA-256 разрешён только exact forensic/replay profile;
- reeling layout и подтвержденный fish model hash;
- historical inventory vote candidates, минимум 6 matches и confidence 0.85,
  только для characterization/forensic replay;
- typed/scaled player-status candidates;
- required/optional domain policy.

Embedded registry schema `2` дополнительно фиксирует optional inventory
binding. У текущего shipping profile поле равно `-`: decoder/vote contract
существует, но production address authority не выдумывается из legacy bytes.

`capture_plan` содержит resolved addresses только для одной уже проверенной
process generation. Resolver обязан передать exact `(pid, creation time)` и
Common authority fingerprint для GTA/WebEngine runtime. Observer сравнивает
generation/authority до чтения, делает только exact reads и повторно
revalidate-ит lease после последнего read. PID reuse, module/file drift, short
read, partial domain decode и replayed sequence
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

- confirmed fish hash `802685111`, active и characterized `fish_caught`
  inactive byte, world positions и normalized player right vector;
- weighted inventory open/closed vote с legacy thresholds;
- WebEngine indicator records `(food, water, health)` и пары inventory/backpack
  weight;
- serialized и DOM chat evidence с active input, visibility и active tab.

Fixture читает current CTest. Negative CTest покрывает exact forensic
hash/profile drift, trusted fingerprint mismatch, short/oversize read,
process-generation drift, invalid UTF-8, unknown fish hash, ambiguous semantic
anchors/inventory vote и replayed sequence.

## Production admission и оставшиеся gaps

Normal Engine выполняет одну coarse capture operation. Positive visual reeling
trigger вызывает только Fishing `resolve_reeling` + `memory_observer::capture`;
Common inventory facade в этом path не вызывается. Остальные frames выполняют
ровно один `inventory_open_acquisition::observe()`: его cold-to-hot discovery и
double-read остаются одной Common operation. Поэтому cold CEF scan не попадает
в latency-critical A/D path.

После `unknown` product adapter повторяет cold attempt не чаще monotonic
`250 ms -> 500 ms -> 1 s -> 2 s -> 4 s`, затем сохраняет cap `4 s`. Между
deadline он создаёт свежий aggregate только с `unknown`; known `open/closed`
никогда не кэшируются и hot Common facade снова вызывается на следующем
requested frame. Смена GTA generation немедленно вызывает `reset`, очищает
backoff и требует новую observation. Screenshot detector сохраняет только
item/context geometry и никогда не превращает неизвестность в closed. Один
capture read/decode/generation drift вызывает не более одной полной
re-resolution с новым observer connection; повторный failure очищает pending
resolver state и cached observer sessions, оставаясь unknown без stale fallback.
Confirmed inactive fish остаётся pending до успешного coherent capture, поэтому
первый read/decode failure не теряет terminal transition. После commit anchor
удаляется; после исчерпания bounded retry он сбрасывается без replay.

Обычная shipping и compile-isolated `Локальный доступ` композиции создают один
Common trusted-publisher runtime с observation enabled. Common доказывает
accepted signer/timestamp, pinned file identity, dynamic PE/loaded-size
coherence и stable process generation; client version/hash/size/profile не
являются availability gates. Старый Fishing binding, exact 1.20.7 profile и его
`memory_inventory_binding_unavailable` остаются только forensic/
characterization path и не являются production authority. Ни один путь не
публикует выдуманный `open/closed`. Полная
граница и подготовленный manual evidence entrypoint описаны в
[inventory-state characterization](INVENTORY_STATE_CHARACTERIZATION.md).
Player/status/chat поля также публикуются только при наличии admitted layout;
visual evidence не выдаётся за memory evidence. E11 остаётся partial live
acceptance. Оставшиеся gates:

1. Исторический preflight 2026-08-24 зафиксировал прежний SHA-gated blocker;
   после ADR-0005 этот receipt остаётся provenance и не описывает текущий
   production admission.
2. Нужен свежий read-only live capture текущего trusted/semantic path:
   executable-section coverage, unique player/replay, exact active fish и
   coherent snapshot, плюс реальные target-loss captures.
3. Один отдельный read-only live acceptance trusted-publisher inventory path;
   authentic player status/chat captures остаются отдельными gaps. Manual
   `CLOSED/OPEN` legacy characterization больше не является runtime admission.
4. Изменившийся GTA build получает свежий Common lease и проходит те же
   semantic anchors. Новый exact profile/revision создаётся только для forensic
   provenance либо при реальном изменении layout data, не для разблокировки SHA.

Для сбора forensic evidence по конкретному hash существует отдельный non-shipping
[compatibility probe](BUILD_PROFILE_COMPATIBILITY_PROBE.md). Он deep-clone-ит
frozen baseline только в памяти, использует distinct candidate identity,
требует полную уникальность anchors, bounded entity count, ровно одну active
fish identity, coherent snapshot и post-capture revalidation. Даже успешный
candidate result не изменяет registry и не является production admission.

Единственный исторический live pass этого diagnostic 2026-08-24 подтвердил
process/window/hash и pinned baseline, но вернул `pattern_scan_incomplete`.
Он не является текущим production gate: shipping resolver теперь сам требует
полное executable-section покрытие и unique semantic anchors после Common
trusted admission. Screenshot по-прежнему не подменяет memory evidence.

Дополнительный zero-input scan legacy inventory signature на exact current hash
также вернул `0` matches даже по всем `13490` readable regions до 16 MiB.
Старый anchor имел sliding base и не имел module-rooted pointer, поэтому он
намеренно не promoted и current hash не добавлен wildcard-ом.

До выполнения этих пунктов отсутствие profile/plan дает fail-closed result, а
production bundle не включает Python memory runtime как fallback.
