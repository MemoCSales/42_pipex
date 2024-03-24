/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:03:21 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/24 21:22:11 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	check_heredoc(int n, char *argv[])
{
	if (ft_strncmp(argv[1], "here_doc", 7) == 0)
	{
		if (n < 6)
		{
			ft_putstr_fd("./pipex here_doc LIMITER cmd cmd1 file\n", 2);
			exit(1);
		}
		return (1);
	}
	else if (ft_strncmp(argv[1], "here_doc", 7) != 0)
	{
		if (n < 6)
		{
			ft_putstr_fd("./pipex infile cmd1 cmd2 cmd3 ... outfile\n", 2);
			exit(1);
		}
	}
	return (0);
}

void	put_input(t_pipex *pipex, char *argv[])
{
	char	*buffer;
	int		file;

	close(pipex->fd[0]);
	file = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (file < 0)
	{
		ft_putstr_fd("Error opening .heredoc_tmp file", 2);
		exit(1);
	}
	while (1)
	{
		ft_putstr_fd("heredoc>", 1); //check if it is 0 or 1
		buffer = get_next_line(0);
		if (ft_strncmp(buffer, argv[2], ft_strlen(argv[2])) == 0)
		{
			free(buffer);
			break;
		}
		ft_putstr_fd(buffer, pipex->fd[1]);
		free(buffer);
	}
	
}

void	do_here_doc(t_pipex *pipex, char *argv[])
{
	if (pipe(pipex->fd) == -1)
	{
		perror("Pipe error");
		exit(EXIT_FAILURE);
	}
	pipex->pid1	= fork();
	if (pipex->pid1 < 0)
	{
		perror("Fork error in here_doc");
		exit(EXIT_FAILURE);
	}
	// ./pipex here_doc LIMITER cmd cmd1 file
	if (pipex->pid1 == 0)
		//Child process
		put_input(&pipex, argv); //function to handle here_doc
	else
	{
		//Parent process
		close(pipex->fd[1]);	//close writting end of pipe
		dup2(pipex->fd[0], STDIN_FILENO);	//
		waitpid(pipex->pid1, NULL, 0);
	}
}
