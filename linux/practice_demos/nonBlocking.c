#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUFFER_SIZE 20

int main(int argc, char *argv[])
{
    printf("select function study \n");

    char buffer[BUFFER_SIZE] = "\0";
    int n = 0;

    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK|O_RDONLY);

    while (1)
    {
        n = read(STDIN_FILENO, buffer, BUFFER_SIZE);

        if (n < 0) 
        {
            printf("error , %s\n", strerror(errno));
            sleep(1);
        } else if ( n == 0) {
            printf("no input\n");
            sleep(1);
        } else {
            write(STDOUT_FILENO, buffer, n);
            printf("size is %d\n", n);
        }
    }

    return 1;
}
