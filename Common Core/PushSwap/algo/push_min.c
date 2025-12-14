/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:50:14 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/14 17:59:53 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	moov_node(t_list **stack_a, int min_pos, long min_val)
{
	if (min_pos <= 5 / 2)
	{
		while ((*stack_a)->value != min_val)
			ra(stack_a);
	}
	else
	{
		while ((*stack_a)->value != min_val)
			rra(stack_a);
	}
}

void	push_min(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		min_pos;
	long	min_val;
	int		i;

	tmp = *stack_a;
	min_val = tmp->value;
	min_pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->value < min_val)
		{
			min_val = tmp->value;
			min_pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	moov_node(stack_a, min_pos, min_val);
	pb(stack_a, stack_b);
}
