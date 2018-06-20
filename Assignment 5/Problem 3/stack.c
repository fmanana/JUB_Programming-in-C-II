/*
    JTSK-320112
    a5 p3.c
    Fezile Manana
    f.manana@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void pop(Stack *s, char item[15])
{
  if(s->count == -1)
    {
      printf("Popping Stack Underflow\n");
      return;
    }
	strcpy(item, s->array[s->count]);
    s->count--;
}

void push(Stack *s, char item[15])
{
  if(s->count == 9)
    {
      printf("Pushing Stack Overflow\n");
      return;
    }

  s->count++;
  strcpy(s->array[s->count], item);
}