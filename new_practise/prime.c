#include<stdio.h>
int is_prime(int num)
{
    for(int i=2 ; i<num ; i++)
    {
        if(num % i == 0)
        {
            return 1;
        }
    }
    return 0;
}
int prime(int n)
{
    int i = 1,j = 1;
    while(i < n)
    {
        if(!(is_prime(j)))
        {
            printf("%d ",j);
            i++;
        }
        j++;
    }
    printf("\n");
}
int main()
{
    int n;
    printf("Enter num: ");
    scanf("%d",&n);
    prime(n);
}