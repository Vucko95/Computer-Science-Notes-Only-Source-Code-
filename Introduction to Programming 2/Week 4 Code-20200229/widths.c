/*file widths.c*/
#include <stdio.h>
int main() {
   int int_arr[5];
   char char_arr[5];

   printf( "1st int addr: %p\n", int_arr );
   printf( "2nd int addr: %p\n", (int_arr + 1));
   printf( "1st char addr: %p\n", char_arr );
   printf( "2nd char addr: %p\n", (char_arr + 1));
}
