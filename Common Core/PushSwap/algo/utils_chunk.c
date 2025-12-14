/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_chunk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 16:03:29 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/14 13:42:33 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	current;

	current = 0;
	while (current < size - 1)
	{
		if (tab[current + 1] < tab[current])
		{
			ft_swap(&tab[current + 1], &tab[current]);
			current = 0;
		}
		else
			current++;
	}
}

int	chunk_size(int size)
{
	if (size <= 20)
		return (5);
	if (size <= 100)
		return (15);
	return (35);
}
