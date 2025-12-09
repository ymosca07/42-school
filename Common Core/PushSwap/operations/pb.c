/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:52:05 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/04 16:46:14 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    pb(t_list **stack_a, t_list **stack_b)
{
    if (!stack_a || !stack_b || !*stack_a)
        return ;
    t_list  *first_a;
    first_a = *stack_a;
    *stack_a = (*stack_a)->next;

    first_a->next = NULL;
    ft_lstadd_front(stack_b, first_a);
    
    write(1, "pb\n", 3);
}
