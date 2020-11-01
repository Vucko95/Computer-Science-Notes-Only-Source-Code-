//week3_3s.c
//lab week3 question 3 model solution
#include <stdio.h>
#include <limits.h>

int main()
{
	short x = SHRT_MAX;
   	printf( "x is : %d\n", x );
	x = x + 1;
	printf( "x is : %d\n", x );
	
	short y = SHRT_MIN;
	printf( "y is : %d\n", y );
	y = y - 1;
	printf( "y is : %d\n", y );
}
