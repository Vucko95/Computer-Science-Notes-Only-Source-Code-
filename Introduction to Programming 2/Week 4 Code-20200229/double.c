/* File: double.c */
#include <stdio.h>

void twice( int n, int *arr) {
	int i;
	for (i=0; i<n; i++){
		*(arr+i) *= 2;
	}
}

int main () {
	int arr[10];
	int n = sizeof(arr)/sizeof(arr[0]); 
	int i;
	for (i=0; i<n; i++){
		arr[i] = i;
		printf("%d, ", arr[i]);
	}
	printf("\n");
	twice(n, arr);
	for (i=0; i<n; i++){
		printf("%d, ", arr[i]);
	}
}