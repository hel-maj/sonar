# Fishing live observation preflight

Статус: non-shipping prerequisite реализован и принят offline. Первый live GTA
pass 2026-08-24 выполнился ровно один раз и fail-closed обнаружил unsupported
game build; дальнейших live reads в этой попытке не было.

## Назначение

`Sonar.Fishing.LiveObservationPreflight.exe` проверяет только read-only часть
production observation path перед отдельной проверкой автоматизации:

```text
exact GTA5.exe resolver
  -> current foreground client snapshot
  -> exact executable hash / embedded profile selection
  -> one coherent GDI client frame
  -> production Fishing stage detector
  -> one bounded reeling memory aggregate
  -> sanitized readiness result
```

Это отдельный product-owned diagnostic executable, а не новый Host/Engine RPC.
Он не разделяет production fishing episode и не даёт authority на действие.

## Жёсткая read-only граница

Preflight никогда не создаёт mutation sink, input lease, packet budget, hotkey
reader, clipboard writer или network transport. Он не активирует окно, не
двигает курсор и не отправляет клавиатурные/мышиные события. Construction
adapter-а инертен; observation начинается только после exact аргумента
`--confirmed-live-read-only`.

Один запуск делает не больше одного вызова каждого coarse шага. Capture
отклоняется до выделения frame buffer, если client area больше `16 777 216`
пикселей. Memory resolver сохраняет существующие bounds: module scan не больше
256 MiB, один read не больше 256 KiB, не больше 96 regions и 1 MiB aggregate.
Любая смена process/window generation, geometry, profile или sequence даёт
fail-closed result.

Stdout содержит только schema version, общий флаг и шесть readiness flags:
`process`, `window`, `build`, `profile`, `capture`, `memory`, плюс один stable
reason key. PID, HWND, пути, executable hash, addresses, raw frame, detector
confidence/stage и memory values наружу не выводятся.

## Безопасная команда разработчика

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\run_live_observation_preflight.ps1 -ConfirmedLiveReadOnly
```

Скрипт сначала выполняет offline gate/build, затем проверяет imports готового
EXE на input API и network DLL. Для уже принятой сборки можно явно добавить
`-NoBuild`. После подтверждения скрипт даёт минимум пять секунд, чтобы вернуть
GTA на передний план, и делает ровно один observation pass.

Перед каждым live запуском нужен новый gate:

1. Запустить поддерживаемую сборку GTA/Majestic и перейти в сцену рыбалки с
   активной рыбой, чтобы reeling memory aggregate был наблюдаем.
2. Закрыть игровые меню и оставить client area видимой, не свёрнутой.
3. Запустить команду с `-ConfirmedLiveReadOnly`.
4. Во время пятисекундного отсчёта вернуть GTA на передний план и не менять
   окно/разрешение до результата.
5. Принять только `ready=true`; любой другой reason не разрешает physical-input
   stage и требует нового запуска после устранения причины.

Звуковые сигналы отсутствуют: команда использует только консольный countdown и
одну JSON-строку результата. Она не запускает GTA и не повторяет попытку.

## Build, tests и release exclusion

CMake option `SONAR_FISHING_BUILD_LIVE_OBSERVATION_PREFLIGHT` по умолчанию
`OFF`. `scripts/test_ipc.ps1` включает его только в offline test build и
проверяет:

- pure runner success/failure, one-shot ordering и capture budget;
- fail-closed unsupported build, detector и memory paths;
- exact coarse JSON allowlist без fine/sensitive данных;
- source boundary без mutation API и запуск без подтверждения с exit code 64;
- normal native CTest/IPC regression suite.

Release build не включает option, package recipe копирует только `Sonar.exe` и
`Sonar.Engine.exe`, а bundle allowlist отвергает diagnostic executable. Поэтому
preflight не попадает в shipping/install/update bundle.

Успешный read-only результат является только evidence для E09-E11. Он не
подтверждает лицензию, final input gate, key-up cleanup, overlay, полный fishing
episode или устойчивость длительной сессии. Эти проверки остаются отдельными
явно подтверждаемыми этапами.

Первый live результат имел `process/window/build/capture=true`,
`profile/memory=false`, reason `game_build_unsupported`. Единственный frozen
profile не совпал с текущим executable hash; hash намеренно не входит в coarse
JSON. Production registry не изменялся. Для отдельной evidence-проверки нового
hash подготовлен [build-profile compatibility probe](BUILD_PROFILE_COMPATIBILITY_PROBE.md),
который также не является wildcard fallback или registry admission.

Единственный последующий compatibility pass получил candidate SHA-256, но
fail-closed завершился `pattern_scan_incomplete`: cross-pattern uniqueness,
fish identity и coherent snapshot не подтверждены. Поэтому новый hash не
enrolled, а inventory open/close и другие physical-input проверки не
выполнялись.
