"""Forward browser WebSocket messages to a serial port."""

import asyncio
import sys

import serial
from websockets.asyncio.server import serve


async def main():
    port = sys.argv[1] if len(sys.argv) > 1 else "COM3"
    # Change 9600 to match your device's baud rate.
    with serial.Serial(port, baudrate=9600, write_timeout=1) as device:

        async def handle(websocket):
            async for message in websocket:
                if not isinstance(message, str):
                    await websocket.send("Please send text.")
                    continue
                try:
                    device.write((message + "\n").encode("utf-8"))
                    await websocket.send("Sent to serial: " + message)
                except serial.SerialException as error:
                    await websocket.send("Serial error: " + str(error))

        async with serve(handle, "127.0.0.1", 8765):
            print(f"Serial: {port} at 9600 baud; WebSocket: ws://127.0.0.1:8765")
            await asyncio.get_running_loop().create_future()


if __name__ == "__main__":
    try:
        asyncio.run(main())
    except KeyboardInterrupt:
        pass
