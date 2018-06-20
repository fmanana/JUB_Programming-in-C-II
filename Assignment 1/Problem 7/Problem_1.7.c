/*
   JTSK-320112
   a1 p7.c
   Fezile Manana
   f.manana@jacobs-university.de
*/

#include <stdio.h>

unsigned int setswitchbits(unsigned int x, unsigned int set, unsigned int tog)
{
  x |= (1 << set);
  x ^= (1 << tog);

  return x;
}

int main()
{
  unsigned int var, set, toggle;
  scanf("%u", &var);
  scanf("%u", &set);
  scanf("%u", &toggle);

  unsigned int new_var;
  new_var = setswitchbits(var, set, toggle);
  int bit, i;
  printf("The binary representation is: ");
  for(i = 15; i >= 0; i--)
    {
      bit = 2;
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
  printf("\nAfter setting and switching: ");
  for(i = 15; i >= 0; i--)
    {
      bit = 2;
      if(new_var & 1 << i)
	{
	  bit = 1;
	  printf("%d", bit);
	}
      else if(new_var ^ 1 << i)
	{
	  bit = 0;
	  printf("%d", bit);
	}
    }
  printf("\n");
  return 0;
}