/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:59:55 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/25 17:23:02 by mcruz-sa         ###   ########.fr       */
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
	int		infile;
	int		outfile;
	int		fd[2];
	char	*path;
	char	**dir_paths;
	pid_t	pid1;
	pid_t	pid2;
	int		is_heredoc;
	int		cmds;
	int		start_index;
}			t_pipex;

// pipex_bonus.c
void		do_here_doc(t_pipex *pipex, char *argv[]);
void		child_process_bonus(char *argv, t_pipex *pipex, char **env);

// utils_bonus.c
int			check_heredoc(int n, char *argv[]);
void		get_path_env_bonus(char **env, t_pipex *pipex);
void		put_input(t_pipex *pipex, char *argv[]);
int			get_num_cmds(t_pipex *pipex, int argc);
void		prog_exec_bonus(char *argv, char **env, t_pipex *pipex);

// utils_bonus_2.c
void		cleanup_split_bonus(char **split);
void		close_pipes(t_pipex *pipex);
char		*cmd_path_bonus(char *argv, t_pipex *pipex);
void		check_openfile(t_pipex *pipex, int file_type);
int			get_index(t_pipex *pipex);

#endif