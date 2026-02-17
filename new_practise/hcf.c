#include<stdio.h>
int main()
{
    int num1,num2;
    int hcf = 1;
    printf("Enter num1 and num2: ");
    scanf("%d %d",&num1,&num2);
    for (int i = 1; i <= num1 || i<= num2; i++)
    {
        if(num1 % i == 0 && num2 % i == 0)
        {
            hcf = i;
        }
    }
    int lcm = (num1 * num2)/hcf;
    printf("HCF is %d\n",hcf);
    printf("LCM is %d\n",lcm);

    return 0;
}