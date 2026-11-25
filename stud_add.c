
#include"student.h"

void stud_add(SLL **head)
{
    SLL *new=malloc(sizeof(SLL));
    new->next=0;
    int r=1;
    SLL *temp=*head;
    while(temp!=NULL)
    {
        if(temp->rollno==r)
        {
            r++;
            temp=*head;
        }
        else
            temp=temp->next;
    }
    new->rollno=r;
    printf("Enter the name and marks of the student:\n");
    scanf( "%s %f",new->name,&new->percentage);
    if(*head==NULL)
        *head=new;
    else
    {
        SLL *last=*head;
        while(last->next)
            last=last->next;
        last->next=new;
        new->next=0;
    }
}
