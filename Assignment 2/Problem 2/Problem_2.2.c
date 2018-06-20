/*
   JTSK-320112
   a2 p2.c
   Fezile Manana
   f.manana@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
  char str[100];
  char *substr;
  int from, until;
  int error = 0;
  fgets(str, 100, stdin);
  scanf("%d", &from);
  scanf("%d", &until);
  //Performing checks
  if(from < 0)
    {
      printf("The first position is negative!\n");
      error = 1;
    }
  if(until > strlen(str)-2)
    {
      printf("The second position is higher than the last position!\n");
      error = 2;
    }
  if(error != 0)
    {
      return 1;
    }
  else{
  //Dynamic allocation of substr
  substr = (char*) malloc(sizeof(char) * (until - from + 1));
  int i, j = from;
  for(i = 0; i <= (until-from); i++)
    {
      substr[i] = str[j];
      j++;	
    }
  printf("Result of substring(%d, %d): ", from, until);
  for(i = 0; i <= (until-from) ; i++)
    printf("%c", substr[i]);

  printf("\n");
  }
  
  free(substr);
  return 0;
}