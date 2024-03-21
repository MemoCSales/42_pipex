/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_FIFO_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:30:21 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/19 20:39:38 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "sys/stat.h"
#include "sys/types.h"
#include "time.h"

/*FIFO files to communicate between processes*/
/*This function uses the 1_FIFO2.c*/
int	main(void)
{
	int	arr[5];
    int	fd = open ("sum", O_RDONLY);
	if (fd == -1)
		return (-1);
	
    int	i;

	i = 0;
	while (i < 5)
	{
		if (read(fd, &arr[i], sizeof(int)) == -1)
			return (2);
		printf("Received %d\n", arr[i]);
		i++;
	}
	close(fd);
    int sum = 0;
    i = 0;
    while (i < 5)
    {
        sum += arr[i];
        i++;
    }
    printf("Result is %d\n", sum);
	return (0);
}