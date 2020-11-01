#include <stdio.h>
#define LENGTH 5

int main() {
   int arr[LENGTH] = { 0, 0, 0, 0, 0 };
   int i = 0;
   for (i = 0; i < LENGTH; i++ ) {
      printf( "%d; ", arr[ i ] );
   }
   printf("\n");
}
