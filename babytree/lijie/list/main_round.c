/* main.c
 * 环形链表
 */
#include <stdio.h>
#include <stdlib.h>
#include "link_round.h"

void print_item(link p)
{
	printf("cur ptr:%u  pre ptr:%u  next ptr:%u  value:%d\n" , p ,p->prev ,p->next  ,p->item); //exit(0);
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
//exit(0);
    printf("create ordered double list , total nodes %d \n" , node_num);
    for (i=0;i<node_num;i++ )
    {
        insert(make_node((int)rand()%100) , 1);
    }
    traverse(print_item);
    destroy();


    //环形链表解决josephus杀人问题
    int n = 20 , m = 3;
    printf("practice : jsephus kill people problem , total nodes %d  , the survivor num is %d \n" , n , m);
    for (i=1;i<=n;i++)
    {
        insert(make_node(i) ,0);//构造链表
    }

    traverse(print_item);
    delete(search(1));

    printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");
    traverse(print_item);
    link head = get_link_head();

    int count = 0;
    if (head)
    {
        do
        {   
            head = head->next;
            count++;
            if (count%m == 0)
            {
                delete(head->prev);
            }
            
        }
        while (head != head->next);
    }
    printf("bbbbbbbbbb");
    traverse(print_item);
    //环形链表解决josephus杀人问题 end
	return 0;
}