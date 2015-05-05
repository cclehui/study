#include <stdio.h>
#include <time.h>

#include <unistd.h>
#include <sys/types.h>

int main(int arc , char *argv[]) {
    char buffer[5];
    fd_set fds;    
    struct timeval tv;
    int ret;
    time_t cur_time;

    while (1) {
        tv.tv_sec = 2;
        tv.tv_usec = 500;

        FD_ZERO(&fds);
        FD_SET(0 , &fds);

        ret = select(1 , &fds , NULL , NULL , &tv);
        if (ret < 0) {
            perror("select");
        } else if (ret == 0 ){
            printf("超时\n");
            sleep(1);
        } else {
            //read(0 , buffer , sizeof(buffer));
            scanf("%s" , buffer);
            printf("your input is : %s\n" , buffer);
        }

        cur_time = time(NULL);
        printf("当前时间:%s\n" , ctime(&cur_time));
    }

}
