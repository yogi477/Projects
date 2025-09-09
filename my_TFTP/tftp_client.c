#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "tftp.h"
#include "tftp_client.h"
#define IP "127.0.0.1"
char buffer[BUFFER_SIZE];
int count = 0;
tftp_packet packet;
int main() {
    char command[256];
    tftp_client_t client;
    memset(&client, 0, sizeof(client));  // Initialize client structure
    
    // Main loop for command-line interface
    int choice;
    while (1) {
        //printf("tftp> ");
        printf("1.Connect\n2.Put\n3.Get\n4.Mode\n5.Exit\nEnter the choice: ");
        if(scanf("%d",&choice) != 1)
        {
            printf("Invalid input\n");
            exit(0);
        }
        getchar();
        switch (choice)
        {
        case 1:
            /* code */
            printf("Enter the IP Address: ");
            fgets(client.server_ip, sizeof(client.server_ip), stdin);
            // Remove newline character
            client.server_ip[strcspn(client.server_ip, "\n")] = 0;
            int p;
            printf("Enter the PORT: ");
            scanf(" %d",&p);
            getchar();
            connect_to_server(&client,client.server_ip,p);
            count = 1;
            break;
        case 2:
            if(count != 0)
            {
                char ch[20];
                printf("Enter the filename: ");
                scanf("%[^\n]",ch);
                put_file(&client,ch);
            }
            else
            {
                printf("\e[31mConnect to server first\e[0m\n");
                exit(0);
            }
            break;
        case 3:
            if(count != 0)
            {
               char ch[20];
                printf("Enter the filename: ");
                scanf("%[^\n]",ch);
                get_file(&client,ch);
            }
            else
            {
                printf("\e[31mConnect to server first\e[0m\n");
                exit(0);
            }
            break;
        case 4:
            break;
        case 5:
            exit(0);
        default:
            break;
        }
    }

    return 0;
}

// Function to process commands
// void process_command(tftp_client_t *client, char *command) {
   
//     if(strcmp(command,"connect") == 0)
//     {

//     }
// }

// This function is to initialize socket with given server IP, no packets sent to server in this function
void connect_to_server(tftp_client_t *client, char *ip, int port) {
    // Create UDP socket
    client->sockfd = socket(AF_INET,SOCK_DGRAM,0);
    if(client->sockfd == -1)
    {
        printf("\e[31mSocket creation failed\e[0m\n");
        exit(0);
    }

    // Set socket timeout option


    // Set up server address
    memset(&client->server_addr,0,sizeof(client->server_addr));
    client->server_addr.sin_family = AF_INET;
    client->server_addr.sin_port = htons(port);
    client->server_addr.sin_addr.s_addr = inet_addr(ip);
    client->server_len = sizeof(client->server_addr);

    printf("\e[32mConnection successful\e[0m\n");

}

void put_file(tftp_client_t *client, char *filename) {
    // Send WRQ request and send file
    memset(&packet,0,sizeof(packet));
    packet.opcode = htons(2);
    strcpy(packet.body.request.filename,filename);
    strcpy(packet.body.request.mode,"octet");
    int packet_len = 2 + strlen(filename) + 1 + strlen("octet") + 1;
    int res = sendto(client->sockfd,&packet,packet_len,0,(struct sockaddr*)&client->server_addr,client->server_len);
    if(res)
    {
        printf("\e[32mRequest Sent successfuly\e[0m\n");
    }
    else
    {
        printf("\e[31mRequest not sent\e[0m\n");
    }
}

void get_file(tftp_client_t *client, char *filename) {
    // Send RRQ and recive file 
    memset(&packet,0,sizeof(packet));
    packet.opcode = htons(1);
    strcpy(packet.body.request.filename,filename);
    strcpy(packet.body.request.mode,"octet");
    int packet_len = 2 + strlen(filename) + 1 + strlen("octet") + 1;
    int res = sendto(client->sockfd,&packet,packet_len,0,(struct sockaddr*)&client->server_addr,client->server_len);
    if(res)
    {
        printf("\e[32mRequest Sent successfuly\e[0m\n");
    }
    else
    {
        printf("\e[31mData not sent\e[0m\n");
    }
    int fd = open("client.txt",O_CREAT| O_WRONLY| O_TRUNC, 0644);
    if(fd == -1)
    {
        perror("\e[31mFile creation failed\e[0m\n");
        return;
    }
    memset(&packet,0,sizeof(packet));
    int n;
    uint16_t block = 1;
    while(1)
    {
        n =  recvfrom(client->sockfd,&packet,sizeof(packet),0,(struct sockaddr*)&client->server_addr,&client->server_len);
        if(ntohs(packet.opcode) == ERROR)
        {
            printf("\e[31m%s\e[0m\n",packet.body.error_packet.error_msg);
            return;
        }
        else if(n <= 0 || ntohs(packet.opcode) != DATA || ntohs(packet.body.data_packet.block_number) != block)
        {
            perror("\e[31mError while receiving data\e[0m\n");
            break;
        }
        int data_len = n - 4;
        write(fd,&packet.body.data_packet.data,data_len);
        memset(&packet,0,sizeof(packet));
        packet.opcode = htons(ACK);
        packet.body.ack_packet.block_number = htons(block);
        sendto(client->sockfd,&packet,4,0,(struct sockaddr*)&client->server_addr,client->server_len);
        if(n < 512)
        {
            break;
        }
        block++;
        memset(&packet, 0, sizeof(packet));
    }

    close(fd);
    printf("\e[32mFile received successfuly\e[0m\n");
    
}

void disconnect(tftp_client_t *client) {
    // close fd
   
}
void send_request(int sockfd, struct sockaddr_in server_addr, char *filename, int opcode)
{

}

void receive_request(int sockfd, struct sockaddr_in server_addr, char *filename, int opcode)
{
    
}