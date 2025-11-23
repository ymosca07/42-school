/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utouze-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:05:31 by utouze-b          #+#    #+#             */
/*   Updated: 2025/09/14 18:38:43 by utouze-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char check_dupe(unsigned int *dupe, char c, char l, char s)
{
	if ((*dupe & (1 << (c - 1)) && c != 0) 
		|| (*dupe & (1 << (l + s - 1)) && l != 0))
		return (1);
	if (c != 0)
		*dupe |= 1 << (c - 1);
	if (l != 0)
		*dupe |= 1 << (l + s - 1);
	return (0);
}

char check_dupes_n(char *board, char index, char s)
{
	unsigned int dupe;
	int i;

	i = 0;
	dupe = 0;
	while (i < s)
	{
		if (check_dupe(&dupe, board[i * s + (index % s)], board[i + (index / s) * s], s))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

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

char	check_rule_n(char *board, char *rules, char r_index, char size)
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

char	check_rules_n(char *board, char *rules, char index, char size)
{
	if (check_dupes_n(board, index, size)
		|| check_rule_n(board, rules, index % size, size)
		|| check_rule_n(board, rules, size + index % size, size)
		|| check_rule_n(board, rules, 2 * size + index / size, size)
		|| check_rule_n(board, rules, 3 * size + index / size, size))
		return (0);
	return (1);
}

char	solve_n(char *board, char *rules, char index, char size)
{
	char	i;
	char	s;

	s = size * size;
	if (index == s)
		return (1);
	if (board[index] != 0)
		return (solve_n(board, rules, index + 1, size));
	i = 1;
	while (i < size + 1)
	{
		board[index] = i;
		if (check_rules_n(board, rules, index, size))
		{
			if (solve_n(board, rules, index + 1, size))
				return (1);
		}
		i++;
	}
	board[index] = 0;
	return (0);
}
