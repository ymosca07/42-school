/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:25:49 by yamosca-          #+#    #+#             */
/*   Updated: 2025/10/14 18:25:49 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t size)
{
	const unsigned char	*src;
	unsigned char		*dest;
	size_t				i;

	if (!destination && !source)
		return (NULL);
	src = (const unsigned char *)source;
	dest = (unsigned char *)destination;
	if (dest < src)
	{
		i = 0;
		while (i < size)
		{
			dest[i] = src[i];
			i++;
		}
	}
	else
	{
		while (size--)
			dest[size] = src[size];
	}
	return (destination);
}
