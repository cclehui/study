#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

#define IO_BUFFER_SIZE 1024

int main(int argc  , char *argv[]) {
    printf("sssssss%s \n" , "dddddd");   

    FILE *fp;
    char *fileName = "/usr/include/time.h";
    char buffer[IO_BUFFER_SIZE];
    
    if ((fp = fopen(fileName , "r")) == NULL) {
        printf("cannot open file %s \n" , fileName);
        return;
    }

    while (fgets(buffer , IO_BUFFER_SIZE , fp) != NULL) {
        printf("%s" , buffer);
    }

    fclose(fp);
    
    
}
