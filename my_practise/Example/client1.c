#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>
#define PORT 8080
#define IP "127.0.0.1"
int main()
{
    struct sockaddr_in clintinfo;
    memset(&clintinfo,0,sizeof(clintinfo));
    clintinfo.sin_family = AF_INET;
    clintinfo.sin_port = htons(PORT);
    clintinfo.sin_addr.s_addr = inet_addr(IP);
    int sock_fd = socket(AF_INET,SOCK_DGRAM,0);
    if(sock_fd < 0)
    {
        printf("Socket creation failed\n");
        return 1;
    }
    char buff[100] = {'\0'};
    printf("Enter data: ");
    fgets(buff,sizeof(buff),stdin);
    buff[strcspn(buff,"\n")];
    socklen_t len = sizeof(clintinfo);
    
   sendto(sock_fd,buff,sizeof(buff),0,(struct sockaddr*)&clintinfo,sizeof(clintinfo));
   recvfrom(sock_fd,buff,sizeof(buff),0,(struct sockaddr*)&clintinfo,&len);
   printf("%s\n",buff);
    close(sock_fd);
}