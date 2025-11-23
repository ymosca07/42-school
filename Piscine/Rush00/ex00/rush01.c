/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 14:12:06 by yamosca-          #+#    #+#             */
/*   Updated: 2025/09/06 14:57:24 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	check_pos(int row, int col, int x, int y)
{
	if ((row == 0 && col == 0)
		|| (row == x - 1 && col == y - 1
			&& x > 1 && y > 1))
		ft_putchar('/');
	else if ((row == 0 && col == y - 1) || (row == x - 1 && col == 0))
		ft_putchar('\\');
	else if (row == 0 || row == x - 1 || col == 0 || col == y -1)
		ft_putchar('*');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	col;
	int	row;

	col = 0;
	while (col < y)
	{
		row = 0;
		while (row < x)
		{
			check_pos(row, col, x, y);
			row++;
		}
		ft_putchar('\n');
		col++;
	}
}
