/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 11:29:16 by calide-n          #+#    #+#             */
/*   Updated: 2021/02/19 11:54:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

int	ft_check_cmd(char *str)
{
	if (strcmp(str, "pwd")		&&
			strcmp(str, "echo")		&&
			strcmp(str, "cat")		&&
			strcmp(str, "cd")		&&
			strcmp(str, "export")	&&
			strcmp(str, "unset")	&&
			strcmp(str, "env")		&&
			strcmp(str, "mkdir")	&&
			strcmp(str, "exit"))
		return (0);
	return (1);
}

t_input	ft_selector(char **tabs)
{
	int i = 0;
	int j = 0;
	t_input input;
	input.command = NULL;
	if (tabs[0])
	{
		if (ft_check_cmd(tabs[0]) == 0)
			printf("msh : command not found : %s\n", tabs[0]);
		input.command = tabs[0];
		while (tabs[i])
			i++;
		input.args = malloc(sizeof(char *) * (i + 1));
		i = 1;
		while (tabs[i])
		{
			input.args[i - 1] = tabs[i];
			i++;
		}
	}
	return (input);
}
