/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 09:06:41 by bjacquet          #+#    #+#             */
/*   Updated: 2025/09/20 09:06:46 by bjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

int	int_prog(char *nb, char *file)
{
	char	*content;

	(void)nb;
	if (!ft_existe_file(file))
		return (ft_puterror("Dict Error"));
	content = ft_file_to_str(file);
	if (!content)
	{
		return (ft_puterror("Dict Error"));
	}
	ft_putstr(content);
	return (1);
}

int	main(int ac, char **av)
{
	char		*file;

	file = "numbers.dict";
	if (ac < 2 || ac > 3)
	{
		return (ft_puterror("Error"));
	}
	else if (ac == 2)
	{
		if (!ft_str_is_numeric(av[1]))
			return (ft_puterror("Error"));
		else
			int_prog(av[1], file);
	}
	else if (ac == 3)
	{
		if (!ft_str_is_numeric(av[2]) || !ft_str_is_alpha(av[1]))
			return (ft_puterror("Error"));
		else
			int_prog(av[2], av[1]);
	}
	return (0);
}
