#include<stdio.h>
#include<stdlib.h>
int bubble_sort(int *arr,int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for(int j=0;j < size - i - 1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
}
int main()
{
    int size1;
    printf("Enter arr1 size: ");
    scanf("%d",&size1);
    int *arr1 = malloc(sizeof(int) * size1);
    printf("Enter arr1 elements\n");
    for (int i = 0; i < size1; i++)
    {
        scanf("%d",&arr1[i]);
    }
    bubble_sort(arr1,size1);
    printf("sorted elements are: \n");
    for (int i = 0; i < size1; i++)
    {
        printf("%d ",arr1[i]);
    }
    printf("\n");
}