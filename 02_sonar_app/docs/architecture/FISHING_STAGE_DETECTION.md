# Native Fishing stage detection

Статус: production composition подключена; offline parity accepted, guarded
live acceptance ещё не выполнен.

## Goal и граница

`native/fishing_stage_detection` принадлежит Sonar Fishing и переносит только
визуальное распознавание пяти legacy trigger-состояний:

- `ad` -> `reeling`;
- `start2` и `wait_tension` -> `waiting_for_bite`;
- `start1` -> `casting`;
- `start` -> `tackle_selection`;
- отсутствие принятого match -> `none`.

Порядок выше является product policy и сохраняет фактический legacy priority.
Модуль принимает immutable BGR24 frame view и возвращает stage, исходный
trigger ID, confidence и normalized bounds. Он не открывает процесс/окно, не
захватывает экран, не читает память, не вызывает input/clipboard/network и не
имеет Host RPC.

Сам detector по-прежнему не владеет capture, catch/tackle OCR, side effects или
production admission. Normal Engine и отдельный non-shipping
[live observation preflight](LIVE_OBSERVATION_PREFLIGHT.md) композируют его как
pure часть цельной C++ operation; Host не получает frame/stage RPC.

## Build inputs и release representation

Десять FHD/2K gray8 templates находятся в
`native/fishing_stage_detection/assets`. `manifest-v1.tsv` фиксирует размеры,
SHA-256 текущего PGM и SHA-256 исторического PNG, из которого получен каждый
template. PGM является language-neutral migration asset, а CMake встраивает его
байты в static native target; loose PNG/PGM, OpenCV, Python interpreter, wheel
или OCR model не требуются runtime/bundle.

`scripts/test_ipc.ps1` до configure проверяет exact hash/size всех embedded
assets и 30 screenshot fixtures. Generated C++ существует только внутри
`build/` и не является новым source owner.

## Geometry и matching

FHD/2K ROI сохраняют product semantics, но масштабируются от актуальной
client-frame geometry. Для совместимого близкого к 16:9 кадра больше legacy
112% limit применяется area normalization до соответствующего reference
viewport; 4K поэтому обрабатывается через 2K representation. Для остальных
размеров ROI и template scale вычисляются из фактических width/height. Physical
screen coordinates и один display mode не используются.

Gray conversion сохраняет OpenCV fixed-point BGR coefficients. Полный поиск
использует `TM_CCOEFF_NORMED`-совместимую формулу: FFT ускоряет только raw
cross-correlation, а local sum/variance вычисляются для каждой позиции через
integral images. Threshold, scale priority и early acceptance `>= 0.98`
сохраняют characterization semantics.

## Parity и measured optimization

Первый корректный Release baseline до optimization:

- corpus: `30/30` FHD/2K/4K;
- maximum confidence delta к текущему OpenCV oracle: `0.000287584`;
- p50 `98.4974 ms`, p95 `216.366 ms`, max `217.859 ms`;
- process CPU `4140.62 ms`, peak working set `76,177,408` bytes.

Baseline показал latency hotspot относительно legacy stage loops с bounded
50 ms waits. После parity отдельная optimization сохранила формулу и весь
corpus: FFT twiddle factors готовятся один раз на 2D plan, а только два больших
tension spectra удерживаются в thread-safe cache максимум на четыре entries.
Маленькие stage templates не кэшируются.

Повторный Release measurement:

- corpus и maximum confidence delta не изменились;
- p50 `86.9563 ms` (-11.7%), p95 `150.553 ms` (-30.4%), max `150.765 ms`;
- process CPU `3046.88 ms` (-26.4%);
- peak working set `84,627,456` bytes (+8,450,048 bytes).

Рост памяти является измеренным bounded trade-off только для больших tension
spectra. Дальнейшая algorithm change без нового corpus/performance evidence не
принимается.

## Acceptance и remaining gates

Текущий acceptance:

- `SonarFishingStageDetectionTests`: `30/30`, invalid frame fail-closed;
- native/IPC CTest и managed IPC integration проходят текущий repository gate;
- MSVC v143 Release `/W4 /WX`, managed warnings/errors `0/0`;
- managed/native no-Python ownership scans green;
- GTA/window/capture/input/network не запускались.

Normal Engine уже использует exact target resolver, coherent capture и detector
внутри whole fishing episode. До live acceptance остаются authentic
multi-resolution/DPI runs, focus/target loss, supported-build confirmation и
отдельный physical-input/crash-cleanup gate. Non-shipping preflight позволяет
проверить observation path без создания input authority, но сам по себе не
разрешает автоматизацию.
