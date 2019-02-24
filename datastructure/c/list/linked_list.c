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

bool delete_node(List *list , DataType data) {
    if (is_empty(list)) {
        return true;
    }
    List *pre_list = list;
    do {
        if (list->data == data) {
            pre_list->next = list->next;
            free(list);
            list = NULL;
            return true;
        }
        pre_list = list;
        list = list->next;
    }while (list != NULL);
    return true;
}

bool destroy_list(List **list) {
    if (is_empty(*list)) {
        free(*list);
        *list = NULL;
        return true;
    }
    List *pre_list = *list;
    do {
        pre_list = *list;
        *list = (List *)(*list)->next;

        free(pre_list);
        pre_list=NULL;
    }while (*list != NULL);
    return true;
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
