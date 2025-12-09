/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:46:32 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/04 16:47:25 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    pa(t_list **stack_a, t_list **stack_b)
{
    if (!stack_a || !stack_b || !*stack_b)
        return ;
    t_list  *first_b;
    first_b = *stack_b;
    *stack_b = (*stack_b)->next;
    first_b->next = NULL;

    ft_lstadd_front(stack_a, first_b);
    
    write(1, "pa\n", 3);
}
