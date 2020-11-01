#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   printf( "Enter a filename: "); // prompt user for filename
   char* str = malloc(80*sizeof(char)); //string for filename  
   fgets (str, 80*sizeof(str), stdin); //get filename
   str[strlen(str)-1]='\0'; //replace trailing \n that fgets grabs with \0
   FILE *fp = fopen( str, "r" );

   if ( fp == NULL ) /* check does file exist etc */
   { 
      printf( "Cannot open file for reading \n" );
      exit(EXIT_FAILURE); /* terminate program */
   }

   int c = getc( fp );
   while( c != EOF ) {
      putchar( c );
      c = getc( fp );
   }
   fclose( fp );
}
