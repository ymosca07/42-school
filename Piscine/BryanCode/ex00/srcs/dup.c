/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 08:49:21 by bjacquet          #+#    #+#             */
/*   Updated: 2025/09/21 08:49:23 by bjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*dup_empty(void)
{
	char	*p;

	p = (char *)malloc(1);
	if (!p)
		return (NULL);
	p[0] = '\0';
	return (p);
}

char	*dup_range(const char *b, int i, int j)
{
	int		k;
	char	*p;

	p = (char *)malloc((j - i + 2));
	if (!p)
		return (NULL);
	k = 0;
	while (i <= j)
	{
		p[k] = b[i];
		k++;
		i++;
	}
	p[k] = '\0';
	return (p);
}

char	*dup_trim(const char *b, int len)
{
	int	i;
	int	j;

	i = 0;
	j = len - 1;
	while (i < len && is_space(b[i]))
		i++;
	while (j >= i && is_space(b[j]))
		j--;
	if (j < i)
		return (dup_empty());
	return (dup_range(b, i, j));
}
