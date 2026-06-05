# Доступные URL

Текущий публичный домен:

```text
https://m-sonar-addr.ru
```

HTTP-версии этих адресов Caddy перенаправляет на HTTPS.

## Для пользователей

| URL | Что делает |
| --- | --- |
| `https://m-sonar-addr.ru/download` | Страница загрузки. Автоматически переводит браузер на случайный zip из latest version folder в `builds`. |
| `https://m-sonar-addr.ru/api/random-build.zip` | Прямая ссылка на случайный готовый zip из latest version folder. Отдает файл как attachment. |
| `https://m-sonar-addr.ru/api/startup-block` | Подписанная POST-проверка blocklist по build key и license key перед запуском приложения. |
| `https://m-sonar-addr.ru/sonar-release.json` | Глобальная release metadata для приложения: версия, сообщение обновления, `download_link`. |

## Для проверки сервера

| URL | Что делает |
| --- | --- |
| `https://m-sonar-addr.ru/random-build-health` | Health check сервиса случайной выдачи zip. Показывает `latest_version`, `latest_builds_dir`, `archive_count`, `invalid_archive_count` и `total_archive_count`. |
| `https://m-sonar-addr.ru/` | Корень Keygen API. В браузере может вернуть `404`, это нормально: это не лендинг и не страница скачивания. |

## License API

Эти URL использует приложение. Открывать их в браузере вручную обычно не нужно.

| URL | Метод | Что делает |
| --- | --- | --- |
| `https://m-sonar-addr.ru/v1/licenses/actions/validate-key?include=policy` | `POST` | Проверка ключа лицензии и получение policy metadata. |
| `https://m-sonar-addr.ru/v1/machines` | `POST` | Активация текущего компьютера для лицензии. |
| `https://m-sonar-addr.ru/v1/machines/<fingerprint>` | `PATCH` | Обновление machine metadata: build hash, build key, имя сборки, IP. |

Если в сборку когда-нибудь будет вшит `SONAR_LICENSE_ACCOUNT_ID`, routes станут account-scoped:

```text
https://m-sonar-addr.ru/v1/accounts/<account_id>/licenses/actions/validate-key?include=policy
https://m-sonar-addr.ru/v1/accounts/<account_id>/machines
https://m-sonar-addr.ru/v1/accounts/<account_id>/machines/<fingerprint>
```

Сейчас account id для клиента не нужен, поэтому приложение ходит на обычные `/v1/...` routes.

## Админка

| URL | Что делает |
| --- | --- |
| `https://ui.m-sonar-addr.ru/` | Keygen UI для администрирования лицензий. Не давать пользователям. |

## Редиректы

| URL | Куда ведет |
| --- | --- |
| `https://www.m-sonar-addr.ru/...` | `https://m-sonar-addr.ru/...` |
| `https://sonar-keygen.m-sonar-addr.ru/...` | `https://m-sonar-addr.ru/...` |

## DNS, но не web URL приложения

`mail.m-sonar-addr.ru` указывает на сервер как DNS A/MX host, но приложение Sonar его не использует. В Caddy для него отдельный web-сайт не настроен.
