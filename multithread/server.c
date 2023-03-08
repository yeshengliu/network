#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <limits.h>
#include <pthread.h>

#define SERVERPORT 8989
#define BUFSIZE 4096
#define SOCKETERROR (-1)
#define SERVER_BACKLOG 100  // allow 100 pending connections

typedef struct sockaddr_in SA_IN;
typedef struct sockaddr SA;

void* handle_connection(void* client_socket);
int check(int exp, const char *msg);

int main(int argc, char *argv[]) {
  int server_socket, client_socket, addr_size;
  SA_IN server_addr, client_addr;

  // create socket
  check(server_socket = socket(AF_INET, SOCK_STREAM, 0),
    "Failed to create socket");
  
  // set server address
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(SERVERPORT);

  // bind socket
  check(bind(server_socket, (SA *)&server_addr, sizeof(server_addr)),
    "Failed to bind socket");

  // listen
  check(listen(server_socket, SERVER_BACKLOG),
    "Failed to listen");

  while (true) {

    printf("Waiting for connection...\n");

    // accept connection
    addr_size = sizeof(SA_IN);
    check(client_socket =
      accept(server_socket, (SA *)&client_addr, (socklen_t*)&addr_size),
      "Failed to accept connection");
    
    // handle connection using threads
    pthread_t thread; // keep track of thread
    int *pclient = malloc(sizeof(int));
    *pclient = client_socket;
    pthread_create(&thread, NULL, handle_connection, (void*)pclient);

    // testing no threads
    // handle_connection(pclient);
  
  } // while

  return 0;
}

int check(int exp, const char *msg) {
  if (exp == SOCKETERROR) {
    perror(msg);
    exit(1);
  }
  return exp;
}

void* handle_connection(void* p_client_socket) {
  int client_socket = *((int*)p_client_socket);
  free(p_client_socket);
  char buffer[BUFSIZE];
  size_t bytes_read;
  int msg_size = 0;
  char actual_path[PATH_MAX + 1];

  // read the client message
  while ((bytes_read = read(client_socket, buffer + msg_size, sizeof(buffer) - msg_size - 1)) > 0) {
    msg_size += bytes_read;
    if (msg_size > BUFSIZE - 1 || buffer[msg_size - 1] == '\n') break;
  }
  check(bytes_read, "Failed to read message");
  buffer[msg_size - 1] = '\0'; // null terminate the message and remove the \n

  printf("Message from client: %s\n", buffer);
  fflush(stdout);

  // validity check
  if (realpath(buffer, actual_path) == NULL) {
    printf("Invalid path: %s\n", buffer);
    close(client_socket);
    return NULL;
  }

  // read file and send its content back to client
  FILE *file = fopen(actual_path, "r");
  if (file == NULL) {
    printf("Failed to open file: %s\n", actual_path);
    close(client_socket);
    return NULL;
  }

  sleep(1); // for performance testing

  while ((bytes_read = fread(buffer, 1, BUFSIZE, file)) > 0) {
    printf("Sending %zu bytes...\n", bytes_read);
    write(client_socket, buffer, bytes_read);
  }

  fclose(file);
  close(client_socket);
  printf("Closing connection\n");
  return NULL;
}