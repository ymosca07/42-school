/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarolla <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 22:03:39 by adarolla          #+#    #+#             */
/*   Updated: 2025/09/24 20:22:03 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

int	measure_byte(char *file)
{
	int	byte;
	char		*buffer;
	int	fd;
	int	nb;

	nb = 0;
	byte = 1;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		write(1, "map error\n", 10);
		return (1);
	}
	while (byte > 0)
	{
		buffer = malloc((sizeof(char) * 50) + 1);
		byte = read(fd, buffer, 50);
		nb += byte;
	}
	close(fd);
	return (nb);
}

char	*get_map(char *file)
{
	int	byte;
	char	*buffer;
	int	fd;
	char	*str;
	
	byte = 1;
	fd = open(file, O_RDONLY);
	str = malloc(measure_byte(file));
	while (byte > 0)
	{
		buffer = malloc((sizeof(char) * 50) + 1);
		byte = read(fd, buffer, 50);
		str = ft_strcat(str, buffer);
	}
	close(fd);
	return(str);
}
