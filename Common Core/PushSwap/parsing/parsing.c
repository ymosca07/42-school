/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:20:35 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/14 14:44:34 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ltab_error(char **tmp, long *stack, int n)
{
	free(tmp[n]);
	n++;
	while (tmp[n])
	{
		free(tmp[n]);
		n++;
	}
	free(tmp);
	free(stack);
	write(2, "Error\n", 6);
	exit(1);
}

void	tmp_error(char **tmp)
{
	int	n;

	n = 0;
	while (tmp[n])
	{
		free(tmp[n]);
		n++;
	}
	free(tmp);
	write(2, "Error\n", 6);
	exit(1);
}

static long	*get_long_tab(char **tmp, long *stack)
{
	int	n;
	int	error;

	error = 0;
	n = 0;
	while (tmp[n])
	{
		stack[n] = ft_atol(tmp[n], &error);
		if (error == -1)
			ltab_error(tmp, stack, n);
		free(tmp[n]);
		n++;
	}
	return (stack);
}

long	*parsing(char **argv, int *count)
{
	char	*str;
	long	*stack;
	char	**tmp;

	str = NULL;
	stack = NULL;
	tmp = NULL;
	check_empty_string(argv);
	str = init_split_stack(argv);
	tmp = ft_split(str, ' ');
	free(str);
	verif_signs(tmp);
	while (tmp[*count])
		(*count)++;
	stack = malloc(sizeof(long) * (*count));
	if (!stack)
		return (NULL);
	stack = get_long_tab(tmp, stack);
	free(tmp);
	last_verif(stack, count);
	return (stack);
}
