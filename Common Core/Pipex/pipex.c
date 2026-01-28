/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:19:09 by yamosca-          #+#    #+#             */
/*   Updated: 2026/01/27 12:19:00 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void end_action(t_pipex *pipex)
{
	close_pipes(pipex);
	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
	parent_free(pipex);
	free(pipex);
}
static void fork_action(t_pipex *pipex, char **argv, char **envp)
{
	pipex->pid1 = fork();
	if (pipex->pid1 == 0)
		child_one(pipex, argv, envp);
	pipex->pid2 = fork();
	if (pipex->pid2 == 0)
		child_two(pipex, argv, envp);
}

static void file_descriptor_action(t_pipex *pipex, char **argv)
{
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
		error_signal("No such file or directory\n");
	pipex->outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile < 0)
		error_signal("Permission denied\n");
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	if (argc != 5)
	{
		error_signal("The program must have 4 arguments\n");
		return (1);
	}
	pipex = calloc(sizeof(t_pipex), 1);
	if (pipe(pipex->tube) < 0)
	{
		error_signal("Pipe initialization error\n");
		free(pipex);
		return (1);
	}
	pipex->paths = get_paths(envp);
	if (!pipex->paths | !pipex->paths[0])
	{
		error_signal("Path vide ou introuvable\n");
		return (1);
	}
	file_descriptor_action(pipex, argv);
	fork_action(pipex, argv, envp);
	end_action(pipex);
	return (0);
}
