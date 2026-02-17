#include<stdio.h>
#include<string.h>
int romanToInt(char* s) {
    char str[8] = "IVXLCDM";
    //int arr[8] = {1,5,10,50,100,500,1000};
    int arr[128] = {0};
    int res = 0;
    arr['I'] = 1;
    arr['V'] = 5;
    arr['X'] = 10;
    arr['L'] = 50;
    arr['C'] = 100;
    arr['D'] = 500;
    arr['M'] = 1000;
    int i = 0;
    while(s[i])
    {
        if(arr[s[i]] == 0)
            return 1;
        
            if(s[i+1] && arr[s[i]] < arr[s[i+1]])
            {
                res += arr[s[i+1]] - arr[s[i]];
                i += 2;
            }
            else
            {
                res += arr[s[i]];
                i++;
            }
    }
    return res;
}

int main()
{
    char str[10];
    printf("Enter roman interger: ");
    scanf("%s",str);
    printf("%d\n",romanToInt(str));

}