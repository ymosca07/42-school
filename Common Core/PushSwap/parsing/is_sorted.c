/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 16:37:59 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/14 16:55:02 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_list **stack_a)
{
	t_list	*node;
	t_list	*more;

	node = *stack_a;
	more = (*stack_a)->next;
	while (more)
	{
		if (node->value > more->value)
			return (0);
		node = node->next;
		more = more->next;
	}
	ft_lstclear(*stack_a);
	return (1);
}
