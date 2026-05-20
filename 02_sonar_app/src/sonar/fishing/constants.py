from __future__ import annotations

from sonar.vision.geometry import Rect


PROCESS_NAME = "gta5.exe"

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


def fish_roi_for_resolution(width: int, height: int) -> Rect:
    return FISH_ROI_2K if resolution_name(width, height) == "2k" else FISH_ROI_FHD


def garbage_roi_for_resolution(width: int, height: int) -> Rect:
    return GARBAGE_ROI_2K if resolution_name(width, height) == "2k" else GARBAGE_ROI_FHD


def inventory_roi_for_resolution(width: int, height: int) -> Rect:
    return INVENTORY_ROI_2K if resolution_name(width, height) == "2k" else INVENTORY_ROI_FHD


def food_check_roi_for_resolution(width: int, height: int) -> Rect:
    return FOOD_CHECK_ROI_2K if resolution_name(width, height) == "2k" else FOOD_CHECK_ROI_FHD


def thirst_check_roi_for_resolution(width: int, height: int) -> Rect:
    return THIRST_CHECK_ROI_2K if resolution_name(width, height) == "2k" else THIRST_CHECK_ROI_FHD


def casting_roi_for_resolution(width: int, height: int) -> Rect:
    return CASTING_ROI_2K if resolution_name(width, height) == "2k" else CASTING_ROI_FHD


def hooking_rois_for_resolution(width: int, height: int) -> tuple[Rect, Rect]:
    if resolution_name(width, height) == "2k":
        return HOOKING_RED_ROI_2K, HOOKING_BUBLES_ROI_2K
    return HOOKING_RED_ROI_FHD, HOOKING_BUBLES_ROI_FHD
