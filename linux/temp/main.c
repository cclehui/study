#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include "io.h"

int main(void) {
    int fd =  myOpen("/etc/passwd" , O_RDONLY);

    myCopy(fd , 2);

    printf("\n-------------------------------------------------------------\n");

    fd =  myOpen("Makefile" , O_RDONLY);

    myCopy(fd , 2);

    return;
}
