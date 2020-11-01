#include <stdio.h>
#include <limits.h>

int main()
{
	int x = INT_MAX;
	printf( "x is : %d\n", x );
	x = x + 1;
	printf( "x is : %d\n", x );
	
	int y = INT_MIN;
    printf( "y is : %d\n", y );
	y = y - 1;
	printf( "y is : %d\n", y );
}
