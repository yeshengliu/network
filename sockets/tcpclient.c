#include "common.h"

int main(int argc, char *argv[]) {
  int sockfd, n;
  int sendbytes;
  struct sockaddr_in servaddr;
  char sendline[MAXLINE];
  char recvline[MAXLINE];

  // usage check
  if (argc != 2) {
    error_handling("usage: %s <hostname>\n", argv[0]);
  }

  // create socket
  // AF_INET: IPv4, SOCK_STREAM: TCP, SOCK_DGRAM: UDP
  // 0 == use TCP
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    error_handling("Error while creating the socket!\n");
  }

  // set server address
  // address family: internet port
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(SERVER_PORT);

  // translate address
  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
    error_handling("inet_pton error for %s ", argv[1]);
  }

  // connect to server
  if (connect(sockfd, (SA *)&servaddr, sizeof(servaddr)) < 0) {
    error_handling("Error while connecting to server!\n");
  }

  // send request
  sprintf(sendline, "GET / HTTP/1.1\r\n\r\n");
  sendbytes = strlen(sendline);
  if (send(sockfd, sendline, sendbytes, 0) != sendbytes) {
    error_handling("Error while sending request!\n");
  }

  // receive response
  memset(recvline, 0, MAXLINE);
  while ((n = recv(sockfd, recvline, MAXLINE, 0)) > 0) {
    printf("%s", recvline);
  }
  if (n < 0) {
    error_handling("Error while receiving response!\n");
  }

  exit(0);
}