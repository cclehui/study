#include <stdio.h>

#define BUFFER_SIZE 10

int main(void) {
    char buffer[BUFFER_SIZE];
    setvbuf(stdout , buffer , _IOFBF , BUFFER_SIZE);

    printf("xxxxxxxxx\n");
    return 0;
}
