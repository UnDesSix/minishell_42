/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:26:04 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/22 15:44:53 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

void	ft_free_words(t_word *word)
{
	int	x;

	x = 0;
	while (word[x].content)
	{
		free(word[x].content);
		x++;
	}
	free(word);
}

int		get_input(t_list *begin_list)
{
	char	*line;
	int		ret;

	ret = 0;
	line = NULL;
	ft_putstr_fd("\033[1m\033[32m➜\033[0m msh ", 1);
	signals();
	while (42)
	{
		g_proc.index = 0;
		ret = get_next_line(0, &line);
		if (line)
		{
			if (ret == 0)
				break ;
			ret = divide_lines(line, begin_list);
			if (ret == 0)
				break ;
			free(line);
		}
		if (g_proc.ret == 0)
			ft_putstr_fd("\033[1m\033[32m➜\033[0m msh ", 1);
		else
			ft_putstr_fd("\033[1m\033[31m➜\033[0m msh ", 1);
	}
	free(line);
	return (0);
}

int		main(int argc, char **argv, char **envp)
{
	t_list	*begin_list;

	(void)argc;
	(void)argv;
	g_proc.ret = 0;
	g_proc.index = 0;
//	g_proc.shell_lvl = 0;
	begin_list = tabs_to_list(envp);
	get_input(begin_list);
	ft_list_clear(begin_list, free_var);
	return (g_proc.ret);
}
