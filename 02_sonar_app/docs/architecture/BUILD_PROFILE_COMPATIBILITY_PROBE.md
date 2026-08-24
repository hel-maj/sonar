# Fishing build-profile compatibility probe

Статус: diagnostic реализован и принят offline; единственный live pass выполнен
2026-08-24 и fail-closed отклонён. Текущая GTA build остаётся unsupported и не
добавлена в production registry.

## Причина появления

Первый one-shot [live observation preflight](LIVE_OBSERVATION_PREFLIGHT.md)
2026-08-24 вернул:

```text
process_ready=true
window_ready=true
build_ready=true
profile_ready=false
capture_ready=true
memory_ready=false
reason=game_build_unsupported
```

Единственный embedded profile допускает exact `GTA5.exe` SHA-256
`677E4E355CFBDB13273B1D992407E3C261B3A108DC4DD5C8A0C4C1DA651802E5`.
Результат доказывает hash drift, но намеренно не раскрывает новый hash и не
даёт evidence, достаточного для добавления production profile. Wildcard или
перенос старого layout на новый hash без проверки запрещён.

## Diagnostic-only boundary

`Sonar.Fishing.BuildProfileCompatibilityProbe.exe` является отдельным
OFF-by-default non-shipping target. Он не связан с `Sonar.Engine.exe`, не
добавляет overload в shipping memory resolver, не меняет embedded registry и
не использует его registry SHA как admission evidence.

Diagnostic:

1. Находит exact `GTA5.exe`, проверяет одно foreground client window и получает
   SHA-256 через production least-rights connector.
2. Выбирает frozen baseline только по exact id
   `majestic-gta5-677e4e35-v1` и revision `1`, deep-clone-ит его в памяти и
   меняет только game hash. Уже admitted hash отклоняется.
3. Использует отдельную candidate identity
   `nonshipping-build-profile-candidate-v1` и candidate schema `1`.
4. Полностью читает module с hard bound 256 MiB. Все hits всех world-pattern
   alternatives разрешаются в ровно один distinct validated player endpoint;
   replay pattern обязан иметь ровно один hit.
5. Replay entity list принимается только с реально прочитанным count `1..2048`.
   Fallback count отсутствует. Должна существовать ровно одна active entity с
   exact fish model hash `802685111` и конечной дистанцией `1..120` метров.
6. Production `memory_observer` делает coherent bounded snapshot с отдельным
   fish-identity region. Финальный predicate требует `active=true`,
   `fish_model_confirmed=true`, finite/in-range geometry и повторно читает hash,
   active byte и process generation после snapshot.

Любой incomplete read, arithmetic overflow, generation drift, отсутствующий или
неоднозначный anchor/player/replay/fish даёт fail-closed result. Retry отсутствует.

## Sanitized result

Stdout содержит только:

- result schema и общий `ready`;
- coarse flags `process_ready`, `window_ready`, `hash_ready`,
  `baseline_ready`, `patterns_unique`, `fish_identity_ready`,
  `snapshot_ready`;
- candidate SHA-256;
- baseline profile id/revision;
- stable reason key.

PID, HWND, path, absolute/module-relative addresses, raw module/memory values,
frame, stage, confidence, positions и distance не выводятся и не сохраняются.

Даже `ready=true` является только compatibility evidence для offline review.
Он не добавляет profile в registry, не разрешает normal Engine, overlay или
physical input. Новый immutable profile/revision, canonical fixture/hash pin,
regressions и обычный supported-profile preflight остаются отдельными gates.

## Одна подготовленная попытка

Probe требует active-reeling state и foreground GTA, поэтому сначала полностью
подготавливается offline, затем пользователь один раз подтверждает одну попытку:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\run_build_profile_compatibility_probe.ps1 -ConfirmedLiveBuildProfileCompatibility
```

Wrapper проверяет offline suite и binary imports, даёт 5-10 секунд для возврата
в GTA и выполняет один pass. Ввода, screen capture/recording, overlay, network,
window activation и повторной попытки нет. Switch является внутренней safety
assertion того же подтверждения, а не причиной спрашивать пользователя второй
раз. Звуковые сигналы отсутствуют.

Точный later protocol и receipt:

1. Offline проверки и CMake/import/source isolation должны быть зелёны;
   прямой запуск diagnostic EXE запрещён.
2. Пользователь вручную оставляет GTA на active reeling и foreground;
   затем одно fresh contextual confirmation покрывает ровно одну
   попытку.
3. Wrapper выполняет один bounded pass после delay не менее пяти
   секунд; exit `0` означает `ready=true`, exit `2` — санитизированный
   fail-closed result.
4. Receipt — только ровно один emitted JSON из описанного выше
   allowlist. PID/HWND/path/address/raw frame/raw memory/value не сохраняются.
5. После любого result нет retry. Если понадобится новая
   state-dependent попытка, она сначала снова подготавливается offline и
   получает новое одноразовое confirmation.
6. Даже `ready=true` передаётся только в offline profile review; registry
   не меняется и shipping Engine не получает admission.

Единственная разрешённая live compatibility попытка 2026-08-24 вернула exit 2:

```text
ready=false
process_ready=true
window_ready=true
hash_ready=true
baseline_ready=true
patterns_unique=false
fish_identity_ready=false
snapshot_ready=false
candidate_sha256=8c2c3f768b87f060d678d9e175842aa20449cf5bc164c630692a494eb353d472
baseline_profile_id=majestic-gta5-677e4e35-v1
baseline_profile_revision=1
reason=pattern_scan_incomplete
```

Sanitized ignored receipt сохранён в
`build/live-evidence/fishing-build-profile-compatibility-20260824.json`, его
SHA-256 —
`33A3C6F23E95C1B3647A35238BEC09F99459B3B707A32EA63715B12DF7D15F15`.
Повторной попытки, ввода, активации окна, screen capture, overlay или сети не
было. Этот result не доказывает layout compatibility: production registry и
shipping resolver не менялись, inventory input остаётся запрещённым.

## Build и release exclusion

CMake option `SONAR_FISHING_BUILD_PROFILE_COMPATIBILITY_PROBE` по умолчанию
`OFF`; release script дополнительно передаёт exact `OFF`. Offline CTest
проверяет core sequencing/JSON allowlist, validator success и negative paths,
read-only source/import boundary, отсутствие candidate API/markers в shipping
source и `Sonar.Engine.exe`, а также отсутствие executable в package recipe.

Release allowlist остаётся неизменным: diagnostic отсутствует в bundle,
install, update и rollback.
