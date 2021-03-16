/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:25:32 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/15 16:32:49 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int echo(char **tab)
{
	int	flag;
	int	i;

	flag = 1;
	i = 0;
	if (tab[1])
		if (ft_strcmp(tab[1], "-n") == 0)
			flag = 2;
	i = flag;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		if (tab[i + 1])
			ft_putstr(" ");
		i++;
	}
	if (flag == 1)
		ft_putstr("\n");
	return (1);
}
