"""Forward newline-terminated serial strings to connected browsers."""

import asyncio
import sys

import serial
from websockets.asyncio.server import broadcast, serve


async def main():
    port = sys.argv[1] if len(sys.argv) > 1 else "COM8"
    clients = set()

    async def handle(websocket):
        clients.add(websocket)
        try:
            await websocket.wait_closed()
        finally:
            clients.discard(websocket)

    # Match the baud rate to your device. Timeout lets shutdown finish promptly.
    with serial.Serial(port, baudrate=115200, timeout=0.2) as device:
        async with serve(handle, "127.0.0.1", 8765):
            print(f"Reading {port} at 115200 baud; ws://127.0.0.1:8765", flush=True)
            pending = b""
            while True:
                # Read in a thread so serial waiting doesn't block WebSocket connections.
                pending += await asyncio.to_thread(device.readline)
                while b"\n" in pending:
                    line, pending = pending.split(b"\n", 1)
                    message = line.rstrip(b"\r").decode("utf-8", errors="replace")
                    print(message, flush=True)
                    broadcast(clients, message)


if __name__ == "__main__":
    try:
        asyncio.run(main())
    except KeyboardInterrupt:
        pass
