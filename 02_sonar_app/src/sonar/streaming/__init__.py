"""Local game streaming support."""

from dataclasses import replace

from sonar.streaming.chat import ChatDetection, MajesticChatController, MajesticChatDetector
from sonar.streaming.service import StreamSnapshot, StreamingService as BaseStreamingService


class StreamingService(BaseStreamingService):
    def _snapshot_locked(self) -> StreamSnapshot:
        snapshot = super()._snapshot_locked()
        if snapshot.status == "preparing" and not snapshot.active and snapshot.stream_url is None:
            return replace(snapshot, status="offline")
        return snapshot


__all__ = ["ChatDetection", "MajesticChatController", "MajesticChatDetector", "StreamSnapshot", "StreamingService"]
