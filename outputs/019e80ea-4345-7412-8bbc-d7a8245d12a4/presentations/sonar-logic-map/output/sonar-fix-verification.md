# Sonar: повторная проверка переходов после исправлений

Дата проверки: 2026-06-01.

## Исправлено

1. Терминальные ветки перевеса `stop` и `exit_game` теперь вызывают полноценный `_stop_from_brain`, поэтому выполняются cleanup, сброс `running`, возврат `phase` в `IDLE` и уведомление об остановке.
2. Telegram получил runtime gate от лицензии. Gate управляет polling, исходящими API-запросами и обработкой входящих callbacks. Reload настроек не может обойти gate.
3. Во время повторного аудита найден и исправлен связанный lifecycle-дефект: остановка стрима теперь закрывает управляемый chat mode до очистки runtime. Если игровой чат закрыть не удалось, paused-бот безопасно останавливается.
4. При отзыве `stream_chat` entitlement активный управляемый chat mode принудительно закрывается.

## Повторный аудит

- В fishing-контуре прямые установки `_stop_event` остались только внутри централизованных `stop()` и `_stop_from_brain()`.
- В Telegram прямой stop-флаг остался только внутри собственного polling lifecycle.
- Состояние стрима `active=True, status=error` после неудачного restart FFmpeg является degraded runtime: UI оставляет доступной остановку и не разрешает повторный start до cleanup. Это не подтверждено как нарушение порядка действий.

## Проверка

```text
python -m pytest -q
616 passed, 1 xfailed

python -m compileall -q src/sonar ...
OK

git diff --check
OK
```
