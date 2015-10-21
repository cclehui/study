#include<sys/time.h>  
#include<sys/types.h>  
#include<unistd.h>  
#include<string.h>  
#include<stdlib.h>  
#include<stdio.h>  
int main()  
{  
    char buf[10]="";  
    fd_set rdfds;  
    struct timeval tv;  
    int ret;  
    FD_ZERO(&rdfds);  
    FD_SET(0,&rdfds);   //文件描述符0表示stdin键盘输入  
    tv.tv_sec = 3;  
    tv.tv_usec = 500;  
    ret = select(1,&rdfds,NULL,NULL,&tv);  
    if(ret<0)  
        printf("\n selcet");  
    else if(ret == 0)  
        printf("\n timeout");  
    else  
        printf("\n ret = %d",ret);  

    if(FD_ISSET(0,&rdfds))  //如果有输入，从stdin中获取输入字符  
    {  
        printf("\n reading");  
        fread(buf,9,1,stdin);  
    }  
    write(1,buf,strlen(buf));  
    printf("\n %d \n", strlen(buf));  
    return 0;  
}  
