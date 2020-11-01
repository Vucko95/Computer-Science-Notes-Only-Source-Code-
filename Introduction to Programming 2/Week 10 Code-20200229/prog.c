#include <stdio.h>
#include <stdlib.h>

int main()
{
	
	FILE *fp1, *fp2;
	
	fp1 = fopen( "prog.c", "r" ); /* open for reading */
	fp2 = fopen( "prog.old", "w" ) ; /* open for writing */

	if ( fp1 == NULL ) /* check does file exist etc */	
	{ 
		printf( "Cannot open prog.c for reading \n" );
		exit(1); /* terminate program THERE IS A BETTER WAY TO DO THIS!*/
	}
	else if ( fp2 == NULL )
	{ 
		printf( "Cannot open prog.old for writing\n" );
		exit(1); /* terminate program THERE IS A BETTER WAY TO DO THIS!*/
	}

	char c = getc( fp1 ) ; /* read from prog.c */

	while ( c != EOF )
	{ 
		putc( c, fp2 ); /* copy to prog.old */ 
		c = getc( fp1 ); /* read next char */
	}
	fclose(fp1);
	fclose(fp2);

	printf( "Files successfully copied.\n" );

}
