#include "push_swap.h"

// top_target과 다음 노드의 순서를 바꿈.
int         switch_node(node *top_target)
{
    node    *temp_node;
    int     temp_value;

    if (top_target == 0 || top_target->next == 0)
    {
        printf("[ERROR]switch_node : have not top_target OR top_target->next\n");
        return(-1);
    }
    temp_node = top_target->next;
    temp_value = pop(top_target);
    if (add(temp_node, temp_value) < 0)
        return(-1);
    return(1);
}

// target을 dest->next로 옮김
int         move_node(node *target, node *dest)
{
    int     temp_value;
    if (target == 0 || dest == 0)
    {
        printf("[ERROR]move_node : have not target OR dest\n");
        return(-1);
    }
    temp_value = pop(target);
    if (add(dest, temp_value) < 0)
        return(-1);
    return(1);
}

// target에 value 반환하고 제거
int         pop(node *target)
{
    node    *temp;
    int     value;

    if (target == 0)
    {
        printf("[ERROR]pop : have not target\n");
        return(-1);
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

// head->next에 노드 추가
int         add(node *head, int value)
{
    node        *temp;
    if (head == 0)
    {
        printf("[ERROR]add : have not head\n");
        return(-1);
    }
    if (!(temp = ft_calloc(1, sizeof(node))))
        return(-1);
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
    return(1);
}
