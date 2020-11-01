/* 
ATLAS.c     brett becker    12/09/2005

*/

#include <stdio.h>
#include <stdlib.h>
#include <cblas.h>
#include <math.h>

void initMat( int M, int N, double mat[], double val )
{
  int     i, j;
  for (i= 0; i< M; i++)
    for (j= 0; j< N; j++)
      mat[i*N+j] = val;
}

int main()
{

  int numreps = 5;
  double *A, *B, *C;
  int N = 1000;
  printf ("Please enter matrix dimension n : "); 
  scanf("%d", &N);
  int i;

  //allocate and initialize arrays
  A = malloc (N*N*sizeof(double));
  B = malloc (N*N*sizeof(double));
  C = malloc (N*N*sizeof(double));
  if (!A || !B || !C)
    {
      printf( "Out of memory, reduce N value.\n");
      exit(-1);
    }
  initMat(N, N, A, rand());
  initMat(N, N, B, rand());
      
  //multiply
  printf("Multiply matrices %d times...\n", numreps);
  for (i=0; i<numreps; i++)
    {
      ATL_dgemm(CblasNoTrans, CblasNoTrans, N, N, N, 1.0, A, N, B, N, 0.0, C, N);
    }
  printf("Done ...\n");

  free(A); 
  free(B); 
  free(C);
 
  return 0;
}
