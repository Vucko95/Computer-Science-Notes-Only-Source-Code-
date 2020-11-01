// week6_3s.c 
// lab week 6 question 3 model solution

#include <stdio.h>

void changeArray( int a[] ) {

	int i = 0;
	while (i<10)
	{
		a[i] = a[i] * 10;
		i=i+1;
	}

}

int main () {

	int a[10];
	int i = 0;
	printf("enter 10 integers separated by space:\n");
	while (i<10)
	{
		scanf("%d", &a[i] );
		i=i+1;
	}

	changeArray(a);
	
	i = 0;
	while (i<10){
		//printf("%d " , parray[i] );
	    printf("%d " , a[i] );
	   	i = i + 1;
	}
	printf("\n");
   return 0;
}