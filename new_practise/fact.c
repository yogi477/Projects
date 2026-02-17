#include<stdio.h>
int fact(int num)
{
    if(num == 1)
    {
        return num;
    }
    return fact(num - 1) * num;
}
int main()
{
    int num;
    printf("Enter num: ");
    scanf("%d",&num);
    printf("factorial of %d = %d\n",num,fact(num));
    // int res = 1;
    // for(int i=1; i<=num; i++)
    // {
    //     res *= i;
    // }
    // printf("factorial of %d = %d\n",num,res);

} 