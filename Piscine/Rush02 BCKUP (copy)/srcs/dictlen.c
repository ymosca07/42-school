/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictlen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcotza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 13:05:04 by thcotza           #+#    #+#             */
/*   Updated: 2025/09/20 13:17:45 by thcotza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

int	dictlen(char *content)
{
	int	i;
	int	countline;

	countline = 0;
	i = 0;
	while (content[i])
	{
		if (content[i] == '\n' && content[i + 1] != '\n')
			countline++;
		i++;
	}
	return (countline);
}
