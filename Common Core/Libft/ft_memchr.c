/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 20:29:21 by yamosca-          #+#    #+#             */
/*   Updated: 2025/10/16 20:29:21 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)memoryBlock;
	while (i < size)
	{
		if (str[i] == (char)searchedChar)
			return ((void *)&str[i]);
		i++;
	}
	return (0);
}
