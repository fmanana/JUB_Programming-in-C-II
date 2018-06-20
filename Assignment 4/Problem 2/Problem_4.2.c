/*
  JTSK-320112
  a4 p2.c
  Fezile Manana
  f.manana@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void lower_case(char string[])
{
  int i;
  for(i = 0; string[i] != '\0'; i++)
    {
      if(string[i] >= 'A' || string[i] <= 'Z')
	{
	  printf("%c", tolower(string[i]));
        }
      else
	{
          printf("%c", string[i]);
        }
    }
}

void upper_case(char string[])
{
  int i;
  for(i = 0; string[i] != '\0'; i++)
    {
      if(string[i] >= 'a' || string[i] <= 'z')
	{
	  printf("%c", toupper(string[i]));
        }
      else
	{
          printf("%c", string[i]);
        }
    }
}

//Switching between lower and upper case letters
void lower2upper(char string[])
{
  int i;
  for(i = 0; string[i] != '\0'; i++)
    {
      if(islower(string[i]))
	{
	  printf("%c", toupper(string[i]));
        }
      else if(isupper(string[i]))
	{
	  printf("%c",tolower(string[i]));
	}
      else if(string[i] == ' ')
	{
	  printf(" ");
	}
    }
    	printf("\n");
}

void terminate(char string[])
{
    exit(0);
}

int main()
{
    char string[100];
    char c;
    fgets(string, 100, stdin);
    
    void (*func_array[4])(char string[]) = {&upper_case, &lower_case, &lower2upper, &terminate};

    while(1)
      {
	scanf("%c", &c);
	getchar();
	//Translating c to an int by force cast and ASCII numbers
	func_array[(int)(c) - 'a'](string);
      }

    return 0;
}