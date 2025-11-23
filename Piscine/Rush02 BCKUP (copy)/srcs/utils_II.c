/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_II.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 10:10:22 by bjacquet          #+#    #+#             */
/*   Updated: 2025/09/20 12:25:09 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	stock;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] <= tab[i + 1])
		{
			i++;
		}
		else
		{
			stock = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = stock;
			i = 0;
		}
	}
}

int	ft_lap(char *content, int lap, char symbol)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (check < lap)
	{
		if (content[i] == symbol)
			check++;
		i++;
	}
	return (i);
}

char	*first_word(char *content, int lap)
{
	int		i;
	char	*word;
	int		len;
	int		j;

	i = ft_lap(content, lap, '\n');
	len = 0;
	while (content[i + len] >= '0' && content[i + len] <= '9')
		len++;
	word = malloc(sizeof(char) * len + 1);
	word[0] = '\0';
	j = 0;
	while (content[i] >= '0' && content[i] <= '9')
	{
		word[j] = content[i];
		i++;
		j++;
	}
	word[i] = '\0';
	return (word);
}

char	*last_word(char *content, int lap)
{
	int		i;
	char	*word;
	int		len;
	int		j;

	i = ft_lap(content, lap + 1, ':');
	while ((content[i] >= 9 && content[i] <= 13) || content[i] == ' ')
		i++;
	len = 0;
	while ((content[i + len] >= 'a' && content[i + len] <= 'z')
		|| (content[i + len] >= 'A' && content[i + len] <= 'Z'))
		len++;
	word = malloc(sizeof(char) * len + 1);
	word[0] = '\0';
	j = 0;
	while ((content[i] >= 'a' && content[i] <= 'z')
		|| (content[i] >= 'A' && content[i] <= 'Z'))
	{
		word[j] = content[i];
		i++;
		j++;
	}
	word[i] = '\0';
	return (word);
}
