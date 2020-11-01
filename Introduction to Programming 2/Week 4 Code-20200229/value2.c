/*file value2.c*/
#include <stdio.h>
int main() {	
	int x = 5;
	int *ptr;
	ptr = &x;
	printf("address of x: %p\n", ptr);
	printf("value of x: %d\n", *ptr);
	*ptr = 10;
	printf( "value of x: %d\n", x );
	printf("value of x: %d\n", *ptr);
}