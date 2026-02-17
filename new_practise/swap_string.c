#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int swap_string(char *s1,char *s2)
{
    int s1_len = 0,s2_len = 0,index = 0;
    while (s1[s1_len] != '\0')
    {
        s1_len++;
    }
    index = s1_len;
    while(s2[s2_len] != '\0')
    {
        s1[s1_len] = s2[s2_len];
        s1_len++;
        s2_len++;
    }
    s1[s1_len] = '\0';
    
    int i = 0;
    for(i; i < index; i++)
    {
        s2[i] = s1[i];
    }
    s2[i] = '\0';

    int j = 0;
    for(j; j < s2_len; j++)
    {
        s1[j] = s1[index];
        index++;
    }
    s1[j] = '\0';
    printf("s1 = %s\n",s1);
    printf("s2 = %s\n",s2);
    
}
int main()
{
    char *s1 = (char *)malloc(30 * sizeof(char));
    char *s2 = (char *)malloc(30 * sizeof(char));

    printf("Enter the string1: ");
    scanf("%[^\n]",s1);
    getchar();
    printf("Enter the string2: ");
    scanf("%[^\n]",s2);
    swap_string(s1,s2);
    free(s1);
    free(s2);
    
}