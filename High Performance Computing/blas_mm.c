#include <stdio.h>
#include <stdlib.h>
#include <cblas.h>

int main(void)
{
   double ALPHA=1.0, BETA=1.0;
   int n;
   double** A;
   double** B;
   double** C; 
   int numreps = 5;
   
   int i=0;
   int j=0;

   printf ("Please enter matrix dimension n : "); 
   scanf("%d", &n);
   

   // allocate memory for the matrices
   
   // note that for each matrix there
   // are only two memory allocations
   
   ///////////////////// Matrix A //////////////////////////
   A =(double **)malloc(n*sizeof(double *));
	A[0] = (double *)malloc(n*n*sizeof(double));
	if(!A)
    {
      printf("memory failed \n");
      exit(1);
    }
	for(i=1; i<n; i++)
    {
      A[i] = A[0]+i*n;
      if (!A[i])
	  {
		printf("memory failed \n");
		exit(1);
	  }
    }
     ///////////////////// Matrix B //////////////////////////
  
  B =(double **)malloc(n*sizeof(double *));
  B[0] = (double *)malloc(n*n*sizeof(double));
  if(!B)
    {
      printf("memory failed \n");
      exit(1);
    }
  for(i=1; i<n; i++)
    {
      B[i] = B[0]+i*n;
      if (!B[i])
	{
	  printf("memory failed \n");
	  exit(1);
	}
    }
	
	///////////////////// Matrix C //////////////////////////
  C =(double **)malloc(n*sizeof(double *));
  C[0] = (double *)malloc(n*n*sizeof(double));
  if(!C)
    {
      printf("memory failed \n");
      exit(1);
    }
  for(i=1; i<n; i++)
    {
      C[i] = C[0]+i*n;
      if (!C[i])
	{
	  printf("memory failed \n");
	  exit(1);
	}
    } 

      
	
   // initialize the matrices
   // we can also create random matrices using the rand() method from the math.h library
   for(i=0; i<n; i++)
   {
		for(j=0; j<n; j++)
	   {
		  A[i][j] = 1;
		  B[i][j] = 2;
	   }
   }
	
  //multuply matrices
  printf("Multiply matrices %d times...\n", numreps);
  for (i=0; i<numreps; i++)
         cblas_dgemm( CblasRowMajor,  CblasTrans, CblasNoTrans, n, n, n,
                   ALPHA, A[0], n, B[0], n, BETA, C[0], n );
  printf("Done ...\n");
    //deallocate memory
   free(A[0]);
   free(A);
   free(B[0]);
   free(B);
   free(C[0]);
   free(C);

   
   return 0;
}

   

   



