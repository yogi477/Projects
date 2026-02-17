#include "tftp.h"
#include "tftp_client.h"

int main()
{
    struct sockaddr_in clninfo,servinfo;
    Tftp_packet client,server;
    memset(&clninfo,0,sizeof(clninfo));
    memset(&servinfo,0,sizeof(servinfo));
    memset(&server,0,sizeof(server));
    socklen_t sock_len = sizeof(clninfo);
    char buff[100] = {'\0'};
    socklen_t len = sizeof(clninfo);
    socklen_t len1 = sizeof(client);

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
    printf("Server is waiting...\n");
    recvfrom(socket_fd,buff,sizeof(buff),0,(struct sockaddr*)&clninfo,&len);
    printf("%s\n",buff);
    memset(&client,0,sizeof(client));
    recvfrom(socket_fd,&client,sizeof(client),0,(struct sockaddr*)&clninfo,&len);
    // printf("%s\n",client.body.request.filename);
    // printf("%s\n",client.body.request.mode);

    if(client.opcode == RRQ)
    {
        printf("RRQ Request\n");
        int file_fd = open("server_file.txt",O_RDONLY);
        if(file_fd == -1)
        {
            printf("File opening failed\n");
        }
        else
        {
            char buff[100] = "client_file.txt";
            sendto(socket_fd,buff,sizeof(buff),0,(struct sockaddr*)&clninfo,sizeof(clninfo));

        }
        char byte;
        int data;
        while( (data = read(file_fd,&byte,sizeof(byte))) > 0)
        {
            sendto(socket_fd,&byte,data,0,(struct sockaddr*)&clninfo,sizeof(clninfo));
        }
        sendto(socket_fd," ",0,0,(struct sockaddr*)&clninfo,sizeof(clninfo));
        printf("File sent successfully\n");
        
    }
    else if(client.opcode == WRQ)
    {

    }
    close(socket_fd);
    return 0;
}