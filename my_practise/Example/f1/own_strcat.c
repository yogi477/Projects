#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void own_strcat(char *s1,char *s2)
{
    int size = strlen(s1) + strlen(s2) + 2;
    s1 = realloc(s1,size);
    int val = strlen(s1);
    for(int i = 0;s2[i] != '\0';i++)
    {
        s1[val] = s2[i];
        val++;
    }
    s1[val] = '\0';
    free(s2);
}
int main()
{
    char *str1 = malloc(sizeof(char) * 20);
    char *str2 = malloc(sizeof(char) * 20);
    printf("Enter string1: ");
    scanf("%[^\n]",str1);
    
    printf("Enter string2: ");
    scanf(" %[^\n]",str2);
    own_strcat(str1,str2);
    printf("After strstr: %s\n",str1);
}