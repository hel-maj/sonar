from __future__ import annotations

import ctypes
import json
import mmap
import os
import re
import shutil
import subprocess
import sys
from dataclasses import dataclass
from datetime import datetime
from pathlib import Path
from typing import Iterable

try:
  import winreg
except ImportError:
  winreg = None

PARAMS = [
  'RippleBumpiness',
  'OceanBumpiness',
  'OceanWaveMinAmplitude',
  'OceanWaveMaxAmplitude',
  'ShoreWaveMaxAmplitude',
]

APP_ID_GTAV = '271590'
SCRIPT_DIR = Path(__file__).resolve().parent
CONFIG_PATH = SCRIPT_DIR / 'config.json'


@dataclass(frozen=True)
class GameInstall:
  path: Path
  source: str


def main() -> None:
  print('GTA V Waves Tool')
  print('================')

  config = load_config()
  installs = find_game_installs(config)

  if len(installs) == 0:
    print('GTA V не найдена автоматически.')
    print('Добавь путь в config.json -> target.extra_game_paths и запусти снова.')
    wait_enter()
    return

  game = choose_game(installs)
  target_values = choose_action(config)

  if target_values is None:
    print('Выход.')
    return

  rpf_path = get_rpf_path(game.path, config)

  if not rpf_path.exists():
    print(f'Не найден архив: {rpf_path}')
    wait_enter()
    return

  if not is_admin():
    print('Предупреждение: скрипт запущен без прав администратора.')
    print('Если GTA V лежит в Program Files или доступ запрещён, запусти run.bat от имени администратора.')
    print('')

  try:
    patch_rpf(rpf_path, target_values, config)
  except PermissionError:
    print('Нет доступа к update.rpf. Запусти скрипт от имени администратора и закрой GTA/OpenIV.')
  except RuntimeError as error:
    print(str(error))
  except Exception as error:
    print(f'Неожиданная ошибка: {error}')

  wait_enter()


def load_config() -> dict:
  if not CONFIG_PATH.exists():
    raise FileNotFoundError(f'Не найден config.json рядом со скриптом: {CONFIG_PATH}')

  with CONFIG_PATH.open('r', encoding='utf-8') as file:
    config = json.load(file)

  validate_config(config)
  return config


def validate_config(config: dict) -> None:
  if 'target' not in config:
    raise ValueError('В config.json нет блока target.')

  if 'values' not in config:
    raise ValueError('В config.json нет блока values.')

  for preset_name in ['default', 'no_waves']:
    if preset_name not in config['values']:
      raise ValueError(f'В config.json нет values.{preset_name}.')

    for param in PARAMS:
      if param not in config['values'][preset_name]:
        raise ValueError(f'В config.json нет values.{preset_name}.{param}.')

      value = str(config['values'][preset_name][param])

      if not re.fullmatch(r'-?\d+\.\d+', value):
        raise ValueError(f'Некорректное значение {preset_name}.{param}: {value}')


def find_game_installs(config: dict) -> list[GameInstall]:
  installs: list[GameInstall] = []

  installs.extend(find_steam_installs())
  installs.extend(find_epic_installs())
  installs.extend(find_rockstar_installs())
  installs.extend(find_extra_installs(config))

  unique: dict[str, GameInstall] = {}

  for install in installs:
    normalized = str(install.path.resolve()).lower()

    if normalized not in unique and is_gtav_dir(install.path):
      unique[normalized] = install

  return list(unique.values())


def find_steam_installs() -> list[GameInstall]:
  steam_roots = get_steam_roots()
  installs: list[GameInstall] = []

  for steam_root in steam_roots:
    libraries = get_steam_libraries(steam_root)

    for library in libraries:
      manifest_path = library / 'steamapps' / f'appmanifest_{APP_ID_GTAV}.acf'
      install_dir = parse_steam_install_dir(manifest_path)

      if install_dir is not None:
        installs.append(GameInstall(library / 'steamapps' / 'common' / install_dir, 'Steam manifest'))

      installs.append(GameInstall(library / 'steamapps' / 'common' / 'Grand Theft Auto V', 'Steam common'))

  return installs


def get_steam_roots() -> list[Path]:
  roots: list[Path] = []

  for key_root, key_path in get_steam_registry_keys():
    value = read_registry_value(key_root, key_path, 'SteamPath')

    if value is None:
      value = read_registry_value(key_root, key_path, 'InstallPath')

    if value is not None:
      roots.append(Path(value.replace('/', '\\')))

  for env_name in ['ProgramFiles(x86)', 'ProgramFiles']:
    env_path = os.environ.get(env_name)

    if env_path is not None:
      roots.append(Path(env_path) / 'Steam')

  return dedupe_paths(roots)


def get_steam_registry_keys() -> list[tuple[object, str]]:
  if winreg is None:
    return []

  return [
    (winreg.HKEY_CURRENT_USER, r'Software\Valve\Steam'),
    (winreg.HKEY_LOCAL_MACHINE, r'SOFTWARE\WOW6432Node\Valve\Steam'),
    (winreg.HKEY_LOCAL_MACHINE, r'SOFTWARE\Valve\Steam'),
  ]


def get_steam_libraries(steam_root: Path) -> list[Path]:
  libraries = [steam_root]
  libraryfolders_path = steam_root / 'steamapps' / 'libraryfolders.vdf'

  if not libraryfolders_path.exists():
    return dedupe_paths(libraries)

  try:
    text = libraryfolders_path.read_text(encoding='utf-8', errors='ignore')
  except OSError:
    return dedupe_paths(libraries)

  for match in re.finditer(r'"path"\s+"([^\"]+)"', text):
    raw_path = match.group(1).replace('\\\\', '\\')
    libraries.append(Path(raw_path))

  return dedupe_paths(libraries)


def parse_steam_install_dir(manifest_path: Path) -> str | None:
  if not manifest_path.exists():
    return None

  try:
    text = manifest_path.read_text(encoding='utf-8', errors='ignore')
  except OSError:
    return None

  match = re.search(r'"installdir"\s+"([^\"]+)"', text)

  if match is None:
    return None

  return match.group(1)


def find_epic_installs() -> list[GameInstall]:
  manifests_dir = Path(os.environ.get('PROGRAMDATA', r'C:\ProgramData')) / 'Epic' / 'EpicGamesLauncher' / 'Data' / 'Manifests'
  installs: list[GameInstall] = []

  if not manifests_dir.exists():
    return installs

  for manifest_path in manifests_dir.glob('*.item'):
    try:
      data = json.loads(manifest_path.read_text(encoding='utf-8', errors='ignore'))
    except Exception:
      continue

    display_name = str(data.get('DisplayName', ''))
    app_name = str(data.get('AppName', ''))
    install_location = data.get('InstallLocation')
    search_text = f'{display_name} {app_name}'.lower()

    if install_location is None:
      continue

    if 'grand theft auto v' in search_text or 'gtav' in search_text or 'gta v' in search_text:
      installs.append(GameInstall(Path(str(install_location)), 'Epic manifest'))

  return installs


def find_rockstar_installs() -> list[GameInstall]:
  installs: list[GameInstall] = []

  if winreg is None:
    return installs

  uninstall_roots = [
    (winreg.HKEY_LOCAL_MACHINE, r'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall'),
    (winreg.HKEY_LOCAL_MACHINE, r'SOFTWARE\WOW6432Node\Microsoft\Windows\CurrentVersion\Uninstall'),
    (winreg.HKEY_CURRENT_USER, r'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall'),
  ]

  for root, path in uninstall_roots:
    try:
      with winreg.OpenKey(root, path) as key:
        count = winreg.QueryInfoKey(key)[0]

        for index in range(count):
          try:
            subkey_name = winreg.EnumKey(key, index)

            with winreg.OpenKey(key, subkey_name) as subkey:
              display_name = read_registry_value_from_key(subkey, 'DisplayName') or ''
              install_location = read_registry_value_from_key(subkey, 'InstallLocation')

              if install_location is None:
                continue

              if 'grand theft auto v' in str(display_name).lower() or 'gta v' in str(display_name).lower():
                installs.append(GameInstall(Path(str(install_location)), 'Registry uninstall'))
          except OSError:
            continue
    except OSError:
      continue

  return installs


def find_extra_installs(config: dict) -> list[GameInstall]:
  installs: list[GameInstall] = []
  extra_paths = config.get('target', {}).get('extra_game_paths', [])

  if not isinstance(extra_paths, list):
    return installs

  for raw_path in extra_paths:
    installs.append(GameInstall(Path(str(raw_path)), 'config.json'))

  return installs


def read_registry_value(root: object, path: str, name: str) -> str | None:
  if winreg is None:
    return None

  try:
    with winreg.OpenKey(root, path) as key:
      value, _ = winreg.QueryValueEx(key, name)
      return str(value)
  except OSError:
    return None


def read_registry_value_from_key(key: object, name: str) -> str | None:
  if winreg is None:
    return None

  try:
    value, _ = winreg.QueryValueEx(key, name)
    return str(value)
  except OSError:
    return None


def is_gtav_dir(path: Path) -> bool:
  return path.exists() and (path / 'update' / 'update.rpf').exists() and ((path / 'GTA5.exe').exists() or (path / 'GTA5_Enhanced.exe').exists())


def dedupe_paths(paths: Iterable[Path]) -> list[Path]:
  unique: dict[str, Path] = {}

  for path in paths:
    try:
      key = str(path.resolve()).lower()
    except OSError:
      key = str(path).lower()

    if key not in unique:
      unique[key] = path

  return list(unique.values())


def choose_game(installs: list[GameInstall]) -> GameInstall:
  print('Найденные установки GTA V:')

  for index, install in enumerate(installs, start=1):
    print(f'{index}. {install.path} ({install.source})')

  if len(installs) == 1:
    print('')
    print(f'Выбрана единственная найденная установка: {installs[0].path}')
    print('')
    return installs[0]

  while True:
    answer = input('Выбери номер установки: ').strip()

    if answer.isdigit():
      index = int(answer)

      if 1 <= index <= len(installs):
        print('')
        return installs[index - 1]

    print('Некорректный выбор.')


def choose_action(config: dict) -> dict[str, str] | None:
  print('Что сделать?')
  print('1. Удалить волны')
  print('2. Вернуть волны')
  print('3. Выход')

  while True:
    answer = input('Выбери действие: ').strip()

    if answer == '1':
      return normalize_values(config['values']['no_waves'])

    if answer == '2':
      return normalize_values(config['values']['default'])

    if answer == '3':
      return None

    print('Некорректный выбор.')


def normalize_values(values: dict) -> dict[str, str]:
  return {param: str(values[param]) for param in PARAMS}


def get_rpf_path(game_path: Path, config: dict) -> Path:
  target = config.get('target', {})
  relative_path = target.get('rpf_archive_relative_path', 'update/update.rpf')
  return game_path / Path(str(relative_path))


def patch_rpf(rpf_path: Path, values: dict[str, str], config: dict) -> None:
  if not config.get('target', {}).get('allow_binary_patch_rpf', True):
    raise RuntimeError('В config.json отключён allow_binary_patch_rpf.')

  print(f'Архив: {rpf_path}')
  print('Ищу XML-параметры внутри update.rpf...')

  modifications = collect_modifications(rpf_path, values)

  if len(modifications) == 0:
    raise RuntimeError(
      'Не нашёл XML-теги с параметрами волн внутри update.rpf.\n'
      'Вероятно, weather.xml хранится в RPF в сжатом/зашифрованном виде.\n'
      'Скрипт ничего не изменил. В этом случае нужна замена через OpenIV/OIV/RPF-инструмент.'
    )

  create_backup(rpf_path, config)
  apply_modifications(rpf_path, modifications)

  print('')
  print('Готово. Изменённые параметры:')

  counts: dict[str, int] = {}

  for modification in modifications:
    counts[modification['param']] = counts.get(modification['param'], 0) + 1

  for param in PARAMS:
    count = counts.get(param, 0)
    print(f'- {param}: {count}')

  missing = [param for param in PARAMS if counts.get(param, 0) == 0]

  if len(missing) > 0:
    print('')
    print('Не найдены параметры:')

    for param in missing:
      print(f'- {param}')


def collect_modifications(rpf_path: Path, values: dict[str, str]) -> list[dict[str, object]]:
  modifications: list[dict[str, object]] = []

  with rpf_path.open('rb') as file:
    with mmap.mmap(file.fileno(), 0, access=mmap.ACCESS_READ) as mapped:
      for param in PARAMS:
        target = values[param].encode('ascii')
        pattern = re.compile(rb'<' + re.escape(param.encode('ascii')) + rb'\s+value="([^"]+)"\s*/>')

        for match in pattern.finditer(mapped):
          start, end = match.span(1)
          current = mapped[start:end]

          if len(current) != len(target):
            raise RuntimeError(
              f'Найден {param}, но длина значения отличается: {current.decode("ascii", errors="replace")} -> {values[param]}.\n'
              'In-place замена безопасна только при одинаковой длине значений. Сделай значение формата 0.000000.'
            )

          if current != target:
            modifications.append({
              'param': param,
              'start': start,
              'target': target,
              'old': current,
            })

  return modifications


def create_backup(rpf_path: Path, config: dict) -> None:
  backup_dir_name = str(config.get('target', {}).get('backup_dir_name', 'backups'))
  backup_dir = SCRIPT_DIR / backup_dir_name
  backup_dir.mkdir(parents=True, exist_ok=True)

  marker = backup_dir / backup_marker_name(rpf_path)

  if marker.exists():
    print(f'Бэкап уже есть: {marker}')
    return

  timestamp = datetime.now().strftime('%Y%m%d_%H%M%S')
  backup_path = backup_dir / f'update_{timestamp}.rpf'

  print(f'Создаю бэкап: {backup_path}')
  shutil.copy2(rpf_path, backup_path)
  marker.write_text(str(backup_path), encoding='utf-8')


def backup_marker_name(rpf_path: Path) -> str:
  raw = str(rpf_path.resolve()).lower()
  safe = re.sub(r'[^a-z0-9]+', '_', raw)
  return f'{safe}.backup.txt'


def apply_modifications(rpf_path: Path, modifications: list[dict[str, object]]) -> None:
  with rpf_path.open('r+b') as file:
    with mmap.mmap(file.fileno(), 0, access=mmap.ACCESS_WRITE) as mapped:
      for modification in modifications:
        start = int(modification['start'])
        target = modification['target']

        if not isinstance(target, bytes):
          raise TypeError('target должен быть bytes')

        mapped[start:start + len(target)] = target

      mapped.flush()


def is_admin() -> bool:
  if os.name != 'nt':
    return os.geteuid() == 0

  try:
    return bool(ctypes.windll.shell32.IsUserAnAdmin())
  except Exception:
    return False


def wait_enter() -> None:
  try:
    input('Нажми Enter для выхода...')
  except EOFError:
    pass


if __name__ == '__main__':
  main()
