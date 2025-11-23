/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:22:20 by yamosca-          #+#    #+#             */
/*   Updated: 2025/10/14 16:44:18 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	unsigned char	*s;
	unsigned char	v;
	size_t			i;

	i = 0;
	v = (unsigned char)value;
	s = (unsigned char *)pointer;
	while (count > i)
	{
		s[i] = v;
		i++;
	}
	return (pointer);
}
