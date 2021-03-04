/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:26:04 by calide-n          #+#    #+#             */
/*   Updated: 2021/03/04 15:31:18 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

int	ft_manage_line(char *line, char **envp)
{
	t_block	*block;
	int index;
	int windex;

	index = 0;
	windex = 0;
	block = ft_get_blocks(line);
	while (block[index].stop)
	{
//		ft_execute_block(block[index]);
		windex = 0;
		while (block[index].word[windex].content)
		{
			free(block[index].word[windex].content);
			windex++;
		}
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
		printf("%s\n", line);
		ft_manage_line(line, envp);
		ft_putstr("➜ msh ");
		free(line);
	}
	free(line);
	return (0);
}
