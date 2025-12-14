/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:23:56 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/14 14:40:12 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	pos_sign_more(char *tmp, char **all)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == '+' && i != 0)
			tmp_error(all);
		if (tmp[i] == '+' && ft_strlen(tmp) == 1)
			tmp_error(all);
		i++;
	}
}

static void	pos_sign_less(char *tmp, char **all)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == '-' && i != 0)
			tmp_error(all);
		if (tmp[i] == '-' && ft_strlen(tmp) == 1)
			tmp_error(all);
		i++;
	}
}

void	verif_signs(char **tmp)
{
	int	n;
	int	i;

	i = 0;
	while (tmp[i])
	{
		n = 0;
		while (tmp[i][n])
		{
			if (tmp[i][n] == '+')
				pos_sign_more(tmp[i], tmp);
			if (tmp[i][n] == '-')
				pos_sign_less(tmp[i], tmp);
			n++;
		}
		i++;
	}
}
