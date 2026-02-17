#include<stdio.h>
#include<stdlib.h>
int *rmv_dup(int *arr,int size)
{
    int dup[10] = {0};
    int index = 1;
    int *new_arr = malloc(sizeof(int) * index);
    for (int i = 0; i < size; i++)
    {
        if(dup[arr[i]] == 0)
        {
            dup[arr[i]] = 1;
            new_arr[index - 1] = arr[i];
            index++;
            int *p = realloc(new_arr,sizeof(int) * index);
            if(p == NULL)
            {
                return NULL;
            }
        }
    }
    
    printf("elements are: \n");
    for (int i = 0; i < index - 1; i++)
    {
        printf("%d ",new_arr[i]);
    }
    printf("\n"); 

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
    rmv_dup(arr1,size1);
   
}