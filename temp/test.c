
#include <stdio.h>

int **your_function()
{   int *pArray[3];
    *pArray[0] = 1;
    *pArray[1] = 2;
    *pArray[2] = 3;
    return pArray;
}

void print_array(int *pArray[])
{
    int i = 0;
    for (; i<3; i++)
    {
        printf("%d ",*pArray[i]);
    }
    printf("\n");
}

void main()
{
    p = your_function(array);
    print_array(p);
}

