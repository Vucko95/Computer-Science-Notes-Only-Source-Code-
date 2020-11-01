//realloc.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   char *str;
   // Initial memory allocation
   str = malloc(6 * sizeof(char)); // don't forget 1 for \n
   if (str == NULL)
   {
		printf("ERROR: Out of memory\n");
		return 1;
   }
   strcpy(str, "hello");
   printf("String = %s,  Address = %p\n", str, &str);
   // Reallocating memory 
   str = realloc(str, 13 * sizeof(char));
   if (str == NULL)
   {
		printf("ERROR: Out of memory\n");
		return 1;
   }
   strcat(str, " world!");
   printf("String = %s,  Address = %p\n", str, &str);
   free(str);
}