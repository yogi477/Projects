#include"ssl.h"
int insert_at_last(ssl **s1,int data)
{
    ssl *new = malloc(sizeof(ssl));
    if(*s1 == NULL)
    {
        new->data = data;
        new->link = NULL;
        *s1 = new;
        return SUCCESS;
    }
    else
    {
        ssl *temp = *s1;
        while(temp->link != NULL)
        {
            temp = temp->link;
        }
        new->data = data;
        new->link = NULL;
        temp->link = new;
        return SUCCESS;
    }
    
}