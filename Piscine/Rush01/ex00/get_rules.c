/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flortie <marvin@d42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 18:22:38 by flortie           #+#    #+#             */
/*   Updated: 2025/09/14 18:22:38 by flortie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	count_numbers(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '9')
			j++;
		i++;
	}
	return (j);
}

char	*get_rules(char *str, char *size)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = count_numbers(str);
	if (!(*str))
		return (0);
	if (j < 16 || j % 4 != 0)
		return (0);
	*size = j / 4;
	res = (char *)malloc(j);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			res[j] = str[i] - '0';
			j++;
		}
		i++;
	}
	return (res);
}
