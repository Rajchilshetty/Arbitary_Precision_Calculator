#include "apc.h"

void addition(node *tail1, node *tail2, node **headR, node **tailR)
{
    int carry = 0;
    int sum;

    while (tail1 != NULL || tail2 != NULL || carry)
    {
        sum = carry;

        if (tail1 != NULL)
        {
            sum += tail1->data;
            tail1 = tail1->prev;
        }

        if (tail2 != NULL)
        {
            sum += tail2->data;
            tail2 = tail2->prev;
        }

        insert_first(headR, tailR, sum % 10);
        carry = sum / 10;
    }
}
