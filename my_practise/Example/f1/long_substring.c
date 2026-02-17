#include<stdio.h>
#include<string.h>
int long_substring(char *str)
{
    int len = 0,maxlen = 0,index = 0;
    int n = strlen(str);
    for(int i=0;i<=n;i++)
    {
        if(str[i] == ' ' || str[i] == '\0')
        {
            if(maxlen < len)
            {
                maxlen = len;
                index = i - maxlen;
            }
            len = 0;
        }
        else
        {
            len++;
        }
    }
    for(int i=index;i<=n;i++)
    {
        if(str[i] == ' ')
        {
            str[i] = '\0';
        }
    }
    str = &str[index];
    printf("max sunstring len: %d\n",maxlen);
    printf("Longest substring: %s\n",str);
}
int main()
{
    char str[50];
    printf("Enter the string: ");
    scanf("%[^\n]",str);
    long_substring(str);
}