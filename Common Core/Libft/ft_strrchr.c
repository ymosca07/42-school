/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 20:06:17 by yamosca-          #+#    #+#             */
/*   Updated: 2025/10/16 20:06:17 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int searchedChar)
{
	int		i;
	char	*str;

	i = ft_strlen(string);
	str = (char *)string;
	while (i >= 0)
	{
		if (str[i] == (char)searchedChar)
			return (&str[i]);
		i--;
	}
	return (0);
}
