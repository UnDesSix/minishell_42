/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:50:12 by calide-n          #+#    #+#             */
/*   Updated: 2021/02/19 08:45:11 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

int	ft_execute(t_input input)
{
	int i = 0;

	if (strcmp(input.command, "pwd") == 0)
		pwd();
	if (strcmp(input.command, "echo") == 0)
		echo(input);
	if (strcmp(input.command, "exit") == 0)
		exit(0);
	return (0);	
}
