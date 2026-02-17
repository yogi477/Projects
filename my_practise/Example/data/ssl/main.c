#include"ssl.h"
ssl *s1;
int val;
int main()
{
    s1 = NULL;
    while(1)
    {
        printf("1.insert first\n2.insert last\n3.delete all\n4.print data\n5.Exit\n");
    
        printf("Enter choice: ");
        scanf("%d",&val);
        switch(val)
        {
            case 1:
            {
                int data;
                printf("Enter the data: ");
                scanf("%d",&data);
                if(insert_at_first(&s1,data) == SUCCESS)
                {
                    printf("Data inserted successfully\n");
                }
                else
                {
                    printf("Data failed to insert\n");
                }
                break;
            }
            case 2:
            {
                int data;
                printf("Enter the data: ");
                scanf("%d",&data);
                if(insert_at_last(&s1,data) == SUCCESS)
                {
                    printf("Data inserted successfully\n");
                }
                else
                {
                    printf("Data failed to insert\n");
                }
                break;
            }
            case 3:
            {
                if(delete_all(&s1) == SUCCESS)
                {
                    printf("List deleted successfuly\n");
                }
                break;
            }
            case 4:
            {
                print_data(s1);
                break;
            }
            case 5:
            {
                return 1;
            }
            default:
                break;
        }
    }
    
}