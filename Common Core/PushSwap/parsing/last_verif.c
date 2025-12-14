/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_verif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:00:08 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/14 14:30:43 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error_signal(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static void	verif_double(long *stack, int count, int *error)
{
	int	n;
	int	i;
	int	comp;

	comp = 0;
	i = 0;
	n = 0;
	while (i < count)
	{
		n = 0;
		comp = 0;
		while (n < count)
		{
			if (stack[i] == stack[n])
				comp++;
			if (comp > 1)
				*error = -1;
			n++;
		}
		i++;
	}
}

static void	verif_max_min(long *stack, int count, int *error)
{
	int	n;

	n = 0;
	while (n < count)
	{
		if (stack[n] < INT_MIN || stack[n] > INT_MAX)
			*error = -1;
		n++;
	}
}

void	last_verif(long *stack, int *count)
{
	int	error;

	error = 1;
	verif_double(stack, (*count), &error);
	if (error == -1)
	{
		free(stack);
		error_signal();
	}
	verif_max_min(stack, (*count), &error);
	if (error == -1)
	{
		free(stack);
		error_signal();
	}
	return ;
}
