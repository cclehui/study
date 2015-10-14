#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include "io.h"

int main(int argc, char *argv[]) {

    if (argc != 3) {
        showUsage(argc, argv, "copy file1 file2");
        return;
    }

    int fd_s =  myOpen(argv[1] , O_RDONLY);

    if (fd_s < 0) {
        return;
    }

    if (access(argv[2] , F_OK) == 0) {
        printf("目标文件已存在\n");
        return;
    }

    int fd_d =  myOpen(argv[2] , O_CREAT);

    myCopy(fd_s , fd_d);

    return;
}
