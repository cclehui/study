#ifndef _LINEAR_LIST_H
#define _LINEAR_LIST_H

#include "../global.h"

typedef int DataType;
typedef struct ListNode ListNode;
typedef struct ListNode List;

struct ListNode{
    DataType data;
    ListNode *next;
};


List *create_list();
bool is_empty(List *list);
bool add_node(List **list ,ListNode *list_node );
ListNode* find_node(List *list , DataType data);
bool delete_node(List *list , DataType data);
bool destroy_list(List **list);
void list_show(List *list);

#endif
