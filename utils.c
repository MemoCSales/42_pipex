
#include "pipex.h"

void    check_argc(int n)
{
    if (n < 5)
	{
        ft_putstr_fd("./pipex infile cmd1 cmd2 outfile\n", STDERR_FILENO);
		exit(1);
	}
}

void	get_path_env(char **env)
{
	int		i;
	char	*path_env;
	t_pipex pipex;

	path_env = NULL;
	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path_env = (char *)malloc(ft_strlen(env[i]) - 4);
			ft_strcpy(path_env, env[i] + 5);
			break;
		}
		i++;
	}
	pipex.path = path_env;
	free(path_env);
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
