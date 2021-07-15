#include "push_swap.h"


void        swap(int *x, int *y)
{
    int     temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

int         find_pivot(int *array)
{
    int     pibot_index;
    int     temp;

    if(array == 0)
        print_error(1);
    pibot_index = (int)sizeof(array) / (int)sizeof(int) / 2;
    temp = array[pibot_index];
    free(array);
    return (temp);
}

void        q_sort(int *array, int left, int right)
{
    int     pivot;
    int     low;
    int     high;

    if (left >= right)
        print_error();
    pivot = array[left];
    low = left;
    high = right + 1;
    while(low < high)
    {
        low++;
        while (array[low] < pivot && low <= right)
            low++;
        high--;
        while (array[high] > pivot && high >= left)
            high--;
        if (low < high)
            swap(&array[low], &array[high]);
    }
    swap(&array[high], &array[left]);
    q_sort(array, left, high - 1);
    q_sort(array, high + 1, right);
}

int        *node_to_sort_array(node *src, int length)
{
    int     *temp_array;
    int     size;
    node    *src_current;

    src_current = src;
    if (!(temp_array = ft_calloc(length, sizeof(int))))
        print_error();
    size = 0;
    while(size < length)
    {
        temp_array[size++] = src_current->value;
        src_current = src_current->next;
    }
    q_sort(temp_array, 0, size - 1);
    return(temp_array);
}