#include<stdio.h>
int prime_num(int num)
{
    if(num < 2)
    {
        return 0;
    }
    for(int i=2;i * i <= num;i++)
    {
        if(num % i == 0)
        {
            return 1;
        }
    }
    return 0;
}
int check_goodnum(int num)
{
    while(num != 0)
    {
        int a = num % 10;
        if((prime_num(a)))
        {
            return 1;
        }
        else
        {
            num /= 10;
            continue;
        }
    }
    return 0;
}
int main()
{
    int num;
    printf("Enter num: ");
    scanf("%d",&num);
    if(prime_num(num) == 1 && check_goodnum(num) == 1)
    {
        printf("This number is not good number\n");
    }
    else
    {
        printf("Good number\n");
    }
    
}