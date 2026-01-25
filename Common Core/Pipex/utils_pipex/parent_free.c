/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:29:04 by yamosca-          #+#    #+#             */
/*   Updated: 2026/01/25 18:12:06 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void parent_free(t_pipex *pipex)
{
    int i;

    i = -1;
    while (pipex->paths[++i])
        free(pipex->paths[i]);
    free(pipex->paths);
}
