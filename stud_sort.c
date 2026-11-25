#include"student.h"

int count_nodes(SLL *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}

void stud_sort(SLL *head)
{
    if(head==0)
    {
        printf("No records found\n");
        return;
    }
    int i,j,count=count_nodes(head);
    SLL *temp1=head,*temp2,t;
for(i=0;i<count-1;i++)
{
    temp2=temp1->next;
    for(j=i+1;j<count;j++)
    {
        {
            for(j=0;j<count-1;j++)
            {
                if(strcmp(temp1->name,temp2->name)>0)
                {
                    t=*temp1;
                    *temp1=*temp2;
                    *temp2=t;
                }
            }
        }
}

}

}