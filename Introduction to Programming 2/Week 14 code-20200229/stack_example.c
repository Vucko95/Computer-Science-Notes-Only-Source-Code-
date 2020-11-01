#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
} Node;

typedef struct {
	Node *top;
	int size;
} Stack;

Stack* new_stack() {
	Stack *sptr = malloc(sizeof(Stack));
	if (sptr == NULL) return NULL;
	sptr->size = 0;
	sptr->top = NULL;
	return sptr;
}

bool push(Stack *sptr, int value) {
	Node *node = malloc(sizeof(node));
	if (node == NULL) return false;
	
	node->data= value;
	node->next = sptr->top;
	sptr->top = node;
	sptr->size++;
	return true;
}

int pop(Stack *sptr) {
	Node *node = sptr->top;
	int data = sptr->top->data;
	sptr->top = sptr->top->next;
	sptr->size--;
	free(node);
	return data;
}

bool is_empty(Stack *sptr) {
	return sptr->size == 0;
}

void dispose_stack(Stack *sptr) {
	while (!is_empty(sptr)) {
		pop(sptr);
	}
	
	free(sptr);
}

int size(Stack *sptr){
   //should return the number of items in the stack
}

int top(Stack *sptr){
   //returns the data at the top of the stack without popping the stack
}

int max(Stack *sptr){
    //returns the max value in the stack
}

void display(Stack *sptr) {
	printf("\nvalues: ");
	Node *cur = sptr->top;
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
	printf("size: %d\n", sptr->size);
	printf("\n");
}

int main() {
	Stack *stack = new_stack();
	
	printf("pushing 1");
	push(stack, 1);
	display(stack);

	printf("pushing 7");	
	push(stack, 7);
	display(stack);

	printf("popping");
	pop(stack);
	display(stack);

	printf("pushing 4");	
	push(stack, 4);
	display(stack);

	printf("popping");
	pop(stack);
	display(stack);

	printf("pushing 3");	
	push(stack, 3);
	display(stack);
	
	dispose_stack(stack);

	return(0);
	
}	
