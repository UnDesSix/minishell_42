/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 18:49:24 by calide-n          #+#    #+#             */
/*   Updated: 2021/02/18 20:04:27 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

int echo(t_input input)
{
	int i;
	int flag;

	if (!input.args[0])
		return (0);
	i = 0;
	flag = 0;
	if ((strcmp(input.args[0], "-n") == 0))
	{
		i = 1;
		flag = 1;
	}

	while (input.args[i])
	{
		ft_putstr_fd(input.args[i], input.fd);
		if (input.args[i + 1])
			ft_putstr_fd(" ", input.fd);
		i++;
	}
	if (flag == 0)
		ft_putstr_fd("\n", input.fd);
	return (0);
}
