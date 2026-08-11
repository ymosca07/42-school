/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_long_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 11:16:30 by yamosca-          #+#    #+#             */
/*   Updated: 2026/06/09 19:05:48 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	free_error(char **tmp, long *stack, int n)
{
	while (tmp[n])
	{
		free(tmp[n]);
		n++;
	}
	free(tmp);
	free(stack);
}

long	*get_long_tab(char **tmp, long *stack)
{
	int	n;

	n = 0;
	while (tmp[n])
	{
		stack[n] = ft_atol(tmp[n]);
		if (stack[n] == -1)
		{
			free_error(tmp, stack, n);
			return (NULL);
		}
		free(tmp[n]);
		n++;
	}
	return (stack);
}
