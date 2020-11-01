/*file pointer.c*/
#include <stdio.h>
int main() {
   
	int a = 6;
	int *p;
	p = &a;
 
	printf( "%d\n", *p );
}