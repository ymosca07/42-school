/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:43:52 by yamosca-          #+#    #+#             */
/*   Updated: 2025/09/07 20:50:56 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
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
