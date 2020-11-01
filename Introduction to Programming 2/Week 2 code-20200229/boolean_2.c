#include <stdio.h>
#include <stdbool.h>
int main() {
   int total = 0;
   bool finished = false;
   while( !finished ) {
      printf( "Enter a number: " );
      int num;
      scanf( "%d", &num );
      if ( num < 0 )
         finished = true;
      else
         total += num;
   }
   printf( "Total is: %d\n", total );
}
