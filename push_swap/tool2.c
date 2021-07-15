/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 21:56:42 by marvin            #+#    #+#             */
/*   Updated: 2021/07/15 21:56:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void     ra(stack *ab_stack)
{
    move_node(ab_stack->a_head->next, ab_stack->a_bottom);
    ab_stack->a_bottom = ab_stack->a_bottom->next;
    write(1, "ra\n", 3);
}

void     rb(stack *ab_stack)
{
    move_node(ab_stack->b_head->next, ab_stack->b_bottom);
    ab_stack->b_bottom = ab_stack->b_bottom->next;
    write(1, "rb\n", 3);
}

void     rr(stack *ab_stack)
{
    ra(ab_stack);
    rb(ab_stack);
    write(1, "rr\n", 3);
}

void     rra(stack *ab_stack)
{
    node    *temp;

    temp = ab_stack->a_bottom->before;
    move_node(ab_stack->a_bottom, ab_stack->a_head);
    ab_stack->a_bottom = temp;
    write(1, "rra\n", 4);
}

void     rrb(stack *ab_stack)
{
    node    *temp;

    temp = ab_stack->b_bottom->before;
    move_node(ab_stack->b_bottom, ab_stack->b_head);
    ab_stack->b_bottom = temp;
    write(1, "rrb\n", 4);
}