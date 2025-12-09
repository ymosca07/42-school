/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:50:14 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/04 16:25:10 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_min(t_list **stack_a, t_list **stack_b, long min)
{
    t_list *node;

    node = *stack_a;
    
    while (node && node->value != min)
    {
        node = node->next;
    }
    if (node && node->value == min)
    {
        while (((*stack_a)->value) != node->value)
            ra(stack_a);
        pb(stack_a, stack_b);
        return ;
    }
}