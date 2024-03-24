/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:59:55 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/24 19:54:30 by mcruz-sa         ###   ########.fr       */
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
} t_pipex;

//utils_bonus.c
int     check_heredoc(int n, char *argv[]);
void	do_here_doc(t_pipex *pipex, char *argv[]);

#endif