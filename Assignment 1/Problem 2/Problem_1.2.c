/*
  JTSK-320112
  a1 p2.c
  Fezile Manana
  f.manana@jacobs-university.de
*/

#include <stdio.h>

#define BIT(A) ((A&4) > 0 ? 1 : 0)


int main()
{
  char str;

  scanf("%c", &str);
  printf("The decimal representation is: %d\n", str);
  printf("The third least significant bit is: %d\n", BIT(str));

  return 0;
}