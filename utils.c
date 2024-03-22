/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:54:35 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/22 20:37:33 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    check_argc(int n)
{
    if (n < 5)
	{
        ft_putstr_fd("./pipex infile cmd1 cmd2 outfile\n", STDERR_FILENO);
		exit(1);
	}
}

void	get_path_env(char **env, t_pipex *pipex)
{
	int		i;
	char	*path_env;

	path_env = NULL;
	pipex->path = NULL;
	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path_env = (char *)malloc(ft_strlen(env[i]) - 4);
			ft_strcpy(path_env, env[i] + 5);
			pipex->path = path_env;
			break;
		}
		i++;
	}
}

void	ft_strcpy(char *dst, const char *src)
{
	while (*src != '\0')
	{
		*dst = *src;
		src++;
		dst++;
	}
	*dst = '\0';
}

void	prog_exec(char *argv, char **env, t_pipex pipex)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	path = cmd_path(argv, pipex);
	if(execve(path, cmd, env) == -1)
	{
		ft_putstr_fd("Command not found: ", 2);
		ft_putendl_fd(cmd[0], 2);
		cleanup_split(cmd);
		exit(1);
	}
}

char	*cmd_path(char *argv, t_pipex pipex)
{
	int		i;
	char	*prog;
	char	*path_cmd;
	char	**cmd;

	cmd = ft_split(argv, ' ');
	i = 0;
	while (pipex.dir_paths[i])
	{
		path_cmd = ft_strjoin(pipex.dir_paths[i], "/");
		prog = ft_strjoin(path_cmd, cmd[0]);
		free(path_cmd);
		if (access(prog, F_OK | X_OK) == 0)
		{
			cleanup_split(cmd);
			return (prog);
		}
		free(prog);
		i++;
	}
	cleanup_split(pipex.dir_paths);
	cleanup_split(cmd);
	return(argv);
}
