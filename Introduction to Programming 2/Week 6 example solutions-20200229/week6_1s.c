// week6_1s.c 
// lab week 6 question 1 model solution

#include <stdio.h>

int * getArray( ) {

	static int a[10];
	int i = 0;
	printf("enter 10 integers separated by space:\n");
	while (i<10)
	{
		scanf("%d", &a[i] );
		i=i+1;
	}

   return a;
}

int main () {

	int *parray = getArray();
	int i = 0;
	while (i<10){
		printf("%d " , parray[i] );
	  	i = i + 1;
	}

   return 0;
}