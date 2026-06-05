# Ключи подписки Sonar

Sonar читает уровень подписки из metadata лицензии или policy на сервере лицензий.

Поддерживаемые значения:

| Уровень | Metadata | Доступ |
| --- | --- | --- |
| Intro | `intro` | Только вкладка Рыбалка. Бот, Обзор, Telegram, Статистика и Стрим недоступны. |
| Basic | `basic` | Рыбалка с запуском бота, Обзор без расширенных метрик, Telegram без команд стрима и статистики. |
| Premium | `premium` | Полный функционал. |
| Dev | `dev` | Сейчас копирует Premium. |
| Promo | `promo` | Сейчас копирует Premium. |

Базовые разделы `Настройки`, `Лицензия` и `О приложении` не ограничиваются уровнем подписки.

## Как задать уровень

Используйте одно из полей metadata:

```json
{
  "license_group": "premium"
}
```

Также поддерживаются алиасы `tier`, `plan`, `group` и `sonar_group`:

```json
{
  "tier": "basic"
}
```

Лучше задавать уровень на policy. Тогда все новые ключи этой policy автоматически получают нужный доступ. Metadata конкретной license используйте только для персонального исключения или ручного апгрейда.

## Создание ключей через Keygen UI

1. Откройте закрытую админку Keygen UI.
2. Создайте или выберите policy для нужного уровня.
3. В metadata policy укажите `license_group`.
4. Создайте новую license в этой policy.
5. Передайте пользователю созданный key.

Примеры metadata для policy:

```json
{
  "license_group": "intro"
}
```

```json
{
  "license_group": "basic"
}
```

```json
{
  "license_group": "premium"
}
```

```json
{
  "license_group": "dev"
}
```

```json
{
  "license_group": "promo"
}
```

## Апгрейд пользователя

Чтобы пользователь улучшил подписку, создайте новый ключ в policy более высокого уровня или измените metadata его текущей license:

```json
{
  "license_group": "premium"
}
```

После этого пользователь вводит новый ключ на вкладке `Лицензия` или приложение обновляет текущий ключ при следующей проверке лицензии.

## Точечные исключения

Уровень можно расширить или ограничить через feature flags:

```json
{
  "license_group": "basic",
  "allow_features": ["statistics"],
  "deny_features": ["stream"]
}
```

`deny_features` сильнее уровня и `allow_features`.

Текущие feature names:

```text
overview
overview_session_stats
fishing
fishing_bot
fishing_tackle
statistics
telegram
stream
stream_chat
settings
```

`settings` оставлен для совместимости. В интерфейсе раздел Настройки доступен независимо от подписки.
