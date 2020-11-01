#include <stdio.h>
double sum_par (int n, double *a) {
	double total = 0.0;
	int i;
	for (i=0; i<=n; i++) total = total + *(a+i);
	return total;
}

int main () {
	double A[ 5 ] = {1, 2, 3, 4, 5};
	double B[ 7 ] = {7, 6, 5, 4, 3, 2, 1};
	double sum;
	sum = sum_par( 4, A );
	printf (" sum = %f\n", sum);
	sum = sum_par( 5, &B[0] );
	printf (" sum = %f\n", sum);
}
