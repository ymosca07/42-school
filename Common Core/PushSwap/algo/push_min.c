/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymosca-- <ymosca--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:50:14 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/11 21:22:21 by ymosca--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    push_min(t_list **stack_a, t_list **stack_b, long min, int min_position)
{
    t_list *node;

    node = *stack_a;
    
    while (node && node->value != min)
    {
        node = node->next;
    }
    if (node && node->value == min)
    {
        if (min_position <= 2)
        {
            while (((*stack_a)->value) != node->value)
                ra(stack_a);
        }
        else if (min_position > 2)
        {
            while (((*stack_a)->value) != node->value)
                rra(stack_a);
        }
        pb(stack_a, stack_b);
        return ;
    }
}
