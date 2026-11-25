#include"student.h"

void stud_delall(SLL **head)
{
    SLL *del=*head;
    while(del)
    {
        *head=del->next;
        free(del);
        sleep(1);
        del=*head;
    }
    printf("All records deleted \n");
      
}