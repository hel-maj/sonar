# Native casting, hooking and reeling episode

## Goal и граница

`SonarFishingEpisode` переносит в C++ Engine один цельный cancellable workflow:

```text
E14 stage + semantic cast/hook cue + same-cycle E11 memory
  -> cast decision and confirmation
  -> hook decision and confirmation
  -> E13 reeling estimator/policy/stabilizer
  -> immediate final mutation gate
  -> bounded terminal confirmation and unconditional A/D cleanup
```

Host не получает frame, memory field, detector step, `PressA`, `PressD`,
`DetectHook` или `CastStep`. Public runtime surface остается coarse
`run/cancel/result` внутри Engine composition.

Не входят в этот slice:

- tackle/storage preparation: это отдельный inventory/store episode;
- реализация capture и semantic cast/hook detectors: они принадлежат E14;
- catch-screen OCR и catch-resolution;
- production process/window/input adapter или live GTA admission;
- fine-grained Host RPC и fallback input в Host.

## Trace текущего поведения

До реализации были зафиксированы historical effective paths, включая runtime
override `bot_adjustments.py`. После parity gate эти paths удалены из product
tree и доступны только в Git history:

- `_prepare_fishing_start` выбирает `casting`, `hooking` или `reeling` по
  `start1`, `start2`/`wait_tension`, `ad`;
- `_casting_control_loop` ждет semantic green-zone cue до 10 секунд, выполняет
  один short Space pulse и ждет переход до 8 секунд;
- `_do_hooking` ждет red/bubbles cue до 60 секунд, выполняет один Space pulse и
  подтверждает следующую стадию до 3 секунд;
- `_run_reeling_module` допускает до 180 секунд, потребляет memory motion,
  удерживает только A/D и всегда вызывает tracker cleanup;
- language-neutral `tests/fixtures/fishing_episode/e13-v1.tsv` и current native
  tests сохраняют observable rules без executable oracle.

## Contracts и invariants

### Coherent observation

`fishing_episode_observation` несет один monotonic sequence/time. Если E11
memory присутствует, его sequence/time обязаны точно совпасть с outer cycle.
Profile id/revision и GTA/WebEngine `(pid, creation time)` замораживаются по
первому memory sample; drift завершает episode до следующей mutation.

E14 stage проверяется по каноническим trigger mappings:

| Stage | Trigger |
|---|---|
| casting | `start1` |
| waiting | `start2` или `wait_tension` |
| reeling | `ad` |

Cast cue допустим только на casting stage, hook cue только на waiting stage.
Ambiguous confidence/cue combinations, non-finite geometry, stale sequence,
missing E11 reeling evidence и unconfirmed stage loss fail closed.

### Whole episode state machine

Runner может безопасно начать с casting, waiting или reeling, чтобы пережить
Engine restart/replay на границе стадии. Tackle-selection намеренно отклоняется,
поскольку этот episode не владеет storage/tackle действиями.

Bounds сохраняют current effective policy: 10-second cast wait, 8-second cast
confirmation, 60-second hook wait, 3-second hook confirmation, 180-second
reeling и 260-second total deadline. Дополнительно действует hard limit 8,192
observations; default request использует 4,096.

Reeling использует существующие `FishVelocityTracker`,
`ProjectedVelocityPolicy`, `MoveStabilizer` и `ProjectInputIntent`. Episode
добавляет только ownership sequence и не дублирует их EMA/deadband policy.

### Mutation authority

`fishing_mutation_port::acquire` получает один exclusive Engine input lease на
весь episode, но не является authorization. Каждая `apply()` обязана прямо
перед matching side effect повторно проверить:

- exact observation sequence;
- signed entitlement revision;
- accepted settings revision;
- lifecycle revision/actionability;
- exact process/window generation и foreground identity;
- Common input packet budget.

Cast/hook Space pulses и A/D switch являются typed Engine intents. На normal,
failed и cancelled terminal path выполняется один bounded best-effort A/D
cleanup. Cleanup не разрешает новую action и не должен пропускаться только из-за
cancel/entitlement revocation; exact target identity все равно обязателен.

Shipping composition использует только `disabled_fishing_mutation_port`,
который не приобретает lease и не запускает observer. Никакой concrete live
mutation adapter этим slice не подключен.

## Offline acceptance

Language-neutral replay находится в
`tests/fixtures/fishing_episode/e13-v1.tsv`: 19 rows / 6 episodes, SHA-256
`48BE8A7AEC802A0F9950A5C1E497DC204B5D09795E77527D17BBFFA47706B349`.
Он покрывает full cast-hook-reel, resume на waiting/reeling, manual reeling
input-off, catch terminal, cast/hook timeouts и unconfirmed reeling stage loss.

Native tests дополнительно проверяют:

- default-off и disabled composition без observation/action;
- stale sequence, E11 profile revision и process-generation drift;
- cue/stage ambiguity;
- settings, entitlement, lifecycle, foreground и packet-budget final gates;
- cancellation после принятой mutation;
- cleanup failure, который отменяет успешный result;
- invalid hook enum и observation-budget exhaustion;
- один lease и один cleanup на episode.

Focused Release acceptance: MSVC v143 `/W4 /WX`, CTest `1/1`; effective legacy
casting/hooking/reeling characterization `149/149`. Five equal 100,000-episode
replay runs measured range `82.3207-85.5194 ms`, median `83.9312 ms` /
`839.312 ns` per complete episode and deterministic checksum `2300000`. New
Host/Engine IPC operations/bytes are `0/0`. No hotspot was demonstrated, so no
semantic optimization followed parity.

Combined canonical Phase 39/40 acceptance is WPF `155/155`, native IPC CTest
`25/25` and managed IPC `6/6`, with warnings/errors `0/0` and green managed and
native source-ownership scans. The unchanged six-operation inert Engine path
measured `39.864 ms` bootstrap, `44.555 ms` scenario, `93.480 ms`
start-through-exit, `0.000 ms` sampled CPU and `7,254,016` bytes peak working
set. E13 adds no offline Host command or IPC operation.

## Production gaps и rollback

Offline episode не означает production authority. До production cutover нужны:

1. native E14 cast/hook semantic detectors с frozen authentic corpora;
2. approved signed E11 build/address profile и target resolver;
3. один shared lease implementation для всех Engine input episodes;
4. guarded Common process/window/input adapter с immediate final gate;
5. hard-crash key cleanup/restart evidence и real multi-build target-loss gate;
6. signed entitlement admission и final two-EXE bundle matrix.

Rollback прост: не подключать production mutation port. Disabled composition
остается fail closed; legacy runtime fallback отсутствует, а accepted evidence
сохранено в language-neutral fixtures.
