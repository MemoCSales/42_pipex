/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:28:12 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/25 17:51:30 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char *argv[], char *env[])
{
	t_pipex	pipex;
	int		i;

	pipex.is_heredoc = check_heredoc(argc, argv);
	pipex.start_index = get_index(&pipex);
	get_path_env_bonus(env, &pipex);
	pipex.dir_paths = ft_split(pipex.path, ':');
	if (pipex.is_heredoc)
	{
		pipex.outfile = open(argv[argc - 1], O_WRONLY | O_APPEND, 0777);
		do_here_doc(&pipex, argv);
	}
	else
	{
		pipex.infile = open(argv[1], O_RDONLY, 0777);
		pipex.outfile = open(argv[argc - 1], O_WRONLY | O_TRUNC, 0777);
		dup2(pipex.infile, STDIN_FILENO);
		close(pipex.infile);
	}
	i = pipex.start_index - 1;
	while (++i < argc - 2)
		child_process_bonus(argv[i], &pipex, env);
	dup2(pipex.outfile, STDOUT_FILENO);
	waitpid(pipex.pid1, NULL, 0);
	prog_exec_bonus(argv[argc - 2], env, &pipex);
}
