#include <stdio.h>
#include <stdlib.h>

#ifndef _STACK_H
#define _STACK_H

struct stack
{
    unsigned int count;
    char array[10];
};

void pop(struct stack *);

void push(struct stack *, char item);

void empty(struct stack *);

void isEmpty(struct stack *);

#endif