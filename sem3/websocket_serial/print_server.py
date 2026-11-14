"""Print messages sent by index.html to the terminal."""

import asyncio

from websockets.asyncio.server import serve


async def handle(websocket):
    async for message in websocket:
        print(message, flush=True)
        await websocket.send("Printed: " + message)


async def main():
    async with serve(handle, "127.0.0.1", 8765):
        print("Listening on ws://127.0.0.1:8765", flush=True)
        await asyncio.get_running_loop().create_future()


if __name__ == "__main__":
    try:
        asyncio.run(main())
    except KeyboardInterrupt:
        pass
