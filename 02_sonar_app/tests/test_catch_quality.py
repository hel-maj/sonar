from sonar.fishing.catch_quality import CATCH_SIZE_COLORS_BY_KEY, CATCH_SIZE_TYPES, normalize_catch_size


MODEST = "\u0421\u043a\u0440\u043e\u043c\u043d\u044b\u0439 \u0443\u043b\u043e\u0432"
GOOD = "\u0425\u043e\u0440\u043e\u0448\u0438\u0439 \u0443\u043b\u043e\u0432"
RECORD = "\u0420\u0435\u043a\u043e\u0440\u0434\u043d\u044b\u0439 \u0443\u043b\u043e\u0432"
TROPHY = "\u0422\u0440\u043e\u0444\u0435\u0439\u043d\u0430\u044f"


def test_catch_size_types_are_explicit_and_stable():
    assert [item.label for item in CATCH_SIZE_TYPES] == [
        MODEST,
        GOOD,
        RECORD,
        TROPHY,
    ]


def test_normalize_catch_size_reads_known_ocr_fragments():
    assert normalize_catch_size("\u0441\u043a\u0440\u043e\u043c\u043d\u042b\u0419") == MODEST
    assert normalize_catch_size(GOOD) == GOOD
    assert normalize_catch_size("\u0420\u0435\u043a\u043e\u0440\u0434") == RECORD
    assert normalize_catch_size(TROPHY) == TROPHY


def test_catch_size_colors_are_bound_to_stable_keys():
    assert CATCH_SIZE_COLORS_BY_KEY == {
        "modest": "#242424",
        "good": "#275277",
        "record": "#8C1D2C",
        "trophy": "#1D8667",
    }
