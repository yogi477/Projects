#include<stdio.h>
//#include<stdlib.h>
// #define SUCCESS 0
// #define FAILURE -1
// typedef struct node
// {
//     int data;
//     struct node *link;
// }list;
// int insert_last(list **l1,int data)
// {
//     list *new = malloc(sizeof(list));
//     new->data = data;
//     new->link = NULL;
//     if(*l1 == NULL)
//     {
//         l1 = new;
//         return SUCCESS;
//     }
//     list *temp = *l1;
//     while(temp->link != NULL)
//     {
//         temp = temp->link;
//     }
//     temp = new;
//     return SUCCESS;  
// }
void arr_sort(int arr[],int size)
{
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-i-1; j++)
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
int remove_dup(int arr[],int *size)
{
    arr_sort(arr,*size);
    int index = 0;
    for(int i=0;i< *size;i++)
    {
        if(arr[index] != arr[i])
        {
            index++;
            arr[index] = arr[i];
        }
    }
    *size = index + 1;
}
void print_arr(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
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
    remove_dup(arr,&size);
    print_arr(arr,size);

}