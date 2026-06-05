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
  "deny_features": ["stream"],
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

Текущая схема:

- `intro` - только вкладка Рыбалка, без запуска бота.
- `basic` - Рыбалка с запуском бота, Обзор и Telegram без стрима и расширенной статистики.
- `premium` - полный функционал.
- `dev` - сейчас копирует `premium`.
- `promo` - сейчас копирует `premium`.
- `admin` и `owner` - полный доступ.

Если группы надо поменять, править надо `GROUP_FEATURES` в `features.py`.

## Доступные features

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

Их можно использовать в `allow_features` и `deny_features`.

## Как задать metadata сразу группе

В Keygen группа пользователей обычно соответствует policy. Поэтому массовые настройки надо задавать в metadata policy, а не в каждой лицензии.

Порядок:

1. Откройте `keygen-ui`.
2. Найдите нужную policy.
3. Откройте metadata этой policy.
4. Вставьте JSON.
5. Сохраните.

Пример для Intro:

```json
{
  "license_group": "intro",
  "latest_version": "1.2.3",
  "update_message": "Обновление Sonar Intro\nДоступны общие исправления",
  "download_link": "https://m-sonar-addr.ru/download"
}
```

Пример для Basic:

```json
{
  "license_group": "basic",
  "latest_version": "1.2.3",
  "update_message": "Обновление Sonar Basic\nДоступны общие исправления",
  "download_link": "https://m-sonar-addr.ru/download"
}
```

Пример для Premium:

```json
{
  "license_group": "premium",
  "latest_version": "1.2.3",
  "update_message": "Обновление Sonar Premium\nИсправлена рыбалка и стрим",
  "download_link": "https://m-sonar-addr.ru/download"
}
```

Пример для Dev:

```json
{
  "license_group": "dev",
  "latest_version": "1.2.3",
  "update_message": "Обновление Sonar Dev\nПолный доступ для разработки",
  "download_link": "https://m-sonar-addr.ru/download"
}
```

Пример для Promo:

```json
{
  "license_group": "promo",
  "latest_version": "1.2.3",
  "update_message": "Обновление Sonar Promo\nПолный доступ для промо-ключей",
  "download_link": "https://m-sonar-addr.ru/download"
}
```

Пример временного ограничения:

```json
{
  "license_group": "premium",
  "deny_features": ["stream"],
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
  "deny_features": ["stream"]
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

Для random build downloads указывайте стабильный URL `https://m-sonar-addr.ru/download`, без номера версии в path. Сервер сам выберет latest version folder внутри `builds`.
