/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 00:16:03 by yamosca-          #+#    #+#             */
/*   Updated: 2026/01/25 18:11:53 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char **get_paths(char **envp)
{
    int i;
    char **paths;
    
    i = -1;
    paths = NULL;
    while (envp[++i])
    {
        if (ft_strncmp(envp[i], "PATH=", 5) == 0)
            paths = ft_split(envp[i] + 5, ':');
    }
    return (paths);
}
