/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:22:20 by yamosca-          #+#    #+#             */
/*   Updated: 2026/08/10 16:19:28 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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
