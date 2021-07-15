/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 21:56:58 by marvin            #+#    #+#             */
/*   Updated: 2021/07/15 21:56:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// top_target과 다음 노드의 순서를 바꿈.
void         switch_node(node *top_target)
{
    node    *temp_node;
    int     temp_value;

    if (top_target == 0 || top_target->next == 0)
    {
        printf("[ERROR]switch_node : have not top_target OR top_target->next\n");
        print_error();
    }
    temp_node = top_target->next;
    temp_value = pop(top_target);
    add(temp_node, temp_value);
}

// target을 dest->next로 옮김
void         move_node(node *target, node *dest)
{
    int     temp_value;
    if (target == 0 || dest == 0)
    {
        printf("[ERROR]move_node : have not target OR dest\n");
        print_error();
    }
    temp_value = pop(target);
    add(dest, temp_value);
}

// target에 value 반환하고 제거
int         pop(node *target)
{
    node    *temp;
    int     value;

    if (target == 0)
    {
        printf("[ERROR]pop : have not target\n");
        print_error(1);
    }
    temp = target;
    value = temp->value;
    if (target->next != 0)
    {
        target->next->before = target->before;
        target->before->next = target->next;
    }
    else
        target->before->next = 0;
    free(temp);
    return(value);
}

// next에 노드 추가
void         add(node *head, int value)
{
    node        *temp;
    if (head == 0)
    {
        printf("[ERROR]add : have not head\n");
        print_error();
    }
    if (!(temp = ft_calloc(1, sizeof(node))))
        print_error();
    temp->value = value;
    temp->before = head;
    if (head->next != 0)
    {
        temp->next = head->next;
        head->next->before = temp;
    }
    else
        temp->next = 0;
    head->next = temp;
}
