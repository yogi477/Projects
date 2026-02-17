#include<stdio.h>
typedef struct
{
    char name[20];
    int age;
}student;

void read_data(student *s1)
{
    printf("Enter name: ");
    scanf("%[^\n]",s1->name);
    printf("Enter the age: ");
    scanf("%d",&(s1->age));
}
void print_data(student *s1)
{
    printf("Name: %s\n",s1->name);
    printf("Age: %d\n",s1->age);
}
int main()
{
    student s1;
    read_data(&s1);
    print_data(&s1);

}