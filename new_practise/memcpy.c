#include<stdio.h>
#include<string.h>
void *mem_cpy(void *dst,void *src,size_t n)
{
    char *ch_src = (char*)src;
    char *ch_dst = (char*)dst;
    for(size_t i=0; i<n ; i++)
    {
        ch_dst[i] = ch_src[i];
    }
    return dst;
}
int main()
{
    char src[10] = "hello";
    char dst[10] = {0};
    // memcpy(dst,src,sizeof(src));
    // printf("src -> %s\n",src);
    // printf("dst -> %s\n",dst);
    // printf("src -> %p\n",src);
    // printf("dst -> %p\n",dst);

    // char *ch = mem_cpy(dst,src,sizeof(src));
    // printf("src -> %s\n",src);
    // printf("dst -> %s\n",ch);
    // printf("src -> %p\n",src);
    // printf("dst -> %p\n",ch);
}