#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>

#define LISTEN_PORT 3555

int main(int argc, char *argv[])
{
    int socktFd, connectedFd;
    struct socketaddr_in bindAddr;

    socktFd = socket(AF_INET, SOCK_STREAM, 0);
    if (socktFd == -1) 
    {
        printf("error:%s\n", strerror(errno));
        exit(1);
    }

    memset(bindAddr, 0, sizeof(bindAddr));
    bindAddr.sin_family = AF_INET;
    bindAddr.sin_port = LISTEN_PORT;

    printf("socktFd inited %d\n", socktFd);
    
    return 1;
}
