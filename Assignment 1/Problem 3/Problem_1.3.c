/*
  JTSK-320112
  a1 p3.c
  Fezile Manana
  f.manana@jacobs-university.de
*/


#include <stdio.h>

#define SUM(A, B, C) ((A) + (B) + (C))
//We need two max macros. The first for A and B,
//the second for the max of A and B with C
#define MAX1(A, B) ((A) > (B) ? (A) : (B))
#define MAX(A, B, C) MAX1(MAX1(A, B), C)
//Same method for min macro
#define MIN1(A, B) ((A) < (B) ? (A) : (B))
#define MIN(A, B, C) MIN1(MIN1(A, B), C)
#define EXPR(A, B, C) (SUM(A, B, C) + MAX(A, B, C))/(float)MIN(A, B, C)
//Min macro is casted to a float in order to yield
//a floating point in the expression

int main()
{
  int arr[3];
  int i;
  for(i = 0; i < 3; i++)
    {
      scanf("%d", &arr[i]);
    }
  float value = EXPR(arr[0], arr[1], arr[2]);
  printf("The value of the expression is: %.6f\n", value);

  return 0;
}