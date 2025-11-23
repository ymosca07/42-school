/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 08:57:17 by bjacquet          #+#    #+#             */
/*   Updated: 2025/09/21 08:57:19 by bjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*lookup(t_stock_str *dict, int n, const char *key)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (str_eq(dict[i].key, key))
			return (dict[i].value);
		i++;
	}
	return (NULL);
}

void	put_key_word(t_stock_str *d, int n, const char *key, int *first)
{
	char	*w;

	w = lookup(d, n, key);
	if (w)
	{
		put_space(first);
		puts1(w);
	}
}

void	u32_to_dec(int v, char *buf)
{
	int		i;
	int		j;
	char	tmp[16];

	if (v == 0)
	{
		buf[0] = '0';
		buf[1] = '\0';
		return ;
	}
	i = 0;
	while (v > 0)
	{
		tmp[i] = (char)('0' + (v % 10));
		v = v / 10;
		i++;
	}
	j = 0;
	while (i > 0)
	{
		i--;
		buf[j] = tmp[i];
		j++;
	}
	buf[j] = '\0';
}

void	print_0_99(t_stock_str *d, int n, int v, int *first)
{
	char	key[16];

	if (v < 20)
	{
		u32_to_dec(v, key);
		put_key_word(d, n, key, first);
		return ;
	}
	u32_to_dec((v / 10) * 10, key);
	put_key_word(d, n, key, first);
	if (v % 10 != 0)
	{
		u32_to_dec(v % 10, key);
		put_key_word(d, n, key, first);
	}
}

void	print_0_999(t_stock_str *d, int n, int v, int *first)
{
	char	key[16];

	if (v >= 100)
	{
		u32_to_dec(v / 100, key);
		put_key_word(d, n, key, first);
		put_key_word(d, n, "100", first);
		v = v % 100;
	}
	if (v > 0)
		print_0_99(d, n, v, first);
}
