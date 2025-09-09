#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "tftp.h"

char buf[BUFFER_SIZE];

void handle_client(int sockfd, struct sockaddr_in client_addr, socklen_t client_len, tftp_packet *packet);

int main() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    tftp_packet packet;


    // Create UDP socket
    sockfd = socket(AF_INET,SOCK_DGRAM,0);
    if(sockfd == -1)
    {
        printf("\e[31mServer Socket creation failed\e[0m\n");
        return 1;
    }

    // Set socket timeout option
    //TODO Use setsockopt() to set timeout option

    
    // Set up server address
    struct sockaddr_in servinfo;
    servinfo.sin_family = AF_INET;
    servinfo.sin_port = htons(PORT);
    servinfo.sin_addr.s_addr = INADDR_ANY;
   
    // Bind the socket
    int bind_fd = bind(sockfd,(struct sockaddr*)&servinfo,sizeof(servinfo));
    if(bind_fd == -1)
    {
        printf("\e[31mServer socket binding failed\e[0m\n");
        return 1;
    }
  

    printf("TFTP Server listening on port %d...\n", PORT);

    // Main loop to handle incoming requests
    while (1) {
        int n = recvfrom(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&client_addr, &client_len);
        if (n < 0) {
            perror("\e[31mReceive failed or timeout occurred\e[0m");
            continue;
        }

         handle_client(sockfd, client_addr, client_len, &packet);
    }

    close(sockfd);
    return 0;
}

void handle_client(int sockfd, struct sockaddr_in client_addr, socklen_t client_len, tftp_packet *packet) 
{
    // Extract the TFTP operation (read or write) from the received packet
    // and call send_file or receive_file accordingly
    uint16_t opcode = htons(packet->opcode);
        //printf("Received file name %s\n",packet->body.request.filename);
    if(opcode == RRQ)
    {
        //send file
        printf("Recieved RRQ\n");
        printf("Received file name %s\n",packet->body.request.filename);
        send_file(sockfd,client_addr,client_len,packet->body.request.filename);
    }
    else if(packet->opcode == WRQ)
    {
        //receive file
        printf("\eReceived WRQ\n");
    }
    else
    {
        printf("\e[31mUnknown packet received\e[0m\n");
        exit(0);
    }

}




