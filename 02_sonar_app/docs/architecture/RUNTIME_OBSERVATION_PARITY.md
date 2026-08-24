# Runtime observation: historical parity matrix

Статус: native owners и offline parity проверены; live memory authority для
текущего GTA/WebEngine build отсутствует.

Дата проверки: 2026-08-24.

## Oracles и уровень доказательства

Основной oracle - последний tracked Python tree перед удалением native
migration commit `4cbb5f2`: `4cbb5f2^` содержит `memory_reeling.py`,
`inventory_memory.py`, `player_status.py`, `game_menu.py`,
`inventory_stage.py` и их consumers/tests. Отдельный более старый frozen
Nuitka reconstruction в `d13e165^` содержит dossier
`workers__fishing__memory_fish_reader.md`; это не original source и поэтому он
не может сам по себе выдать production address/profile authority.

Матрица разделяет memory facts, visual facts и derived automation state. Поле,
которого не было в historical memory owner, не объявляется memory parity.

## Field-by-field matrix

| Наблюдаемый факт | Historical Python oracle и точная семантика | Current native owner | Production/runtime статус |
| --- | --- | --- | --- |
| Inventory `open / closed / unknown` | `inventory_memory.py`: до 80 byte candidates `(address, closed_value, open_value, weight)`; минимум 6 совпадений, confidence не ниже `0.85`; unmatched/ambiguous/read failure возвращали `None` | Exact-pinned Common `SonarMajesticCefInventory 0.1.0` facade + aggregate `inventory_open_state`; projection - `inventory_observation.inventory_open: optional<bool>` | Ordinary shipping denied/inert до promotion. Compile-isolated Local Access явно admits только candidate 1.20.7; Common владеет exact identity, CEF/V8 discovery и double-read. Legacy Fishing binding остаётся characterization-only |
| Inventory item list | Historical memory owner не найден. Последний Python bot использовал visual slot/template detectors; `InventoryMemoryDetector` создавался и закрывался, но `_is_inventory_open()` фактически вызывал visual `GameMenuDetector` и `InventoryStageDetector` | `production_visual_detector` того же client frame: `instance_id`, canonical `item_id`, `title`, compartment, confidence, normalized bounds | Current-frame candidates считываются и не стираются только из-за unknown memory-open. Они не actionable, пока `surface` не подтвержден как inventory/context; memory list не выдуман |
| Inventory/backpack current/max weight | `player_status.py`, WebEngine indicator/weight window: `inventory_weight`, `inventory_weight_max`, `backpack_weight`, `backpack_weight_max` | `decode_player_status_evidence` в aggregate snapshot | Decoder parity есть; production WebEngine selection/layout отсутствует, поэтому runtime fields остаются absent/unknown |
| Food, water, health | `player_status.py`: nullable integer facts из WebEngine window/candidates | `player_status_evidence.food/water/health` | Decoder parity есть; тот же WebEngine admission gap |
| Generic game menu open | Memory field не найден. `game_menu.py` искал visual templates `menu_hide`/`menu_back` с threshold `0.74` и возвращал match либо `None` | Same-frame text/visual adapter публикует `game_menu_open: optional<bool>`; positive menu сохраняется независимо от unknown inventory state | Offline state composition покрыта. Authentic menu screenshot/live acceptance отсутствует; OCR failure остаётся `unknown`, а не `false` |
| Fishing mini-game active | Memory field уровня всей мини-игры не найден. Python `_is_fishing_stage_active` проверял visual triggers `start`, `start1`, `start2`, `wait_tension`, `ad` | Stage detector + `fishing_minigame_active: optional<bool>` и typed `fishing_stage` | 30-frame visual corpus покрывает active stages/none. Live acceptance отсутствует |
| Confirmed reeling fish active byte | `memory_reeling.py`: byte at confirmed fish `+0x189`; `1` означает current fish active, любое прочитанное другое значение переводило tracker action в `fish_caught`. `ReelingState.active` был lifecycle tracker flag, не global mini-game flag | `reeling_evidence.active`; native намеренно принимает только exact `0/1`: `0` - pending terminal transition, `1` - active, остальные значения - `unknown` fail-closed. Pending `0` очищается только после coherent successful capture | Это осознанное safety narrowing относительно legacy `!= 1`, а не полная byte-value parity. Characterization и resolver regression покрывают active/inactive, failure между resolution/capture и bounded retry без replay |
| Reeling geometry | `memory_reeling.py`: confirmed fish hash `802685111`, player/fish XYZ, player-right XY, derived distance | `reeling_evidence` с independent hash reread и bounded exact projections | Decoder/resolver parity есть для admitted historical profile; current hash live не admitted |
| Chat input/visibility/tab | Historical chat tools: nullable `input_active`, `visible`, active tab id и confidence из serialized/DOM window | `decode_chat_evidence` | Decoder parity есть; production WebEngine plan отсутствует |
| New-catch memory event `(eng_key, ru_name, weight)` | Только старый reverse dossier `memory_fish_reader`: UTF-16 WebEngine text, count-based delta и queue. Это поток новых уловов, не current inventory; removals/moves/sales он не наблюдает | Current production catch fact принадлежит same-frame catch-screen detector; memory event owner не admitted | Не перенесён как runtime memory fact: нет original tracked source, exact needle/profile, deterministic target selection и current-build evidence. Использовать как inventory contents запрещено |

## Coherent Engine composition

Production memory adapter больше не предоставляет вызывающему коду отдельные
мелкие scopes. Positive trigger того же кадра выполняет только Fishing
reeling-only plan. Остальные кадры вызывают Common inventory-open facade ровно
один раз; Common внутри владеет cold-to-hot discovery и coherent double-read.
После unknown Fishing кэширует только unknown и применяет monotonic exponential
retry от 250 ms до cap 4 s; known state не кэшируется. Смена GTA generation
немедленно reset-ит facade/backoff. Поэтому cold inventory discovery не
задерживает latency-critical reeling control и не повторяется на каждом кадре.

`production_frame_observer` затем формирует один Engine-local aggregate:

- `inventory_open` - только coherent memory evidence;
- `items`/context geometry - только текущий client frame;
- `game_menu_open` и `fishing_minigame_active` - независимые visual facts того
  же frame;
- `reeling` - optional memory fact того же sequence/generation.

Menu positive не исчезает при unknown inventory memory. Item candidates тоже
сохраняются для observation/diagnostics, но `inventory_surface::unknown`
останавливает episode до любого mutation. OCR/title/items никогда не заменяют
unknown memory-open. Если memory одновременно сообщает open, а независимый
same-frame detector подтверждает menu, mini-game или catch surface, aggregate
сохраняет отдельные facts для диагностики, но делает inventory surface
`unknown` и удаляет actionable geometry.

При identity/signature/read/decode drift resolver инвалидирует cache. Adapter
делает не больше одной повторной resolution/capture попытки; pending inactive
fish сохраняется только для этой retry и commit-ится после coherent success.
Повторный failure возвращает unknown, сбрасывает pending transition и cached
observer sessions и не использует last-known fallback. Process generation
change сразу очищает player/replay/fish и inventory caches и требует полного
bounded rediscovery.

## Оставшиеся live evidence gaps

1. Exact current GTA hash/profile и controlled `CLOSED/OPEN` inventory binding.
2. Authentic active и `1 -> 0` confirmed-fish captures на admitted build.
3. Exact WebEngine process generation/profile для player status/chat; старый
   catch-event dossier отдельно требует более сильного oracle и не является
   inventory snapshot.
4. Authentic menu screenshots и совместная same-cycle capture проверка menu,
   mini-game и inventory item candidates. В этой задаче GTA/capture/input не
   запускались.

## Какие controls сейчас fail-closed и почему

Developer-full-access заменяет только внешние startup/update и licensing gates.
Он не меняет GTA identity, memory-profile admission, foreground/coherence или
immediate input gates. Поэтому отсутствие exact current-build profile не
исправляется wildcard-ом либо переносом addresses старого build.

| Control / episode | Что уже можно наблюдать | Конкретный текущий blocker |
| --- | --- | --- |
| Start fishing и reeling input | Visual fishing stage/targets того же кадра | Actual `GTA5.exe` SHA-256 `8c2c3f768b87f060d678d9e175842aa20449cf5bc164c630692a494eb353d472` отсутствует в registry; offline compatibility probe завершился `pattern_scan_incomplete`, поэтому нет admitted E11 player/replay/fish evidence для final mutation gate |
| Inventory open/close, store, garbage, meal, bait | Same-frame visual item candidates, menu и stage; Local Access additionally composes Common candidate 1.20.7 | Ordinary shipping deliberately disabled until Common profile promotion. Local Access path is offline-covered but still requires separate read-only/live acceptance; any mismatch remains typed `unknown` and blocks mutation |
| Generic menu recovery | Positive same-frame menu observation распознаётся независимо от inventory | Authentic current-build menu corpus/live acceptance отсутствует. После recovery action следующий inventory-dependent шаг снова остановится на `inventory_open = unknown`; OCR failure не превращается в closed/gameplay |
| Fishing mini-game state | Visual trigger даёт independent active/inactive observation | Само состояние наблюдаемо offline, но reeling mutation всё равно требует admitted current-build E11 evidence; visual stage не подменяет memory safety gate |
| Inventory/status counters | Native decoders для food/water/health и inventory/backpack weights | Нет exact admitted WebEngine process-generation/profile/layout и capture plan; поля остаются absent |
| Game chat state | Native decoder для input/visibility/tab | Нет exact admitted WebEngine target/profile/layout и production capture composition; fields остаются absent |
| Current inventory contents из memory | Ничего: historical authoritative memory snapshot owner не найден | Старый count-delta catch stream не моделирует removals/moves/sales и не является inventory snapshot; без нового evidence-backed owner поле не создаётся |

Для reeling GTA blocker нужен новый exact profile только после unique complete
pattern resolution, coherent relationship validation и controlled read-only
captures на этом же SHA-256. Для ordinary shipping inventory нужен promotion
Common profile с independent evidence. Local Access уже compile-time admits
exact candidate 1.20.7, но его фактическая read-only/live acceptance не
выполнялась в этой задаче; mismatch остаётся fail-closed.
