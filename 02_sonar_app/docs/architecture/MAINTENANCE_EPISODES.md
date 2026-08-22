# Native maintenance episodes (E16-E18)

Статус: Phase 40 offline boundary реализована; production composition и
physical authority отсутствуют.

## Goal и граница

`SonarFishingMaintenanceEpisode` переносит цельные legacy routines питания,
удаления мусора, проверки снастей и восстановления после уведомления о
приманке в C++ Engine. Это один coarse application boundary поверх E15
inventory session, а не набор Host RPC для capture, решения и отдельных
клавиш.

Owner и dependency direction:

```text
E11 coherent evidence + product detector observations
                         |
                         v
             maintenance_episode runner
             /        |        |       \
          meal     garbage   tackle    bait
             \        |        |       /
              E15 inventory_episode_context
                         |
        exact-sequence inventory_mutation_port
                         |
               disabled shipping adapter
```

Модуль переиспользует pure `meal_recovery`, `garbage_disposal`,
`equipment_recovery`, E11 player/reeling evidence, E15 surface/item observation
и полный validated `RuntimeSettingsSnapshot`. Он не владеет capture, WinAPI,
OCR/template assets, Common packet budget, entitlement transport или Host UI.

## Episode invariants

- Один E15 session выполняет initial foreground intent, release-all,
  observation, operation, close/resume и failure cleanup. Maintenance operation
  не получает второй mutation adapter и не может обойти exact observation
  sequence.
- `maintenance_observer::current_maintenance()` обязан соответствовать всему
  E15 inventory snapshot, включая ordered item identities, compartment,
  confidence, normalized bounds и context action. Несогласованный aggregate
  блокируется до product decision.
- Live mutation не включена: `disabled_inventory_mutation_port` остаётся
  единственной готовой composition. `runtime-authority.json` фиксирует
  `live_observer_composed=false`, `live_mutation_composed=false`,
  `host_command=false`, `side_effects=false`.
- Cancellation, stale sequence, invalid settings/geometry, rejected final gate
  и ambiguous confirmation fail closed. После локального failure один bounded
  cleanup сначала выпускает все клавиши, затем закрывает context/inventory;
  rejected mutation или cancellation не переиспользуются как cleanup authority.
- Все item targets заданы instance id и normalized bounds. Resolution, DPI и
  absolute screen coordinates не входят в contract.

## Preserved behavior

### E16 meal/player-status recovery

- Product priority сохраняет `irp -> donut -> cocktail` отдельно для player
  inventory и backpack.
- E11 food/water являются предпочтительным typed evidence; hunger/thirst HUD
  triggers используются только когда core status отсутствует.
- Один consume ждёт legacy 6 секунд и принимается только после исчезновения
  exact instance и уменьшения доступного player-food set. Backpack move
  принимается только если exact instance сменил compartment либо число того же
  canonical item в player inventory увеличилось.
- До 10 consumptions и 5 backpack moves. Отсутствие еды закрывает inventory и
  требует bounded HUD/status confirmation. `continue` отключает дальнейший
  meal search до ручного restart; `stop`, `exit_game`, `shutdown_pc` становятся
  typed terminal intent и подавляют fishing resume.
- Закрытие использует фактический `inventory_hotkey`, а не literal `i`.

### E17 garbage disposal

- Включённые `corn`, `bag`, `pack` берутся из полного settings snapshot.
- Pure planner сохраняет confidence-descending stable order. После каждого
  atomic discard новый snapshot полностью пересчитывает candidates, поэтому
  UI reflow не переносит старые coordinates.
- Успех требует исчезновения exact instance и уменьшения числа выбранных
  garbage items. Loop ограничен 128 подтверждёнными removals.

### E18 tackle and bait recovery

- Tackle сохраняет priority `rod, reel, line, hook, bait, net`, allowed-without
  leader/net warnings и session-start net semantics. Obscured scan ждёт
  `6s + 3 x 2s`; terminal depletion должна повториться в двух fresh reads через
  500 ms. Изменившееся показание завершает episode без terminal mutation.
- Effective bait override сохраняет порядок: read-only preflight делает
  3-second cooldown advance до reeling/no-notice checks и завершает эти ветви
  без mutation. Recovery делает bounded stage exit (около 5 секунд) и до 10
  restart attempts по 1.5 секунды.
- Если reeling начинается после первого `Esc`, второй `Esc` не отправляется;
  episode блокируется и выполняет release-all cleanup. Failed restart даёт
  typed stop outcome.

## Offline fixtures и acceptance

Language-neutral corpus
`tests/fixtures/maintenance_episode/episode-v1.tsv` содержит 27 observation
rows / 5 episodes и SHA-256
`F4ED4238EEDB677620C4AFEABCAAEEA62F61EA97F33775567643269376BF7BBA`.
Он фиксирует backpack move + consume, meal depletion `continue`, two-item
garbage reflow, double-confirmed tackle stop и bait exit/restart.

Native regressions дополнительно покрывают exact aggregate coherence, stale
confirmation, disabled adapter, rejected terminal final gate, exact meal/
backpack/garbage confirmation, unconfirmed tackle depletion, reeling during
bait exit, cancellation и invalid settings/kind. Focused MSVC v143 Release
acceptance: `/W4 /WX`, CTest `2/2` вместе с изменённым E15 suite.

Пять replay runs по 100,000 already-admitted tackle episodes дали median
`69.784 ms` / `697.842 ns` per episode, range `68.888-69.949 ms`, checksum
`1699995`. Capture, detector, sleeps, process/window validation и physical
input исключены. Hotspot не обнаружен; после parity не менялись retries,
timings, sorting или confirmation semantics.

Combined canonical `setup_native.ps1` + `test_native.ps1` acceptance после
Phase 39/40: WPF `155/155`, native IPC CTest `25/25`, managed IPC `6/6`, build
warnings/errors `0/0`, managed/native source-ownership scans green. Inert
Engine сохранил 6 IPC operations: bootstrap `39.864 ms`, scenario `44.555 ms`,
start-through-exit `93.480 ms`, sampled CPU `0.000 ms`, peak working set
`7,254,016` bytes. Maintenance и fishing episodes не добавлены в offline IPC
command surface, поэтому их operation/byte delta остаётся `0/0`.

## Remaining production gates

Phase 40 не переводит authority и не закрывает E16-E18 полностью. Нужны:

1. product-owned tackle/item/meal/garbage detector output и guarded E11/E14
   composition с signed build/profile inputs;
2. один shared exclusive live mutation lease с immediate entitlement,
   settings/lifecycle revision, process/window generation, foreground и Common
   packet-budget revalidation для каждого intent;
3. compose the product's verified signed-entitlement admission and freshness
   revision into every immediate mutation check; Phase 40 itself does not
   grant automation or terminal authority;
4. offline target-loss, process exit и hard-crash cleanup tests, затем отдельный
   explicit live-readiness gate для multi-resolution confirmation;
5. production composition, package allowlist и start/exit/crash/update/rollback
   release matrix. Ни один из этих gates не выполнялся в Phase 40.
