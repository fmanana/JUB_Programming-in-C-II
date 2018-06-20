/*
  JTSK-320112
  a3_p2.c
  Fezile Manana
  f.manana@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

struct list
  {
    char letter;
    struct list *next;
  };

struct list* push_back(struct list* my_list, char elem)
{
  struct list *cursor, *new;
  cursor = my_list;
  new = (struct list *) malloc(sizeof(struct list));
  if(new == NULL)
    return my_list;

  new->letter = elem;
  new->next = NULL;
  if(my_list == NULL)
    return new;
  while(cursor->next != NULL)
    cursor = cursor->next;
  cursor->next = new;
  return my_list;
}

struct list* push_front(struct list* my_list, char elem)
{
  struct list *new;
  new = (struct list *) malloc(sizeof(struct list));
  if(new == NULL)
    {
      return my_list;
    }
  new->letter = elem;
  new->next = my_list;
  return new;
}

void empty_list(struct list* my_list)
{
  struct list *next_elem;
  while(my_list != NULL)
    {
      next_elem = my_list->next;
      free(my_list);
      my_list = next_elem;
    }
}

struct list* rm_first(struct list* my_list)
{
  struct list *cursor;
  if(my_list == NULL)
    return my_list;
  cursor = my_list->next;
  free(my_list);
  my_list = cursor;
  return cursor;
}

void print(struct list *my_list)
{
  struct list *ptr;
  for(ptr = my_list; ptr; ptr = ptr->next)
    {
      printf("%c ", ptr->letter);
    }
  printf("\n");
}

struct list* insert(struct list *my_list, int position, char elem, int *counter_ptr)
{
  
  struct list *cursor, *new;
  int i = 0;
  cursor=my_list;
  new = (struct list *) malloc(sizeof(struct list));
  new->letter = elem;
  new->next = NULL;
  
  if(cursor == NULL || position < 0 || position > *counter_ptr)
    {
      printf("Invalid position!\n");
      return my_list;
    }
  //Traversing list
  while(i < position - 1)
    {
      cursor = cursor->next;
      i++;
    }

  new->next = cursor->next;  
  my_list->next = new;
  return my_list;
}

struct list* reverse(struct list *my_list)
{
  if(my_list == NULL || my_list->next == NULL)
    {
      return my_list;
    }

  struct list *helper1, *helper2, *helper3;
    helper1 = my_list;
    helper2 = helper1->next;
    helper3 = helper2->next;
    
  while(1)
    {
        helper2->next = helper1;
        helper1 = helper2;
        if (helper3==NULL)
        {
            break;
        }
        helper2 = helper3;
        helper3 = helper3->next;
    }
  
    my_list->next=NULL;
    return helper2;
}

int main()
{
    
  struct list *my_list = NULL;
  int input;
  char elem;
  scanf("%d", &input);
  
  //Counter to keep track of the number of elements
  int counter = 0;
  int position;
  int *counter_ptr = &counter;
  
  while(input != 5)
  { 
    switch(input)
    {
      case 1 :
	getchar();
	scanf("%c", &elem);
	my_list = push_back(my_list, elem);
	counter++;
	break;
     case 2 :
       getchar();
       scanf("%c", &elem);
       my_list = push_front(my_list, elem);
       counter++;
       break;
     case 3 :
       getchar();
       my_list = rm_first(my_list);
       counter--;
       break;
     case 4 :
       print(my_list);
       break;
     case 5 :
       empty_list(my_list);
       break;
     case 6 :
       getchar();
       scanf("%d", &position);
       getchar();
       scanf("%c", &elem);
       my_list = insert(my_list, position, elem, counter_ptr);
       counter++;
       break;
    case 7 :
      my_list = reverse(my_list);
      break;
    }
    scanf("%d", &input);
  }
  
  return 0;
}