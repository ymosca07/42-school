/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rule4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emheuga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:59:37 by emheuga           #+#    #+#             */
/*   Updated: 2025/09/14 15:59:38 by emheuga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	check_rule(char *board, char *rules, char r_index)	// trop de ligne 
{
	int	row;
	int	col;

	row = r_index / 4;
	col = r_index % 4;
	if (r_index < 8 && col_full(board, r_index))
	{
		if (check_column(board, col, 0) != rules[col])
		{
			return (1);
		}
		if (check_column(board, col, 1) != rules[col + 4])
		{
			return (1);
		}
	}
	if (r_index >= 8 && row_full(board, r_index))
	{
		if (check_line(board, row, 0) != rules[row + 8])
		{
			return (1);
		}
		if (check_line(board, row, 1) != rules[row + 12])
		{
			return (1);
		}
	}
	return (0);
}

char	check_rules(char *board, char *rules, char index)
{
	if (check_dupes(board, index, size)
		|| check_rule(board, rules, index % size)
		|| check_rule(board, rules, size + index % size)
		|| check_rule(board, rules, 2 * size + index / size)
		|| check_rule(board, rules, 3 * size + index / size))
	{
		return (0);
	}
	return (1);
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
