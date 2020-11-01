#include <stdio.h>

typedef struct {
   int hour;
   int minute;
   int second;
} Time;

void display_time( Time time );
void add_hour( Time time );

int main() {
   Time t;
   printf("Please enter the time now (h m s):");
   scanf("%d%d%d", &t.hour, &t.minute, &t.second);

   add_hour( t ); // this won't work: t is passed by value and cannot be changed

   printf("The time in 1 hour will be: ");
   display_time( t );
   putchar( '\n' );
}

void display_time( Time time ) {
   printf( "%02d:%02d:%02d", time.hour, time.minute, time.second );
}

void add_hour( Time time ) {
   time.hour = ( time.hour + 1 ) % 24;
}