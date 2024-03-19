/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:54:35 by mcruz-sa          #+#    #+#             */
/*   Updated: 2024/03/19 19:34:01 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//This main function represents the creation of a parent and a child process
// int main(int argc, char *argv[])
// {
// 	int id;

// 	id = fork();
// 	// printf("Hello world from id: %d\n", id);
// 	if (id == 0)
// 		printf("Hello from child process\n");
// 	else
// 	{
// 		printf("Hello from the main process\n");
// 	}
// 	return (0);
// }



/* This main function is to represent that 3 child process were created */
// int main(int argc, char *argv[])
// {
// 	int id;

// 	id = fork();
// 	if (id != 0)
// 		fork();
// 	printf("Hello world\n");

// 	return (0);
// }



/*wait function implementation*/
// int	main(int argc, char *argv[])
// {
// 	int id = fork();
// 	int	n;
// 	int i;
// 	int	status;

// 	if (id == 0)
// 		n = 1;
// 	else
// 		n = 6;

// 	if (id != 0)
// 		wait(&status);
// 	i = n;
// 	while (i < n + 5)
// 	{
// 		printf("%d ", i);
// 		fflush(stdout);
// 		i++;
// 	}
	
// 	if (id != 0)
// 		printf("\n");
	
// 	return (0);
// }




/*GET THE IDS OF THE PROCESSES*/
/*getpid() -> returns the child process ID*/
/*getppid() -> returns the parent process ID*/
// int	main(void)
// {
// 	int	id;

// 	id = fork();
// 	if (id == 0)
// 	{
// 		sleep(1);
// 	}
// 	printf("Current ID; %d, parent ID: %d\n", getpid(), getppid());
// 	if (id != 0)
// 	{
// 		wait(NULL);
// 	}
// 	return(0);
// }



/*CALLING FORK MULTIPLE TIMES*/
int	main(void)
{
	int	id, id2;

	id = fork();
	id2 = fork();
	if (id == 0)
	{
		if (id2 == 0)
			printf("We are process y\n");
		else
			printf("We are process x\n");
	}
	else
	{
		if (id2 == 0)
			printf("We are process z\n");
		else
		printf("We are the parent process!\n");
	}
	while(wait(NULL) != -1 || errno != ECHILD)
		printf("Waited for a child to finish\n");
	return(0);
}