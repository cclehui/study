/* linkedlist.c  环形链表*/
#include <stdlib.h>
#include <stdio.h>
#include "link_round.h"

static link head = NULL;
//static link tail = NULL;

link get_link_head(){
    return head;
}

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
	link p = head;
    do
    {
        if (p->item == key)
			return p;
        p = p->next;
    }
    while (p != head);
    
	return NULL;
}

void insert(link p ,short sort)
{
    link tail;
    if (head)
    {
        tail = head->prev;
        if (sort == 1)
        {
            link *next_node = &head;
            link cur_node;
            do
            {   //printf("111111111 %d  %d %d %d %d \n" , *next_node , (*next_node)->prev , (*next_node)->next , (*next_node)->item , p->item);
                cur_node = *(next_node);
                if ((*next_node)->item >= p->item)
                {
                    p->next = *next_node;
                    p->prev = (*next_node)->prev;
                    
                    (*next_node)->prev = p;
                    *next_node = p;
                    if (tail->next != head)
                    {
                        tail->next = head;
                    }
                    return;
                }

                next_node = &((*next_node)->next);
            }
            while (*next_node != head);
          
            //插入到链表尾部
            p->next = head;
            p->prev = cur_node;
            *next_node = p;
            tail = p;
            head->prev = p;

            //printf("222222222 %d %d \n" , p->prev , p->item);
            return;

        } else
        {
            
            p->next = head;
            p->prev = head->prev;
            head->prev->next = p;
            head->prev = p;
            if (head->next == head)
            {
                head->next = p;
            }
            head = p;
            //tail->next = head;
        }
        
    } else
    {
        p->prev = p;
        p->next = p;
        head = p;
        //tail = p;
    }
}

void delete(link p)
{
    if (!head || !p)
    {
        return;
    }
    
    if (p->prev == head && p == head)
    {
        head = NULL;
        return;
    }

    p->prev->next = p->next;
    p->next->prev = p->prev;
    if (p == head)
    {
        head = p->next;    
    }
    free_node(p);
}

void traverse(void (*visit)(link))
{
    if (!head)
    {   
        return;
    }

    link p = head;
    do
    {
        visit(p);
        p = p->next;
    }
    while (p != head);
}

void destroy(void)
{
    if (!head)
    {
        return;
    }

    link p = head;
    do
    {
        head = p->next;
        free_node(p);
        p = head;
    }
    while (p != head);

    head = NULL;
    //tail = NULL;
}


void enqueue(link p)
{
	insert(p , 0);
}

link dequeue(void)
{
}