#include <stdio.h>
#include <stdlib.h>
int main(int argc ,char *argv[]){
    char *p  = argv[1];
    int offset = p == NULL ? -1 : atoi(p);
    printf("opcode index %d \n",offset);
    
    int count = 0;
    FILE *fp;
    fp = fopen("opcode.txt","r");
    char temp[300];

    while(!feof(fp)){
        fgets(temp,1024,fp);
        if(count == offset){
            printf("the opcode handler is: %s \n",temp);
            break;
        }
        count++;
    }

    return 1;
}
