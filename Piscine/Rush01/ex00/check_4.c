/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emheuga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:59:37 by emheuga           #+#    #+#             */
/*   Updated: 2025/09/14 18:46:07 by utouze-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
char	check_dupes(char *board, char index);

char indexer(char i, char reverse)
{
	if (reverse)
		return (3 - i);
	return i;
}

char	check_column(char *board, char column, char reverse)
{
	char	result;
	char	i;
	char	max;

	result = 0;
	i = 0;
	max = 0;
	while (i < 4)
	{
		if (max < board[column + 4 * indexer(i, reverse)])
		{
			result++;
			max = board[column + 4 * indexer(i, reverse)];
		}
		i++;
	}
	return (result);
}

char	check_line(char *board, char line, char reverse)
{
	char	result;
	char	i;
	char	max;

	result = 0;
	i = 0;
	max = 0;
	while (i < 4)
	{
		if (max < board[line * 4 + indexer(i, reverse)])
		{
			result++;
			max = board[line * 4 + indexer(i, reverse)];
		}
		i++;
	}
	return (result);
}

char	col_full(char *board, char index)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (board[index + i * 4] == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

char	row_full(char *board, char index)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (board[i + index * 4] == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

char	check_rule(char *board, char *rules, char r_index)
{
	int	row;
	int	col;

	row = r_index / 4;
	col = r_index % 4;
	if (r_index < 8 && col_full(board, col))
	{
		if (check_column(board, col, 0) != rules[col])
			return (1);
		if (check_column(board, col, 1) != rules[col + 4])
			return (1);
	}
	if (r_index >= 8 && row_full(board, row))
	{
		if (check_line(board, row, 0) != rules[row + 8])
			return (1);
		if (check_line(board, row, 1) != rules[row + 12])
			return (1);
	}
	return (0);
}

char	check_rules(char *board, char *rules, char index)
{

	if (check_dupes(board, index)
		|| check_rule(board, rules, index % 4)
		|| check_rule(board, rules, 4 + index % 4)
		|| check_rule(board, rules, 8 + index / 4)
		|| check_rule(board, rules, 12 + index / 4))
	{
		return (0);
	}
	return (1);
}
