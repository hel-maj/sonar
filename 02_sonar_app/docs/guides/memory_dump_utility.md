# Утилита дампа памяти игры

`sonar.tools.dump_process_memory` делает повторяемые read-only слепки памяти
`GTA5.exe` и `majestic-webengine.exe`. Формат совместим с
`dump_chat_history --memory-dump`: в каждой папке есть `manifest.json`, а байты
процессов лежат рядом в `memory.bin`.

Запускать из PowerShell в `02_sonar_app`:

```powershell
python -m sonar.tools.dump_process_memory --mode auto --list-processes
```

Если `OpenProcess failed`, откройте PowerShell от администратора. Утилита не
инжектит код и не пишет в процесс, но читает его память.

## Быстрый ручной цикл

Серия дампов по Enter:

```powershell
python -m sonar.tools.dump_process_memory --mode auto --interactive --select --name probe
```

1. Если включён `--select`, утилита сразу покажет процессы и попросит выбрать
   индексы или PID через запятую.
2. Нажмите Enter для первого дампа.
3. Сделайте действие в игре.
4. Снова нажмите Enter для следующего дампа.
5. Введите `q`, чтобы завершить серию. Команда `l` внутри цикла повторно
   покажет выбранные процессы.

Серия сохраняется в `..\logs\chat_memory\probe_series_YYYYMMDD_HHMMSS`.
Каждый снимок лежит в подпапке `snapshot_001_*`, `snapshot_002_*` и так далее.

## Режимы

- `--mode gtav` - только `GTA5.exe`.
- `--mode webengine` - все `majestic-webengine.exe`; с `--select` можно выбрать
  несколько renderer PID.
- `--mode all` или `--mode auto` - `GTA5.exe` плюс WebEngine.
- `--mode cache` - только кешированные окна памяти чата и состояния из
  `chat_windows_latest.json` / `chat_state_windows_latest.json`.
- `--mode near-player` - окна вокруг найденных адресов `player`, `fish` и
  `replay_interface` в `GTA5.exe`.
- `--mode map` - только карта readable regions и modules, без байтов памяти.
- `--mode custom --pid 12345` или `--process name.exe,pid:12345` - ручной выбор.

Полный `GTA5.exe` может занимать много гигабайт. Для разведки сначала используйте
карту или лимит:

```powershell
python -m sonar.tools.dump_process_memory --mode gtav --region-mode map --name gta_map
python -m sonar.tools.dump_process_memory --mode gtav --max-total-mb 512 --name gta_limited
```

## Полезные команды

Только WebEngine renderer после выбора PID:

```powershell
python -m sonar.tools.dump_process_memory --mode webengine --select --interactive --name web_probe
```

Кешированные окна памяти чата:

```powershell
python -m sonar.tools.dump_chat_history --process auto
python -m sonar.tools.dump_process_memory --mode cache --interactive --name chat_cache_probe
```

Окна рядом с игроком:

```powershell
python -m sonar.tools.dump_process_memory --mode near-player --interactive --name near_player_probe
```

Увеличить окна around player/fish:

```powershell
python -m sonar.tools.dump_process_memory --mode near-player --near-window-kb 2048 --name near_player_wide
```

## Сравнение двух дампов

```powershell
python -m sonar.tools.dump_process_memory --compare `
  ..\logs\chat_memory\probe_series_20260612_010000\snapshot_001_20260612_010005 `
  ..\logs\chat_memory\probe_series_20260612_010000\snapshot_002_20260612_010040 `
  --compare-key process-pid
```

Результат `memory_diff_*.json` содержит:

- `comparable_bytes` - сколько байтов удалось сравнить по одинаковым адресам;
- `changed_bytes` - сколько байтов отличается;
- `changed_ranges` - первые диапазоны адресов, где были изменения.

Если процесс перезапустился между дампами, используйте `--compare-key process`,
но трактуйте результат осторожно: адресное пространство могло измениться.

## Как использовать дамп дальше

Для чтения истории чата из сохранённого слепка:

```powershell
python -m sonar.tools.dump_chat_history --memory-dump ..\logs\chat_memory\probe_20260612_010000
```

Для дальнейшего анализа смотрите:

- `manifest.json` - процессы, PID, modules, выбранные regions, anchors/cache
  metadata;
- `selected_regions` - что планировалось читать;
- `regions` - что реально записалось в `memory.bin`;
- `memory_map` в режиме `map` - карта readable regions без байтов.

## Практические ограничения

- Дамп - это снимок процесса на момент чтения; живой процесс может менять память
  во время записи.
- `--mode cache` работает только с валидным кешем текущего процесса. Если игра
  или WebEngine перезапущены, manifest покажет `process_restarted`,
  `parent_restarted` или другой cache reason.
- Для больших дампов держите достаточно свободного места на диске.
