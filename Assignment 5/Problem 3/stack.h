#include <stdio.h>
#include <stdlib.h>

#ifndef _STACK_H
#define _STACK_H

typedef struct
{
    int count;
    char array[10][15];
}Stack;

void pop(Stack *, char item[15]);

void push(Stack *, char item[15]);

#endif