/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_gourps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 09:03:34 by bjacquet          #+#    #+#             */
/*   Updated: 2025/09/21 09:03:35 by bjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*build_scale_key(int scale)
{
	int		total;
	int		i;
	char	*s;

	if (scale <= 0)
		return (NULL);
	total = 1 + scale * 3;
	s = (char *)malloc(total + 1);
	if (!s)
		return (NULL);
	s[0] = '1';
	i = 1;
	while (i < total)
	{
		s[i] = '0';
		i++;
	}
	s[total] = '\0';
	return (s);
}

int	handle_zero_case(t_stock_str *dict, int n, char *nb)
{
	int	i;

	i = 0;
	while (nb[i] && nb[i] == '0')
		i++;
	if (nb[i] == '\0')
	{
		puts1(lookup(dict, n, "0"));
		puts1("\n");
		return (1);
	}
	return (0);
}

void	print_g_s(t_stock_str *dict, int n, int part, int scale)
{
	char	*key;

	if (part <= 0)
		return ;
	print_0_999(dict, n, part, &g_first);
	if (scale <= 0)
		return ;
	key = build_scale_key(scale);
	if (!key)
		return ;
	put_key_word(dict, n, key, &g_first);
	free(key);
}

void	print_groups_loop(t_stock_str *dict, int n, char *nb)
{
	int	len;
	int	groups;
	int	i;
	int	part;
	int	first;

	len = my_strlen(nb);
	groups = count_groups(nb, len);
	first = 1;
	i = groups - 1;
	while (i >= 0)
	{
		part = group_value(nb, len, i);
		print_g_s(dict, n, part, i);
		i--;
	}
	puts1("\n");
}

void	print_number_words(t_stock_str *dict, int n, char *nb)
{
	if (!dict || !nb)
		return ;
	if (handle_zero_case(dict, n, nb))
		return ;
	while (*nb == '0')
		nb++;
	print_groups_loop(dict, n, nb);
}
