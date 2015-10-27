#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

void subProcess(int num)
{
    while(1)
    {
        printf("this is sub process %d , pid is %d\n" , num, getpid());
        sleep(1);
    }
}

int main()
{
    int i = 0, subPid = 0;

    printf("parent process id is %d\n", getpid());
    for (i=0;i<3;i++)
    {
        printf("vfork number %d \n", i);
        subPid = fork();

        if (subPid == -1){
            printf("vfork error!!! , error msg is : %s\n", strerror(errno));
        } else if (subPid == 0) {
            subProcess(i);
            break;
        } else {
            printf("parent process ,pid is %d\n", getpid());
        } 

        sleep(1);

    }
}
