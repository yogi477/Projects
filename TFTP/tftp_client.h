#ifndef TFTP_CLIENT_H
#define TFTP_CLIENT_H
#include "tftp.h"

#pragma pack(1)
typedef struct{
    int socket_fd;
    struct sockaddr_in servinfo;
    socklen_t servlen;
    char server_ip[INET_ADDRSTRLEN];
}tftp_info_t;

int connect_to_server(tftp_info_t *tftp_info,int16_t port);
int get(tftp_info_t *clientinfo);
#endif