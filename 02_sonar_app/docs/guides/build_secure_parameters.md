# Параметры защищённой сборки

Этот документ является справочником параметров `scripts/build_secure.ps1`.
Порядок выпуска версии описан в [update_release_full.md](update_release_full.md),
а модель защиты - в [release_build_security.md](release_build_security.md).

## Важные побочные эффекты

Каждый фактический запуск сборки перед началом полностью удаляет:

```text
02_sonar_app/build
02_sonar_app/dist
```

Не запускайте две сборки одновременно. Сначала сохраните нужные артефакты из
`dist`. Скрипт также может скачать streaming binaries и, если не передан
`-SkipInstall`, установить или обновить build-зависимости выбранного Python
3.12.

## Полный список параметров

| Параметр | Default | Назначение и ограничения |
| --- | --- | --- |
| `-SkipInstall` | выключен | Пропускает `pip install --upgrade -e .[build]`. Используйте только когда build-зависимости Python 3.12 уже установлены. |
| `-Count <N>` | `1` | Создаёт `N` защищённых exe и zip. Значение должно быть больше нуля. Сам скрипт не задаёт верхнюю границу. |
| `-BuildKey <hex>` | новый случайный ключ | Повторно использует 11-символьный современный или 64-символьный legacy hex key. Допустим только с `Count 1`. Не вводите произвольное значение для обычного релиза. |
| `-ObfuscationSeed <value>` | новый случайный seed | Фиксирует генератор branding, build hash, encrypted literals и обфускации. Допустим только с `Count 1`. |
| `-LicenseServerUrl <url>` | environment, `.env`, затем dev-placeholder | Вшивает публичный base URL лицензии и обновлений. Для пользовательского релиза явно передавайте `https://m-sonar-addr.ru`. Завершающий `/` удаляется. |
| `-LicenseAccountId <id>` | environment, `.env`, затем пусто | Включает account-scoped Keygen routes. Текущей production-схеме не требуется. Не выводить в обычный launcher. |
| `-StartupBlockUrl <url>` | встроенный production URL | Переопределяет endpoint startup block. Встроенное значение: `https://m-sonar-addr.ru/api/startup-block`. Ошибка приводит к fail-closed запуску клиента. |
| `-StartupBlockPublicKey <key>` | встроенный production public key | Переопределяет Ed25519 public key проверки startup block. Это не private key. Ошибка приводит к fail-closed запуску клиента. |
| `-IconName <file.png>` | случайный доступный PNG | Выбирает точный файл из `assets/game_icons`. Stem файла задаёт имя приложения и exe. Допустим только с `Count 1`. |
| `-NoLto` | выключен | Передаёт Nuitka `--lto=no` вместо `--lto=yes`. Используйте только как fallback при internal compiler error MinGW. |

Пустые значения URL и account-параметров разрешают
`prepare_build_branding.py` применить environment, `.env` или встроенное
значение. Приоритет источников описан в
[environment_variables.md](environment_variables.md).

## Безопасные варианты запуска

Одна release-сборка с уже установленными зависимостями:

```powershell
powershell -ExecutionPolicy Bypass -File .\scripts\build_secure.ps1 `
  -SkipInstall `
  -Count 1 `
  -LicenseServerUrl "https://m-sonar-addr.ru"
```

Набор случайных сборок:

```powershell
powershell -ExecutionPolicy Bypass -File .\scripts\build_secure.ps1 `
  -SkipInstall `
  -Count 20 `
  -LicenseServerUrl "https://m-sonar-addr.ru"
```

Установить или обновить build-зависимости и собрать один exe:

```powershell
powershell -ExecutionPolicy Bypass -File .\scripts\build_secure.ps1 `
  -Count 1 `
  -LicenseServerUrl "https://m-sonar-addr.ru"
```

Fallback без LTO:

```powershell
powershell -ExecutionPolicy Bypass -File .\scripts\build_secure.ps1 `
  -SkipInstall `
  -Count 1 `
  -LicenseServerUrl "https://m-sonar-addr.ru" `
  -NoLto
```

Сборка с выбранной иконкой:

```powershell
powershell -ExecutionPolicy Bypass -File .\scripts\build_secure.ps1 `
  -SkipInstall `
  -Count 1 `
  -LicenseServerUrl "https://m-sonar-addr.ru" `
  -IconName "Example.png"
```

## Повтор известной build identity

Для восстановления идентичности известной сборки возьмите из
`config/sonar_build_keys.json`:

- build key;
- obfuscation seed;
- имя файла из `icon_png`.

Запускайте только с `Count 1`:

```powershell
powershell -ExecutionPolicy Bypass -File .\scripts\build_secure.ps1 `
  -SkipInstall `
  -Count 1 `
  -BuildKey "<build_key>" `
  -ObfuscationSeed "<seed>" `
  -IconName "<icon-file.png>" `
  -LicenseServerUrl "https://m-sonar-addr.ru"
```

Это повторяет build key, seed, имя и иконку, но не обещает побайтово
идентичный exe. Текущая карта не сохраняет URL overrides, account id,
startup-block overrides, LTO mode и версии toolchain. Для расследования старой
сборки эти значения нужно подтвердить отдельно.

## Логи

У `build_secure.ps1` нет параметра специальной сборки с логами. Ход сборки уже
выводится в консоль, а пользовательский exe создаётся с отключённым console
window. Runtime-логи frozen exe включаются отдельно переменной окружения
`SONAR_ENABLE_RELEASE_LOGS=1` при запуске exe.

Прямой вывод `build_secure.ps1` содержит build identity, включая obfuscation
seed, и не должен сохраняться без фильтрации. Sonar Container может сформировать
журнал только через wrapper с `build-log-sanitizer.ps1`. Wrapper не использует
`Start-Transcript`: он записывает в product-local `logs\container-build` только
уже отфильтрованные строки. Это журнал процесса сборки, а не изменение поведения
собранного приложения.
