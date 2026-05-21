#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>

int    picoshell(char **cmds[])
{
	int fd[2];
	pid_t pid;
	int lst_fd = -1;
	int i = 0;
	int res = 0;
	int status;

	while(cmds[i])
	{
		if (cmds[i + 1] && pipe(fd) == -1)
			return (1);
		pid = fork();
		if (pid == -1)
		{
			if (cmds[i + 1])
			{
				close(fd[1]);
				close(fd[0]);
			}
			return (1);
		}
		if (pid == 0)
		{
			if (lst_fd != -1)
			{
				if (dup2(lst_fd, STDIN_FILENO) == -1)
					exit(1);
				close(lst_fd);
			}
			if (cmds[i + 1])
			{
				close(fd[0]);
				if (dup2(fd[1], STDOUT_FILENO) == -1)
					exit(1);
				close(fd[1]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		if (lst_fd != -1)
			close(lst_fd);
		if (cmds[i + 1])
		{
			close(fd[1]);
			lst_fd = fd[0];
		}
		i++;
	}
	while(wait(&status) > 0)
	{
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			res = 1;
		if (WIFEXITED(status))
			res = 1;
	}
	return (res);
}