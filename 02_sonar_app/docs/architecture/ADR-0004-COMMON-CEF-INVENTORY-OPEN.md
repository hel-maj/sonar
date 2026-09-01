# ADR-0004: Common CEF inventory facade

Статус: принято, обновлено 2026-08-27.

## Контекст

Исторический Fishing binding различал `open/closed` по product-owned byte
candidates, а visual detector находил только видимые slot candidates; единого
memory snapshot открытости, веса, сетки и содержимого не было.
Копирование CEF/V8 discovery из Hunting или Common создало бы второго владельца
Win32 process/session/generation и снова допустило бы расхождение между
продуктами. При этом cold discovery нельзя выполнять в latency-critical
reeling path или повторять на каждом UI frame после `unknown`.

## Решение

Fishing exact-pins установленный `SonarMajesticRuntimeModule 0.1.3` / target
`Sonar::MajesticRuntimeModule` и `SonarMajesticCefInventory 0.1.33` / targets
`Sonar::MajesticCefInventory` и `Sonar::MajesticCefInventoryContent`. SHA-256
их `SHA256SUMS.txt` равны соответственно
`6E902CF03A7F19F4451D6F5F03CFAD6AA2B2928FEB9C56C5B873CD6EC1ADA845` и
`E79A579A3CAA29E91FC8EA4A4DCDFDDE98FA4D03FACBF5BC8B6AB0C76440A4FE`.
RuntimeModule является единственным owner role-based trusted-publisher
admission; CEF Inventory exact-зависит от него и добавляет только CEF/V8 и
inventory content semantics.
Continuous content factory включает closed-state bootstrap на собственной копии
policy, поэтому содержимое не зависит от открытости inventory UI. Общий
`acquisition_policy` остаётся strict-by-default; closed path по-прежнему требует
unique root, double-read open state и stable process/file generation.
Setup, offline gate и release builder проверяют как сам pin, так и каждый
payload из manifest. Sibling checkout Common не используется.

Production composition владеет отдельным cancellable inventory worker и создаёт
Common provider через
`content::create_win32_trusted_publisher_inventory_content_provider`.
Observation включена одинаково в ordinary и Local Access builds. Медленный cold
discovery не выполняется на control/heartbeat thread и не задерживает reeling;
worker публикует только изменившийся coarse snapshot.

Identity admission не зависит от file/product version, SHA-256, file size,
PE timestamp, заранее известного loaded image size или exact profile. Semantic
inventory binding не использует compiled V8 instance-type ordinals. Неполный,
неоднозначный или нестабильный proof возвращает unavailable. Common на одном
pinned read handle доказывает accepted WinTrust publisher и timestamp,
ненулевую dynamic PE identity, равенство disk PE `SizeOfImage` loaded module,
unique module и стабильный file/process fingerprint между cold и hot authority
brackets. Fishing не получает signer policy, handles, addresses или raw Win32
errors.

Common snapshot содержит open, current/maximum weight, 17x6 grid, active
position и bounded items: stable/runtime/catalog identity, placement/span,
count/maximum, weights, condition/freshness/durability, description,
image/icon references, typed stats/buffs и optional usable/rottable. Fishing
переносит его через canonical `inventory/v1/sonar_inventory.proto` как один
revisioned `InventoryStateSnapshot`; product владеет только mapping, columns,
commands, feature policy и presentation composition. Renderer discovery,
admission, V8 layout, coherent reads и hot binding остаются внутри Common.
Screenshot/OCR может дать актуальную geometry для automation surface, но не
заменяет memory snapshot. Legacy Fishing resolver и exact Common profile 1.20.7
сохраняются только для offline forensic replay/characterization.

Worker выполняет bounded sample с cadence 500 ms и публикует новую revision
только при изменении видимого ready/unavailable state. Common provider сам
отзывает binding при process/file/generation/read drift; исключение переводится
в sanitized `inventory_source_failed`. Stale snapshot, address или unfinished
read transaction не replay-ятся. Завершение Engine отменяет worker и ждёт его
bounded stop до освобождения IPC/process resources.

Local Access по-прежнему снимает только перечисленные в ADR-0002 внешние
licensing/entitlement и startup availability gates. Он не меняет inventory
publisher/file/process proof, current generation, foreground, lease или final
input gates. Неизвестность либо drift остаются fail-closed.

## Последствия и rollback

- Fishing зависит только от публичных Common RuntimeModule и CEF
  content/provider surfaces; локальные verifier, renderer/V8 headers и copied
  layouts запрещены ownership test. Тот же test запрещает возврат
  exact-profile factory и candidate identifiers в runtime adapter.
- Любой Common failure отображается как typed unavailable reason; last-known
  replay отсутствует.
- Обновление package требует нового exact version/hash и повторного Release
  link/test gate. Rollback возвращает предыдущую проверенную Host/Engine pair;
  legacy Fishing authority не восстанавливается.
- Live GTA/input acceptance не выполнялась этим ADR и остаётся отдельным gate.
