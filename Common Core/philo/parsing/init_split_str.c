/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_split_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:17:52 by yamosca-          #+#    #+#             */
/*   Updated: 2026/06/09 19:05:51 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

char	*init_split_str(char **input)
{
	int		i;
	int		n;
	char	*str;
	int		j;

	j = 0;
	i = 0;
	str = ft_calloc(sizeof(char), ft_count_len(input) + 1);
	if (!str)
		return (NULL);
	n = 0;
	while (input[++n])
	{
		i = 0;
		while (input[n][i])
		{
			if (input[n][i] != ' ' && input[n][i] != '+')
				str[j++] = input[n][i];
			i++;
		}
		if (input[n + 1])
			str[j++] = ' ';
	}
	return (str);
}
