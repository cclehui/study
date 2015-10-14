#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include "io.h"

int myOpen(char *file , int type)
{
    int fd =  open(file , type);

    if (fd < 0) {
        printf("open file fail errno = %d , %s \n" , errno , strerror(errno));
    }
    return fd;
}

int myCopy(int s_fd , int d_fd)
{
    if (s_fd < 0 || d_fd < 0)
    {
        printf("file description error\n");
    }
    
    char buffer[BUFFER_SIZE] = {"\0"};
    int count = 0;

    while ( read(s_fd, buffer, BUFFER_SIZE) > 0 ) 
    {
        printf("%d\t%s", ++count,  buffer);
        printf("\n....................................................\n");
    } 

    return 1;    
}
