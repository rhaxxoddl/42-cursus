/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 11:57:16 by sanjeon           #+#    #+#             */
/*   Updated: 2021/06/20 14:12:55 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	sa(stack *ab_stack)
{
    if (switch_node(ab_stack->a_head->next) < 0)
        return(-1);
    if (ab_stack->a_head->next->next->next == 0)
        ab_stack->a_bottom = ab_stack->a_head->next->next;
    write(1, "sa\n", 3);
    return(1);
}

int     sb(stack *ab_stack)
{
    if (switch_node(ab_stack->b_head->next) < 0)
        return(-1);
    if (ab_stack->b_head->next->next->next == 0)
        ab_stack->b_bottom = ab_stack->b_head->next->next;
    write(1, "sb\n", 3);
    return(1);
}

int     ss(stack *ab_stack)
{
    if (sa(ab_stack) < 0)
        return(-1);
    if (sb(ab_stack) < 0)
        return(-1);
    write(1, "ss\n", 3);
    return(0);
}
int     pa(stack *ab_stack)
{
    if (ab_stack->a_bottom == 0)
        ab_stack->a_bottom = ab_stack->b_head->next;
    if (ab_stack->b_head->next != 0)
        if (move_node(ab_stack->b_head->next, ab_stack->a_head) < 0)
            return(-1);
    write(1, "pa\n", 3);
    return(1);
}

int     pb(stack *ab_stack)
{
    if (ab_stack->b_bottom == 0)
        ab_stack->b_bottom = ab_stack->a_head->next;
    if (ab_stack->a_head->next != 0)
        if (move_node(ab_stack->a_head->next, ab_stack->b_head) < 0)
            return(-1);
    write(1, "pb\n", 3);
    return(1);
}