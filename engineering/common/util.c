#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int trim(char *str , char list[]) {
    int start = 0 , end = 0 , find_start = 0 ,find_end = 0 , end_count = 0 ,index = 0;

    while (*(str + index) != '\0') {
        if (strchr(list , *(str + index)) != NULL) {
            if (find_start == 0 ) {
                start++;
            } else {
                find_end = 1;
                end_count++;
            }
        } else {
            find_start = 1;
            find_end = 0;
        }
        if (find_end == 0) {
            end++;
            end = end + end_count;
            end_count = 0;
        }
        index++;
    }

    //printf("start=%d,end=%d\n" , start , end);
    
    for (index=start;index<end;index++) {
        *(str + (index-start)) = *(str + index);    
    }
    *(str + end - start) = '\0';
    
    return 1;
}
