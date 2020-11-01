#include <stdio.h>

int main()
{
	FILE *fp;
	int c;
	
	fp = fopen("display.c", "r"); // open file
	while ( (c = getc(fp)) != EOF)
	{
		putchar(c); // print to standard output
	}
	fclose(fp); // close the file
}
