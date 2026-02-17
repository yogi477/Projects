#include "tftp.h"
#include "tftp_client.h"
tftp_info_t clientinfo;
int main()
{
    int choice;
    while(1)
    {
        printf("1.Connect\n2.Get\n3.Put\n4.Mode\n5.Exit\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            uint16_t port;    
            printf("Enter the Port: ");
            scanf("%hu",&port);
            getchar();    
            printf("Enter the ip: ");
            fgets(clientinfo.server_ip,sizeof(clientinfo.server_ip),stdin);
            clientinfo.server_ip[strcspn(clientinfo.server_ip,"\n")] = '\0';
            connect_to_server(&clientinfo,port);
            break;
        case 2:
            get(&clientinfo);
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            return 0;
        default:
            break;
        }
    }
    
    return 0;
}