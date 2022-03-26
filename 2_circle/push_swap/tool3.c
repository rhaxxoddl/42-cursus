/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 21:56:40 by marvin            #+#    #+#             */
/*   Updated: 2021/07/15 21:56:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void     rrr(stack *ab_stack)
{
    rra(ab_stack);
    rrb(ab_stack);
    write(1, "rrr\n", 4);
}

void     start_node(stack *ab_stack)
{
    if (!(ab_stack->a_head = ft_calloc(1, sizeof(node))))
        print_error();
    if (!(ab_stack->b_head = ft_calloc(1, sizeof(node))))
        print_error();
}

void    atob(int l, stack *ab_stack)
{
    int i;
    int pivot_value;
    int ra_count;
    int pb_count;

    i = 0;
    if (l <= 1)
        return;
    pivot_value = find_pivot(node_to_sort_array(ab_stack->a_head->next, l));
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
    btoa(pb_count, ab_stack);
    while(pb_count > 0)
    {
        pa(ab_stack);
        pb_count--;
    }
}

void    btoa(int l, stack *ab_stack)
{
    int i;
    int pivot_value;
    int rb_count;
    int pa_count;

    i = 0;
    if (l <= 1)
        return;
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
    atob(pa_count, ab_stack);
    while(pa_count > 0)
    {
        pb(ab_stack);
        pa_count--;
    }
}