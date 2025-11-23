/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emheuga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:57:26 by emheuga           #+#    #+#             */
/*   Updated: 2025/09/13 11:57:28 by emheuga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int main (int argc, char ** argv)
{
	int max_int;
	int view;
	int i;
	
	i = 0;
	max_int = (argv[1][i]);
	view = 1;
	if (argc != 2)
		write (1, "error", 5);

	while (argv[1][i])
	{
		if (argv[1][i] > max_int)
			{
				max_int = argv[1][i];
				view++;
			}
	i++;
	}
	printf("%d", view);
	return (view);
}
