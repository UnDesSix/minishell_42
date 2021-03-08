/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:50:12 by calide-n          #+#    #+#             */
/*   Updated: 2021/02/19 14:32:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

int	ft_execute(t_input input, char **envp)
{
	int		i = 0;
	pid_t	pid = 0;
	int		status;

	if (strcmp(input.command, "pwd") == 0)
		pwd();
	else if (strcmp(input.command, "echo") == 0)
		echo(input);
	else if (strcmp(input.command, "exit") == 0)
		exit(0);
	else if (strcmp(input.command, "cd") == 0)
		exit(0);
	else if (strcmp(input.command, "mkdir") == 0)
	{
		pid = fork();
		if (pid == 0)
			execve("/bin/mkdir", input.args, envp);
		else
			wait(&status);
	}

	return (0);	
}
