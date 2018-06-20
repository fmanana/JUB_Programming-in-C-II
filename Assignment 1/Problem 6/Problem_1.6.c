/*
   JTSK-320112
   a1 p6.c
   Fezile Manana
   f.manana@jacobs-university.de
*/

#include <stdio.h>

int main()
{
  unsigned int var;

  scanf("%u", &var);

  printf("The binary representation is: ");
  int bit,i;
  for(i = 15; i >= 0 ; i--)
    {
      bit = 2;
      //If bit mask is true then print
      //the value of bit
      if(var & 1 << i)
	{
	  bit = 1;
	  printf("%d", bit);
	}
      else if(var ^ 1 << i)
	{
	  bit = 0;
	  printf("%d", bit);
	}
    }
  printf("\n");
  return 0;
}