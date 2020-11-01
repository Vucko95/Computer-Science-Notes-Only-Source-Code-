#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int capacity;	
    int top;
} Stack;

bool is_empty(Stack *sptr) {
    return (sptr->top == 0);
}

bool is_full(Stack *sptr){
	return (sptr->capacity == sptr->top);
}

bool push( Stack *sptr, int value ) {
   // extend capacity
    if ( is_full(sptr) ) {
      int  *new_data;
      new_data = realloc( sptr->data, sizeof( int ) * sptr->capacity * 2 );
      if ( new_data == NULL ) return false;
      sptr->data = new_data;
      sptr->capacity *= 2;
    }
    sptr->data[ sptr->top++ ] = value;
    return true;
}

int pop(Stack *sptr) {
		if(is_empty( sptr )){
			printf( "The stack is empty!" );
			return -1;			
		}
		else{
			sptr->top--;
			return sptr->data[sptr->top];
		}
}

void display(Stack *sptr) {
    int i=0;
    printf("data: ");
    for (i=0;i<sptr->top; i++)
         printf("[%d] ", sptr->data[i]);
    printf("\ntop: %d", sptr->top);
    printf("\ncapacity: %d\n", sptr->capacity);
}

Stack* new_stack() {
  int capacity = 5; // let's start with a capacity of 5
  Stack *stack = malloc( sizeof( Stack ) );
  if ( stack == NULL ) return NULL;
  stack->top = 0;
  stack->capacity = capacity;
  stack->data = malloc( sizeof( int ) * capacity );
  if ( stack->data == NULL ) {
    free( stack );
    return NULL;
  }
  return stack;
}

void dispose_stack( Stack *sptr ) {
  free( sptr->data );
  free( sptr );
}

int main() {
	//do not edit this function
	//see output comment below
   int i = 0;
   Stack *stack = new_stack();
   
   for ( i = 0; i < 25; i++ ) {
         push( stack, i );
    }
	display ( stack );
	printf( "%s\n", "popping stack!");
	printf( "the value popped is: %d\n", pop(stack) );
	printf( "pushing 2\n"); 
	push(stack, 2);
	printf( "pushing 55\n");
	push(stack, 55);
	printf( "pushing 30\n");
	push(stack, 30);
	display(stack);
	dispose_stack(stack);
}

/*output of main should be:
data: [0] [1] [2] [3] [4] [5] [6] [7] [8] [9] [10] [11] [12] [13] [14] [15] [16] [17] [18] [19] [20] [21] [22] [23] [24]
top: 25
capacity: 40
popping stack!
the value popped is: 24
pushing 2
pushing 55
pushing 30
data: [0] [1] [2] [3] [4] [5] [6] [7] [8] [9] [10] [11] [12] [13] [14] [15] [16] [17] [18] [19] [20] [21] [22] [23] [2] [55] [30]
top: 27
capacity: 40
*/