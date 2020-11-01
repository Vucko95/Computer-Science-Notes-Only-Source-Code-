#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
   int data;
   struct Node *next;
} Node;

Node* add_element( Node *head, int element ) {
   Node *new_node;
   new_node = malloc( sizeof( Node ) );
   new_node->data = element;
   new_node->next = head;
   return new_node;
}

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

void print_list( Node *head ) {
   Node *current;
   current = head;
   while( current != NULL ) {
      if ( current == head ) {
         printf( "{ %d", current->data );
      }
      else if ( current->next != NULL ) {
         printf( ", %d", current->data );
      }
      else {
         printf( ", %d }\n", current->data );
      }
      current = current->next;
   }
}

int value_at(Node *head, int n){
	if (n < 1){//if we try to get the value at a node less than the first return error
		return -1;
	}
	else if( n > length( head )){//if we try to get the value at a node beyond end of list return error 
		return -1;
	}
	else{
		Node* current = head; //start at head of list
		int count = 1; //head is the first node in list so start there
		while( count < n ) {//move towards end of list
			count++; //update count
			current = current->next; //make current the next node
		}
		//we are now at the end of the list, so return the value at the current (last) node
		return current->data;
	}
}

void add_element_at_end( Node *head, int element) { //no need to return a node, as the head doesn't change!
   Node *current = head; //start at head of list
   Node *new_node = malloc( sizeof( Node ) ); //make new node
   new_node->data = element; //set value of new node
   new_node->next = NULL; //new node goes at end, so its next is NULL
   int count = 1; //we count the head as the first node
   while (count < length(head)){ //move towards end of list
	   count++; //increase count
	   current = current->next; //update current
   }
   //current is at end of list. 
   current->next = new_node; //make next of last node the new node
}

int main() {
   Node* list_head;
   list_head = NULL;
   list_head = add_element( list_head, 3 );
   list_head = add_element( list_head, 2 );
   list_head = add_element( list_head, 1 );
   list_head = add_element( list_head, 0 );

   int len = length( list_head );
   printf( "Length is: %d\n", len );
   print_list( list_head );

   //test value_at
   printf( "Question 1: The value at node 2 is: %d\n", value_at(list_head, 2));
 
   //test add_element_at_end
   printf( "\nQuestion 2: Adding value 4 at end of list in a new node - node 5\n");
   add_element_at_end(list_head, 4);
   len = length( list_head );
   printf( "Length is: %d\n", len );
   print_list( list_head );
}

