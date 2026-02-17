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
    int socket_fd;
    struct sockaddr_in servinfo,clientinfo;
    char buff[50];
    socklen_t len = sizeof(clientinfo);
    socket_fd = socket(AF_INET,SOCK_STREAM,0);
    if(socket_fd < 0)
    {
	printf("Socket creation failed\n");
	return 1;
    }
    servinfo.sin_family = AF_INET;
    servinfo.sin_port = htons(PORT);
    servinfo.sin_addr.s_addr = INADDR_ANY;
    int b_fd = bind(socket_fd,(struct sockaddr*)&servinfo,sizeof(servinfo));
    if(b_fd < 0)
    {
	printf("Binding failed\n");
	return 1;
    }
    printf("Server is waiting\n");
    listen(socket_fd,5);
    int new_fd = accept(socket_fd,(struct sockaddr*)&clientinfo,&len);
    int data = recv(new_fd,buff,sizeof(buff),0);
    if(data > 0)
    {
	buff[data] = '\0';
    }
    printf("Received message: %s\n",buff);
}

