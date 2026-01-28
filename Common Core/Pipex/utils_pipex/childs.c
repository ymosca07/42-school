/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 09:50:25 by yamosca-          #+#    #+#             */
/*   Updated: 2026/01/27 12:29:22 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void error_call(t_pipex *pipex)
{
    close_pipes(pipex);
	parent_free(pipex);
	free(pipex);
	exit(1);
}

void child_two(t_pipex *pipex, char **argv, char **envp)
{
    if (pipex->outfile < 0)
        error_call(pipex);
    pipex->cmd_args = ft_split(argv[3], ' ');
    pipex->cmd_path = find_cmd(pipex->paths, pipex->cmd_args[0]);
    if (!pipex->cmd_path)
    {
        error_signal("Second command not found\n");
        error_call(pipex);
    }

    close(pipex->tube[1]);
    dup2(pipex->tube[0], STDIN_FILENO);
    dup2(pipex->outfile, STDOUT_FILENO);
    close(pipex->tube[0]);
    close(pipex->outfile);
    execve(pipex->cmd_path, pipex->cmd_args, envp);

    error_signal("Execve fail");
    exit(127);
}

void child_one(t_pipex *pipex, char **argv, char **envp)
{
    if (pipex->infile < 0)
        error_call(pipex);
    
    pipex->cmd_args = ft_split(argv[2], ' ');
    pipex->cmd_path = find_cmd(pipex->paths, pipex->cmd_args[0]);
    if (!pipex->cmd_path)
    {
        error_signal("First command not found\n");
        error_call(pipex);
    }

    close(pipex->tube[0]);
    dup2(pipex->infile, STDIN_FILENO);
    dup2(pipex->tube[1], STDOUT_FILENO);
    close(pipex->infile);
    close(pipex->tube[1]);
    execve(pipex->cmd_path, pipex->cmd_args, envp);

    error_signal("Execve fail");
    exit(127);
}
