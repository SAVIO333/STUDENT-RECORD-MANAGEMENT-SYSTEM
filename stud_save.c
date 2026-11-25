#include"student.h"

void stud_save(SLL *head)
{
    FILE *fp=fopen("students.dat","w");
    if(fp==NULL)
    {
        printf("File not present\n");
        return;
    }
   
    while(head)
    {
        fprintf(fp,"%d %s %f\n",head->rollno,head->name,head->percentage);
        head=head->next;
    }
    printf("Data saved successfully\n");
    fclose(fp);
}