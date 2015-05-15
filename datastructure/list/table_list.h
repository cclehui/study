#ifndef _TABLE_LIST_H
#define _TABLE_LIST_H

#include "../global.h"

struct Data{
    char *name;
    char *sex;
};

int* create_table_list(int size);

#endif
