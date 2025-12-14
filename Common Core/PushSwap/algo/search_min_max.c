/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_min_max.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:07:13 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/14 13:51:14 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	append_index(t_list **stack_a)
{
	t_list	*cursor;
	int		index;

	cursor = *stack_a;
	index = 0;
	while (cursor)
	{
		cursor->index = index;
		cursor = cursor->next;
	}
}

static void	get_min_max(t_list *node, long *limits, int *pos)
{
	limits[0] = node->value;
	limits[1] = node->value;
	pos[0] = 0;
	pos[1] = 0;
	while (node)
	{
		if (node->value < limits[0])
		{
			limits[0] = node->value;
			pos[0] = node->index;
		}
		if (node->value > limits[1])
		{
			limits[1] = node->value;
			pos[1] = node->index;
		}
		node = node->next;
	}
}

void	search_min_max(t_list **stack_a, t_list **stack_b)
{
	long	limits[2];
	int		pos[2];

	append_index(stack_a);
	get_min_max(*stack_a, limits, pos);
	push_min(stack_a, stack_b, limits[0], pos[0]);
	push_max(stack_a, stack_b, limits[1], pos[1]);
}
