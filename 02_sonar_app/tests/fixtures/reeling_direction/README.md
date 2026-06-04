# Reeling direction fixtures

Copy reviewed `*.fixture.npz` files produced by `scripts\record_manual_reeling.ps1`
into this directory. `tests/test_probe_reeling_direction.py` replays every
checked-in fixture against the current reeling-input logic. Version 2 fixtures
store fish world positions and the player's right vector so different map
locations and camera angles remain covered.

Fixtures that intentionally reproduce the current direction bug are marked
`xfail(strict=True)` in the test module. Once the algorithm is fixed, an XPASS
forces removal of that temporary marker.
