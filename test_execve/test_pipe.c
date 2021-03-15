#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char	*exec_arg1(char **envp)
{
	pid_t	pid;
	char	*tabs[] = {"/bin/ls", NULL};
	char	*something;

	something = malloc (sizeof(char) * 100);
	pid = fork();
	if (pid < 0)
	{
		printf("Process issues.\n");
		return (NULL);
	}
	if (pid == 0)
	{
		printf("child : %p\n", something);
		execve(tabs[0], tabs, envp);
		exit(0);
	}
	else
		printf("parent : %p\n", something);
	return (something);
}

int		main(int argc, char **argv, char **envp)
{
	char *something = exec_arg1(envp);
	wait(NULL);
	free(something);
	return (0);
}
