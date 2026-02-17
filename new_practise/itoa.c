#include<stdio.h>
#include<stdlib.h>
int main()
{
    int num = 12345;
    char s[10];
    sprintf(s,"%x",num);
    printf("%s\n",s);

    float n = 1234.5678;
    gcvt(n,6,s);
    printf("%s\n",s);

}