/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dupes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flortie <marvin@d42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 13:23:53 by flortie           #+#    #+#             */
/*   Updated: 2025/09/13 13:23:53 by flortie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	check_dupes(char *board, char index)
{
	int	i;
	int	row;
	int	col;
	char	value;

	row = index / 4;
	col = index % 4;
	i = 0;
	value = board[index];
	while (i < 4)
	{
		if (i != col && (value != 0) && board[row * 4 + i] == value)
			return (1);
		i++;
	}

	i = 0;
	while (i < 4)
	{
		if (i != row && (value != 0) && board[i * 4 + row] == value)
			return (1);
		i++;
	}
	return (0);
}
#include <stdio.h>
int	main()
{
	char	test[] = "4321122243211222";
	printf("%i", check_dupes(test, 1));
}
