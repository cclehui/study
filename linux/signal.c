#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


void my_handler(int signo) {
    printf("caught signal %d \n" , signo);
    exit(1);
}

int main(){
    signal(SIGINT , my_handler);

    pause();
}
