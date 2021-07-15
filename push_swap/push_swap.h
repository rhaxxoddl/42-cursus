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
#include <limits.h>
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
void		switch_node(node *a);
void		move_node(node *target, node *dest);
int         pop(node *target);
void        add(node *head, int value);

/*
util.c
*/
void		print_error();
int			find_pivot(int array[]);
void		q_sort(int array[], int left, int right);
int			*node_to_sort_array(node *src, int length);

/*
tool1.c
*/
void		sa(stack *ab_stack);
void		sb(stack *ab_stack);
void		ss(stack *ab_stack);
void		pa(stack *ab_stack);
void		pb(stack *ab_stack);

/*
tool2.c
*/
void		ra(stack *ab_stack);
void		rb(stack *ab_stack);
void		rr(stack *ab_stack);
void		rra(stack *ab_stack);
void		rrb(stack *ab_stack);

/*
tool3.c
*/
void		rrr(stack *ab_stack);
void    	start_node(stack *ab_stack);
void		atob(int l, stack *ab_stack);
void		btoa(int l, stack *ab_stack);
#endif