/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:19:09 by yamosca-          #+#    #+#             */
/*   Updated: 2026/01/21 18:16:50 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
    t_pipex *pipex;

    pipex = malloc(sizeof(t_pipex));

    if (argc != 5)
    {
        perror("The program must have 4 arguments");
        return (1);
    }

    if (pipe(pipex->tube) < 0)
    {
        perror("Pipe error");
        return (1);
    }

    pipex->paths = get_paths(envp);

    if (!pipex->paths | !pipex->paths[0])
    {
        perror("Path vide ou introuvable");
        return (1);
    }

    pipex->infile = open(argv[1], O_RDONLY);
    pipex->outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);

    pipex->pid1 = fork();
    if (pipex->pid1 == 0)
        child_one(pipex, argv, envp);

    pipex->pid2 = fork();
    if (pipex->pid2 == 0)    
        child_two(pipex, argv, envp);

    close_pipes(pipex);

    waitpid(pipex->pid1, NULL, 0);
    waitpid(pipex->pid2, NULL, 0);

    parent_free(pipex);
    free(pipex);

    return (0);
}
