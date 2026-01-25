/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamosca- <yamosca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 00:33:01 by yamosca-          #+#    #+#             */
/*   Updated: 2026/01/25 18:25:04 by yamosca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#   define PIPEX_H

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>

typedef struct s_pipex 
{
    int tube[2];
    int infile;
    int outfile;
    char **paths;
    char *cmd_path;
    char **cmd_args;
    pid_t pid1;
    pid_t pid2;
}   t_pipex;

char **get_paths(char **envp);
char *find_cmd(char **paths, char *cmd);
void    close_pipes(t_pipex *pipex);
void parent_free(t_pipex *pipex);
void child_one(t_pipex *pipex, char **argv, char **envp);
void child_two(t_pipex *pipex, char **argv, char **envp);
void    error_signal(char *str);

int	ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);

#endif