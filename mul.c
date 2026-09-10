#include "apc.h"

void multiplication(node *tail1, node *tail2, node **headR, node **tailR)
{
    node *p1, *p2;
    int len1, len2;
    int *a, *b, *result;
    int i, j, k;

    /*
     * The function receives tail pointers.
     * Move from each tail to its head first.
     */
    p1 = tail1;
    while (p1 != NULL && p1->prev != NULL)
        p1 = p1->prev;

    p2 = tail2;
    while (p2 != NULL && p2->prev != NULL)
        p2 = p2->prev;

    len1 = list_len(p1);
    len2 = list_len(p2);

    a = malloc(sizeof(int) * len1);
    b = malloc(sizeof(int) * len2);
    result = calloc(len1 + len2, sizeof(int));

    if (a == NULL || b == NULL || result == NULL)
    {
        free(a);
        free(b);
        free(result);
        return;
    }

    i = 0;
    while (p1 != NULL)
    {
        a[i++] = p1->data;
        p1 = p1->next;
    }

    i = 0;
    while (p2 != NULL)
    {
        b[i++] = p2->data;
        p2 = p2->next;
    }

    /*
     * School multiplication:
     *
     *       123
     *     x 456
     *     -----
     *
     * Each pair of digits is multiplied and placed
     * in its corresponding result position.
     */
    for (i = len1 - 1; i >= 0; i--)
    {
        for (j = len2 - 1; j >= 0; j--)
        {
            k = i + j + 1;
            result[k] += a[i] * b[j];
        }
    }

    /* Convert every result position to a single decimal digit. */
    for (k = len1 + len2 - 1; k > 0; k--)
    {
        result[k - 1] += result[k] / 10;
        result[k] %= 10;
    }

    /* Skip leading zeroes. */
    k = 0;
    while (k < len1 + len2 - 1 && result[k] == 0)
        k++;

    for (; k < len1 + len2; k++)
        insert_last(headR, tailR, result[k]);

    free(a);
    free(b);
    free(result);
}
