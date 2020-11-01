#include <stdio.h>

int main() {
   int mat[3][3]; // matrix can have max 3 rows and 3 cols
   int i, j;
   printf("Enter the matrix elements row-wise :- \n");
   for ( i = 0; i < 3; i++ ) { // outer loop iterates over each row
      for ( j = 0; j < 3; j++ ) { // inter loop iteartes over each column
         printf("mat[ %d ][ %d ] : ", i, j);
         scanf("%d", &mat[i][j]); /* i -> row no. and j -> col no. */
      }
   }
   /* display the matrix */
   printf("You have entered the matrix :- \n");
   for ( i = 0; i < 3; i++ ) {
      for ( j = 0; j < 3; j++ ) {
         printf("%d  ", mat[i][j]);
      }
      printf("\n");
   }
   return 0;
}