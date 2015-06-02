/* main.c
 * 双向链表
 */
#include <stdio.h>
#include "linkt_youhua.h"

void print_item(link p)
{
	printf("cur ptr:%u  pre ptr:%u  next ptr:%u  value:%d\n" , p ,p->prev ,p->next  ,p->item); 
}

int main(void)
{
    srand((int)time(NULL));
    
    int node_num = (int)rand()%20;
    int i = 0;
    printf("create unordered double list , total nodes %d \n" , node_num);
    for (i=0;i<node_num;i++ )
    {
        insert(make_node((int)rand()%100) , 0);
    }
    traverse(print_item);

    destroy();

    printf("create ordered double list , total nodes %d \n" , node_num);
    for (i=0;i<node_num;i++ )
    {
        insert(make_node((int)rand()%100) , 1);
    }
    traverse(print_item);
    

	return 0;
}