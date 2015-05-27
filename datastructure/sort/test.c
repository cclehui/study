#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "../global.h"
#include "../list/table_list.h"

void main(){
    int rand_num = rand();
    int data_num = 10 , i = 0;
    long *data_array = create_table_list(data_num);

    for (i=0;i<data_num;i++) {
        srand((unsigned int)time(0) + i);
        rand_num = rand();
        add_table_list(&data_array , (int)((100.0*rand_num)/(RAND_MAX)));
    }
    show_table_list(data_array);


    int array_data[data_num];

    for (i=0;i<data_num;i++) {
        srand((unsigned int)time(0) + i);
        rand_num = rand();
        array_data[i] = (int)((100.0*rand_num)/(RAND_MAX));
    }

    printf("unsorted array data :\n");
    show_int_array(array_data , data_num);
    
    printf("sorted array data :\n");

    printf("time : %d , rand : %d, fengzi: %d  , fengmu: %d \n" , time() , (int)((100.0*rand_num)/(RAND_MAX)), rand_num , RAND_MAX);
}
