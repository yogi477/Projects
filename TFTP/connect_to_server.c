#include "tftp.h"
#include "tftp_client.h"

Tftp_packet packet;
int connect_to_server(tftp_info_t *tftp_info,int16_t port)
{
    memset(&tftp_info->servinfo,0,sizeof(tftp_info->servinfo));
    tftp_info->servinfo.sin_port = htons(port);
    tftp_info->servinfo.sin_family = AF_INET;
    tftp_info->servinfo.sin_addr.s_addr = inet_addr(tftp_info->server_ip);

    int fd = socket(AF_INET,SOCK_DGRAM,0);
    if(fd == -1)
    {
        printf("Socket creation failed\n");
        close(fd);
        return 1;
    }
    tftp_info->socket_fd = fd;  //socket fd
    tftp_info->servlen = sizeof(tftp_info->servinfo);
    char buff[] = "connected to server"; 
    sendto(fd,buff,sizeof(buff),0,(struct sockaddr*)&tftp_info->servinfo,sizeof(tftp_info->servinfo));
    // memset(&packet,0,sizeof(packet));
    // packet.opcode = RRQ;
    // strcpy(packet.body.request.filename,"new.txt");
    // strcpy(packet.body.request.mode,"octet");
    // sendto(fd,&packet,sizeof(packet),0,(struct sockaddr*)&tftp_info->servinfo,sizeof(tftp_info->servinfo));
    // close(fd);
    return 0;
}
