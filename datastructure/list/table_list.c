#include <stdio.h>
#include <stdlib.h>
#include "table_list.h"

int *create_table_list(int size) {
    int *table_list[size] ;
    if (size <= 0) {
        return table_list;
    }

    int num = 0;
    for (num=0;num < size;num++) {
        printf("%p\n" , table_list + num); 
        *(table_list + num) = (int *)malloc(sizeof(int));
        **(table_list + num) = num;
    }

    for (num=0;num < size;num++) {
        printf("%d\n" , **(table_list + num));
    }

    return table_list;
}
