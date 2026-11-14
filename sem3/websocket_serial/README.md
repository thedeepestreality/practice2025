# WebSocket to serial

Browser JavaScript → WebSocket → Python → serial device.

Requires Python 3.10+ and a serial device connected to your computer.

1. Open a terminal in this folder and install dependencies:
   ```sh
   python -m pip install -r requirements.txt
   ```
2. Find your serial port:
   ```sh
   python -m serial.tools.list_ports
   ```
3. Start the server with your port name:
   ```sh
   python server.py COM3
   ```
   On Linux, for example: `python server.py /dev/ttyUSB0`.
   Set the baud rate in `server.py` to match your device (default: 9600).
4. Open `index.html` in your browser and click **Send to serial**.

Each click sends the input text as UTF-8 followed by a newline (`\n`).
The page displays the server's write acknowledgement; it does not read a
response from the serial device. Close other serial monitors before starting.
Stop the server with Ctrl+C; this also closes the serial port.

To print messages in the terminal without a serial device, run
`python print_server.py` instead of `server.py`, then open or reload
`index.html` and click the send button. Run only one server at a time;
both use port 8765.

For the opposite direction (serial device to browser), run:
```sh
python serial_to_websocket.py COM8
```
This server reads at 115200 baud and forwards each UTF-8 line ending in `\n`
to all connected browsers. Change its baud rate to match your device.
Stop the other servers first, then open or reload `index.html`. Incoming
strings appear automatically on the page; the send button isn't needed.
This server only reads from serial and sends to WebSocket.

API references: [websockets](https://websockets.readthedocs.io/en/stable/reference/asyncio/server.html),
[pySerial](https://pyserial.readthedocs.io/en/latest/pyserial_api.html).
