#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	handle()
{
	exit(0);
}

int main(void)
{
	signal(SIGSEGV, handle);
	while (1)
	{
		printf("ok\n");
		sleep(1);
	}
	return (0);
}
