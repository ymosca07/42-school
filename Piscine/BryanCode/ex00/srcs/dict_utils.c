/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 08:49:03 by bjacquet          #+#    #+#             */
/*   Updated: 2025/09/21 08:49:05 by bjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	dict_free(t_stock_str *arr, int n)
{
	if (!arr)
		return ;
	free_until(arr, n);
	free(arr);
}

void	free_until(t_stock_str *a, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(a[i].key);
		free(a[i].value);
		i++;
	}
}

int	is_space(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\t')
		return (1);
	if (c == '\r')
		return (1);
	return (0);
}

int	line_len(const char *p)
{
	int	len;

	len = 0;
	while (p[len] && p[len] != '\n')
		len++;
	return (len);
}

int	find_colon(const char *b, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (b[i] == ':')
			return (i);
		i++;
	}
	return (-1);
}
