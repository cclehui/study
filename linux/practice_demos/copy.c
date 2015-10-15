#include <stdio.h>
#include <unistd.h>

void showUsage(int argc, char *argv[], char *usage) 
{
    int i = 0;
    for (i=0;i<argc;i++) {
        printf("%s\n", argv[i]);
    }

    printf("correct usage: %s\n" , usage);
}


int main(int argc, char *argv[]){
    
    if (argc != 3) {
        showUsage(argc, argv, "copy file1 file2");
        return;
    }

    char *source_file = argv[1];
    char *dest_file = argv[2];
    char buffer[100] = "\0";
    char flag = '\0';
    int status = 0;

    //判断文件是否存在
    if (access(source_file, R_OK|F_OK) == -1) {
        printf("源文件不存在或不可读\n");
        return;
    }

    if (access(dest_file, F_OK) == 0) {
        while (1) {
            printf("标文件已存在 ，是否覆盖？y/n\n");
            scanf("%c", &flag);
            scanf("%[^\n]", &buffer);
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
    }



}
