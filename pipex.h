/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:06:40 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/22 19:59:10 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>

typedef struct s_pipex
{
    int     infile;
    int     outfile;
    int     fd[2];
    char    *path;
    char    **dir_paths;
    pid_t   pid;
} t_pipex;

// utils.c
void    check_argc(int n);
void	get_path_env(char **env, t_pipex *pipex);
void	ft_strcpy(char *dst, const char *src);
void	prog_exec(char *argv, char **env, t_pipex pipex);
char	*cmd_path(char *argv, t_pipex pipex);
void	cleanup_split(char **split);

//pipex.c
void	child_process(char *argv[], t_pipex pipex, char *env[]);
void	parent_process(char *argv[], t_pipex pipex, char *env[]);



#endif