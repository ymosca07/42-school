/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ber_extension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:19:17 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/17 13:20:52 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ber_extension(char *argv)
{
	int	i;

	i = ft_strlen(argv);
	if (argv[i - 1] != 'r')
		return (1);
	if (argv[i - 2] != 'e')
		return (1);
	if (argv[i - 3] != 'b')
		return (1);
	if (argv[i - 4] != '.')
		return (1);
	return (0);
}
