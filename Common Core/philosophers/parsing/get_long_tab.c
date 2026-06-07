/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_long_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 11:16:30 by yamosca-          #+#    #+#             */
/*   Updated: 2026/05/31 11:16:50 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long	*get_long_tab(char **tmp, long *stack)
{
	int	n;
	int	error;

	n = 0;
	error = 0;
	while (tmp[n])
	{
		stack[n] = ft_atol(tmp[n], &error);
		if (error == -1)
			ltab_error(tmp, stack, n);
		free(tmp[n]);
		n++;
	}
	return (stack);
}
