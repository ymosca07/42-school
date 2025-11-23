/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:12:14 by yamosca-          #+#    #+#             */
/*   Updated: 2025/10/16 17:12:14 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t nb)
{
	size_t	dest_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (nb == 0)
		return (src_len);
	dest_len = ft_strlen(dest);
	if (dest_len >= nb)
		return (src_len + nb);
	ft_strlcpy(&dest[dest_len], src, nb - dest_len);
	return (dest_len + src_len);
}
