import websockets
import asyncio

async def hello():
    uri = "ws://localhost:5000/echo"  # Match the server's URL
    while True:
        try:
            async with websockets.connect(uri) as websocket:
                while True:
                    await websocket.send("pong")
                    message = await websocket.recv()
                    if message == "ping":
                        print("Received ping, sending pong")
                        await websocket.send("pong")
                    else:
                        print(f"< {message}")
        except websockets.ConnectionClosedOK:
            print("Connection closed normally")
            break
        except Exception as e:
            print(f"Connection error: {e}")
            break
        await asyncio.sleep(5)  # Wait before trying to reconnect

asyncio.run(hello())
