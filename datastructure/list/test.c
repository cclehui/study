#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

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



}
