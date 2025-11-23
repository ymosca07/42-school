/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 14:10:31 by juperrin          #+#    #+#             */
/*   Updated: 2025/09/06 14:50:28 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	check_pos(int row, int col, int x, int y)
{
	if ((row == 0 && col == 0) || (row == 0 && col == y - 1)
		|| (col == 0 && row == x - 1)
		|| (col == y - 1 && row == x - 1))
	{
		ft_putchar('o');
	}
	else if (row == 0 || row == x - 1)
	{
		ft_putchar('|');
	}
	else if (col == 0 || col == y - 1)
	{
		ft_putchar('-');
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

	if (x < 0)
	{
		return ;
	}
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
	return ;
}
