#include<stdio.h>
#include<stdlib.h>
int rmv_space(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        while(str[i] == ' ')
        {
            for (int j = i; str[j] != '\0'; j++)
            {
                str[j] = str[j+1];
                if(str[j] == '\0')
                {
                    break;
                }
            }
            
        }
        
    }
    
}
int main()
{
    char *s1 = (char *)malloc(30 * sizeof(s1));
    printf("Enter the string: ");
    scanf("%[^\n]",s1);
    rmv_space(s1);
    printf("%s\n",s1);
    free(s1);
}