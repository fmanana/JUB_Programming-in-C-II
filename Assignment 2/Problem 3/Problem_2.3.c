/*
  JTSK-320112
  a2 p3.c
  Fezile Manana
  f.manana@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

void read_input(int n, int **A, int **B)
{
  int i, j;
  for(i = 0; i < n; i++)
    {
      for(j = 0; j < n; j++)
	{
	  scanf("%d", &A[i][j]);
	}
    }
  for(i = 0; i < n; i++)
    {
      for(j = 0; j < n; j++)
	{
	  scanf("%d", &B[i][j]);
	}
    }
}

void print(int n, int **A, int **B)
{
  int i, j;
  
  printf("Matrix A:\n");
  for(i = 0; i < n; i++)
    {
      for(j = 0; j < n; j++)
	{
	  printf("%d ", A[i][j]);
	  //If statements purely for formatting purposes
	  if(j == n - 1 && i != j)
	    {
	      printf("\n");
	    }
	}
    }
  
  printf("\nMatrix B:\n");
  for(i = 0; i < n; i++)
    {
      for(j = 0; j < n; j++)
	{
	  printf("%d ", B[i][j]);
	  //If statements purely for formatting purposes
	  if(j == n - 1 && i != j)
	    {
	      printf("\n");
	    }
	}
    }
  printf("\n");
}

/*Compare function: first loop checks if elements X[i][i]
  match(leading diagonal). If they match checks to see if
  X[i][j] match(secondary diagonal. Sets an int to 1 if all checks
  are true, else sets to 0.
*/
void compare(int n, int **A, int **B)
{
  int i, j;
  int result = 2;
  for(i = 0; i < n; i++)
    {
      if(A[i][i] == B[i][i])
	{
	  for(j = n - 1; j >= 0; j--)
	    {
	      if(A[i][j] == B[i][j])
		  result = 1;
	      else
		  result = 0;
	    }
	}
    }
  if(result == 1)
      printf("The comparison result: identical\n");
  else
    printf("The comparison result: NOT identical\n");
}

int main()
{
  int n;
  int **A, **B;
  int **ptr_A;
  int **ptr_B;
  
  scanf("%d", &n);
  A = (int **) malloc(sizeof(int*) * n);
  B = (int **) malloc(sizeof(int*) * n);

  //Set pointers to matrices
  ptr_A = A;
  ptr_B = B;
  
  int i;
  for(i = 0; i < n; i++)
    {
      A[i] = (int *) malloc(sizeof(int) * n);
      B[i] = (int *) malloc(sizeof(int) * n);
    }
  
  //function calls
  read_input(n, ptr_A, ptr_B);
  print(n, ptr_A, ptr_B);
  compare(n, ptr_A, ptr_B);

  for(i = 0; i < n; i++)
    free(A[i]);
  free(A);
  for(i = 0; i < n; i++)
    free(B[i]);
  free(B);
  
  return 0;
}