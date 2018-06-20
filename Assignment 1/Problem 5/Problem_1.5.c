/*
   JTSK-320112
   a1 p5.c
   Fezile Manana
   f.manana@jacobs-university.de
*/

#include <stdio.h>

int main()
{
  unsigned int var;

  scanf("%u", &var);

  printf("The backwards binary representation is: ");
  int bit,i, j;
  for(i = 0; i < 16 ; i++)
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
	  //If a zero is found, the intis checked
	  //for a 1 starting from the 16th bit
	  for(j = 15; j > i; j--)
	    {
	      //If a 1 is found then 0 is printed and the
	      //loop breaks to check the next bit
	      if(var & 1 << j)
		{
		  printf("%d", bit);
		  break;
		}
	     }
	}
    }
  printf("\n");
  return 0;
}