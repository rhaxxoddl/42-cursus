
#include "push_swap.h"

int     ra(stack *ab_stack)
{
    if (move_node(ab_stack->a_head->next, ab_stack->a_bottom) < 0)
        return(-1);
    ab_stack->a_bottom = ab_stack->a_bottom->next;
    write(1, "ra\n", 3);
    return(1);
}

int     rb(stack *ab_stack)
{
    if (move_node(ab_stack->b_head->next, ab_stack->b_bottom) < 0)
        return(-1);
    ab_stack->b_bottom = ab_stack->b_bottom->next;
    write(1, "rb\n", 3);
    return(1);
}

int     rr(stack *ab_stack)
{
    if (ra(ab_stack) < 0)
        return(-1);
    if (rb(ab_stack) < 0)
        return(-1);
    write(1, "rr\n", 3);
    return(1);
}

int     rra(stack *ab_stack)
{
    node    *temp;

    temp = ab_stack->a_bottom->before;
    if (move_node(ab_stack->a_bottom, ab_stack->a_head) < 0)
        return(-1);
    ab_stack->a_bottom = temp;
    write(1, "rra\n", 4);
    return(1);
}

int     rrb(stack *ab_stack)
{
    node    *temp;

    temp = ab_stack->b_bottom->before;
    if (move_node(ab_stack->b_bottom, ab_stack->b_head) < 0)
        return(-1);
    ab_stack->b_bottom = temp;
    write(1, "rrb\n", 4);
    return(1);
}