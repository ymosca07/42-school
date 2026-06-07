/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:42:30 by yamosca-          #+#    #+#             */
/*   Updated: 2026/05/31 11:56:02 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*res;
	size_t	len;

	if (nmemb != 0 && (size >= ((size_t) - 1) / nmemb))
		return (NULL);
	len = nmemb * size;
	res = malloc(len);
	if (!res)
		return (NULL);
	ft_bzero(res, len);
	return (res);
}
