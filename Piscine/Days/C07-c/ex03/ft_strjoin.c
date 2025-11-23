/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:45:43 by yamosca-          #+#    #+#             */
/*   Updated: 2025/09/21 17:32:27 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *s1, char *s2)
{
	int	i;
	int	j;

	j = ft_strlen(s1);
	i = 0;
	while (s2[i] != '\0')
	{
		s1[j + i] = s2[i];
		i++;
	}
	return (s1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		str_nb;
	int		i;

	i = 0;
	str_nb = 0;
	result = malloc(1500);
	result[0] = '\0';
	while (str_nb < size)
	{
		if (str_nb == size - 1)
		{
			ft_strcat(result, strs[i]);
		}
		else
		{
			ft_strcat(result, strs[i]);
			ft_strcat(result, sep);
		}
		str_nb++;
		i++;
	}
	result[ft_strlen(result)] = '\0';
	return (result);
}
