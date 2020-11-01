/* Factorial using recursion */

#include<stdio.h>
 
long factorial(int);
 
int main()
{
  int number;
  long fact;
 
  printf("Enter an integer to find its factorial\n");
  scanf("%d", &number); 
 
  if (number < 0)
    printf("Factorial of negative integers is not defined.\n");
  else
  {
    fact = factorial(number);
    printf("%d! = %ld\n", number, fact);
  }
 
  return 0;
}
 
long factorial(int n)
{
  if (n == 0)
    return 1;
  else
    return(n * factorial(n-1));
}