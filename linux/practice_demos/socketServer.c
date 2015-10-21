#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <rpc/types.h>

#define LISTEN_PORT 3555
#define MAX_CONNECT 10

int main(int argc, char *argv[])
{
    int socktFd, connectedFd;
    struct sockaddr_in bindAddr, remoteAddr;
    int addrLength = sizeof(struct sockaddr_in);

    socktFd = socket(AF_INET, SOCK_STREAM, 0);
    if (socktFd == -1) 
    {
        printf("open socket error:%s\n", strerror(errno));
        exit(1);
    }


    memset(&bindAddr, 0, sizeof(bindAddr));
    bindAddr.sin_family = AF_INET;
    bindAddr.sin_port = htons(LISTEN_PORT);
    bindAddr.sin_addr.s_addr = htonl(INADDR_ANY);//ip

    if (bind(socktFd, (struct sockaddr*)&bindAddr, sizeof(bindAddr)) == -1) 
    {
        printf("bind error: %s\n", strerror(errno));
        exit(1);
    }

    if (listen(socktFd, MAX_CONNECT) == -1) 
    {
        printf("listen error: %s\n", strerror(errno));
        exit(1);
    }

    printf("socktFd %d inited, listen on port %d\n", socktFd, LISTEN_PORT);

    memset(&remoteAddr, 0, sizeof(remoteAddr));
    while (1)
    {
        connectedFd = accept(socktFd, (struct sockaddr *)&remoteAddr, &addrLength);
        if (connectedFd == -1)
        {
            printf("accept error: %s\n", strerror(errno));
        }

        printf("connected client fd %d , remote ip:%ld , port:%d\n", 
                connectedFd, (remoteAddr.sin_addr), (remoteAddr.sin_port));
        //inet_ntoa
    }
    
    return 1;
}
