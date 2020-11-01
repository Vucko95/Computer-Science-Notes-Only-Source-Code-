#include <stdio.h>

typedef struct {
	int year;
	int month;
}ExpiryDate;

void add_month( ExpiryDate *expiry );
	
int main() {
   int y, m;
   ExpiryDate expiry;  
   printf("%s\n", "Enter a month and year");
   scanf("%d%d", &m, &y);
   expiry.year = y;
   expiry.month = m;
   printf( "The expiry date is %d/%d\n", expiry.month, expiry.year);
   add_month(&expiry);
   printf( "The new expiry date is %d/%d\n", expiry.month, expiry.year);
}

void add_month( ExpiryDate *exp ) {
   if(exp->month < 12){
	   exp->month = exp->month+1;
   }
   else{
	   exp->month = 1;
	   exp->year = exp->year+1;
   }
}