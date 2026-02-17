#include<stdio.h>
void print_arr(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int missing_num(int arr[],int size,int n)
{
    int nsum = (n * (n + 1))/2;
    int arr_sum = 0;
    for(int i=0;i<size;i++)
    {
        arr_sum += arr[i];
    }
    return nsum - arr_sum;
}
int main()
{
    int size;
    printf("Enter the size: ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter the array elements: ");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Missing element: %d\n",missing_num(arr,size,5));
}