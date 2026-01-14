/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:29:58 by yamosca-          #+#    #+#             */
/*   Updated: 2025/12/18 17:52:13 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**copy_map(char **map, t_game *game)
{
	int		n;
	char	**tmp;

	n = -1;
	tmp = (char **)ft_calloc(game->map_h, 23);
	if (!tmp)
		return (NULL);
	while (game->map[++n])
	{
		tmp[n] = ft_strdup(map[n]);
		if (!tmp[n])
			return (NULL);
	}
	return (tmp);
}
