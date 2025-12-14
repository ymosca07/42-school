/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymosca-- <ymosca--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:40:38 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/11 21:21:49 by ymosca--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstclear(t_list *node)
{
	t_list	*clear;

	clear = NULL;
	while (node)
	{
		clear = node->next;
		free(node);
		node = clear;
	}
}
