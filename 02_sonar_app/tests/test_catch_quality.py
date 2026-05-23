from sonar.fishing.catch_quality import CATCH_SIZE_COLORS_BY_KEY, CATCH_SIZE_TYPES, normalize_catch_size


def test_catch_size_types_are_explicit_and_stable():
    assert [item.label for item in CATCH_SIZE_TYPES] == [
        "Скромный улов",
        "Хороший улов",
        "Рекордный улов",
        "Трофейный улов",
    ]


def test_normalize_catch_size_reads_known_ocr_fragments():
    assert normalize_catch_size("скромнЫЙ") == "Скромный улов"
    assert normalize_catch_size("Хороший улов") == "Хороший улов"
    assert normalize_catch_size("Рекорд") == "Рекордный улов"
    assert normalize_catch_size("Трофейная") == "Трофейный улов"


def test_catch_size_colors_are_bound_to_stable_keys():
    assert CATCH_SIZE_COLORS_BY_KEY == {
        "modest": "#242424",
        "good": "#275277",
        "record": "#8C1D2C",
        "trophy": "#1D8667",
    }
