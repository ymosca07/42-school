/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:27:46 by yamosca-          #+#    #+#             */
/*   Updated: 2025/11/09 17:58:50 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*trim_line(char *stock)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	j = 0;
	i = 0;
	k = 0;
	while (stock[i] != '\n' && stock[i])
		i++;
	i++;
	j = ft_strlen(stock);
	str = ft_calloc(1, (j - i + 1));
	j = i;
	while ((i + k < ft_strlen(stock)) && str)
		str[k++] = stock[j++];
	free(stock);
	if (!*str || !str)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char	*result_line(char *stock)
{
	char	*result;
	int		i;
	char	tmp;

	i = 0;
	while (stock[i] != '\n' && stock[i])
		i++;
	i++;
	result = ft_calloc(1, (i + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (stock[i] && stock[i] != '\n')
	{
		tmp = stock[i];
		result[i] = tmp;
		i++;
	}
	if (stock[i] == '\n')
	{
		tmp = stock[i];
		result[i] = tmp;
	}
	return (result);
}

char	*stock_line(char *stock, char *buffer)
{
	char	*stock_total;
	int		len1;
	int		len2;

	if (!buffer)
		return (NULL);
	len1 = ft_strlen(stock);
	len2 = ft_strlen(buffer);
	stock_total = ft_calloc(len1 + len2 + 1, 1);
	if (!stock_total)
		return (NULL);
	if (stock)
		ft_strlcpy(stock_total, stock, len1 + 1);
	ft_strlcpy(stock_total + len1, buffer, len2 + 1);
	free(stock);
	return (stock_total);
}

char	*read_file(int fd, int byte, char *buffer, char *stock)
{
	while (byte > 0)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, 1);
		if (!buffer)
			return (NULL);
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == -1)
		{
			free(stock);
			free(buffer);
			return (NULL);
		}
		if (byte == 0)
		{
			free(buffer);
			return (stock);
		}
		stock = stock_line(stock, buffer);
		free(buffer);
		if (!stock)
			return (NULL);
		if (ft_is_in(stock))
			return (stock);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	int			byte;
	static char	*stock;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	byte = 1;
	buffer = NULL;
	stock = read_file(fd, byte, buffer, stock);
	if (stock && ft_is_in(stock))
	{
		result = result_line(stock);
		stock = trim_line(stock);
		return (result);
	}
	if (stock && *stock)
	{
		result = ft_strdup(stock);
		free(stock);
		stock = NULL;
		return (result);
	}
	free(stock);
	return (NULL);
}
