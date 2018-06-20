#include <stdio.h>
#include <stdlib.h>

struct list
  {
    char letter;
    struct list *next;
  };

struct list* push_back(struct list* my_list, char elem);

struct list* push_front(struct list* my_list, char elem);

void empty_list(struct list* my_list);

struct list* rm_first(struct list* my_list);

void print(struct list *my_list);