/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:50:00 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/04 16:41:05 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_3(t_list **stack_a)
{
    long first;
    long second;
    long third;

    if (!stack_a || !*stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
        return;

    first = (*stack_a)->value;
    second = (*stack_a)->next->value;
    third = (*stack_a)->next->next->value;
    if (first > second && second > third && third < first)
    {
        ra(stack_a);
        sa(stack_a);
    }
    else if (first < second && second > third && first < third)
    {
        ra(stack_a);
        ra(stack_a);
        sa(stack_a);
    }
    else if (first < second && second > third && first > third)
        rra(stack_a);
    else if (first > second && second < third && first < third)
        sa(stack_a);
    else if (first > second && second < third && third < first)
        ra(stack_a);
}
