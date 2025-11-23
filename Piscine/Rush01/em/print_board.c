/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emheuga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:41:49 by emheuga           #+#    #+#             */
/*   Updated: 2025/09/13 11:41:51 by emheuga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>


void print_board (char *board)
{
	int col;
	int line;
	int i;
	char c;
	
	col = 0;
	line = 0;
	i = 0;
	
	while (line < 4)
	{
		col = 0;

		while (col < 4)
		{
			c = board[i] + '0';
			write (1, &c, 1);
			col ++;
			i++;
		}
	write (1, "\n",1);
	line++;
	}
}

int main ()
{
	char test[] = 
	{
		1, 2, 3, 4,
		2, 1, 3, 4,
		3, 2, 4, 4,
		4, 2, 3, 1,
	};
	print_board(test);


}
