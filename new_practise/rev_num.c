#include<stdio.h>
int main()
{
    int num;
    printf("Enter the num: ");
    scanf("%d",&num);
    int a,b = 0;
    while (num != 0)
    {
        a = num % 10;
        b = b * 10 + a;
        num /= 10;
    }
    printf("reverse number is %d\n",b);
}