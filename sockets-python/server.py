"""
A simple TCP server that requests a file from the client.
"""

import socket
import sys

HOST = "127.0.0.1"  # localhost
PORT = int(sys.argv[1])

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))  # Bind the socket to an address and port number
    s.listen()  # Enable a server to accept connections.
    print(f"server IP address: {HOST}")
    print(f"server port number: {PORT}")
    print("Ready to serve...")
    while True:
        # Accept a connection. The socket must be bound to an address and listening for connections.
        conn, addr = s.accept()
        with conn:
            data = conn.recv(1024)  # receives the data from the client
            url = data.decode()

            conn.send(b"---------------HTTP RESPONSE---------------\n")
            try:
                f = open(url, "rb")
                conn.send(b"HTTP/1.1 200 OK\n")
                l = f.read(1024)
                while l:
                    conn.send(l)
                    l = f.read(1024)
                f.close()
            except OSError:
                conn.send(b"HTTP/1.1 404 Not Found")

            conn.send(b"\n")
            conn.send(b"---------------END OF HTTP RESPONSE---------------")
