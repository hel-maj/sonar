# Fishing inventory open-state: admission и characterization

Статус: production runtime переведён на exact-pinned Common trusted-publisher
CEF facade;
исторический Fishing binding и manual tool сохранены только как development
characterization, но больше не являются production authority.

## Runtime contract

Inventory open-state отделён от reeling memory. `production_frame_observer`
делает один coarse runtime observation. При positive reeling trigger он
запрашивает только latency-critical reeling evidence; на остальных кадрах
запрашивает inventory. Поэтому cold inventory discovery не блокирует A/D
control, а открытие/закрытие инвентаря не зависит от active fish или replay
list. Клавиша продуктового episode остаётся `TAB`.

Production путь состояния:

```text
same-frame exact GTA process generation
  -> one SonarMajesticCefInventory 0.1.18 observe()
  -> Common trusted publisher + pinned file/process admission
  -> bounded CEF/V8 discovery + three-frame semantic type proof
  -> Common coherent double-read + generation-pinned hot binding
  -> Fishing unknown-only exponential retry (250 ms .. 4 s cap)
  -> aggregate unknown / closed / open
```

Screenshot и OCR владеют только геометрией item/context. Они не могут заменить
memory state. Обычная shipping и compile-isolated Local Access композиции
используют один Common trusted-publisher runtime с observation enabled и
explicit closed bootstrap после authority proof. File/product version, SHA-256,
file size, PE timestamp, заранее известный loaded size и exact profile не
являются identity-admission gates. Semantic type proof не использует historical
instance-type ordinals и возвращает `unknown` при incomplete, ambiguous или
unstable evidence. Любая причина Common, inconsistent state либо GTA
generation drift даёт `unknown`, а не `closed`. Known state не кэшируется;
после unknown следующий cold attempt throttled, а смена generation reset-ит
facade и retry немедленно.

Ниже зафиксирован только historical/development characterization contract; он
не подключён к production adapter. Такой binding обязан фиксировать exact image
profile, диапазон и byte budget
сканирования, максимум region/hit count, masked pattern, exact slot stride/count,
signal offsets и vote/confidence policy. Runtime дополнительно ограничивает
cold scan 1 GiB, region 64 MiB, enumeration 32 768 regions, pattern 64 KiB и
80 итоговых signals. Incomplete read, неоднозначная signature run, generation
drift или повторная неудача после cache invalidation не публикуют snapshot.
Failed cold discovery не повторяется в каждом frame: state machine выдерживает
bounded 5-second cooldown, сохраняя тот же typed blocker, и затем допускает
новую попытку.

Shipping registry schema `2` продолжает кодировать старый Fishing binding как
`-`, но production adapter больше его не читает. Loose JSON, абсолютный адрес,
wildcard build hash или копия Common/Hunting CEF verifier/layout не допускаются.

## Почему legacy binding остался только characterization

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

## Optional forensic user-gated сбор

Non-shipping C++ tool может собрать controlled closed/open evidence текущего
exact process generation для forensic replay старого Fishing binding. Этот
receipt не нужен для trusted-publisher runtime availability. Tool сам не
нажимает `TAB`, не активирует окно и не делает кадр. Пользователь вручную
устанавливает запрошенное состояние и подтверждает готовность в консоли:

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
registry, Common publisher policy или runtime availability и не разрешает
input. Повторный run имеет смысл только для отдельной forensic задачи.

## Build/release isolation

Shipping Engine и Local Access линкуют тот же immutable static package и
создают один trusted-publisher facade. Runtime setting не может заменить его
admission. `scripts/setup_native.ps1`, `scripts/test_ipc.ps1` и release builder
проверяют exact 0.1.18, manifest hash
`EC109F38E0F0BF1428EA63505B186022CE2116301014E0578AB0886DF7CFCF7D` и каждый
manifest payload. Подробнее: [ADR-0004](ADR-0004-COMMON-CEF-INVENTORY-OPEN.md).

Tool собирается только при OFF-by-default
`SONAR_FISHING_BUILD_PROFILE_COMPATIBILITY_PROBE=ON`. Source/import CTest
запрещает input, focus, capture, write-process-memory и network capabilities.
`Sonar.Fishing.InventoryStateCharacterization.exe` не входит в Engine, package,
install/update или двух-EXE release allowlist.
