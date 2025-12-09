/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:09:43 by yamosca-          #+#    #+#             */
/*   Updated: 2025/11/26 17:18:35 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rb(t_list **stack_b)
{
    t_list *first;
    t_list *last;
    
    if (!stack_b || !*stack_b || !(*stack_b)->next)
        return ;
        
    first = *stack_b;
    last = *stack_b;
    
    while (last->next)
        last = last->next;
    last->next = first;
    *stack_b = first->next;
    first->next = NULL;
    write(1, "ra\n", 3);
}
