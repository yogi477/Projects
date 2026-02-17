#include<stdio.h>
int power_2(unsigned int num)
{
    if((num & (num - 1)) == 0)
    {
        return 1;
    }
    return 0;
}
static inline int power_3(int num)
{
    int n = 3;
    while(n <= num)
    {
        if(n == num)
            return n;
        n = n * 3;
    }
    return n;
}
int main()
{
    int n;
    printf("Enter num: ");
    scanf("%d",&n);
    // if(power_2(n))
    // {
    //     printf("power of 2\n");
    // }
    // else
    // {
    //     printf("Not power of 2\n");
    // }
    if(power_3(n) == n)
    {
        printf("power of 3\n"); 
    }
    else
    {
        printf("Not power of 3\n"); 
    }
    return 0;

}