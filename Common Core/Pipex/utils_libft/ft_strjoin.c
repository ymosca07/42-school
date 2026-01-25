/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 19:23:37 by yamosca-          #+#    #+#             */
/*   Updated: 2026/01/19 00:49:52 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_string = malloc(len1 + len2 + 1);
	if (!new_string)
		return (NULL);
	ft_strlcpy(new_string, s1, len1 + 1);
	ft_strlcpy(new_string + len1, s2, len2 + 1);
	return (new_string);
}
