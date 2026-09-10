#include "apc.h"

/* Check command-line arguments and operands. */
int cla_validation(int argc, char *argv[])
{
    int i, j;

    if (argc != 4)
        return FAILURE;

    if (argv[2][0] != '+' && argv[2][0] != '-' &&
        argv[2][0] != 'x' && argv[2][0] != 'X' &&
        argv[2][0] != '/')
        return FAILURE;

    if (argv[2][1] != '\0')
        return FAILURE;

    for (i = 0; argv[1][i] != '\0'; i++)
    {
        if (argv[1][i] < '0' || argv[1][i] > '9')
            return FAILURE;
    }

    for (j = 0; argv[3][j] != '\0'; j++)
    {
        if (argv[3][j] < '0' || argv[3][j] > '9')
            return FAILURE;
    }

    if (i == 0 || j == 0)
        return FAILURE;

    return SUCCESS;
}

/* Create a doubly linked list containing one decimal digit per node. */
void create_list(char *opr, node **head, node **tail)
{
    int i;

    for (i = 0; opr[i] != '\0'; i++)
        insert_last(head, tail, opr[i] - '0');
}

/* Insert at beginning. */
int insert_first(node **head, node **tail, int data)
{
    node *new = malloc(sizeof(node));

    if (new == NULL)
        return FAILURE;

    new->data = data;
    new->prev = NULL;
    new->next = *head;

    if (*head == NULL)
        *tail = new;
    else
        (*head)->prev = new;

    *head = new;
    return SUCCESS;
}

/* Insert at end. */
int insert_last(node **head, node **tail, int data)
{
    node *new = malloc(sizeof(node));

    if (new == NULL)
        return FAILURE;

    new->data = data;
    new->next = NULL;
    new->prev = *tail;

    if (*tail == NULL)
        *head = new;
    else
        (*tail)->next = new;

    *tail = new;
    return SUCCESS;
}

/* Delete the complete list. */
int delete_list(node **head, node **tail)
{
    node *temp = *head;

    while (temp != NULL)
    {
        node *next = temp->next;
        free(temp);
        temp = next;
    }

    *head = NULL;
    *tail = NULL;
    return SUCCESS;
}

/* Print a number represented by the list. */
void print_list(node *head)
{
    if (head == NULL)
    {
        printf("0");
        return;
    }

    while (head != NULL)
    {
        printf("%d", head->data);
        head = head->next;
    }
}

/* Return number of nodes. */
int list_len(node *head)
{
    int count = 0;

    while (head != NULL)
    {
        count++;
        head = head->next;
    }

    return count;
}

/* Remove leading zero nodes, but keep one zero for value 0. */
void remove_pre_zeros(node **head)
{
    node *temp = *head;

    while (temp != NULL && temp->data == 0 && temp->next != NULL)
    {
        temp = temp->next;
        free(temp->prev);
        temp->prev = NULL;
        *head = temp;
    }
}

/* Compare two positive numbers represented by lists. */
int compare_list(node *head1, node *head2)
{
    int len1 = list_len(head1);
    int len2 = list_len(head2);

    if (len1 > len2)
        return OPERAND1;
    if (len1 < len2)
        return OPERAND2;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data > head2->data)
            return OPERAND1;
        if (head1->data < head2->data)
            return OPERAND2;

        head1 = head1->next;
        head2 = head2->next;
    }

    return SAME;
}
