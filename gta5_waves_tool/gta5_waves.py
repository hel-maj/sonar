from __future__ import annotations

import json
import os
import re
import shutil
import subprocess
from dataclasses import dataclass
from datetime import datetime
from pathlib import Path
from uuid import uuid4
from zipfile import ZIP_DEFLATED, ZipFile
from xml.sax.saxutils import escape

try:
  import winreg
except ImportError:
  winreg = None

APP_ID_GTAV = '271590'
SCRIPT_DIR = Path(__file__).resolve().parent
CONFIG_PATH = SCRIPT_DIR / 'config.json'
STATE_PATH = SCRIPT_DIR / 'state.json'


@dataclass(frozen=True)
class GameInstall:
  path: Path
  source: str


@dataclass(frozen=True)
class RpfTarget:
  label: str
  archive_path: str
  original_relative_path: Path
  mods_relative_path: Path
  required: bool

  @property
  def slug(self) -> str:
    return re.sub(r'[^a-zA-Z0-9._-]+', '_', self.label).strip('_') or 'rpf'


def main() -> None:
  print('GTA V Waves Portable No-Waves')
  print('=============================')
  print('Обрабатывает update/update.rpf, common.rpf, mods/update/update.rpf и mods/common.rpf.')
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
    action = choose_action()

    if action is None:
      print('Выход.')
      return

    targets = get_targets(game.path)

    if config.get('installer', {}).get('auto_install', True):
      process_targets(action, game.path, config, targets)
    else:
      print('Автоустановка отключена в config.json -> installer.auto_install.')
      print('Создаю .oiv-пакеты для ручной установки.')

      for target in targets:
        if (game.path / target.original_relative_path).exists() or (game.path / target.mods_relative_path).exists():
          oiv_path = create_oiv(action, config, target)
          print(f'Создан пакет для {target.label}: {oiv_path}')
  except PermissionError:
    print('Нет доступа к RPF. Запусти run.bat от имени администратора и закрой GTA/OpenIV.')
  except RuntimeError as error:
    print(str(error))
  except Exception as error:
    print(f'Неожиданная ошибка: {error}')

  wait_enter()


def load_config() -> dict:
  if not CONFIG_PATH.exists():
    raise RuntimeError(f'Не найден config.json: {CONFIG_PATH}')

  with CONFIG_PATH.open('r', encoding='utf-8') as file:
    return json.load(file)


def choose_action() -> str | None:
  print('Что сделать?')
  print('1. Удалить волны')
  print('2. Вернуть волны')
  print('3. Выход')

  while True:
    value = input('Выбери действие: ').strip()

    if value == '1':
      return 'no_waves'

    if value == '2':
      return 'default'

    if value == '3':
      return None

    print('Введите 1, 2 или 3.')


def get_targets(game_path: Path) -> list[RpfTarget]:
  return [
    RpfTarget(
      label='update/update.rpf',
      archive_path='update\\update.rpf',
      original_relative_path=Path('update') / 'update.rpf',
      mods_relative_path=Path('mods') / 'update' / 'update.rpf',
      required=True,
    ),
    RpfTarget(
      label='common.rpf',
      archive_path='common.rpf',
      original_relative_path=Path('common.rpf'),
      mods_relative_path=Path('mods') / 'common.rpf',
      required=False,
    ),
  ]


def process_targets(action: str, game_path: Path, config: dict, targets: list[RpfTarget]) -> None:
  print('')
  print('Целевые архивы:')

  for target in targets:
    original_path = game_path / target.original_relative_path
    mods_path = game_path / target.mods_relative_path
    print(f'- {target.label}: original={"есть" if original_path.exists() else "нет"}, mods={"есть" if mods_path.exists() else "нет"}')

  print('')

  for target in targets:
    original_path = game_path / target.original_relative_path
    mods_path = game_path / target.mods_relative_path
    mods_existed_before = mods_path.exists()

    if not original_path.exists():
      if target.required:
        raise RuntimeError(f'Не найден обязательный архив: {original_path}')

      print(f'{target.label}: оригинальный архив не найден - оригинал пропускаю.')
    else:
      if config.get('target', {}).get('backup_whole_update_rpf', True):
        backup_named_rpf(original_path, game_path, config, f'{target.slug}_before_{action}')

      oiv_path = create_oiv(action, config, target)
      apply_oiv_to_original_target(oiv_path, game_path, config, target)

    if action == 'no_waves':
      if mods_existed_before:
        apply_no_waves_to_existing_mods(game_path, config, target)
      elif should_create_missing_mods_target(config, target):
        create_no_waves_missing_mods(game_path, config, target)
      else:
        clear_mods_no_waves_state(game_path, target)
        print(f'{target.label}: {target.mods_relative_path.as_posix()} не было до отключения волн - mods не создаю и не трогаю.')
    else:
      restore_mods_if_we_changed_it(game_path, config, target)

  print('')
  print('Готово.')


def create_oiv(action: str, config: dict, target: RpfTarget, create_archive_if_missing: bool = False) -> Path:
  generated_dir = SCRIPT_DIR / config.get('target', {}).get('generated_dir_name', 'generated')
  generated_dir.mkdir(exist_ok=True)

  package_name = f'GTA V {"No Waves" if action == "no_waves" else "Restore Waves"} {target.label}'
  oiv_name = f'gta5_waves_{action}_{target.slug}.oiv'
  oiv_path = generated_dir / oiv_name
  xml_path = get_weather_xml_path_in_archive(target)
  operations_xml, op_count = create_xml_patch_operations(action, config)
  create_archive_value = 'True' if create_archive_if_missing else 'False'

  print(f'{target.label}: XML-patch операций для weather.xml: {op_count}')

  assembly_xml = f'''<?xml version="1.0" encoding="UTF-8"?>
<package version="2.2" id="{{{uuid4()}}}" target="Five">
  <metadata>
    <name>{package_name}</name>
    <version>
      <major>1</major>
      <minor>0</minor>
      <tag>Release</tag>
    </version>
    <author>
      <displayName>Local</displayName>
    </author>
    <description><![CDATA[Generated XML patch changes only configured wave values in the current installed weather.xml.]]></description>
  </metadata>
  <gameversion>legacy</gameversion>
  <colors>
    <headerBackground useBlackTextColor="False">$FF272727</headerBackground>
    <iconBackground>$FF2E2E2E</iconBackground>
  </colors>
  <content>
    <archive path="{target.archive_path}" createIfNotExist="{create_archive_value}" type="RPF7">
      <xml path="{xml_path}">
{operations_xml}
      </xml>
    </archive>
  </content>
</package>
'''

  with ZipFile(oiv_path, 'w', ZIP_DEFLATED) as archive:
    archive.writestr('assembly.xml', assembly_xml)

  return oiv_path


def get_weather_xml_path_in_archive(target: RpfTarget) -> str:
  if target.label == 'update/update.rpf':
    return 'common/data/levels/gta5/weather.xml'

  return 'data/levels/gta5/weather.xml'


def create_xml_patch_operations(preset_name: str, config: dict) -> tuple[str, int]:
  parameters = list(config.get('parameters', []))
  values_by_weather = config.get('values', {}).get(preset_name)

  if not parameters:
    raise RuntimeError('В config.json не задан parameters.')

  if values_by_weather is None:
    raise RuntimeError(f'В config.json не найден values.{preset_name}.')

  operations: list[str] = []

  if preset_name == 'no_waves' and isinstance(values_by_weather.get('*'), dict):
    max_weather_items = int(config.get('target', {}).get('max_weather_items_for_global_patch', 80))
    global_values = values_by_weather['*']

    for item_index in range(1, max_weather_items + 1):
      for param_name in parameters:
        value = global_values.get(param_name)

        if value is None:
          continue

        operations.append(create_xml_replace_operation(
          f'/CContentsOfWeatherXmlFile/WeatherTypes/Item[{item_index}]/{param_name}',
          param_name,
          str(value),
        ))
  else:
    weather_names = get_weather_names_for_default_patch(config, values_by_weather)

    for weather_name in weather_names:
      for param_name in parameters:
        value = get_value_for_weather(values_by_weather, weather_name, param_name)

        if value is None:
          continue

        operations.append(create_xml_replace_operation(
          f'/CContentsOfWeatherXmlFile/WeatherTypes/Item[Name="{escape_xpath_literal(weather_name)}"]/{param_name}',
          param_name,
          str(value),
        ))

  return '\n'.join(operations), len(operations)


def get_weather_names_for_default_patch(config: dict, values_by_weather: dict) -> list[str]:
  names: list[str] = []

  for name in config.get('weather_names', []):
    if isinstance(name, str) and name not in names:
      names.append(name)

  for name in values_by_weather.keys():
    if isinstance(name, str) and name != '*' and name not in names:
      names.append(name)

  return names


def create_xml_replace_operation(xpath: str, param_name: str, value: str) -> str:
  return f'        <replace xpath={quote_xml_attr(xpath)}>\n          <{param_name} value={quote_xml_attr(value)} />\n        </replace>'


def quote_xml_attr(value: str) -> str:
  return '"' + escape(value, {'"': '&quot;'}) + '"'


def escape_xpath_literal(value: str) -> str:
  return value.replace('"', '&quot;')


def read_base_weather(config: dict) -> str:
  relative_path = config.get('payload', {}).get('base_weather_relative_path', 'payload/base_weather.xml')
  path = SCRIPT_DIR / Path(relative_path)

  if not path.exists():
    raise RuntimeError(f'Не найден базовый weather.xml: {path}')

  return path.read_text(encoding='utf-8')


def create_modified_weather(preset_name: str, config: dict) -> tuple[str, int]:
  text = read_base_weather(config)
  parameters = list(config.get('parameters', []))
  values_by_weather = config.get('values', {}).get(preset_name)

  if not parameters:
    raise RuntimeError('В config.json не задан parameters.')

  if values_by_weather is None:
    raise RuntimeError(f'В config.json не найден values.{preset_name}.')

  weather_types_match = re.search(r'(<WeatherTypes>)(.*?)(</WeatherTypes>)', text, flags=re.DOTALL)

  if weather_types_match is None:
    raise RuntimeError('В payload/base_weather.xml не найден блок <WeatherTypes>.')

  body = weather_types_match.group(2)
  changed_count = 0

  def replace_item(match: re.Match[str]) -> str:
    nonlocal changed_count
    item = match.group(0)
    name_match = re.search(r'<Name>\s*([^<]+?)\s*</Name>', item)

    if name_match is None:
      return item

    weather_name = name_match.group(1).strip()

    for param_name in parameters:
      value = get_value_for_weather(values_by_weather, weather_name, param_name)

      if value is None:
        continue

      pattern = rf'(<{re.escape(param_name)}\b[^>]*\bvalue=")([^"]*)("[^>]*/?>)'

      def replace_param(param_match: re.Match[str]) -> str:
        nonlocal changed_count
        old_value = param_match.group(2)

        if old_value != value:
          changed_count += 1

        return f'{param_match.group(1)}{value}{param_match.group(3)}'

      item = re.sub(pattern, replace_param, item, count=1)

    return item

  new_body = re.sub(r'<Item>.*?</Item>', replace_item, body, flags=re.DOTALL)
  new_text = text[:weather_types_match.start(2)] + new_body + text[weather_types_match.end(2):]
  return new_text, changed_count


def get_value_for_weather(values_by_weather: dict, weather_name: str, param_name: str) -> str | None:
  weather_values = values_by_weather.get(weather_name)

  if isinstance(weather_values, dict) and param_name in weather_values:
    return str(weather_values[param_name])

  global_values = values_by_weather.get('*')

  if isinstance(global_values, dict) and param_name in global_values:
    return str(global_values[param_name])

  return None


def apply_oiv_to_original_target(oiv_path: Path, game_path: Path, config: dict, target: RpfTarget) -> None:
  original_rpf = game_path / target.original_relative_path
  mods_rpf = game_path / target.mods_relative_path
  saved_mods_rpf: Path | None = None
  created_temp_mods_rpf = False

  print('')
  print(f'{target.label}: CodeWalker ставит top-level архив во временный mods-путь.')
  print(f'{target.label}: применяю пакет к оригинальному архиву через временный {target.mods_relative_path.as_posix()}.')

  try:
    if mods_rpf.exists():
      timestamp = datetime.now().strftime('%Y%m%d_%H%M%S')
      saved_mods_rpf = mods_rpf.with_name(f'{mods_rpf.name}.gta5_waves_saved_{timestamp}.bak')
      print(f'Найден существующий {target.mods_relative_path.as_posix()}, временно убираю его: {saved_mods_rpf.name}')
      shutil.move(str(mods_rpf), str(saved_mods_rpf))

    result = run_codewalker_installer(oiv_path, game_path, config)

    if result.returncode != 0:
      print(f'Установщик завершился с кодом: {result.returncode}')
      print('Команда, которую можно запустить вручную:')
      print(format_command(result.args))
      raise RuntimeError('Автоустановка не завершилась успешно.')

    if not mods_rpf.exists():
      raise RuntimeError(f'Установщик не создал временный {target.mods_relative_path.as_posix()}. Нечего копировать в оригинал.')

    created_temp_mods_rpf = True
    print(f'Копирую временно изменённый {target.mods_relative_path.as_posix()} в оригинальный {target.original_relative_path.as_posix()}...')
    shutil.copy2(mods_rpf, original_rpf)
    print(f'Оригинальный архив обновлён: {original_rpf}')
  finally:
    if created_temp_mods_rpf and mods_rpf.exists():
      try:
        mods_rpf.unlink()
        cleanup_empty_dirs([mods_rpf.parent])
        print(f'Временный {target.mods_relative_path.as_posix()} удалён.')
      except OSError as error:
        print(f'Не смог удалить временный {target.mods_relative_path.as_posix()}: {error}')

    if saved_mods_rpf is not None and saved_mods_rpf.exists():
      try:
        mods_rpf.parent.mkdir(parents=True, exist_ok=True)
        shutil.move(str(saved_mods_rpf), str(mods_rpf))
        print(f'Старый {target.mods_relative_path.as_posix()} возвращён на место.')
      except OSError as error:
        print(f'Не смог вернуть старый {target.mods_relative_path.as_posix()}: {error}')


def should_create_missing_mods_target(config: dict, target: RpfTarget) -> bool:
  target_config = config.get('target', {})

  if target.label == 'common.rpf':
    return bool(target_config.get('create_missing_mods_common_rpf', True))

  if target.label == 'update/update.rpf':
    return bool(target_config.get('create_missing_mods_update_rpf', True))

  return False


def create_no_waves_missing_mods(game_path: Path, config: dict, target: RpfTarget) -> None:
  mods_rpf = game_path / target.mods_relative_path

  if mods_rpf.exists():
    apply_no_waves_to_existing_mods(game_path, config, target)
    return

  print('')
  print(f'{target.label}: {target.mods_relative_path.as_posix()} не существует.')
  print('Создаю mods-архив как копию текущего игрового архива и применяю XML-patch только к волновым параметрам.')
  print('payload/base_weather.xml остаётся ванильным fallback/reference и не используется для перезаписи редакса.')
  oiv_path = create_oiv('no_waves', config, target, create_archive_if_missing=True)
  result = run_codewalker_installer(oiv_path, game_path, config)

  if result.returncode != 0:
    print(f'Установщик завершился с кодом: {result.returncode}')
    print('Команда, которую можно запустить вручную:')
    print(format_command(result.args))
    raise RuntimeError(f'Не удалось создать {target.mods_relative_path.as_posix()}.')

  if not mods_rpf.exists():
    raise RuntimeError(f'Установщик не создал {target.mods_relative_path.as_posix()}.')

  remember_mods_no_waves(game_path, target, mods_rpf, None, created_by_script=True)
  print(f'Создан {target.mods_relative_path.as_posix()} с отключёнными волнами.')


def apply_no_waves_to_existing_mods(game_path: Path, config: dict, target: RpfTarget) -> None:
  mods_rpf = game_path / target.mods_relative_path

  if not mods_rpf.exists():
    print(f'{target.mods_relative_path.as_posix()} исчез до применения волн - пропускаю mods.')
    return

  backup_path = backup_named_rpf(mods_rpf, game_path, config, f'{target.slug}_mods_before_no_waves')
  print(f'Запомнил текущее состояние {target.mods_relative_path.as_posix()}: {backup_path}')
  oiv_path = create_oiv('no_waves', config, target)
  apply_oiv_to_existing_mods_rpf(oiv_path, game_path, config, target)
  remember_mods_no_waves(game_path, target, mods_rpf, backup_path, created_by_script=False)


def apply_oiv_to_existing_mods_rpf(oiv_path: Path, game_path: Path, config: dict, target: RpfTarget) -> None:
  mods_rpf = game_path / target.mods_relative_path

  if not mods_rpf.exists():
    print(f'{target.mods_relative_path.as_posix()} не найден - пропускаю.')
    return

  print('')
  print(f'Применяю такие же значения к существующему {target.mods_relative_path.as_posix()}...')
  result = run_codewalker_installer(oiv_path, game_path, config)

  if result.returncode != 0:
    print(f'Установщик завершился с кодом: {result.returncode}')
    print('Команда, которую можно запустить вручную:')
    print(format_command(result.args))
    raise RuntimeError(f'Не удалось применить изменения к {target.mods_relative_path.as_posix()}.')

  print(f'{target.mods_relative_path.as_posix()} обновлён.')


def restore_mods_if_we_changed_it(game_path: Path, config: dict, target: RpfTarget) -> None:
  mods_rpf = game_path / target.mods_relative_path
  state = load_state()
  game_state = state.get(get_game_state_key(game_path), {})
  mods_states = game_state.get('mods_no_waves')
  mods_state = mods_states.get(target.slug) if isinstance(mods_states, dict) else None

  if not isinstance(mods_state, dict) or not mods_state.get('applied'):
    print(f'Для {target.mods_relative_path.as_posix()} нет записи, что no-waves применялся этим скриптом - mods не трогаю.')
    return

  if not mods_rpf.exists():
    print(f'{target.mods_relative_path.as_posix()} был изменён этим скриптом, но сейчас файла нет - не пересоздаю его.')
    clear_mods_no_waves_state(game_path, target)
    return

  current_snapshot = get_file_snapshot(mods_rpf)
  after_snapshot = mods_state.get('after_snapshot')
  created_by_script = bool(mods_state.get('created_by_script'))

  if created_by_script:
    if snapshots_equal(current_snapshot, after_snapshot):
      print(f'{target.mods_relative_path.as_posix()} был создан этим скриптом и после этого не менялся - удаляю его при откате.')
      mods_rpf.unlink()
      cleanup_empty_dirs([mods_rpf.parent])
      clear_mods_no_waves_state(game_path, target)
      return

    print(f'{target.mods_relative_path.as_posix()} был создан этим скриптом, но потом менялся.')
    print('Не удаляю файл, чтобы не потерять последующие изменения. Применяю preset default только к текущему mods-файлу.')
    oiv_path = create_oiv('default', config, target)
    apply_oiv_to_existing_mods_rpf(oiv_path, game_path, config, target)
    clear_mods_no_waves_state(game_path, target)
    return

  backup_path = get_state_path(mods_state.get('backup_path'))

  if backup_path is not None and backup_path.exists():
    if snapshots_equal(current_snapshot, after_snapshot):
      print(f'Возвращаю {target.mods_relative_path.as_posix()} из backup, чтобы вернуть ровно то, что было до no-waves.')
      shutil.copy2(backup_path, mods_rpf)
      clear_mods_no_waves_state(game_path, target)
      return

    print(f'{target.mods_relative_path.as_posix()} менялся после отключения волн.')
    print('Чтобы не затереть чужие последующие изменения, не копирую backup целиком.')
    print('Вместо этого применяю preset default только к текущему mods-файлу.')
  else:
    print(f'Backup старого {target.mods_relative_path.as_posix()} не найден.')
    print('Применяю preset default к текущему mods-файлу.')

  oiv_path = create_oiv('default', config, target)
  apply_oiv_to_existing_mods_rpf(oiv_path, game_path, config, target)
  clear_mods_no_waves_state(game_path, target)


def backup_named_rpf(rpf_path: Path, game_path: Path, config: dict, suffix: str) -> Path:
  backup_dir = SCRIPT_DIR / config.get('target', {}).get('backup_dir_name', 'backups')
  backup_dir.mkdir(exist_ok=True)
  timestamp = datetime.now().strftime('%Y%m%d_%H%M%S')
  safe_game_name = re.sub(r'[^a-zA-Z0-9._-]+', '_', game_path.name).strip('_') or 'GTAV'
  backup_path = backup_dir / f'{safe_game_name}_{suffix}_{timestamp}.rpf'
  print(f'Делаю бэкап {rpf_path.name}: {backup_path}')
  shutil.copy2(rpf_path, backup_path)
  return backup_path


def remember_mods_no_waves(game_path: Path, target: RpfTarget, mods_rpf: Path, backup_path: Path | None, created_by_script: bool) -> None:
  if not mods_rpf.exists():
    return

  state = load_state()
  game_key = get_game_state_key(game_path)
  game_state = state.setdefault(game_key, {})
  mods_states = game_state.setdefault('mods_no_waves', {})
  mods_state = {
    'applied': True,
    'target': target.label,
    'rpf_path': str(mods_rpf),
    'created_by_script': created_by_script,
    'after_snapshot': get_file_snapshot(mods_rpf),
    'updated_at': datetime.now().isoformat(timespec='seconds'),
  }

  if backup_path is not None:
    mods_state['backup_path'] = make_state_path(backup_path)

  mods_states[target.slug] = mods_state
  save_state(state)


def clear_mods_no_waves_state(game_path: Path, target: RpfTarget) -> None:
  state = load_state()
  game_key = get_game_state_key(game_path)
  game_state = state.get(game_key)

  if isinstance(game_state, dict):
    mods_states = game_state.get('mods_no_waves')

    if isinstance(mods_states, dict) and target.slug in mods_states:
      del mods_states[target.slug]
      save_state(state)


def load_state() -> dict:
  if not STATE_PATH.exists():
    return {}

  try:
    with STATE_PATH.open('r', encoding='utf-8') as file:
      data = json.load(file)

    if isinstance(data, dict):
      return data
  except (OSError, json.JSONDecodeError):
    return {}

  return {}


def save_state(state: dict) -> None:
  with STATE_PATH.open('w', encoding='utf-8', newline='') as file:
    json.dump(state, file, ensure_ascii=False, indent=2)
    file.write('\n')


def get_game_state_key(game_path: Path) -> str:
  try:
    return str(game_path.resolve()).lower()
  except OSError:
    return str(game_path).lower()


def get_file_snapshot(path: Path) -> dict:
  stat = path.stat()
  return {
    'size': stat.st_size,
    'mtime_ns': stat.st_mtime_ns,
  }


def snapshots_equal(left: dict | None, right: object) -> bool:
  if not isinstance(left, dict) or not isinstance(right, dict):
    return False

  return left.get('size') == right.get('size') and left.get('mtime_ns') == right.get('mtime_ns')


def make_state_path(path: Path) -> str:
  try:
    return str(path.relative_to(SCRIPT_DIR))
  except ValueError:
    return str(path)


def get_state_path(value: object) -> Path | None:
  if not isinstance(value, str) or not value.strip():
    return None

  path = Path(value)

  if path.is_absolute():
    return path

  return SCRIPT_DIR / path


def run_codewalker_installer(oiv_path: Path, game_path: Path, config: dict) -> subprocess.CompletedProcess:
  installer_config = config.get('installer', {})
  installer_relative_path = installer_config.get('executable_relative_path', 'tools/CodeWalker.OIVInstaller.exe')
  installer_path = SCRIPT_DIR / Path(installer_relative_path)

  if not installer_path.exists():
    raise RuntimeError(f'Не найден installer: {installer_path}')

  args = [
    str(installer_path),
    '--install', str(oiv_path),
    '--game', str(game_path),
  ]

  if installer_config.get('force_game_version', True):
    args.append('--force')

  if installer_config.get('skip_installer_backup', False):
    args.append('--skip_backup')

  for arg in installer_config.get('extra_args', []):
    args.append(str(arg))

  print('')
  print('Запускаю bundled CodeWalker.OIVInstaller.exe...')
  print(f'Папка GTA V: {game_path}')
  print('')

  return subprocess.run(args, cwd=str(SCRIPT_DIR))

def choose_game(installs: list[GameInstall]) -> GameInstall:
  print('Найденные установки GTA V:')

  for index, install in enumerate(installs, start=1):
    print(f'{index}. {install.path} ({install.source})')

  print('')

  if len(installs) == 1:
    print(f'Выбрана единственная найденная установка: {installs[0].path}')
    print('')
    return installs[0]

  while True:
    value = input('Выбери установку: ').strip()

    if not value.isdigit():
      print('Введите номер из списка.')
      continue

    index = int(value)

    if 1 <= index <= len(installs):
      print('')
      return installs[index - 1]

    print('Нет такого номера.')


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


def is_gtav_dir(path: Path) -> bool:
  return (path / 'update' / 'update.rpf').exists() and (
    (path / 'GTA5.exe').exists()
    or (path / 'GTA5_Enhanced.exe').exists()
    or (path / 'eboot.bin').exists()
  )


def find_extra_installs(config: dict) -> list[GameInstall]:
  installs: list[GameInstall] = []

  for raw_path in config.get('target', {}).get('extra_game_paths', []):
    path = Path(raw_path)

    if is_gtav_dir(path):
      installs.append(GameInstall(path, 'config extra_game_paths'))

  return installs


def find_steam_installs() -> list[GameInstall]:
  installs: list[GameInstall] = []

  for steam_root in get_steam_roots():
    for library in get_steam_libraries(steam_root):
      manifest_path = library / 'steamapps' / f'appmanifest_{APP_ID_GTAV}.acf'
      install_dir = parse_steam_install_dir(manifest_path)

      if install_dir:
        installs.append(GameInstall(library / 'steamapps' / 'common' / install_dir, 'Steam manifest'))
      else:
        installs.append(GameInstall(library / 'steamapps' / 'common' / 'Grand Theft Auto V', 'Steam common'))

  return installs


def get_steam_roots() -> list[Path]:
  roots: list[Path] = []

  for key_root, key_path in get_steam_registry_keys():
    steam_path = read_registry_value(key_root, key_path, 'SteamPath')

    if steam_path is None:
      steam_path = read_registry_value(key_root, key_path, 'InstallPath')

    if steam_path:
      roots.append(Path(steam_path.replace('/', '\\')))

  for env_name in ['ProgramFiles(x86)', 'ProgramFiles']:
    env_path = os.environ.get(env_name)

    if env_path:
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

    for match in re.finditer(r'"path"\s+"([^\"]+)"', text):
      libraries.append(Path(match.group(1).replace('\\\\', '\\')))
  except OSError:
    return dedupe_paths(libraries)

  return dedupe_paths(libraries)


def parse_steam_install_dir(manifest_path: Path) -> str | None:
  if not manifest_path.exists():
    return None

  try:
    text = manifest_path.read_text(encoding='utf-8', errors='ignore')
    match = re.search(r'"installdir"\s+"([^\"]+)"', text)

    if match is None:
      return None

    return match.group(1)
  except OSError:
    return None


def find_epic_installs() -> list[GameInstall]:
  manifests_dir = Path(os.environ.get('PROGRAMDATA', r'C:\ProgramData')) / 'Epic' / 'EpicGamesLauncher' / 'Data' / 'Manifests'
  installs: list[GameInstall] = []

  if not manifests_dir.exists():
    return installs

  for manifest_path in manifests_dir.glob('*.item'):
    try:
      data = json.loads(manifest_path.read_text(encoding='utf-8', errors='ignore'))
      app_name = str(data.get('AppName', '')).lower()
      display_name = str(data.get('DisplayName', '')).lower()
      install_location = data.get('InstallLocation')

      if install_location and ('gta' in app_name or 'grand theft auto v' in display_name):
        installs.append(GameInstall(Path(install_location), 'Epic manifest'))
    except (OSError, json.JSONDecodeError):
      continue

  return installs


def find_rockstar_installs() -> list[GameInstall]:
  installs: list[GameInstall] = []

  for key_root, key_path in get_rockstar_registry_keys():
    for value_name in ['InstallFolder', 'InstallDir', 'InstallPath']:
      value = read_registry_value(key_root, key_path, value_name)

      if value:
        installs.append(GameInstall(Path(value), 'Rockstar registry'))

  common_paths = [
    Path(os.environ.get('ProgramFiles', r'C:\Program Files')) / 'Rockstar Games' / 'Grand Theft Auto V',
    Path(os.environ.get('ProgramFiles(x86)', r'C:\Program Files (x86)')) / 'Rockstar Games' / 'Grand Theft Auto V',
  ]

  for path in common_paths:
    installs.append(GameInstall(path, 'Rockstar common path'))

  return installs


def get_rockstar_registry_keys() -> list[tuple[object, str]]:
  if winreg is None:
    return []

  return [
    (winreg.HKEY_LOCAL_MACHINE, r'SOFTWARE\WOW6432Node\Rockstar Games\Grand Theft Auto V'),
    (winreg.HKEY_LOCAL_MACHINE, r'SOFTWARE\Rockstar Games\Grand Theft Auto V'),
    (winreg.HKEY_CURRENT_USER, r'Software\Rockstar Games\Grand Theft Auto V'),
  ]


def read_registry_value(root: object, key_path: str, value_name: str) -> str | None:
  if winreg is None:
    return None

  try:
    with winreg.OpenKey(root, key_path) as key:
      value, _ = winreg.QueryValueEx(key, value_name)

      if isinstance(value, str) and value.strip():
        return value.strip()
  except OSError:
    return None

  return None


def dedupe_paths(paths: list[Path]) -> list[Path]:
  unique: dict[str, Path] = {}

  for path in paths:
    normalized = str(path).lower()

    if normalized not in unique:
      unique[normalized] = path

  return list(unique.values())


def cleanup_empty_dirs(paths: list[Path]) -> None:
  for path in paths:
    try:
      path.rmdir()
    except OSError:
      pass


def format_command(args: object) -> str:
  if not isinstance(args, list):
    return str(args)

  return ' '.join(f'"{arg}"' if ' ' in str(arg) else str(arg) for arg in args)


def wait_enter() -> None:
  try:
    input('Нажми Enter для выхода...')
  except EOFError:
    pass


if __name__ == '__main__':
  main()
