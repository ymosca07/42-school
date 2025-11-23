/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utlis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 08:52:44 by bjacquet          #+#    #+#             */
/*   Updated: 2025/09/21 08:52:46 by bjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	my_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

void	puts1(const char *s)
{
	if (!s)
		return ;
	write(1, s, my_strlen(s));
}

void	put_space(int *first)
{
	if (*first == 0)
		write(1, " ", 1);
	else
		*first = 0;
}

int	str_eq(const char *a, const char *b)
{
	int	i;

	if (!a || !b)
		return (0);
	i = 0;
	while (a[i] && b[i] && a[i] == b[i])
		i++;
	return (a[i] == '\0' && b[i] == '\0');
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}
