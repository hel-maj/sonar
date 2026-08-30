# ADR-0006: сброс статистики текущей сессии

Статус: принято

Дата: 2026-08-27

## Контекст

Страница `Статистика` показывает один volatile aggregate, которым владеет
production Engine. Локальное обнуление ViewModel оставляло бы Engine и другие
consumer-ы на старой ревизии. Разбивать операцию на несколько мелких IPC-вызовов
тоже нельзя: длительность, итоги, снасти, строки рыб и chart buckets должны
перейти к одной новой сессии на одной linearization boundary.

Persistent history, CSV и восстановление прежней статистической сессии не входят
в целевую Fishing composition.

## Решение

- В append-only `FishingEnvelope` добавлен
  `ResetFishingSessionStatisticsRequest` с field number `24`. Этот номер нельзя
  переиспользовать для другой семантики.
- Production и compile-isolated Local Access Engine публикуют capability
  `fishing-session.statistics.reset:1.0`; offline diagnostic Engine её не
  публикует. Host не отправляет команду старой или диагностической generation,
  которая capability не согласовала.
- Host посылает ровно одну coarse command
  `reset-fishing-session-statistics` через тот же serialized generation gate,
  что Start/Stop. Engine под своим state gate вызывает один reset aggregate,
  увеличивает progress revision и возвращает correlated command result плюс
  полный `FishingSessionSnapshot`.
- Reset меняет только in-memory statistics текущей сессии. Сам reset не
  останавливает активную рыбалку, не меняет настройки, entitlement или pending
  notifications и не выполняет input либо другой game side effect. Если его
  atomic capture уже видит завершившуюся production operation, общий completion
  reconciler сначала переводит lifecycle в stopped и ровно один раз публикует
  уведомление с correlation исходного Start, а не reset-команды.
- Host принимает результат только от exact bound Engine generation. Timeout или
  caller cancellation после начала обмена retire-ит эту generation, чтобы
  orphan reply не нарушил request/reply ordering. Supervisor может создать новую
  generation, но никогда не replay-ит reset. Caller cancellation не считается
  runtime failure и не включает backoff. Deadline/cancellation до фактической
  отправки команды не retire-ит здоровую generation.
- Один monotonic revision owner объединяет correlated reset response и
  `SessionSnapshotReceived`: поздняя continuation ревизии N не может откатить
  уже опубликованную ревизию N+1.
- ViewModel заменяет состояние только принятым aggregate snapshot. Явный Engine
  rejection или cancellation до отправки сохраняет последний подтверждённый
  snapshot. Ambiguous timeout/cancellation после отправки retire-ит generation,
  а supervisor публикует fail-closed `Empty`; последний aggregate такой
  generation не сохраняется. Rapid click ограничен атомарным single-flight gate,
  success toast не показывается, а ошибка доступна на самой странице.

## Совместимость

Field `24` является append-only protobuf extension. Старый reader может
пропустить unknown field, но новый Host всё равно требует explicit capability до
отправки. Обновление Host и Engine поставляется одной manifest-bound парой.

## Отклонённые варианты

- Обнулить только WPF ViewModel: создаёт две разные истины и возвращает старые
  значения со следующим Engine snapshot.
- Отправлять отдельные reset-вызовы для totals, tackle, rows и buckets: теряется
  атомарность, растут latency и риск частичного состояния.
- Считать reset разновидностью Stop/Start: это меняет automation lifecycle и
  может породить нежелательный side effect.

## Проверка

- protobuf golden fixture фиксирует exact field `24` и round trip;
- native composition test проверяет одну границу reset и сохранение lifecycle,
  settings и notification state;
- managed IPC integration проверяет correlated empty aggregate;
- supervisor regressions проверяют exact generation, timeout до/после issue,
  caller cancellation без failure/backoff, fail-closed `Empty` и отсутствие
  replay после recovery;
- revision regression фиксирует порядок response N -> event N+1 -> late
  continuation N;
- ViewModel и WPF surface regressions проверяют accepted/rejected/cancelled
  result, retirement projection, видимую ошибку и single-flight rapid click.

## Rollback

При rollback action скрывается из UI, а capability удаляется только вместе с
координированным rollback manifest-bound пары Host/Engine. Field `24` остаётся
reserved навсегда; локальное ViewModel-обнуление не возвращается.
