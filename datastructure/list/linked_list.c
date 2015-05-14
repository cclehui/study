#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


List* create_list() {
    List *a = NULL;
    return a;
}

bool is_empty(List *list) {
    if (list == NULL) {
        return true;
    }
    return false;
}

bool add_node(List **list ,ListNode *list_node ) {
    if (list_node == NULL) {
        return false;
    }

    if (is_empty(*list)) {
        *list = list_node;
        return true;
    }

    List *cur_list = *list;
    while (cur_list->next != NULL) {
        cur_list = cur_list->next;
    }

    list_node->next = NULL;
    cur_list->next = list_node;
    return true;
}

ListNode* find_node(List *list , DataType data) {
    if (is_empty(list)) {
        return NULL;
    }
    do {
        if (list->data == data) {
            list->next = NULL;
            return list;
        }
        list = list->next;
    }while (list != NULL);
    return NULL;
}

void list_show(List *list) {
    if (is_empty(list)) {
        return;
    }
    int node_count = 0;
    do {
        printf("this number %d  linkde node , data is %d\n" , ++node_count , list->data);
        list = list->next;
    }while (list != NULL);

    return;
}
