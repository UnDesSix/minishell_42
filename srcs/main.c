/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:26:04 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/01 12:10:59 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

int	ft_manage_line(char *line, char **envp)
{
	t_block	*block;
	int index;
	int windex = 0;

	index = 0;
	block = ft_get_blocks(line);
	while (block[index].stop)
	{
		ft_execute_block(block[index]);
		free(block[index].word);
		index++;
	}
	free(block);
	return (0);
}

int main(int argc, char **argv, char **envp)
{
	char	*line;

	ft_putstr("➜ msh ");
	while (get_next_line(0, &line) != 0)
	{
		ft_manage_line(line, envp);
		ft_putstr("➜ msh ");
		free(line);
	}
	free(line);
	return (0);
}
