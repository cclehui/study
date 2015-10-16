#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>

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

//putcharRepeat
/*{{{*/
void putcharRepeat(char ch, int num) {
    if (num < 1) {
        return;
    }
    int i = 0;
    for (i=0; i<num; i++) {
        putchar(ch);
    }
}
/*}}}*/


int isDir(char *path) {
    struct stat buff;
    int status = stat(path, &buff);

    if (status == 0 && (buff.st_mode & S_IFDIR)) {
        return 1;
    }
    return 0;
}

void myTree(char *path, int level) {

    if (level > 5) {
        return;
    } 
    
    int i = 0;
    char flagChar = '-';

    if (isDir(path) == 1) {
        int pathLength = strlen(path);
        if (*(path + pathLength - 1) != '/') {
            path = strcat(path, "/");
            pathLength++;
        }

        DIR *dir;
        struct dirent *ptr;
        char *tempPath = NULL;
        dir = opendir(path);


        while ((ptr = readdir(dir)) != NULL) {

            if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0) {
                continue;
            }

            putcharRepeat(flagChar, level);
            printf("%s%s\n", path, ptr->d_name);

            tempPath = malloc(pathLength + strlen(ptr->d_name) + 1);

            memcpy(tempPath, path, pathLength);
            memcpy(tempPath + pathLength, ptr->d_name, strlen(ptr->d_name) + 1);

            //printf("=========> %s \n%d\n", tempPath, pathLength);
            //return;

            //printf("----> %s\n", tempPath);return;

            myTree(tempPath, level + 1);
            free(tempPath);
        }

        tempPath = NULL;

        closedir(dir);
    } else {
        putcharRepeat(flagChar, level);
        printf("%s\n", path);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        showUsage(argc, argv, "tree directory");
        return;
    }

    myTree(argv[1], 0);
    
}
