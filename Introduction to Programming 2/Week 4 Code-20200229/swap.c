/* File: swap.c */
#include <stdio.h>

void swap (int x, int y) {
	int temp;
	temp = x;
	x = y;
	y = temp;
	printf("a = %d, b = %d\n", x, y);
}

int main () {
	int a =-100, b = 120 ;
	swap (a, b);
	printf ("a = %d, b = %d\n", a, b);
}
