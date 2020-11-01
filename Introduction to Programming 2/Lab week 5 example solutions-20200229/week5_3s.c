//lab week4 question 3 model solution
//student name
//student number

#include <stdio.h>

int main() {
	int i = 0;
	int int_arr[5] = {1,2,3,4,5};
	int *p = int_arr;
	    
    //print array
    i = 0;
    while (i < 5){
	    printf("%d ", int_arr[i]);
		i = i + 1;
	}	
	printf("\n");
   
    //add 1 to each element using pointer arithmetic
	i = 0;
	while (i < 5){
		*(p + i) = *(p + i) + 1;
		i = i + 1;
	}
    
	//print array
    i = 0;
    while (i < 5){
	    printf("%d ", int_arr[i]);
		i = i + 1;
	}
	printf("\n");
	
	//finally, multiply all even numbers in array by 100 and all odd by -33
	i = 0;
    while (i < 5){
	    if(i%2==0){
			int_arr[i] = int_arr[i]*100;
		}
		else{
			int_arr[i] = int_arr[i]*-33;
		}
		printf("%d ", int_arr[i]);
		i = i + 1;
	}
}
