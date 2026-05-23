from __future__ import annotations

from dataclasses import dataclass, field
from datetime import datetime
from threading import RLock
from typing import Any, Callable


@dataclass(slots=True)
class Event:
    name: str
    payload: dict[str, Any] = field(default_factory=dict)
    created_at: datetime = field(default_factory=datetime.now)


@dataclass(slots=True)
class UiEventMessage:
    text: str
    event_type: str = "info"
    icon: str = ""
    detail: str = ""
    extra_green: str = ""
    extra_red: str = ""
    created_at: datetime = field(default_factory=datetime.now)


UiEventSubscriber = Callable[[UiEventMessage], None]


class EventBus:
    def __init__(self) -> None:
        self._ui_event_subscribers: list[UiEventSubscriber] = []
        self._lock = RLock()

    def subscribe_ui_events(self, subscriber: UiEventSubscriber) -> Callable[[], None]:
        with self._lock:
            self._ui_event_subscribers.append(subscriber)

        def unsubscribe() -> None:
            with self._lock:
                if subscriber in self._ui_event_subscribers:
                    self._ui_event_subscribers.remove(subscriber)

        return unsubscribe

    def publish_ui_event(self, event: UiEventMessage) -> None:
        with self._lock:
            subscribers = tuple(self._ui_event_subscribers)
        for subscriber in subscribers:
            subscriber(event)


event_bus = EventBus()
