/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 00:51:36 by yamosca-          #+#    #+#             */
/*   Updated: 2026/01/25 18:11:45 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char *find_cmd(char **paths, char *cmd)
{
    char *full_path;
    char *tmp_path;
    int i;

    i = -1;
    while (paths[++i])
    {
        tmp_path = ft_strjoin(paths[i], "/");
        full_path = ft_strjoin(tmp_path, cmd);
        if (access(full_path, F_OK | X_OK) == 0)
            return (full_path);
        else
        {
            free(tmp_path);
            free(full_path);
        }
    }
    return (NULL);
}