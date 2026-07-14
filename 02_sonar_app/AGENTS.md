# Agent Notes

## GTA/Majestic Memory Dumps

- Use `python -m sonar.tools.dump_process_memory` from `02_sonar_app` for repeatable process memory snapshots.
- Prefer `--mode map`, `--mode cache`, `--mode near-player`, or a small `--max-total-mb` before any full `GTA5.exe` dump. Full readable GTA memory can be many gigabytes.
- Use `--interactive` for manual before/after game actions and `--compare LEFT RIGHT` for JSON diffs.
- Dumps are written under `P:\projects\Majestic\Sonar\logs\chat_memory` by default.
- See `docs/guides/memory_dump_utility.md` for command examples and caveats.
