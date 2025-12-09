/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:38:37 by yamosca-          #+#    #+#             */
/*   Updated: 2025/11/26 15:37:00 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_list **stack_a)
{
    t_list *first;
    t_list *second;
    long tmp;

    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return ;

    first = *stack_a;
    second = (*stack_a)->next;

    tmp = first->value;
    first->value = second->value;
    second->value = tmp;
    
    write(1, "sa\n", 3);
}
