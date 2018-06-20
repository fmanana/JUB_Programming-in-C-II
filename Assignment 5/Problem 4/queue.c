/*
    JTSK-320112
    a5 p4.c
    Fezile Manana
    f.manana@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

static void copy_to_node(Item item, Node *pn);
//static void copy_to_item(Node *pn, Item *pi);

void initialize_queue(Queue *pq)
{
	pq->front = pq->rear = NULL;
	pq->items = 0;
}

char queue_is_full(const Queue *pq)
{
	return pq->items == MAXQUEUE;
}

char queue_is_empty(const Queue *pq)
{
	return pq->items == 0;
}

int queue_item_count(const Queue *pq)
{
	return pq->items;
}

char enqueue(Item item, Queue *pq)
{
	if(pq->items == MAXQUEUE)
	{
	}
	
	Node n;
	copy_to_node(item, &n);
	n.next = NULL;
	
	if(pq->items == 0)
	{
		pq->front = &n;
	}
	else
	{
		pq->rear->next = &n;
	}
	pq->rear = &n;
	pq->items++;
	
	return item;
}

char dequeue(Item *pitem, Queue *pq)
{
	
        return 0;
}

void empty_queue(Queue *pq)
{
	Item dummy;
	while (!queue_is_empty(pq)) {
		dequeue(&dummy, pq);
	}
}

static void copy_to_node(Item item, Node *pn)
{
	pn->item = item;
}