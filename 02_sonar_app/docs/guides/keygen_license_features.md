# Лицензии, группы и feature flags в Keygen

В приложении Sonar доступ к функциям теперь считается из metadata лицензии и policy.

Логика такая:

1. Metadata policy задает базовую группу и набор возможностей для всех лицензий этой policy.
2. Metadata конкретной лицензии может переопределить или дополнить это для одного пользователя.
3. Глобальный `sonar-release.json` задает общую информацию об обновлении для всех.

## Основные поля metadata

```json
{
  "license_group": "basic",
  "allow_features": ["telegram"],
  "deny_features": ["streaming"],
  "latest_version": "1.2.3",
  "update_message": "🚀 Новая версия\nИсправлены ошибки",
  "download_link": "https://m-sonar-addr.ru/download"
}
```

Поля:

- `license_group` - имя группы лицензии.
- `allow_features` - фичи, которые надо добавить поверх группы.
- `deny_features` - фичи, которые надо явно выключить.
- `latest_version` - версия, которую увидит пользователь.
- `update_message` - текст обновления, поддерживает `\n` и emoji.
- `download_link` - отдельная ссылка скачивания. Если поле задано, в интерфейсе появится ссылка.

## Доступные группы

Группы задаются в коде в `src\sonar\license\features.py`.

Базовая схема:

- `basic` - базовые экраны и настройки.
- `fishing` - рыбалка и связанные действия.
- `streamer` - рыбалка плюс streaming и stream chat.
- `pro` - все основные фичи.
- `admin` - полный доступ.

Если группы надо поменять, править надо `GROUP_FEATURES` в `features.py`.

## Доступные features

Текущие feature names:

```text
overview
fishing
settings
statistics
telegram
streaming
stream_chat
```

Их можно использовать в `allow_features` и `deny_features`.

## Как задать metadata сразу группе

В Keygen группа пользователей обычно соответствует policy. Поэтому массовые настройки надо задавать в metadata policy, а не в каждой лицензии.

Порядок:

1. Откройте `keygen-ui`.
2. Найдите нужную policy.
3. Откройте metadata этой policy.
4. Вставьте JSON.
5. Сохраните.

Пример для базовой группы:

```json
{
  "license_group": "basic",
  "latest_version": "1.2.3",
  "update_message": "✅ Базовое обновление\nДоступны общие исправления\nСсылка ведет на случайную сборку",
  "download_link": "https://m-sonar-addr.ru/download"
}
```

Пример для стримеров:

```json
{
  "license_group": "streamer",
  "allow_features": ["streaming", "stream_chat", "telegram"],
  "latest_version": "1.2.3",
  "update_message": "📺 Версия для стримеров\nОбновлена трансляция\nДобавлены правки stream chat",
  "download_link": "https://m-sonar-addr.ru/download"
}
```

Пример для pro:

```json
{
  "license_group": "pro",
  "latest_version": "1.2.3",
  "update_message": "🚀 Pro обновление\nИсправлена рыбалка\nУлучшены проверки статуса",
  "download_link": "https://m-sonar-addr.ru/download"
}
```

Пример временного ограничения:

```json
{
  "license_group": "pro",
  "deny_features": ["streaming"],
  "update_message": "⚠️ Streaming временно отключен\nОстальные функции работают"
}
```

## Как включить отдельную фичу одному пользователю

Откройте конкретную license и добавьте metadata:

```json
{
  "allow_features": ["telegram"]
}
```

Так пользователь останется в своей группе, но получит Telegram.

## Как отключить отдельную фичу одному пользователю

```json
{
  "deny_features": ["streaming"]
}
```

`deny_features` сильнее, чем группа и `allow_features`.

## Как не обновлять сотни лицензий вручную

Для массового `latest_version`, `update_message` и `download_link` используйте один из двух вариантов:

1. `sonar-release.json` на сервере, если всем показывается одно и то же.
2. Metadata на policy, если разным группам нужны разные тексты или версии.

Не добавляйте `latest_version` в каждую license, если это не персональное исключение.

## Приоритет metadata

Приоритет такой:

```text
sonar-release.json < policy metadata < license metadata
```

То есть:

- глобальный JSON дает значения по умолчанию;
- policy metadata переопределяет их для группы;
- license metadata переопределяет их для конкретного пользователя.

## Переносы строк и emoji

В JSON перенос строки пишется как `\n`:

```json
{
  "update_message": "🐟 Первая строка\n🚀 Вторая строка\n✅ Третья строка"
}
```

В интерфейсе это будет показано несколькими строками.

## download_link

Если `download_link` пустой или отсутствует, ссылка в интерфейсе не показывается.

Если задан:

```json
{
  "download_link": "https://m-sonar-addr.ru/download"
}
```

на главном экране появится хорошо вписанная ссылка скачивания.

