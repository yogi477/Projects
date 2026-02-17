#include<stdio.h>
int lcm(int a,int b)
{
    int max = (a > b) ? a : b;
    while(1)
    {
        if(max % a == 0 && max % b == 0)
        {
            printf("LCM = %d\n",max);
            break;
        }
        max++;
    }
    return 0;
}
int main()
{
    int a,b;
    printf("Enter num1: ");
    scanf("%d",&a);
    printf("Enter num2: ");
    scanf("%d",&b);
    lcm(a,b);

}