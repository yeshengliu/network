# Multithread Server
This project is to practice writing **multi-threaded** server with C

## Usage
To compile the project, type
```
% make
```
To run the web server, type
```
% ./server
```
I also include ruby scripts for testing
* **client.rb** - create a local web client to send a local file to web server
* **generateFile.rb** - generate testing files with random strings

To test the performance, type
```
% time ./sendManyRequests.bash
```

## Reflection
### Advantage
The server with threads shows a huge improved performance when the request takes rather long time to accomplish (1s+), because requests can be processed simultaneously.
