/*
  This is a simple queue implementation using a singly linked list.
  Specifically it is a queue to store client connections.
*/

#ifndef QUEUE_H
#define QUEUE_H

struct node {
  int* client_socket;
  struct node *next;
};
typedef struct node node_t;

void enqueue(int* client_socket);
int* dequeue();

#endif