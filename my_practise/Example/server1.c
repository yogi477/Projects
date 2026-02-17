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
    struct sockaddr_in clninfo,servinfo;
    memset(&clninfo,0,sizeof(clninfo));
    memset(&servinfo,0,sizeof(servinfo));
    socklen_t sock_len = sizeof(clninfo);
    char buff[100] = {'\0'};
    socklen_t len = sizeof(clninfo);
    int socket_fd = socket(AF_INET,SOCK_DGRAM,0);
    if(socket_fd < 0)
    {
        printf("Socket creation failed\n");
    }
    servinfo.sin_family = AF_INET;
    servinfo.sin_port = htons(PORT);
    servinfo.sin_addr.s_addr = INADDR_ANY;
    int bindfd = bind(socket_fd,(struct sockaddr*)&servinfo,sizeof(servinfo));
    if(bindfd < 0)
    {
        printf("Socket binding failed\n");
    }
    printf("UDP Server is waiting...\n");

        recvfrom(socket_fd,buff,sizeof(buff),0,(struct sockaddr*)&clninfo,&len);
        printf("Received data: %s\n",buff);
        memset(buff,'\0',sizeof(buff));
        strcpy(buff,"Hello from UDP server");
        sendto(socket_fd,buff,strlen(buff),0,(struct sockaddr*)&clninfo,sizeof(clninfo));
        close(socket_fd);

}