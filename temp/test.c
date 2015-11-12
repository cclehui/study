
#include <stdio.h>

#ifdef  __linux__
    #define CCTEST 10
#else
    #define CCTEST 20
#endif

void main()
{
    printf("number is %d\n", CCTEST);
}

