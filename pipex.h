/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimenasandoval <jimenasandoval@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:06:40 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/22 12:27:07 by jimenasando      ###   ########.fr       */
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
    pid_t   pid;
} t_pipex;

// utils.c
void    check_argc(int n);

//pipex.c
void	child_process(char *argv[], t_pipex pipex, char *env[]);
void	parent_process(char *argv[], t_pipex pipex, char *env[]);



#endif