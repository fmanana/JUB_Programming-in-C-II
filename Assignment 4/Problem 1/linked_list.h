/*
  JTSK-320112
  a4 p1.c
  Fezile Manana
  f.manana@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

#ifndef LINKED_LIST
#define LINKED_LIST
struct list
  {
    char letter;
    struct list *next;
  };

struct list* push_back(struct list*, char);

struct list* push_front(struct list*, char);

void empty_list(struct list*);

struct list* rm_first(struct list*);

void print(struct list*);

#endif