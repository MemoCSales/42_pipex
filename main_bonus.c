/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:28:12 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/24 21:19:53 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char *argv[], char *env[])
{
	t_pipex pipex;
	int		is_heredoc;

	is_heredoc = check_heredoc(argc, argv);
	if (is_heredoc)
	{
		pipex.outfile = open (argv[argc -1], O_WRONLY | O_CREAT | O_APPEND, 0777);
		if (pipex.outfile < 0)
		{
			ft_putstr_fd("Error opening outfile\n", STDERR_FILENO);
			exit(1);
		}
		do_here_doc(&pipex, argv);
	}
	return (0);
}
