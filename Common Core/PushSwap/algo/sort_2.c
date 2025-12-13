/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymosca-- <ymosca--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:13:15 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/11 21:22:27 by ymosca--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void sort_2(t_list **stack_a)
{
    t_list *first;
    t_list *second;

    first = *stack_a;
    second = (*stack_a)->next;
    if (first->value > second->value)
        sa(stack_a);
    return ;
}
