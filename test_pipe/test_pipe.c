#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	char	buffer[100];
	int		fd[2];
	int		pid;

	if (pipe(fd) == -1)
	{
		printf("pipe function failed\n");
		return (0);
	}
	pid = fork();
	if (pid < 0)
	{
		printf("fork function failed\n");
		return (0);
	}
	if (pid != 0)
	{
		close(fd[1]);
		sleep(3);
		read(fd[0], buffer, 100);
		printf("child said : %s\n", buffer);
		close(fd[0]);
	}
	else
	{
		close(fd[0]);
		write(fd[1], "bonjour reuf", strlen("bonjour reuf"));
		close(fd[1]);
	}
	return (0);
}
