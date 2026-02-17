#include<stdio.h>
int pailndrome(char *str)
{
    int size = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        size++;
        i++;
    }
    for(int i=0; str[i] != '\0'; i++)
    {
        if (str[i] != str[size - i - 1])
        {
            return 1;
        }
        
    }
    return 0;
}
int main()
{
    char str[20];
    printf("Enter the string: ");
    scanf("%[^\n]",str);
    if(pailndrome(str))
    {
        printf("Not palindrome\n");
    }
    else
    {
        printf("Palindrome\n");
    }
    return 0;
}