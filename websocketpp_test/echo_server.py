from gevent import monkey
monkey.patch_all()

import time
from gevent.pywsgi import WSGIServer
from flask import Flask
from flask_sock import Sock

app = Flask(__name__)
app.config['SOCK_SERVER_OPTIONS'] = {'ping_interval': 25}

sock = Sock(app)

@sock.route('/echo')
def echo(ws):
    print("open route")
    while True:
        print("here")
        try:
            data = ws.receive()
            print(data)
            ws.send(data)
            # Implementing a simple heartbeat mechanism
            time.sleep(2)  # Sleep for 30 seconds
            ws.send("ping")  # Send a "ping" message
        except Exception as e:
            print(f"caught error: {e}")
            break

if __name__ == '__main__':
    WSGIServer(('', 5000), app).serve_forever()
