#include "push_swap.h"

int     rrr(stack *ab_stack)
{
    if (rra(ab_stack) < 0)
        return(-1);
    if (rrb(ab_stack) < 0)
        return(-1);
    write(1, "rrr\n", 4);
    return(1);
}

int     start_node(stack *ab_stack)
{
    if (!(ab_stack->a_head = ft_calloc(1, sizeof(node))))
        return(-1);
    if (!(ab_stack->b_head = ft_calloc(1, sizeof(node))))
        return(-1);
    return(0);
}

int    atob(int l, stack *ab_stack)
{
    int i;
    int pivot_value;
    int ra_count;
    int pb_count;

    i = 0;
    if (l <= 1)
        return(0);
    if((pivot_value = find_pivot(node_to_sort_array(ab_stack->a_head->next, l))) == -1)
        return(-1);
    ra_count = 0;
    pb_count = 0;
    while(i < l)
    {
        if(ab_stack->a_head->next->value > pivot_value)
        {
            ra(ab_stack);
            ra_count++;
        }
        else
        {
            pb(ab_stack);
            pb_count++;
        }
        i++;
    }
    while(ra_count > 0)
    {
        rra(ab_stack);
        ra_count--;
    }
    if(atob(ra_count, ab_stack) == -1)
        return(-1);
    if(btoa(pb_count, ab_stack) == -1)
        return(-1);
    return(0);
}

int    btoa(int l, stack *ab_stack)
{
    int i;
    int pivot_value;
    int rb_count;
    int pa_count;

    i = 0;
    if (l <= 1)
        return(0);
    pivot_value = find_pivot(node_to_sort_array(ab_stack->a_head->next, l));
    rb_count = 0;
    pa_count = 0;;
    while(i < l)
    {
        if (ab_stack->a_head->next->value > pivot_value)
        {
            rb(ab_stack);
            rb_count++;
        }
        else
        {
            pa(ab_stack);
            pa_count++;
        }
        i++;
    }
    while(rb_count > 0)
    {
        rrb(ab_stack);
        rb_count--;
    }
    if(atob(pa_count, ab_stack) == -1)
        return(-1);
    if(btoa(rb_count, ab_stack) == -1)
        return(-1);
    return(0);
}