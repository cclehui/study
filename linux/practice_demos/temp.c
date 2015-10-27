#include <stdio.h>
#include <string.h>
#include <sys/types.h>

int trim(char *data, char *needTrimStr)
{
    int lastIndex = strlen(data);
    
    while (lastIndex >= 0)
    {
        if (strchr(needTrimStr, *(data + lastIndex - 1)) != 0)
        {
            *(data + lastIndex - 1) = '\0';
            lastIndex--;

        } else {
            break;
        }
    }

    return lastIndex;

}

int main()
{
    char data[] = "124\n";
    printf("raw data size is %lu , data is %s\n", strlen(data), data);

    int newLength = trim(data, "\n");

    printf("new data size is %d , data is %s\n", newLength, data);


}
