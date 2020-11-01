#include <stdio.h>
#include <stdlib.h>

int main()
{
	int chars = 0;
	int lines = 0;
	int c = getchar();
	if (c == EOF){
		printf("File is empty!\n");
	}
	else{
		while (c != EOF)
		{
			if(c == '\n'){
				lines++;
			}
			else if (c != '\r'){
				chars++;
			}
			c = getchar();
		}
		printf("number of chars = %d\n", chars);
		printf("number of lines = %d\n", lines);
	}
}
