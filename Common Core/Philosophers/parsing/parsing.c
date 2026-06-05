/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:20:35 by yamosca-          #+#    #+#             */
/*   Updated: 2026/05/31 12:11:35 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long	*parsing(char **argv, int *count)
{
	char	*str;
	long	*tab;
	char	**tmp;

	my_is_digit(argv);
	str = init_split_str(argv);
	tmp = ft_split(str, ' ');
	free(str);
	if (!tmp)
		tmp_error(tmp);
	while (tmp[*count])
		(*count)++;
	tab = malloc(sizeof(long) * (*count));
	if (!tab)
		tmp_error(tmp);
	tab = get_long_tab(tmp, tab);
	free(tmp);
	last_verif(tab, count);
	return (tab);
}
