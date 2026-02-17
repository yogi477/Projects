#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *print_twice(char *s1)
{
    
    int index;
    char *str = malloc(((strlen(s1)*2) + 1)* sizeof(char));
    for (int i = 0; s1[i] != '\0'; i++)
    {
        str[index++] = s1[i];
        str[index++] = s1[i];
    }
    str[index] = '\0';
    return str;
}
int main()
{
    char *s1 = (char *)malloc(30 * sizeof(s1));
    printf("Enter the string: ");
    scanf("%[^\n]",s1);
    char *res = print_twice(s1);
    printf("%s\n",res);
    free(res);
    free(s1);
}