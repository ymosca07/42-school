/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 14:11:54 by yamosca-          #+#    #+#             */
/*   Updated: 2026/08/10 17:38:15 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void player_orientation(t_render *data, t_player *player)
{
    if (player->position == 'E')
    {
        data->dir_x = 1.0;
	    data->orientation_y = 0.66;
    }
    if (player->position == 'S')
    {
	    data->dir_y = 1.0;
	    data->orientation_x = -0.66;
    }
    if (player->position == 'N')
    {
	    data->dir_y = -1.0;
	    data->orientation_x = 0.66;
    }
    if (player->position == 'W')
    {
        data->dir_x = -1.0;
	    data->orientation_y = -0.66;
    }
}

static void	ft_setup_data(t_config *config, t_player *player, t_map *map, t_render *data)
{
	ft_memset(data, 0, sizeof(t_render));
	data->map = config->map;
	data->map_width = map->width;
	data->map_height = map->height;
	data->px = (double)player->x + 0.5;
	data->py = (double)player->y + 0.5;
    data->dir_x = 0.0;
	data->dir_y = 0.0;
	data->orientation_x = 0.0;
	data->orientation_y = 0.00;
	player_orientation(data, player);
    data->floor_color = config->floor[0] << 16 | config->floor[1] << 8 | config->floor[2];
    data->sky_color = config->ceiling[0] << 16 | config->ceiling[1] << 8 | config->ceiling[2];
    data->path_ea = config->EA;
    data->path_no = config->NO;
    data->path_we = config->WE;
    data->path_so = config->SO;
}

int main(int argc, char **argv)
{
    int x;
    char        **input;
    t_config    *config = ft_calloc(sizeof(t_config), 1);
    t_player    *player = ft_calloc(sizeof(t_player), 1);
    t_map       *map = ft_calloc(sizeof(t_map), 1);
    t_render	data;

    input = NULL;
    if (argc != 2 || cub_extension(argv[1]))
        all_free_error(input, config, map, player);
    input = fill_data(argv[1]);
    if (!input)
        all_free_error(input, config, map, player);
    x = fill_input(config, input);
    if (x == -1)
        all_free_error(input, config, map, player);
    if (rgb_verif(config) == -1)
        all_free_error(input, config, map, player);
    x = maps(config, player, map);
    if (x == -1)
        all_free_error(input, config, map, player);
    ft_setup_data(config, player, map, &data);
	ft_mlx_game_init(&data);
    all_free(input, config, map, player);
    return (0);
}

