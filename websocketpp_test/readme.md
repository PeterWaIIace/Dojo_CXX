
### ECHO CLIENT-SERVER
## Websocketpp compatibility with flask-sock testing

## Build and run client:

```
.\build.bat ; Echo_client.exe
```

## run server:
```
python echo_server.py
```


## current issue:

Server:
```
Not reveiving anything
```

Client:
```
[2024-09-01 21:55:27] [connect] Successful connection
[2024-09-01 21:55:27] [connect] WebSocket Connection [::1]:5000 v-2 "WebSocket++/0.8.2" / 101
on open
Echo succeed: unknown error
[2024-09-01 21:55:27] [frame_header] Dispatching write containing 1 message(s) containing 6 header bytes and 11 payload bytes
[2024-09-01 21:55:27] [frame_header] Header Bytes:
[0] (6) 81 8B ED 80 65 02

[2024-09-01 21:55:27] [control] Control frame received with opcode 8
[2024-09-01 21:55:27] [error] handle_read_frame error: asio.system:10053 (An established connection was aborted by the software in your host machine.)
[2024-09-01 21:55:27] [disconnect] Disconnect close local:[1006,An established connection was aborted by the software in your host machine.] remote:[1005]
[2024-09-01 21:55:27] [frame_header] Dispatching write containing 1 message(s) containing 6 header bytes and 2 payload bytes
[2024-09-01 21:55:27] [frame_header] Header Bytes:
[0] (6) 88 82 CD 9E 5C 64

[2024-09-01 21:55:27] [info] asio async_write error: asio.system:10053 (An established connection was aborted by the software in your host machine.)
[2024-09-01 21:55:27] [fatal] handle_write_frame error: websocketpp.transport:2 (Underlying Transport Error)
```
