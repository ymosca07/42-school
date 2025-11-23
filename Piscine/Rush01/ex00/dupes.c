/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dupes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flortie <marvin@d42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 13:23:53 by flortie           #+#    #+#             */
/*   Updated: 2025/09/14 19:48:17 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	check_dupes(char *board, char index)
{
	int		i;
	int		row;
	int		col;
	char	value;
	char	size;

	size = 4;
	row = index / size;
	col = index % size;
	i = 0;
	value = board[index];
	while (i < size)
	{
		if (i != col && (value != 0) && board[row * size + i] == value)
			return (1);
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (i != row && (value != 0) && board[i * size + col] == value)
			return (1);
		i++;
	}
	return (0);
}
