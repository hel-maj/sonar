# Sonar: аудит runtime-состояний

## Scope

Граф описывает runtime-логику desktop-приложения: запуск, лицензию, UI-команды, рыболовный автомат, Telegram, streaming, временный chat mode, закрытие окна и self-uninstall. Build/release-скрипты не включены.

## Как читать модель

Sonar не является одним строгим конечным автоматом. В приложении параллельно меняются:

1. lifecycle бота: `running` и `stop_event`;
2. внутренний `BotPhase`;
3. визуальная стадия игры `detected_stage`;
4. lifecycle стрима;
5. временный chat mode;
6. лицензия и feature entitlements.

Цвета стрелок:

- голубой: основной lifecycle;
- зелёный: успешный guarded-переход;
- жёлтый: обслуживание или восстановление;
- красный: нормальная терминальная остановка;
- красный пунктир: кандидат запрещённого состояния или отсутствующего gate.

## Кандидаты для инженерной проверки

### 1. Перевес может завершить brain thread без полноценного lifecycle stop

В [`bot.py`](P:/projects/Majestic/Sonar/02_sonar_app/src/sonar/fishing/bot.py:2244) ветка `release` продолжает цикл, но `stop` и `exit_game` вызывают только `self._stop_event.set()`. В отличие от других терминальных веток, [`_stop_from_brain`](P:/projects/Majestic/Sonar/02_sonar_app/src/sonar/fishing/bot.py:392) не вызывается.

Возможная комбинация после выхода из brain loop:

```text
brain thread завершён
state.running == True
phase и cleanup устарели
```

UI строит статус на `bot.state.running` в [`main_window.py`](P:/projects/Majestic/Sonar/02_sonar_app/src/sonar/ui/main_window.py:2212), поэтому пользователь может увидеть работающий бот при уже завершённом потоке.

### 2. Telegram polling не выключается runtime feature gate-ом

[`NotificationManager.configure`](P:/projects/Majestic/Sonar/02_sonar_app/src/sonar/telegram/notifier.py:89) запускает polling при `settings.enabled` и наличии токена. Лицензионный gate в [`main_window.py`](P:/projects/Majestic/Sonar/02_sonar_app/src/sonar/ui/main_window.py:1564) скрывает страницы, останавливает fishing и stream, но не останавливает Telegram polling при отсутствии `FEATURE_TELEGRAM` или неактивной лицензии.

Remote start рыбалки и стрима имеют собственные проверки, но Telegram-меню содержит и другие административные действия. Это стоит закрыть одним runtime gate-ом.

## Структурное замечание

`BotPhase` полезен как операционный маркер, но не должен считаться единственным источником истины: routing в [`bot.py`](P:/projects/Majestic/Sonar/02_sonar_app/src/sonar/fishing/bot.py:602) определяется визуальными trigger-ами и независимыми флагами задач.

## Артефакты

- `sonar-runtime-overview.svg` / `.png`: обзор runtime-контуров;
- `sonar-fishing-state-graph.svg` / `.png`: подробный автомат рыбалки;
- `sonar-stream-chat-graph.svg` / `.png`: lifecycle стрима и временный chat mode;
- `sonar-state-model.drawio`: редактируемая diagrams.net-модель с тремя страницами;
- `sonar-application-logic.pptx`: презентационная версия.
