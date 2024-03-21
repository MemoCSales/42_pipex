/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_fork_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:32:48 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/19 20:02:53 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[])
{
    int arr[] = {1, 2, 3, 4, 1, 2, 7};
    int fd[2];
    int id;
    int start, end;
    int arrSize;
    
    if (pipe(fd) == -1)
    {
        perror("Pipe error");
        exit(EXIT_FAILURE);
    }
    
    id = fork();
    if (id == -1)
        exit(EXIT_FAILURE);
    arrSize = sizeof(arr) / sizeof(int);
    if (id == 0)
    {
        start = 0;
        end = start + arrSize / 2;
    }
    else
    {
        start = arrSize / 2;
        end = arrSize;
    }
    
    int sum = 0;
    int i = start;

    while (i < end)
    {
        sum += arr[i];
        i++;
    }
    printf("Calculated partial sum %d\n", sum);

    if (id == 0)
    {
        close(fd[0]);
        if (write(fd[1], &sum, sizeof(sum)) == -1)
            exit(EXIT_FAILURE);
        close(fd[1]);
    }
    else
    {
        int sumFromChild;
        close(fd[1]);
        if(read(fd[0], &sumFromChild, sizeof(sumFromChild)) == -1)
            exit(EXIT_FAILURE);
        close(fd[0]);

        int totalSum = sum + sumFromChild;
        printf("Total sum is %d\n", totalSum);
    }
    wait(NULL);
    return (0);
}