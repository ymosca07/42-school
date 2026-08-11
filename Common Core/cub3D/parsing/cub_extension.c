/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_extension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 14:12:26 by yamosca-          #+#    #+#             */
/*   Updated: 2026/08/10 16:34:27 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	cub_extension(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (file[i - 1] != 'b')
		return (1);
	if (file[i - 2] != 'u')
		return (1);
	if (file[i - 3] != 'c')
		return (1);
	if (file[i - 4] != '.')
		return (1);
	return (0);
}
