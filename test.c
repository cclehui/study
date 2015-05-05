#include <stdio.h>

void main(){
    int a = 1;
    int *pa = &a;
    int **p = &pa;

    printf("out : %d",**p);
}
