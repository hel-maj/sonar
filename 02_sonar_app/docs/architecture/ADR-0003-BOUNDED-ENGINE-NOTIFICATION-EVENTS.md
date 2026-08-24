# ADR-0003: bounded Engine notification events

Статус: accepted, 2026-08-24.

## Контекст

Автоматические Telegram-уведомления о рыбалке должны исходить из уже
подтвержденных фактов production Engine: улов, начало и остановка сессии,
восстановление еды, заполнение инвентаря, состояние игрока, усталость наживки и
потеря фокуса. Host не должен повторно читать память GTA, делать снимок экрана
или выводить событие из UI-состояния. Snapshot с текущим состоянием также не
заменяет occurrence event: coalescing допустим для snapshot, но потерял бы
отдельный улов или переход lifecycle.

События не дают authority для игрового действия. Telegram transport является
внешней наблюдательной границей: его задержка, ошибка или отсутствие credentials
не должны останавливать Engine, Host или текущую рыбалку.

## Решение

Product IPC v1 получает один typed `FishingNotificationEvent` с вариантами
`catch`, `session started/stopped`, `meal`, `inventory full`, `player status`,
`bait tired` и `focus lost`.

- Production composition складывает только подтвержденные domain facts в
  in-memory FIFO до 64 событий. Новое событие при насыщении отбрасывается и
  увеличивает bounded diagnostic counter. Очередь очищается при подготовке
  новой automation session и никогда не сохраняется на диск.
- Engine сериализует уведомления в Common events channel. Все notification
  frames идут через одну normal-priority FIFO lane. Это сохраняет их wire
  sequence; lifecycle priority не используется, потому что он мог бы
  переставить два notification frames.
- Aggregate snapshots остаются отдельным latest-only coalesced stream. Поэтому
  Host ведет независимые монотонные watermarks для notification и snapshot:
  общий header sequence может иметь пропуски из-за control replies и порядок
  между FIFO event и coalesced snapshot не является occurrence order.
- `EngineSessionSupervisor` присваивает receipt текущую Host generation и
  привязывает state/event callbacks к immutable generation binding. Принимаются
  frames только от текущего managed session; retirement сериализуется с уже
  начатой доставкой callback. При process death,
  закрытии или fault event pump generation немедленно отзывается; поздние
  frames старого session отбрасываются.
- Telegram publisher имеет собственную in-memory очередь до 64 receipts,
  дедупликацию по `(generation, sequence)` и последовательную отправку текущим
  admin IDs. При новой generation накопленные receipts старой generation не
  публикуются. После restart исторические события не восстанавливаются и не
  переотправляются.
- Ошибки producer projection, outbox, settings read, planner и отдельной
  Telegram delivery поглощаются на наблюдательной границе. Ошибка event stream
  относится к liveness всей Engine generation и запускает обычное supervised
  replacement с отзывом authority и no-replay invariant.

## Security и privacy

Publisher не делает capture, не меняет focus, не вызывает input и не добавляет
новый Engine command. В этой реализации catch photo намеренно отключено. Текст
stop reason пропускается только через product mapping; внутренние причины не
показываются пользователю. Bot token и admin IDs остаются в существующем DPAPI
state и не входят в event payload или diagnostics.

## Проверки

Offline regressions доказывают:

1. native очередь bounded, сохраняет порядок типов, считает pressure и
   опустошается без replay;
2. wire mapper принимает все только typed/валидные значения;
3. supervisor меняет generation после смерти event pump и не пересылает позднее
   событие старого session;
4. publisher отбрасывает duplicate/stale receipts и продолжает работу после
   отказа Telegram delivery;
5. inventory-space notification является edge-triggered;
6. producer/publisher tests не используют GTA, capture, focus, input,
   credentials или сеть.

Live Telegram delivery и authentic GTA events остаются отдельной acceptance и
не выводятся из offline gate.

## Последствия и rollback

Преимущество - автоматические уведомления используют тот же подтвержденный
Engine fact, что и session statistics, без Host-side memory adapter. Цена -
occurrence stream намеренно loss-bounded при pressure и не является журналом.

Rollback требует одновременно удалить product proto payload, native producer,
Host mapper/source/publisher и capability `fishing-notifications.events` из
обоих peers. Оставлять только одну сторону нельзя: exact handshake capability и
schema должны совпадать.

## Skills audit

Проверен `sonar-fishing-workflow`. Ownership, IPC и live-safety routing не
изменились; новый повторяемый release workflow не появился, поэтому skill
менять не требуется.
