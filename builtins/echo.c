/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:25:32 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/19 12:23:55 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	echo(t_word *word)
{
	int	flag;
	int	i;

	flag = 1;
	i = 0;
	if (word[1].content)
		if (ft_strcmp(word[1].content, "-n") == 0)
			flag = 2;
	i = flag;
	while (word[i].content)
	{
		if (ft_strcmp(word[i].content, "$?") == 0)
			ft_putnbr_fd(g_proc.ret, 1);
		else
			ft_putstr(word[i].content);
		if (word[i + 1].content)
			ft_putstr(" ");
		i++;
	}
	if (flag == 1)
		ft_putstr("\n");
	return (1);
}
