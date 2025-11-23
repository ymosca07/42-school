/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 00:50:44 by yamosca-          #+#    #+#             */
/*   Updated: 2025/09/24 20:18:35 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/* Dans char *s on recup le str de get map */

int	count_words(char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			count++;
		}
		i++;
	}
	return (count + 1);
}

char	**ft_split(char *s, char c)
{
	int	i;
	char	**split;
	int	j;
	int	n;
	int	l;

	l = 0;
	j = 0;
	n = 0;
	split = NULL;
	i = 0;
	split = malloc(sizeof(char) * count_words(s, c) + 1);
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			j = 0;
			i++;
			n++;
		}
		
		while (s[l] != '\0')
		{
			if (s[l] == c)
				break ;
			l++;
		}

		split[n] = malloc((sizeof(char) * l) + 1);
		split[n][j] = s[i];
		i++;
		j++;
	}
	return (split);
}
