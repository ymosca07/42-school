/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:09:37 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/14 13:41:16 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		if (s[i] == '\0')
			break ;
		else
			i++;
	}
	return (count);
}

static size_t	get_words(char const *s, char c, size_t words_number)
{
	size_t	i;
	size_t	count;
	size_t	comp;

	comp = 0;
	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			if (s[i + 1] == c || s[i + 1] == '\0')
				comp++;
			count++;
			i++;
		}
		if (comp == words_number)
			return (count);
		i++;
		count = 0;
	}
	return (count);
}

static size_t	ft_start(char const *s, char c, size_t words_number)
{
	size_t	i;
	size_t	count;
	size_t	len;

	len = 0;
	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			if (s[i + 1] == c || s[i + 1] == '\0')
				count++;
			i++;
			len++;
		}
		if (count == words_number)
			return (i - len);
		i++;
		len = 0;
	}
	return (0);
}

static char	**free_all(char **split, size_t nb_words)
{
	size_t	i;

	i = 0;
	while (split[i])
		i++;
	if (i == nb_words)
		return (split);
	i = 0;
	while (i < nb_words)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	words_number;
	size_t	words_total;
	size_t	start;
	size_t	i;

	words_number = ft_count_words(s, c);
	words_total = words_number;
	i = 0;
	split = malloc(sizeof(char *) * (words_total + 1));
	if (!split)
		return (NULL);
	while (words_number > 0)
	{
		start = ft_start(s, c, words_number);
		split[words_total - i - 1] = ft_substr(s, start, get_words(s, c,
					words_number));
		words_number--;
		i++;
	}
	split[words_total] = NULL;
	split = free_all(split, words_total);
	return (split);
}
