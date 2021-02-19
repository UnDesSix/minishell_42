/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:50:12 by calide-n          #+#    #+#             */
/*   Updated: 2021/02/19 18:54:18 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

int	ft_bin_binary(t_input input)
{
	pid_t pid;
	int status;

	pid = fork();
	if (ft_strncmp(input.args[0], "/bin/", 5) != 0)
		input.args[0] = ft_strjoin("/bin/", input.args[0]);
	if (pid == 0)
		execve(input.args[0], input.args, NULL);
	else 
		wait(&status);
	return (0);
}

int	ft_execute(t_input *input)
{
	int i = 0;
	
	if (ft_strcmp(input[0].args[0], "exit") == 0)
		exit(0);
	else if (ft_strcmp(input[0].args[0], "pwd") == 0)
		pwd();
	else if (ft_strcmp(input[0].args[0], "cd") == 0)
		cd(input[0]);
	else
	{
		//ft_check_if_bin
		ft_bin_binary(input[0]);
	}
	return (0);	
}
