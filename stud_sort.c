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

void stud_sort(SLL **head)
{
    if (*head == NULL)
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

    int count = count_nodes(*head);
    int i, j, swap;
    SLL *prev, *curr, *next;

    for (i = 0; i < count - 1; i++)
    {
        prev = NULL;
        curr = *head;

        for (j = 0; j < count - 1 - i; j++)
        {
            next = curr->next;
            if ((op == 'N' || op == 'n') && strcmp(curr->name, next->name) > 0)
                swap = 1;
            else if ((op == 'P' || op == 'p') && curr->percentage < next->percentage)
                swap = 1;
            else
                swap = 0;

            if (swap)
            {
                if (prev == NULL)
                {
                    *head = next;
                }
                else
                {
                    prev->next = next;
                }
                curr->next = next->next;
                next->next = curr;

                prev = next; // Update prev to the new node after swapping
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
    }
}
