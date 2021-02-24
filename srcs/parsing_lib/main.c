/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:15:26 by calide-n          #+#    #+#             */
/*   Updated: 2021/02/24 15:56:57 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	ft_check_cmd(char *word)
{
	return(ft_strcmp(word, "echo") == 0 || ft_strcmp(word, "ls") == 0||
			ft_strcmp(word, "pwd") == 0 || ft_strcmp(word, "export") == 0 ||
			ft_strcmp(word, "unset") == 0 || ft_strcmp(word, "env") == 0);
}

int	ft_check_speop(char *word)
{
	return(ft_strcmp(word, "|") == 0 || ft_strcmp(word, "<") == 0 ||
			ft_strcmp(word, ">") == 0|| ft_strcmp(word, ">>") == 0||
			ft_strcmp(word, "=") == 0);
}

int	ft_identify_word(char *word)
{
	if (ft_check_cmd(word))
		return (CMD);
	if (ft_check_speop(word))
		return (SPEOP);
	return (ARG);
}

void	ft_identify_block(t_block **block)
{
	int b;
	int w;

	b = 0;
	while (block[b]->stop)
	{
		w = 0;
		while (block[b]->word[w].content)
		{
			block[b]->word[w].type = ft_identify_word(block[b]->word[w].content);
			w++;
		}
		b++;
	}
}

int main(int argc, char **argv)
{
	t_block	*block;
	char	*line;
	int index;
	int windex = 0;

	while (get_next_line(0, &line) != 0)
	{
		index = 0;
		if (block)
			free(block);
		block = ft_get_blocks(line);
		ft_identify_block(&block);
		free(line);
		while (block[index].stop)
		{
			windex = 0;
			printf("%d [", index);
			while (block[index].word[windex].content)
			{
				printf(" [%s spe:%d: space:%d: type:%d:]", block[index].word[windex].content, block[index].word[windex].sep, block[index].word[windex].space, block[index].word[windex].type);
				windex++;
			}
			printf(" ]\n");
			index++;	
		}
	}
	return (0);
}
