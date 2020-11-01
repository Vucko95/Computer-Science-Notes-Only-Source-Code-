#include <stdio.h>

int main(){
	int c;
	int num_lines = 0;
	int num_characters = 0;
	c = getchar();
	while (c != EOF) {
	    num_characters++;	
	    if (c == '\n') num_lines++;
	    c = getchar();
	}
	if (num_characters != 0) {
	    printf("There are %d characters \n", num_characters);
	    printf("There are %d lines \n", num_lines);
	}
	else
	    printf("No data to count \n");
}