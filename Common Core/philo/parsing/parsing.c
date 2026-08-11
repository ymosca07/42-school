/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:20:35 by yamosca-          #+#    #+#             */
/*   Updated: 2026/06/09 19:06:03 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	free_tmp(char **tmp)
{
	int	n;

	n = 0;
	while (tmp[n])
	{
		free(tmp[n]);
		n++;
	}
	free(tmp);
}

static int	increment_count(char **tmp)
{
	int	count;

	count = 0;
	while (tmp[count])
		count++;
	return (count);
}

int	parsing(char **argv, long **tab)
{
	char	*str;
	char	**tmp;

	if (my_is_digit(argv) == -1)
		return (-1);
	str = init_split_str(argv);
	if (!str)
		return (-1);
	tmp = ft_split(str, ' ');
	free(str);
	if (!tmp)
		return (-1);
	*tab = ft_calloc(sizeof(long), increment_count(tmp));
	if (!*tab)
	{
		free_tmp(tmp);
		return (-1);
	}
	*tab = get_long_tab(tmp, *tab);
	if (!*tab)
		return (-1);
	if (last_verif(*tab, increment_count(tmp), tmp) == -1)
		return (-1);
	free(tmp);
	return (0);
}
