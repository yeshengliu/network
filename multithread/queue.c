#include "queue.h"
#include <stdlib.h>

node_t* head = NULL;
node_t* tail = NULL;

void enqueue(int* client_socket) {
  node_t* new_node = (node_t*)malloc(sizeof(node_t));
  new_node->client_socket = client_socket;
  new_node->next = NULL;
  if (tail == NULL) {
    head = new_node;
  } else {
    tail->next = new_node;
  }
  tail = new_node;
}

// Return NULL if queue is empty
// Return the pointer to a client socket if queue is not empty
int* dequeue() {
  if (head == NULL) {
    return NULL;
  }
  int* client_socket = head->client_socket;
  node_t* temp = head;
  head = head->next;
  if (head == NULL) {
    tail = NULL;
  }
  free(temp);
  return client_socket;
}