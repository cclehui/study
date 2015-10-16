#include <stdio.h>
#include <fcntl.h>

#define BUFFER_SIZE 100

//showUsage
/*{{{*/
void showUsage(int argc, char *argv[], char *usage) 
{
    int i = 0;
    for (i=0;i<argc;i++) {
        printf("%s\n", argv[i]);
    }

    printf("correct usage: %s\n" , usage);
}
/*}}}*/

int main(int argc, char *argv[]){
    
    if (argc != 3) {
        showUsage(argc, argv, "copy file1 file2");
        return;
    }

    char *source_file = argv[1];
    char *dest_file = argv[2];
    char buffer[BUFFER_SIZE] = "\0";
    char flag = '\0';
    int status = 0;

    //判断源文件是否存在
    if (access(source_file, R_OK|F_OK) == -1) {
        printf("源文件不存在或不可读\n");
        return;
    }

    //判断目标文件是否存在
    /*{{{*/
    if (access(dest_file, F_OK) == 0) {
        while (1) {
            printf("目标文件已存在 ，是否覆盖？y/n\n");
            scanf("%c", &flag);
            scanf("%[^\n]", &buffer);
            getchar();
            printf("input:%c, status=%d\n", flag, status);
            switch (flag) {
                case 'y':
                    status = 1;
                    break;
                case 'n':
                    return;
                default:
                    break;
            }

            if (status == 1) {
                break;
            }
        }
        unlink(dest_file);
    }
    /*}}}*/
    

    int s_fd = open(source_file, O_RDONLY);
    int d_fd = open(dest_file, O_CREAT|O_WRONLY, S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);

    if (s_fd < 0 || d_fd < 0) {
        printf("系统异常!!!");
        return;
    }

    buffer[0] = '\0';

    int tempSize = 0;

    do{
       tempSize = read(s_fd, buffer, BUFFER_SIZE); 
       write(d_fd, buffer, tempSize);
    } while (tempSize == BUFFER_SIZE);

    close(d_fd);
    close(s_fd);
}
