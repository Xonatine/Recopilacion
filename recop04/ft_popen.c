/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_popen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:18:22 by dgargant          #+#    #+#             */
/*   Updated: 2025/11/11 17:22:16 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>


int ft_popen(const char *file, char *const argv[], char type)
{
	int fd[2];
	pid_t pid;
	
	if (!file || !argv || (type != 'r' && type != 'w'))
		return (-1);
	if (pipe(fd) == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
	{
		close(fd[0]);
		close(fd[1]);
		return (-1);
	}
	if (pid == 0)
	{
		if (type == 'r')
		{
			if (dup2(fd[1], STDOUT_FILENO) == -1)
				exit(1);
		}
		else
		{
			if (dup2(fd[0], STDIN_FILENO) == -1)
				exit(1);	
		}
		close(fd[0]);
		close(fd[1]);
		execvp(file, argv);
		exit(1);
	}
	else
	{
		if (type == 'r')
		{
			close(fd[1]);
			return (fd[0]);
		}
		else
		{
			close(fd[0]);
			return(fd[1]);
		}
	}
}

