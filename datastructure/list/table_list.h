#ifndef _TABLE_LIST_H
#define _TABLE_LIST_H

#include "../global.h"

struct Data{
    char *name;
    char *sex;
};
typedef int table_data_type;
long* create_table_list(int size);
long* add_table_list(long **table_list_ptr_ptr , table_data_type value);
void show_table_list(long *table_list); 

void test_malloc();

#endif
