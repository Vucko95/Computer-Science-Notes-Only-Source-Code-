#include <stdio.h>

int main() {
	int c;
	int x = 0;
	int y = 0;
	c = getchar();
	while (c != EOF) {
	    x++;	
	    if (c == '\n') y++;
	    c = getchar();
	}
	if (x != 0) {
	    printf("x = %d \n", x);
	    printf("y = %d \n", y);
	}
	else
	    printf("No result \n");
}