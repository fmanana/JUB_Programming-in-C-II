#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main()
{
    
  struct list *my_list = NULL;
  int input;
  char elem;
  scanf("%d", &input);
  
  while(input != 5)
  { 
    switch(input)
    {
      case 1 :
	getchar();
	scanf("%c", &elem);
	my_list = push_back(my_list, elem);
	break;
     case 2 :
       getchar();
       scanf("%c", &elem);
       my_list = push_front(my_list, elem);
       break;
     case 3 :
       getchar();
       my_list = rm_first(my_list);
       break;
     case 4 :
       print(my_list);
       break;
     case 5 :
       empty_list(my_list);
       break;
    }
    scanf("%d", &input);
  }	      
  return 0;
}