# Sockets
This project is to practice writing **web sockets** (client & server) with C

## Usage
To compile the project, type
```
% make
```
To run the web client, type
```
% ./tcpc <ip-address>
```
To run the web server, type
```
% ./tcps
```

## Example
### tcpc
```
% ./tcpc 142.251.33.78

HTTP/1.1 200 OK
Date: Sun, 05 Mar 2023 14:55:36 GMT
Expires: -1
Cache-Control: private, max-age=0
Content-Type: text/html; charset=ISO-8859-1
P3P: CP="This is not a P3P policy! See g.co/p3phelp for more info."
Server: gws
X-XSS-Protection: 0
X-Frame-Options: SAMEORIGIN
Set-Cookie: 1P_JAR=2023-03-05-14; expires=Tue, 04-Apr-2023 14:55:36 GMT; path=/; domain=.google.com; Secure
Set-Cookie: AEC=ARSKqsJCWsqgoB0TDTjqFpVpHrbCkmsowAHgR0BEny4V2grrM07_eEouOhE; expires=Fri, 01-Sep-2023 14:55:36 GMT; path=/; domain=.google.com; Secure; HttpOnly; SameSite=lax
Set-Cookie: NID=511=vr2LwXpiThS53_s9Gi3Jqw1vlDk63UPWe9HF5YH1nx-IOy76PDFDv2I_XautvqBOGA882ljmpL1f519aH-Vlic37RUBOJNYl9vewxbM7hrRd3mzgMEPAtW3mb6_qjm9V0g0eI0bBfqiIePZkCnJEViB63RuTBQrTw7aYoYaIPng; expires=Mon, 04-Sep-2023 14:55:36 GMT; path=/; domain=.google.com; HttpOnly
Accept-Ranges: none
Vary: Accept-Encoding
Transfer-Encoding: chunked
```
# tcps
```
% ./tcps

waiting for connection on port 18000...

47 45 54 20 2F 20 48 54 54 50 2F 31 2E 31 0D 0A 48 6F 73 74 3A 20 6C 6F 63 61 6C 68 6F 73 74 3A 31 38 30 30 30 0D 0A 43 6F 6E 6E 65 63 74 69 6F 6E 3A 20 6B 65 65 70 2D 61 6C 69 76 65 0D 0A 73 65 63 2D 63 68 2D 75 61 3A 20 22 43 68 72 6F 6D 69 75 6D 22 3B 76 3D 22 31 31 30 22 2C 20 22 4E 6F 74 20 41 28 42 72 61 6E 64 22 3B 76 3D 22 32 34 22 2C 20 22 47 6F 6F 67 6C 65 20 43 68 72 6F 6D 65 22 3B 76 3D 22 31 31 30 22 0D 0A 73 65 63 2D 63 68 2D 75 61 2D 6D 6F 62 69 6C 65 3A 20 3F 30 0D 0A 73 65 63 2D 63 68 2D 75 61 2D 70 6C 61 74 66 6F 72 6D 3A 20 22 6D 61 63 4F 53 22 0D 0A 44 4E 54 3A 20 31 0D 0A 55 70 67 72 61 64 65 2D 49 6E 73 65 63 75 72 65 2D 52 65 71 75 65 73 74 73 3A 20 31 0D 0A 55 73 65 72 2D 41 67 65 6E 74 3A 20 4D 6F 7A 69 6C 6C 61 2F 35 2E 30 20 28 4D 61 63 69 6E 74 6F 73 68 3B 20 49 6E 74 65 6C 20 4D 61 63 20 4F 53 20 58 20 31 30 5F 31 35 5F 37 29 20 41 70 70 6C 65 57 65 62 4B 69 74 2F 35 33 37 2E 33 36 20 28 4B 48 54 4D 4C 2C 20 6C 69 6B 65 20 47 65 63 6B 6F 29 20 43 68 72 6F 6D 65 2F 31 31 30 2E 30 2E 30 2E 30 20 53 61 66 61 72 69 2F 35 33 37 2E 33 36 0D 0A 41 63 63 65 70 74 3A 20 74 65 78 74 2F 68 74 6D 6C 2C 61 70 70 6C 69 63 61 74 69 6F 6E 2F 78 68 74 6D 6C 2B 78 6D 6C 2C 61 70 70 6C 69 63 61 74 69 6F 6E 2F 78 6D 6C 3B 71 3D 30 2E 39 2C 69 6D 61 67 65 2F 61 76 69 66 2C 69 6D 61 67 65 2F 77 65 62 70 2C 69 6D 61 67 65 2F 61 70 6E 67 2C 2A 2F 2A 3B 71 3D 30 2E 38 2C 61 70 70 6C 69 63 61 74 69 6F 6E 2F 73 69 67 6E 65 64 2D 65 78 63 68 61 6E 67 65 3B 76 3D 62 33 3B 71 3D 30 2E 37 0D 0A 53 65 63 2D 46 65 74 63 68 2D 53 69 74 65 3A 20 6E 6F 6E 65 0D 0A 53 65 63 2D 46 65 74 63 68 2D 4D 6F 64 65 3A 20 6E 61 76 69 67 61 74 65 0D 0A 53 65 63 2D 46 65 74 63 68 2D 55 73 65 72 3A 20 3F 31 0D 0A 53 65 63 2D 46 65 74 63 68 2D 44 65 73 74 3A 20 64 6F 63 75 6D 65 6E 74 0D 0A 41 63 63 65 70 74 2D 45 6E 63 6F 64 69 6E 67 3A 20 67 7A 69 70 2C 20 64 65 66 6C 61 74 65 2C 20 62 72 0D 0A 41 63 63 65 70 74 2D 4C 61 6E 67 75 61 67 65 3A 20 65 6E 2D 55 53 2C 65 6E 3B 71 3D 30 2E 39 2C 7A 68 2D 54 57 3B 71 3D 30 2E 38 2C 7A 68 2D 43 4E 3B 71 3D 30 2E 37 2C 7A 68 3B 71 3D 30 2E 36 2C 6A 61 3B 71 3D 30 2E 35 0D 0A 43 6F 6F 6B 69 65 3A 20 75 73 65 72 6E 61 6D 65 2D 6C 6F 63 61 6C 68 6F 73 74 2D 38 38 38 38 3D 22 32 7C 31 3A 30 7C 31 30 3A 31 36 37 35 35 36 38 34 34 32 7C 32 33 3A 75 73 65 72 6E 61 6D 65 2D 6C 6F 63 61 6C 68 6F 73 74 2D 38 38 38 38 7C 34 34 3A 4D 7A 49 77 59 57 4A 6B 59 54 59 33 4E 54 41 32 4E 44 63 34 59 57 49 79 59 6D 51 31 59 7A 42 6D 4E 57 59 7A 4E 32 51 33 4F 54 4D 3D 7C 39 35 36 35 65 33 39 30 62 63 63 62 37 36 63 31 31 31 63 63 32 65 64 38 64 33 63 61 30 65 37 39 62 30 33 63 61 32 35 34 65 63 31 35 32 66 31 66 31 37 36 37 33 66 61 38 33 35 38 37 36 34 38 39 22 3B 20 5F 78 73 72 66 3D 32 7C 62 64 39 32 35 34 64 66 7C 35 39 61 61 61 61 36 64 62 39 38 63 66 61 64 36 31 65 62 32 32 62 38 62 38 30 66 30 39 65 32 37 7C 31 36 37 35 35 36 38 34 34 32 3B 20 57 65 62 73 74 6F 72 6D 2D 63 34 36 34 36 37 37 36 3D 63 64 32 63 35 31 32 36 2D 37 34 30 62 2D 34 32 62 64 2D 62 61 66 37 2D 62 39 37 39 34 30 63 36 66 63 38 64 0D 0A 0D 0A 

GET / HTTP/1.1
Host: localhost:18000
Connection: keep-alive
sec-ch-ua: "Chromium";v="110", "Not A(Brand";v="24", "Google Chrome";v="110"
sec-ch-ua-mobile: ?0
sec-ch-ua-platform: "macOS"
DNT: 1
Upgrade-Insecure-Requests: 1
User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/110.0.0.0 Safari/537.36
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7
Sec-Fetch-Site: none
Sec-Fetch-Mode: navigate
Sec-Fetch-User: ?1
Sec-Fetch-Dest: document
Accept-Encoding: gzip, deflate, br
Accept-Language: en-US,en;q=0.9,zh-TW;q=0.8,zh-CN;q=0.7,zh;q=0.6,ja;q=0.5
Cookie: username-localhost-8888="2|1:0|10:1675568442|23:username-localhost-8888|44:MzIwYWJkYTY3NTA2NDc4YWIyYmQ1YzBmNWYzN2Q3OTM=|9565e390bccb76c111cc2ed8d3ca0e79b03ca254ec152f1f17673fa835876489"; _xsrf=2|bd9254df|59aaaa6db98cfad61eb22b8b80f09e27|1675568442; Webstorm-c4646776=cd2c5126-740b-42bd-baf7-b97940c6fc8d
```

## Reference
https://www.youtube.com/watch?v=bdIiTxtMaKA&list=PL9IEJIKnBJjH_zM5LnovnoaKlXML5qh17&index=1