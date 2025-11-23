/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-deun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 12:12:05 by mle-deun          #+#    #+#             */
/*   Updated: 2025/09/06 13:56:48 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	check_pos(int row, int col, int x, int y)
{
	if (row == 0 && (col == 0 || col == y - 1))
	{
		ft_putchar('A');
	}
	else if (row == x -1 && (col == 0 || col == y - 1))
	{
		ft_putchar('C');
	}
	else if (row == 0 || row == x - 1 || col == 0 || col == y -1)
	{
		ft_putchar('B');
	}
	else
	{
		ft_putchar(' ');
	}
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
