#include "push_swap.h"

void         print_error(int type, node *head, stack *target)
{
    write(1, "ERROR\n", 6);
    exit(1);
}

void    linkedlist_free(node *head)
{
    node    *temp;

    temp = head->next;
    while(temp->next != 0)
        temp = temp->next;
    while(temp->before != 0)
    {
        temp = temp->before;
        free(temp->next);
    }
    head = 0;
}

void    stack_free(stack *target)
{
    if (target->a_head != 0)
        linkedlist_free(target->a_head);
    if (target->b_head != 0)
        linkedlist_free(target->b_head);
    free(target);
}