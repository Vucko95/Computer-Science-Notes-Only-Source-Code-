//checking.c
#include<stdio.h>
#include <stdlib.h>
int main()
{
	int *ptr_one = malloc(sizeof(int));
	if (ptr_one == NULL)
	{
		printf("ERROR: Out of memory\n");
		return 1;
	}
	else{
		*ptr_one = 25;
		printf("%d\n", *ptr_one);
	}
	free(ptr_one);//why is this here and not inside the else? 

	int *ptr_two = malloc(sizeof(int)*999999999999999999999999999999999999999999999999999999999);
	if (ptr_two == NULL)
	{
		printf("ERROR: Out of memory\n");
		return 1;
	}
	else{
		printf("allocation for ptr_two succeeded!");
	}
	free(ptr_two);
}