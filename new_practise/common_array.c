#include<stdio.h>
#include<stdlib.h>
int cmn_array(int *arr1,int *arr2,int size1,int size2)
{
    int arr_size = 1;
    int index = 0;
    int arr[10] = {0};
    int *cmn_arr = (int*)malloc(sizeof(int) * arr_size);
    for(int i = 0;i<size1;i++)
    {
        for (int j = 0; j<size2; j++)
        {
            if(arr1[i] == arr2[j])
            {
                if(arr[arr1[i]] == 0)
                {
                    arr[arr1[i]] = 1;
                    cmn_arr[index] = arr1[i];
                    index++;
                    arr_size++;
                    int *p = realloc(cmn_arr,sizeof(int) * arr_size);
                    if(p == NULL)
                    {
                        perror("Error\n");
                        return 1;
                    }
                }
                
            }
        }
        
    }
    printf("Common elements are: \n");
    for(int i=0;i<arr_size - 1;i++)
    {
        printf("%d ",cmn_arr[i]);
    }
    free(cmn_arr);
    printf("\n");
}
int main()
{
    int size1,size2;
    printf("Enter arr1 size: ");
    scanf("%d",&size1);
    printf("Enter arr2 size: ");
    scanf("%d",&size2);
    int arr1[size1];
    int arr2[size2];
    printf("Enter arr1 elements\n");
    for (int i = 0; i < size1; i++)
    {
        scanf("%d",&arr1[i]);
    }
    printf("Enter arr2 elements\n");
    for (int i = 0; i < size2; i++)
    {
        scanf("%d",&arr2[i]);
    }
    cmn_array(arr1,arr2,size1,size2);
    
}