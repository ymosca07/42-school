/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utouze-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:05:31 by utouze-b          #+#    #+#             */
/*   Updated: 2025/09/14 15:11:59 by utouze-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	get_cell(char *board, char r_index, char i, char size)
{
	if (r_index / (size * 2) == 0)
	{
		if (r_index / size == 0)
			return (board[i * size + (r_index % size)]);
		else
			return (board[(size - i - 1) * size + (r_index % size)]);
	}
	if (r_index / size == 2)
		return (board[i + size * (r_index % size)]);
	return (board[size - i - 1 + size * (r_index % size)]);
}

char	check_rule(char *board, char *rules, char r_index, char size)
{
	char	i;
	char	empty;
	char	see;
	char	max;
	char	curr;

	i = 0;
	empty = 0;
	max = 0;
	see = 0;
	if (rules[r_index] == 0)
		return (0);
	while (i < size)
	{
		curr = get_cell(board, r_index, i, size);
		if (curr > max)
		{
			max = curr;
			see += 1;
		}
		if (curr == 0)
			empty++;
		i++;
	}
	return (empty == 0 && rules[r_index] != see);
}

char	check_rules(char *board, char *rules, char index, char size)
{
	if (check_dupes(board, index, size)
		|| check_rule(board, rules, index % size, size)
		|| check_rule(board, rules, size + index % size, size)
		|| check_rule(board, rules, 2 * size + index / size, size)
		|| check_rule(board, rules, 3 * size + index / size, size))
		return (0);
	return (1);
}

char	solve_board(char *board, char *rules, char index, char size)
{
	char	i;
	char	s;

	s = size * size;
	if (index == s)
		return (1);
	if (board[index] != 0)
		return (solve_board(board, rules, index + 1, size, print));
	i = 1;
	while (i < size + 1)
	{
		board[index] = i;
		if (check_rules(board, rules, index, size))
		{
			if (solve_board(board, rules, index + 1, size, print))
				return (1);
		}
		i++;
	}
	board[index] = 0;
	return (0);
}
