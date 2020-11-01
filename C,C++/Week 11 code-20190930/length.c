#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
   int data;
   struct Node *next;
} Node;

int length(Node *head) {
  Node *current;
  current = head;
  int count = 0;
  while( current != NULL ) {
    count++;
    current = current->next;
  }
  return count;
}

Node* build_one_two_three() {
  Node *head;
  Node *second;
  Node *third;
  head = malloc(sizeof(Node));
  second = malloc(sizeof(Node));
  third = malloc(sizeof(Node));
  head->data = 1;  head->next = second;
  second->data = 2;
  second->next = third;
  third->data = 3;
  third->next = NULL;
  return head;
}

int main() {
   Node* list_head;
   list_head = build_one_two_three();
   int len = length( list_head );
   printf( "Length is: %d\n", len );
}
