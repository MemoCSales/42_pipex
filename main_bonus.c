/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimenasandoval <jimenasandoval@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:28:12 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/24 23:58:55 by jimenasando      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_openfile(t_pipex *pipex, char *file)
{
	if (file = "outfile")
	{
		if (pipex->outfile < 0)
			{
				ft_putstr_fd("Error opening outfile\n", STDERR_FILENO);
				exit(1);
			}
	}
	else if (file = "infile")
	{
		if (pipex->infile < 0)
		{
			ft_putstr_fd("Error opening outfile\n", STDERR_FILENO);
			exit(1);
		}
	}
}

int	main(int argc, char *argv[], char *env[])
{
	t_pipex pipex;
	int		is_heredoc;

	is_heredoc = check_heredoc(argc, argv);
	get_path_env(env, &pipex);
	pipex.dir_paths - ft_split(pipex.path, ':');
	if (is_heredoc)
	{
		pipex.outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
		check_openfile(&pipex, "outfile");
		do_here_doc(&pipex, argv);
	}
	else
	{
		pipex.infile = open(argv[1], O_RDONLY, 0777);
		check_openfile(&pipex, "infile");
		pipex.outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		check_openfile(&pipex, "outfile");
		dup2(pipex.infile, STDIN_FILENO);
		close(pipex.infile);
	}
	close_pipes(&pipex);
	cleanup_split(pipex.dir_paths);
	return (0);
}
