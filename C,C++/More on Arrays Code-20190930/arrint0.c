#include <stdio.h>
#define LENGTH 20

int main() {
   int arr[LENGTH];
   int i = 0;
   for (i = 0; i < LENGTH; i++ ) {
      printf( "%d; ", arr[ i ] );
   }
   printf("\n");
}
