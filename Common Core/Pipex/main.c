/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:19:09 by yamosca-          #+#    #+#             */
/*   Updated: 2026/01/19 01:48:20 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int main(int argc, char **argv, char **envp)
{
    char **paths;
    char *cmd_path;
    char **cmd_args;
    
    paths = get_paths(envp);
    
    if (!paths)
        return (1);

    cmd_args = ft_split(argv[2], ' ');

    cmd_path = find_cmd(paths, cmd_args[0]);
        
    printf("%s\n", cmd_path);
}