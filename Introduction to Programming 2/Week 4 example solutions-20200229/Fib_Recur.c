/* Recursive Fibonacci */

#include<stdio.h>
 
int f(int);
 
main()
{
   int n, i = 0, c;
 
   printf("Enter the number of terms\n");
   scanf("%d",&n);
 
   printf("First %d terms of Fibonacci series are :-\n",n);
 
   for ( c = 1 ; c <= n ; c++ )
   {
      printf("%d\n", f(i));
      i++; 
   }
 
   return 0;
}
 
int f(int n)
{
   if ( n == 0 )
      return 0;
   else if ( n == 1 )
      return 1;
   else
      return ( f(n-1) + f(n-2) );
} 