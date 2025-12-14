/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymosca-- <ymosca--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:35:51 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/11 21:21:57 by ymosca--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*init_stack_a(t_list *stack_a, long *stack, int *count)
{
	t_list	*new_node;
	int		n;

	n = 0;
	while (n < (*count))
	{
		new_node = ft_lstnew(stack[n]);
		ft_lstadd_back(&stack_a, new_node);
		n++;
	}
	return (stack_a);
}
