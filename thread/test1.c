#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM 10

void *print_hello( void *i) {
    printf("this is thread %d\n" ,i);
    pthread_exit(NULL);
}

int main(int argc ,char *argv[]) {
    pthread_t threads[NUM];
    int status , i;

    for (i = 1;i <= NUM; i++) {
        //printf("this is thread main \n");
        status = pthread_create(&threads[i] , NULL , print_hello , (void *)i);

        if (status != 0) {
            printf("cannot create thread status : %d\n", status);
            exit(-1);
        }
    }
    int *b;
    b = &i;

    long c = 1;
    printf("xxxxx :%d \n" , *b);
    printf("size of i: %d \n" ,sizeof(i));
    printf("size of b: %d \n" ,sizeof(b));
    printf("size of c: %d \n" ,sizeof(c));
}
