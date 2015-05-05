#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//创建
list *create_list() {
    list *new_list = (list *)malloc(sizeof(list));
    new_list->head = NULL;
    return new_list; 
}

void list_add(list *list , listNode *node) {
    if (list == NULL) {
        return;
    }

    
    if ( list->head == NULL) {
        list->head = node;
        return ;
    }
    //printf("%s\n" , node->command);

    listNode *cur = list->head;

    while (cur->next != NULL) {
        cur = cur->next;
    }

    cur->next = node;

    return;

}

void list_show(list *list) {
    listNode *head = list->head;
    if (head == NULL){
        return;
    }
    do {
        printf("%s %s\n" , head->command , head->desc);    
        head = head->next;
    }while (head != NULL);

    return;
}

listNode *list_find(list *list  , char *command) {
    if (list == NULL || list->head == NULL) {
        return NULL;
    }

}
