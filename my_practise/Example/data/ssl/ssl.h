#ifndef SSL_H
#define SSL_H

#include<stdio.h>
#include<stdlib.h>

#define SUCCESS 0
#define FAILURE 1

typedef struct node
{
    int data;
    struct node *link;
}ssl;

int insert_at_first(ssl **s1,int data);
int insert_at_last(ssl **s1,int data);
int print_data(ssl *s1);
int delete_all(ssl **s1);


#endif