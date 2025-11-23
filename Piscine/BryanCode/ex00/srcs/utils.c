/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 10:10:22 by bjacquet          #+#    #+#             */
/*   Updated: 2025/09/20 10:10:24 by bjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

int	ft_str_is_alpha(char *str)
{
	while (*str)
	{
		if ((*str < 'a' || *str > 'z') && (*str < 'A' || *str > 'Z'))
		{
			if (*str != '\0' && *str != '.')
			{
				return (0);
			}
		}
		str++;
	}
	return (1);
}

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if ((*str < '0' || *str > '9') && *str != '\0')
		{
			return (0);
		}
		str++;
	}
	return (1);
}

int	ft_puterror(char *str)
{
	while (*str)
	{
		write(2, str, 1);
		str++;
	}
	write(2, "\n", 1);
	return (0);
}

int	ftstrlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(2, "\n", 1);
	return (0);
}
