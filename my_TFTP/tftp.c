/* Common file for server & client */

#include "tftp.h"
#include<stdio.h>
void send_file(int sockfd, struct sockaddr_in client_addr, socklen_t client_len, char *filename) 
{
    // Implement file sending logic here
     tftp_packet packet,ack;
    int block = 1;
    int bytes;
    int pck_len;
    int fd = open(filename,O_RDONLY);
    if(fd == -1)
    {
        printf("\e[31mFile not existing in server\e[0m\n");
        packet.opcode = htons(ERROR);
        packet.body.error_packet.error_code = htons(1);
        strcpy(packet.body.error_packet.error_msg,"File not present in server");
        pck_len = 4 + 4 + strlen("File not present in server") + 1;
        sendto(sockfd,&packet,pck_len,0,(struct sockaddr*)&client_addr,client_len);
        return;
    }
    while((bytes = read(fd,packet.body.data_packet.data,sizeof(packet.body.data_packet.data))) > 0)
    {
        packet.opcode = htons(DATA);
        packet.body.data_packet.block_number = htons(block);
        pck_len = 4 + bytes;
        sendto(sockfd,&packet,pck_len,0,(struct sockaddr*)&client_addr,client_len);

        int n = recvfrom(sockfd,&ack,sizeof(ack),0,(struct sockaddr*)&client_addr,&client_len);
        if(ntohs(ack.opcode) != ACK && ntohs(ack.body.ack_packet.block_number) != block)
        {
            printf("\e[31mack failed for block %d\e[0m\n",block);
            break;
        }
        if(bytes < 512)
        {
            break;
        }
        block++;
    }
    close(fd);
    printf("\e[32mFile sent successfully\e[0m\n");
        
}

void receive_file(int sockfd, struct sockaddr_in client_addr, socklen_t client_len, char *filename) 
{
    // Implement file receiving logic here
}