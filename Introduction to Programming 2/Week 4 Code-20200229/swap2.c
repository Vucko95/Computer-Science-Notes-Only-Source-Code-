/* File: swap2.c */
#include <stdio.h>

void swap (int *px, int *py) {
	int temp;
	temp = *px;
	*px = *py;
	*py = temp;
	printf("a = %d, b = %d\n",*px, *py);
}

int main () {
	int a =-100, b = 120 ;
	swap (&a, &b);
	printf ("a = %d, b = %d\n", a, b);
}
