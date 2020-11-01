#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *in, *even, *odd;
	int value, i;
	
	in = fopen( "numbers.txt", "r" ); /* open for reading */
	even = fopen( "even.txt", "w" ); /* open for reading */
	odd = fopen( "odd.txt", "w" ); /* open for reading */
	
	if ( in == NULL ) /* check does file exist etc */ 
	{ 
		printf( "Cannot open numbers.txt for reading \n" );
		exit(0); /* terminate program */
	}
	if ( even == NULL ) /* check does file exist etc */ 
	{ 
		printf( "Cannot open even.txt for writing \n" );
		exit(0); /* terminate program */
	}
	if ( odd == NULL ) /* check does file exist etc */ 
	{ 
		printf( "Cannot open odd.txt for writing \n" );
		exit(0); /* terminate program */
	}
	
	fscanf( in, "%d", &value );
	do {
		if( value % 2 == 0){
			//value is even, write to even.txt
			fprintf(even, "%d ", value);
		}
		else{
			//value is odd, write to odd.txt
			fprintf(odd, "%d ", value);
		}
		fscanf( in, "%d", &value );
	}while ( !feof(in) );

	fclose(in);
	fclose(odd);
	fclose(even);
}
