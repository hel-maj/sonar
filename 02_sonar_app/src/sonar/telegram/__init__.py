"""Telegram integration."""

from __future__ import annotations

import importlib.abc
import importlib.machinery
import sys


class _NotifierLoader(importlib.abc.Loader):
    def __init__(self, wrapped: importlib.abc.Loader) -> None:
        self.wrapped = wrapped

    def create_module(self, spec):
        if hasattr(self.wrapped, "create_module"):
            return self.wrapped.create_module(spec)
        return None

    def exec_module(self, module) -> None:
        self.wrapped.exec_module(module)
        from sonar.telegram.notifier_adjustments import apply_to_module

        apply_to_module(module)


class _NotifierFinder(importlib.abc.MetaPathFinder):
    def find_spec(self, fullname, path, target=None):
        if fullname != __name__ + ".notifier":
            return None
        try:
            sys.meta_path.remove(self)
            spec = importlib.machinery.PathFinder.find_spec(fullname, path)
        finally:
            sys.meta_path.insert(0, self)
        if spec is not None and spec.loader is not None:
            spec.loader = _NotifierLoader(spec.loader)
        return spec


def install() -> None:
    module = sys.modules.get(__name__ + ".notifier")
    if module is not None:
        from sonar.telegram.notifier_adjustments import apply_to_module

        apply_to_module(module)
        return
    if any(isinstance(finder, _NotifierFinder) for finder in sys.meta_path):
        return
    sys.meta_path.insert(0, _NotifierFinder())


install()
