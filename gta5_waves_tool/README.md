# GTA V Waves Portable

Портативный скрипт для отключения/возврата волн в `weather.xml` без ручного OpenIV.

## Граница Sonar Fishing

Это отдельная **nonshipping dev utility** вне `02_sonar_app`. Она не входит в
исходники, setup/test/build/package entrypoints, runtime composition или release
bundle Sonar Fishing. Её локальный Python нужен только для ручной подготовки
GTA-файлов и не является Python-зависимостью продукта.

## Главное изменение

Скрипт больше не заменяет `weather.xml` целиком из `payload/base_weather.xml`.

Теперь он создаёт `.oiv` с XML-patch командами и меняет только параметры из `config.json -> parameters` прямо в текущем установленном `weather.xml` внутри RPF. Поэтому Redux/NEVEK/No Night и другие значения погоды сохраняются.

`payload/base_weather.xml` лежит как fallback/reference. Обычный режим установки его не использует для перезаписи редакса.

## Какие архивы обрабатываются

- `update/update.rpf/common/data/levels/gta5/weather.xml`
- `common.rpf/data/levels/gta5/weather.xml`
- `mods/update/update.rpf/common/data/levels/gta5/weather.xml`
- `mods/common.rpf/data/levels/gta5/weather.xml`

Если `mods/update/update.rpf` или `mods/common.rpf` отсутствуют, скрипт может создать их как копию текущего игрового архива и применить только XML-patch волновых параметров.

## Что меняется при отключении волн

Список параметров задаётся в `config.json -> parameters`.

Текущий no-waves preset:

```xml
<RippleBumpiness value="0.320000" />
<RippleMinBumpiness value="0.160000" />
<RippleMaxBumpiness value="0.370000" />
<OceanBumpiness value="0.150000" />
<OceanNoiseMinAmplitude value="0.000000" />
<OceanWaveAmplitude value="0.000000" />
<ShoreWaveAmplitude value="0.000000" />
<OceanWaveWindScale value="0.000000" />
<ShoreWaveWindScale value="0.000000" />
<OceanWaveMinAmplitude value="0.000000" />
<ShoreWaveMinAmplitude value="0.000000" />
<OceanWaveMaxAmplitude value="0.000000" />
<ShoreWaveMaxAmplitude value="0.000000" />
```

Все остальные параметры редакса не должны меняться.

## Важно про mods

Папка `mods` не загружается обычной GTA V сама по себе. Для неё нужны `dinput8.dll` и `OpenIV.asi`/`RageOpenV.asi`. Поэтому скрипт также меняет оригинальные `update.rpf` и `common.rpf`.

## Запуск

Запусти `run.bat`.

Перед изменениями скрипт делает бэкапы RPF в папку `backups`.
