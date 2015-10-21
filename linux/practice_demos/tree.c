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

//max
/*{{{*/
    int max(int x, int y) {
        if (x > y) {
            return x;
        }

        return y;
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

static char suffix[] = {'/', '\0'};
void myTree(char *path, int level) {

    if (level > 5) {
        return;
    } 
    
    int i = 0;
    char flagChar = '-';

    if (isDir(path) == 1) {
        int pathLength = strlen(path);
        DIR *dir;
        struct dirent *ptr;
        char *tempPath = NULL;
        int tempPathSize = 0;
        int pathIsNew = 0;

        if (*(path + pathLength - 1) != '/') {
            tempPath = malloc(pathLength + 2);
            memcpy(tempPath, path, pathLength);
            memcpy(tempPath + pathLength, suffix, 2);
            path = tempPath;

            tempPath = NULL;
            pathLength++;
            pathIsNew = 1;
        }

        dir = opendir(path);


        while ((ptr = readdir(dir)) != NULL) {

            if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0) {
                continue;
            }

            if ((pathLength + strlen(ptr->d_name) + 1) > tempPathSize) {
                if (tempPath != NULL) {
                    free(tempPath);
                }
                tempPathSize = pathLength + strlen(ptr->d_name) + 1;
                tempPath = malloc(pathLength + strlen(ptr->d_name) + 1);
            }

            memcpy(tempPath, path, pathLength);
            memcpy(tempPath + pathLength, ptr->d_name, strlen(ptr->d_name) + 1);

            putcharRepeat(flagChar, level);
            printf("%s\n", tempPath);

            if (isDir(tempPath) == 1) {
                putcharRepeat(flagChar, level);
                myTree(tempPath, level + 1);
            } 

        }
        
        if (tempPath != NULL) {
            free(tempPath);
            tempPath = NULL;
        }

        if (pathIsNew == 1) {
            free(path);
        }

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
