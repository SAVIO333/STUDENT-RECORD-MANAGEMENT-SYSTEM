#include "student.h"

static void mod_by_roll(SLL *head, int roll)
{
    SLL *temp = head;
    while (temp != NULL)
    {
        if (temp->rollno == roll)
        {
            printf("Current Details -> Roll No: %d | Name: %s | Percentage: %.2f\n",
                   temp->rollno, temp->name, temp->percentage);
            printf("Enter the new name and percentage:\n");
            scanf("%s %f", temp->name, &temp->percentage);

            while (temp->percentage < 0.0f || temp->percentage > 100.0f)
            {
                printf("Invalid percentage! Enter value between 0.00 and 100.00:\n");
                scanf("%f", &temp->percentage);
            }

            printf("Record modified successfully.\n");
            return;
        }
        temp = temp->next;
    }
    printf("Record with roll number %d not found.\n", roll);
}

static void mod_by_name(SLL *head)
{
    char name[50];
    int count = 0, roll;
    SLL *temp = head;

    printf("Enter name to search:\n");
    scanf("%s", name);

    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            count++;
            roll = temp->rollno;
        }
        temp = temp->next;
    }

    if (count == 0)
    {
        printf("Record with name '%s' not found.\n", name);
        return;
    }
    else if (count > 1)
    {
        printf("Multiple records found with name '%s':\n", name);
        temp = head;
        while (temp != NULL)
        {
            if (strcmp(temp->name, name) == 0)
            {
                printf("Roll No: %d | Name: %s | Percentage: %.2f\n",
                       temp->rollno, temp->name, temp->percentage);
            }
            temp = temp->next;
        }
        printf("Enter the roll number of the record to modify:\n");
        scanf("%d", &roll);
    }

    mod_by_roll(head, roll);
}

static void mod_by_perc(SLL *head)
{
    float perc;
    int count = 0, roll;
    SLL *temp = head;

    printf("Enter percentage to search:\n");
    scanf("%f", &perc);

    while (temp != NULL)
    {
        if (temp->percentage == perc)
        {
            count++;
            roll = temp->rollno;
        }
        temp = temp->next;
    }

    if (count == 0)
    {
        printf("Record with percentage %.2f not found.\n", perc);
        return;
    }
    else if (count > 1)
    {
        printf("Multiple records found with percentage %.2f:\n", perc);
        temp = head;
        while (temp != NULL)
        {
            if (temp->percentage == perc)
            {
                printf("Roll No: %d | Name: %s | Percentage: %.2f\n",
                       temp->rollno, temp->name, temp->percentage);
            }
            temp = temp->next;
        }
        printf("Enter the roll number of the record to modify:\n");
        scanf("%d", &roll);
    }

    mod_by_roll(head, roll);
}

void stud_mod(SLL *head)
{
    if (head == NULL)
    {
        printf("No records found\n");
        return;
    }

    char op;
    int roll;

    printf("Enter which record to search for modification\n");
    printf("R/r : Search by roll number\n");
    printf("N/n : Search by name\n");
    printf("P/p : Search by percentage\n");
    scanf(" %c", &op);

    switch (op)
    {
        case 'R':
        case 'r':
            printf("Enter roll number to modify:\n");
            scanf("%d", &roll);
            mod_by_roll(head, roll);
            break;

        case 'N':
        case 'n':
            mod_by_name(head);
            break;

        case 'P':
        case 'p':
            mod_by_perc(head);
            break;

        default:
            printf("Invalid option.\n");
    }
}
