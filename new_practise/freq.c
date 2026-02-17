#include<stdio.h>
#include<string.h>
struct hash
{
    int value;
    int count;
};
int freq_count(int *arr,int siz,struct hash *ptr);
int main()
{
    struct hash sh[20];
    for(int i=0;i<20;i++)
    {
        sh[i].count = 0;
        sh[i].value = -1;
    }
    int size1;
    printf("Enter arr1 size: ");
    scanf("%d",&size1);
    int arr1[size1];
    printf("Enter arr1 elements\n");
    for (int i = 0; i < size1; i++)
    {
        scanf("%d",&arr1[i]);
    }
    freq_count(arr1,size1,sh);
}
int freq_count(int *arr,int siz,struct hash *ptr)
{
    int count = 0;
    for(int i=0;i<siz;i++)
    {
        int freq = 1;
        if(arr[i] == 12345)
            continue;
        for (int j = i+1; j < siz; j++)
        {
            if(arr[i] == arr[j] && arr[j] != 12345)
            {
                freq++;
                arr[j] = 12345; 
            }
        }
        ptr[count].value = arr[i];
        ptr[count].count = freq;
        count++;
   
    }
    for (int i = 0; i < count; i++)
    {
        printf("%d occurs %d times\n",ptr[i].value,ptr[i].count);
    }
}