/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 08:48:38 by bjacquet          #+#    #+#             */
/*   Updated: 2025/09/21 08:48:41 by bjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	count_lines(const char *s)
{
	int	n;
	int	in;

	n = 0;
	in = 0;
	while (*s)
	{
		if (*s != '\n' && in == 0)
		{
			in = 1;
			n++;
		}
		else if (*s == '\n')
			in = 0;
		s++;
	}
	return (n);
}

static int	parse_line(const char *b, int len, t_stock_str *out)
{
	int	k;

	k = find_colon(b, len);
	if (k < 0)
		return (0);
	out->key = dup_trim(b, k);
	if (!out->key)
		return (0);
	out->value = dup_trim(b + k + 1, len - k - 1);
	if (!out->value)
	{
		free(out->key);
		out->key = NULL;
		return (0);
	}
	return (1);
}

static void	handle_line(const char *p, int len, t_stock_str *arr, int *n)
{
	if (len > 0 && parse_line(p, len, &arr[*n]))
	{
		if (arr[*n].key[0] != '\0' && arr[*n].value[0] != '\0')
		{
			*n = *n + 1;
		}
		else
		{
			free(arr[*n].key);
			free(arr[*n].value);
		}
	}
}

static int	parse_loop(const char *content, t_stock_str *arr)
{
	const char	*p;
	const char	*q;
	int			len;
	int			n;

	n = 0;
	p = content;
	while (*p)
	{
		q = p + line_len(p);
		len = (int)(q - p);
		handle_line(p, len, arr, &n);
		if (*q == '\n')
			p = q + 1;
		else
			p = q;
	}
	return (n);
}

t_stock_str	*dict_parse(const char *content, int *out_n)
{
	t_stock_str	*arr;
	int			cap;
	int			n;

	if (out_n)
		*out_n = 0;
	if (!content)
		return (NULL);
	cap = count_lines(content);
	if (cap <= 0)
		return (NULL);
	arr = (t_stock_str *)malloc(sizeof(*arr) * cap);
	if (!arr)
		return (NULL);
	n = parse_loop(content, arr);
	if (out_n)
		*out_n = n;
	return (arr);
}
