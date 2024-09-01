from gevent import monkey
monkey.patch_all()

from gevent import pywsgi
from geventwebsocket.handler import WebSocketHandler
from flask import Flask
from flask_sock import Sock

app = Flask(__name__)
sock = Sock(app)

@sock.route('/echo')
def echo(ws):
    while True:
        try:
            data = ws.receive()
            print(data)
            ws.send(data)
        except Exception as e:
            print(f"caught error: {e}")

if __name__ == '__main__':
    server = pywsgi.WSGIServer(('', 5000), app, handler_class=WebSocketHandler)
    server.serve_forever()