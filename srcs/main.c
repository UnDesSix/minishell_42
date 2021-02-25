/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:26:04 by calide-n          #+#    #+#             */
/*   Updated: 2021/02/25 10:53:22 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

int main(int argc, char **argv)
{
	t_block	*block;
	char	*line;
	int index;
	int windex = 0;
	pid_t pid;
	int status;

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
	}
	return (0);
}
