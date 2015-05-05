#ifndef MODEL_LIST
#define MODEL_LIST

typedef struct _listNode{
    char *command;
    char *desc;
    //void (*exec)();
    struct _listNode *next;
}listNode;

typedef struct _list{
    listNode *head;
}list;

list *create_list(); 
void list_add(list *list , listNode *node);
void list_show(list *list); 

#endif
