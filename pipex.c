/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimenasandoval <jimenasandoval@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:54:28 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/23 15:57:32 by jimenasando      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char *argv[], t_pipex pipex, char *env[])
{
	pipex.infile = open(argv[1], O_RDONLY, 0777);
	if (pipex.infile < 0)
	{
		ft_putstr_fd("Error opening infile\n", STDERR_FILENO);
		exit(1);
	}
	// printf("Before first dup2 in childprocess\n");
	dup2(pipex.infile, STDIN_FILENO);
	close(pipex.infile);
	dup2(pipex.fd[1], STDOUT_FILENO);
	close(pipex.fd[0]);
	prog_exec(argv[2], env, pipex);
}

void	parent_process(char *argv[], t_pipex pipex, char *env[])
{
	pipex.outfile = open(argv[4], O_TRUNC | O_CREAT | O_RDWR , 0777);
	if (pipex.outfile < 0)
	{
		ft_putstr_fd ("Error opening outfile\n", STDERR_FILENO);
		exit(1);
	}
	dup2(pipex.outfile, STDOUT_FILENO);
	close(pipex.outfile);
	dup2(pipex.fd[0], STDIN_FILENO);
	close(pipex.fd[1]);
	prog_exec(argv[3], env, pipex);
	}

