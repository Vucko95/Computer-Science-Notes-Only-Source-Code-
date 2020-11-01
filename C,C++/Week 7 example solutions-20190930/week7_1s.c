#include <stdio.h>

struct ExpiryDate {
	int year;
	int month;
};
	
int main() {
   int y, m;
   struct ExpiryDate expiry;  
   printf("%s\n", "Enter a month and year");
   scanf("%d%d", &m, &y);
   expiry.year = y;
   expiry.month = m;
   printf( "The expiry date is %d/%d\n", expiry.month, expiry.year);
}