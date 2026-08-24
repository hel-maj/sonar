# Fishing inventory open-state: admission и characterization

Статус: runtime scope и fail-closed recovery реализованы; shipping binding для
текущего GTA build отсутствует; manual characterization tool принят offline и
ещё не запускался.

## Runtime contract

Inventory open-state отделён от reeling memory. `production_frame_observer`
запрашивает `memory_capture_scope::inventory_state`, поэтому открытие/закрытие
инвентаря не зависит от active fish, replay list или стадии рыбалки. Клавиша
продуктового episode остаётся `TAB`.

Путь состояния:

```text
exact GTA image hash + process generation
  -> optional product-owned embedded_inventory_binding
  -> bounded cold signature discovery
  -> generation-pinned cached binding
  -> masked-signature revalidation on every plan
  -> one automatic bounded rediscovery after drift
  -> typed failure cooldown before another cold scan
  -> coherent candidate reads
  -> Common unknown / closed / open normalizer
```

Screenshot и OCR владеют только геометрией item/context. Они не могут заменить
memory state. Если exact profile не содержит binding, normal runtime возвращает
typed `inventory_binding_failure::profile_unavailable` и stable reason
`memory_inventory_binding_unavailable`. Actual current hash ещё не admitted и
fail-closed раньше с тем же typed failure и reason
`memory_game_build_unsupported`. В обоих случаях UI/episode получает `unknown`,
а не `closed`.

Admitted binding обязан фиксировать exact image profile, диапазон и byte budget
сканирования, максимум region/hit count, masked pattern, exact slot stride/count,
signal offsets и vote/confidence policy. Runtime дополнительно ограничивает
cold scan 1 GiB, region 64 MiB, enumeration 32 768 regions, pattern 64 KiB и
80 итоговых signals. Incomplete read, неоднозначная signature run, generation
drift или повторная неудача после cache invalidation не публикуют snapshot.
Failed cold discovery не повторяется в каждом frame: state machine выдерживает
bounded 5-second cooldown, сохраняя тот же typed blocker, и затем допускает
новую попытку.

Shipping registry schema `2` явно кодирует отсутствие inventory binding как
`-`. Loose JSON, абсолютный адрес, wildcard build hash или импорт Hunting CEF
address/layout не допускаются.

## Почему legacy binding не promoted

Исторический Python detector действительно различал bytes `closed/open` через
weighted vote, но сохранённый anchor не является production binding:

- module-rooted pointer и pointer chain отсутствовали;
- один masked pattern повторялся через `0x600`, образуя несколько sliding base;
- лучший старый `closed` выбор имел только `18/32` matched,
  confidence `0.8888888889` и `14` unreadable;
- полный read-only scan текущего exact hash
  `8c2c3f768b87f060d678d9e175842aa20449cf5bc164c630692a494eb353d472`
  не нашёл ни одного exact masked match: сначала `5663` deterministic regions /
  `536760320` bytes, затем все `13490` readable regions не больше 16 MiB /
  `7609348096` bytes.

Sanitized ignored receipt:
`build/live-evidence/fishing-inventory-signature-compatibility-20260824.json`,
SHA-256
`6795F62F25D5F17D56DD25D95DE2BFB77DD0EFEFD35271CC2001BD3C27EDBC2D`.
Проверка не использовала input, screen capture, focus/activation или network.

## Один оставшийся user-gated сбор

Non-shipping C++ tool собирает controlled closed/open evidence текущего exact
process generation. Он сам не нажимает `TAB`, не активирует окно и не делает
кадр. Пользователь вручную устанавливает запрошенное состояние и подтверждает
готовность в консоли:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File `
  .\scripts\run_inventory_state_characterization.ps1 `
  -ConfirmedManualInventoryCharacterization
```

Один запуск содержит discovery `CLOSED/OPEN`, затем два validation cycle
`CLOSED/OPEN` по три read-only samples на состояние. Перед каждым Enter нужно
дождаться окончания анимации. Wrapper сначала выполняет offline gate и import /
network-dependency scan. Прямой запуск EXE без
`--confirmed-manual-inventory-characterization` возвращает `64` и не читает
process.

Receipt сохраняется только в ignored `build/live-evidence/` и содержит exact
hash/generation, bounded scan policy и validated byte candidates. Он не меняет
registry и не разрешает input. После одного такого user-gated run signature/root
review, immutable profile fixture/hash pin, synthetic discovery/recovery tests
и read-only current-build acceptance выполняются автономно; второй ручной
toggle-run нужен только если первый receipt fail-closed или build изменился.

## Build/release isolation

Tool собирается только при OFF-by-default
`SONAR_FISHING_BUILD_PROFILE_COMPATIBILITY_PROBE=ON`. Source/import CTest
запрещает input, focus, capture, write-process-memory и network capabilities.
`Sonar.Fishing.InventoryStateCharacterization.exe` не входит в Engine, package,
install/update или двух-EXE release allowlist.
