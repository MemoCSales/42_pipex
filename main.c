/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimenasandoval <jimenasandoval@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:06:22 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/23 15:51:09 by jimenasando      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ./pipex infile cmd1 cmd2 outfile
int main(int argc, char *argv[], char **env)
{
	t_pipex	pipex;

	// printf("Before check_argc\n");
	check_argc(argc);
	// printf("After check_argc\n");
	create_pipe(&pipex);
	pipex.pid = fork();
	if (pipex.pid < 0)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
	// printf("Before get_path_env function\n");
	get_path_env(env, &pipex);
	// printf("After get_path_env_function\n");
	pipex.dir_paths = ft_split(pipex.path, ':');
	if (pipex.pid == 0)
	{
		// printf("Before child process function\n");
		child_process(argv, pipex, env);
		// printf("After child process function\n");
		exit(1);
	}
	else
	{
		waitpid(pipex.pid, NULL, 0);
		// printf("Before parent process function\n");
		parent_process(argv, pipex, env);
		// printf("After parent process function\n");
		close_pipes(&pipex);
		cleanup_split(pipex.dir_paths);
		free(pipex.path);
	}
	return (0);   
}

// int main(int argc, char *argv[])
// {
// 	int fd[2];
// 	int	pid1;

// 	if (pipe(fd) == -1)
// 	{
// 		perror("Pipe error");
// 		exit(EXIT_FAILURE);
// 	}

// 	pid1 = fork();
// 	if (pid1 < 0)
// 	{
// 		perror("Child process error");
// 		exit(EXIT_FAILURE);
// 	}
// 	if (pid1 == 0)
// 	{
// 		//child process
// 		// const char	*filename = "/usr/bin/grep";
// 		// char	*const argv[] = {"/usr/bin/grep", "a", NULL};
// 		// execve(filename, argv, envp);
// 		dup2(fd[1], STDOUT_FILENO);
// 		close(fd[0]);
// 		close(fd[1]);
// 		execlp("ping", "ping", "-c", "5", "google.com", NULL);
// 	}
// 	int pid2 = fork();
// 	if (pid2 == 0)
// 	{
// 		//child process 2
// 		dup2(fd[0], STDIN_FILENO);
// 		close(fd[1]);
// 		close(fd[0]);
// 		execlp("grep", "grep", "rtt", NULL);
// 	}
// 	close(fd[0]);
// 	close(fd[1]);
// 	waitpid(pid1, NULL, 0);
// 	waitpid(pid2, NULL, 0);
// 	return (0);

// }
