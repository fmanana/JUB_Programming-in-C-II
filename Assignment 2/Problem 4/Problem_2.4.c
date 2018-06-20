/*
  JTSK-320112
  a2 p4.c
  Fezile Manana
  f.manana@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

//Function to read inputs. Parametres include the zize of each
//sub array and the matrix
void read_in(unsigned int x, unsigned int y, unsigned int z, int ***A)
{
  int i, j, k;

  for(i = 0; i < x; i++)
    {
      for(j = 0; j < y; j++)
	{
	  for(k = 0; k < z; k++)
	    {
	      scanf("%d", &A[i][j][k]);
	    }
	}
    }
}

//Function for printing the elements
void print(unsigned int x, unsigned int y, unsigned int z, int ***A)
{
  int i, j, k;

  for(j = 0; j < y; j++)
    {
      for(i = 0; i < x; i++)
	{
	  for(k = 0; k < z; k++)
	    {
	      //If statements for format purposes
	      if(i == 0 && k == 0)
		printf("Section %d:\n", j + 1);
	      printf("%d ", A[i][j][k]);
	      if(k == z - 1)
		printf("\n");
	    }
	}
    }
}
int main()
{
  int ***A;
  unsigned int x, y, z;
  int i, j;
  int ***ptr;

  scanf("%u", &x);
  scanf("%u", &y);
  scanf("%u", &z);

  A = (int ***) malloc(sizeof(int**) * x);
  //Pointer is used in function calls
  ptr = A;
  //Dynamically allocating 3D array
  for(i = 0; i < x; i++)
    {
      A[i] = (int **) malloc(sizeof(int*) * y);
      for(j = 0; j < y; j++)
	{
	  A[i][j] = (int *) malloc(sizeof(int) * z); 
	}
    }
  //Function calls
  read_in(x, y, z, ptr);
  print(x, y, z, ptr);
  
  for(i = 0; i < x; i++)
    {
      for(j = 0; j < y; j++)
	{
	  free(A[i][j]);
	}
       free(A[i]);
    }
  free(A);
  
  return 0;
}