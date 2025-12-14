/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _sa.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymosca-- <ymosca--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:08:22 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/11 21:23:07 by ymosca--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	_sa(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;
	long	tmp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = (*stack_a)->next;
	tmp = first->value;
	first->value = second->value;
	second->value = tmp;
}
