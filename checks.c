
#include "pipex.h"

void    check_argc(int n)
{
    if (n < 5)
	{
        ft_putstr_fd("./pipex infile cmd1 cmd2 outfile\n", STDERR_FILENO);
		exit(1);
	}
}