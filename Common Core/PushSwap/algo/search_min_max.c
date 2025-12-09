/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_min_max.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:07:13 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/04 16:18:01 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    search_min_max(t_list **stack_a, t_list **stack_b)
{
    long min;
    long max;
    t_list *node;

    max = (*stack_a)->value;
    min = (*stack_a)->value;
    node = *stack_a;
    while (node)
    {
        if (node->value < min)
            min = node->value;
        if (node->value > max)
            max = node->value;
        node = node->next;
    }
    push_min(stack_a, stack_b, min);
    push_max(stack_a, stack_b, max);
    return ;
}
