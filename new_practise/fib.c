#include<stdio.h>
int main()
{
    int n;
    int a = 0;
    int b = 1;
    int c = a + b;
    printf("Enter num: ");
    scanf("%d",&n);
    if(n > 0)
    {
        printf("%d %d ",a,b);
        while(c <= n)
        {
            printf("%d ",c);
            // b = c;
            // a = b;
            a = b;
            b = c;
            c = a + b;
        }
    }
}