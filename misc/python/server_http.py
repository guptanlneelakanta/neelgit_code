# server.py
import ssl
from http.server import HTTPServer, BaseHTTPRequestHandler

class SimpleHandler(BaseHTTPRequestHandler):
    def do_GET(self):
        self.send_response(200)
        self.send_header("Content-type", "text/plain")
        self.end_headers()
        self.wfile.write(b"Hello over HTTPS!")

if __name__ == "__main__":
    server_address = ('0.0.0.0', 4443)
    httpd = HTTPServer(server_address, SimpleHandler)

    # Wrap socket with SSL
    httpd.socket = ssl.wrap_socket(
        httpd.socket,
        keyfile="server.key",     # your private key
        certfile="server.crt",    # your certificate (signed)
        server_side=True
    )

    print("Serving HTTPS on port 4443")
    httpd.serve_forever()

