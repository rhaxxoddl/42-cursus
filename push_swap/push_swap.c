/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 11:32:53 by sanjeon           #+#    #+#             */
/*   Updated: 2021/07/07 16:45:26 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int         sort_check(stack *ab_stack)
{
    node    *temp;

    temp = ab_stack->a_head;
    while (temp->next)
    {
        if (temp->value < temp->next->value)
        return (0);
    }
    return (1);
}

int         push_swap(stack *ab_stack)
{
    if (sort_check(ab_stack) == 1)
        return (0);
    return (0);
}

void        print_stack_info(stack *ab_stack)
{
    if (ab_stack->a_head->next != 0)
        printf("a_top : %d\n", ab_stack->a_head->next->value);
    if (ab_stack->b_head->next != 0)
        printf("b_top : %d\n", ab_stack->b_head->next->value);
    if (ab_stack->a_bottom != 0)
        printf("a_bottom : %d\n", ab_stack->a_bottom->value);
    if (ab_stack->b_bottom != 0)
        printf("b_bottom : %d\n", ab_stack->b_bottom->value);
}

void        print_stack(stack *ab_stack)
{
    node    *current;
    
    if (ab_stack->a_head->next != 0)
    {
        current = ab_stack->a_head->next;
        printf("A : top");
        while (current != 0)
        {
            printf(" %d", current->value);
            current = current->next;
        }
        printf(" bottom\n");
    }
    if (ab_stack->b_head->next != 0)
    {
        current = ab_stack->b_head->next;
        printf("B : top");
        while (current != 0)
        {
            printf(" %d", current->value);
            current = current->next;
        }
        printf(" bottom\n");
    }
}

int         main(int argc, char *argv[])
{
    int     i;
    node    *current;
    stack   *ab_stack;

    if (argc <= 1 || argv[0] == 0)
    {
        return(print_error());
    }
    i = 1;
    if (!(ab_stack = ft_calloc(1, sizeof(stack))))
        return(print_error());
    if (start_node(ab_stack) != 0)
        return(print_error());
    current = ab_stack->a_head;
    while (argv[i] != 0)
    {
        if (add(current, ft_atoi(argv[i])) == -1)
            return(print_error());
        current = current->next;
        ab_stack->a_bottom = current;
        i++;
    }
    if(atob(i - 1, ab_stack) == -1)
        return(-1);
    print_stack(ab_stack);
    print_stack_info(ab_stack);
    print_stack(ab_stack);
    return(0);
}
