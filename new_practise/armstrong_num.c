#include<stdio.h>
int power(int base,int expo)
{
    if(expo == 1)
    {
        return base;
    }
    return power(base,expo - 1) * base;

}
int main()
{
    int num;
    printf("Enter num: ");
    scanf("%d",&num);
    int size = 0;
    int a = num;
    while (a != 0)
    {
        size++;
        a/= 10;
    }
    a = num;
    int res = 0;
    while(a != 0)
    {
        res += power(a % 10,size);
        a /= 10;
    }
    //printf("armstrong number is %d\n",res);
    if(num == res)
    {
        printf("Armstrong number\n");
    }
    else
    {
        printf("Not armstrong number\n");
    }
}