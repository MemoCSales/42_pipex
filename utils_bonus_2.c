/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:47:41 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/25 17:51:41 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	cleanup_split_bonus(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	split = NULL;
}

void	close_pipes(t_pipex *pipex)
{
	close(pipex->fd[0]);
	close(pipex->fd[1]);
}

char	*cmd_path_bonus(char *argv, t_pipex *pipex)
{
	int		i;
	char	*prog;
	char	*path_cmd;
	char	**cmd;

	cmd = ft_split(argv, ' ');
	i = 0;
	while (pipex->dir_paths[i])
	{
		path_cmd = ft_strjoin(pipex->dir_paths[i], "/");
		prog = ft_strjoin(path_cmd, cmd[0]);
		free(path_cmd);
		if (access(prog, F_OK | X_OK) == 0)
		{
			cleanup_split_bonus(cmd);
			return (prog);
		}
		free(prog);
		i++;
	}
	cleanup_split_bonus(pipex->dir_paths);
	cleanup_split_bonus(cmd);
	return (argv);
}

void	check_openfile(t_pipex *pipex, int file_type)
{
	if (file_type)
	{
		if (pipex->outfile < 0)
		{
			ft_putstr_fd("Error opening outfile\n", STDERR_FILENO);
			exit(1);
		}
	}
	else
	{
		if (pipex->infile < 0)
		{
			ft_putstr_fd("Error opening infile\n", STDERR_FILENO);
			exit(1);
		}
	}
}

int	get_index(t_pipex *pipex)
{
	pipex->start_index = 0;
	if (pipex->is_heredoc)
		pipex->start_index = 3;
	else
		pipex->start_index = 2;
	return (pipex->start_index);
}
