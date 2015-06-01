/* linkedlist.c */
#include <stdlib.h>
#include <stdio.h>
#include "link.h"

static link head = NULL;

link make_node(unsigned char item)
{
	link p = malloc(sizeof *p);
	p->item = item;
	p->next = NULL;
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

void insert(link p , short sort)
{
	if (sort == 1)
	{
        /*
        if (!head)
        {
            head = p;
            head->next = NULL;
            return;
        }
        */
        
        link *next_node = &head;
        for (next_node = &head;*next_node ; next_node = &((*next_node)->next))
        {
            if ((*next_node)->item >= p->item)
            {
                p->next = *next_node;
                *next_node = p;
                return;
            }
        }


        *next_node = p;
        (*next_node)->next = NULL;
        return;
        
	} else {
	    p->next = head;
	    head = p;
	}
    return;
}

void delete(link p)
{
	link pre;
	if (p == head) {
		head = p->next;
		return;
	}
	for (pre = head; pre; pre = pre->next)
		if (pre->next == p) {
			pre->next = p->next;
			return;
		}
}

void traverse(void (*visit)(link))
{
	link p;
	for (p = head; p; p = p->next)
		visit(p);
}

void destroy(void)
{
	link q, p = head;
	head = NULL;
	while (p) {
		q = p;
		p = p->next;
		free_node(q);
	}
}

void push(link p)
{
	insert(p , 0);
}

link pop(void)
{
	if (head == NULL)
		return NULL;
	else {
		link p = head;
		head = head->next;
		return p;
	}
}
