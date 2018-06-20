/*
   JTSK-320112
   a2 p1.c
   Fezile Manana
   f.manana@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  int n, i;
  double *arr;

  scanf("%d", &n);
  arr = (double*) malloc(sizeof(double) * n);
  if(arr == NULL)
    exit(1);
  
  for(i = 0; i < n; i++)
    {
      scanf("%lf", &arr[i]);
    }
  
  double* ptr = &arr[0];
  for(i = 0; i < n; i++)
    {
      if(arr[i] - (int)(arr[i]) == 0)
	{
	  //difference between the pointer and the current element
	  //gives the number of elements
 	  printf("Before the first integer: %ld elements\n", ptr-arr);
  	  break;
	}
      ptr++;
    }

  free(arr);
  return 0;
}