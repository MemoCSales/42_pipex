/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_execve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:46:53 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/20 17:32:58 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int main(int argc, char *argv[])
// {
// 	char	*const args[] = {"ls", NULL}; // commands
// 	char	*const envp[] = { NULL }; 	// env

// 	execve("/usr/bin/ls", args, envp);

// 	perror("execve");
//     return(1);
// }

void    callexecve()
{
    char    *const args[] = {"ls", NULL};
    char    *const envp[] = { NULL };

    execve("/usr/bin/ls", args, envp);
    perror("execve");
        exit(EXIT_FAILURE);
}
int main(void)
{
    pid_t   pid;

    printf("Hi I am the main process. My PID is: %d\n", getpid());
    pid = fork();
    if (pid == -1)
        printf("Error while forking\n");
    else if (pid == 0)
    {
        printf("I am the child. But now a new parent. My PID is %d -- My child's PID is %d\n", getpid(), pid);
        callexecve();
    }
    else if (pid > 1)
    {
        printf("I am the parent. My PID is: %d --- My child's PID is %d\n", getpid(), pid);
        waitpid(pid, NULL, 0);
        printf("Got back the control?\n");
    }
}