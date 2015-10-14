#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include "io.h"

int myOpen(char *file , int type)
{
    int fd =  open(file , type);

    if (fd < 0) {
        printf("open file fail errno = %d , %s  , %s\n" , errno , strerror(errno), file);
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
    int count = 0, size = 0;

    while ( (size = read(s_fd, buffer, BUFFER_SIZE - 1)) > 0 ) 
    {
        buffer[size] = '\0';
        write(d_fd, buffer, size);
        //printf("%s", buffer);
        //printf("%d\t%s", ++count,  buffer);
        //printf("\n....................................................\n");
    } 

    return 1;    
}

void showUsage(int argc, char *argv[], char *usage) 
{
    int i = 0;
    for (i=0;i<argc;i++) {
        printf("%s\n", argv[i]);
    }

    printf("usage: %s\n" , usage);
}
