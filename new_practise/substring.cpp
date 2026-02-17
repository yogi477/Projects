#include<iostream>
#include<string>
using namespace std;
class Solution {
    public:
        int strStr(string haystack, string needle) 
        {
            int index = -1,count = 0,j = 0;
            for(int i=0;haystack[i] != '\0';i++)
            {
                if(haystack[j] == needle[i] && needle[j] != '\0' )
                {
                    if(index == -1)
                    {
                        index = i;
                    }
                    count++;
                    j++;
                }
            }
            if(needle.length() == count) return index;
            return -1;
        }
};
int main()
{
    string a = "hello";
    string b = "ll";
    Solution obj;
    cout << obj.strStr(a,b) << endl;

}