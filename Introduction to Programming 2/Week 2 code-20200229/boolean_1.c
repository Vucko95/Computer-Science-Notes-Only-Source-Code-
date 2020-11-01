#include <stdio.h>
int main() {
   int total = 0;
   int finished = 0;
   while( !finished ) {
      printf( "Enter a number: " );
      int num;
      scanf( "%d", &num );
      if ( num < 0 )
         finished = 1;
      else
         total += num;
   }
   printf( "Total is: %d\n", total );
}
