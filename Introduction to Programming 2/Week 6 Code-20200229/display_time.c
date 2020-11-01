#include <stdio.h>

typedef struct {
   int hour;
   int minute;
   int second;
} Time;

void display_time( Time time );

int main() {
   Time now, next;
   printf("Please enter the time now (h m s):");
   scanf("%d%d%d", &now.hour, &now.minute, &now.second);

   next.hour = (now.hour + 1) % 24;
   next.minute = now.minute; next.second = now.second;

   printf("The time in 1 hour will be: ");
   display_time( next );
   putchar( '\n' );
}

void display_time( Time time ) {
   printf( "%02d:%02d:%02d", time.hour, time.minute, time.second );
}