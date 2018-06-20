/*
  JTSK-320112
  a1 p1.c
  Fezile Manana
  f.manana@jacobs-university.de
*/

#include <stdio.h>

#define CYCLE(A, B, C, D) {A help=B;B=D;D=C;C=help;}

int main()
{
  int arr[3];
  double arr2[3];
  int i;

  for(i = 0; i < 3; i++)
    {
      scanf("%d", &arr[i]);
    }
  for(i = 0; i < 3; i++)
    {
      scanf("%lf", &arr2[i]);
    }
  CYCLE(int, arr[0], arr[1], arr[2])
  CYCLE(double, arr2[0], arr2[1], arr2[2])

    printf("After the permutation:\n");
  
    for(i = 0; i < 3; i++)
      {
	printf("%d\n", arr[i]);
      }
    
    for(i = 0; i < 3; i++)
      {
	printf("%.5lf\n", arr2[i]);
      }
    return 0;
}