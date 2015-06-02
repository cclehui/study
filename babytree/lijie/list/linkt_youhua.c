/* linkedlist.c  双向链表 优化*/
#include <stdlib.h>
#include <stdio.h>
#include "linkt_youhua.h"

static link head = NULL;
static link tail = NULL;

link make_node(unsigned char item)
{
	link p = malloc(sizeof *p);
	p->item = item;
	p->prev = p->next = NULL;
	return p;
}

void free_node(link p)
{
	free(p);
}

link search(unsigned char key)
{
	link p;
	for (p = head; p; p = p->next)
		if (p->item == key)
			return p;
	return NULL;
}

void insert(link p ,short sort)
{
    if (head)
    {
        if (sort == 1)
        {
            link *next_node = &head;
            link cur_node;
            for (next_node = &head;*next_node ; next_node = &((*next_node)->next))
            {   
                cur_node = *(next_node);
                if ((*next_node)->item >= p->item)
                {
                    p->next = *next_node;
                    p->prev = (*next_node)->prev;
                    //printf("111111111 %d  %d \n" , p->prev , p->item);
                    (*next_node)->prev = p;
                    *next_node = p;
                    return;
                }
            }
            
            //插入到链表尾部
            *next_node = p;
            (*next_node)->next = NULL;
            (*next_node)->prev = cur_node;
            tail = (*next_node);

            //printf("222222222 %d %d \n" , p->prev , p->item);
            return;

        } else
        {
            p->next = head;
            p->prev = NULL;
            head->prev = p;
            head = p;
        }
        
    } else
    {
        p->prev = NULL;
        p->next = NULL;
        head = p;
        tail = p;
    
    }
}

void delete(link p)
{
    if (p->prev)
    {
        p->prev->next = p->next;
    }

    if (p->next)
    {
        p->next->prev = p->prev;
    }
    if (!p->next && p->prev)
    {
        head = NULL;
        tail = NULL;
    }
    free_node(p);
}

void traverse(void (*visit)(link))
{
	link p;
	for (p = head; p; p = p->next)
		visit(p);
}

void destroy(void)
{
	link p = head;
	while (p) {
		head = p->next;
		free_node(p);
        p = head;
	}

    tail = NULL;
}

void enqueue(link p)
{
	insert(p , 0);
}

link dequeue(void)
{
	if (tail->prev == head)
		return NULL;
	else {
		link p = tail->prev;
		delete(p);
		return p;
	}
}