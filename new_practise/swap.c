#include<stdio.h>
/*int main()
{
    int a,b;
    printf("Enter a and b: ");
    scanf("%d %d",&a,&b);

    printf("before swap a = %d b = %d\n",a,b);

    // a = a ^ b;
    // b = a ^ b;
    // a = a ^ b;

    //a = 5, b = 10
    a = a + b; // 5 + 10 = 15
    b = a - b;  // 15 - 10 = 5
    a = a - b;  //15 - 5 = 10

    printf("After swap a = %d b = %d\n",a,b);
}*/

//generic pointer
void swap(void *p, void *q,int size)
{
    char *a = (char *)p;
    char *b = (char *)q;
    char temp;
    for(int i = 0 ; i < size; i++)
    {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }

    
}
int main()
{
    int op;
    printf("Swap\n1.int\n2.float\n3.char\n");
    scanf("%d",&op);
    switch (op)
    {
    case 1:
        int a,b;
        printf("Enter a and b: ");
        scanf("%d %d",&a,&b);
        swap(&a,&b,sizeof(int));
        printf("%d %d\n",a,b);
        break;
    case 2:
        float a1,b1;
        printf("Enter a and b: ");
        scanf("%f %f",&a1,&b1);
        swap(&a1,&b1,sizeof(float));
        printf("%f %f\n",a1,b1);
        break;
    case 3:
        char a2,b2;
        printf("Enter a: ");
        scanf(" %c",&a2);
        printf("Enter b: ");
        scanf(" %c",&b2);
        swap(&a2,&b2,sizeof(char));
        printf("%c %c\n",a2,b2);
        break;
    
    default:
        break;
    }
}