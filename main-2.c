#include "apc.h"

int main(int argc, char *argv[])
{
    node *head1 = NULL, *tail1 = NULL;
    node *head2 = NULL, *tail2 = NULL;
    node *headR = NULL, *tailR = NULL;

    int cmp;
    int negative = 0;

    if (cla_validation(argc, argv) == FAILURE)
    {
        printf("Usage: ./a.out <operand1> <operator> <operand2>\n");
        printf("Example: ./a.out 123 + 456\n");
        return FAILURE;
    }

    create_list(argv[1], &head1, &tail1);
    create_list(argv[3], &head2, &tail2);

    remove_pre_zeros(&head1);
    remove_pre_zeros(&head2);

    switch (argv[2][0])
    {
        case '+':
            addition(tail1, tail2, &headR, &tailR);
            break;

        case '-':
            cmp = compare_list(head1, head2);

            if (cmp == SAME)
            {
                insert_last(&headR, &tailR, 0);
            }
            else if (cmp == OPERAND1)
            {
                subtraction(tail1, tail2, &headR, &tailR);
            }
            else
            {
                subtraction(tail2, tail1, &headR, &tailR);
                negative = 1;
            }
            break;

        case 'x':
        case 'X':
            multiplication(tail1, tail2, &headR, &tailR);
            break;

        case '/':
            if (compare_list(head2, head1) == SAME &&
                head2 != NULL && head2->data == 0)
            {
                printf("Error: Division by zero\n");
                delete_list(&head1, &tail1);
                delete_list(&head2, &tail2);
                return FAILURE;
            }

            /* Explicit zero check also handles values such as 0000. */
            if (list_len(head2) == 1 && head2->data == 0)
            {
                printf("Error: Division by zero\n");
                delete_list(&head1, &tail1);
                delete_list(&head2, &tail2);
                return FAILURE;
            }

            division(head1, head2, &headR, &tailR);
            break;

        default:
            printf("Invalid operator\n");
            delete_list(&head1, &tail1);
            delete_list(&head2, &tail2);
            return FAILURE;
    }

    printf("Result: ");
    if(negative)
    printf("-");
    print_list(headR);
    printf("\n");

    delete_list(&head1, &tail1);
    delete_list(&head2, &tail2);
    delete_list(&headR, &tailR);

    return SUCCESS;
}
