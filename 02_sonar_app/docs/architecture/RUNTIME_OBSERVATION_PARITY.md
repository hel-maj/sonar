# Runtime observation: historical parity matrix

Статус: native owners и offline parity проверены; inventory и reeling
production admission version-independent. Свежая live acceptance semantic
reeling anchors и trusted inventory path ещё требуется.

Дата проверки: 2026-08-26.

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
| Inventory `open / closed / unavailable` | `inventory_memory.py`: до 80 byte candidates `(address, closed_value, open_value, weight)`; минимум 6 совпадений, confidence не ниже `0.85`; unmatched/ambiguous/read failure возвращали `None` | Exact-pinned Common `SonarMajesticCefInventory 0.1.31` content provider -> Engine inventory worker -> canonical `InventoryStateSnapshot` | Ordinary и Local Access используют `SonarMajesticRuntimeModule 0.1.3` как единый trusted-publisher file/process authority. Continuous content provider допускает closed bootstrap только после unique-root/double-read proof, поэтому content не зависит от открытости UI. Version/hash/size/profile клиента и CEF/V8 ordinal не являются availability gate. Public runtime policy defaults to zero known sizes; current observed size/timestamp participate only in one lease fingerprint и drift revocation. Incomplete/coherence/authority failure публикуется как sanitized unavailable state; exact 1.20.7 остаётся forensic-only |
| Inventory item list and placement | Python automation использовала visual slot/template candidates; отдельного целостного memory-owner в Fishing не было | Common content snapshot: runtime/instance/catalog identity, title/category, 17x6 row/column/span, count/max, weights, condition/freshness/durability, description, image/icon reference, stats/buffs и optional usable/rottable; Fishing только отображает и применяет product policy | Один bounded snapshot публикуется latest-only через typed event. Raw addresses/V8 types/source-only weapon semantics не пересекают IPC. Visual detector остаётся отдельным current-frame automation-surface evidence и не заменяет memory content |
| Inventory current/max weight | `player_status.py`, WebEngine indicator/weight window: `inventory_weight`, `inventory_weight_max`, `backpack_weight`, `backpack_weight_max` | Common content snapshot `current_weight/maximum_weight` + typed inventory IPC | Production provider и Host projection подключены; достоверность текущего live состояния остаётся отдельным read-only acceptance gate. Historical backpack-specific split не синтезируется |
| Food, water, health | `player_status.py`: nullable integer facts из WebEngine window/candidates | `player_status_evidence.food/water/health` | Decoder parity есть; тот же WebEngine admission gap |
| Generic game menu open | Memory field не найден. `game_menu.py` искал visual templates `menu_hide`/`menu_back` с threshold `0.74` и возвращал match либо `None` | Same-frame text/visual adapter публикует `game_menu_open: optional<bool>`; positive menu сохраняется независимо от unknown inventory state | Offline state composition покрыта. Authentic menu screenshot/live acceptance отсутствует; OCR failure остаётся `unknown`, а не `false` |
| Fishing mini-game active | Memory field уровня всей мини-игры не найден. Python `_is_fishing_stage_active` проверял visual triggers `start`, `start1`, `start2`, `wait_tension`, `ad` | Stage detector + `fishing_minigame_active: optional<bool>` и typed `fishing_stage` | 30-frame visual corpus покрывает active stages/none. Live acceptance отсутствует |
| Confirmed reeling fish active byte | `memory_reeling.py`: byte at confirmed fish `+0x189`; `1` означает current fish active, любое прочитанное другое значение переводило tracker action в `fish_caught`. `ReelingState.active` был lifecycle tracker flag, не global mini-game flag | `reeling_evidence.active`; native намеренно принимает только exact `0/1`: `0` - pending terminal transition, `1` - active, остальные значения - `unknown` fail-closed. Pending `0` очищается только после coherent successful capture | Это осознанное safety narrowing относительно legacy `!= 1`, а не полная byte-value parity. Characterization и resolver regression покрывают active/inactive, failure между resolution/capture и bounded retry без replay |
| Reeling geometry | `memory_reeling.py`: confirmed fish hash `802685111`, player/fish XYZ, player-right XY, derived distance | Common trusted GTA lease + Fishing executable-section semantic resolver + `reeling_evidence` с independent hash reread и bounded exact projections | Shipping availability не зависит от build hash/version/size/timestamp. Offline regression доказывает unique/ambiguous anchors и coherent capture; свежая live acceptance текущей сцены остаётся отдельной |
| Chat input/visibility/tab | Historical chat tools: nullable `input_active`, `visible`, active tab id и confidence из serialized/DOM window | `decode_chat_evidence` | Decoder parity есть; production WebEngine plan отсутствует |
| New-catch memory event `(eng_key, ru_name, weight)` | Только старый reverse dossier `memory_fish_reader`: UTF-16 WebEngine text, count-based delta и queue. Это поток новых уловов, не current inventory; removals/moves/sales он не наблюдает | Current production catch fact принадлежит same-frame catch-screen detector; memory event owner не admitted | Не перенесён как runtime memory fact: нет original tracked source, exact needle/profile, deterministic target selection и current-build evidence. Использовать как inventory contents запрещено |

## Coherent Engine composition

Production memory adapter больше не предоставляет вызывающему коду отдельные
мелкие scopes. Positive trigger выполняет только Fishing reeling plan. Common
inventory content provider работает на отдельном cancellable Engine worker с
500 ms cadence, поэтому cold discovery и полный content decode не выполняются
на reeling/control/heartbeat thread. Только изменившийся ready/unavailable
snapshot получает новую product revision; drift или read failure отзывает
binding и публикует unavailable, а stale known snapshot не replay-ится.

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

1. Read-only live acceptance Common trusted-publisher inventory path и Fishing
   trusted/semantic reeling path; exact current GTA hash не является gate.
2. Authentic active и `1 -> 0` confirmed-fish captures на admitted build.
3. Exact WebEngine process generation/profile для player status/chat; старый
   catch-event dossier отдельно требует более сильного oracle и не является
   inventory snapshot.
4. Authentic menu screenshots и совместная same-cycle capture проверка menu,
   mini-game и inventory item candidates. В этой задаче GTA/capture/input не
   запускались.

## Какие controls сейчас fail-closed и почему

Developer-full-access заменяет только внешние startup/update и licensing gates.
Он не меняет Common trusted identity, semantic anchors, foreground/coherence
или immediate input gates. Изменившийся build проходит новую проверку signer/
file/process identity и текущих semantics; старые addresses не переносятся.

| Control / episode | Что уже можно наблюдать | Конкретный текущий blocker |
| --- | --- | --- |
| Start fishing и reeling input | Visual fishing stage/targets того же кадра + shipping Common trusted lease/semantic resolver | Нужен свежий active-reeling live pass с полным executable scan, unique player/replay, одной exact fish identity и coherent snapshot; исторический `pattern_scan_incomplete` относится к forensic probe и не является hash blocker |
| Inventory open/close, store, garbage, meal, bait | Same-frame visual item candidates, menu и stage; both builds compose Common trusted-publisher tri-state | Version-independent path is offline-covered but still requires separate read-only/live acceptance; publisher/file/process/semantic mismatch remains typed `unknown` and blocks mutation |
| Generic menu recovery | Positive same-frame menu observation распознаётся независимо от inventory | Authentic current-build menu corpus/live acceptance отсутствует. После recovery action следующий inventory-dependent шаг снова остановится на `inventory_open = unknown`; OCR failure не превращается в closed/gameplay |
| Fishing mini-game state | Visual trigger даёт independent active/inactive observation | Само состояние наблюдаемо offline, но reeling mutation всё равно требует fresh trusted/semantic E11 evidence; visual stage не подменяет memory safety gate |
| Inventory/status counters | Native decoders для food/water/health и inventory/backpack weights | Нет trusted WebEngine semantic binding и production capture plan; поля остаются absent |
| Game chat state | Native decoder для input/visibility/tab | Нет trusted WebEngine semantic binding и production capture composition; fields остаются absent |
| Current inventory contents из memory | Ничего: historical authoritative memory snapshot owner не найден | Старый count-delta catch stream не моделирует removals/moves/sales и не является inventory snapshot; без нового evidence-backed owner поле не создаётся |

Для reeling GTA не нужен hash enrollment. Каждый свежий process generation
проходит Common trusted-module admission, полный unique pattern resolution,
coherent relationship validation и controlled read-only capture. Inventory-open
также не ждёт profile promotion; mismatch обоих путей остаётся fail-closed.
