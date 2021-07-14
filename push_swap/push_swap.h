/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 11:45:42 by sanjeon           #+#    #+#             */
/*   Updated: 2021/07/07 16:42:17 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PUSH_SWAP_H__
# define __PUSH_SWAP_H__

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "./includes/Libft/libft.h"


# define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )

typedef struct NODE{
	struct NODE *next;
	struct NODE *before;
	int value; 
} node;

typedef struct {
	node	*a_head;
	node	*a_bottom;
	node	*b_head;
	node	*b_bottom;
} stack;

/*
linkedlist.c
*/
int			switch_node(node *a);
int			move_node(node *target, node *dest);
int         pop(node *target);
int         add(node *head, int value);

/*
util.c
*/
int			print_error();
int			find_pivot(int array[]);
void		q_sort(int array[], int left, int right);
int			*node_to_sort_array(node *src, int length);

/*
tool1.c
*/
int			sa(stack *ab_stack);
int			sb(stack *ab_stack);
int			ss(stack *ab_stack);
int			pa(stack *ab_stack);
int			pb(stack *ab_stack);

/*
tool2.c
*/
int			ra(stack *ab_stack);
int			rb(stack *ab_stack);
int			rr(stack *ab_stack);
int			rra(stack *ab_stack);
int			rrb(stack *ab_stack);

/*
tool3.c
*/
int			rrr(stack *ab_stack);
int     	start_node(stack *ab_stack);
int			atob(int l, stack *ab_stack);
int			btoa(int l, stack *ab_stack);
#endif