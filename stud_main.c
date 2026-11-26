#include"student.h"
int main()
{
    char op,c;
    SLL *head = NULL;
    while(1)
    {
        printf("Enter the operation to be performed:\na/A. Add\nd/D. Delete\ns/S. Show\nm/M. Modify\nv/V. Save\ne/E. Exit\nt/T. Sort\nl/L. Delete All\nr/R. Reverse_link\n");
        scanf(" %c",&op);
        switch(op)
        {
            case 'A':
            case 'a':
                    stud_add(&head);break;    
            case 'D':
            case 'd':
                    stud_del(&head);break;
            case 'S':
            case 's':
                    stud_show(head);break;
            case 'M':
            case 'm':
                    stud_mod(head);break;
            case 'V':
            case 'v':
                    stud_save(head);break;
             case 'E':
             case 'e':
            {
                char exit_op;
                printf("S/s : Save and exit\n");
                printf("E/e : Exit without saving\n");
                printf("Enter your choice: ");
                scanf(" %c", &exit_op);

                if (exit_op == 'S' || exit_op == 's')
                {
                    stud_save(head);
                    return 0;
                }
                else if (exit_op == 'E' || exit_op == 'e')
                {
                    stud_delall(&head);
                    return 0;
                }
                else
                {
                    printf("Invalid choice.\n");
                }
                break;
            }

              case 'T':
              case 't':
                      stud_sort(head);break;
            case 'L':
            case 'l':
                    stud_delall(&head);break;
            case 'R':
            case 'r':
                    stud_revlink(&head);break; 
            default:printf("Invalid option\n");
        }
    }

}