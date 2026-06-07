/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_verif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:00:08 by yamosca-          #+#    #+#             */
/*   Updated: 2026/05/31 11:09:52 by yamosca-         ###   ########.fr       */
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

void	last_verif(long *stack, int *count)
{
	int	error;

	error = 1;
	verif_max_min(stack, (*count), &error);
	if (error == -1)
	{
		free(stack);
		error_signal();
	}
}
