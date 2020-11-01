//cast.c
#include <stdio.h>

int main() {
	float f = 10.0;
	int i = (int) f;
	printf("i=%d\n", i);
	
	i = 12;
	f = (float) i;
	printf("f=%.2f\n", f);
}
