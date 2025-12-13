/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymosca-- <ymosca--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:09:43 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/13 01:21:41 by ymosca--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
    write(1, "rb\n", 3);
}
