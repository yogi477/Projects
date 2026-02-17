#include<stdio.h>
int main()
{
    __uint32_t data = 0x11223344;
    __uint8_t *newdata;
    newdata = (__uint8_t*)&data;
    if(*newdata = 0x11)
    {
        printf("Big endian\n");
    }
    else if(*newdata == 0x44)
    {
        printf("Little endianess\n");
    }
    return 0;
}
