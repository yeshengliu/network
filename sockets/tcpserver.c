#include "common.h"

int main(int argc, char *argv[]) {
  int listenfd, connfd, n;
  struct sockaddr_in servaddr;
  uint8_t buff[MAXLINE + 1];
  uint8_t recvline[MAXLINE + 1];

  // create new socket
  if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    error_handling("Error while creating the socket!");
  }

  // set server address
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(SERVER_PORT); /* server port */

  // bind
  // associate the socket with the server address
  if (bind(listenfd, (SA *) &servaddr, sizeof(servaddr)) < 0) {
    error_handling("Error while binding the socket!");
  }

  // listen
  if (listen(listenfd, 10) < 0) {
    error_handling("Error while listening the socket!");
  }

  // accept
  while (1) {
    struct sockaddr_in addr;
    socklen_t addr_len;
    char client_ip[MAXLINE + 1];

    // accept blocks until an incoming connection arrives
    // it returns a "file descriptor" for the new connection
    printf("waiting for connection on port %d...\n", SERVER_PORT);
    fflush(stdout);
    connfd = accept(listenfd, (SA *) &addr, &addr_len);

    inet_ntop(AF_INET, &addr, client_ip, MAXLINE);
    printf("accepted connection from %s\n", client_ip);
    
    // zero out the receive buffer to make sure it ends up null terminated
    memset(recvline, 0, MAXLINE);

    // read the request from the client
    while ((n = read(connfd, recvline, MAXLINE - 1)) > 0) {
      fprintf(stdout, "\n%s\n\n%s", bin2hex(recvline, n), recvline);

      // detect the end of the request
      if (recvline[n - 1] == '\n') {
        break;
      }
      memset(recvline, 0, MAXLINE);
    }

    // check for error
    if (n < 0) {
      error_handling("Error while reading the request!");
    }

    // now send the response back to the client
    snprintf((char*) buff, sizeof(buff), "HTTP/1.0 200 OK\r\n\r\nHello");

    // write the response into connection socket
    write(connfd, (char*) buff, strlen((char*) buff));
    close(connfd);
  }
}