/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 20:58:23 by yamosca-          #+#    #+#             */
/*   Updated: 2025/10/16 20:58:23 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	char	*s1;
	char	*s2;

	j = 0;
	if (!to_find[0])
		return ((char *)str);
	s1 = (char *)str;
	i = 0;
	s2 = (char *)to_find;
	while (s1[i] != '\0' && len > i)
	{
		j = 0;
		while (s1[i + j] == s2[j] && len > (i + j))
		{
			j++;
			if ((s2[j]) == '\0')
				return (&s1[i]);
		}
		i++;
	}
	return (NULL);
}
