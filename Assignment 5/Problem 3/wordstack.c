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

int main()
{
    Stack s;

    s.count = -1;
	char input[15], item[15];
	char comp;
	int i;
	while(1)
	{
		scanf("%s", input);
		push(&s, input);
		comp = getchar();
		
		if(comp == '\n')
		{
			if(strcmp(input, "exit")== 0)
			{
			  exit (0);
			}
			printf("The reversed sentence is:\n");
			
			int j;
			i = s.count;
			for(j = 0; j <= i; j++)
			{
				pop(&s, item);
				printf("%s", item);
				//Add spaces
				if(j < i)
				  printf(" ");
			}
			printf("\n");
		}
		
	}
    
	
	return 0;
}