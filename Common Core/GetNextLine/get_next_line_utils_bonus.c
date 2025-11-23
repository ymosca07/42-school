/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:14:10 by yamosca-          #+#    #+#             */
/*   Updated: 2025/11/09 18:01:15 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*res;
	size_t	len;

	if (nmemb != 0 && (size >= ((size_t)-1) / nmemb))
		return (NULL);
	len = nmemb * size;
	res = malloc(len);
	if (!res)
		return (NULL);
	while (len--)
		res[len] = '\0';
	return (res);
}

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_is_in(char *stock)
{
	int	i;

	i = 0;
	if (!stock)
		return (0);
	while (stock[i])
	{
		if (stock[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlcpy(char *dest, const char *src, int size)
{
	int	i;

	i = 0;
	if (size == 1)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	return (ft_strlen(src));
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*new;

	i = 0;
	if (!str)
		return (NULL);
	new = ft_calloc(ft_strlen(str) + 1, 1);
	if (!new)
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	return (new);
}
