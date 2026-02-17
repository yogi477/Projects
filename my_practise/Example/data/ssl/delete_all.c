#include"ssl.h"
int delete_all(ssl **s1)
{
    if(*s1 == NULL)
    {
        printf("List is Empty\n");
        return SUCCESS;
    }
    ssl *temp = *s1;
    ssl *t1 = NULL;
    while (temp != NULL)
    {
        t1 = temp->link;
        free(temp);
        temp = t1;
    }
    *s1 = NULL;
    return SUCCESS;
}