#include<stdio.h>
#include<string.h>
void string_sort(int col,int row,char str[row][col])
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<row-i-1;j++)
        {
            if(strcmp(str[j],str[j+1]) > 0)
            {
                char temp[50];
                strcpy(temp,str[j]);
                strcpy(str[j],str[j+1]);
                strcpy(str[j+1],temp);
            }
        }
    }
    printf("sorted string: ");
    for(int i=0;i<row;i++)
    {
        printf("%s ",str[i]);
    }
    printf("\n");
}
int main()
{
    int row,col;
    printf("Enter row & col: ");
    scanf("%d" "%d",&row,&col);
    getchar();
    char arr[row][col];
    printf("Enter the strings:\n");
    for(int i=0;i<row;i++)
    {
        //scanf(" %[^\n]",arr[i]);
        fgets(arr[i],col,stdin);
        arr[i][strcspn(arr[i],"\n")] = '\0';
    }
    string_sort(col,row,arr);
    
}