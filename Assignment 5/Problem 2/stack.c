/*
    JTSK-320112
    a5 p2.c
    Fezile Manana
    f.manana@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void pop(struct stack *s)
{
  if(s->count == 0)
    {
      printf("Popping Stack Underflow\n");
      return;
    }

    s->count--;
  char temp = s->array[s->count];
  printf("%c", temp);

}

void push(struct stack *s, char item)
{
  if(s->count == 10)
    {
      printf("Pushing Stack Overflow\n");
      return;
    }

  
  s->array[s->count] = item;
  s->count++;
}

void empty(struct stack *s)
{
  int i;

  printf("Emptying Stack ");
  for(i = s->count-1; i >= 0; i--)
  {
    printf("%c ", s->array[i]);
  }
  printf("\n");

  s->count = 0;
}

void isEmpty(struct stack *s)
{
  if(s->count == 0)
    printf("The stack is empty\n");
  else
    printf("The stack is not empty\n");
}