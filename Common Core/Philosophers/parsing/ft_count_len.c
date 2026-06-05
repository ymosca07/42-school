/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:17:30 by yamosca-          #+#    #+#             */
/*   Updated: 2026/05/31 12:15:17 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_count_len(char **input)
{
	int	n;
	int	count;

	n = 1;
	count = 0;
	while (input[n])
	{
		count += ft_strlen(input[n]);
		if (input[n + 1])
			count += 1;
		n++;
	}
	return (count);
}
