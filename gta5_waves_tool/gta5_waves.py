from __future__ import annotations

import ctypes
import json
import mmap
import os
import re
import shutil
from dataclasses import dataclass
from datetime import datetime
from pathlib import Path
from typing import Iterable

try:
  import winreg
except ImportError:
  winreg = None

APP_ID_GTAV = '271590'
SCRIPT_DIR = Path(__file__).resolve().parent
CONFIG_PATH = SCRIPT_DIR / 'config.json'


@dataclass(frozen=True)
class GameInstall:
  path: Path
  source: str


@dataclass(frozen=True)
class Modification:
  weather: str
  param: str
  start: int
  old: bytes
  target: bytes


def main() -> None:
  print('GTA V Waves Tool')
  print('================')
  print('Патчит оригинальный update/update.rpf. Закрой GTA V и OpenIV перед запуском.')
  print('')

  try:
    config = load_config()
    installs = find_game_installs(config)

    if len(installs) == 0:
      print('GTA V не найдена автоматически.')
      print('Добавь путь в config.json -> target.extra_game_paths и запусти снова.')
      wait_enter()
      return

    game = choose_game(installs)
    preset_name = choose_action()

    if preset_name is None:
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

    patch_rpf(rpf_path, preset_name, config)
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

  parameters = config.get('parameters')

  if not isinstance(parameters, list) or len(parameters) == 0:
    raise ValueError('В config.json должен быть непустой массив parameters.')

  values = config.get('values')

  if not isinstance(values, dict):
    raise ValueError('В config.json нет блока values.')

  for preset_name in ['default', 'no_waves']:
    preset = values.get(preset_name)

    if not isinstance(preset, dict):
      raise ValueError(f'В config.json нет values.{preset_name}.')

    for weather_name, weather_values in preset.items():
      if not isinstance(weather_values, dict):
        raise ValueError(f'Некорректный блок values.{preset_name}.{weather_name}.')

      for param in parameters:
        if param not in weather_values:
          raise ValueError(f'В config.json нет values.{preset_name}.{weather_name}.{param}.')

        value = str(weather_values[param])

        if not re.fullmatch(r'-?\d+\.\d+', value):
          raise ValueError(f'Некорректное значение {preset_name}.{weather_name}.{param}: {value}')

  default = values['default']
  no_waves = values['no_waves']

  for weather_name, weather_values in default.items():
    if weather_name not in no_waves:
      raise ValueError(f'В config.json нет values.no_waves.{weather_name}.')

    for param in parameters:
      default_value = str(weather_values[param])
      no_waves_value = str(no_waves[weather_name][param])

      if len(default_value) != len(no_waves_value):
        raise ValueError(
          f'Длины значений должны совпадать для безопасного патча: {weather_name}.{param}: '
          f'{default_value} -> {no_waves_value}'
        )


def find_game_installs(config: dict) -> list[GameInstall]:
  installs: list[GameInstall] = []
  installs.extend(find_steam_installs())
  installs.extend(find_epic_installs())
  installs.extend(find_rockstar_installs())
  installs.extend(find_extra_installs(config))

  unique: dict[str, GameInstall] = {}

  for install in installs:
    try:
      normalized = str(install.path.resolve()).lower()
    except OSError:
      normalized = str(install.path).lower()

    if normalized not in unique and is_gtav_dir(install.path):
      unique[normalized] = install

  return list(unique.values())


def find_steam_installs() -> list[GameInstall]:
  installs: list[GameInstall] = []

  for steam_root in get_steam_roots():
    for library in get_steam_libraries(steam_root):
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
    libraries.append(Path(match.group(1).replace('\\\\', '\\')))

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


def choose_action() -> str | None:
  print('Что сделать?')
  print('1. Удалить волны')
  print('2. Вернуть волны')
  print('3. Выход')

  while True:
    answer = input('Выбери действие: ').strip()

    if answer == '1':
      return 'no_waves'

    if answer == '2':
      return 'default'

    if answer == '3':
      return None

    print('Некорректный выбор.')


def get_rpf_path(game_path: Path, config: dict) -> Path:
  relative_path = config.get('target', {}).get('rpf_archive_relative_path', 'update/update.rpf')
  return game_path / Path(str(relative_path))


def patch_rpf(rpf_path: Path, preset_name: str, config: dict) -> None:
  if not config.get('target', {}).get('allow_binary_patch_rpf', True):
    raise RuntimeError('В config.json отключён allow_binary_patch_rpf.')

  print(f'Архив: {rpf_path}')
  print(f'Режим: {preset_name}')
  print('Ищу WeatherTypes внутри update.rpf...')

  modifications, found_weather = collect_modifications(rpf_path, preset_name, config)

  if len(found_weather) == 0:
    raise RuntimeError(
      'Не нашёл блок <WeatherTypes> внутри update.rpf.\n'
      'Вероятно, weather.xml хранится в RPF в сжатом/зашифрованном виде.\n'
      'Скрипт ничего не изменил. В этом случае нужна замена через OpenIV/OIV/RPF-инструмент.'
    )

  missing_weather = sorted(set(config['values'][preset_name]) - found_weather)

  if len(modifications) == 0:
    print('Изменений не требуется: значения уже совпадают с выбранным режимом.')
    print_missing_weather(missing_weather)
    return

  create_backup(rpf_path, config)
  apply_modifications(rpf_path, modifications)
  print_report(modifications, missing_weather)


def collect_modifications(rpf_path: Path, preset_name: str, config: dict) -> tuple[list[Modification], set[str]]:
  modifications: list[Modification] = []
  found_weather: set[str] = set()
  preset = config['values'][preset_name]
  parameters = [str(param) for param in config['parameters']]
  weather_start_token = b'<WeatherTypes>'
  weather_end_token = b'</WeatherTypes>'

  with rpf_path.open('rb') as file:
    with mmap.mmap(file.fileno(), 0, access=mmap.ACCESS_READ) as mapped:
      search_from = 0

      while True:
        section_start = mapped.find(weather_start_token, search_from)

        if section_start == -1:
          break

        section_end = mapped.find(weather_end_token, section_start)

        if section_end == -1:
          break

        section_end += len(weather_end_token)
        section = mapped[section_start:section_end]
        collect_section_modifications(section, section_start, preset, parameters, modifications, found_weather)
        search_from = section_end

  return modifications, found_weather


def collect_section_modifications(
  section: bytes,
  section_offset: int,
  preset: dict,
  parameters: list[str],
  modifications: list[Modification],
  found_weather: set[str],
) -> None:
  for item_match in re.finditer(rb'<Item>.*?</Item>', section, re.DOTALL):
    item = item_match.group(0)
    item_offset = section_offset + item_match.start()
    name_match = re.search(rb'<Name>\s*([^<]+?)\s*</Name>', item)

    if name_match is None:
      continue

    weather_name = name_match.group(1).decode('ascii', errors='ignore').strip()

    if weather_name not in preset:
      continue

    found_weather.add(weather_name)
    weather_values = preset[weather_name]

    for param in parameters:
      target_value = str(weather_values[param])
      target = target_value.encode('ascii')
      pattern = re.compile(rb'<' + re.escape(param.encode('ascii')) + rb'\s+value="([^"]+)"\s*/>')
      value_match = pattern.search(item)

      if value_match is None:
        continue

      current = value_match.group(1)

      if current == target:
        continue

      if len(current) != len(target):
        raise RuntimeError(
          f'Найдено значение другой длины: {weather_name}.{param}: '
          f'{current.decode("ascii", errors="replace")} -> {target_value}.\n'
          'Direct patch безопасен только при одинаковой длине значения.\n'
          'Скорее всего, файл уже меняли полной заменой через OpenIV. Вернуть такие значения чистым Python без RPF-инструмента нельзя.'
        )

      modifications.append(Modification(
        weather=weather_name,
        param=param,
        start=item_offset + value_match.start(1),
        old=current,
        target=target,
      ))


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


def apply_modifications(rpf_path: Path, modifications: list[Modification]) -> None:
  with rpf_path.open('r+b') as file:
    with mmap.mmap(file.fileno(), 0, access=mmap.ACCESS_WRITE) as mapped:
      for modification in modifications:
        mapped[modification.start:modification.start + len(modification.target)] = modification.target

      mapped.flush()


def print_report(modifications: list[Modification], missing_weather: list[str]) -> None:
  print('')
  print('Готово. Изменённые параметры:')
  counts: dict[tuple[str, str], int] = {}

  for modification in modifications:
    key = (modification.weather, modification.param)
    counts[key] = counts.get(key, 0) + 1

  weather_names = sorted({modification.weather for modification in modifications})

  for weather_name in weather_names:
    changed = [param for current_weather, param in counts if current_weather == weather_name]
    print(f'- {weather_name}: {", ".join(changed)}')

  print_missing_weather(missing_weather)


def print_missing_weather(missing_weather: list[str]) -> None:
  if len(missing_weather) == 0:
    return

  print('')
  print('В RPF не найдены погодные блоки из config.json:')

  for weather_name in missing_weather:
    print(f'- {weather_name}')

  print('Это не ошибка, если твой weather.xml уже был урезан модом.')


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
