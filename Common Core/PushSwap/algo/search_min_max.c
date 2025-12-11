/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_min_max.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:07:13 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/11 17:29:56 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void append_index(t_list **stack_a)
{
    t_list *cursor;
    int index;

    cursor = *stack_a;
    index = 0;
    while (cursor)
    {
        cursor->index = index;
        cursor = cursor->next;
    }
}

void    search_min_max(t_list **stack_a, t_list **stack_b)
{
    long min;
    long max;
    int len_min;
    int len_max;
    t_list *node;

    len_max = 0;
    len_min = 0;
    max = (*stack_a)->value;
    min = (*stack_a)->value;
    node = *stack_a;
    append_index(stack_a);
    while (node)
    {
        if (node->value < min)
        {
            min = node->value;
            len_min = node->index;
        }
        if (node->value > max)
        {
            max = node->value;
            len_max = node->index;
        }
        node = node->next;
    }
    push_min(stack_a, stack_b, min, len_min);
    push_max(stack_a, stack_b, max, len_max);
    return ;
}
