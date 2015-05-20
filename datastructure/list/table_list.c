#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table_list.h"

long* create_table_list(int size) {
    unsigned long *table_list = NULL;
    if (size < 0) {
        return table_list;
    }

    size = (size == 0) ? 10 : size;
    table_list  = (long *)malloc(sizeof(table_data_type *)*size + 2);
    
    *(table_list) = size;//用于存储list总大小
    *(table_list + 1) = 0;//用于存储list实际大小

    /*
    int num = 0;
    printf("int %d , ptf %d\n" , sizeof(long) , sizeof(long*));
    for (num=0;num < size;num++) {
        *(table_list + num) = (long)malloc(sizeof(table_data_type));
        *((table_data_type *)*(table_list + num)) = num + 100;
        printf("%d \t %d\n" , table_list + num , *(table_list + num)); 
    }
    */

    return table_list;
}

long *add_table_list(long **table_list_ptr_ptr , table_data_type value) {

    long *table_list = *table_list_ptr_ptr;

    printf("ptr %d \t %d\n" , table_list , *(table_list + 1));

    if (*(table_list) <= *(table_list + 1)) { 
        //int new_size = *(table_list) * 2;
        //int new_list_length = *(table_list + 1);
        //

        show_table_list(table_list);
        printf("111111111\n");
        
        //long *new_table_list = (long *)malloc(*(table_list) * 2 + 2);
        long *new_table_list = (long *)malloc(20);
        printf("tt %u \t new:%u\n" , table_list , new_table_list);
        //*(new_table_list) = *(table_list) * 2;
        //*(new_table_list + 1) = *(table_list + 1);
        //memcpy(new_table_list + 2 , table_list + 2 , *(table_list));
        
        show_table_list(table_list);
        printf("22222222\n");
        exit(0);

        printf("size %d , %d\n" , *(table_list) , *(new_table_list));

        show_table_list(new_table_list);

        free(table_list);

        table_list = new_table_list;
        *table_list_ptr_ptr = (long)table_list;
        printf("new ptr %d , outside %d\n" , table_list  , *table_list_ptr_ptr );
    } 

    long *next_value_ptr = table_list + 1 + *(table_list + 1) + 1;

    
    *(next_value_ptr) = (long)malloc(sizeof(table_data_type));
    *((table_data_type *)*(next_value_ptr)) = value;

    (*(table_list + 1))++;

    
    return;
}


void show_table_list(long *table_list) {
    if (*table_list <= 0 || *(table_list + 1) <= 0 || *(table_list) < *(table_list + 1)) {
        return;
    }

    int i = 0;
    for (i=0;i < *(table_list + 1);i++) {
        //printf("tts %d\n" , i);
        printf("show data : %d \t %d \t %u \t %u\n" , *((table_data_type *)*(table_list + 2 + i)) , *(table_list + 1) , table_list , table_list + 2 + i);
    }
}
