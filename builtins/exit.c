/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:34:35 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/21 23:33:51 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		ft_is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

void	numeric_arg_error(char *str)
{
	g_proc.ret = 2;
	printf("msh: exit: %s: numeric argument required\n", str);
}

int		ft_exit(t_word *word)
{
	g_proc.ret = 0;
	if (word[0].content)
	{
		if (ft_strcmp(word[0].content, "exit") == 0)
		{
			if (word[1].content)
			{
				if (ft_is_number(word[1].content))
				{
					g_proc.ret = ft_atoi(word[1].content);
					if (word[2].content)
					{
						printf("msh: exit: too many arguments\n");
						return (1);
					}
				}
				else
					numeric_arg_error(word[1].content);
			}
			return (-2);
		}
	}
	return (0);
}
