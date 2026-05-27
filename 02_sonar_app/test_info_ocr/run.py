from __future__ import annotations

import csv
import json
import shutil
import sys
from dataclasses import asdict, dataclass
from pathlib import Path

import cv2

ROOT_DIR = Path(__file__).resolve().parents[1]
SRC_DIR = ROOT_DIR / 'src'
if str(SRC_DIR) not in sys.path:
    sys.path.insert(0, str(SRC_DIR))

from sonar.fishing.item_info import ItemInfo, ItemInfoDetector  # noqa: E402

IMAGE_EXTENSIONS = {'.jpg', '.jpeg', '.png', '.bmp', '.webp'}


@dataclass(frozen=True, slots=True)
class OcrRunResult:
    file: str
    slice_file: str
    found: bool
    rect: str
    title: str
    item_name: str
    weight: str
    satiety_change: str
    thirst_change: str
    condition_percent: str
    poison_chance: str
    effects: str
    parameter_modifications: str
    strength: str
    gender: str
    description: str
    text: str


def main() -> int:
    base_dir = Path(__file__).resolve().parent
    screenshots_dir = base_dir / 'screenshots'
    results_dir = base_dir / 'results'
    slices_dir = results_dir / 'slices'

    screenshots_dir.mkdir(parents=True, exist_ok=True)
    if results_dir.exists():
        shutil.rmtree(results_dir)
    slices_dir.mkdir(parents=True, exist_ok=True)

    detector = ItemInfoDetector()
    results: list[OcrRunResult] = []

    for screenshot_path in sorted(screenshots_dir.iterdir(), key=lambda path: path.name.lower()):
        if not screenshot_path.is_file() or screenshot_path.suffix.lower() not in IMAGE_EXTENSIONS:
            continue
        frame = cv2.imread(str(screenshot_path), cv2.IMREAD_COLOR)
        if frame is None:
            results.append(_not_found_result(screenshot_path, 'cv2.imread вернул None'))
            continue
        item_info = detector.detect(frame, read_text=True)
        if item_info is None:
            results.append(_not_found_result(screenshot_path, ''))
            continue
        slice_file = _save_slice(detector, frame, item_info, slices_dir, screenshot_path)
        results.append(_result_from_item_info(screenshot_path, slice_file, item_info))

    _write_csv(results_dir / 'results.csv', results)
    _write_json(results_dir / 'results.json', results)
    _write_text(results_dir / 'results.txt', results)
    print(f'Готово. Обработано файлов: {len(results)}')
    print(f'Результаты: {results_dir}')
    return 0


def _save_slice(
    detector: ItemInfoDetector,
    frame,
    item_info: ItemInfo,
    slices_dir: Path,
    screenshot_path: Path,
) -> str:
    crop = detector.crop(frame, item_info)
    if crop is None:
        return ''
    slice_name = f'{screenshot_path.stem}_item_info.png'
    slice_path = slices_dir / slice_name
    cv2.imwrite(str(slice_path), crop)
    return f'slices/{slice_name}'


def _result_from_item_info(screenshot_path: Path, slice_file: str, item_info: ItemInfo) -> OcrRunResult:
    rect = item_info.rect
    return OcrRunResult(
        file=screenshot_path.name,
        slice_file=slice_file,
        found=True,
        rect=f'{rect.x},{rect.y},{rect.width},{rect.height}',
        title=item_info.title,
        item_name=item_info.item_name,
        weight=item_info.weight,
        satiety_change=item_info.satiety_change,
        thirst_change=item_info.thirst_change,
        condition_percent=item_info.condition_percent,
        poison_chance=item_info.poison_chance,
        effects=' | '.join(item_info.effect_names),
        parameter_modifications=' | '.join(item_info.parameter_modifications),
        strength=item_info.strength,
        gender=item_info.gender,
        description=item_info.description,
        text=item_info.text,
    )


def _not_found_result(screenshot_path: Path, text: str) -> OcrRunResult:
    return OcrRunResult(
        file=screenshot_path.name,
        slice_file='',
        found=False,
        rect='',
        title='',
        item_name='',
        weight='',
        satiety_change='',
        thirst_change='',
        condition_percent='',
        poison_chance='',
        effects='',
        parameter_modifications='',
        strength='',
        gender='',
        description='',
        text=text,
    )


def _write_csv(path: Path, results: list[OcrRunResult]) -> None:
    with path.open('w', encoding='utf-8-sig', newline='') as file:
        writer = csv.DictWriter(file, fieldnames=list(asdict(results[0]).keys()) if results else list(OcrRunResult.__dataclass_fields__))
        writer.writeheader()
        for result in results:
            writer.writerow(asdict(result))


def _write_json(path: Path, results: list[OcrRunResult]) -> None:
    data = [asdict(result) for result in results]
    path.write_text(json.dumps(data, ensure_ascii=False, indent=2), encoding='utf-8')


def _write_text(path: Path, results: list[OcrRunResult]) -> None:
    blocks: list[str] = []
    for result in results:
        blocks.append(
            '\n'.join(
                (
                    f'Файл: {result.file}',
                    f'Найдено: {result.found}',
                    f'Кроп: {result.slice_file}',
                    f'Rect: {result.rect}',
                    f'Заголовок: {result.title}',
                    f'Вес: {result.weight}',
                    f'Сытость: {result.satiety_change}',
                    f'Жажда: {result.thirst_change}',
                    'Текст:',
                    result.text,
                )
            )
        )
    path.write_text('\n\n---\n\n'.join(blocks), encoding='utf-8')


if __name__ == '__main__':
    raise SystemExit(main())
