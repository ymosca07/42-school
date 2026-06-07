/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ltab_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 11:11:55 by yamosca-          #+#    #+#             */
/*   Updated: 2026/05/31 11:25:28 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ltab_error(char **tmp, long *stack, int n)
{
	free(tmp[n]);
	n++;
	while (tmp[n])
	{
		free(tmp[n]);
		n++;
	}
	free(tmp);
	free(stack);
	printf("Error | ltab error\n");
	exit(1);
}
