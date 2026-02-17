#include"ssl.h"
int print_data(ssl *s1)
{
    if(s1 == NULL)
    {
        printf("List is empty\n");
        return SUCCESS;
    }
    while(s1 != NULL)
    {
         if(s1->link == NULL)
        {
            printf("%d\n",s1->data);
            return SUCCESS;
        }
        printf("%d-->",s1->data);
        s1 = s1->link;
    }
}