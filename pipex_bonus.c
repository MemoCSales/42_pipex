/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:47:49 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/25 17:52:10 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	do_here_doc(t_pipex *pipex, char *argv[])
{
	if (pipe(pipex->fd) == -1)
	{
		perror("Pipe error");
		exit(EXIT_FAILURE);
	}
	pipex->pid1 = fork();
	if (pipex->pid1 < 0)
	{
		perror("Fork error in here_doc");
		exit(EXIT_FAILURE);
	}
	if (pipex->pid1 == 0)
		put_input(pipex, argv);
	else
	{
		close(pipex->fd[1]);
		dup2(pipex->fd[0], STDIN_FILENO);
		waitpid(pipex->pid1, NULL, 0);
	}
}

void	child_process_bonus(char *argv, t_pipex *pipex, char **env)
{
	if (pipe(pipex->fd) == -1)
	{
		perror("Pipe error");
		exit(EXIT_FAILURE);
	}
	pipex->pid1 = fork();
	if (pipex->pid1 < 0)
	{
		perror("Fork error in child");
		exit(EXIT_FAILURE);
	}
	if (pipex->pid1 == 0)
	{
		printf("here");
		close(pipex->fd[0]);
		dup2(pipex->fd[1], STDOUT_FILENO);
		prog_exec_bonus(argv, env, pipex);
	}
	else
	{
		close(pipex->fd[1]);
		dup2(pipex->fd[0], 0);
	}
}
