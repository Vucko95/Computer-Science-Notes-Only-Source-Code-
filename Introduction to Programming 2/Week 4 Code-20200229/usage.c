/* File : usage.c */
#include <stdio.h>

int main () {
	int a = 13, b = -9, i, *p = &a; // p is a pointer to int
	for (i=0; i<10; i++) {
		if ( *p > 0 ) {
			p = &b ;
		} else if ( *p < 0 ) {
			p = &a ;
		}
		*p = *p + 1 ;
	}
	printf ( "The value of a and b are : %d and %d \n", a, b);
}
