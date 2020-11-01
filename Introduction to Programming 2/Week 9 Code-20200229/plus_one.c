#include <stdio.h>

int main()
{
	int a = 0;
	printf("a is %d\n", a);
	a = a + 1;
	printf("a after a=a+1 is %d\n", a);
	a++;
	printf("a after a++ is %d\n", a);
	a += 1;
	printf("a after a+=1 is %d\n", a);
	a=(-(~a)); //see http://www.geeksforgeeks.org/add-1-to-a-given-number/ for explanation
	printf("a after a=(-(~a)) is %d\n", a);
}
