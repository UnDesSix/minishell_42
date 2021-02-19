/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:50:12 by calide-n          #+#    #+#             */
/*   Updated: 2021/02/19 20:42:26 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

int	ft_bin_binary(t_input input)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
		execve(input.args[0], input.args, NULL);
	else 
		wait(&status);
	return (0);
}

int	ft_check_if_bin(t_input *input, char **binary_path)
{
	char *tmp_path;
	int		i;
	struct stat stats;

	i = 0;
	tmp_path = input->args[0];
	while (binary_path[i])
	{
		if (strncmp(input->args[0], binary_path[i], ft_strlen(binary_path[i])) == 0)
			return (1);
		i++;
	}
	i = 0;
	while (binary_path[i])
	{
		input->args[0] = ft_strjoin(binary_path[i], tmp_path);
		if (stat(input->args[0], &stats) != -1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_execute(t_input *input)
{
	int i = 0;
	
	char *binary_path[] = {"/sbin/", "/bin/", "/usr/bin/", "/usr/sbin/", "/usr/local/bin/", NULL};

	if (ft_strcmp(input[0].args[0], "exit") == 0)
		exit(0);
	else if (ft_strcmp(input[0].args[0], "pwd") == 0)
		pwd();
	else if (ft_strcmp(input[0].args[0], "cd") == 0)
		cd(input[0]);
	else
	{
		if (!ft_check_if_bin(&input[0], binary_path))
			printf("Is not binary\n");
		else
			ft_bin_binary(input[0]);
	}
	return (0);	
}
