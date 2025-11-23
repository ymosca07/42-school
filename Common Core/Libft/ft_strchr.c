/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:37:18 by yamosca-          #+#    #+#             */
/*   Updated: 2025/10/16 19:37:18 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int searchedChar)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)string;
	while (str[i] != '\0')
	{
		if ((str[i] != (char)searchedChar))
			i++;
		else
			return (&str[i]);
	}
	if ((char)searchedChar == '\0')
		return (&str[i]);
	return (NULL);
}
