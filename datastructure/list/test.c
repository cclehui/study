#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "table_list.h"

main() {
    List *test_list;
    test_list = create_list();
    ListNode *temp_node;

    printf("inited linked list  , data is %p\n" , test_list);
    
    printf("\ntest add data node , start ...\n");
    int num = 10 ,i = 1;
    for (i=1 ; i <= num ; i++) {
        temp_node = (ListNode *)malloc(sizeof(ListNode));
        temp_node->data = i;
        temp_node->next = NULL;

        add_node(&test_list , temp_node);

        printf("add %d\n" , i);
    }
    printf("test add data node , end\n");
    
    printf("\ntest show linked list data , start ...\n");
    
    list_show(test_list);

    printf("test show linked list data , end\n");

    printf("\n delete node 5 ...\n");
    delete_node(test_list , 5);
    list_show(test_list);

    printf("\n destroy list ...\n");
    destroy_list(&test_list);
    list_show(test_list);
    printf("address %p\n" , test_list);

    for (i=1;i<=50;i++) {
        printf(".");
    }
    printf("\n table list testing ....\n");
    

    //int *t = (int *)malloc(40);
    //test_malloc(t);
    
    long *table_list = NULL;
    table_list = create_table_list(num);
    show_table_list(table_list);
    printf("outside,ptr: %u\t value:%u\n" , &table_list , table_list);
    for (i=1;i<= 2*num ;i++){
        add_table_list(&table_list , i*4 + i);
    }
    printf("outside,ptr: %u\t value:%u\n" , &table_list , table_list);

    show_table_list(table_list);
}
