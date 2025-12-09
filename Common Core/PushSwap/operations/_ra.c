/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:07:07 by yamosca-          #+#    #+#             */
/*   Updated: 2025/11/27 11:07:27 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    _ra(t_list **stack_a)
{
    t_list *first;
    t_list *last;
    
    if (!*stack_a || !(*stack_a)->next)
        return ;
        
    first = *stack_a;
    last = *stack_a;
    
    while (last->next)
        last = last->next;
    last->next = first;
    *stack_a = first->next;
    first->next = NULL;
}