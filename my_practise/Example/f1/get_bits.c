#include<stdio.h>
int get_n_bit(int num,int n,int pos) //n bits, pos position
{
    num = num >> pos - 1;
    return (num & ((1 << n) - 1));
}
int clear_n_bit(int num,int n,int pos)
{
    num = (num & (~((1 << n) - 1) << (pos - 1) ));
}
