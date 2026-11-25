#include "student.h"

int count_nodes(SLL *ptr)
{
    int count = 0;
    while (ptr)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

void stud_sort(SLL *ptr)
{
    if (ptr == NULL)
    {
        printf("No records found\n");
        return;
    }

    char op;
    printf("N/n : Sort with name\n");
    printf("P/p : Sort with percentage\n");
    printf("Enter your choice: ");
    scanf(" %c", &op);

    if (op != 'N' && op != 'n' && op != 'P' && op != 'p')
    {
        printf("Invalid option.\n");
        return;
    }

    int i, j, c = count_nodes(ptr), swap;
    SLL *p1 = ptr, *p2, t;

    for (i = 0; i < c - 1; i++)
    {
        p2 = p1->next;
        for (j = 0; j < c - 1 - i; j++)
        {
            if ((op == 'N' || op == 'n') && strcmp(p1->name, p2->name) > 0)
                swap = 1;
            else if ((op == 'P' || op == 'p') && p1->percentage < p2->percentage)
                swap = 1;
            else
                swap = 0;

            if (swap)
            {
                t.rollno = p1->rollno;
                strcpy(t.name, p1->name);
                t.percentage = p1->percentage;

                p1->rollno = p2->rollno;
                strcpy(p1->name, p2->name);
                p1->percentage = p2->percentage;

                p2->rollno = t.rollno;
                strcpy(p2->name, t.name);
                p2->percentage = t.percentage;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }

    printf("Records sorted successfully.\n");
}