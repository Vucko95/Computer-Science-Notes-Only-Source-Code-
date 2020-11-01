#include<stdio.h>
#include <stdlib.h>

void print_arr(int *x, int s);
void fill_array(int *x, int begin, int end);

int main()
{
	int my_size = 5;
	int *arr;
	arr = malloc(sizeof(int) * my_size);

	if (arr == NULL)
	{
		printf("ERROR: Out of memory\n");
		return 1;
	}
	
	fill_array(arr, 0, my_size);
	print_arr(arr, my_size);
	
	//resize array!
	int new_size = 10;
	arr = realloc(arr, sizeof(int) * new_size);

	fill_array(arr, my_size, new_size);
	print_arr(arr, new_size);

	
	free(arr);
}

void print_arr(int *x, int s){
	int i = 0;
	while(i < s){
		printf("%d ", x[i]);
		i++;
	}
	printf("\n");
}

void fill_array(int *x, int begin, int s){
	int i = begin;
	while (i < s){ 
		x[i] = i;
		i++;
	}
}