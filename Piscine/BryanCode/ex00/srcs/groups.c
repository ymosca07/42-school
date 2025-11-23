/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groups.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 09:00:53 by bjacquet          #+#    #+#             */
/*   Updated: 2025/09/21 09:00:55 by bjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	group_value(const char *nb, int len, int grp)
{
	int	end;
	int	start;
	int	val;
	int	p;

	end = len - grp * 3 - 1;
	start = end - 2;
	if (start < 0)
		start = 0;
	if (end < 0)
		return (0);
	val = 0;
	p = start;
	while (p <= end)
	{
		if (!is_digit(nb[p]))
			return (0);
		val = val * 10 + (nb[p] - '0');
		p++;
	}
	return (val);
}

int	count_groups(const char *nb, int len)
{
	int	g;

	(void)nb;
	g = len / 3;
	if (len % 3 != 0)
		g++;
	return (g);
}
