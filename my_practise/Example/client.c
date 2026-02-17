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
    int sock_fd;
    struct sockaddr_in clientinfo;
    char buff[50];
    sock_fd = socket(AF_INET,SOCK_STREAM,0);
    if(sock_fd < 0)
    {
	printf("Socket creatiom failed\n");
	return 1;
    }
    clientinfo.sin_family = AF_INET;
    clientinfo.sin_port = htons(PORT);
    clientinfo.sin_addr.s_addr = inet_addr(IP);
    int fd = connect(sock_fd,(struct sockaddr*)&clientinfo,sizeof(clientinfo));
    printf("Enter the message: ");
    scanf("%[^\n]",buff);
    send(sock_fd,buff,sizeof(buff),0);
    printf("Message sent to server\n");
}
	    
