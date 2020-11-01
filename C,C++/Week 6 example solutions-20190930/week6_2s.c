// week6_2s.c 
// lab week 6 question 2 model solution

#include <stdio.h>

int main () {

	int a [10];
	int i = 0;
	while (i<10){
		a[i] = i * 8;
	  	i = i + 1;
	}
	i = 0;
	while (i<10){
		printf("%d " , *(a + i) );
	  	i = i + 1;
	}

   return 0;
}