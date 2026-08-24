# Аудит пользовательских функций Sonar Fishing

Статус: current native implementation audited offline

Дата проверки: 2026-08-24

Этот документ отделяет реально доступные функции исторической Python-версии от
текущего native owner и внешних runtime prerequisites. Наличие UI, router или
fake adapter не считается работающей production-функцией.

Compile-isolated local-access bundle снимает только внешние licensing/entitlement
и signed startup availability/update-block admission gates
и не меняет строки этой матрицы: отсутствующий adapter или unsupported GTA
profile остается недоступным, а все memory/window/capture/input safety gates
остаются обязательными. Product UI показывает `Локальный доступ` без key prompt,
raw feature IDs и build terminology; техническая identity остается в manifest и
diagnostics. См. [ADR-0002](ADR-0002-DEVELOPER-FULL-ACCESS-AUTHORITY.md).

## Матрица parity

| Legacy capability | Native owner | Runtime dependency | Проверено / осталось |
| --- | --- | --- | --- |
| Обычный запуск приложения | `Sonar.exe` без аргументов + supervised `Sonar.Engine.exe` | .NET Desktop Runtime 10 x64; startup admission | Product command и package contract есть. Offline demo cycles и inert packaged Engine crash/replacement проверяются отдельно; normal launch зависит от реального startup endpoint |
| Запуск/остановка рыбалки из UI и hotkey | одна coarse Engine automation session; Host и global hotkey вызывают тот же command | подписанная entitlement, exact GTA process/window/build profile, foreground и final input gates | Реализация и offline state-machine/IPC gates есть; read-only candidate pass вернул `pattern_scan_incomplete`, поэтому текущий GTA hash не admitted и physical-input acceptance не выполнялась |
| Catch/inventory/meal/bait/equipment/statistics | C++ production episodes + revisioned aggregate IPC; session statistics только в памяти | та же live authority; authentic UI/game evidence | Native episodes и fixtures есть. Inventory state отделён от reeling и допускает только coherent memory + Common contract; screenshot владеет лишь geometry. Но shipping inventory binding отсутствует, а current hash не admitted, поэтому current build даёт `unknown` / `memory_game_build_unsupported`; старый admitted profile дал бы `memory_inventory_binding_unavailable`. Inventory-dependent episode ещё не production-usable. Подготовлен один manual `CLOSED/OPEN` characterization run |
| Настройки и hotkeys | Host state coordinator, atomic `config/state.dat`, DPAPI secrets, revisioned Engine apply | текущий Windows user | Save/coalescing, rapid toggle, navigation/focus и hotkey lifecycle покрываются managed tests; live hotkey side effect не выполнялся |
| Legacy license settings | `LegacyLicenseKeyImporter` через local maintenance command | точный существующий `license_settings.json`; backend для повторной проверки | Импортируется только `license_key` в DPAPI state. Legacy id/role/features/dates никогда не становятся trust evidence; source сохраняется |
| Лицензирование | Common verification + product HTTPS transport/cache + independent Engine admission | действующий backend response и entitlement | Полный offline signature/cache/revocation contract есть; production credential/backend acceptance внешняя |
| Telegram transport, меню, start/stop, statistics, tackle | bounded HTTPS long poll + `TelegramCommandDispatcher` + native fishing use case | token/admin IDs, feature entitlement, сеть | Credential-independent routing/composition покрыты. Реальный transport требует пользовательскую конфигурацию |
| Telegram automatic catch/start-stop/meal/inventory/bait/focus notifications | typed production Engine occurrence stream -> current-generation supervisor source -> bounded Host publisher | те же token/admin IDs/network плюс authentic production Engine facts | Producer, wire, generation/sequence dedupe, no-replay и send-failure isolation покрыты offline. Фото не делается. Реальная сеть не запускалась; live GTA event delivery остается acceptance |
| Telegram player status / rescan | DTO/formatters существуют, production coarse Engine query отсутствует | supported memory profile + new coarse aggregate IPC operation | Legacy команда была product-facing; сейчас menu скрывает capability и dispatcher fail-closed. Нельзя подменять Host-side memory read |
| Telegram screenshot | production adapter отсутствует | отдельный fresh capture gate, exact target/generation and privacy policy | Legacy команда была product-facing; current router сохраняет intent, но menu скрывает его и direct call rejects |
| Telegram focus game | production adapter отсутствует | exact target/generation + user-approved foreground activation | Legacy команда была product-facing; Host-side `SetForegroundWindow` shortcut запрещён, нужен coarse Engine operation и final gate |
| Telegram close game | production adapter отсутствует | exact process generation, explicit destructive policy and confirmation semantics | Legacy команда была product-facing; current route не рекламируется и rejects |
| Telegram shutdown PC | production adapter отсутствует | authenticated admin, explicit destructive policy, final confirmation and OS authority | Legacy команда была product-facing; намеренно не реализована как неограждённый Host shortcut |
| Streaming capture/HLS/public link/chat mode | `StreamingRuntimeController` владеет lifecycle contract; normal composition использует `UnavailableStreamingController` | approved redistributable encoder/tunnel or native mux path, guarded capture, authenticated viewer, HTTPS tunnel | Legacy FFmpeg/cloudflared runtime был реальным. Eleven fake-adapter lifecycle tests доказывают только core; production streaming пока недоступен и UI честно fail-closed |
| Local install/update/rollback/interrupted recovery | product-owned local maintenance executor + общий `ReleaseSwapTransaction` | exact development-unsigned bundle; production path дополнительно требует signing/backend metadata | Product wrapper фактически прошёл isolated install/update/rollback/interrupted recovery с allowlist/no-Python после каждого этапа; production-signed activation не имитируется |
| Remote signed update | signed manifest/stager/swap core | production public key, metadata endpoint, Authenticode certificate/timestamp and signed distribution acceptance | Core проверен fake transport/filesystem. Remote production composition остаётся fail-closed |
| Game overlay | отсутствовал как product-facing legacy owner и отсутствует в native composition | не применимо | `overlay` в legacy встречался только как detector rejection term и Pillow visual layer; game/stream overlay window, toggle или consumer не найден. Поэтому Fishing overlay нечего активировать или визуально принимать |

## Почему Telegram gaps не закрыты Host-side WinAPI

Screenshot, game focus, player-memory scan и game shutdown относятся к одному
exact process/window generation и safety lifecycle. Разнести observation,
foreground activation и side effect по Host callbacks означало бы потерять
generation/final-gate invariant. Их target state — отдельные coarse Engine
operations с bounded aggregate result. PC shutdown дополнительно требует
отдельной destructive-command policy; наличие старого callback не является
достаточной авторизацией.

## Streaming boundary

Историческая версия могла скачать и запустить FFmpeg/cloudflared. Текущий strict
двух-EXE release не может молча включить найденный GPL FFmpeg или непроверенный
network payload. Credential-independent lifecycle, cancellation, restart и
cleanup уже реализованы; недостающие capture/viewer/tunnel adapters перечислены
в [H07 runtime](H07_STREAMING_RUNTIME.md). Пока они не подтверждены, normal
composition обязана оставаться fail-closed, а migrated feature нельзя выдавать
за рабочую по наличию одной страницы.

## Overlay semantics

Fishing использует captured game frame для semantic detectors, но это не
overlay. Native Host показывает обычные WPF pages и не создаёт topmost,
click-through или injected game surface. Stream viewer тоже не является game
overlay. Проверка Hunting/Poker overlays выполняется их владельцами и не может
служить доказательством Fishing.

## Release evidence rule

Offline test, fake adapter, development-unsigned lifecycle и production live
acceptance записываются раздельно. Отсутствие внешнего секрета не скрывает UI и
contract функции, но также не разрешает fake entitlement, wildcard build
profile, unsigned production claim или сетевой payload неизвестного
происхождения.
