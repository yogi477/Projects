#include<stdio.h>
#include<stdlib.h>
int count_vowel_consonents(char *str,int *vowel,int *conso)
{
    char s1[6] = "aeiou";
    for(int i=0;str[i] != '\0';i++)
    {
        int flag = 0;
        for (int j = 0; s1[j] != '\0'; j++)
        {
            if (str[i] == s1[j] || str[i] == s1[j] - 32)
            {
                flag = 1;
                (*vowel)++; //*vowel++
            }
            
        }
        if(flag == 0 && str[i] != ' ')
        {
            (*conso)++;
        }
        
    }
    
}
int main()
{
    int vowel = 0,conso = 0;
    char *str = (char *)malloc(30 * sizeof(char));
    if(str == NULL)
    {
        return 1;
    }
    printf("Enter the string: ");
    scanf("%[^\n]",str);
    count_vowel_consonents(str,&vowel,&conso);
    printf("Vowels = %d\n",vowel);
    printf("Consonents = %d\n",conso);

    free(str);
    return 0;

    
}