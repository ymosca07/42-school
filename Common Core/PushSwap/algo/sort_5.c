/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymosca-- <ymosca--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:56:18 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/11 21:22:39 by ymosca--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void sort_5(t_list **stack_a, t_list **stack_b)
{
    long first;
    long second;
    long third;
    long fourth;
    long fifth;

    first = (*stack_a)->value;
    second = (*stack_a)->next->value;
    third = (*stack_a)->next->next->value;
    fourth = (*stack_a)->next->next->next->value;
    fifth = (*stack_a)->next->next->next->next->value;

    if (first == 1 && second == 2 && third == 3
        && fourth == 4 && fifth == 5)
        return ;
    
    search_min_max(stack_a, stack_b);
    
    sort_3(stack_a);
    pa(stack_a, stack_b);
    ra(stack_a);
    pa(stack_a, stack_b);
    return ;
}
