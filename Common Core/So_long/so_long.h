/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:23:29 by yamosca-          #+#    #+#             */
/*   Updated: 2026/01/07 12:40:00 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#   define SO_LONG_H

#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"
#include "minilibx-linux/mlx.h"

typedef struct s_game
{
    void *mlx;
    void *window;
    char **map;

    int map_w; 
    int map_h;

    int player_x;
    int player_y;

    int collectibles;
    int steps;

    void    *img_wall; 
    void    *img_floor; 
    void    *img_player;
    void    *img_collect;
    void    *img_exit;
    void    *img_nocol;
} t_game;

int     ft_strlen(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(char *str);
char    **copy_map(char **map, t_game *game);
void    free_all(char **tmp);

int     get_height_map(char *file);
void    read_map(char *file, t_game *game);
void    player_position(t_game *game);

void    aff_sprites(t_game *game, void *mlx, void *win);
void    load_sprites(t_game *game, void *mlx, int *signal);

void    check_stuff(t_game *game);
void    wall_check(t_game *game);
void    error_signal(char *str);
int     ber_extension(char *argv);
void    map_len(t_game *game);
void    flood_fill(int y, int x, char f, char **map);
void    end_possible(char **map);
void    screen_security(t_game *game);
void    free_struct(t_game *game);

int inputs_keycode(int keycode, t_game *game);

#endif