# ADR-0004: Common CEF inventory-open facade

Статус: принято, 2026-08-24.

## Контекст

Исторический Fishing binding различал `open/closed` по product-owned byte
candidates, но не имел доказанной module-rooted authority для текущей сборки.
Копирование CEF/V8 discovery из Hunting или Common создало бы второго владельца
Win32 process/session/generation и снова допустило бы расхождение между
продуктами. При этом cold discovery нельзя выполнять в latency-critical
reeling path или повторять на каждом UI frame после `unknown`.

## Решение

Fishing exact-pins установленный `SonarMajesticCefInventory 0.1.0`, target
`Sonar::MajesticCefInventory`; SHA-256 его `SHA256SUMS.txt` равен
`B44CD61110B4B4E152DE52245021CD4C12233E2886EE1FDF323942F27C2352F8`.
Setup, offline gate и release builder проверяют как сам pin, так и каждый
payload из manifest. Sibling checkout Common не используется.

Production composition владеет одним долгоживущим facade instance. На кадре с
positive reeling trigger вызывается только Fishing reeling capture. На прочем
кадре Fishing вызывает `inventory_open_acquisition::observe()` ровно один раз и
переносит только Common `unknown/closed/open` в тот же immutable aggregate.
Renderer discovery, exact client verification, V8 layout, double-read и hot
binding остаются внутри Common. Legacy Fishing inventory resolver сохраняется
только для offline characterization и не участвует в production adapter.

После `unknown` Fishing кэширует только `unknown` и stable reason, применяя
monotonic exponential retry `250 ms -> 500 ms -> 1 s -> 2 s -> 4 s` с cap
`4 s`. `open/closed` не кэшируются: hot facade вызывается на каждом реально
запрошенном non-reeling aggregate. Смена GTA process generation немедленно
сбрасывает facade/backoff и требует свежую попытку; stale known state не
возвращается.

Обычная shipping composition передаёт `denied`, оставляет observation disabled
и не разрешает closed bootstrap. Compile-isolated `Локальный доступ` явно
разрешает только встроенный non-shipping profile
`majestic-client-1.20.7-candidate-v1`, включает observation и closed bootstrap.
Runtime flag не может изменить этот выбор. Exact process/generation,
foreground, lease и final input gates не ослабляются. До отдельного promotion
нового shipping profile обычный выпуск остаётся inert/unknown.

## Последствия и rollback

- Fishing зависит только от публичного `inventory_open.hpp`; локальные
  `Windows.h`, verifier, renderer/V8 headers и copied layouts запрещены
  ownership test.
- Любой Common failure или inconsistent `known/reason` отображается в typed
  `production_inventory_*` reason и `unknown`; last-known replay отсутствует.
- Обновление package требует нового exact version/hash и повторного Release
  link/test gate. Rollback возвращает предыдущий pin и оставляет shipping path
  disabled, не восстанавливая legacy authority.
- Live GTA/input acceptance не выполнялась этим ADR и остаётся отдельным gate.
