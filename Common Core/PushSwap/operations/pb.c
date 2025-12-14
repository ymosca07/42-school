/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymosca-- <ymosca--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:52:05 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/11 21:23:16 by ymosca--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_a;

	if (!stack_a || !stack_b || !*stack_a)
		return ;
	first_a = *stack_a;
	*stack_a = (*stack_a)->next;
	first_a->next = NULL;
	ft_lstadd_front(stack_b, first_a);
	write(1, "pb\n", 3);
}
