#include"student.h"

static void del_by_roll(SLL **head, int roll)
{
    SLL *temp = *head, *prev = NULL;

    while (temp != NULL)
    {
        if (temp->rollno == roll)
        {
            if (prev == NULL)
                *head = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            printf("Record deleted successfully.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Record with roll number %d not found.\n", roll);
}

static void del_by_name(SLL **head)
{
    char name[50];
    

    printf("Enter name to delete:\n");
    scanf("%s", name);

    while (*head)
    {
        if (strcmp((*head)->name, name) == 0)
        {
            del_by_roll(head, (*head)->rollno);
            return;
        }
        *head = (*head)->next;
    }

    printf("Record with name '%s' not found.\n", name);
}

void stud_del(SLL **head)
{
    if (*head == NULL)
    {
        printf("No records found\n");
        return;
    }

    char op;
    int roll;

    printf("R/r : Delete based on roll number\n");
    printf("N/n : Delete based on name\n");
    printf("Enter the operation to be performed:\n");
    scanf(" %c", &op);

    switch (op)
    {
        case 'R':
        case 'r':
            printf("Enter roll number to delete:\n");
            scanf("%d", &roll);
            del_by_roll(head, roll);
            break;

        case 'N':
        case 'n':
            del_by_name(head);
            break;

        default:
            printf("Invalid option.\n");
    }
}
