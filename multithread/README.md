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

## Process
### Step 1 - Apply multi-threads to simple web server
The server with threads shows a huge improved performance when the request takes rather long time to accomplish (1s+), since requests can be now processed simultaneously.

However, creating thread for each connection is not an optimal solution because a large number of threads will grind system performance.

### Step 2 - Create thread pools
Using thread pools definitely avoid creating too many threads but still takes high CPU usage because all threads are waiting for new connections

Commmon Issues:
* Double free of object
  * Reason: the shared data structure "queue" is not thread-safe
  * Solution: use mutex thread lock to protect enqueue() and dequeue()

