"""
A simple TCP client that requests a file from the server.
"""

import socket
import sys

HOST = sys.argv[1]
PORT = int(sys.argv[2])
url = sys.argv[3]

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    # set timeout to detect file not found
    s.settimeout(1)
    try:
        s.connect((HOST, PORT))
        print("Connection Successful!")
        s.sendall(url.encode())
        while True:
            data = s.recv(1024)
            if not data:
                break
            print(data.decode())
    # server not respond
    except:
        print("Error while connecting!")
