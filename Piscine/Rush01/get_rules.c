/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flortie <marvin@d42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:35:08 by flortie           #+#    #+#             */
/*   Updated: 2025/09/13 11:35:08 by flortie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	count_numbers(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '4')
			j++;
		i++;
	}
	return (j);
}

char	*get_rules(char *str)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = count_numbers(str);
	if (!(*str))
		return (0);
	if (j != 16)
		return (0);
	res = (char *)malloc(j + 1);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			res[j] = str[i] - '0';
			j++;
		}
		i++;
	}
	return (res);
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	if (argc <= 1)
		return (0);
	char *test = get_rules(argv[1]);
	printf("%s", test);
	free(test);
}
