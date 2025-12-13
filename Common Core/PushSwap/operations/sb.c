/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymosca-- <ymosca--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:37:48 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/11 21:23:54 by ymosca--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void sb(t_list **stack_b)
{
    t_list *first;
    t_list *second;
    long tmp;

    if (!stack_b || !*stack_b || !(*stack_b)->next)
        return ;

    first = *stack_b;
    second = (*stack_b)->next;

    tmp = first->value;
    first->value = second->value;
    second->value = tmp;
    
    write(1, "sb\n", 3);
}
