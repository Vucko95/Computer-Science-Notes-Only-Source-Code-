//week3_1s.c
//lab week3 question 1 model solution
#include <stdio.h>

int main(){
	int numbers[10];
	//read in array
	int i = 0;
	printf("enter 10 integers separated by space:\n");
	while (i < 10)
	{
		scanf("%d", &numbers[i] );
		i = i + 1;
	}
	
	//swap first and second halves of array
	i = 0;
	int temp = 0;
		while (i < 5){
			temp = numbers[i + 5];
			numbers[i + 5] = numbers[i];
			numbers[i] = temp;
			i = i + 1;
		}
	//reverse order of first 5 elements
	i = 0;
	temp = 0;
	int length = 5;
	float mid = 5 / 2;
	while (i < mid){
			temp = numbers[length - 1 - i];
			numbers[length - 1 - i] = numbers[i];
			numbers[i] = temp;
			i = i + 1;
		}
	//print array
	i = 0;
	while (i<10)
	{
		printf("%d ", numbers[i] );
		i = i + 1;
	}
}
