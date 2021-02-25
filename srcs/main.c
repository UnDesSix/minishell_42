/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:26:04 by calide-n          #+#    #+#             */
/*   Updated: 2021/02/25 17:42:46 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

int	ft_check_exec(t_word word)
{
	
	return (0);
}

int ft_exec(t_block block)
{
	int 	w;
	char	**tab;
	int		status;
	char 	*tmp;

	w = 0;
	while (block.word[w].content)
	{
		if (block.word[w].type == 0)
		{
			tmp = block.word[w].content;
			block.word[w].content = ft_strjoin("/bin/", tmp);
			free(tmp);
		}
		w++;
	}
	tab = malloc(sizeof(char *) * (w + 1));
	w = 0;
	while (block.word[w].content)
	{
		tab[w] = block.word[w].content;
		w++;
	}
	tab[w] = NULL;
	w = 0;
	pid_t pid;

	pid = fork();
	if (pid == 0)
		execve(tab[0], tab, NULL);
	else
		wait(&status);
	return (0);
}

int main(int argc, char **argv)
{
	t_block	*block;
	char	*line;
	int index;
	int windex = 0;
	pid_t pid;
	int status;

	ft_putstr("➜ msh ");
	while (get_next_line(0, &line) != 0)
	{
		index = 0;
		if (block)
			free(block);
		block = ft_get_blocks(line);
		ft_identify_block(&block);
		free(line);
		//ft_exec(block[0]);
		while (block[index].stop)
		{
			windex = 0;
			if (ft_strcmp(block[index].word[windex].content, "exit") == 0)
				exit(0);
			printf("%d [", index);
			while (block[index].word[windex].content)
			{
				printf(" [%s spe:%d: space:%d: type:%d:]", block[index].word[windex].content, block[index].word[windex].sep, block[index].word[windex].space, block[index].word[windex].type);
				windex++;
			}
			printf(" ]\n");
			index++;	
		}
		ft_putstr("➜ msh ");
	}
	return (0);
}
