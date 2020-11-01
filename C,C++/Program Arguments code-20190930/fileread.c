#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
   if ( argc != 2 ) {
      printf( "No filename\n" );
      exit(EXIT_FAILURE);
   }

   FILE *fp = fopen(argv[1], "r");
   if ( fp == NULL ) {
      printf("[%s] not opened\n", argv[1]);
      exit(EXIT_FAILURE);
   }  

   int c = getc( fp );
   while( c != EOF ) {
      putchar( c );
      c = getc( fp );
   }

   fclose( fp );
}
