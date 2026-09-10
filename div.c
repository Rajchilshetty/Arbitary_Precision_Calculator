#include "apc.h"

/*
 * Long division for positive integers.
 * The quotient is stored in headR/tailR.
 */
void division(node *head1, node *head2, node **headR, node **tailR)
{
    node *current = NULL, *currentTail = NULL;
    node *quotient = NULL, *quotientTail = NULL;
    node *divisorTail = head2;
    int count;

    /* Find the divisor tail because subtraction() expects tail pointers. */
    while (divisorTail != NULL && divisorTail->next != NULL)
        divisorTail = divisorTail->next;

    while (head1 != NULL)
    {
        /*
         * Bring the next dividend digit down to the current remainder.
         */
        insert_last(&current, &currentTail, head1->data);
        remove_pre_zeros(&current);

        count = 0;

        /*
         * The quotient digit is between 0 and 9.
         * Repeated subtraction is therefore sufficient here.
         */
        while (compare_list(current, head2) != OPERAND2)
        {
            node *newHead = NULL;
            node *newTail = NULL;

            subtraction(currentTail, divisorTail, &newHead, &newTail);

            delete_list(&current, &currentTail);
            current = newHead;
            currentTail = newTail;

            count++;
        }

        insert_last(&quotient, &quotientTail, count);
        head1 = head1->next;
    }

    remove_pre_zeros(&quotient);

    if (quotient == NULL)
        insert_last(headR, tailR, 0);
    else
    {
        *headR = quotient;
        *tailR = quotientTail;
    }

    delete_list(&current, &currentTail);
}
