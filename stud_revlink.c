#include "student.h"

static int count_node(SLL *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}

void stud_revlink(SLL **head)
{
    if (*head == NULL)
    {
        printf("No records found\n");
        return;
    }

    int i, c = count_node(*head);
    if (c > 1)
    {
        SLL **a = malloc(sizeof(SLL *) * c);
        SLL *t = *head;

        for (i = 0; i < c; i++)
        {
            a[i] = t;
            t = t->next;
        }

        for (i = c - 1; i > 0; i--)
            a[i]->next = a[i - 1];

        a[0]->next = NULL;
        *head = a[c - 1];

        free(a);
    }

    printf("List reversed successfully.\n");
}
