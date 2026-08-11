/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 18:15:04 by yamosca-          #+#    #+#             */
/*   Updated: 2026/08/10 16:36:18 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*new_string;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_string = ft_calloc(len1 + len2 + 1, 1);
	if (!new_string)
		return (NULL);
	ft_strlcpy(new_string, s1, len1 + 1);
	ft_strlcpy(new_string + len1, s2, len2 + 1);
	if (s1)
		free(s1);
	return (new_string);
}
