/**
 * @file testqueue.c
 */

#include <stdio.h>

#include "queue.h"

int main() 
{
	Queue line;
	Item temp;
	int ch = 0;
	
	initialize_queue(&line);
	int a = 0;
	while (1)
	{
		scanf("%d", &ch);
		getchar();
		switch (ch)	{
			case 1:
				printf("add char: ");
				scanf("%c", &temp);
				if (!queue_is_full(&line))
				{
					printf("Putting %c into queue\n", temp);
					enqueue(temp, &line);
				}
				else
					puts("Queue is full");
				break;

			case 2:
				if (queue_is_empty(&line))
					puts("Queue Underflow");
				else
				{
					dequeue(&temp, &line);
					printf("Removing %c from queue\n", temp);

				}
				break;
		       case 4:
		    	   a = 1;
		    	   break;
		}
		if(a == 1)
		  break;
		printf("%d items in queue\n", queue_item_count(&line));
		puts("Type 1 to add, 2 to delete, 4 to quit:");
	}
		
	
	puts("Bye.");
	return 0;
}