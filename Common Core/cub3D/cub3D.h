/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 18:03:48 by yamosca-          #+#    #+#             */
/*   Updated: 2026/08/10 17:31:41 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include <unistd.h>

typedef struct s_config {
    
    char *NO;
    char *SO;
    char *WE;
    char *EA;

    int ceiling[3];
    int floor[3];
    
    char **map;
    
}t_config ;

typedef struct s_player {
    
    int x;
    int y;

    int position;
    
}t_player;

typedef struct s_map {

    int height;
    int width;

}t_map;

# include "minilibx-linux/mlx.h"
# include "utils/utils.h"
# include "parsing/parsing.h"
# include "maps/maps.h"
# include "get_next_line/get_next_line.h"
# include "free/free.h"
# include "render.h"

#endif