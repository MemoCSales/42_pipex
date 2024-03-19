/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_FIFO.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:06:55 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/19 20:43:39 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "sys/stat.h"
#include "sys/types.h"
#include "time.h"

/*FISRT STEP: CREATING THE FIFO file*/
// int main(void)
// {
	
// 	if (mkfifo("myfifo1", 0777) == -1)
// 	{
// 		if (errno != EEXIST)
// 		{
// 			printf("Could not create fifo file\n");
// 			return (1);
// 		}
// 	}

// 	printf("Opening...\n");
// 	int	fd = open("myfifo1", O_WRONLY);
// 	if (fd == -1)
// 		return (3);
// 	printf("Opened\n");
// 	int	x = 97;
// 	if (write(fd, &x, sizeof(x)) == -1)
// 	{
// 		return (2);
// 	}
// 	printf("Written\n");
// 	close(fd);
// 	printf("Closed\n");
// 	return (0);
// }


/*FIFO files to communicate between processes*/
/*This function uses the 1_FIFO2.c*/
/*the sum file needs to be created in termianl by mkfifo sum command*/
int	main(void)
{
	int	arr[5];
	srand(time(NULL));
	int	i;

	i = 0;
	while (i < 5)
	{
		arr[i] = rand() % 10;
		i++;
	}
	int	fd = open ("sum", O_WRONLY);
	if (fd == -1)
		return (-1);
	i = 0;
	while (i < 5)
	{
		if (write(fd, &arr[i], sizeof(int)) == -1)
			return (2);
		printf("Wrote %d\n", arr[i]);
		i++;
	}
	close(fd);
	return (0);
}