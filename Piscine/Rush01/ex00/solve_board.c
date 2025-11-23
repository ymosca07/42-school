/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flortie <marvin@d42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:30:55 by flortie           #+#    #+#             */
/*   Updated: 2025/09/14 18:43:54 by utouze-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	check_rules(char *board, char *rules, char index);
char	print_board(char *board, char size);

char	solve_board(char *board, char *rules)
{
	char	i;
	char	tab_size;

	tab_size = 16;
	i = 0;
	while (i < tab_size)
	{
		if (i < 0)
			return (0);
		board[i] += 1;
		if (board[i] == 5)
		{
			board[i] = 0;
			i -= 1;
			continue ;
		}
		if (check_rules(board, rules, i))
			i++;
	}
	return (1);
}
