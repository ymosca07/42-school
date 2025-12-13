/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymosca-- <ymosca--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:50:09 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/11 21:22:18 by ymosca--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    push_max(t_list **stack_a, t_list **stack_b, long max, int max_position)
{
    t_list *node;

    node = *stack_a;
    
    while (node && node->value != max)
    {
        node = node->next;
    }
    if (node && node->value == max)
    {
        if (max_position <= 2)
        {
            while (((*stack_a)->value) != node->value)
                ra(stack_a);
        }
        else if (max_position > 2)
        {
            while (((*stack_a)->value) != node->value)
                rra(stack_a);
        }
        pb(stack_a, stack_b);
        return ;
    }
}
