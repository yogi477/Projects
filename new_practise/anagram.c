#include<stdio.h>
#include<stdlib.h>
int anagram(char *s1,char *s2)
{
    for (int i = 0; s1[i] != '\0'; i++)
    {
        int flag = 0;
        for (int j = 0; s2[j] != '\0'; j++)
        {
            if (s1[i] == s2[j])
            {
                flag = 1;
            }
            
        }
        if(flag != 1)
        {
            return 1;
        }
        
    }
    return 0;
}
int main()
{
    char *s1 = (char *)malloc(30 * sizeof(char));
    char *s2 = (char *)malloc(30 * sizeof(char));
    printf("Enter string1: ");
    scanf("%[^\n]",s1);
    getchar();
    printf("Enter string2: ");
    scanf("%[^\n]",s2);
    if(anagram(s1,s2))
    {
        printf("Not anagram\n");
    }
    else
    {
        printf("anagram\n");
    }
    
    free(s1);
    free(s2);
    return 0;

}