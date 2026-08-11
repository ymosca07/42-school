/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_verif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:00:08 by yamosca-          #+#    #+#             */
/*   Updated: 2026/06/09 19:05:55 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	verif_max_min(long *stack, int count, int *error)
{
	int	n;

	n = 0;
	while (n < count)
	{
		if (stack[n] < INT_MIN || stack[n] > INT_MAX)
		{
			*error = -1;
			return ;
		}
		n++;
	}
}

int	last_verif(long *stack, int count, char **tmp)
{
	int	error;

	error = 1;
	verif_max_min(stack, count, &error);
	if (error == -1)
	{
		free(stack);
		free(tmp);
		return (-1);
	}
	return (0);
}
