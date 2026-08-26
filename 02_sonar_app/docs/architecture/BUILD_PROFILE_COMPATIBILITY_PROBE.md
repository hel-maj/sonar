# Fishing build-profile compatibility probe

Статус: forensic diagnostic реализован и принят offline; единственный live pass
2026-08-24 fail-closed отклонён. После ADR-0005 exact hash больше не является
production availability gate и этот документ не определяет runtime admission.

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

На тот момент единственный embedded profile допускал exact `GTA5.exe` SHA-256
`677E4E355CFBDB13273B1D992407E3C261B3A108DC4DD5C8A0C4C1DA651802E5`.
Результат доказывает hash drift, но намеренно не раскрывает новый hash и не
даёт evidence, достаточного для подтверждения layout. Wildcard или перенос
старых addresses без semantic проверки запрещён. Теперь shipping resolver
выполняет эту проверку непосредственно после Common trusted admission; SHA
остаётся только provenance.

## Diagnostic-only boundary

`Sonar.Fishing.BuildProfileCompatibilityProbe.exe` является отдельным
OFF-by-default non-shipping target. Он не связан с `Sonar.Engine.exe`, не
добавляет overload в shipping memory resolver, не меняет embedded registry и
не использует его registry SHA как admission evidence.

Diagnostic:

1. Находит exact `GTA5.exe`, проверяет одно foreground client window, получает
   Common trusted lease и дополнительно вычисляет SHA-256 через отдельный
   forensic connector; hash не участвует в admission lease.
2. Выбирает frozen baseline только по exact id
   `majestic-gta5-677e4e35-v1` и revision `1`, deep-clone-ит его в памяти и
   меняет только game hash. Уже admitted hash отклоняется.
3. Использует отдельную candidate identity
   `nonshipping-build-profile-candidate-v1` и candidate schema `1`.
4. Bounded parser проверяет DOS/PE64 headers, `SizeOfImage`, section table и
   executable ranges модуля с hard bound 256 MiB. Pattern scan читает только
   полностью покрытые committed-readable executable sections, полученные через
   Common `query_region`; unreadable non-executable `.data` не входит в scan.
   Все hits всех world-pattern alternatives разрешаются в ровно один distinct
   validated player endpoint; replay pattern обязан иметь ровно один hit.
5. Replay entity list принимается только с реально прочитанным count `1..2048`.
   Fallback count отсутствует. Должна существовать ровно одна active entity с
   exact fish model hash `802685111` и конечной дистанцией `1..120` метров.
6. Production `memory_observer` делает coherent bounded snapshot с отдельным
   fish-identity region. Финальный predicate требует `active=true`,
   `fish_model_confirmed=true`, finite/in-range geometry и повторно читает hash,
   active byte и process generation после snapshot.

Executable reads идут chunks до 64 KiB. Failed exact read рекурсивно делится до
4 KiB и на leaf получает только один полный retry; общий byte budget ограничен
1 GiB. Любой постоянный executable hole, исчерпание budget, malformed PE,
arithmetic overflow, generation drift, отсутствующий или неоднозначный
anchor/player/replay/fish даёт fail-closed result. Частично прочитанный section
никогда не используется.

Причины scan/layout и endpoint resolution разделены и остаются
санитизированными: `module_layout_unavailable`,
`module_executable_scan_incomplete`, а для `world_endpoint` и
`replay_endpoint` отдельно `incomplete`, `unresolved` и `ambiguous`.

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
Он не добавляет profile в registry и не разрешает overlay или physical input.
Production Engine независимо требует Common lease, unique semantic anchors,
coherent capture и обычные final gates.

## Одна подготовленная попытка

Probe требует active-reeling state и foreground GTA, поэтому сначала полностью
подготавливается offline. Явный запуск команды задаёт одну попытку:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\run_build_profile_compatibility_probe.ps1
```

Wrapper проверяет offline suite и binary imports, даёт 5-10 секунд для возврата
в GTA и выполняет один pass. Ввода, screen capture/recording, overlay, network,
window activation и повторной попытки нет. Отдельный user-facing confirmation
switch не дублируется; внутренний EXE safety argument остаётся. Звуковые
сигналы отсутствуют.

Точный later protocol и receipt:

1. Offline проверки и CMake/import/source isolation должны быть зелёны;
   прямой запуск diagnostic EXE запрещён.
2. Пользователь вручную оставляет GTA на active reeling и foreground; один
   явный запуск wrapper покрывает ровно одну попытку.
3. Wrapper выполняет один bounded pass после delay не менее пяти
   секунд; exit `0` означает `ready=true`, exit `2` — санитизированный
   fail-closed result.
4. Receipt — только ровно один emitted JSON из описанного выше
   allowlist. PID/HWND/path/address/raw frame/raw memory/value не сохраняются.
5. После любого result нет retry. Если понадобится новая
   state-dependent попытка, она сначала снова подготавливается offline и
   запускается новой явной командой.
6. Даже `ready=true` передаётся только в offline profile review; registry
   не меняется. Shipping Engine получает admission только через собственный
   trusted/semantic path, а не из receipt probe.

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

`pattern_scan_incomplete` - исторический schema-1 receipt старой версии probe,
в которой module read и endpoint stages были объединены в одну причину. Он не
локализует текущий blocker. Новая версия не переинтерпретирует старый receipt и
для следующей отдельно разрешённой попытки вернёт одну из stage-specific причин
выше.

Sanitized ignored receipt сохранён в
`build/live-evidence/fishing-build-profile-compatibility-20260824.json`, его
SHA-256 —
`33A3C6F23E95C1B3647A35238BEC09F99459B3B707A32EA63715B12DF7D15F15`.
Повторной попытки, ввода, активации окна, screen capture, overlay или сети не
было. Этот result не доказывает layout compatibility и не переинтерпретируется
как production evidence. Текущий shipping resolver сам выполняет более сильный
semantic admission; inventory/input остаются под собственными fresh gates.

## Build и release exclusion

CMake option `SONAR_FISHING_BUILD_PROFILE_COMPATIBILITY_PROBE` по умолчанию
`OFF`; release script дополнительно передаёт exact `OFF`. Offline CTest
проверяет core sequencing/JSON allowlist, validator success и negative paths,
read-only source/import boundary, отсутствие candidate API/markers в shipping
source и `Sonar.Engine.exe`, а также отсутствие executable в package recipe.

Release allowlist остаётся неизменным: diagnostic отсутствует в bundle,
install, update и rollback.
