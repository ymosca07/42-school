/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymosca-- <ymosca--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:56:41 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/11 21:23:31 by ymosca--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    rrb(t_list **stack_b)
{
    t_list *before_last;
    t_list *last;
    
    if (!stack_b || !*stack_b || !(*stack_b)->next)
        return ;
        
    last = *stack_b;
    before_last = *stack_b;
    while (last->next)
        last = last->next;
    while (before_last->next->next)
        before_last = before_last->next;
    before_last->next = NULL;
    last->next = *stack_b;
    *stack_b = last;
    write(1, "rrb\n", 4);
}
