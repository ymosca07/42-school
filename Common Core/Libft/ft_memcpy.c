/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:03:44 by yamosca-          #+#    #+#             */
/*   Updated: 2025/10/14 18:03:44 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest_str, const void *src_str, size_t n)
{
	const unsigned char	*src;
	unsigned char		*dest;
	size_t				i;

	if (!dest_str && !src_str)
		return (NULL);
	i = 0;
	dest = (unsigned char *)dest_str;
	src = (const unsigned char *)src_str;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest_str);
}
