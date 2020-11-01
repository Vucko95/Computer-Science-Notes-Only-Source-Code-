#include <stdio.h>
#include <stdlib.h>


typedef struct {
	int hour;
    int minute;
	int second;
}Time;

typedef struct {
	int year;
	int month;
	int day;
	Time time;
}Date;

//void add_month( ExpiryDate *expiry );
	
int main() {
   int year, month, day;
   printf("%s\n", "Enter a year, month and day:");
   scanf("%d%d%d", &year, &month, &day);
   Date date;
   date.year = year;
   date.month = month;
   date.day = day;
   
   int hr, min, sec;
   printf("%s\n", "Enter an hour, minute, and second:");
   scanf("%d%d%d", &hr, &min, &sec);
   date.time.hour = hr;
   date.time.minute = min;
   date.time.second = sec;
   
   printf( "The meeting is on %02d/%02d/%d at %02d:%02d:%02d\n", date.day, date.month, date.year, date.time.hour, date.time.minute, date.time.second);
}