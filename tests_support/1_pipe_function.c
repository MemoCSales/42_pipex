/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_pipe_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:41:28 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/19 19:55:14 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*practicing with pipes*/
int main(void)
{
    int fd[2];
    int id;
    
    if (pipe(fd) == -1)
    {
        printf("An error ocurred with opening the pipe\n");
        return (1);
    }
    id = fork();
    if (id == -1)
    {
        printf("An error ocurred with forking\n");
        return (4);
    }
    if (id == 0)
    {
        close(fd[0]);
        int x;
        printf("Input a number: ");
        scanf("%d", &x);
        if (write(fd[1], &x, sizeof(int)) == -1)
        {
            printf("An error ocurred with writing to the pipe\n");
            return (2);
        }
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        int y;
        if (read(fd[0], &y, sizeof(int)) == -1)
        {
            printf("An error ocurred with reading from the pipe\n");
            return (3);
        }
        y = y * 3;
        close(fd[0]);
        printf("Got from chile process %d\n", y);
    }
    return (0);
}
