#include<stdio.h>
int gcd_or_hcf(int a,int b)
{
    int min = (a < b)? a: b;
    while(1)
    {
        if(a % min == 0 && b % min == 0)
        {
            printf("GCD is: %d\n",min);
            break;
        }
        min--;
    }
}
int main()
{
    int a,b;
    printf("Enter num1: ");
    scanf("%d",&a);
    printf("Enter num2: ");
    scanf("%d",&b);
    gcd_or_hcf(a,b);
}