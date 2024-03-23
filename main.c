/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:06:22 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/23 19:49:08 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ./pipex infile cmd1 cmd2 outfile
int	main(int argc, char *argv[], char **env)
{
	t_pipex	pipex;

	check_argc(argc);
	create_pipe(&pipex);
	pipex.pid = fork();
	if (pipex.pid < 0)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
	get_path_env(env, &pipex);
	pipex.dir_paths = ft_split(pipex.path, ':');
	if (pipex.pid == 0)
		child_process(argv, pipex, env);
	waitpid(pipex.pid, NULL, 0);
	parent_process(argv, pipex, env);
	close_pipes(&pipex);
	cleanup_split(pipex.dir_paths);
	return (0);
}
