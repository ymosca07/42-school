/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utouze-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 17:38:34 by utouze-b          #+#    #+#             */
/*   Updated: 2025/09/14 17:59:44 by utouze-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*alloc_board(char size, char *hints)
{
	char	*result;
	int		i;

	result = malloc(sizeof(char) * size * size);
	i = 0;
	while (i < size * size)
	{
		result[i] = 0;
		i++;
	}
	i = 0;
	while (*hints)
	{
		if ('0' <= *hints && *hints <= '0' + size)
			result[i++] = *hints - '0';
		else if (*hints != ' ')
			return (NULL);
		hints++;
	}
	return (result);
}
