/* file: array.c*/

#include <stdio.h>

int main() {
	int i = 0;
	int int_arr[5] = {1,2,3,4,5};
	int *p = int_arr;
	    
	//change arr[3] to -1
	*(int_arr + 2) = -1;
	
	//change arr[4] to 0
	*(p + 3) = 0;
       
	//print array
	i = 0;
	while (i < 5){
	    printf("%d ", int_arr[i]);
		i = i + 1;
	}
}