#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common/util.h"
#include "color.h"

#include "model/list.h"

#define COMMAND_BUFFER_LENGTH 20

#define FLUSH                                       \
    do{                                             \
        int c;                                      \
        while((c = getchar()) != '\n' && c != EOF)  \
            ;                                       \
    }while(0)

void exec_command(char *command);

int main() {
    //system
    system("stty erase ^H");//输入backspace不显示

    char command[COMMAND_BUFFER_LENGTH];
    printf("welcome %d\n" , sizeof(list));

    list *my_list = create_list();


    listNode my_list_nodes[] = {
                    {"help" , "help information" , NULL},
                    {"quit" , "exit progress" , NULL}
                };
    int i=0;
    for (i=0;i<2;i++) {
        list_add(my_list , &my_list_nodes[i]);
    }

    list_show(my_list);

    while(1){
        printf(">");

        if (*fgets(command ,COMMAND_BUFFER_LENGTH , stdin) != '\n') {
            if (strlen(command) == COMMAND_BUFFER_LENGTH - 1 && command[COMMAND_BUFFER_LENGTH - 1] == 0) {
                FLUSH;
            }

            //执行command
            exec_command(command);
        }
    }
    return 0;
}


void exec_command(char *command) {
    trim(command ,"\n\r ");
    printf("your inputed command is :"RED" %s\n"NONE , command);

}
