#include<stdio.h>
const int * const a;
int *const b;
const int *b;

int main(void)
{
    char acData[5] ={'A','B','C','D','E'};
    char *pcData = NULL;
    pcData = acData;
    printf("%c ",*pcData++);
    return 0;
}