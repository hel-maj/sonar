from __future__ import annotations

from sonar.security.runtime import decrypt_text_literal
from sonar.vision.geometry import Rect


PROCESS_NAME = decrypt_text_literal("gta_process_name")

REFERENCE_WIDTH_FHD = 1920
REFERENCE_HEIGHT_FHD = 1080
REFERENCE_WIDTH_2K = 2560
REFERENCE_HEIGHT_2K = 1440

FISH_ROI_FHD = Rect(778, 373, 368, 232)
FISH_ROI_2K = Rect(1037, 497, 492, 310)
FISH_MATCH_THRESHOLD = 0.63

GARBAGE_ROI_FHD = Rect(1077, 90, 538, 986)
GARBAGE_ROI_2K = Rect(1436, 99, 717, 1341)
GARBAGE_MATCH_THRESHOLD = 0.8
GARBAGE_TEMPLATE_FILES_FHD = {"corn": "corn.png", "bag": "bag.png", "pack": "pack.png"}
GARBAGE_TEMPLATE_FILES_2K = {"corn": "corn2k.png", "bag": "bag2k.png", "pack": "pack2k.png"}

INVENTORY_ROI_FHD = Rect(390, 70, 1130, 980)
INVENTORY_ROI_2K = Rect(520, 90, 1520, 1320)
FOOD_CHECK_ROI_FHD = Rect(1106, 482, 53, 22)
FOOD_CHECK_ROI_2K = Rect(1472, 641, 72, 35)
THIRST_CHECK_ROI_FHD = Rect(1106, 507, 60, 26)
THIRST_CHECK_ROI_2K = Rect(1472, 676, 80, 35)
MEAL_MATCH_THRESHOLD = 0.75
MEAL_MAX_CONSUME = 10
STORE_FISH_MATCH_THRESHOLD = 0.9

CASTING_ROI_FHD = Rect(690, 891, 539, 11)
CASTING_ROI_2K = Rect(913, 1186, 735, 20)
GREEN_HSV_LOW = (40, 80, 80)
GREEN_HSV_HIGH = (80, 255, 255)
MIN_GREEN_PIXELS = 15
CASTING_PAUSE_SECONDS = 0.1

HOOKING_RED_ROI_FHD = Rect(1370, 982, 134, 15)
HOOKING_RED_ROI_2K = Rect(1828, 1312, 171, 16)
HOOKING_BUBLES_ROI_FHD = Rect(1361, 861, 56, 55)
HOOKING_BUBLES_ROI_2K = Rect(1817, 1148, 71, 71)
HOOKING_MATCH_THRESHOLD = 0.85
HOOKING_PAUSE_SECONDS = 30.0

TAKE_FISH_COORDS = {"2k": (1134, 968), "fullhd": (864, 728)}
RELEASE_FISH_COORDS = {"2k": (1397, 972), "fullhd": (1056, 727)}

TRIGGER_ROIS_FHD = {
    "needs": Rect(4, 601, 679, 478),
    "needs_2k": Rect(5, 800, 905, 637),
    "events": Rect(300, 760, 1120, 320),
    "events_2k": Rect(400, 1010, 1500, 430),
    "stage": Rect(1535, 1022, 372, 44),
    "stage_2k": Rect(2052, 1365, 492, 55),
    "tension": Rect(1240, 760, 360, 320),
    "tension_2k": Rect(1660, 1010, 470, 420),
    "advantage": Rect(838, 1018, 70, 37),
    "advantage_2k": Rect(1121, 1359, 87, 46),
    "boat_human": Rect(694, 663, 527, 414),
    "boat_human_2k": Rect(925, 984, 708, 455),
    "ad": Rect(690, 885, 660, 185),
    "ad_2k": Rect(920, 1180, 880, 250),
}

BOT_DELAYS = {
    "short": 0.05,
    "key": 0.1,
    "click": 0.3,
    "half": 0.5,
    "normal": 1.0,
    "inventory": 2.0,
    "esc": 3.0,
    "wait": 5.0,
    "recover_pause": 10.0,
}


def resolution_name(width: int, height: int) -> str:
    return "2k" if width >= 2500 or height >= 1300 else "fullhd"


def reference_size_for_resolution(resolution: str) -> tuple[int, int]:
    if resolution == "2k":
        return REFERENCE_WIDTH_2K, REFERENCE_HEIGHT_2K
    return REFERENCE_WIDTH_FHD, REFERENCE_HEIGHT_FHD


def frame_scale(width: int, height: int, *, reference_resolution: str = "fullhd") -> float:
    reference_width, reference_height = reference_size_for_resolution(reference_resolution)
    return ((width / reference_width) + (height / reference_height)) / 2.0


def scale_rect(
    rect: Rect,
    width: int,
    height: int,
    *,
    reference_resolution: str = "fullhd",
) -> Rect:
    reference_width, reference_height = reference_size_for_resolution(reference_resolution)
    scale_x = width / reference_width
    scale_y = height / reference_height
    left = int(round(rect.x * scale_x))
    top = int(round(rect.y * scale_y))
    right = int(round(rect.right * scale_x))
    bottom = int(round(rect.bottom * scale_y))
    return Rect(left, top, max(1, right - left), max(1, bottom - top)).clamp(width, height)


def scale_rect_for_resolution(base_rect: Rect, high_res_rect: Rect, width: int, height: int) -> Rect:
    resolution = resolution_name(width, height)
    if resolution == "2k":
        return scale_rect(high_res_rect, width, height, reference_resolution="2k")
    return scale_rect(base_rect, width, height, reference_resolution="fullhd")


def template_scales_for_frame(
    width: int,
    height: int,
    template_resolution: str,
    *,
    factors: tuple[float, ...] = (0.82, 0.90, 0.96, 1.0, 1.04, 1.10, 1.20),
    extras: tuple[float, ...] = (1.0,),
) -> tuple[float, ...]:
    base = frame_scale(width, height, reference_resolution=template_resolution)
    values = {round(base * factor, 2) for factor in factors}
    values.update(round(value, 2) for value in extras)
    return tuple(sorted(value for value in values if 0.30 <= value <= 3.25))


def trigger_roi_for_resolution(roi_name: str, width: int, height: int) -> Rect | None:
    resolution = resolution_name(width, height)
    reference_name = f"{roi_name}_2k" if resolution == "2k" and f"{roi_name}_2k" in TRIGGER_ROIS_FHD else roi_name
    rect = TRIGGER_ROIS_FHD.get(reference_name)
    if rect is None:
        return None
    reference_resolution = "2k" if reference_name.endswith("_2k") else "fullhd"
    return scale_rect(rect, width, height, reference_resolution=reference_resolution)


def fish_roi_for_resolution(width: int, height: int) -> Rect:
    return scale_rect_for_resolution(FISH_ROI_FHD, FISH_ROI_2K, width, height)


def garbage_roi_for_resolution(width: int, height: int) -> Rect:
    return scale_rect_for_resolution(GARBAGE_ROI_FHD, GARBAGE_ROI_2K, width, height)


def inventory_roi_for_resolution(width: int, height: int) -> Rect:
    return scale_rect_for_resolution(INVENTORY_ROI_FHD, INVENTORY_ROI_2K, width, height)


def food_check_roi_for_resolution(width: int, height: int) -> Rect:
    return scale_rect_for_resolution(FOOD_CHECK_ROI_FHD, FOOD_CHECK_ROI_2K, width, height)


def thirst_check_roi_for_resolution(width: int, height: int) -> Rect:
    return scale_rect_for_resolution(THIRST_CHECK_ROI_FHD, THIRST_CHECK_ROI_2K, width, height)


def casting_roi_for_resolution(width: int, height: int) -> Rect:
    return scale_rect_for_resolution(CASTING_ROI_FHD, CASTING_ROI_2K, width, height)


def hooking_rois_for_resolution(width: int, height: int) -> tuple[Rect, Rect]:
    return (
        scale_rect_for_resolution(HOOKING_RED_ROI_FHD, HOOKING_RED_ROI_2K, width, height),
        scale_rect_for_resolution(HOOKING_BUBLES_ROI_FHD, HOOKING_BUBLES_ROI_2K, width, height),
    )
