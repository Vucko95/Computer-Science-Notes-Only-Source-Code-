#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	int value;
	
	fp = fopen( "data.txt", "r" ); /* open for reading */

	if ( fp == NULL ) /* check does file exist etc */ 
	{ 
		printf( "Cannot open data.txt for reading \n" );
		exit(1); /* terminate program THERE IS A BETTER WAY TO DO THIS! */
	}

	fscanf( fp, "%d", &value );
	while ( !feof(fp) ) {
		printf( "%d | ", value );
		for( int i = 0; i < value; i++ ) {
			printf( "*" ); // could also use putchar( '*' );
		}
		printf( "\n" );
		fscanf( fp, "%d", &value );
	}
	fclose(fp);
}
