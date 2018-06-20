/*
   JTSK-320112
   a1 p4.c
   Fezile Manana
   f.manana@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

#define INTERMEDIATE
int main()
{
  int **A;
  int **B;
  int **C;
  int n;
  
  scanf("%d", &n);
  
  int i, j;
  //Declaring 2D arrays
  A = (int **) malloc(sizeof(int *) * n);
  B = (int **) malloc(sizeof(int *) * n);
  C = (int **) malloc(sizeof(int *) * n);
  for(i = 0; i < n; i++)
    {
      A[i] = (int *) malloc(sizeof(int) * n);
      B[i] = (int *) malloc(sizeof(int) * n);
      C[i] = (int *) malloc(sizeof(int) * n);
    }

  //Reading inputs for matrix A
  for(i = 0; i < n; i++)
    {
      for(j = 0; j < n; j++)
	{
	  scanf("%d", &A[i][j]);
	}
    }
  //Reading inputs for matrix B
  for(i = 0; i < n; i++)
    {
      for(j = 0; j < n; j++)
	{
	  scanf("%d", &B[i][j]);
	}
    }
  //Computing output matrix(C)
  int k;
  for(i = 0; i < n; i++)
    {
      for(j = 0; j < n; j++)
	{
	  C[i][j] = 0;
	  for(k = 0; k < n; k++)
	    C[i][j] =C[i][j] + A[i][k]*B[k][j];
	}
    }

#ifdef INTERMEDIATE
  printf("The intermediate product values are:\n");
  for(i = 0; i < n; i++)
    {
      for(j = 0; j < n; j++)
	{
	  for(k = 0; k < n; k++)
	  printf("%d\n", (A[i][k]*B[k][j]));
	}
    }
#endif

  printf("The product of the matrices is:\n");

  for(i = 0; i < n; i++)
    {
      for(j = 0; j < n; j++)
	{
	  printf("%d ", C[i][j]);
	  //If statements purely for formatting purposes
	  if(j == n - 1 && i != j)
	    {
	      printf("\n");
	    }
	}
    }
  printf("\n");
  
  for(i = 0; i < n; i++)
    free(A[i]);
  free(A);
  for(i = 0; i < n; i++)
    free(B[i]);
  free(B);
  for(i = 0; i < n; i++)
    free(C[i]);
  free(C);

  return 0;
}