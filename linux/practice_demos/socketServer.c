#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <rpc/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define LISTEN_PORT 3555
#define MAX_CONNECT 10
#define MAX_LINE 4096

int trim(char *data, char *needTrimStr)
{
    int lastIndex = strlen(data);
    
    while (lastIndex >= 0)
    {
        if (strchr(needTrimStr, *(data + lastIndex - 1)) != 0)
        {
            *(data + lastIndex - 1) = '\0';
            lastIndex--;

        } else {
            break;
        }
    }

    return lastIndex;

}

void handleClientMsg(int connectedSocket) 
{
    char *readBuffer = malloc(MAX_LINE);
    int n = 0;
    char msg[] = "your msg is :";

    while (1)
    {
        memset(readBuffer, 0, MAX_LINE);
        n = read(connectedSocket, readBuffer, MAX_LINE - 1); 
        n = trim(readBuffer, " \t\r\n");
        if (n > 0)
        {
            write(connectedSocket, msg, sizeof(msg));
            write(connectedSocket, readBuffer, n);
            write(connectedSocket, "\n", 1);
        }
    }
    return;
}

int main(int argc, char *argv[])
{
    int socktFd, connectedFd, newPd;
    struct sockaddr_in bindAddr, remoteAddr;
    int addrLength = sizeof(struct sockaddr_in);
    char welcomeMsg[] = "welcome to our server !!!\n";

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

    //printf("socktFd %d inited, ip %d, listen on port %d\n", socktFd, bindAddr.sin_addr.s_addr, LISTEN_PORT);
    printf("current pid: %d ,socktFd %d inited, ip %d, listen on port %d\n", getpid(), socktFd, INADDR_ANY, LISTEN_PORT);

    memset(&remoteAddr, 0, sizeof(remoteAddr));
    while (1)
    {
        connectedFd = accept(socktFd, (struct sockaddr *)&remoteAddr, &addrLength);
        if (connectedFd == -1)
        {
            printf("accept error: %s\n", strerror(errno));
        }

        printf("accept success , connected fd is : %d\n", connectedFd);


        newPd = fork();
        if (newPd == -1){
            printf("fork error : %s\n", strerror(errno));
            continue;

        } else if (newPd == 0) {
            //子进程
            printf("connected client fd %d , remote ip:%s , port:%d\n", 
                    connectedFd, inet_ntoa(remoteAddr.sin_addr), ntohs(remoteAddr.sin_port));

            write(connectedFd, welcomeMsg, sizeof(welcomeMsg));
            handleClientMsg(connectedFd);//循环处理客户端消息
            break;

        } else {
            //父进程
            printf("accept for another connetd...\n");
        }

    }

    printf("out while --------\n");
    
    return 1;
}
