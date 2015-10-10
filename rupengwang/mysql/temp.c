#include <stdio.h>
#include <stdlib.h>
//#include <winsock.h>
#include "mysql.h"

#pragma comment(lib, "libmysql.lib")

int main(int argc, char *argv[])
{
    printf("Hello, world\n");
    MYSQL mysql, *sock;
    mysql_init(&mysql);
    return 0;
}
