#include"ssl.h"
int insert_at_first(ssl **s1,int data)
{
    ssl *new = malloc(sizeof(ssl));
    if(new == NULL)
    {
        printf("Memory allocation failed\n");
        return FAILURE;
    }
    new->data = data;
    new->link = NULL;
    if(*s1 == NULL)
    {
        *s1 = new;
        return SUCCESS;
    }
    else
    {
        new->link = *s1;
        *s1 = new;
        return SUCCESS;
    }
}