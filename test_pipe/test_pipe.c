#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct	s_saver
{
	int	*current_pfd;
	int	*past_pfd;
}				t_saver;

int		exec_arg0(char **envp, t_saver *saver)
{
	pid_t	pid;
	char	*tabs[] = {"/usr/bin/hexdump", "-C", NULL};
	int		flag = 0;

	pid = fork();
	if (pid < 0)
	{
		printf("Process issues.\n");
		return (-1);
	}
	if (pid == 0)
	{
		close(saver->current_pfd[1]);
		close(0);
		dup(saver->current_pfd[0]);
		execve(tabs[0], tabs, envp);
//		exit(0);
	}
	return (0);
}

int		exec_arg1(char **envp, t_saver *saver)
{
	pid_t	pid;
	char	*tabs[] = {"/bin/ls", "srcs", NULL};

	pid = fork();
	if (pid < 0)
	{
		printf("Process issues.\n");
		return (-1);
	}
	if (pid == 0)
	{
		close(saver->current_pfd[0]);
		close(1);
		dup(saver->current_pfd[1]);
		execve(tabs[0], tabs, envp);
//		exit(0);
	}
	return (0);
}
int		exec_pipe(t_saver *saver)
{
	int	*pfd;

	pfd = malloc(sizeof(int) * 2);
	if (pipe(pfd) < 0)
	{
		printf("Pipe issues.\n");
		return (-1);
	}
	saver->current_pfd = pfd;
	return (0);
}

int		main(int argc, char **argv, char **envp)
{
	t_saver *saver;

	saver = malloc(sizeof(t_saver));
	saver->current_pfd = NULL;
	exec_pipe(saver);
	printf("saver->current_pfd[0] : %d\n", saver->current_pfd[0]);
	printf("saver->current_pfd[1] : %d\n", saver->current_pfd[1]);
	exec_arg1(envp, saver);
	exec_arg0(envp, saver);
	return (0);
}
