/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimenasandoval <jimenasandoval@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:59:55 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/25 11:03:51 by jimenasando      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "./libft/libft.h"
# include "support/ft_printf.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
    int     infile;
    int     outfile;
    int     fd[2];
    char    *path;
    char    **dir_paths;
    pid_t   pid1;
    pid_t   pid2;
    int     is_heredoc;
    int     cmds;
} t_pipex;

//utils_bonus.c
int     check_heredoc(int n, char *argv[]);
void	get_path_env(char **env, t_pipex *pipex);
void	put_input(t_pipex *pipex, char *argv[]);
void	do_here_doc(t_pipex *pipex, char *argv[]);

//utils_bonus_2.c
void	cleanup_split(char **split);
void	close_pipes(t_pipex *pipex);


#endif