/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utouze-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 17:45:09 by utouze-b          #+#    #+#             */
/*   Updated: 2025/09/14 19:56:22 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*alloc_board(char size, char *hints);
char	print_board(char *board, char size);
char	*get_rules(char *str, char *size);
char	solve_n(char *board, char *rules, char index, char size);
char	solve_board(char *board, char *rules);

void	arg2(char *arg)
{
	char	*rules;
	char	*board;
	char	size;
	char	succes;

	rules = get_rules(arg, &size);
	if (size == 0)
	{
		write(1, "Erreur\n", 7);
		return ;
	}
	board = alloc_board(size, "");
	printf("size %i\n", size);
	if (size == 4)
		succes = solve_board(board, rules);
	else
		succes = solve_n(board, rules, 0, size);
	if (succes)
		print_board(board, size);
	else
		write(1, "Erreur\n", 7);
}

void	arg3(char **arg)
{
	char	*rules;
	char	*board;
	char	size;

	rules = get_rules(arg[1], &size);
	if (size == 0)
	{
		write(1, "Erreur\n", 7);
		return ;
	}
	board = alloc_board(size, arg[2]);
	print_board(board, size);
	if (solve_n(board, rules, 0, size))
		print_board(board, size);
	else
		write(1, "Erreur\n", 7);
	if (board)
		free(board);
	if (rules)
		free(rules);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		arg2(argv[1]);
	else if (argc == 3)
		arg3(argv);
	else
		write(1, "Erreur\n", 7);
}
