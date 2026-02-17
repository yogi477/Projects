#ifndef TFTP_H
#define TFTP_H

#include <stdint.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define PORT 6969
#define BUFFER_SIZE 516  // TFTP data packet size (512 bytes data + 4 bytes header)
#define TIMEOUT_SEC 5    // Timeout in seconds
#define IP_ADDRESS  "127.0.0.1"

typedef enum{
    RRQ = 1,
    WRQ = 2,
    DATA = 3,
    ACK = 4,
    ERROR = 5
}tftp_opcode;
#pragma pack(1)
typedef struct{
    uint16_t opcode;
    union 
    {
        struct{
            char filename[256];
            char mode[8];
        }request;

        struct{
            uint16_t blocknumber;
            char data[512];
        }Data_packet;
        
        struct{
            uint16_t blocknumber;
        }ACK_packet;

        struct{
            uint16_t errorcode;
            char errormsg[256];
        }Error_packet;
    }body;  
}Tftp_packet;
#endif