#include<stdio.h>
#include<stdlib.h>
int unique_string(char *s1,char *res)
{
    char uniq[128] = {0};
    int index = 0;
    for (int i = 0; s1[i] != '\0'; i++)
    {
        if(uniq[s1[i]] == 0)
        {
            res[index++] = s1[i];
            uniq[s1[i]] = 1;
        }
    }
    res[index] = '\0';
    
}
int main()
{
    char *s1 = (char *)malloc(30 * sizeof(char));
    char *res = (char *)malloc(30 * sizeof(char));
    printf("Enter the string: ");
    scanf("%[^\n]",s1);
    unique_string(s1,res);
    printf("unique: %s\n",res);

}