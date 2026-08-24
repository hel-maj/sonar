# Sonar Fishing migration performance evidence

Статус: active offline baseline

Дата измерения: 2026-08-22

## Правило оптимизации

Language parity, behavior change и optimization выполняются отдельными steps.
После каждого принятого parity slice измеряются startup, CPU, memory, IPC и
релевантный hot path. Оптимизация разрешена только для продемонстрированного
hotspot, не меняет observable semantics и повторяет focused/full gates.

Если baseline не показывает проблему, код не усложняется speculative cache,
pool, SIMD, batching или изменением algorithm/timing policy. Для любой будущей
оптимизации этот документ фиксирует before/after на одной машине, одинаковой
Release configuration и одинаковом corpus.

## Measurement environment

- CPU: Intel Core Ultra 7 265K.
- OS: Windows 11 IoT Enterprise 10.0.26200.
- .NET SDK: 10.0.400.
- CMake: 4.4.2.
- Native: MSVC v143 x64 Release, `/W4 /WX`.
- Common native: immutable 0.1.1 manifest SHA-256
  `695B6BFAD82A3052A5021BA55F9F833D81672DA755BF98626CC66CFB3DACAE0C`.
- Common native Windows: immutable 0.1.1 manifest SHA-256
  `EE61031CBC06550FD478892EFECD250FD4786790C5687F260B2D40B85B5C9446`.
- Common WPF: immutable `Sonar.UI.Wpf 0.2.18` package SHA-256
  `737CB6EAC3FDB7A25D20D0B74626F6912092848C2697A8E200A9570CFDF955F6`.
- Common managed licensing: immutable `Sonar.Licensing.Verification 0.1.3`
  package SHA-256
  `CA1DAC5C5220872F15130C863AB5D12E85709AC19D4972AFC7193C8223FA7518`.
- Common native licensing: immutable 0.1.2 manifest SHA-256
  `E777E623A2974E07CF4338670C3A41DF13BCDB8990F447987BB1BC0FF21834AC`.

Measurements are local development evidence, not universal release budgets.
Power state, scheduler and security software can change timings. A release
candidate repeats the measurement on its signed bundle and records the sample
set, p50/p95/max and admission budgets before optimization.

## Phase 12-14 baseline

Command:

```powershell
powershell -ExecutionPolicy Bypass -File .\scripts\test_ipc.ps1
```

The gate builds Release, runs all parity tests, then prints process and pure
policy `METRIC` lines.
The measured IPC scenario contains six coarse operations after accepted
handshake: settings, heartbeat, read-only session + event snapshot, catch
quality, catch disposition and shutdown. It never launches GTA, capture,
memory attach, physical input, network or WPF window.

| Measurement | Result |
| --- | ---: |
| Engine process start + dual-pipe connect + handshake accept | 33.571 ms |
| Six-operation IPC scenario through `ShutdownReady` | 28.436 ms |
| Engine process start through normal exit | 64.380 ms |
| Engine CPU sampled before shutdown | 0.000 ms - below Windows counter resolution in this sample |
| Engine peak working set | 6,971,392 bytes |
| Reeling policy, 1,000,000 mixed velocity + Evaluate + Stabilize samples | 14.449 ms |
| Reeling policy average | 14.449 ns/sample |
| Meal/player-status policy, 1,000,000 mixed estimate + timer + plan samples | 45.130 ms |
| Meal/player-status policy average | 45.130 ns/sample |

The reeling checksum `-310099.206` and meal-recovery checksum
`9719138455.000` prevent Release optimization from deleting either loop; both
benchmarks vary the policy input/state. Timing has no pass/fail threshold, so
scheduler noise cannot make the correctness gate flaky.

Decision after the Phase 14 parity slice: no hotspot was demonstrated in the
pure reeling policy, meal/player-status recovery policy or bounded offline IPC
scenario. No optimization was made. Current blockers are missing production
capabilities and safety contracts, not measured CPU/memory/IPC cost. Full WPF
first-paint/startup memory remains unmeasured because this safe gate
intentionally does not open a product window; it is measured with the offscreen
visual/startup matrix after Common UI 0.2 adoption.

## Phase 15 aggregate statistics snapshot baseline

Phase 15 extends the existing single revisioned session event with fish rows
and catch-size buckets. It does not add an IPC operation or polling loop. The
same Release gate measured the exact expanded schema and managed mapper:

| Measurement | Result |
| --- | ---: |
| Engine process start + dual-pipe connect + handshake accept | 30.971 ms |
| Six-operation IPC scenario through `ShutdownReady` | 31.167 ms |
| Engine process start through normal exit | 64.049 ms |
| Engine CPU sampled before shutdown | 15.625 ms |
| Engine peak working set | 6,074,368 bytes |
| Reeling policy, 1,000,000 samples | 14.543 ms / 14.543 ns per sample |
| Meal/player-status policy, 1,000,000 samples | 31.529 ms / 31.529 ns per sample |

The inert session intentionally contains zero fish rows and the four stable
zero-count catch-size definitions, so this sample measures schema/mapping cost
without fake production catches. Native corpus tests independently exercise
non-empty rows, pricing and buckets. Normal run-to-run timing variance is not
an optimization result: no code was optimized between the Phase 14 and Phase
15 samples. No CPU, memory, IPC or pure-policy hotspot was demonstrated; no
optimization was made.

## Phase 16 garbage-disposal policy baseline

The garbage slice adds no Engine process path or IPC operation. Its bounded
policy sorts only the candidates produced by one inventory-frame detector; the
five-row parity corpus covers filtering, stable ties, empty and disabled cases.
The full Release gate after the slice measured:

| Measurement | Result |
| --- | ---: |
| Engine bootstrap | 29.893 ms |
| Six-operation IPC scenario | 37.000 ms |
| Engine normal start through exit | 68.839 ms |
| Engine CPU sampled before shutdown | 0.000 ms - below counter resolution |
| Engine peak working set | 6,078,464 bytes |
| Reeling policy, 1,000,000 samples | 14.682 ms / 14.682 ns per sample |
| Meal/player-status policy, 1,000,000 samples | 31.142 ms / 31.142 ns per sample |

Candidate ordering is trivially bounded by visible inventory items and was not
demonstrated as a hotspot; adding an artificial million-item benchmark would
not represent product workload. Native CTest 12/12 and the two-case current
Python oracle are the relevant correctness evidence. No optimization was made.

## Phase 17 equipment-recovery policy baseline

The pure tackle/bait policy is constant-time over six fixed slots and adds no
Engine process path or IPC operation. The full Release gate measured:

| Measurement | Result |
| --- | ---: |
| Engine bootstrap | 31.358 ms |
| Six-operation IPC scenario | 30.919 ms |
| Engine normal start through exit | 64.283 ms |
| Engine CPU sampled before shutdown | 0.000 ms - below counter resolution |
| Engine peak working set | 6,074,368 bytes |
| Reeling policy, 1,000,000 samples | 14.806 ms / 14.806 ns per sample |
| Meal/player-status policy, 1,000,000 samples | 33.225 ms / 33.225 ns per sample |

Focused current-Python characterization 15/15 and native CTest 13/13 cover the
relevant behavior. No measured CPU/memory/IPC or policy hotspot exists; no
optimization was made.

## Phase 18 managed Telegram settings/state baseline

The Host-only slice adds no Engine operation, polling loop or network call. It
adds immutable settings/draft validation, a SHA-256 configuration identity used
only to bind an availability result to the exact credentials, and schema-v2
state persistence for seven notification-sound flags. The full Release gate
measured:

| Measurement | Result |
| --- | ---: |
| Engine bootstrap | 30.246 ms |
| Six-operation IPC scenario | 38.102 ms |
| Engine normal start through exit | 68.802 ms |
| Engine CPU sampled before shutdown | 0.000 ms - below counter resolution |
| Engine peak working set | 6,078,464 bytes |
| Reeling policy, 1,000,000 samples | 14.138 ms / 14.138 ns per sample |
| Meal/player-status policy, 1,000,000 samples | 33.734 ms / 33.734 ns per sample |

WPF 41/41, native CTest 13/13 and managed IPC 3/3 are green. The process
variation is normal single-sample noise; no CPU, memory or IPC hotspot was
demonstrated and no optimization was made. Offscreen WPF first-paint remains
deferred until the pinned Common UI 0.2 page composition is available.

## Phase 19 inert Telegram inbound/menu protocol baseline

The bounded router/menu/reducer slice is Host-only and performs no HTTP,
polling, Engine command or OS action. The shared behavior corpus contains 45
real command/callback routes and the parser rejects payloads above 64 KiB before
JSON materialization. The full Release gate measured:

| Measurement | Result |
| --- | ---: |
| Engine bootstrap | 29.980 ms |
| Six-operation IPC scenario | 28.341 ms |
| Engine normal start through exit | 60.356 ms |
| Engine CPU sampled before shutdown | 0.000 ms - below counter resolution |
| Engine peak working set | 6,078,464 bytes |
| Reeling policy, 1,000,000 samples | 14.306 ms / 14.306 ns per sample |
| Meal/player-status policy, 1,000,000 samples | 30.984 ms / 30.984 ns per sample |

Focused current-Python characterization is 45/45, WPF is 46/46, native CTest
is 13/13 and managed IPC is 3/3. The router is event-driven and bounded; no
startup/CPU/memory/IPC hotspot was demonstrated and no optimization was made.

## Phase 20-22 Common UI, statistics mutation and Windows safety baseline

These slices add the complete eight-page Common 0.2.18 composition, 132-image
offscreen render matrix, atomic custom-price revisions, semantic hotkey
conflict checks and the exact Common Windows process/window/input-budget
dependency. The runtime-safety test uses only the current test process and an
invalid zero HWND; it does not attach to GTA, observe an external window or
emit input. The native Engine control loop now dispatches the existing inert
commands by typed payload rather than depending on one fixed diagnostic order.

Latest full Release sample:

| Measurement | Result |
| --- | ---: |
| Engine bootstrap | 42.160 ms |
| Six-operation IPC scenario | 38.357 ms |
| Engine normal start through exit | 83.399 ms |
| Engine CPU sampled before shutdown | 46.875 ms |
| Engine peak working set | 6,987,776 bytes |
| Reeling policy, 1,000,000 samples | 14.202 ms / 14.202 ns per sample |
| Meal/player-status policy, 1,000,000 samples | 34.735 ms / 34.735 ns per sample |

Correctness gates at this point are WPF 73/73, native CTest 14/14 and managed
IPC 3/3. The timing increase versus individual earlier samples is within the
observed single-run variance and was not caused by an isolated optimization.
No measured hotspot was demonstrated, so no algorithm, cache, pooling or
batching change was made. Signed-bundle startup/first paint and production
long-lived supervisor p50/p95/max remain release-candidate measurements.

## Phase 23 Host streaming contract and complete page union baseline

This Host-only slice adds one revisioned immutable streaming snapshot and one
coarse controller boundary shared by the Stream page and Overview projection.
The exact quality/bitrate table, status normalization, command/setting union,
typed unavailable result and atomic persisted 10-FPS setting are covered with
offline fakes. No FFmpeg, HLS server, tunnel, network, game window or process
was launched. The Common UI render remains 132 images; WPF acceptance is now
81/81.

| Measurement | Result |
| --- | ---: |
| Engine bootstrap | 36.058 ms |
| Six-operation IPC scenario | 29.063 ms |
| Engine normal start through exit | 67.777 ms |
| Engine CPU sampled before shutdown | 0.000 ms - below counter resolution |
| Engine peak working set | 6,995,968 bytes |
| Reeling policy, 1,000,000 samples | 14.280 ms / 14.280 ns per sample |
| Meal/player-status policy, 1,000,000 samples | 34.349 ms / 34.349 ns per sample |

Native CTest remains 14/14 and managed IPC remains 3/3. This state/model slice
adds no Engine command, polling loop, process or network load. No hotspot was
demonstrated and no optimization was made; the missing production streaming
orchestrator is a capability gap rather than a performance problem.

## Phase 24 long-lived session and signed-entitlement baseline

The gate adds one long-lived contained-session regression and one separate
Host/Engine entitlement scenario. The existing six-operation diagnostic metric
is intentionally unchanged; signed entitlement is measured by the additional
IPC test so the historical scenario remains comparable. No production key,
network, external process, window, capture or input was used.

| Measurement | Result |
| --- | ---: |
| Engine bootstrap | 43.731 ms |
| Existing six-operation IPC scenario | 52.263 ms |
| Engine normal start through exit | 105.299 ms |
| Engine CPU sampled before shutdown | 15.625 ms |
| Engine peak working set | 7,860,224 bytes |
| Reeling policy, 1,000,000 samples | 14.337 ms / 14.337 ns per sample |
| Meal/player-status policy, 1,000,000 samples | 30.773 ms / 30.773 ns per sample |

Correctness gates are WPF 87/87, native CTest 15/15 and managed IPC 5/5.
The process sample includes normal build/scheduler variance and the RSA fixture
work occurs in a separate short-lived diagnostic session. No repeated sample,
CPU/memory threshold or user-facing delay demonstrates a hotspot, so no cache,
parser shortcut, crypto substitution or algorithm change was made.

## Phase 25 bounded event-delivery baseline

The read-only aggregate snapshot now passes through one cancellable Engine
writer backed by the frozen Common priority/latest buffers. The gate adds three
deterministic tests for priority ordering, latest-only snapshot coalescing,
explicit safety saturation, drain and closed admission. It adds no new IPC
operation, GTA/window/capture/input/network side effect or polling loop.

| Measurement | Result |
| --- | ---: |
| Engine bootstrap | 41.393 ms |
| Existing six-operation IPC scenario | 42.550 ms |
| Engine normal start through exit | 94.601 ms |
| Engine CPU sampled before shutdown | 15.625 ms |
| Engine peak working set | 8,232,960 bytes |
| Reeling policy, 1,000,000 samples | 14.466 ms / 14.466 ns per sample |
| Meal/player-status policy, 1,000,000 samples | 31.184 ms / 31.184 ns per sample |

Native CTest is 16/16 and managed IPC is 5/5. The one-sample working-set change
is within prior process/build variance and does not demonstrate a hotspot;
therefore no speculative pooling, batching or algorithm change was made.
Signed-bundle and long-lived production pressure p50/p95/max remain release
candidate measurements.

## Phase 26 native game-chat episode baseline

The game-chat slice is a bounded, event-driven state machine outside the
offline Engine diagnostic executable. It adds no IPC operation or polling
thread and the shipping adapter rejects before observation. The focused corpus
and native tests cover the exact meaningful action sequence and all timeout
bounds; no external window, capture, clipboard or input was touched.

| Measurement | Result |
| --- | ---: |
| Engine bootstrap | 38.703 ms |
| Existing six-operation IPC scenario | 33.018 ms |
| Engine normal start through exit | 80.602 ms |
| Engine CPU sampled before shutdown | 31.250 ms |
| Engine peak working set | 8,232,960 bytes |
| Reeling policy, 1,000,000 samples | 14.360 ms / 14.360 ns per sample |
| Meal/player-status policy, 1,000,000 samples | 32.946 ms / 32.946 ns per sample |

Correctness gates are WPF 91/91 with 132/132 renders, native CTest 18/18,
managed IPC 5/5 and focused legacy screenshot/classifier parity 2/2. The process metrics
remain within earlier single-run variance and the new policy is not on the
measured Engine path, so no hotspot was demonstrated and no optimization was
made. Detector and live-adapter performance will be measured only when those
capabilities exist behind an offline replay/live-readiness gate.

## Phase 27 Engine supervisor recovery baseline

The product supervisor replaces the previous one-shot health owner without
adding an IPC command or another process. Its correctness matrix includes an
actual crash of the inert Engine, a new contained generation and exact settings
revision replay; unit seams cover the full circuit/cancellation/terminal matrix.

| Measurement | Result |
| --- | ---: |
| Engine bootstrap | 41.205 ms |
| Existing six-operation IPC scenario | 40.047 ms |
| Engine normal start through exit | 90.486 ms |
| Engine CPU sampled before shutdown | 15.625 ms |
| Engine peak working set | 8,237,056 bytes |
| Reeling policy, 1,000,000 samples | 14.114 ms / 14.114 ns per sample |
| Meal/player-status policy, 1,000,000 samples | 31.157 ms / 31.157 ns per sample |

The timings remain inside prior machine/scheduler variance. Restart policy is
exercised only after a demonstrated process/IPC failure, so no normal-path
backoff or speculative pooling optimization was introduced.

## Phase 28 native game-chat detector baseline

Five Release runs decoded and classified the exact twelve-image corpus. Per
frame detector timings exclude WIC fixture decode; process CPU and peak working
set include the WIC test loader plus all twelve decoded frames. Reported values
below are the median across the five runs, except peak memory which was stable
at the shown maximum.

| Measurement | Result |
| --- | ---: |
| Frames per run | 12 |
| Detector p50 | 35.920 ms |
| Detector p95 / max | 46.972 ms |
| Whole test process CPU | 500.000 ms |
| Whole test peak working set | 49,795,072 bytes |

All twelve outputs exactly match the frozen legacy observation, while inactive
frames remain fail closed. Chat detection runs only inside bounded 150 ms
confirmation polling in the current episode; there is no accepted continuous
capture loop or production latency budget yet. The measurements therefore do
not demonstrate a user-visible hotspot. No approximation, cache or threshold
shortcut was mixed into the port; real multi-resolution replay and accepted
runtime cadence must precede any isolated optimization.

## Phase 29 Telegram lifecycle/dispatch baseline

The Host-only slice adds no Engine IPC command. Long polling blocks on bounded
HTTPS I/O and callback dispatch is sequential; update payloads remain limited
to 64 KiB and API responses to 2 MiB. Token/admin/enablement changes replace
one generation, while notification-only settings changes preserve it. Faults
use a two-second bounded retry and shutdown cancels the active request.

The current demo/offline composition denies network activation, so its process
baseline is unchanged and a synthetic throughput benchmark would not represent
production Telegram latency. Managed acceptance is 106/106 with zero warnings;
token rotation, cancellation, no-op reconfiguration, edit fallback and guarded
dispatch are deterministic. No measured hotspot justified an optimization.

## Phase 30 native chat mutation boundary baseline

The Win32 adapter remains absent from demo/offline composition. Acceptance uses
an injected recording backend, so it proves packet/cancellation semantics
without focusing a window, moving a cursor, changing clipboard state or
emitting input. The focused test includes one intentional 1 ms wait and cancels
one 2-second wait after roughly 10 ms; it is not a platform throughput
benchmark.

| Measurement | Result |
| --- | ---: |
| Native default CTest | 17/17 |
| Native IPC CTest | 20/20 |
| Managed IPC | 6/6 |
| Engine bootstrap | 32.542 ms |
| Existing six-operation IPC scenario | 34.611 ms |
| Engine normal start through exit | 75.999 ms |
| Engine peak working set | 7,249,920 bytes |
| Reeling policy, 1,000,000 samples | 14.213 ms / 14.213 ns per sample |
| Meal/player-status policy, 1,000,000 samples | 33.136 ms / 33.136 ns per sample |

The chat library is still outside the inert Engine executable, so the startup,
IPC, CPU and memory sample only guards against unrelated regression; CPU time
was below the sampler resolution in this run. Values remain within prior
machine/scheduler variance and demonstrate no hotspot. No batching threshold,
timing or algorithm optimization was made after parity.

## Phase 32 Host streaming lifecycle baseline

Five equal Release runs executed the complete 128-test WPF process after the
eleven fake-only H07 lifecycle cases were added. The measurement includes WPF
test-host startup and all existing managed acceptance; it does not claim real
FFmpeg, HLS, tunnel or capture throughput.

| Measurement | Result |
| --- | ---: |
| WPF acceptance | 128/128 |
| Median wall time | 2219.172 ms |
| Median process CPU | 1437.5 ms |
| Maximum peak working set | 16,564,224 bytes |
| New Host/Engine IPC operations / bytes | 0 / 0 |

The fake matrix covers exact media profiles, startup/rollback/cleanup order,
in-flight cancellation, serialized restart, bounded retry and chat/cleanup
deadlines. One cleanup test intentionally consumes a 40 ms timeout; this is
contract evidence rather than a throughput hotspot. Results remain within the
existing managed test-host/scheduler range, so no caching, pooling, batching or
timing shortcut was introduced. Real tool/network startup, steady-state CPU,
media memory and end-to-end latency must be measured only after the remaining
guarded H07 adapters and production admission exist.

## Phase 33 native fishing-stage detector parity and optimization

The first correct MSVC v143 Release implementation replayed the exact
SHA/size-pinned 30-frame FHD/2K/4K corpus. WIC decode and fixture file I/O were
excluded from per-frame detector timing. The benchmark process included corpus
loading, detector warm-up and all 30 measured calls; IPC remained absent because
the detector is not yet composed into the inert Engine executable.

| Measurement | Correct baseline | Optimized |
| --- | ---: | ---: |
| Exact stage parity | 30/30 | 30/30 |
| Maximum confidence delta vs OpenCV oracle | 0.000287584 | 0.000287584 |
| Detector p50 | 98.4974 ms | 86.9563 ms |
| Detector p95 | 216.366 ms | 150.553 ms |
| Detector maximum | 217.859 ms | 150.765 ms |
| Process CPU | 4,140.62 ms | 3,046.88 ms |
| Peak working set | 76,177,408 bytes | 84,627,456 bytes |
| New Host/Engine IPC operations / bytes | 0 / 0 | 0 / 0 |

The parity baseline demonstrated a latency hotspot relative to legacy stage
loops containing bounded 50 ms waits. Optimization was isolated after parity:
2D FFT plans now precompute their twiddle factors, and a thread-safe cache keeps
at most four spectra only for the two large tension templates. The normalized
cross-correlation formula, local statistics, thresholds, scale order, stage
priority, normalized geometry and fail-closed outcomes are unchanged. The
measured trade-off is `8,450,048` additional peak working-set bytes for `11.7%`
lower p50, `30.4%` lower p95 and `26.4%` lower process CPU.

Focused acceptance remains `/W4 /WX`, `30/30` parity and the same confidence
delta after optimization. Full offline/native/managed/no-Python gate results are
recorded with Phase 33 in `ENGINE_MIGRATION.md`; production capture, process,
window, input and network adapters were not run.

The same final full gate measured the unchanged inert Engine path at `47.597 ms`
bootstrap, `31.586 ms` for the existing six-operation IPC scenario and
`89.647 ms` start-through-exit, with `0.000 ms` sampled Engine CPU and
`8,237,056` bytes peak working set. The stage slice added `0` operations and
`0` bytes to that IPC path; these values are a regression guard, not a claim
about production capture or detector-loop throughput inside Engine.

## Phase 34 signed release transaction baseline

The update slice adds no Engine message, capture loop or steady-state worker.
Its network and filesystem acceptance uses a fake `HttpMessageHandler`, bounded
memory streams and isolated temporary install roots. The complete managed Host
suite is `136/136` with warnings/errors `0/0`; new Host/Engine IPC operations
and bytes are `0/0`.

No throughput optimization was justified. Correctness requires streaming at
most the signed payload length, SHA-256 over the exact received bytes,
write-through staging and explicit filesystem moves, so buffering the complete
EXE or weakening flush/hash/allowlist checks was rejected. Download throughput
and installed-drive update duration must be measured only with the eventual
signed production pair and after-exit activator.

## Phase 35 native inventory-store episode baseline

The Release benchmark executes the complete already-open, empty-inventory,
no-resume episode through three monotonic observations and five mutation-port
intents. It excludes capture, OCR, sleeps and physical input because those
adapters remain deliberately uncomposed. The episode does not add a Host/Engine
message or IPC byte.

| Measurement | Result |
| --- | ---: |
| Language-neutral fixture rows / episodes | 26 / 5 |
| Focused CTest | 1/1 |
| Benchmark episodes per run | 100,000 |
| Five-run elapsed range | 34.563-36.015 ms |
| Median elapsed | 35.199 ms |
| Median time per episode | 351.994 ns |
| Deterministic checksum | 252399995 |
| New Host/Engine IPC operations / bytes | 0 / 0 |

The combined canonical gate is WPF `143/143`, native IPC CTest `23/23` and
managed IPC `6/6`, with warnings/errors `0/0`. The unchanged inert Engine path
measured `37.859 ms` bootstrap, `35.032 ms` for its existing six-operation IPC
scenario and `81.271 ms` start-through-exit, with `0.000 ms` sampled Engine CPU
and `8,232,960` bytes peak working set. The inventory module is not linked into
that diagnostic executable, so its measured startup, memory and IPC deltas are
zero; these numbers are a regression guard rather than production episode
throughput evidence.

The five runs are stable and far below any detector, capture or human-facing
timing budget. No hotspot was demonstrated, so no speculative cache, batching,
allocation shortcut or retry/timing change was made after parity. Production
measurement remains pending for the future E14 observer and guarded mutation
adapter; it must separately record capture/detector cost, CPU, peak working set,
confirmation latency and crash cleanup without weakening the exact observation
sequence gate.

## Phase 36 native coherent-memory observation baseline

The Release benchmark runs the pure confirmed-reeling, eight-vote inventory and
serialized-chat decoders as one aggregate-shaped loop. It excludes process
open/hash, Common exact reads and WebEngine window scanning because the signed
production build/address profile and target resolver remain deliberately
uncomposed. The capability adds no Host/Engine message or IPC byte.

| Measurement | Result |
| --- | ---: |
| Language-neutral fixture rows | 5 |
| Focused CTest / Python oracle | 1/1 / 4/4 |
| Benchmark aggregates per run | 250,000 |
| Five-run elapsed range | 78.711-80.694 ms |
| Median elapsed | 79.573 ms |
| Median time per aggregate | 318.290 ns |
| Deterministic checksum | 2250000.000 |
| New Host/Engine IPC operations / bytes | 0 / 0 |

The pure decoder baseline is stable and far below capture/process costs. No
hotspot was demonstrated, so no speculative SIMD, pooled mutable buffer,
weakened validation or cross-snapshot cache was added after parity. The initial
lifecycle contract retains an admitted read-only session and verified image
hash only while the exact Common process generation remains unchanged;
generation drift discards both sessions and the whole snapshot. This is part of
admission correctness, not a post-parity timing optimization.

Production measurement remains pending. After an approved profile and guarded
composition exist, record image-hash admission cost, p50/p95/max complete
capture latency, read bytes, CPU, peak working set and recovery after either
process disappears. Those measurements cannot weaken the 96-region, 256-KiB
per-region, 1-MiB aggregate, exact-read or generation-revalidation gates.

## Phase 39 native whole-fishing-episode baseline

The Release benchmark executes a complete six-observation cast-hook-reel
episode through the E14 stage contract, E11-shaped coherent reeling snapshots,
the existing reeling estimator/policy/stabilizer and a fake exact-sequence
mutation session. It excludes capture, detector work, process reads, waits and
physical input because every live adapter remains deliberately uncomposed. The
whole operation adds no Host/Engine message or byte.

| Measurement | Result |
| --- | ---: |
| Language-neutral fixture rows / episodes | 19 / 6 |
| Focused CTest / legacy characterization | 1/1 / 149/149 |
| Benchmark episodes per run | 100,000 |
| Five-run elapsed range | 82.3207-85.5194 ms |
| Median elapsed | 83.9312 ms |
| Median time per episode | 839.312 ns |
| Deterministic checksum | 2900000 |
| New Host/Engine IPC operations / bytes | 0 / 0 |

The checksum includes both bounded A/D down/up pulse pairs produced by the
six-observation replay; this replaces the earlier long-lived held-key projection
without weakening the immediate final gate. The replay baseline is stable and
orders of magnitude below the preserved
3-180 second human-facing phase budgets. No measured hotspot justified pooling
mutable observations, weakening profile/generation validation, caching an
action across sequences or changing estimator/timing semantics, so no
post-parity optimization was made. Production measurement must separately
record capture/detector/memory costs, p50/p95/max confirmation latency, CPU,
peak working set, packet count and cleanup after cancellation, target loss and
hard crash once signed profiles and live readiness are approved.

## Phase 40 native maintenance-episode baseline

The Release benchmark executes a complete already-admitted tackle-check
episode through the coarse maintenance runner, E15 exact-sequence context and
two mutation intents. It excludes detector/capture, waits and physical input;
those adapters remain deliberately uncomposed. Meal, garbage, tackle and bait
share the same final port, so the slice adds no Host/Engine message or byte.

| Measurement | Result |
| --- | ---: |
| Language-neutral fixture rows / episodes / domains | 27 / 5 / 4 |
| Focused E15 + maintenance CTest | 2/2 |
| Benchmark episodes per run | 100,000 |
| Five-run elapsed range | 68.888-69.949 ms |
| Median elapsed | 69.784 ms |
| Median time per episode | 697.842 ns |
| Deterministic checksum | 1699995 |
| New Host/Engine IPC operations / bytes | 0 / 0 |

The combined canonical Phase 39/40 gate is WPF `155/155`, native IPC CTest
`25/25` and managed IPC `6/6`, with warnings/errors `0/0`. The unchanged inert
Engine measured `39.864 ms` bootstrap, `44.555 ms` for six IPC operations,
`93.480 ms` start-through-exit, `0.000 ms` sampled CPU and `7,254,016` bytes
peak working set. Maintenance is not linked into that command surface, so these
are regression guards rather than production detector/input measurements.

The replay baseline is stable and orders of magnitude below the preserved
300 ms-6 s human-facing waits. No measured hotspot justified pooling mutable
observations, caching a target across reflow, collapsing confirmation reads or
changing retry/timing policy, so parity and the exact final-sequence gate remain
unchanged. Production measurement must separately record each detector/capture
cost, p50/p95/max confirmation latency, CPU, peak working set, packet count and
cleanup after target/process loss once signed profiles and live readiness are
approved.

## Future before/after record

For a measured hotspot add one row set containing:

1. capability and exact replay corpus;
2. commit/worktree identifier and toolchain/package hashes;
3. before p50/p95/max, CPU time, peak working set and IPC bytes/count;
4. one isolated optimization and why it preserves semantics;
5. after results under the same conditions;
6. focused parity, full offline, no-Python and release gates.
