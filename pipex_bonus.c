
#include "pipex_bonus.h"

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

