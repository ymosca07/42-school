/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flortie <marvin@d42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 17:58:47 by flortie           #+#    #+#             */
/*   Updated: 2025/09/14 17:58:47 by flortie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_board(char *board, char size)
{
	char	i;
	char	c;

	i = 0;
	while (i < size * size)
	{
		c = '0' + board[i];
		write(1, &c, 1);
		if (i % size == size - 1)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}
