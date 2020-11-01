//lab week4 question 1 model solution
//student name
//student number

#include <stdio.h>

int main () {
	int x = 30;
	printf ("x is %d \n", x);
	int* y;
	y = &x;
	*y = 50;
	printf ("x is %d \n", x);
}
