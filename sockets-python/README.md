# Sockets
This project is to practice writing **web sockets** (client & server) with Python

## Usage
To run the web client, type
```
% python3 client.py <ip-address> <port-number> <file-name>
```
To run the web server, type
```
% python3 server.py <port-number>
```

## Example
```
% python3 client.py 127.0.0.1 8521 test01
Connection Successful!

---------------HTTP RESPONSE---------------
HTTP/1.1 200 OK

--- FILE CONTEXT ---

---------------END OF HTTP RESPONSE---------------

% python3 client.py 127.0.0.1 8521 doesntexist
Connection Successful!

---------------HTTP RESPONSE---------------
HTTP/1.1 404 Not Found

---------------END OF HTTP RESPONSE---------------

% python3 client.py 000.0.0.0 8521 test01

Error while connecting!
```