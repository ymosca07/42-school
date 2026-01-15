/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_height_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:23:32 by yamosca-          #+#    #+#             */
/*   Updated: 2026/01/15 17:36:58 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_height_map(t_game *game, char *file)
{
	int		fd;
	char	*tmp;
	int		count;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free_struct(game);
		error_signal("Error\nFile descriptor error");
	}
	count = 0;
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		free(tmp);
		count++;
		tmp = get_next_line(fd);
	}
	close(fd);
	return (count);
}
