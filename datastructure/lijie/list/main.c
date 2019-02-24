/* main.c */
#include <stdio.h>
#include <stdlib.h>
#include "link.h"

void print_item(link p)
{
	printf(" cur ptr: %d\tnext ptr: %d \t, value is :%d\n", p , p->next , p->item); 
}

int main(void)
{

	srand((int)time(NULL));
	int node_count = (int)rand()%20;
    int i = 0;
    
    //无序链表
	printf(" create unordered new list , node count is %d \n" , node_count);
	for (i=0;i<node_count ;i++ )
	{
		insert(make_node((unsigned char)rand()%128) , 0);
	}
	traverse(print_item);
    destroy();

    //有序链表
    printf(" create ordered new list , node count is %d \n" , node_count);
	for (i=0;i<node_count ;i++ )
	{
		insert(make_node((unsigned char)rand()%128) , 1);
	}
	traverse(print_item);
	

	return 0;
}