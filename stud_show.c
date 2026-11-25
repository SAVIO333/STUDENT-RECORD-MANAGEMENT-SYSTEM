#include"student.h"

void stud_show(SLL *head)
{
    
    if(head==NULL)
        printf("No records found\n");
    else
    {
        printf("Rollno\tName\tPercentage\n");
        while(head)
        {
            printf("%d\t%s\t%f\n",head->rollno,head->name,head->percentage);
            head=head->next;
        }
    }
}