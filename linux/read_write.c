#include <stdio.h>
#include <unistd.h>

int main(int argc , char *argv[]) {
    char buff[5] = "";

    read(1 , buff , sizeof(buff));

    write(2 , buff , sizeof(buff));
    write(2 , "\n" , 1);
    printf("%d , %d , %d\n" , stdin , stdout , stderr);

    perror("test error");
}
