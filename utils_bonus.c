/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:03:21 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/25 17:46:00 by mcruz-sa         ###   ########.fr       */
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

void	get_path_env_bonus(char **env, t_pipex *pipex)
{
	int	i;

	pipex->path = NULL;
	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			pipex->path = env[i] + 5;
			break ;
		}
		i++;
	}
}

void	put_input(t_pipex *pipex, char *argv[])
{
	char	*buffer;

	close(pipex->fd[0]);
	while (1)
	{
		ft_putstr_fd("heredoc>", 1);
		buffer = get_next_line(0);
		if (ft_strncmp(buffer, argv[2], ft_strlen(argv[2])) == 0)
		{
			free(buffer);
			exit(0);
		}
		ft_putstr_fd(buffer, pipex->fd[1]);
		free(buffer);
	}
	free(buffer);
}

int	get_num_cmds(t_pipex *pipex, int argc)
{
	int	i;

	pipex->cmds = 0;
	if (pipex->is_heredoc)
	{
		i = 3;
		while (i < argc - 1)
		{
			pipex->cmds++;
			i++;
		}
		return (pipex->cmds);
	}
	else
	{
		i = 2;
		while (i < argc - 1)
		{
			pipex->cmds++;
			i++;
		}
		return (pipex->cmds);
	}
}

void	prog_exec_bonus(char *argv, char **env, t_pipex *pipex)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	path = cmd_path_bonus(argv, pipex);
	if (execve(path, cmd, env) == -1)
	{
		ft_putstr_fd("Command not found: ", 2);
		ft_putendl_fd(cmd[0], 2);
		cleanup_split_bonus(cmd);
		exit(1);
	}
}
