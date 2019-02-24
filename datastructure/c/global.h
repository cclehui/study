#ifndef _GLOBAL_H
#define _GLOBAL_H

typedef int bool;

#define true 1
#define false 0
#define TRUE 1
#define FALSE 0


void show_int_array(int *data , int size) {
    int i=0;
    for (i=0;i<size;i++) {
        printf("show array data %d , %d \n" , i , *(data + i));
    }
}

#endif
