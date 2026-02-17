#include<stdio.h>
#include<stdlib.h>
int even_index(char *s1)
{
    for (int i = 0; s1[i] != '\0'; i++)
    {
        if(i % 2 == 0 || i == 0)
        {
            printf("%c ",s1[i]);
        }
    }
    printf("\n");
}
int main()
{
    char *s1 = (char *)malloc(30 * sizeof(char));
    printf("Enter the string: ");
    scanf("%[^\n]",s1);
    even_index(s1);
}