/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:27:37 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/20 16:59:32 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	ctrl_c(int sig)
{
	int	i;

	i = 0;
	if (g_proc.index != 0)
	{
		while (i < g_proc.index)
		{
			kill(g_proc.pid[i], sig);
			g_proc.pid[i] = 0;
			i++;
		}
		g_proc.ret = 130;
		ft_putstr("\n");
	}
	else
	{
		g_proc.ret = 1;
        ft_putstr_fd("\n\033[1m\033[31m➜\033[0m msh ", 1);
	}
	return ;
}

void	ctrl_slash(int sig)
{
	int	i;

	i = 0;
	if (g_proc.pid[0] != 0)
	{
		while (i < g_proc.index)
		{
			kill(g_proc.pid[i], sig);
			g_proc.pid[i] = 0;
			i++;
		}
		g_proc.ret = 131;
		ft_putstr("Quit: 3\n");
	}
	else
		ft_putstr("\b\b");
	return ;
}

void	signals()
{
	signal(SIGINT, ctrl_c);
	signal(SIGQUIT, ctrl_slash);
}
