/* Factorial using loop */

#include <stdio.h>
 
int main()
{
  int c, number;
  long fact = 1;
 
  printf("Enter a number to calculate its factorial\n");
  scanf("%d", &number);
 
  for (c = 1; c <= number; c++)
    fact = fact * c;
 
  printf("%d! = %ld\n", number, fact);
 
  return 0;
}