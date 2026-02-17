#include "tftp.h"
#include "tftp_client.h"
Tftp_packet packet1;
struct sockaddr_in info;

int get(tftp_info_t *clientinfo)
{
    memset(&info,0,sizeof(info));
    socklen_t len = sizeof(info);
    memset(&packet1,0,sizeof(packet1));
    packet1.opcode = RRQ;
    sendto(clientinfo->socket_fd,&packet1,sizeof(packet1),0,(struct sockaddr*)&clientinfo->servinfo,clientinfo->servlen);
    char buff[100];
    int a = 0;
    if((a = recvfrom(clientinfo->socket_fd,&buff,sizeof(buff),0,(struct sockaddr*)&info,&len)) > 0)
    {
        printf("File present in server\n");
    }
    
    int fd = open("client_file.txt",O_CREAT | O_WRONLY | O_TRUNC,0644);
    if(fd == -1)
    {
        printf("Client file unable to create\n");
    }
    char byte;
    int data = 1;
    socklen_t len_1 = sizeof(clientinfo);
    while ((data = recvfrom(clientinfo->socket_fd,&byte,sizeof(byte),0,(struct sockaddr*)&clientinfo->servinfo,&len_1)) > 0)
    {
        if(data == 0)
            break;
        write(fd,&byte,data);

    }
    printf("File received successfully\n");
}