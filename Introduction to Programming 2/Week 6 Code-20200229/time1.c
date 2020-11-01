#include <stdio.h>

struct Time {
   int hour;
   int minute;
   int second;
};

int main() {

   printf( "Size of int is %lu\n", sizeof( int ) );
   printf( "Size of Time is %lu\n", sizeof( struct Time ) );
}